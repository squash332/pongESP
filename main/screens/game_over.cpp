#include "game_over.hpp"

lv_obj_t* currentScore = nullptr;

static void restart_button_event_cb(lv_event_t *e)
{
    if (lv_event_get_code(e) == LV_EVENT_CLICKED)
    {
        ESP_LOGI("BUTTON EVENT", "PLAY AGAIN PRESSED");
        setState(GameState::PLAYING);
    }
}

static void menu_button_event_cb(lv_event_t *e)
{
    if (lv_event_get_code(e) == LV_EVENT_CLICKED)
    {
        ESP_LOGI("BUTTON EVENT", "MAIN MENU PRESSED");
        setState(GameState::MENU);
    }
}

void createGameOver(uint32_t receivedScore)
{   
    // title
    lv_obj_t *titleLabel = lv_label_create(gameOverScreen->scr);
    lv_label_set_text(titleLabel, "GAME OVER");
    lv_obj_set_style_text_color(titleLabel, lv_color_hex(0xFFFFFF), LV_PART_MAIN);
    lv_obj_align(titleLabel, LV_ALIGN_TOP_MID, 0, LV_PCT(5));

    // score: blabla
    currentScore = lv_label_create(gameOverScreen->scr);
    lv_label_set_text_fmt(currentScore, "SCORE: %ld", receivedScore);
    lv_obj_set_style_text_color(currentScore, lv_color_hex(0xFFFFFF), LV_PART_MAIN);
    lv_obj_align(currentScore, LV_ALIGN_TOP_MID, 0, LV_PCT(15));

    // play again btn
    lv_obj_t *restartButton = lv_button_create(gameOverScreen->scr);
    lv_obj_set_size(restartButton, LV_PCT(50), LV_PCT(15));
    lv_obj_align(restartButton, LV_ALIGN_TOP_MID, 0, LV_PCT(30));
    lv_obj_t *restartLabel = lv_label_create(restartButton);
    lv_label_set_text(restartLabel, "PLAY AGAIN");
    lv_obj_center(restartLabel);

    lv_obj_add_event_cb(restartButton, restart_button_event_cb, LV_EVENT_CLICKED, NULL);

    // back to main menu

    lv_obj_t *menuButton = lv_button_create(gameOverScreen->scr);
    lv_obj_set_size(menuButton, LV_PCT(50), LV_PCT(15));
    lv_obj_align(menuButton, LV_ALIGN_TOP_MID, 0, LV_PCT(60));
    lv_obj_t *menuLabel = lv_label_create(menuButton);
    lv_label_set_text(menuLabel, "MAIN MENU");
    lv_obj_center(menuLabel);

    lv_obj_add_event_cb(menuButton, menu_button_event_cb, LV_EVENT_CLICKED, NULL);

    // timer maybe ?
}

void resetGameOverScreen()
{
    lv_obj_clean(gameOverScreen->scr);
}

