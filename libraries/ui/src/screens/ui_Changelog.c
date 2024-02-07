// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.4
// LVGL version: 8.3.6
// Project name: knobOS

#include "../ui.h"

void ui_Changelog_screen_init(void)
{
    ui_Changelog = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Changelog, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_flex_flow(ui_Changelog, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_Changelog, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER);

    ui_Label4 = lv_label_create(ui_Changelog);
    lv_obj_set_width(ui_Label4, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label4, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label4, -32);
    lv_obj_set_y(ui_Label4, -56);
    lv_obj_set_align(ui_Label4, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label4, "Changelog");
    lv_obj_set_style_text_color(ui_Label4, lv_color_hex(0x3171DE), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label4, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label5 = lv_label_create(ui_Changelog);
    lv_obj_set_width(ui_Label5, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label5, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label5, 1);
    lv_obj_set_y(ui_Label5, -6);
    lv_obj_set_align(ui_Label5, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label5, "- Added LVGL\n- Added FlashScreen\n- Corrected Orientation\n- Added Touch Controls");
    lv_obj_set_style_text_color(ui_Label5, lv_color_hex(0x6B6B6D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label5, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label5, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_Changelog, ui_event_Changelog, LV_EVENT_ALL, NULL);

}
