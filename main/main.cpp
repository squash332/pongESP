#include "display.hpp"
#include "ball.hpp"
#include "paddle.hpp"
#include "blocks.hpp"
#include "constants.hpp"
#include "touch.hpp"

#include "esp_random.h"
#include "esp_log.h"

void game_init(lv_obj_t *src);
void show_game_over_overlay(lv_obj_t *src);
Paddle *paddle;
Ball *ball;
Touch *touch;

static bool gameOverShown = false;

extern "C" void app_main()
{
    Display display;
    touch = new Touch();

    srand(esp_random());
    lv_timer_handler();

    game_init(lv_scr_act());
    // Paddle paddle(lv_scr_act());
    // Ball ball(lv_scr_act());

    while (true)
    {
        lv_tick_inc(16);

        if (ball->active)
        {
            if (touch->read())
            {
                paddle->update();
            }
            ball->update();
        }
        else if ( !gameOverShown)
        {
            show_game_over_overlay(lv_scr_act());  
        }

        lv_timer_handler();
        vTaskDelay(pdMS_TO_TICKS(16));
    }
}

void game_init(lv_obj_t *src)
{
    paddle = new Paddle(src);
    ball = new Ball(src);

    initBlocks();
    createBlocks(src);
}

void show_game_over_overlay(lv_obj_t *src) {
    gameOverShown = true;

    lv_obj_clean(src);
    lv_obj_t* panel = lv_obj_create(src);

    lv_obj_set_size(panel, LV_PCT(70), LV_PCT(70));
    lv_obj_set_style_bg_color(panel, lv_color_hex(0x000000), LV_PART_MAIN);
    lv_obj_center(panel);

    lv_obj_t* label = lv_label_create(panel);
    lv_label_set_text(label, "GAME OVER");

    lv_obj_set_style_text_color(label, lv_color_hex(0xFFFFFF), LV_PART_MAIN);
    lv_obj_center(label);

}