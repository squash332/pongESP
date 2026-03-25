#include "screen.hpp"

Screen::Screen() {
    scr = lv_obj_create(NULL);
    lv_obj_set_style_bg_color(scr, lv_color_hex(0x000000), LV_PART_MAIN);
    lv_obj_set_style_bg_opa(scr, LV_OPA_COVER, LV_PART_MAIN);
    lv_obj_t *label = lv_label_create(scr);
    lv_label_set_text(label, "");
    lv_obj_align(label, LV_ALIGN_TOP_LEFT, 10, 10);
    lv_obj_center(scr);
}

void Screen::show() {
    lv_scr_load(scr);
}

void Screen::hide() {
    lv_obj_add_flag(scr, LV_OBJ_FLAG_HIDDEN);
}

lv_obj_t* Screen::getScr() {
    return scr;
}