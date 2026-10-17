#ifndef HARDWARE_H
#define HARDWARE_H

#include "status.h"
#include <stdio.h>

#define MICROPHONE_PIN 1

#define AMP_BCLK 15
#define AMP_LRC 16
#define AMP_DOUT 17

#define DISPLAY_SDA 8
#define DISPLAY_SCL 9
#define MOVE_SENSOR_ECHO 5
#define MOVE_SENSOR_TRIG 4
#define TOUCH_PIN 32

#define SD_SCK 12
#define SD_MISO 13
#define SD_MOSI 11
#define SD_CS 14

#define SWITCH_PIN 18

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#ifdef __cplusplus
extern "C" {
#endif

//FUNCIONES
void inicializar_hardware(void);
int medir_distancia();
void inicializar_pantalla(void);
void inicializar_sensor_movimiento(void);
void inicializar_amplificador(void);
void inicializar_microfono(void);
void inicializar_microsd(void);
void inicializar_touch(void);
void inicializar_interruptor(void);
int leer_microfono(void);

#ifdef __cplusplus
}
#endif

#endif