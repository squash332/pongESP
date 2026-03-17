#pragma once
#include "lvgl.h"
#include "game_object.hpp"

class Paddle : public GameObject
{
public:
    Paddle(lv_obj_t *parent);
    ~Paddle() = default;

    void update() override;

private:
    int32_t x_pos;
};