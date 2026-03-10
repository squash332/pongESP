#include "display.hpp"

Display display;
extern "C" void app_main()
{
    bsp_i2c_init();
    
    display.init();
    bsp_display_backlight_on();
    display.fillScreen(0xFFFF);
    display.setCursor(50, 50);
    display.setTextColor(0xF800);
    display.print("wassup");

    while (true) {
        printf("is this working\n");
        vTaskDelay(pdMS_TO_TICKS(1500));
    }
}