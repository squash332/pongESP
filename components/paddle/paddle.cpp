#include "paddle.hpp"
extern Touch *touch; // spent 45 mins debugging and realized i was setting positions to an uninitialized object (missing *)

Paddle::Paddle(lv_obj_t *parent) : GameObject(parent)
{

    setSize(50, 10);
    setColor(0xFFFFFF);
    lv_obj_set_pos(obj, DISPLAY_WIDTH / 2 - getWidth() - X_OFFSET, DISPLAY_HEIGHT - getHeight() - 2*Y_OFFSET);
}

void Paddle::update()
{
    // printf("paddle updated pos: %ld\n", touch->x);
    set_x_pos(touch->x);

}

void Paddle::set_x_pos(uint32_t x)
{
    lv_obj_set_x(obj, x - getWidth() / 2);
}
