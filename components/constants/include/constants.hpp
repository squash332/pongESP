#pragma once

#define DISP lv_display_get_default()
constexpr int DISPLAY_WIDTH  = 320;
constexpr int DISPLAY_HEIGHT = 240;
#define X_OFFSET 10
#define Y_OFFSET 10
#define COLS 12
#define ROWS 4
#define TILE_SIZE 16
#define SPACING 10
#define BALL_SIZE 10
#define PADDLE_Y_POS DISPLAY_HEIGHT - 2*Y_OFFSET
