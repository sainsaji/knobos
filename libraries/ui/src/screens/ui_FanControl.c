// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.4
// LVGL version: 8.3.6
// Project name: knobOS

#include "../ui.h"

void ui_FanControl_screen_init(void)
{
    ui_FanControl = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_FanControl, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_flex_flow(ui_FanControl, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_FanControl, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);

    lv_obj_set_style_pad_left(ui_FanControl, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_FanControl, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_FanControl, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_FanControl, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);

    ui_AppTitleComp2 = ui_AppTitleComp_create(ui_FanControl);
    lv_obj_set_width(ui_AppTitleComp2, 159);
    lv_obj_set_height(ui_AppTitleComp2, 31);
    lv_obj_set_x(ui_AppTitleComp2, 0);
    lv_obj_set_y(ui_AppTitleComp2, -82);
    lv_obj_set_flex_flow(ui_AppTitleComp2, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_AppTitleComp2, LV_FLEX_ALIGN_SPACE_AROUND, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);

    lv_img_set_src(ui_comp_get_child(ui_AppTitleComp2, UI_COMP_APPTITLECOMP_APPIMAGE2), &ui_img_fan_png);

    lv_label_set_text(ui_comp_get_child(ui_AppTitleComp2, UI_COMP_APPTITLECOMP_APPLABEL2), "Fan Control");

    ui_AppControls1 = lv_obj_create(ui_FanControl);
    lv_obj_set_width(ui_AppControls1, 189);
    lv_obj_set_height(ui_AppControls1, 118);
    lv_obj_set_x(ui_AppControls1, -1);
    lv_obj_set_y(ui_AppControls1, -36);
    lv_obj_set_align(ui_AppControls1, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_AppControls1, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_AppControls1, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(ui_AppControls1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_SwitchHolder1 = lv_obj_create(ui_AppControls1);
    lv_obj_set_width(ui_SwitchHolder1, 175);
    lv_obj_set_height(ui_SwitchHolder1, 31);
    lv_obj_set_x(ui_SwitchHolder1, -1);
    lv_obj_set_y(ui_SwitchHolder1, -35);
    lv_obj_set_align(ui_SwitchHolder1, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_SwitchHolder1, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_SwitchHolder1, LV_FLEX_ALIGN_END, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(ui_SwitchHolder1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_SwitchHolder1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SwitchHolder1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_SwitchHolder1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_SwitchHolder1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_switch1 = lv_switch_create(ui_SwitchHolder1);
    lv_obj_set_width(ui_switch1, 50);
    lv_obj_set_height(ui_switch1, 25);
    lv_obj_set_x(ui_switch1, -62);
    lv_obj_set_y(ui_switch1, -19);
    lv_obj_set_align(ui_switch1, LV_ALIGN_CENTER);


    ui_SwitchLabel1 = lv_label_create(ui_SwitchHolder1);
    lv_obj_set_width(ui_SwitchLabel1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_SwitchLabel1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_SwitchLabel1, 14);
    lv_obj_set_y(ui_SwitchLabel1, -5);
    lv_obj_set_align(ui_SwitchLabel1, LV_ALIGN_CENTER);
    lv_label_set_text(ui_SwitchLabel1, "Switch On");

    ui_Slider2 = lv_slider_create(ui_AppControls1);
    lv_obj_set_width(ui_Slider2, 150);
    lv_obj_set_height(ui_Slider2, 10);
    lv_obj_set_x(ui_Slider2, 1);
    lv_obj_set_y(ui_Slider2, 7);
    lv_obj_set_align(ui_Slider2, LV_ALIGN_CENTER);


    ui_Label6 = lv_label_create(ui_AppControls1);
    lv_obj_set_width(ui_Label6, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label6, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label6, 4);
    lv_obj_set_y(ui_Label6, 34);
    lv_obj_set_align(ui_Label6, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label6, "Speed Control");

    ui_ChangeColorButton1 = lv_btn_create(ui_AppControls1);
    lv_obj_set_width(ui_ChangeColorButton1, 160);
    lv_obj_set_height(ui_ChangeColorButton1, 27);
    lv_obj_set_align(ui_ChangeColorButton1, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_ChangeColorButton1, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ChangeColorButton1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Label7 = lv_label_create(ui_ChangeColorButton1);
    lv_obj_set_width(ui_Label7, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label7, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label7, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label7, "Set Timer");

    lv_obj_add_event_cb(ui_ChangeColorButton1, ui_event_ChangeColorButton1, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_FanControl, ui_event_FanControl, LV_EVENT_ALL, NULL);

}
