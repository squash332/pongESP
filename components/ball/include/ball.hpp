#pragma once
#include "lvgl.h"
#include "game_object.hpp"
#include "constants.hpp"
class Ball : public GameObject
{
public:
    Ball(lv_obj_t *parent);
    ~Ball() = default;

    void update() override;

private:
    int32_t x, y, vx, vy;

};