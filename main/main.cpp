#include "display.hpp"
#include "ball.hpp"
#include "esp_random.h"


extern "C" void app_main()
{
    Display display;
    display.fillScreen(0x000000);
    
    srand(esp_random());
    GameObject paddle(lv_scr_act());
    paddle.setSize(70, 10);
    paddle.setColor(0xFFFFFF); 
    paddle.setPosition(125, 220);;
    
    Ball ball(lv_scr_act());

    while (true) {
        ball.update();
        lv_timer_handler();
        vTaskDelay(pdMS_TO_TICKS(10));
    }
}