#pragma once

#include "bsp/esp-bsp.h"
#include "esp_spiffs.h"
#include "audio_player.h"

#define SPIFFS_BASE "/spiffs"

class Audio
{
public:
    Audio();
    ~Audio() = default;

    esp_codec_dev_handle_t speaker_dev;

    void play(const char *path);
    void gameLoad();
    void gameOver();
    void blockBreak();
    void adjustVolume(uint32_t volume);
    void muteAudio();
};
