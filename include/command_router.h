#ifndef COMMAND_ROUTER_H
#define COMMAND_ROUTER_H

#include <Arduino.h>

/**
 * @brief decide qué gráfico o movimiento mostrar basándose en las instrucciones que recibió del servidor
 * 
 * @param comando 
 * @param valor 
 * @return true 
 * @return false 
 * 
 * @author Martina Marquez
 */
bool ejecutar_comando(const String& comando, const String& valor);

#endif