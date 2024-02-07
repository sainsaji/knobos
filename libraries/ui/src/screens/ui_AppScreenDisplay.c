// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.4
// LVGL version: 8.3.6
// Project name: knobOS

#include "../ui.h"

void ui_AppScreenDisplay_screen_init(void)
{
    ui_AppScreenDisplay = lv_obj_create(NULL);
    lv_obj_add_flag(ui_AppScreenDisplay, LV_OBJ_FLAG_SCROLL_ONE);     /// Flags
    lv_obj_set_flex_flow(ui_AppScreenDisplay, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_AppScreenDisplay, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_SPACE_BETWEEN);
    lv_obj_set_style_bg_color(ui_AppScreenDisplay, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_AppScreenDisplay, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_AppScreen = lv_obj_create(ui_AppScreenDisplay);
    lv_obj_set_width(ui_AppScreen, 150);
    lv_obj_set_height(ui_AppScreen, 148);
    lv_obj_set_x(ui_AppScreen, 73);
    lv_obj_set_y(ui_AppScreen, -33);
    lv_obj_set_align(ui_AppScreen, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_AppScreen, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_AppScreen, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_add_flag(ui_AppScreen, LV_OBJ_FLAG_SCROLL_ON_FOCUS | LV_OBJ_FLAG_SCROLL_ONE);     /// Flags
    lv_obj_clear_flag(ui_AppScreen, LV_OBJ_FLAG_SCROLL_MOMENTUM);      /// Flags
    lv_obj_set_style_border_color(ui_AppScreen, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_AppScreen, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_AppScreen, 30, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_AppScreen, 30, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_AppScreen, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_AppScreen, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui_AppScreen, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_AppScreen, 10, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_AppScreen, lv_color_hex(0x3272DE), LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_AppScreen, 255, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);

    ui_AppComponent2 = lv_obj_create(ui_AppScreen);
    lv_obj_set_width(ui_AppComponent2, 100);
    lv_obj_set_height(ui_AppComponent2, 96);
    lv_obj_set_x(ui_AppComponent2, -336);
    lv_obj_set_y(ui_AppComponent2, -159);
    lv_obj_set_align(ui_AppComponent2, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_AppComponent2, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_AppComponent2, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(ui_AppComponent2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    lv_obj_set_style_pad_left(ui_AppComponent2, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_AppComponent2, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_AppComponent2, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_AppComponent2, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui_AppComponent2, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_AppComponent2, 10, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);

    ui_AppImage1 = lv_img_create(ui_AppComponent2);
    lv_img_set_src(ui_AppImage1, &ui_img_lightbulb_png);
    lv_obj_set_width(ui_AppImage1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_AppImage1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_AppImage1, -7);
    lv_obj_set_y(ui_AppImage1, -4);
    lv_obj_set_align(ui_AppImage1, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_AppImage1, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_AppImage1, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_END, LV_FLEX_ALIGN_START);
    lv_obj_add_flag(ui_AppImage1, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_AppImage1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_AppLabel1 = lv_label_create(ui_AppComponent2);
    lv_obj_set_width(ui_AppLabel1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_AppLabel1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_AppLabel1, -3);
    lv_obj_set_y(ui_AppLabel1, 26);
    lv_obj_set_align(ui_AppLabel1, LV_ALIGN_CENTER);
    lv_label_set_text(ui_AppLabel1, "Light Control");

    ui_AppComponent3 = lv_obj_create(ui_AppScreen);
    lv_obj_set_width(ui_AppComponent3, 100);
    lv_obj_set_height(ui_AppComponent3, 96);
    lv_obj_set_x(ui_AppComponent3, -336);
    lv_obj_set_y(ui_AppComponent3, -159);
    lv_obj_set_align(ui_AppComponent3, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_AppComponent3, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_AppComponent3, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(ui_AppComponent3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    lv_obj_set_style_pad_left(ui_AppComponent3, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_AppComponent3, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_AppComponent3, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_AppComponent3, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui_AppComponent3, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_AppComponent3, 10, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);

    ui_AppImage4 = lv_img_create(ui_AppComponent3);
    lv_img_set_src(ui_AppImage4, &ui_img_fan_png);
    lv_obj_set_width(ui_AppImage4, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_AppImage4, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_AppImage4, -7);
    lv_obj_set_y(ui_AppImage4, -4);
    lv_obj_set_align(ui_AppImage4, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_AppImage4, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_AppImage4, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_END, LV_FLEX_ALIGN_START);
    lv_obj_add_flag(ui_AppImage4, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_AppImage4, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_AppLabel4 = lv_label_create(ui_AppComponent3);
    lv_obj_set_width(ui_AppLabel4, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_AppLabel4, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_AppLabel4, -3);
    lv_obj_set_y(ui_AppLabel4, 26);
    lv_obj_set_align(ui_AppLabel4, LV_ALIGN_CENTER);
    lv_label_set_text(ui_AppLabel4, "Fan Control");

    ui_AppComponent4 = lv_obj_create(ui_AppScreen);
    lv_obj_set_width(ui_AppComponent4, 100);
    lv_obj_set_height(ui_AppComponent4, 96);
    lv_obj_set_x(ui_AppComponent4, -336);
    lv_obj_set_y(ui_AppComponent4, -159);
    lv_obj_set_align(ui_AppComponent4, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_AppComponent4, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_AppComponent4, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(ui_AppComponent4, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    lv_obj_set_style_pad_left(ui_AppComponent4, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_AppComponent4, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_AppComponent4, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_AppComponent4, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui_AppComponent4, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_AppComponent4, 10, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);

    ui_AppImage3 = lv_img_create(ui_AppComponent4);
    lv_img_set_src(ui_AppImage3, &ui_img_laptop_png);
    lv_obj_set_width(ui_AppImage3, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_AppImage3, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_AppImage3, -7);
    lv_obj_set_y(ui_AppImage3, -4);
    lv_obj_set_align(ui_AppImage3, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_AppImage3, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_AppImage3, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_END, LV_FLEX_ALIGN_START);
    lv_obj_add_flag(ui_AppImage3, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_AppImage3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_AppLabel3 = lv_label_create(ui_AppComponent4);
    lv_obj_set_width(ui_AppLabel3, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_AppLabel3, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_AppLabel3, -3);
    lv_obj_set_y(ui_AppLabel3, 26);
    lv_obj_set_align(ui_AppLabel3, LV_ALIGN_CENTER);
    lv_label_set_text(ui_AppLabel3, "Lap Control");

    ui_Panel2 = lv_obj_create(ui_AppScreenDisplay);
    lv_obj_set_width(ui_Panel2, 33);
    lv_obj_set_height(ui_Panel2, 33);
    lv_obj_set_x(ui_Panel2, 14);
    lv_obj_set_y(ui_Panel2, 80);
    lv_obj_set_align(ui_Panel2, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_Panel2, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_Panel2, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Panel2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Panel2, 100, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Panel2, lv_color_hex(0x2040BD), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Panel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_Panel2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Panel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label2 = lv_label_create(ui_Panel2);
    lv_obj_set_width(ui_Label2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label2, 9);
    lv_obj_set_y(ui_Label2, 39);
    lv_obj_set_align(ui_Label2, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label2, "i");

    lv_obj_add_event_cb(ui_AppComponent2, ui_event_AppComponent2, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Panel2, ui_event_Panel2, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_AppScreenDisplay, ui_event_AppScreenDisplay, LV_EVENT_ALL, NULL);

}
