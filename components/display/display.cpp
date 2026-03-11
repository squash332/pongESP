#include "display.hpp"

Display::Display()
{
    init();
}

void Display::init()
{
    bsp_display_cfg_t cfg = {
        .lvgl_port_cfg = ESP_LVGL_PORT_INIT_CONFIG(),
        .buffer_size = BSP_LCD_H_RES * CONFIG_BSP_LCD_DRAW_BUF_HEIGHT,
        .double_buffer = 0};
    bsp_display_start_with_config(&cfg);

    bsp_display_backlight_on();

    lv_obj_t *scr = lv_scr_act();
    label = lv_label_create(scr);
    lv_label_set_text(label, "");
    lv_obj_align(label, LV_ALIGN_TOP_LEFT, 10, 10);
}

void Display::fillScreen(uint32_t color)
{   
    lv_obj_t *scr = lv_scr_act();
    lv_obj_set_style_bg_color(scr, lv_color_hex(color), LV_PART_MAIN);
    lv_obj_set_style_bg_opa(scr, LV_OPA_COVER, LV_PART_MAIN);
}


