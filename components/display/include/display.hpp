#pragma once
#include "bsp/esp-bsp.h"
#include "lvgl.h"
#include <cstdint>
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

class Display {
public:
    Display();
    ~Display() = default;

    lv_obj_t* getRoot(); // parent for game objects for easier child positioning
    void fillScreen(uint32_t color);

private:
    lv_obj_t* label = nullptr;
};