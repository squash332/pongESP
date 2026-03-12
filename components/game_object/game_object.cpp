#include "game_object.hpp"

GameObject::GameObject(lv_obj_t *parent)
{
    obj = lv_obj_create(parent);
}

void GameObject::setPosition(uint32_t x, uint32_t y)
{
    lv_obj_set_pos(obj, x, y);
}

void GameObject::setSize(uint32_t w, uint32_t h)
{
    lv_obj_set_size(obj, w, h);
}

void GameObject::setColor(uint32_t color)
{
    lv_obj_set_style_bg_color(obj, lv_color_hex(color), LV_PART_MAIN);
    lv_obj_set_style_bg_opa(obj, LV_OPA_COVER, LV_PART_MAIN);
}

lv_obj_t *GameObject::getObj()
{
    return obj;
}

int32_t GameObject::getX()
{
    return lv_obj_get_x(obj);
}

int32_t GameObject::getY()
{
    return lv_obj_get_y(obj);
}

uint32_t GameObject::getWidth()
{
    return lv_obj_get_width(obj);
}

uint32_t GameObject::getHeight()
{
    return lv_obj_get_height(obj);
}