#include <lvgl.h>
#include <TFT_eSPI.h>
#include <ui.h>
#include <CST816S.h>
#include <Ticker.h>
#include <WiFi.h>
#include <ESP32Time.h>
#include <time.h>


#if DEGUBVAL == 0
  #define DEBUG_PRINT(x)  Serial.print(x)
  #define DEBUG_PRINTLN(x)  Serial.println(x)
#else
  #define DEBUG_PRINT(x)
  #define DEBUG_PRINTLN(x)
#endif


//WiFi Credentials
const char* ssid PROGMEM = "Wi-Fi";
const char* password PROGMEM = "Mywifi#123";

//Socket Credentials
const char* serverAddress PROGMEM = "192.168.1.3"; // IP address of the server you want to send data to
const int serverPort PROGMEM = 8080; // Port of the server

//Connection Variables
bool isConnected = false;

//Touch Initialization
CST816S touch(6, 7, 14, 5);

//RTC Initialization
ESP32Time rtc(19800);
bool timeSync = false;
const char* ntpServer = "pool.ntp.org";
const long  gmtOffset_sec = 19800;
const int   daylightOffset_sec = 0;

/* Screen resolution*/
static const uint16_t screenWidth PROGMEM   = 240;
static const uint16_t screenHeight PROGMEM  = 240;

static lv_disp_draw_buf_t draw_buf;
static lv_color_t buf[ screenWidth * screenHeight / 10 ];

//TFT Initialization
TFT_eSPI tft = TFT_eSPI(screenWidth, screenHeight); /* TFT instance */


/* Display flushing */
void my_disp_flush( lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p )
{
    uint32_t w = ( area->x2 - area->x1 + 1 );
    uint32_t h = ( area->y2 - area->y1 + 1 );

    tft.startWrite();
    tft.setAddrWindow( area->x1, area->y1, w, h );
    tft.pushColors( ( uint16_t * )&color_p->full, w * h, true );
    tft.endWrite();

    lv_disp_flush_ready( disp );
}

/*Read the touchpad*/
void my_touchpad_read( lv_indev_drv_t * indev_driver, lv_indev_data_t * data )
{
    uint16_t touchX = 0, touchY = 0;

    bool touched = touch.available();


    if( !touched )
    {
        data->state = LV_INDEV_STATE_REL;
    }
    else
    {
        data->state = LV_INDEV_STATE_PR;

        touchX = touch.data.x;
        touchY = touch.data.y;

        /*Set the coordinates*/
        data->point.x = touchX;
        data->point.y = touchY;
    }
}

static void lvglTask(void *pvParameters) {
  // Ensure LVGL is initialized
  lv_obj_t *slider = (lv_obj_t *)pvParameters;
  int value = lv_slider_get_value(slider);
  DEBUG_PRINTLN("Slider Value Changed!");
  DEBUG_PRINTLN(value);
  lv_obj_t * switch_btn = ui_LightSwitch; // Assuming ui_LightSwitch is accessible here
  int buttonState = lv_obj_get_state(switch_btn);
  DEBUG_PRINTLN(buttonState);
  lv_obj_clear_state(switch_btn,lv_obj_get_state(switch_btn));
  lv_obj_add_state(switch_btn, LV_STATE_CHECKED);

  // Keep LVGL running
  while(1) {
    lv_task_handler();
    delay(5); // Adjust delay as needed
  }
}

void brightnessSliderUpdate(lv_event_t * e)
{
  lv_obj_t *target = lv_event_get_target(e);
    xTaskCreate(lvglTask, // Task function
              "LVGL Task", // Task name
              4096, // Stack size
              (void *)target, // Task parameters
              1, // Priority
              NULL); // Task handle (optional)
}

void lightControlScreenEvents(lv_event_t * e)
{
  
}

void socketSend(String dataToSocket)
{
  WiFiClient client;
  if (!client.connect(serverAddress, serverPort)) {
    DEBUG_PRINTLN("Connection to server failed");
    delay(1000);
    return;
  }
  
  // Send data to the server
  String dataToSend = dataToSocket;
  client.print(dataToSend);
}

static void connectWiFi(void *pvParameters) {
  lv_obj_t *statusLabel = (lv_obj_t *)pvParameters;
  if(!isConnected)
  {
    WiFi.mode(WIFI_STA); //Optional
    WiFi.begin(ssid, password);
    DEBUG_PRINTLN("\nConnecting");
    lv_label_set_text_fmt(statusLabel, "%s", "Connecting!");

    unsigned long startTime = millis(); // Record the start time

    while (WiFi.status() != WL_CONNECTED && millis() - startTime < 10000) { // Check connection status and time elapsed
      DEBUG_PRINT(".");
      delay(100);
    }

    if (WiFi.status() == WL_CONNECTED) {
      DEBUG_PRINTLN("\nConnected to the WiFi network");
      DEBUG_PRINT("Local ESP32 IP: ");
      DEBUG_PRINTLN(WiFi.localIP());
      lv_label_set_text_fmt(statusLabel, "%s", WiFi.localIP().toString());
      
      isConnected = true;
    } else {
      DEBUG_PRINTLN("\nConnection timed out");
      lv_label_set_text_fmt(statusLabel, "%s", "Failed!");
      // Handle timeout here, for example, retry connection or take appropriate action
    }
  }
  if(isConnected)
  {
    lv_obj_t *wifiImage = ui_WifiImage;
    lv_obj_t *connectButton = ui_ConnectToWifiBtn;
    DEBUG_PRINTLN("\nDisabling Button");
    lv_obj_clear_state(connectButton,lv_obj_get_state(connectButton));
    lv_obj_add_state(connectButton, LV_STATE_DISABLED);
    lv_img_set_src(wifiImage, &ui_img_wifi_connected_png);
    lv_img_set_zoom(wifiImage, 100);
    socketSend("Hello Server");
    syncCurrentTime();
  }
  vTaskDelete(NULL);

  while (1) {
    lv_task_handler();
    delay(5); // Adjust delay as needed
  }
}

