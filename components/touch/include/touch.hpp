#pragma once

#include "esp_lcd_touch_gt911.h"
#include "esp_lcd_touch.h"
#include "bsp/esp-bsp.h"

class Touch
{
public:
    Touch();
    ~Touch() = default;

    uint32_t x, y;

private:
    lv_indev_t *indev;
};