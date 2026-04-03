#include "settings.hpp"

static lv_obj_t *sliderLabel;
static uint32_t volume = 30;

static void back_button_event_cb(lv_event_t *e)
{
    if (lv_event_get_code(e) == LV_EVENT_CLICKED)
    {
        ESP_LOGI("BUTTON EVENT", "GO BACK PRESSED");
        setState(GameState::MENU);
    }
}

static void slider_event_cb(lv_event_t *e)
{
    lv_obj_t *slider = lv_event_get_target_obj(e);
    ESP_LOGI("SLIDER EVENT", "SLIDER REARRANGED");
    volume = lv_slider_get_value(slider);
    audio->adjustVolume(volume);
    lv_label_set_text_fmt(sliderLabel, "NEW VOLUME: %ld", volume);
    lv_obj_align_to(sliderLabel, settingsScreen->scr, LV_ALIGN_TOP_MID, 0, LV_PCT(40));
}

static void test_volume_event_cb(lv_event_t *e)
{
    ESP_LOGI("TEST EVENT:", "SOUND VOLUME");
    playSound(SOUND_BLOCK_BREAK);

}

void createSettings()
{

    // title
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

    // volume
    lv_obj_t *slider = lv_slider_create(settingsScreen->scr);
    lv_obj_set_width(slider, LV_PCT(80));
    lv_obj_align(slider, LV_ALIGN_TOP_MID, 0, LV_PCT(50));
    lv_slider_set_value(slider, volume, LV_ANIM_OFF);

    sliderLabel = lv_label_create(settingsScreen->scr);
    lv_obj_set_style_text_color(sliderLabel, lv_color_hex(0xFFFFFF), LV_PART_MAIN);
    lv_label_set_text_fmt(sliderLabel, "CURRENT VOLUME: %ld", volume);
    lv_obj_align_to(sliderLabel, settingsScreen->scr, LV_ALIGN_TOP_MID, 0, LV_PCT(35));

    lv_obj_add_event_cb(slider, slider_event_cb, LV_EVENT_VALUE_CHANGED, NULL);
    lv_obj_add_event_cb(slider, test_volume_event_cb, LV_EVENT_DOUBLE_CLICKED, NULL);


}

void clearSettingsScreen()
{
    lv_obj_clean(settingsScreen->scr);
}