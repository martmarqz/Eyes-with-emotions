#ifndef AI_CLIENT_H
#define AI_CLIENT_H

#include <Arduino.h>
#include "protocol_ia.h"

bool ia_procesar_audio(const uint8_t* audio, size_t bytesAudio, RespuestaIA& respuesta);

#endif