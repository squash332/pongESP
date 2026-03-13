#include "display.hpp"
#include "ball.hpp"
#include "paddle.hpp"
#include "blocks.hpp"
#include "constants.hpp"

#include "esp_random.h"
#include "esp_log.h"

void game_init(lv_obj_t *src);
Paddle *paddle;
Ball *ball;

extern "C" void app_main()
{
    Display display;
    
    srand(esp_random());
    lv_timer_handler();
    
    game_init(lv_scr_act());
    // Paddle paddle(lv_scr_act());
    // Ball ball(lv_scr_act());
    
    

    while (true)
    {
        ball->update();
        
        // ESP_LOGI("ball", "x:%ld y:%ld\n", ball.getX(), ball.getY());
        lv_timer_handler();

        lv_tick_inc(16);
        vTaskDelay(pdMS_TO_TICKS(16));
    }
}

void game_init(lv_obj_t *src) {
    paddle = new Paddle(src);
    ball = new Ball(src);

    initBlocks();
    createBlocks(src);

}