#include <lvgl.h>
#include <TFT_eSPI.h>
#include <ui.h>
#include <CST816S.h>
#include <Ticker.h>
#include <WiFi.h>

//WiFi Credentials
const char* ssid = "Wi-Fi";
const char* password = "Mywifi#123";

//Socket Credentials
const char* serverAddress = "192.168.1.3"; // IP address of the server you want to send data to
const int serverPort = 8080; // Port of the server

//Connection Variables
bool isConnected = false;

//Touch Initialization
CST816S touch(6, 7, 14, 5);


/* Screen resolution*/
static const uint16_t screenWidth  = 240;
static const uint16_t screenHeight = 240;

static lv_disp_draw_buf_t draw_buf;
static lv_color_t buf[ screenWidth * screenHeight / 10 ];

//TFT Initialization
TFT_eSPI tft = TFT_eSPI(screenWidth, screenHeight); /* TFT instance */



#if LV_USE_LOG != 0
/* Serial debugging */
void my_print(const char * buf)
{
    Serial.printf(buf);
    Serial.flush();
}
#endif

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
                                                                  
        // Serial.print( "Data x " );
        // Serial.println( touchX );

        // Serial.print( "Data y " );
        // Serial.println( touchY );
    }
}

static void lvglTask(void *pvParameters) {
  // Ensure LVGL is initialized
  lv_obj_t *slider = (lv_obj_t *)pvParameters;
  int value = lv_slider_get_value(slider);
  Serial.println("Slider Value Changed!");
  Serial.println(value);
  lv_obj_t * switch_btn = ui_LightSwitch; // Assuming ui_LightSwitch is accessible here
  int buttonState = lv_obj_get_state(switch_btn);
  Serial.println(buttonState);
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
    Serial.println("Connection to server failed");
    delay(1000);
    return;
  }
  
  // Send data to the server
  String dataToSend = dataToSocket;
  client.print(dataToSend);

  // Close the connection
  //client.stop();
}

static void connectWiFi(void *pvParameters) {
  lv_obj_t *statusLabel = (lv_obj_t *)pvParameters;
  if(!isConnected)
  {
    WiFi.mode(WIFI_STA); //Optional
    WiFi.begin(ssid, password);
    Serial.println("\nConnecting");
    lv_label_set_text_fmt(statusLabel, "%s", "Connecting!");

    unsigned long startTime = millis(); // Record the start time

    while (WiFi.status() != WL_CONNECTED && millis() - startTime < 10000) { // Check connection status and time elapsed
      Serial.print(".");
      delay(100);
    }

    if (WiFi.status() == WL_CONNECTED) {
      Serial.println("\nConnected to the WiFi network");
      Serial.print("Local ESP32 IP: ");
      Serial.println(WiFi.localIP());
      lv_label_set_text_fmt(statusLabel, "%s", WiFi.localIP().toString());
      
      isConnected = true;
    } else {
      Serial.println("\nConnection timed out");
      lv_label_set_text_fmt(statusLabel, "%s", "Failed!");
      // Handle timeout here, for example, retry connection or take appropriate action
    }
  }
  if(isConnected)
  {
    lv_obj_t *connectButton = ui_ConnectToWifiBtn;
    Serial.println("\nDisabling Button");
    lv_obj_clear_state(connectButton,lv_obj_get_state(connectButton));
    lv_obj_add_state(connectButton, LV_STATE_DISABLED);
    socketSend("Hello Server");
  }
  vTaskDelete(NULL);

  while (1) {
    lv_task_handler();
    delay(5); // Adjust delay as needed
  }
}

static void lockLaptop(void *pvParameters)
{
  Serial.println("\n Reached LapLock");
  socketSend("Lock");
  while (1) {
    lv_task_handler();
    delay(5); // Adjust delay as needed
  }

}

static void initSettings(void *pvParameters)
{
  Serial.println("\n Reached Settings Init");
}


void connectToWifiTask(lv_event_t * e)
{
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
  Serial.println("\n Settings Screen Loaded");
  if(isConnected)
  {
    lv_obj_t *connectButton = ui_ConnectToWifiBtn;
    Serial.println("\nDisabling Button");
    lv_obj_clear_state(connectButton,lv_obj_get_state(connectButton));
    lv_obj_add_state(connectButton, LV_STATE_DISABLED);
  }
}

void homeScreenLoaded(lv_event_t * e)
{
  Serial.println("\n Home Screen Loaded");
  lv_obj_t *wifiImage = ui_WifiImage;
  if(isConnected)
  {
    
    Serial.println("Connected TO WiFi");
    // lv_obj_clear_state(connectButton,lv_obj_get_state(connectButton));
    // lv_obj_add_state(connectButton, LV_STATE_DISABLED);
    
    lv_img_set_src(wifiImage, &ui_img_wifi_connected_png);
    lv_img_set_zoom(wifiImage, 100);
  }
  else
  {
    lv_img_set_src(wifiImage, &ui_img_nowifi_png);
    lv_img_set_zoom(wifiImage, 100);
    Serial.println("Not Connected to WiFi");
  }
}

void setup()
{
    Serial.begin( 115200 ); /* prepare for possible serial debug */
    touch.begin();
    String LVGL_Arduino = "Hello Arduino! ";
    LVGL_Arduino += String('V') + lv_version_major() + "." + lv_version_minor() + "." + lv_version_patch();

    Serial.println( LVGL_Arduino );
    Serial.println( "I am LVGL_Arduino" );

    lv_init();

#if LV_USE_LOG != 0
    lv_log_register_print_cb( my_print ); /* register print function for debugging */
#endif

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
    

}

void loop()
{
    lv_timer_handler(); /* let the GUI do its work */
    delay(5);
}
