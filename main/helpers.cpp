#include "helpers.hpp"

Touch *touch;
Audio *audio;
Screen *screen;
QueueHandle_t soundQueue;

void app_init()
{
    static Display display;
    touch = new Touch();
    audio = new Audio();
    menuScreen = new Screen();
    gameOverScreen = new Screen();
    gameScreen = new Screen();
    settingsScreen = new Screen();
    setState(GameState::MENU);
}

void playSoundTask(void *arg)
{
    SoundRequest req;

    while (1)
    {
        if (xQueueReceive(soundQueue, &req, portMAX_DELAY))
        {
            switch (req)
            {
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