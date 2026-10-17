#include "voice.h"
#include "hardware.h"
#include "audio_utils.h"
#include "client_ia.h"
#include "config.h"
#include "command_router.h"
#include <Arduino.h>

static int nivel_centro = 2048;

bool voz_inicializar()
{
    long suma = 0;
    int i;

    for(i = 0; i < 200; i++)
    {
        suma += leer_microfono();
        delay(2);
    }

    nivel_centro = suma / 200;

    return true;
}

bool voz_grabar(uint8_t* buffer, size_t capacidad, size_t& bytesGrabados, uint32_t duracionMs)
{
    if(buffer == nullptr)
    {
        return false;
    }

    size_t muestrasMaximas = capacidad / sizeof(int16_t);

    size_t muestras = ((uint64_t)VOZ_SAMPLE_RATE * duracionMs) / 1000;

    if(muestras > muestrasMaximas)
    {
        muestras = muestrasMaximas;
    }

    int16_t* destino = reinterpret_cast<int16_t*>(buffer);

    const uint32_t intervalo = 1000000UL / VOZ_SAMPLE_RATE;

    uint32_t siguiente = micros();

    for(size_t i = 0; i < muestras; i++)
    {
        while((int32_t)(micros() - siguiente) < 0)
        {
            yield();
        }

        siguiente += intervalo;

        int valor = leer_microfono();

        int muestra = valor - nivel_centro;

        muestra *= 8;

        if(muestra > 32767)
        {
            muestra = 32767;
        }
        else if(muestra < -32768)
        {
            muestra = -32768;
        }

        destino[i] = (int16_t)muestra;
    }

    bytesGrabados = muestras * sizeof(int16_t);

    return true;
}

bool voz_procesar()
{
    const size_t pcmBytes = ((uint64_t) VOZ_SAMPLE_RATE * VOZ_DURACION_MS / 1000) * sizeof(int16_t);

    const size_t wavBytes = pcmBytes + 44;

    uint8_t* pcm =(uint8_t*)malloc(pcmBytes);

    if(pcm == nullptr)
    {
        return false;
    }

    size_t bytesGrabados = 0;

    bool grabado = voz_grabar(pcm, pcmBytes, bytesGrabados, VOZ_DURACION_MS);

    if(!grabado)
    {
        free(pcm);
        return false;
    }

    uint8_t* wav =(uint8_t*)malloc(wavBytes);

    if(wav == nullptr)
    {
        free(pcm);
        return false;
    }

    size_t bytesWav = crear_wav(pcm, bytesGrabados, wav, wavBytes);

    if(bytesWav == 0)
    {
        free(wav);
        free(pcm);
        return false;
    }

    RespuestaIA respuesta;

    bool resultado = ia_procesar_audio(wav, bytesWav, respuesta);

    free(wav);
    free(pcm);

    if(!resultado)
    {
        return false;
    }

    if(respuesta.comando == "NINGUNO")
    {
        return true;
    }

    return ejecutar_comando(respuesta.comando, respuesta.valor);
}