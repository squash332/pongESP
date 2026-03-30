#pragma once 
#include "lvgl.h"
#include "screen.hpp"
#include "esp_log.h"
#include "esp_heap_caps.h"

enum class GameState {
    MENU, 
    PLAYING,
    GAME_OVER
};

enum SoundRequest {
    SOUND_GAME_LOAD,
    SOUND_GAME_OVER,
    // SOUND_BLOCK_BREAK
};

extern GameState state;
void setState(GameState newState);
void playSound(SoundRequest sound);