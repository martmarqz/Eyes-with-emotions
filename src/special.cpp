#include "special.h"
#include "images.h"
#include "hardware.h"
#include "status.h"
#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Hacemos referencia a la pantalla OLED global configurada en hardware.cpp
extern Adafruit_SSD1306 pantalla;

// Definición de pines para los LEDs de las calabazas
// (Se usan los pines 16, 17, 18 y 19 para evitar conflicto con el sensor ultrasónico en pines 4 y 5)
const int calabaza1A = 16;
const int calabaza1B = 17;
const int calabaza2A = 18;
const int calabaza2B = 19;

int tiempoParpadeo = 300;
int tiempoEntrePasos = 150;
int pausaEntreRondas = 600;

void encenderCalabaza1(bool estado) {
    digitalWrite(calabaza1A, estado);
    digitalWrite(calabaza1B, estado);
}

void encenderCalabaza2(bool estado) {
    digitalWrite(calabaza2A, estado);
    digitalWrite(calabaza2B, estado);
}

void apagarTodas() {
    encenderCalabaza1(LOW);
    encenderCalabaza2(LOW);
}

void secuenciaAlternada() {
    for (int i = 0; i < 4; i++) {
        encenderCalabaza1(HIGH);
        delay(tiempoParpadeo);
        encenderCalabaza1(LOW);
        delay(tiempoEntrePasos);

        encenderCalabaza2(HIGH);
        delay(tiempoParpadeo);
        encenderCalabaza2(LOW);
        delay(tiempoEntrePasos);
    }
    delay(pausaEntreRondas);
}

void secuenciaJuntas() {
    for (int i = 0; i < 3; i++) {
        encenderCalabaza1(HIGH);
        encenderCalabaza2(HIGH);
        delay(tiempoParpadeo);
        apagarTodas();
        delay(tiempoEntrePasos);
    }
    delay(pausaEntreRondas);
}

void inicializar_especial(void) {
    pinMode(calabaza1A, OUTPUT);
    pinMode(calabaza1B, OUTPUT);
    pinMode(calabaza2A, OUTPUT);
    pinMode(calabaza2B, OUTPUT);
    apagarTodas();
}

void ejecutar_animacion_calabazas(void) {
    // 1. Cambiamos la emoción global del robot a SORPRENDIDO mientras ocurre el show
    actualizar_emocion(SORPRENDIDO);

    // 2. Reproducimos la animación de la pantalla OLED (recorriendo los fotogramas de images.h)
    for (uint16_t i = 0; i < GATOS_FRAME_COUNT; i++) {
        pantalla.clearDisplay();

        const unsigned char* frame = (const unsigned char*)pgm_read_ptr(&gatos_frames[i]);

        pantalla.drawBitmap(
            0,
            0,
            frame,
            SCREEN_WIDTH,
            SCREEN_HEIGHT,
            SSD1306_WHITE
        );

        pantalla.display();
        delay(GATOS_FRAME_DELAY);
    }

    // 3. Ejecutamos las secuencias de parpadeo en los LEDs físicos
    secuenciaAlternada();
    secuenciaJuntas();
    apagarTodas();

    // 4. Regresamos los ojos al estado NEUTRO al finalizar
    actualizar_emocion(NEUTRO);
}