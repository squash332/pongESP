#pragma once 
#include "lvgl.h"
#include "screen.hpp"
#include "esp_log.h"

enum class GameState {
    MENU, 
    PLAYING,
    GAME_OVER
};

extern GameState state;
void setState(GameState newState);