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

/**
 * @brief Inicializa todo el hardware
 * 
 * @author Martina Marquez
 */
void inicializar_hardware(void);

/**
 * @brief mide la distancia del sensor de movimiento
 * 
 * @return int 
 * 
 * @author Martina Marquez
 */
int medir_distancia();

/**
 * @brief Inicializa la OLED
 * 
 * @author Martina Marquez
 */
void inicializar_pantalla(void);

/**
 * @brief Inicializa el sensor de movimiento
 * 
 * @author Martina Marquez
 * 
 */
void inicializar_sensor_movimiento(void);

/**
 * @brief Inicializa el amplificador
 * 
 * @author Martina Marquez
 * 
 */
void inicializar_amplificador(void);

/**
 * @brief Inicializa el microfono
 * 
 * @author Martina Marquez
 * 
 */
void inicializar_microfono(void);

/**
 * @brief Inicializa el lector microSD
 * 
 * @author Martina Marquez
 */
void inicializar_microsd(void);

/**
 * @brief Inicializa el sensor touch
 * 
 * @author Martina Marquez
 * 
 */
void inicializar_touch(void);

/**
 * @brief Inicializa el interruptor
 * 
 * @author Martina Marquez
 * 
 */
void inicializar_interruptor(void);

#ifdef __cplusplus
}
#endif

#endif