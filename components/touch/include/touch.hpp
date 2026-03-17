#pragma once

#include "lvgl.h"
#include "esp_lcd_touch_gt911.h"
#include "esp_lcd_touch.h"
#include "bsp/esp-bsp.h"

class Touch {
    public:
        Touch();
        ~Touch() = default;
        bool read(uint32_t &x, uint32_t &y);

    private: 
        lv_indev_t* indev;

};