#include "paddle.hpp"

Paddle::Paddle(lv_obj_t *parent) : GameObject(parent)
{

    setSize(170, 10);
    setColor(0xFFFFFF);
    lv_obj_align(obj, LV_ALIGN_TOP_MID, 0, 220);
}

void Paddle::update()
{
}
