#include <Arduino.h>
#include "voice.h"
#include "hardware.h"
#include "audio_utils.h"
#include "client_ia.h"
#include "config.h"
#include "command_router.h"
#include "status.h"

static int nivel_centro = 2048;

bool voz_inicializar()
{
    long suma = 0;

    for (int i = 0; i < 200; i++)
    {
        suma += leer_microfono();
        delay(2);
    }

    nivel_centro = suma / 200;
    Serial.printf("[VOZ] Nivel de silencio del microfono: %d\n", nivel_centro);

    return true;
}

bool voz_grabar(uint8_t* buffer, size_t capacidad, size_t& bytesGrabados, uint32_t duracionMs)
{
    if (buffer == nullptr)
    {
        return false;
    }

    size_t muestrasMaximas = capacidad / sizeof(int16_t);
    size_t muestras = ((uint64_t)VOZ_SAMPLE_RATE * duracionMs) / 1000;

    if (muestras > muestrasMaximas)
    {
        muestras = muestrasMaximas;
    }

    int16_t* destino = reinterpret_cast<int16_t*>(buffer);
    const uint32_t intervalo = 1000000UL / VOZ_SAMPLE_RATE;
    uint32_t siguiente = micros();

    int minimo = 4095;
    int maximo = 0;

    for (size_t i = 0; i < muestras; i++)
    {
        while ((int32_t)(micros() - siguiente) < 0)
        {
            yield();
        }
        siguiente += intervalo;

        int valor = leer_microfono();
        if (valor < minimo) minimo = valor;
        if (valor > maximo) maximo = valor;

        int muestra = (valor - nivel_centro) * 8;

        if (muestra > 32767)       muestra = 32767;
        else if (muestra < -32768) muestra = -32768;

        destino[i] = (int16_t)muestra;
    }

    bytesGrabados = muestras * sizeof(int16_t);

    Serial.printf("[VOZ] Grabacion: minimo ADC %d | maximo ADC %d\n", minimo, maximo);

    return true;
}

bool voz_procesar()
{
    const size_t pcmBytes = ((uint64_t)VOZ_SAMPLE_RATE * VOZ_DURACION_MS / 1000) * sizeof(int16_t);
    const size_t wavBytes = pcmBytes + 44;

    Serial.printf("[VOZ] Memoria libre: %u | bloque mas grande: %u | necesito: %u\n",
                  ESP.getFreeHeap(), ESP.getMaxAllocHeap(), (unsigned)wavBytes);

    // Un solo bloque: 44 bytes de cabecera + el audio
    uint8_t* wav = (uint8_t*)malloc(wavBytes);
    if (wav == nullptr)
    {
        Serial.println("[VOZ] ERROR: no hay memoria");
        return false;
    }
    uint8_t* pcm = wav + 44;   // el audio se graba justo después de la cabecera

    // 1) Grabar
    size_t bytesGrabados = 0;
    if (!voz_grabar(pcm, pcmBytes, bytesGrabados, VOZ_DURACION_MS))
    {
        Serial.println("[VOZ] ERROR: fallo la grabacion");
        free(wav);
        return false;
    }
    Serial.printf("[VOZ] Grabados %u bytes\n", (unsigned)bytesGrabados);

    // 2) Normalizar: subir el volumen para que el pico llegue a ~80% del máximo
    {
        int16_t* muestras = (int16_t*)pcm;
        size_t n = bytesGrabados / sizeof(int16_t);
        int pico = 1;
        for (size_t i = 0; i < n; i++)
        {
            int v = abs(muestras[i]);
            if (v > pico) pico = v;
        }
        float ganancia = 26000.0f / pico;
        if (ganancia > 1.0f)
        {
            for (size_t i = 0; i < n; i++)
            {
                muestras[i] = (int16_t)(muestras[i] * ganancia);
            }
        }
        Serial.printf("[VOZ] Pico %d, ganancia aplicada x%.1f\n", pico, ganancia);
    }

    // 3) Escribir la cabecera WAV (el audio ya está en su lugar)
    size_t bytesWav = crear_wav(pcm, bytesGrabados, wav, wavBytes);
    if (bytesWav == 0)
    {
        Serial.println("[VOZ] ERROR: fallo crear_wav");
        free(wav);
        return false;
    }

    // 4) Enviar al servidor
    dibujar_pensativos();
    Serial.println("[VOZ] Enviando al servidor...");

    RespuestaIA respuesta;
    bool resultado = ia_procesar_audio(wav, bytesWav, respuesta);
    free(wav);

    if (!resultado)
    {
        Serial.println("[VOZ] ERROR: fallo la comunicacion con el servidor");
        return false;
    }

    // 5) Mostrar la respuesta
    Serial.printf("IA -> comando: %s | valor: %s | respuesta: %s\n",
                  respuesta.comando.c_str(), respuesta.valor.c_str(),
                  respuesta.respuesta.c_str());

    if (respuesta.comando == "NINGUNO")
    {
        dibujar_ojos_neutros();
        return true;
    }

    return ejecutar_comando(respuesta.comando, respuesta.valor);
}