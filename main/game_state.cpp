#include "game_state.hpp"
#include "game_over.hpp"
#include "game.hpp"
#include "menu.hpp"

GameState state = GameState::MENU;
extern QueueHandle_t soundQueue;

void setState(GameState newState) {
    switch(state) {
        case GameState::MENU: hideMenu(); break;
        case GameState::PLAYING: hideGame(); break;
        case GameState::GAME_OVER: hideGameOver(); break;
    }

    state = newState;

    switch(state) {
        case GameState::MENU:
        showMenu();
        break;

        case GameState::PLAYING:
        gameInit();
        playSound(SOUND_GAME_LOAD);
        break;

        case GameState::GAME_OVER:
        showGameOver(score);
        playSound(SOUND_GAME_OVER);
        break;
    }
}

void playSound(SoundRequest sound) {
    if (soundQueue != NULL) {
        xQueueSend(soundQueue, &sound, 0);
    }
}