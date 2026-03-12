#pragma once
#include "lvgl.h"
#include "game_object.hpp"

class Ball : public GameObject
{
public:
    Ball(lv_obj_t *parent);
    ~Ball() = default;

    void update() override;

    /**********************
     * DEPRECATED FUNCTIONS
     **********************/

    // start in a random direction, random spawn, ball needs to spawn in the top half of the display
    // random spawn - done
    // movement directions? 
    // get current x and y coordinate of ball

private:
    int32_t x, y, vx, vy;

};