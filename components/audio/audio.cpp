#include "audio.hpp"
Audio::Audio()
{

    speaker_dev = bsp_audio_codec_speaker_init();

    // spiffs init
    bsp_spiffs_mount();

    esp_codec_dev_set_out_vol(speaker_dev, 30);

    esp_codec_dev_sample_info_t fs = {};

    fs.sample_rate = 44100;
    fs.channel = 2;
    fs.bits_per_sample = 16;
    esp_codec_dev_open(speaker_dev, &fs);
}

void Audio::play(const char *path)
{

    FILE *f = fopen(path, "rb");
    if (!f)
    {
        printf("Failed to open file\n");
        return;
    }

    fseek(f, 44, SEEK_SET);
    uint8_t buffer[1024];
    size_t bytes_read;

    while ((bytes_read = fread(buffer, 1, sizeof(buffer), f)) > 0)
    {
        esp_codec_dev_write(speaker_dev, buffer, bytes_read);
    }

    fclose(f);
}

void Audio::gameLoad()
{
    play("/spiffs/game_load.wav");
}

void Audio::gameOver()
{
    play("/spiffs/game_over.wav");
}

void Audio::blockBreak() {
    play("/spiffs/block_break.wav");
}

void Audio::adjustVolume(uint32_t volume)
{
    // TODO scrollbar volume adjuster
}

void Audio::muteAudio()
{
    esp_codec_dev_set_out_vol(speaker_dev, 0);
}
