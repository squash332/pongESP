#include "game.hpp"

std::unique_ptr<Paddle> paddle;
std::unique_ptr<Ball> ball;
uint32_t score = 0;

static void my_touch_cb(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);

    if (code == LV_EVENT_PRESSING)
    {
        lv_indev_t *indev = lv_indev_get_act();
        if (!indev || !paddle)
            return;

        lv_point_t point;
        lv_indev_get_point(indev, &point);

        paddle->set_x_pos(point.x);
    }
}

void gameInit()
{
    paddle = std::make_unique<Paddle>(gameScreen->scr);
    ball = std::make_unique<Ball>(gameScreen->scr);
    ball->active = true;
    ball->score = 0;
    ball->block_count = COLS * ROWS;

    initBlocks();
    createBlocks(gameScreen->scr);

    lv_obj_add_event_cb(gameScreen->scr, my_touch_cb, LV_EVENT_PRESSING, NULL);
    ESP_LOGI("BALL STATUS", "%p", ball->active);
}

void updateGame()
{
    if (ball->active)
    {
        if(ball->hitBlock) {
            playSound(SOUND_BLOCK_BREAK);
        }
        ball->update();
    }
    else
    {
        score = ball->getScore();
        setState(GameState::GAME_OVER);
        ESP_LOGI("UPDATE GAME:", "STATE_CHANGE CALLED");
    }
}

void gameReset()
{
    if (ball) {
        ball->active = false;
    }

    score = 0;
    lv_obj_clean(gameScreen->scr);
    paddle.reset();
    ball.reset();
}
