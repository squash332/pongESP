#pragma once

#include "game_object.hpp"
#include "game_state.hpp"

void createGameOver(uint32_t score);
void resetGameOverScreen();

extern lv_obj_t *currentScore;