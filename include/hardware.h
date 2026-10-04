#ifndef HARDWARE_H
#define HARDWARE_H
#include "status.h"
#include <stdio.h>

//Audio y microfono
#define MICROPHONE_PIN 1

// Pines para la pantalla y sensor 
#define DISPLAY_SDA   8
#define DISPLAY_SCL   9
#define MOVE_SENSOR_ECHO 5
#define MOVE_SENSOR_TRIG 4
#define TOUCH_PIN     32 

//Pantalla OLED
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#ifdef __cplusplus
extern "C" {
#endif

// Prototipo de la función principal de hardware
void inicializar_hardware(void);
void dibujar_emocion(Emotion *sentimiento);
int medir_distancia();

#ifdef __cplusplus
}
#endif

#endif