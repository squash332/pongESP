#include "paddle.hpp"
extern Touch *touch; // spent 45 mins debugging and realized i was setting positions to an uninitialized object (missing *)

Paddle::Paddle(lv_obj_t *parent) : GameObject(parent)
{

    setSize(100, 10);
    setColor(0xFFFFFF);
    lv_obj_align(obj, LV_ALIGN_TOP_LEFT, 0, PADDLE_Y_POS);
    // for some wild reason without forcing the layout update, getWidth() in next line returns 0 so this is necessary
    lv_obj_update_layout(obj);
    lv_obj_set_x(obj, (DISPLAY_WIDTH - getWidth()) / 2);
}

void Paddle::update()
{
    // printf("paddle updated pos: %ld\n", touch->x);
    set_x_pos(touch->x);
}

void Paddle::set_x_pos(uint32_t x)
{
    uint32_t half = getWidth() / 2;
    uint32_t max = DISPLAY_WIDTH - X_OFFSET;

    int32_t new_x;

    if (x < half + X_OFFSET)
    {
        new_x = X_OFFSET;
    }
    else if (x > max - half)
    {
        new_x = max - getWidth();
    }
    else
    {
        new_x = x - half;
    }

    lv_obj_set_x(obj, new_x);
}
