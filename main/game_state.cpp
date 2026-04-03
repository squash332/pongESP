#include "game_state.hpp"
#include "game_over.hpp"
#include "game.hpp"
#include "menu.hpp"

GameState state = GameState::MENU;
extern QueueHandle_t soundQueue;

void setState(GameState newState)
{
    switch (newState)
    {
    case GameState::MENU:
        if (menuScreen)
            clearMenuScreen();
        createMenu();
        menuScreen->load();
        break;

    case GameState::PLAYING:
        if (gameScreen)
            gameReset();
        gameInit();
        gameScreen->load();
        playSound(SOUND_GAME_LOAD);
        break;

    case GameState::GAME_OVER:
        if (gameOverScreen)
            resetGameOverScreen();
        createGameOver(score);
        gameOverScreen->load();
        playSound(SOUND_GAME_OVER);
        break;

    case GameState::SETTINGS:
        if (settingsScreen)
            clearSettingsScreen();
        createSettings();
        settingsScreen->load();
        break;
    }

    state = newState;
}

void playSound(SoundRequest sound)
{
    if (soundQueue != NULL)
    {
        xQueueOverwrite(soundQueue, &sound);
    }
}