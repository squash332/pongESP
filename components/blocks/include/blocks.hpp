#pragma once
#include "constants.hpp"
#include "lvgl.h"
extern bool blocks[COLS][ROWS];
extern lv_obj_t *blocks_objs[COLS][ROWS];

void initBlocks();
void createBlocks(lv_obj_t *parent);
