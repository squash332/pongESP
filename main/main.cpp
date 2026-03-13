#include "display.hpp"
#include "ball.hpp"
#include "paddle.hpp"
#include "blocks.hpp"

#include "esp_random.h"
#include "esp_log.h"

extern "C" void app_main()
{
    Display display;

    srand(esp_random());
    lv_timer_handler();

    Paddle paddle(lv_scr_act());
    Ball ball(lv_scr_act());
    Block block(lv_scr_act(), 50, 50);

    while (true)
    {
        ball.update();

        // ESP_LOGI("ball", "x:%ld y:%ld\n", ball.getX(), ball.getY());
        lv_timer_handler();

        vTaskDelay(pdMS_TO_TICKS(16));
    }
}