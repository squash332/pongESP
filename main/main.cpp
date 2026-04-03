#include "helpers.hpp"


extern "C" void app_main()
{
    app_init();

    soundQueue = xQueueCreate(1, sizeof(SoundRequest));
    xTaskCreate(playSoundTask, "playSoundTask", 4096, NULL, 5, &playSoundHandle);

    while (true)
    {
        lv_tick_inc(16);
        if (state == GameState::PLAYING)
        {
            updateGame();
        }
        vTaskDelay(pdMS_TO_TICKS(16));
    }
}
