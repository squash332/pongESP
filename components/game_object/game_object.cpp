#include "game_object.hpp"


GameObject::GameObject(lv_obj_t* parent) {
    obj = lv_obj_create(parent);
}

void GameObject::setPosition(uint32_t x, uint32_t y) {
    lv_obj_set_pos(obj, x, y);
}

void GameObject::setSize(uint32_t w, uint32_t h) {
    lv_obj_set_size(obj, w, h);
}

void GameObject::setColor(uint32_t color) {
    lv_obj_set_style_bg_color(obj, lv_color_hex(color), LV_PART_MAIN);
    lv_obj_set_style_bg_opa(obj, LV_OPA_COVER, LV_PART_MAIN);
}

lv_obj_t* GameObject::getObj() {
    return obj;
}
// void GameObject::setImg() {
//     lv_obj_set_style_bg_image_src(obj, )
// }