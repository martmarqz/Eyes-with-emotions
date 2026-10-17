#include "audio_utils.h"

#define WAV_HEADER_SIZE 44

static void escribir_uint16(uint8_t* destino, uint16_t valor)
{
    destino[0] = valor & 0xFF;
    destino[1] = (valor >> 8) & 0xFF;
}

static void escribir_uint32(uint8_t* destino, uint32_t valor)
{
    destino[0] = valor & 0xFF;
    destino[1] = (valor >> 8) & 0xFF;
    destino[2] = (valor >> 16) & 0xFF;
    destino[3] = (valor >> 24) & 0xFF;
}

size_t crear_wav(const uint8_t* pcm, size_t bytesPcm, uint8_t* wav, size_t capacidadWav)
{
    if(pcm == nullptr)
    {
        return 0;
    }

    if(wav == nullptr)
    {
        return 0;
    }

    if(capacidadWav < bytesPcm + WAV_HEADER_SIZE)
    {
        return 0;
    }

    const uint32_t sampleRate = 8000;
    const uint16_t canales = 1;
    const uint16_t bits = 16;

    const uint16_t blockAlign = canales * (bits / 8);

    const uint32_t byteRate = sampleRate * blockAlign;

    memcpy(wav + 0, "RIFF", 4);

    escribir_uint32(wav + 4, 36 + bytesPcm);

    memcpy(wav + 8, "WAVE", 4);

    memcpy(wav + 12, "fmt ", 4);

    escribir_uint32(wav + 16, 16);

    escribir_uint16(wav + 20, 1);

    escribir_uint16(wav + 22, canales);

    escribir_uint32(wav + 24, sampleRate);

    escribir_uint32(wav + 28, byteRate);

    escribir_uint16(wav + 32, blockAlign);

    escribir_uint16(wav + 34, bits);

    memcpy(wav + 36, "data", 4);

    escribir_uint32(wav + 40, bytesPcm);

    memcpy(wav + 44, pcm, bytesPcm);

    return bytesPcm + WAV_HEADER_SIZE;
}