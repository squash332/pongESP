#pragma once
#include "bsp/esp-bsp.h"
#include "lvgl.h"

class Display {
public:
    Display();
    ~Display() = default;


private:
    lv_obj_t* display = nullptr;
};