#pragma once
#include "lvgl.h"
#include "game_object.hpp"
#include "constants.hpp"
#include "blocks.hpp"
#include "bsp/esp-bsp.h"
class Ball : public GameObject
{
public:
    Ball(lv_obj_t *parent);
    ~Ball() = default;

    void update() override;
    bool collidedTop();
    bool collidedSides();
    bool collidedBlock();

private:
    int32_t x, y, vx, vy;

};