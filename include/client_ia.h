#ifndef AI_CLIENT_H
#define AI_CLIENT_H

#include <Arduino.h>
#include "protocol_ia.h"

/**
 * @brief Envia la grabacion de voz a traves de internet hacia el servidor y recibe instrucciones
 * 
 * @param audio 
 * @param bytesAudio 
 * @param respuesta 
 * @return true 
 * @return false 
 * 
 * @author Martina Marquez
 */
bool ia_procesar_audio(const uint8_t* audio, size_t bytesAudio, RespuestaIA& respuesta);

#endif