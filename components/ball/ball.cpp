#include "ball.hpp"
#include "constants.hpp"

Ball::Ball(lv_obj_t *parent) : GameObject(parent)
{

    setSize(10, 10);
    setColor(0xFFFFFF);

    int32_t x = rand() % (WIDTH - 10);
    int32_t y = rand() % (HEIGHT / 2);

    setPosition(x, y);
}

void Ball::update()
{
    // move(vx, vy);
}