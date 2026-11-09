/**
 * @file reactividad.h
 * @brief Reacción de pantalla según touch, proximidad y modo reposo
 * @author Jose Monje
 */

#ifndef REACTIVIDAD_H
#define REACTIVIDAD_H

void actualizar_emocion_por_proximidad(int distancia);

// Muestra una emoción (por ejemplo, de la IA) durante 'ms' sin que el reposo la tape
void reactividad_mostrar_emocion_temporal(unsigned long ms);

#endif