#include "game_state.hpp"
#include "game_over.hpp"
#include "game.hpp"
#include "menu.hpp"

GameState state = GameState::MENU;

void setState(GameState newState) {
    switch(state) {
        case GameState::MENU: hideMenu(); break;
        case GameState::PLAYING: restartGame(); break;
        case GameState::GAME_OVER: hideGameOver(); break;
    }

    state = newState;

    switch(state) {
        case GameState::MENU: showMenu(); break;
        case GameState::PLAYING: gameInit(); break;
        case GameState::GAME_OVER: showGameOver(); break;
    }
}