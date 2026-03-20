#include "game_over.hpp"


static lv_obj_t* gameOverScreen = nullptr;

static void restart_button_event_cb(lv_event_t *e)
{
    if (lv_event_get_code(e) == LV_EVENT_CLICKED)
    {
        setState(GameState::PLAYING);
    }
}

static void menu_button_event_cb(lv_event_t *e)
{
    if (lv_event_get_code(e) == LV_EVENT_CLICKED)
    {
        setState(GameState::MENU);
    }
}

void showGameOver(lv_obj_t *src) {
    
    lv_obj_clean(src);

    // pop-out
    gameOverScreen = lv_obj_create(src);
    lv_obj_set_size(gameOverScreen, LV_PCT(70), LV_PCT(70));
    lv_obj_set_style_bg_color(gameOverScreen, lv_color_hex(0x000000), LV_PART_MAIN);
    lv_obj_center(gameOverScreen);

    // title
    lv_obj_t* titleLabel = lv_label_create(gameOverScreen);
    lv_label_set_text(titleLabel, "GAME OVER");
    lv_obj_set_style_text_color(titleLabel, lv_color_hex(0xFFFFFF), LV_PART_MAIN);
    lv_obj_align(titleLabel, LV_ALIGN_TOP_MID, 0, 0);

    // score: blabla

    
    // play again btn
    lv_obj_t* restartButton = lv_button_create(gameOverScreen);
    lv_obj_set_size(restartButton, LV_PCT(50), LV_PCT(15));
    lv_obj_align(restartButton, LV_ALIGN_TOP_MID, 0, LV_PCT(30));
    lv_obj_t* restartLabel = lv_label_create(restartButton);
    lv_label_set_text(restartLabel, "PLAY AGAIN");
    lv_obj_center(restartLabel);

    lv_obj_add_event_cb(restartButton, restart_button_event_cb, LV_EVENT_CLICKED, NULL);

    // back to main menu

    lv_obj_t* menuButton = lv_button_create(gameOverScreen);
    lv_obj_set_size(menuButton, LV_PCT(50), LV_PCT(15));
    lv_obj_align(menuButton, LV_ALIGN_TOP_MID, 0, LV_PCT(60));
    lv_obj_t* menuLabel = lv_label_create(menuButton);
    lv_label_set_text(menuLabel, "MAIN MENU");
    lv_obj_center(menuLabel);

    lv_obj_add_event_cb(menuButton, menu_button_event_cb, LV_EVENT_CLICKED, NULL);
    
    // timer maybe ?

}

void hideGameOver() {

    if(gameOverScreen) {
        lv_obj_del(gameOverScreen); 
        gameOverScreen = nullptr;
    }
}