static void lockLaptop(void *pvParameters)
{
  DEBUG_PRINTLN("\n Reached LapLock");
  socketSend("Lock");
  while (1) {
    lv_task_handler();
    delay(5); // Adjust delay as needed
  }

}

static void initSettings(void *pvParameters)
{
  DEBUG_PRINTLN("\n Reached Settings Init");
}


void connectToWifiTask(lv_event_t * e)
{
  DEBUG_PRINTLN("\n Called Connect to WiFi");
  lv_obj_t *wifiStatusLabel = ui_ConnectionStatusLabel;
  xTaskCreate(connectWiFi, // Task function
              "LVGL Connect to WiFi Task", // Task name
              4096, // Stack size
              (void *)wifiStatusLabel, // Task parameters
              1, // Priority
              NULL); // Task handle (optional)
}

void lockLaptopTask(lv_event_t * e)
{
  xTaskCreate(lockLaptop, // Task function
              "LVGL Lock Laptop Task", // Task name
              4096, // Stack size
              NULL, // Task parameters
              1, // Priority
              NULL); // Task handle (optional)
}

void settingsScreenLoaded(lv_event_t * e)
{
  DEBUG_PRINTLN("\n Settings Screen Loaded");
  if(isConnected)
  {
    lv_obj_t *connectButton = ui_ConnectToWifiBtn;
    DEBUG_PRINTLN("\nDisabling Button");
    lv_obj_clear_state(connectButton,lv_obj_get_state(connectButton));
    lv_obj_add_state(connectButton, LV_STATE_DISABLED);
  }
}


void syncCurrentTime()
{
  DEBUG_PRINTLN(rtc.getTime("%A, %B %d %Y %H:%M:%S"));
  lv_obj_t *hourLabel = ui_Hour;
  lv_obj_t *minsLabel = ui_Mins;
  lv_obj_t *dateLabel = ui_DateInfo;
  lv_label_set_text_fmt(hourLabel, "%s", rtc.getTime("%H"));
  lv_label_set_text_fmt(minsLabel, "%s", rtc.getTime("%M"));
  lv_label_set_text_fmt(dateLabel, "%s", rtc.getTime("%b %d"));
  timeSync=true;
}

void homeScreenLoaded(lv_event_t * e)
{
  DEBUG_PRINTLN("\n Home Screen Loaded");
  lv_obj_t *wifiImage = ui_WifiImage;
  if(isConnected)
  {
    DEBUG_PRINTLN("Connected TO WiFi");    
    lv_img_set_src(wifiImage, &ui_img_wifi_connected_png);
    lv_img_set_zoom(wifiImage, 100);
    syncCurrentTime();
  }
  else
  {
    lv_img_set_src(wifiImage, &ui_img_nowifi_png);
    lv_img_set_zoom(wifiImage, 100);
    DEBUG_PRINTLN("Not Connected to WiFi");
  }
}

void setup()
{
    #if DEGUB == 0
    Serial.begin( 115200 ); /* prepare for possible serial debug */
    #endif
    touch.begin();
    String LVGL_Arduino PROGMEM = "Hello Arduino! ";
    LVGL_Arduino += String('V') + lv_version_major() + "." + lv_version_minor() + "." + lv_version_patch();

    DEBUG_PRINTLN( LVGL_Arduino );
    lv_init();
    tft.begin();          /* TFT init */
    tft.setRotation( 4 ); /* Landscape orientation, flipped */

    lv_disp_draw_buf_init( &draw_buf, buf, NULL, screenWidth * screenHeight / 10 );

    /*Initialize the display*/
    static lv_disp_drv_t disp_drv;
    lv_disp_drv_init( &disp_drv );
    /*Change the following line to your display resolution*/
    disp_drv.hor_res = screenWidth;
    disp_drv.ver_res = screenHeight;
    disp_drv.flush_cb = my_disp_flush;
    disp_drv.draw_buf = &draw_buf;
    lv_disp_drv_register( &disp_drv );

    /*Initialize the (dummy) input device driver*/
    static lv_indev_drv_t indev_drv;
    lv_indev_drv_init( &indev_drv );
    indev_drv.type = LV_INDEV_TYPE_POINTER;
    indev_drv.read_cb = my_touchpad_read;
    lv_indev_drv_register( &indev_drv );
    ui_init();
    //lv_obj_add_event_cb(ui_BrightnessSlider, brightnessSliderUpdate, LV_EVENT_VALUE_CHANGED, NULL);
    //lv_obj_add_event_cb(ui_LightControl, lightControlScreenEvents, LV_EVENT_SCREEN_LOADED, NULL);
    lv_obj_add_event_cb(ui_ConnectToWifiBtn, connectToWifiTask, LV_EVENT_PRESSED, NULL);
    lv_obj_add_event_cb(ui_LockLaptopBtn, lockLaptopTask, LV_EVENT_PRESSED, NULL);
    lv_obj_add_event_cb(ui_SettingsScreen, settingsScreenLoaded, LV_EVENT_SCREEN_LOADED, NULL);
    lv_obj_add_event_cb(ui_HomeScreen, homeScreenLoaded, LV_EVENT_SCREEN_LOADED, NULL);
    lv_obj_add_event_cb(ui_FlashScreen, connectToWifiTask, LV_EVENT_SCREEN_LOADED, NULL);
    
}

void loop()
{
    lv_timer_handler(); /* let the GUI do its work */
    delay(5);
}
