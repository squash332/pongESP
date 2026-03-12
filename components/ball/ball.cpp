#include "ball.hpp"

Ball::Ball(lv_obj_t* parent):GameObject(parent) {
    lv_display_t* disp = lv_display_get_default();
    int32_t height = lv_display_get_vertical_resolution(disp);
    int32_t width = lv_display_get_horizontal_resolution(disp);

    setSize(10, 10);
    setColor(0xFFFFFF);
    
    int32_t x = rand() % (width - 10);
    int32_t y = rand() % (height / 2);

    setPosition(x, y);

}

void Ball::update() {
    // move(vx, vy);
}