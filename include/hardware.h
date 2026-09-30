#ifndef HARDWARE_H
#define HARDWARE_H

//Audio y microfono
#define I2S_BCLK_PIN  4
#define I2S_LRC_PIN   5
#define I2S_DOUT_PIN  18
#define I2S_DIN_PIN   19

// Pines para la pantalla y sensor 
#define DISPLAY_SDA   8
#define DISPLAY_SCL   9
#define TOUCH_PIN     32 

// Prototipo de la función principal de hardware
void inicializar_hardware(void);

#endif