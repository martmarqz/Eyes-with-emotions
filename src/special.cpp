#include "special.h"
#include "images.h"
#include "hardware.h"
#include "status.h"
#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Pantalla OLED global configurada en hardware.cpp
extern Adafruit_SSD1306 pantalla;

void inicializar_especial(void)
{
    // No hay nada que inicializar: la animación usa la misma pantalla
}

void ejecutar_animacion_calabazas(void)
{
    // Reproduce la animación de los gatos (fotogramas de images.h)
    for (uint16_t i = 0; i < GATOS_FRAME_COUNT; i++)
    {
        pantalla.clearDisplay();

        const unsigned char* frame = (const unsigned char*)pgm_read_ptr(&gatos_frames[i]);

        pantalla.drawBitmap(0, 0, frame, SCREEN_WIDTH, SCREEN_HEIGHT, SSD1306_WHITE);

        pantalla.display();
        delay(GATOS_FRAME_DELAY);
    }
}