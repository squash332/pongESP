#include "ball.hpp"
#include "constants.hpp"

Ball::Ball(lv_obj_t *parent) : GameObject(parent)
{

    setSize(10, 10);
    setColor(0xFFFFFF);

    x = rand() % (WIDTH - 10);
    y = rand() % (HEIGHT / 2);

    vx = 2;
    vy = 2;

    setPosition(x, y);
}

void Ball::update()
{
    x += vx;
    y += vy;

    // left right
    if (x <= 0 || x > WIDTH - getWidth()) {
        vx = -vx;
    }

    // top or btm
    if (y <= 0 || y > HEIGHT - getHeight()) { 
        vy = -vy;
    }

    setPosition(x, y);
}