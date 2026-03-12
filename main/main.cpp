#include "display.hpp"
#include "ball.hpp"
#include "esp_random.h"
#include "paddle.hpp"

extern "C" void app_main()
{
    Display display;

    srand(esp_random());

    Paddle paddle(lv_scr_act());
    Ball ball(lv_scr_act());

    while (true)
    {
        ball.update();
        lv_timer_handler();
        vTaskDelay(pdMS_TO_TICKS(500));
    }
}