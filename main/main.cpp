#include "display.hpp"

#include "game_over.hpp"
#include "game_state.hpp"
#include "game.hpp"
#include "menu.hpp"


Touch *touch;
Audio *audio;
static TaskHandle_t playSoundHandle = NULL;
QueueHandle_t soundQueue;

void playSoundTask(void *arg) {
    SoundRequest req;
    
    while(1) {
        if (xQueueReceive(soundQueue, &req, portMAX_DELAY)) {
            audio->stopRequested = true;
            switch(req) {
                case SOUND_GAME_LOAD:
                audio->gameLoad();
                break;
                
                case SOUND_GAME_OVER:
                audio->gameOver();
                break;
    
                case SOUND_BLOCK_BREAK:
                audio->blockBreak();
                break;
            }
        }
    }

}

extern "C" void app_main()
{
    audio = new Audio();
    Display display;
    touch = new Touch();
    soundQueue = xQueueCreate(1, sizeof(SoundRequest));
    xTaskCreate(playSoundTask, "playSoundTask", 4096, NULL, 5, &playSoundHandle);
    setState(GameState::MENU);

    while (true)
    {
        lv_tick_inc(16);
         // instead of handler being after the switch state, it needs to be here
        // if its after the state the program keeps crashing :)

        if (state == GameState::PLAYING) {
            updateGame();
        }
        

        vTaskDelay(pdMS_TO_TICKS(16));
    }
}
