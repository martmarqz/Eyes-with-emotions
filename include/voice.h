#ifndef VOICE_H
#define VOICE_H

#include <Arduino.h>

/**
 * @brief inicializa la grabadora de audio
 * 
 * @return true 
 * @return false
 * 
 * @author Martina Marquez 
 */
bool voz_inicializar();

/**
 * @brief graba la voz
 * 
 * @param buffer 
 * @param capacidad 
 * @param bytesGrabados 
 * @param duracionMs 
 * @return true 
 * @return false 
 * 
 * @author Martina Marquez
 */
bool voz_grabar(uint8_t* buffer, size_t capacidad, size_t& bytesGrabados, uint32_t duracionMs);

/**
 * @brief procesa la voz
 * 
 * @return true 
 * @return false 
 * 
 * @author Martina Marquez
 */
bool voz_procesar();

#endif