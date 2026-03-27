#include "game.hpp"

std::unique_ptr<Paddle> paddle;
std::unique_ptr<Ball> ball;
extern Touch* touch;
Screen* gameScreen;
uint32_t score =0;

void gameInit()
{
    gameScreen = new Screen();
    lv_obj_set_style_bg_color(gameScreen->scr, lv_color_hex(0x000000), LV_PART_MAIN);
    lv_scr_load(gameScreen->scr);

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
        if(ball->hitBlock) {
            playSound(SOUND_BLOCK_BREAK);
        }
        ball->update();
    }
    else
    {
        score = calculateScore();
        setState(GameState::GAME_OVER);
    }
}

void hideGame()
{
    if (gameScreen) {
        lv_obj_delete(gameScreen->scr);
        delete gameScreen;               
        gameScreen = nullptr;
    }

    paddle.reset();
    ball.reset();
}