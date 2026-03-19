#pragma once
#include "lvgl.h"
#include "game_object.hpp"
#include "constants.hpp"
#include "blocks.hpp"
#include "bsp/esp-bsp.h"
#include "paddle.hpp"
class Ball : public GameObject
{
public:
    Ball(lv_obj_t *parent);
    ~Ball() = default;

    void update() override;
    bool collidedTop();
    bool gameOver();
    bool collidedSides();
    bool collidedBlock();
    bool collidedPaddle();

    int16_t getCenterX() const;
    int16_t getCenterY() const;
    int16_t getBallCol() const;
    int16_t getBallRow() const;

    bool active = true;
private:
    int32_t x, y, vx, vy;

};