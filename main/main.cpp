#include "display.hpp"


extern "C" void app_main()
{
    Display display;
    display.fillScreen(0xFFFFFF);


    while (true) {
        printf("is this working\n");
        vTaskDelay(pdMS_TO_TICKS(1500));
    }
}