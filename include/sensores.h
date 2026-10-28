/**
 * @file sensores.h
 * @brief Funciones de lectura para los sensores (proximidad, touch y micròfono)
 * @author Jose Monje
 */

 #ifndef SENSORES_H
 #define SENSORES_H

 #include<Arduino.h>
 #include "hardware.h" //Importacion de los pines definidos en hardware.h

 #define UMBRAL_TOUCH 30000
 #define TIMEOUT_US 25000

 void inicializar_sensores(void);
 float obtener_distancia(void);
 int obtener_nivel_mic(void);
 bool touch_presionado(void);
 #endif