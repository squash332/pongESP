#include "display.hpp"

void Display::init() {
    bsp_display_cfg_t cfg = {
        .lvgl_port_cfg = ESP_LVGL_PORT_INIT_CONFIG(),
        .buffer_size   = BSP_LCD_H_RES * CONFIG_BSP_LCD_DRAW_BUF_HEIGHT,
        .double_buffer = 0
    };
    bsp_display_start_with_config(&cfg);

    bsp_display_backlight_on();

    lv_obj_t* scr = lv_scr_act();
    label = lv_label_create(scr);
    lv_label_set_text(label, "");
    lv_obj_align(label, LV_ALIGN_TOP_LEFT, 10, 10);
}

void Display::fillScreen(uint16_t color) {
    lv_obj_set_style_bg_color(lv_scr_act(),
                              lv_color_make(color >> 8, color & 0xFF, 0),
                              LV_PART_MAIN);
}

void Display::setCursor(int x, int y) {
    cursor_x = x;
    cursor_y = y;
}

void Display::setTextColor(uint16_t color) {
    text_color = color;
}

void Display::setTextSize(uint8_t size) {
    text_size = size;
}

void Display::print(const char* text) {
    if (!label) return;
    lv_label_set_text(label, text);
    lv_obj_set_pos(label, cursor_x, cursor_y);
    lv_obj_set_style_text_color(label,
                                lv_color_make(text_color >> 8, text_color & 0xFF, 0),
                                LV_PART_MAIN);
    lv_obj_invalidate(label);
}