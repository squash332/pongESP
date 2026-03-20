#include "game.hpp"

std::unique_ptr<Paddle> paddle;
std::unique_ptr<Ball> ball;
extern Touch* touch;

void gameInit(lv_obj_t *src)
{
    lv_obj_clean(src);
    paddle = std::make_unique<Paddle>(src);
    ball = std::make_unique<Ball>(src);

    initBlocks();
    createBlocks(src);
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

void stopGame()
{
    paddle.reset();
    ball.reset();
}