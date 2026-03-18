#pragma once
#include "lvgl.h"
#include "game_object.hpp"
#include "touch.hpp"

class Paddle : public GameObject
{
public:
    Paddle(lv_obj_t *parent);
    ~Paddle() = default;

    void update() override;
    void set_x_pos(uint32_t x);    

private:
    uint32_t x;
};