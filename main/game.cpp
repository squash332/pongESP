#include "game.hpp"

std::unique_ptr<Paddle> paddle;
std::unique_ptr<Ball> ball;
extern Touch* touch;
Screen* gameScreen;

void gameInit()
{
    gameScreen = new Screen();
    lv_obj_set_style_bg_color(gameScreen->scr, lv_color_hex(0x000000), LV_PART_MAIN);
    lv_disp_load_scr(gameScreen->scr);

    paddle = std::make_unique<Paddle>(gameScreen->scr);
    ball = std::make_unique<Ball>(gameScreen->scr);

    initBlocks();
    createBlocks(gameScreen->scr);
}

void updateGame()
{
    if (ball->active)
    {
        if (touch->read())
        {
            paddle->update();
        }
        ball->update();
    }
    else
    {
        setState(GameState::GAME_OVER);
    }
}

void restartGame()
{
    gameInit();
}