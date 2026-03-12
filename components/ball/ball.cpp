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
    if (x <= X_OFFSET || x > WIDTH - getWidth() - X_OFFSET) {
        vx = -vx;
    }

    // top or btm
    if (y <= Y_OFFSET || y > HEIGHT - getHeight() - Y_OFFSET) { 
        vy = -vy;
    }

    setPosition(x, y);
}