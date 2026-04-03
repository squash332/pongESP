#pragma once

#include "display.hpp"
#include "game_over.hpp"
#include "game_state.hpp"
#include "game.hpp"
#include "menu.hpp"

void app_init();
void playSoundTask(void *arg);

extern Touch *touch;
extern Audio *audio;
extern Screen *screen;
static TaskHandle_t playSoundHandle;
extern QueueHandle_t soundQueue;