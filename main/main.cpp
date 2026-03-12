#include "display.hpp"
#include "ball.hpp"
#include "esp_random.h"
#include "paddle.hpp"
#include "esp_log.h"

extern "C" void app_main()
{
    Display display;

    srand(esp_random());

    Paddle paddle(lv_scr_act());
    Ball ball(lv_scr_act());

    while (true)
    {
        ball.update();

        // ESP_LOGI("ball", "x:%ld y:%ld\n", ball.getX(), ball.getY());
        lv_timer_handler();

        vTaskDelay(pdMS_TO_TICKS(16));
    }
}