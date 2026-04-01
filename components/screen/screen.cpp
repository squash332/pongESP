#include "screen.hpp"

Screen *menuScreen = nullptr;
Screen *gameScreen = nullptr;
Screen *gameOverScreen = nullptr;
Screen *settingsScreen = nullptr;

Screen::Screen()
{
    scr = lv_obj_create(NULL);
    lv_obj_set_style_bg_color(scr, lv_color_hex(0x000000), LV_PART_MAIN);
    lv_obj_set_style_bg_opa(scr, LV_OPA_COVER, LV_PART_MAIN);
    lv_obj_center(scr);
}

// doesnt destroy old screen
void Screen::load()
{
    lv_screen_load_anim(scr, LV_SCREEN_LOAD_ANIM_FADE_IN, 100, 0, false);
}

void Screen::loadWithDelete()
{
    lv_screen_load_anim(scr, LV_SCREEN_LOAD_ANIM_FADE_IN, 100, 0, true);
}

lv_obj_t *Screen::getScr()
{
    return scr;
}
