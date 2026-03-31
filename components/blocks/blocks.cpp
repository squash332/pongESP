#include "blocks.hpp"
#include <cstdio>

bool blocks[COLS][ROWS];

lv_obj_t *blocks_objs[COLS][ROWS] = {nullptr};

void initBlocks()
{

    for (auto col = 0; col < COLS; col++)
    {
        for (auto row = 0; row < ROWS; row++)
        {
            blocks[col][row] = true;
        }
    }
}

void createBlocks(lv_obj_t *parent)
{
    for (int col = 0; col < COLS; col++)
    {
        for (int row = 0; row < ROWS; row++)
        {
            if (blocks[col][row])
            {
                lv_obj_t *block = lv_obj_create(parent);
                lv_obj_set_size(block, TILE_SIZE, TILE_SIZE);
                lv_obj_set_pos(block, col * (TILE_SIZE + SPACING) + X_OFFSET, row * (TILE_SIZE + SPACING / 2) + Y_OFFSET);
                lv_obj_set_style_bg_color(block, lv_color_hex(0xFFFFFF), 0);
                lv_obj_set_style_border_width(block, 0, 0);
                // printf("Creating block at [%d][%d]\n", col, row);
                blocks_objs[col][row] = block;
            }
        }
    }
}

