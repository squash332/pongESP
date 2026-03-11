#include "display.hpp"
#include "game_object.hpp"


extern "C" void app_main()
{
    Display display;
    display.fillScreen(0x000000);

    GameObject paddle(lv_scr_act());

    paddle.setSize(70, 10);
    paddle.setColor(0xFFFFFF);
    paddle.setPosition(125, 220);

    while (true) {
        vTaskDelay(pdMS_TO_TICKS(1500));
    }
}