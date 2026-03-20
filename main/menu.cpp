#include "game_object.hpp"
#include "game_state.hpp"
#include "menu.hpp"
#include "constants.hpp"

static lv_obj_t *menuScreen = nullptr;

static void play_button_event_cb(lv_event_t *e)
{
    if (lv_event_get_code(e) == LV_EVENT_CLICKED)
    {
        setState(GameState::PLAYING);
    }
}

void showMenu(lv_obj_t *src)
{
    lv_obj_clean(src);
    menuScreen = lv_obj_create(src);
    lv_obj_set_size(menuScreen, DISPLAY_WIDTH, DISPLAY_HEIGHT);
    lv_obj_set_style_bg_color(menuScreen, lv_color_hex(0x000000), LV_PART_MAIN);
    lv_obj_set_style_bg_opa(menuScreen, LV_OPA_COVER, LV_PART_MAIN);
    lv_obj_center(menuScreen);

    lv_obj_t *title = lv_label_create(menuScreen);
    lv_label_set_text(title, "MAIN MENU");
    lv_obj_set_style_text_color(title, lv_color_hex(0xFFFFFF), LV_PART_MAIN);
    lv_obj_align(title, LV_ALIGN_TOP_MID, 0, 0);

    // mode: to be added (easy, medium, hard?)

    // play button
    lv_obj_t *playButton = lv_button_create(menuScreen);
    lv_obj_set_size(playButton, LV_PCT(40), LV_PCT(15));
    lv_obj_align(playButton, LV_ALIGN_TOP_MID, 0, LV_PCT(40));
    lv_obj_t *playLabel = lv_label_create(playButton);
    lv_label_set_text(playLabel, "PLAY");
    lv_obj_center(playLabel);

    lv_obj_add_event_cb(playButton, play_button_event_cb, LV_EVENT_CLICKED, NULL);

    // timer maybe ?
}

void hideMenu()
{
    if (menuScreen)
    {
        lv_obj_del(menuScreen);
        menuScreen = nullptr;
    }
}
