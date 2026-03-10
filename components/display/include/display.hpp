#pragma once
#include "bsp/esp-bsp.h"
#include "lvgl.h"
#include <cstdint>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

class Display {
public:
    void init();
    void fillScreen(uint16_t color);
    void setCursor(int x, int y);
    void setTextColor(uint16_t color);
    void setTextSize(uint8_t size);
    void print(const char *text);

private:
    lv_obj_t* label = nullptr;
    int cursor_x = 0;
    int cursor_y = 0;
    uint16_t text_color = 0xFFFF;
    uint8_t text_size = 2;
};