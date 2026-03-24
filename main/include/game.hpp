#pragma once 

#include <memory>
#include "game_state.hpp"
#include "game_object.hpp"
#include "paddle.hpp"
#include "ball.hpp"
#include "touch.hpp"
#include "blocks.hpp"

void gameInit(lv_obj_t *src);
void updateGame();
void restartGame();

extern std::unique_ptr<Paddle> paddle;
extern std::unique_ptr<Ball> ball;