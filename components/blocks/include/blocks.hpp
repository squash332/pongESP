#pragma once 
#include "constants.hpp"
#include "lvgl.h"
#define TILE_SIZE 16
extern bool blocks[COLS][ROWS];

void initBlocks();
void createBlocks(lv_obj_t* parent);

