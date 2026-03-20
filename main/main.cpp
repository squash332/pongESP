#include "display.hpp"

#include "game_over.hpp"
#include "game_state.hpp"
#include "game.hpp"
#include "menu.hpp"


Touch *touch = nullptr;

extern "C" void app_main()
{
    Display display;
    touch = new Touch();
    
    lv_timer_handler();
    setState(GameState::MENU);

    while (true)
    {
        lv_tick_inc(16);
        lv_timer_handler(); // instead of handler being after the switch state, it needs to be here
        // if its after the state the program keeps crashing :)

        switch (state)
        {
        case GameState::MENU:
            break;
        case GameState::PLAYING:
            hideGameOver();
            updateGame();
            break;
        case GameState::GAME_OVER:
            break;
        }

        vTaskDelay(pdMS_TO_TICKS(16));
    }
}
