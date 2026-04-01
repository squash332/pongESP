#pragma once 

#include <memory>
#include "game_state.hpp"
#include "game_object.hpp"
#include "paddle.hpp"
#include "ball.hpp"
#include "touch.hpp"
#include "blocks.hpp"
#include "audio.hpp"
#include "menu.hpp"

void gameInit();
void updateGame();
void gameReset();

extern uint32_t score;
extern std::unique_ptr<Paddle> paddle;
extern std::unique_ptr<Ball> ball;
extern Audio* audio;