SET(SOURCES components/ui_comp_appcomponent.c
    components/ui_comp_apptitlecomp.c
    components/ui_comp_roundbutton.c
    components/ui_comp.c
    screens/ui_FlashScreen.c
    screens/ui_Changelog.c
    screens/ui_HomeScreen.c
    screens/ui_AppScreenDisplay.c
    screens/ui_LightControl.c
    screens/ui_LightColorScreen.c
    screens/ui_FanControl.c
    screens/ui_TimerScreen.c
    ui.c
    components/ui_comp_hook.c
    ui_helpers.c
    ui_events.c
    images/ui_img_1828568161.c
    images/ui_img_1656806725.c
    images/ui_img_suitcase_png.c
    images/ui_img_settings_png.c
    images/ui_img_lightbulb_png.c
    images/ui_img_fan_png.c
    images/ui_img_laptop_png.c)

add_library(ui ${SOURCES})
