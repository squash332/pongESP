#pragma once
#include "bsp/esp-bsp.h"
#include "lvgl.h"
#include <cstdint>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

class Display {
public:
    Display();
    ~Display() = default;

    void init();
    void fillScreen(uint32_t color);
    void setCursor(int x, int y);
    void setTextColor(uint32_t color);
    void setTextSize(uint8_t size);
    void print(const char *text);

private:
    lv_obj_t* label = nullptr;
    int cursor_x = 0;
    int cursor_y = 0;
    uint32_t text_color = 0xFFFFFF;
    uint8_t text_size = 2;
};