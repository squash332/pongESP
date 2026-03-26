#include "display.hpp"

#include "game_over.hpp"
#include "game_state.hpp"
#include "game.hpp"
#include "menu.hpp"


Touch *touch;
Audio *audio;

extern "C" void app_main()
{
    audio = new Audio();
    Display display;
    touch = new Touch();

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
