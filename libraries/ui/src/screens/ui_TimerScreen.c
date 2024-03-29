// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.4
// LVGL version: 8.3.6
// Project name: knobOS

#include "../ui.h"

void ui_TimerScreen_screen_init(void)
{
    ui_TimerScreen = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_TimerScreen, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_flex_flow(ui_TimerScreen, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_TimerScreen, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);

    ui_Arc2 = lv_arc_create(ui_TimerScreen);
    lv_obj_set_width(ui_Arc2, 200);
    lv_obj_set_height(ui_Arc2, 200);
    lv_obj_set_x(ui_Arc2, 77);
    lv_obj_set_y(ui_Arc2, -21);
    lv_obj_set_align(ui_Arc2, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_Arc2, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_Arc2, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Arc2, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_CLICK_FOCUSABLE);      /// Flags
    lv_arc_set_value(ui_Arc2, 5);
    lv_arc_set_bg_angles(ui_Arc2, 0, 360);


    ui_Dropdown1 = lv_dropdown_create(ui_Arc2);
    lv_dropdown_set_options(ui_Dropdown1, "10 Mins\n1 Hour\n3 Hour");
    lv_obj_set_width(ui_Dropdown1, 150);
    lv_obj_set_height(ui_Dropdown1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Dropdown1, -29);
    lv_obj_set_y(ui_Dropdown1, -9);
    lv_obj_set_align(ui_Dropdown1, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Dropdown1, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags



    lv_obj_add_event_cb(ui_TimerScreen, ui_event_TimerScreen, LV_EVENT_ALL, NULL);

}
