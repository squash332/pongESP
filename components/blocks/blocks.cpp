#include "blocks.hpp"

bool blocks[COLS][ROWS];

lv_obj_t *blocks_objs[COLS][ROWS];

void initBlocks() {

    
    for (auto x = 0; x < COLS; x++) {
        for(auto y = 0; y < ROWS; y++) {
            blocks[x][y] = true;
        }
    }
}

void createBlocks(lv_obj_t* parent) {
    int spacing = 10;
    for(int x = 0; x < COLS; x++) {
        for(int y = 0; y < ROWS; y++) {
            if(blocks[x][y]) {
                lv_obj_t* block = lv_obj_create(parent);
                lv_obj_set_size(block, TILE_SIZE, TILE_SIZE);
                lv_obj_set_pos(block, x * (TILE_SIZE + spacing) + X_OFFSET, y * (TILE_SIZE + spacing - 1) + Y_OFFSET);
                lv_obj_set_style_bg_color(block, lv_color_white(), 0);
                lv_obj_set_style_border_width(block, 0, 0);

                blocks_objs[x][y] = block;
            }
        }
    }
}
