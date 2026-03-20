#include "game_state.hpp"
#include "game_over.hpp"
#include "game.hpp"
#include "menu.hpp"

GameState state = GameState::MENU;

void setState(GameState newState) {
    switch(state) {
        case GameState::MENU: hideMenu(); break;
        case GameState::PLAYING: stopGame(); break;
        case GameState::GAME_OVER: hideGameOver(); break;
    }

    state = newState;

    switch(state) {
        case GameState::MENU: showMenu(ACTIVE_SCREEN()); break;
        case GameState::PLAYING: gameInit(ACTIVE_SCREEN()); break;
        case GameState::GAME_OVER: showGameOver(ACTIVE_SCREEN()); break;
    }
}