#include "settings.hpp"

static void back_button_event_cb(lv_event_t *e)
{
    if (lv_event_get_code(e) == LV_EVENT_CLICKED)
    {
        ESP_LOGI("BUTTON EVENT", "GO BACK PRESSED");
        setState(GameState::MENU);
    }
}

void createSettings() {
    
    //title
    lv_obj_t *titleLabel = lv_label_create(settingsScreen->scr);
    lv_label_set_text(titleLabel, "SETTINGS");
    lv_obj_set_style_text_color(titleLabel, lv_color_hex(0xFFFFFF), LV_PART_MAIN);
    lv_obj_align(titleLabel, LV_ALIGN_TOP_MID, 0, LV_PCT(5));

    // back button 
    lv_obj_t *backLabel = lv_label_create(settingsScreen->scr);
    lv_obj_set_size(backLabel, LV_PCT(30), LV_PCT(30));
    lv_obj_align(backLabel, LV_ALIGN_TOP_LEFT, LV_PCT(5), LV_PCT(6));
    lv_obj_set_style_text_color(backLabel, lv_color_hex(0xFFFFFF), LV_PART_MAIN);
    lv_label_set_text(backLabel, "<----");
    lv_obj_add_flag(backLabel, LV_OBJ_FLAG_CLICKABLE);

    lv_obj_add_event_cb(backLabel, back_button_event_cb, LV_EVENT_CLICKED, NULL);
}

void clearSettingsScreen() {
    lv_obj_clean(settingsScreen->scr);
}