#include "status.h"
#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <stdio.h>

/* La pantalla se instancia una sola vez en hardware.cpp. */
extern Adafruit_SSD1306 pantalla;

enum e_Emociones emocion_actual = NEUTRO;

void dibujar_mirada_reojo(void)
{
    // Limpiar la pantalla antes de dibujar
    pantalla.clearDisplay();

    // Ojo izquierdo: base blanca
    pantalla.fillRect(24, 26, 26, 12, SSD1306_WHITE);

    // Pupila izquierda
    pantalla.fillRect(24, 26, 8, 12, SSD1306_BLACK);

    // Ceja izquierda
    pantalla.drawLine(20, 18, 52, 26, SSD1306_WHITE);
    pantalla.drawLine(20, 19, 52, 27, SSD1306_WHITE);

    // Ojo derecho: base blanca
    pantalla.fillRect(78, 26, 26, 12, SSD1306_WHITE);

    // Pupila derecha
    pantalla.fillRect(78, 26, 8, 12, SSD1306_BLACK);

    // Ceja derecha
    pantalla.drawLine(76, 26, 108, 18, SSD1306_WHITE);
    pantalla.drawLine(76, 27, 108, 19, SSD1306_WHITE);

    // Boca seria
    pantalla.fillRect(52, 44, 24, 4, SSD1306_WHITE);

    // Mostrar el dibujo en la pantalla OLED
    pantalla.display();
}
/* Dibujo simple para usar como fotograma de parpadeo/descanso. */
void dibujar_ojos_descansando(void)
{
    pantalla.clearDisplay();

    // Ojo izquierdo cerrado
    pantalla.drawLine(24, 32, 50, 32, SSD1306_WHITE);
    pantalla.drawLine(24, 33, 50, 33, SSD1306_WHITE);

    // Ojo derecho cerrado
    pantalla.drawLine(78, 32, 104, 32, SSD1306_WHITE);
    pantalla.drawLine(78, 33, 104, 33, SSD1306_WHITE);

    // Boca seria
    pantalla.fillRect(52, 44, 24, 4, SSD1306_WHITE);

    pantalla.display();
}

Emotion ojosDescansando = { dibujar_ojos_descansando, 200 };
Emotion ojosEnamorados = { dibujar_mirada_reojo, 200 };
Emotion ojosCansados = { dibujar_ojos_descansando, 200 };
Emotion ojosSorprendidos = { dibujar_mirada_reojo, 200 };
Emotion ojosNeutros = { dibujar_mirada_reojo, 200 };
Emotion ojosFelices = { dibujar_mirada_reojo, 200 };
Emotion ojosBorrachos = { dibujar_mirada_reojo, 200 };
Emotion ojosAsustados = { dibujar_mirada_reojo, 200 };
Emotion ojosFuriosos = { dibujar_mirada_reojo, 200 };
Emotion ojosExclamacion = { dibujar_mirada_reojo, 200 };
Emotion ojosHeridos = { dibujar_mirada_reojo, 200 };
Emotion ojosMiedo = { dibujar_mirada_reojo, 200 };
Emotion ojosMolestos = { dibujar_mirada_reojo, 200 };
Emotion ojosEscuchando = { dibujar_mirada_reojo, 200 };
Emotion ojosAsqueados = { dibujar_mirada_reojo, 200 };
Emotion ojosConfundidos = { dibujar_mirada_reojo, 200 };
Emotion ojosInteresados = { dibujar_mirada_reojo, 200 };
Emotion ojosAburridos = { dibujar_mirada_reojo, 200 };
Emotion ojosPoderosos = { dibujar_mirada_reojo, 200 };
Emotion ojosPacificos = { dibujar_mirada_reojo, 200 };
Emotion ojosAnsiosos = { dibujar_mirada_reojo, 200 };
Emotion ojosCulpables = { dibujar_mirada_reojo, 200 };
Emotion ojosCriticos = { dibujar_mirada_reojo, 200 };
Emotion ojosEnojados = { dibujar_mirada_reojo, 200 };
Emotion ojosTristes = { dibujar_mirada_reojo, 200 };
Emotion ojosHumillados = { dibujar_mirada_reojo, 200 };
Emotion ojosRechazados = { dibujar_mirada_reojo, 200 };
Emotion ojosCelosos = { dibujar_mirada_reojo, 200 };
Emotion ojosOdiosos = { dibujar_mirada_reojo, 200 };
Emotion ojosDesquisiados = { dibujar_mirada_reojo, 200 };
Emotion ojosVengativos = { dibujar_mirada_reojo, 200 };
Emotion ojosFrustrados = { dibujar_mirada_reojo, 200 };
Emotion ojosDistantes = { dibujar_mirada_reojo, 200 };
Emotion ojosBailarin = { dibujar_mirada_reojo, 200 };
Emotion ojosHalloween = { dibujar_mirada_reojo, 200 };
Emotion ojosPesos = { dibujar_mirada_reojo, 200 };
Emotion ojosGuino = { dibujar_mirada_reojo, 200 };

void actualizar_emocion(enum e_Emociones nuevo_estado)
{
    emocion_actual = nuevo_estado;
    printf("Emocion actualizada a la numero: %d\n", (int)emocion_actual);
}

enum e_Emociones obtener_emocion(void)
{
    return emocion_actual;
}
