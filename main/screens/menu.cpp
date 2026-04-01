#include "lvgl.h"
#include "game_state.hpp"
#include "menu.hpp"

static void play_button_event_cb(lv_event_t *e)
{
    if (lv_event_get_code(e) == LV_EVENT_CLICKED)
    {
        ESP_LOGI("BUTTON EVENT", "PLAY GAME PRESSED");
        setState(GameState::PLAYING);
    }
}

static void settings_button_event_cb(lv_event_t *e)
{
    if (lv_event_get_code(e) == LV_EVENT_CLICKED)
    {
        ESP_LOGI("BUTTON EVENT", "OPEN SETINGS PRESSED");
        clearMenuScreen();
        createSettings();
        settingsScreen->load();
    }
}

void createMenu()
{
    // lv_obj_set_size(menuScreen->scr, DISPLAY_WIDTH, DISPLAY_HEIGHT);
    lv_obj_set_style_bg_color(menuScreen->scr, lv_color_hex(0x000000), LV_PART_MAIN);
    lv_obj_set_style_bg_opa(menuScreen->scr, LV_OPA_COVER, LV_PART_MAIN);
    lv_obj_center(menuScreen->scr);

    lv_obj_t *title = lv_label_create(menuScreen->scr);
    lv_label_set_text(title, "MAIN MENU");
    lv_obj_set_style_text_color(title, lv_color_hex(0xFFFFFF), LV_PART_MAIN);
    lv_obj_align(title, LV_ALIGN_TOP_MID, 0, 10);

    // mode: to be added (easy, medium, hard?)

    // play button
    lv_obj_t *playButton = lv_button_create(menuScreen->scr);
    lv_obj_set_size(playButton, LV_PCT(50), LV_PCT(15));
    lv_obj_align(playButton, LV_ALIGN_TOP_MID, 0, LV_PCT(30));
    lv_obj_t *playLabel = lv_label_create(playButton);
    lv_label_set_text(playLabel, "PLAY");
    lv_obj_center(playLabel);

    lv_obj_add_event_cb(playButton, play_button_event_cb, LV_EVENT_CLICKED, NULL);

    // timer maybe ?

    // settings btn
    lv_obj_t* settingsButton = lv_button_create(menuScreen->scr);
    lv_obj_set_size(settingsButton, LV_PCT(50), LV_PCT(15));
    lv_obj_align(settingsButton, LV_ALIGN_TOP_MID, 0, LV_PCT(60));
    lv_obj_t* settingsLabel = lv_label_create(settingsButton);
    lv_label_set_text(settingsLabel, "SETTINGS");
    lv_obj_center(settingsLabel);

    lv_obj_add_event_cb(settingsButton, settings_button_event_cb, LV_EVENT_CLICKED, NULL);

}

void clearMenuScreen()
{
    lv_obj_clean(menuScreen->scr);
}
