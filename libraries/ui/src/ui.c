// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.4
// LVGL version: 8.3.6
// Project name: knobOS

#include "ui.h"
#include "ui_helpers.h"

///////////////////// VARIABLES ////////////////////


// SCREEN: ui_FlashScreen
void ui_FlashScreen_screen_init(void);
void ui_event_FlashScreen(lv_event_t * e);
lv_obj_t * ui_FlashScreen;
lv_obj_t * ui_logo;
lv_obj_t * ui_knobosLabel;
lv_obj_t * ui_firmwareLabel;
void ui_event_roundButton_roundButton(lv_event_t * e);
lv_obj_t * ui_roundButton;


// SCREEN: ui_HomeScreen
void ui_HomeScreen_screen_init(void);
void ui_event_HomeScreen(lv_event_t * e);
lv_obj_t * ui_HomeScreen;
lv_obj_t * ui_TimePanel;
lv_obj_t * ui_Hour;
lv_obj_t * ui_Mins;
lv_obj_t * ui_DateInfo;
lv_obj_t * ui_StatusPanel;
lv_obj_t * ui_WifiPanel;
lv_obj_t * ui_WifiImage;
lv_obj_t * ui_ProfilePanel;
lv_obj_t * ui_ProfileImage;
void ui_event_SettingsPanel(lv_event_t * e);
lv_obj_t * ui_SettingsPanel;
lv_obj_t * ui_SettingsImage;


// SCREEN: ui_AppScreenDisplay
void ui_AppScreenDisplay_screen_init(void);
void ui_event_AppScreenDisplay(lv_event_t * e);
lv_obj_t * ui_AppScreenDisplay;
lv_obj_t * ui_AppScreen;
void ui_event_AppComponent2(lv_event_t * e);
lv_obj_t * ui_AppComponent2;
lv_obj_t * ui_AppImage1;
lv_obj_t * ui_AppLabel1;
void ui_event_AppComponent3(lv_event_t * e);
lv_obj_t * ui_AppComponent3;
lv_obj_t * ui_AppImage4;
lv_obj_t * ui_AppLabel4;
void ui_event_LaptopComponent(lv_event_t * e);
lv_obj_t * ui_LaptopComponent;
lv_obj_t * ui_LaptopImage;
lv_obj_t * ui_LaptopLabel;
void ui_event_Panel2(lv_event_t * e);
lv_obj_t * ui_Panel2;
lv_obj_t * ui_Label2;


// SCREEN: ui_LightControl
void ui_LightControl_screen_init(void);
void ui_event_LightControl(lv_event_t * e);
lv_obj_t * ui_LightControl;
lv_obj_t * ui_AppTitleComp1;
lv_obj_t * ui_AppControls;
lv_obj_t * ui_SwitchHolder;
lv_obj_t * ui_LightSwitch;
lv_obj_t * ui_SwitchLabel;
void ui_event_BrightnessSlider(lv_event_t * e);
lv_obj_t * ui_BrightnessSlider;
lv_obj_t * ui_BrightnessSliderLabel;
void ui_event_ChangeColorButton(lv_event_t * e);
lv_obj_t * ui_ChangeColorButton;
lv_obj_t * ui_Label3;


// SCREEN: ui_LightColorScreen
void ui_LightColorScreen_screen_init(void);
void ui_event_LightColorScreen(lv_event_t * e);
lv_obj_t * ui_LightColorScreen;
lv_obj_t * ui_LightColorWheel;
lv_obj_t * ui_SetColorButton;
lv_obj_t * ui_SetColorLabel;


// SCREEN: ui_FanControl
void ui_FanControl_screen_init(void);
void ui_event_FanControl(lv_event_t * e);
lv_obj_t * ui_FanControl;
lv_obj_t * ui_AppTitleComp2;
lv_obj_t * ui_AppControls1;
void ui_event_SwitchHolder1(lv_event_t * e);
lv_obj_t * ui_SwitchHolder1;
lv_obj_t * ui_switch1;
lv_obj_t * ui_SwitchLabel1;
lv_obj_t * ui_Slider2;
lv_obj_t * ui_Label6;
void ui_event_ChangeColorButton1(lv_event_t * e);
lv_obj_t * ui_ChangeColorButton1;
lv_obj_t * ui_Label7;


