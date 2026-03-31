#pragma once
#include "lvgl.h"

class Screen
{
public:
    lv_obj_t *scr;

    Screen();
    ~Screen() = default;

    lv_obj_t *getScr();
    lv_obj_t *label;

    void load();
    void loadWithDelete();
};

extern Screen *menuScreen;
extern Screen *gameScreen;
extern Screen *gameOverScreen;