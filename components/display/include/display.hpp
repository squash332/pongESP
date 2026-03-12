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


private:
    lv_obj_t* label = nullptr;
};