// SCREEN: ui_TimerScreen
void ui_TimerScreen_screen_init(void);
void ui_event_TimerScreen(lv_event_t * e);
lv_obj_t * ui_TimerScreen;
lv_obj_t * ui_Arc2;
lv_obj_t * ui_Dropdown1;


// SCREEN: ui_SettingsScreen
void ui_SettingsScreen_screen_init(void);
void ui_event_SettingsScreen(lv_event_t * e);
lv_obj_t * ui_SettingsScreen;
lv_obj_t * ui_AppTitleComp3;
lv_obj_t * ui_AppControls2;
void ui_event_ConnectToWifiBtn(lv_event_t * e);
lv_obj_t * ui_ConnectToWifiBtn;
lv_obj_t * ui_WiFiConnectBtnLabel;
lv_obj_t * ui_Image1;
lv_obj_t * ui_AutoConnectPanel;
lv_obj_t * ui_AutoConnectLabel;
lv_obj_t * ui_autoConnectSwitch;
lv_obj_t * ui_ConnectionStatusLabel;


// SCREEN: ui_LaptopControl
void ui_LaptopControl_screen_init(void);
void ui_event_LaptopControl(lv_event_t * e);
lv_obj_t * ui_LaptopControl;
lv_obj_t * ui_AppTitleComp4;
lv_obj_t * ui_AppControls3;
lv_obj_t * ui_LaptopLockPanel;
void ui_event_LockLaptopBtn(lv_event_t * e);
lv_obj_t * ui_LockLaptopBtn;
lv_obj_t * ui_LockLabel;
lv_obj_t * ui____initial_actions0;

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 16
    #error "LV_COLOR_DEPTH should be 16bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP !=0
    #error "LV_COLOR_16_SWAP should be 0 to match SquareLine Studio's settings"
#endif

///////////////////// ANIMATIONS ////////////////////

