#pragma once
#include "lvgl.h"

class Screen {
    public:
    lv_obj_t* scr;

    Screen(); // h and w in % ranged [0,100]
    ~Screen() = default;
    
    lv_obj_t* getScr();
    lv_obj_t* label;

    void show();
    void hide();
};