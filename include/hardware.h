#ifndef HARDWARE_H
#define HARDWARE_H
#include "status.h"
#include <stdio.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Wire.h>

//Audio y microfono
#define I2S_BCLK_PIN  4
#define I2S_LRC_PIN   5
#define I2S_DOUT_PIN  18
#define I2S_DIN_PIN   19

// Pines para la pantalla y sensor 
#define DISPLAY_SDA   8
#define DISPLAY_SCL   9
#define TOUCH_PIN     32 

//Pantalla OLED
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// Prototipo de la función principal de hardware
void inicializar_hardware(void);
void dibujar_emocion(Emotion *sentimiento);

#endif