///////////////////// FUNCTIONS ////////////////////
void ui_event_FlashScreen(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_SCREEN_LOAD_START) {
        loadFlashScreen(e);
    }
}
void ui_event_roundButton_roundButton(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_RELEASED) {
        _ui_screen_change(&ui_HomeScreen, LV_SCR_LOAD_ANIM_MOVE_LEFT, 500, 0, &ui_HomeScreen_screen_init);
    }
}
void ui_event_HomeScreen(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_LEFT) {
        lv_indev_wait_release(lv_indev_get_act());
        _ui_screen_change(&ui_AppScreenDisplay, LV_SCR_LOAD_ANIM_MOVE_LEFT, 500, 0, &ui_AppScreenDisplay_screen_init);
    }
}
void ui_event_SettingsPanel(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(&ui_SettingsScreen, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0, &ui_SettingsScreen_screen_init);
    }
}
void ui_event_AppScreenDisplay(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_BOTTOM) {
        lv_indev_wait_release(lv_indev_get_act());
        _ui_screen_change(&ui_SettingsScreen, LV_SCR_LOAD_ANIM_MOVE_BOTTOM, 500, 0, &ui_SettingsScreen_screen_init);
    }
}
void ui_event_AppComponent2(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_LONG_PRESSED) {
        _ui_screen_change(&ui_LightControl, LV_SCR_LOAD_ANIM_MOVE_BOTTOM, 500, 0, &ui_LightControl_screen_init);
    }
}
void ui_event_AppComponent3(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_LONG_PRESSED) {
        _ui_screen_change(&ui_FanControl, LV_SCR_LOAD_ANIM_MOVE_TOP, 500, 0, &ui_FanControl_screen_init);
    }
}
void ui_event_LaptopComponent(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_LONG_PRESSED) {
        _ui_screen_change(&ui_LaptopControl, LV_SCR_LOAD_ANIM_MOVE_BOTTOM, 500, 0, &ui_LaptopControl_screen_init);
    }
}
void ui_event_Panel2(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_PRESSED) {
        _ui_screen_change(&ui_FlashScreen, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0, &ui_FlashScreen_screen_init);
    }
}
void ui_event_LightControl(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_BOTTOM) {
        lv_indev_wait_release(lv_indev_get_act());
        _ui_screen_change(&ui_AppScreenDisplay, LV_SCR_LOAD_ANIM_MOVE_BOTTOM, 500, 0, &ui_AppScreenDisplay_screen_init);
    }
    if(event_code == LV_EVENT_SCREEN_LOADED) {
        lightControlScreenLoaded(e);
        (e);
    }
}
void ui_event_BrightnessSlider(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_VALUE_CHANGED) {
        brightnessLevelChange(e);
        (e);
    }
}
void ui_event_ChangeColorButton(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_RELEASED) {
        _ui_screen_change(&ui_LightColorScreen, LV_SCR_LOAD_ANIM_MOVE_TOP, 500, 0, &ui_LightColorScreen_screen_init);
    }
}
void ui_event_LightColorScreen(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_BOTTOM) {
        lv_indev_wait_release(lv_indev_get_act());
        _ui_screen_change(&ui_LightControl, LV_SCR_LOAD_ANIM_MOVE_BOTTOM, 500, 0, &ui_LightControl_screen_init);
    }
}
void ui_event_FanControl(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_BOTTOM) {
        lv_indev_wait_release(lv_indev_get_act());
        _ui_screen_change(&ui_AppScreenDisplay, LV_SCR_LOAD_ANIM_MOVE_BOTTOM, 500, 0, &ui_AppScreenDisplay_screen_init);
    }
}
void ui_event_SwitchHolder1(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        swithOnFunction(e);
    }
}
void ui_event_ChangeColorButton1(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_RELEASED) {
        _ui_screen_change(&ui_TimerScreen, LV_SCR_LOAD_ANIM_MOVE_TOP, 500, 0, &ui_TimerScreen_screen_init);
    }
}
void ui_event_TimerScreen(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_BOTTOM) {
        lv_indev_wait_release(lv_indev_get_act());
        _ui_screen_change(&ui_FanControl, LV_SCR_LOAD_ANIM_MOVE_BOTTOM, 500, 0, &ui_FanControl_screen_init);
    }
}
void ui_event_SettingsScreen(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_BOTTOM) {
        lv_indev_wait_release(lv_indev_get_act());
        _ui_screen_change(&ui_HomeScreen, LV_SCR_LOAD_ANIM_MOVE_BOTTOM, 500, 0, &ui_HomeScreen_screen_init);
    }
    if(event_code == LV_EVENT_SCREEN_LOADED) {
        lightControlScreenLoaded(e);
        (e);
    }
}
void ui_event_ConnectToWifiBtn(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        ConnectToWifi(e);
    }
}
void ui_event_LaptopControl(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_BOTTOM) {
        lv_indev_wait_release(lv_indev_get_act());
        _ui_screen_change(&ui_AppScreenDisplay, LV_SCR_LOAD_ANIM_MOVE_BOTTOM, 500, 0, &ui_AppScreenDisplay_screen_init);
    }
}
void ui_event_LockLaptopBtn(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        lockLaptop(e);
    }
}

///////////////////// SCREENS ////////////////////

void ui_init(void)
{
    LV_EVENT_GET_COMP_CHILD = lv_event_register_id();

    lv_disp_t * dispp = lv_disp_get_default();
    lv_theme_t * theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED),
                                               false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    ui_FlashScreen_screen_init();
    ui_HomeScreen_screen_init();
    ui_AppScreenDisplay_screen_init();
    ui_LightControl_screen_init();
    ui_LightColorScreen_screen_init();
    ui_FanControl_screen_init();
    ui_TimerScreen_screen_init();
    ui_SettingsScreen_screen_init();
    ui_LaptopControl_screen_init();
    ui____initial_actions0 = lv_obj_create(NULL);
    lv_disp_load_scr(ui_FlashScreen);
}
