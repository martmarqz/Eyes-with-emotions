#ifndef AUDIO_UTILS_H
#define AUDIO_UTILS_H

#include <Arduino.h>

/**
 * @brief Transforma audio bruto en un formato WAV
 * 
 * @param pcm 
 * @param bytesPcm 
 * @param wav 
 * @param capacidadWav 
 * @return size_t 
 * 
 * @author Martina Marquez
 */
size_t crear_wav(const uint8_t* pcm, size_t bytesPcm, uint8_t* wav, size_t capacidadWav);

#endif