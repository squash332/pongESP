#include "game.hpp"

std::unique_ptr<Paddle> paddle;
std::unique_ptr<Ball> ball;
Screen* gameScreen;
uint32_t score =0;

static void my_touch_cb(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);

    if (code == LV_EVENT_PRESSING)
    {
        lv_indev_t * indev = lv_indev_get_act();
        if (!indev || !paddle) return;

        lv_point_t point;
        lv_indev_get_point(indev, &point);

        paddle->set_x_pos(point.x);
    }
}

void gameInit()
{
    gameScreen = new Screen();
    lv_obj_set_style_bg_color(gameScreen->scr, lv_color_hex(0x000000), LV_PART_MAIN);
    lv_scr_load(gameScreen->scr);

    paddle = std::make_unique<Paddle>(gameScreen->scr);
    ball = std::make_unique<Ball>(gameScreen->scr); 

    
    initBlocks();
    createBlocks(gameScreen->scr);

    lv_obj_add_event_cb(gameScreen->scr, my_touch_cb, LV_EVENT_PRESSING, NULL);
}

void updateGame()
{
    if (ball->active)
    {
        ball->update();
    }
    else
    {
        score = calculateScore();
        setState(GameState::GAME_OVER);
        ESP_LOGI("UPDATE GAME:", "STATE_CHANGE CALLED");
    }
}

void hideGame()
{
    paddle.reset();
    ball.reset();
    resetBlocks(gameScreen->scr);
    if (gameScreen) {
        lv_obj_del_async(gameScreen->scr);
        gameScreen = nullptr;
    }

}