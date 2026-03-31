#include "display.hpp"

Display::Display()
{
    bsp_display_cfg_t cfg = {};
    cfg.lvgl_port_cfg = ESP_LVGL_PORT_INIT_CONFIG();
    cfg.buffer_size = BSP_LCD_H_RES * CONFIG_BSP_LCD_DRAW_BUF_HEIGHT;
    cfg.double_buffer = 0;
    lv_display_t* display = bsp_display_start_with_config(&cfg);
    lv_display_set_default(display);

    bsp_display_backlight_on();
}
