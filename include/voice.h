#ifndef VOICE_H
#define VOICE_H

#include <Arduino.h>

bool voz_inicializar();

bool voz_grabar(uint8_t* buffer, size_t capacidad, size_t& bytesGrabados, uint32_t duracionMs);

bool voz_procesar();

#endif