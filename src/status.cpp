#include "status.h"
#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <stdio.h>

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

void dibujar_ojos_descansando(void)
{
    pantalla.clearDisplay();

    pantalla.drawLine(24, 32, 50, 32, SSD1306_WHITE);
    pantalla.drawLine(24, 33, 50, 33, SSD1306_WHITE);

    pantalla.drawLine(78, 32, 104, 32, SSD1306_WHITE);
    pantalla.drawLine(78, 33, 104, 33, SSD1306_WHITE);

    pantalla.fillRect(52, 44, 24, 4, SSD1306_WHITE);

    pantalla.display();
}


void dibujar_ojos_escuchando(void)
{
    pantalla.clearDisplay();

    pantalla.fillRect(24, 26, 26, 12, SSD1306_WHITE);

    pantalla.fillRect(33, 27, 8, 10, SSD1306_BLACK);

    pantalla.drawLine(24, 20, 50, 18, SSD1306_WHITE);
    pantalla.drawLine(24, 21, 50, 19, SSD1306_WHITE);

    pantalla.fillRect(78, 26, 26, 12, SSD1306_WHITE);

    pantalla.fillRect(87, 27, 8, 10, SSD1306_BLACK);

    pantalla.drawLine(78, 18, 104, 20, SSD1306_WHITE);
    pantalla.drawLine(78, 19, 104, 21, SSD1306_WHITE);

    pantalla.drawLine(16, 25, 12, 29, SSD1306_WHITE);
    pantalla.drawLine(12, 29, 16, 33, SSD1306_WHITE);

    pantalla.drawLine(112, 25, 116, 29, SSD1306_WHITE);
    pantalla.drawLine(116, 29, 112, 33, SSD1306_WHITE);

    pantalla.fillRect(56, 45, 16, 3, SSD1306_WHITE);

    pantalla.display();
}


void dibujar_ojos_asqueados(void)
{
    pantalla.clearDisplay();

    pantalla.fillRect(24, 28, 26, 10, SSD1306_WHITE);

    pantalla.fillRect(33, 30, 7, 8, SSD1306_BLACK);

    pantalla.drawLine(24, 22, 50, 27, SSD1306_WHITE);
    pantalla.drawLine(24, 23, 50, 28, SSD1306_WHITE);

    pantalla.fillRect(78, 28, 26, 10, SSD1306_WHITE);

    pantalla.fillRect(88, 30, 7, 8, SSD1306_BLACK);

    pantalla.drawLine(78, 27, 104, 22, SSD1306_WHITE);
    pantalla.drawLine(78, 28, 104, 23, SSD1306_WHITE);

    pantalla.drawLine(57, 29, 61, 33, SSD1306_WHITE);
    pantalla.drawLine(71, 33, 75, 29, SSD1306_WHITE);

    pantalla.drawLine(49, 46, 60, 43, SSD1306_WHITE);
    pantalla.drawLine(60, 43, 69, 47, SSD1306_WHITE);
    pantalla.drawLine(69, 47, 79, 45, SSD1306_WHITE);

    pantalla.display();
}


void dibujar_ojos_enamorados(void)
{
    pantalla.clearDisplay();

    pantalla.fillRect(28, 20, 8, 4, SSD1306_WHITE);
    pantalla.fillRect(40, 20, 8, 4, SSD1306_WHITE);

    pantalla.fillRect(24, 24, 24, 4, SSD1306_WHITE);
    pantalla.fillRect(24, 28, 24, 4, SSD1306_WHITE);

    pantalla.fillRect(28, 32, 16, 4, SSD1306_WHITE);
    pantalla.fillRect(32, 36, 8, 4, SSD1306_WHITE);

    pantalla.fillRect(82, 20, 8, 4, SSD1306_WHITE);
    pantalla.fillRect(94, 20, 8, 4, SSD1306_WHITE);

    pantalla.fillRect(78, 24, 24, 4, SSD1306_WHITE);
    pantalla.fillRect(78, 28, 24, 4, SSD1306_WHITE);

    pantalla.fillRect(82, 32, 16, 4, SSD1306_WHITE);
    pantalla.fillRect(86, 36, 8, 4, SSD1306_WHITE);

    pantalla.drawLine(52, 44, 57, 48, SSD1306_WHITE);
    pantalla.drawLine(57, 48, 64, 50, SSD1306_WHITE);
    pantalla.drawLine(64, 50, 71, 48, SSD1306_WHITE);
    pantalla.drawLine(71, 48, 76, 44, SSD1306_WHITE);

    pantalla.display();
}


void dibujar_ojos_cansados(void)
{
    pantalla.clearDisplay();

    pantalla.fillRect(24, 27, 26, 12, SSD1306_WHITE);

    pantalla.drawLine(24, 29, 50, 33, SSD1306_BLACK);
    pantalla.drawLine(24, 30, 50, 34, SSD1306_BLACK);

    pantalla.fillRect(34, 33, 6, 5, SSD1306_BLACK);

    pantalla.drawLine(24, 22, 48, 25, SSD1306_WHITE);
    pantalla.drawLine(24, 23, 48, 26, SSD1306_WHITE);
    
    pantalla.fillRect(78, 27, 26, 12, SSD1306_WHITE);

    pantalla.drawLine(78, 33, 104, 29, SSD1306_BLACK);
    pantalla.drawLine(78, 34, 104, 30, SSD1306_BLACK);

    pantalla.fillRect(88, 33, 6, 5, SSD1306_BLACK);

    pantalla.drawLine(80, 25, 104, 22, SSD1306_WHITE);
    pantalla.drawLine(80, 26, 104, 23, SSD1306_WHITE);

    pantalla.drawLine(54, 45, 64, 47, SSD1306_WHITE);
    pantalla.drawLine(64, 47, 74, 45, SSD1306_WHITE);

    pantalla.display();
}


void dibujar_ojos_sorprendidos(void)
{
    pantalla.clearDisplay();

    pantalla.drawLine(24, 14, 48, 10, SSD1306_WHITE);
    pantalla.drawLine(24, 15, 48, 11, SSD1306_WHITE);

    pantalla.drawLine(80, 10, 104, 14, SSD1306_WHITE);
    pantalla.drawLine(80, 11, 104, 15, SSD1306_WHITE);

    pantalla.fillRect(24, 18, 26, 24, SSD1306_WHITE);

    pantalla.fillRect(34, 25, 7, 10, SSD1306_BLACK);

    pantalla.fillRect(35, 26, 2, 3, SSD1306_WHITE);

    pantalla.fillRect(78, 18, 26, 24, SSD1306_WHITE);

    pantalla.fillRect(87, 25, 7, 10, SSD1306_BLACK);

    pantalla.fillRect(88, 26, 2, 3, SSD1306_WHITE);

    pantalla.fillRect(57, 46, 14, 4, SSD1306_WHITE);
    pantalla.fillRect(53, 50, 22, 8, SSD1306_WHITE);
    pantalla.fillRect(57, 58, 14, 3, SSD1306_WHITE);

    pantalla.fillRect(58, 50, 12, 8, SSD1306_BLACK);

    pantalla.display();
}

void dibujar_ojos_neutros(void)
{
    pantalla.clearDisplay();

    pantalla.fillRect(24, 25, 26, 14, SSD1306_WHITE);

    pantalla.fillRect(33, 28, 8, 8, SSD1306_BLACK);

    pantalla.fillRect(78, 25, 26, 14, SSD1306_WHITE);

    pantalla.fillRect(87, 28, 8, 8, SSD1306_BLACK);

    pantalla.drawLine(24, 20, 50, 20, SSD1306_WHITE);
    pantalla.drawLine(78, 20, 104, 20, SSD1306_WHITE);

    pantalla.fillRect(52, 47, 24, 3, SSD1306_WHITE);

    pantalla.display();
}


void dibujar_ojos_felices(void)
{
    pantalla.clearDisplay();

    pantalla.drawLine(24, 33, 29, 28, SSD1306_WHITE);
    pantalla.drawLine(25, 34, 30, 29, SSD1306_WHITE);

    pantalla.drawLine(29, 28, 36, 24, SSD1306_WHITE);
    pantalla.drawLine(29, 29, 36, 25, SSD1306_WHITE);

    pantalla.drawLine(36, 24, 43, 28, SSD1306_WHITE);
    pantalla.drawLine(36, 25, 43, 29, SSD1306_WHITE);

    pantalla.drawLine(43, 28, 50, 33, SSD1306_WHITE);
    pantalla.drawLine(43, 29, 50, 34, SSD1306_WHITE);

    pantalla.drawLine(78, 33, 85, 28, SSD1306_WHITE);
    pantalla.drawLine(78, 34, 85, 29, SSD1306_WHITE);

    pantalla.drawLine(85, 28, 92, 24, SSD1306_WHITE);
    pantalla.drawLine(85, 29, 92, 25, SSD1306_WHITE);

    pantalla.drawLine(92, 24, 99, 28, SSD1306_WHITE);
    pantalla.drawLine(92, 25, 99, 29, SSD1306_WHITE);

    pantalla.drawLine(99, 28, 104, 33, SSD1306_WHITE);
    pantalla.drawLine(99, 29, 104, 34, SSD1306_WHITE);

    pantalla.drawLine(48, 44, 54, 48, SSD1306_WHITE);
    pantalla.drawLine(54, 48, 60, 51, SSD1306_WHITE);
    pantalla.drawLine(60, 51, 64, 52, SSD1306_WHITE);
    pantalla.drawLine(64, 52, 68, 51, SSD1306_WHITE);
    pantalla.drawLine(68, 51, 74, 48, SSD1306_WHITE);
    pantalla.drawLine(74, 48, 80, 44, SSD1306_WHITE);

    pantalla.drawLine(49, 45, 55, 49, SSD1306_WHITE);
    pantalla.drawLine(55, 49, 60, 52, SSD1306_WHITE);
    pantalla.drawLine(60, 52, 64, 53, SSD1306_WHITE);
    pantalla.drawLine(64, 53, 68, 52, SSD1306_WHITE);
    pantalla.drawLine(68, 52, 73, 49, SSD1306_WHITE);
    pantalla.drawLine(73, 49, 79, 45, SSD1306_WHITE);

    pantalla.drawLine(16, 39, 18, 42, SSD1306_WHITE);
    pantalla.drawLine(20, 38, 22, 41, SSD1306_WHITE);

    pantalla.drawLine(106, 38, 108, 41, SSD1306_WHITE);
    pantalla.drawLine(110, 39, 112, 42, SSD1306_WHITE);

    pantalla.display();
}


void dibujar_ojos_borrachos(void)
{
    pantalla.clearDisplay();

    pantalla.drawLine(22, 17, 47, 21, SSD1306_WHITE);
    pantalla.drawLine(23, 18, 48, 22, SSD1306_WHITE);

    pantalla.fillRect(22, 23, 29, 16, SSD1306_WHITE);

    pantalla.drawLine(22, 25, 51, 30, SSD1306_BLACK);
    pantalla.drawLine(22, 26, 51, 31, SSD1306_BLACK);

    pantalla.fillRect(36, 30, 8, 8, SSD1306_BLACK);

    pantalla.drawLine(79, 19, 104, 14, SSD1306_WHITE);
    pantalla.drawLine(79, 20, 104, 15, SSD1306_WHITE);

    pantalla.fillRect(77, 22, 28, 17, SSD1306_WHITE);

    pantalla.fillRect(81, 28, 8, 9, SSD1306_BLACK);

    pantalla.drawLine(14, 24, 18, 28, SSD1306_WHITE);
    pantalla.drawLine(18, 28, 14, 32, SSD1306_WHITE);

    pantalla.drawLine(111, 25, 115, 29, SSD1306_WHITE);
    pantalla.drawLine(115, 29, 111, 33, SSD1306_WHITE);

    pantalla.drawLine(49, 47, 58, 44, SSD1306_WHITE);
    pantalla.drawLine(58, 44, 66, 48, SSD1306_WHITE);
    pantalla.drawLine(66, 48, 76, 45, SSD1306_WHITE);

    pantalla.drawLine(49, 48, 58, 45, SSD1306_WHITE);
    pantalla.drawLine(58, 45, 66, 49, SSD1306_WHITE);
    pantalla.drawLine(66, 49, 76, 46, SSD1306_WHITE);

    pantalla.fillRect(63, 49, 6, 4, SSD1306_WHITE);

    pantalla.display();
}


void dibujar_ojos_asustados(void)
{
    pantalla.clearDisplay();

    pantalla.drawLine(24, 15, 35, 9, SSD1306_WHITE);
    pantalla.drawLine(35, 9, 50, 15, SSD1306_WHITE);
    pantalla.drawLine(24, 16, 35, 10, SSD1306_WHITE);
    pantalla.drawLine(35, 10, 50, 16, SSD1306_WHITE);

    pantalla.drawLine(78, 15, 92, 9, SSD1306_WHITE);
    pantalla.drawLine(92, 9, 104, 15, SSD1306_WHITE);
    pantalla.drawLine(78, 16, 92, 10, SSD1306_WHITE);
    pantalla.drawLine(92, 10, 104, 16, SSD1306_WHITE);

    pantalla.fillRect(24, 18, 26, 27, SSD1306_WHITE);
    pantalla.fillRect(78, 18, 26, 27, SSD1306_WHITE);

    pantalla.fillRect(28, 22, 18, 19, SSD1306_BLACK);
    pantalla.fillRect(82, 22, 18, 19, SSD1306_BLACK);

    pantalla.fillRect(34, 25, 6, 7, SSD1306_WHITE);
    pantalla.fillRect(88, 25, 6, 7, SSD1306_WHITE);

    pantalla.drawLine(15, 24, 12, 29, SSD1306_WHITE);
    pantalla.drawLine(12, 29, 15, 34, SSD1306_WHITE);

    pantalla.drawLine(113, 24, 116, 29, SSD1306_WHITE);
    pantalla.drawLine(116, 29, 113, 34, SSD1306_WHITE);

    pantalla.fillRect(58, 45, 12, 3, SSD1306_WHITE);
    pantalla.fillRect(55, 48, 18, 8, SSD1306_WHITE);
    pantalla.fillRect(58, 56, 12, 3, SSD1306_WHITE);

    pantalla.fillRect(59, 48, 10, 8, SSD1306_BLACK);

    pantalla.display();
}


void dibujar_ojos_furiosos(void)
{
    pantalla.clearDisplay();

    pantalla.fillRect(27, 32, 22, 9, SSD1306_WHITE);
    pantalla.fillRect(29, 27, 19, 8, SSD1306_WHITE);
    pantalla.fillRect(32, 22, 14, 8, SSD1306_WHITE);
    pantalla.fillRect(36, 15, 5, 11, SSD1306_WHITE);

    pantalla.fillRect(29, 21, 5, 9, SSD1306_WHITE);
    pantalla.fillRect(24, 27, 6, 8, SSD1306_WHITE);
    pantalla.fillRect(44, 23, 6, 8, SSD1306_WHITE);

    pantalla.drawLine(25, 33, 30, 26, SSD1306_WHITE);
    pantalla.drawLine(30, 26, 32, 20, SSD1306_WHITE);
    pantalla.drawLine(32, 20, 36, 14, SSD1306_WHITE);
    pantalla.drawLine(36, 14, 39, 21, SSD1306_WHITE);
    pantalla.drawLine(39, 21, 44, 25, SSD1306_WHITE);

    pantalla.fillRect(79, 32, 22, 9, SSD1306_WHITE);
    pantalla.fillRect(80, 27, 19, 8, SSD1306_WHITE);
    pantalla.fillRect(82, 22, 14, 8, SSD1306_WHITE);
    pantalla.fillRect(87, 15, 5, 11, SSD1306_WHITE);

    pantalla.fillRect(94, 21, 5, 9, SSD1306_WHITE);
    pantalla.fillRect(98, 27, 6, 8, SSD1306_WHITE);
    pantalla.fillRect(78, 23, 6, 8, SSD1306_WHITE);

    pantalla.drawLine(103, 33, 98, 26, SSD1306_WHITE);
    pantalla.drawLine(98, 26, 96, 20, SSD1306_WHITE);
    pantalla.drawLine(96, 20, 92, 14, SSD1306_WHITE);
    pantalla.drawLine(92, 14, 89, 21, SSD1306_WHITE);
    pantalla.drawLine(89, 21, 84, 25, SSD1306_WHITE);

    pantalla.fillRect(30, 32, 18, 5, SSD1306_BLACK);
    pantalla.drawLine(29, 31, 48, 35, SSD1306_BLACK);
    pantalla.drawLine(29, 32, 48, 36, SSD1306_BLACK);

    pantalla.fillRect(80, 32, 18, 5, SSD1306_BLACK);
    pantalla.drawLine(80, 35, 99, 31, SSD1306_BLACK);
    pantalla.drawLine(80, 36, 99, 32, SSD1306_BLACK);

    pantalla.fillRect(37, 32, 3, 4, SSD1306_WHITE);
    pantalla.fillRect(88, 32, 3, 4, SSD1306_WHITE);

    pantalla.drawLine(42, 24, 50, 28, SSD1306_BLACK);
    pantalla.drawLine(78, 28, 86, 24, SSD1306_BLACK);

    pantalla.drawLine(16, 27, 20, 22, SSD1306_WHITE);
    pantalla.drawLine(20, 22, 19, 29, SSD1306_WHITE);
    pantalla.drawLine(112, 27, 108, 22, SSD1306_WHITE);
    pantalla.drawLine(108, 22, 109, 29, SSD1306_WHITE);

    pantalla.drawLine(50, 51, 59, 47, SSD1306_WHITE);
    pantalla.drawLine(59, 47, 69, 47, SSD1306_WHITE);
    pantalla.drawLine(69, 47, 78, 51, SSD1306_WHITE);

    pantalla.drawLine(50, 52, 59, 48, SSD1306_WHITE);
    pantalla.drawLine(59, 48, 69, 48, SSD1306_WHITE);
    pantalla.drawLine(69, 48, 78, 52, SSD1306_WHITE);

    pantalla.display();
}

void dibujar_ojos_exclamacion(void)
{
    pantalla.clearDisplay();

    pantalla.fillRect(33, 2, 13, 38, SSD1306_WHITE);
    pantalla.fillRect(78, 2, 13, 38, SSD1306_WHITE);
    pantalla.fillRect(33, 46, 13, 5, SSD1306_WHITE);
    pantalla.fillRect(78, 45, 13, 5, SSD1306_WHITE);
    pantalla.fillRect(59, 45, 12, 5, SSD1306_WHITE);
    pantalla.fillRect(63, 46, 7, 4, SSD1306_WHITE);

    pantalla.display();
}


void dibujar_ojos_heridos(void)
{
    pantalla.clearDisplay();

    pantalla.drawLine(24, 18, 32, 15, SSD1306_WHITE);
    pantalla.drawLine(32, 15, 38, 19, SSD1306_WHITE);
    pantalla.drawLine(40, 20, 50, 17, SSD1306_WHITE);
    pantalla.drawLine(24, 19, 32, 16, SSD1306_WHITE);
    pantalla.drawLine(40, 21, 50, 18, SSD1306_WHITE);

    pantalla.drawLine(78, 17, 87, 20, SSD1306_WHITE);
    pantalla.drawLine(89, 20, 104, 16, SSD1306_WHITE);
    pantalla.drawLine(78, 18, 87, 21, SSD1306_WHITE);
    pantalla.drawLine(89, 21, 104, 17, SSD1306_WHITE);

    pantalla.fillRect(24, 26, 26, 14, SSD1306_WHITE);
    pantalla.fillRect(78, 26, 26, 14, SSD1306_WHITE);

    pantalla.fillRect(27, 29, 20, 8, SSD1306_BLACK);
    pantalla.fillRect(81, 29, 20, 8, SSD1306_BLACK);

    pantalla.drawLine(29, 29, 45, 36, SSD1306_WHITE);
    pantalla.drawLine(29, 30, 45, 37, SSD1306_WHITE);
    pantalla.drawLine(29, 36, 45, 29, SSD1306_WHITE);
    pantalla.drawLine(29, 37, 45, 30, SSD1306_WHITE);

    pantalla.drawLine(83, 29, 99, 36, SSD1306_WHITE);
    pantalla.drawLine(83, 30, 99, 37, SSD1306_WHITE);
    pantalla.drawLine(83, 36, 99, 29, SSD1306_WHITE);
    pantalla.drawLine(83, 37, 99, 30, SSD1306_WHITE);

    pantalla.drawLine(24, 26, 29, 31, SSD1306_BLACK);
    pantalla.drawLine(29, 31, 26, 35, SSD1306_BLACK);
    pantalla.drawLine(104, 26, 99, 31, SSD1306_BLACK);
    pantalla.drawLine(99, 31, 102, 35, SSD1306_BLACK);

    pantalla.drawLine(16, 28, 20, 24, SSD1306_WHITE);
    pantalla.drawLine(18, 34, 22, 37, SSD1306_WHITE);
    pantalla.drawLine(108, 25, 112, 29, SSD1306_WHITE);
    pantalla.drawLine(106, 37, 110, 40, SSD1306_WHITE);

    pantalla.drawLine(49, 49, 58, 46, SSD1306_WHITE);
    pantalla.drawLine(58, 46, 65, 49, SSD1306_WHITE);
    pantalla.drawLine(65, 49, 77, 46, SSD1306_WHITE);

    pantalla.drawLine(49, 50, 58, 47, SSD1306_WHITE);
    pantalla.drawLine(58, 47, 65, 50, SSD1306_WHITE);
    pantalla.drawLine(65, 50, 77, 47, SSD1306_WHITE);

    pantalla.drawLine(58, 47, 60, 51, SSD1306_WHITE);
    pantalla.drawLine(60, 51, 64, 51, SSD1306_WHITE);
    pantalla.drawLine(64, 51, 66, 49, SSD1306_WHITE);

    pantalla.display();
}


void dibujar_ojos_miedo(void)
{
    pantalla.clearDisplay();

    pantalla.drawLine(24, 20, 49, 13, SSD1306_WHITE);
    pantalla.drawLine(24, 21, 49, 14, SSD1306_WHITE);

    pantalla.drawLine(79, 13, 104, 20, SSD1306_WHITE);
    pantalla.drawLine(79, 14, 104, 21, SSD1306_WHITE);

    pantalla.fillRect(24, 22, 26, 21, SSD1306_WHITE);
    pantalla.fillRect(78, 22, 26, 21, SSD1306_WHITE);

    pantalla.fillRect(39, 30, 6, 9, SSD1306_BLACK);
    pantalla.fillRect(83, 30, 6, 9, SSD1306_BLACK);

    pantalla.drawPixel(40, 31, SSD1306_WHITE);
    pantalla.drawPixel(84, 31, SSD1306_WHITE);

    pantalla.drawLine(57, 17, 61, 21, SSD1306_WHITE);
    pantalla.drawLine(71, 21, 75, 17, SSD1306_WHITE);

    pantalla.drawLine(16, 27, 13, 31, SSD1306_WHITE);
    pantalla.drawLine(13, 31, 16, 35, SSD1306_WHITE);

    pantalla.drawLine(112, 27, 115, 31, SSD1306_WHITE);
    pantalla.drawLine(115, 31, 112, 35, SSD1306_WHITE);

    pantalla.fillRect(57, 47, 14, 10, SSD1306_WHITE);
    pantalla.fillRect(60, 49, 8, 6, SSD1306_BLACK);

    pantalla.drawLine(53, 47, 57, 49, SSD1306_WHITE);
    pantalla.drawLine(71, 49, 75, 47, SSD1306_WHITE);

    pantalla.display();
}


void dibujar_ojos_molestos(void)
{
    pantalla.clearDisplay();

    pantalla.drawLine(24, 18, 50, 24, SSD1306_WHITE);
    pantalla.drawLine(24, 19, 50, 25, SSD1306_WHITE);

    pantalla.drawLine(78, 24, 104, 18, SSD1306_WHITE);
    pantalla.drawLine(78, 25, 104, 19, SSD1306_WHITE);

    pantalla.fillRect(24, 27, 26, 13, SSD1306_WHITE);
    pantalla.fillRect(78, 27, 26, 13, SSD1306_WHITE);

    pantalla.fillRect(24, 27, 5, 2, SSD1306_BLACK);
    pantalla.fillRect(29, 27, 5, 3, SSD1306_BLACK);
    pantalla.fillRect(34, 28, 5, 3, SSD1306_BLACK);
    pantalla.fillRect(39, 29, 5, 3, SSD1306_BLACK);
    pantalla.fillRect(44, 30, 6, 3, SSD1306_BLACK);

    pantalla.fillRect(78, 30, 6, 3, SSD1306_BLACK);
    pantalla.fillRect(84, 29, 5, 3, SSD1306_BLACK);
    pantalla.fillRect(89, 28, 5, 3, SSD1306_BLACK);
    pantalla.fillRect(94, 27, 5, 3, SSD1306_BLACK);
    pantalla.fillRect(99, 27, 5, 2, SSD1306_BLACK);

    pantalla.fillRect(35, 33, 6, 6, SSD1306_BLACK);
    pantalla.fillRect(87, 33, 6, 6, SSD1306_BLACK);

    pantalla.drawLine(56, 23, 61, 27, SSD1306_WHITE);
    pantalla.drawLine(72, 27, 77, 23, SSD1306_WHITE);

    pantalla.drawLine(17, 29, 21, 26, SSD1306_WHITE);
    pantalla.drawLine(107, 26, 111, 29, SSD1306_WHITE);

    pantalla.drawLine(53, 46, 64, 49, SSD1306_WHITE);
    pantalla.drawLine(64, 49, 75, 46, SSD1306_WHITE);

    pantalla.drawLine(53, 47, 64, 50, SSD1306_WHITE);
    pantalla.drawLine(64, 50, 75, 47, SSD1306_WHITE);

    pantalla.display();
}


void dibujar_ojos_confundidos(void)
{
    pantalla.clearDisplay();

    pantalla.drawLine(24, 17, 31, 12, SSD1306_WHITE);
    pantalla.drawLine(31, 12, 40, 11, SSD1306_WHITE);
    pantalla.drawLine(40, 11, 50, 16, SSD1306_WHITE);

    pantalla.drawLine(24, 18, 31, 13, SSD1306_WHITE);
    pantalla.drawLine(31, 13, 40, 12, SSD1306_WHITE);
    pantalla.drawLine(40, 12, 50, 17, SSD1306_WHITE);

    pantalla.drawLine(79, 19, 91, 15, SSD1306_WHITE);
    pantalla.drawLine(91, 15, 104, 19, SSD1306_WHITE);
    pantalla.drawLine(79, 20, 91, 16, SSD1306_WHITE);
    pantalla.drawLine(91, 16, 104, 20, SSD1306_WHITE);

    pantalla.fillRect(24, 23, 26, 17, SSD1306_WHITE);

    pantalla.fillRect(34, 28, 7, 8, SSD1306_BLACK);

    pantalla.fillRect(79, 25, 25, 15, SSD1306_WHITE);

    pantalla.fillRect(91, 29, 6, 7, SSD1306_BLACK);

    pantalla.drawLine(57, 22, 60, 25, SSD1306_WHITE);
    pantalla.drawLine(72, 23, 75, 20, SSD1306_WHITE);

    pantalla.drawLine(52, 47, 59, 45, SSD1306_WHITE);
    pantalla.drawLine(59, 45, 65, 49, SSD1306_WHITE);
    pantalla.drawLine(65, 49, 75, 46, SSD1306_WHITE);

    pantalla.drawLine(52, 48, 59, 46, SSD1306_WHITE);
    pantalla.drawLine(59, 46, 65, 50, SSD1306_WHITE);
    pantalla.drawLine(65, 50, 75, 47, SSD1306_WHITE);

    pantalla.drawLine(109, 12, 113, 9, SSD1306_WHITE);
    pantalla.drawLine(113, 9, 116, 12, SSD1306_WHITE);
    pantalla.drawLine(116, 12, 112, 16, SSD1306_WHITE);
    pantalla.fillRect(111, 19, 2, 2, SSD1306_WHITE);

    pantalla.display();
}


void dibujar_ojos_interesados(void)
{
    pantalla.clearDisplay();

    pantalla.drawLine(24, 17, 31, 11, SSD1306_WHITE);
    pantalla.drawLine(31, 11, 40, 12, SSD1306_WHITE);
    pantalla.drawLine(40, 12, 50, 17, SSD1306_WHITE);

    pantalla.drawLine(24, 18, 31, 12, SSD1306_WHITE);
    pantalla.drawLine(31, 12, 40, 13, SSD1306_WHITE);
    pantalla.drawLine(40, 13, 50, 18, SSD1306_WHITE);

    pantalla.drawLine(78, 17, 88, 12, SSD1306_WHITE);
    pantalla.drawLine(88, 12, 97, 11, SSD1306_WHITE);
    pantalla.drawLine(97, 11, 104, 17, SSD1306_WHITE);

    pantalla.drawLine(78, 18, 88, 13, SSD1306_WHITE);
    pantalla.drawLine(88, 13, 97, 12, SSD1306_WHITE);
    pantalla.drawLine(97, 12, 104, 18, SSD1306_WHITE);

    pantalla.fillRect(24, 21, 26, 20, SSD1306_WHITE);
    pantalla.fillRect(78, 21, 26, 20, SSD1306_WHITE);

    pantalla.fillRect(37, 25, 8, 11, SSD1306_BLACK);
    pantalla.fillRect(83, 25, 8, 11, SSD1306_BLACK);

    pantalla.fillRect(38, 26, 2, 3, SSD1306_WHITE);
    pantalla.fillRect(84, 26, 2, 3, SSD1306_WHITE);

    pantalla.drawLine(64, 13, 64, 19, SSD1306_WHITE);
    pantalla.drawLine(61, 16, 67, 16, SSD1306_WHITE);

    pantalla.fillRect(59, 46, 10, 8, SSD1306_WHITE);
    pantalla.fillRect(62, 48, 4, 4, SSD1306_BLACK);

    pantalla.display();
}


void dibujar_ojos_aburridos(void)
{
    pantalla.clearDisplay();

    pantalla.drawLine(24, 19, 50, 21, SSD1306_WHITE);
    pantalla.drawLine(24, 20, 50, 22, SSD1306_WHITE);

    pantalla.drawLine(78, 21, 104, 19, SSD1306_WHITE);
    pantalla.drawLine(78, 22, 104, 20, SSD1306_WHITE);

    pantalla.fillRect(24, 25, 26, 15, SSD1306_WHITE);
    pantalla.fillRect(78, 25, 26, 15, SSD1306_WHITE);

    pantalla.fillRect(24, 25, 26, 6, SSD1306_BLACK);
    pantalla.fillRect(24, 30, 6, 3, SSD1306_BLACK);
    pantalla.fillRect(44, 30, 6, 3, SSD1306_BLACK);

    pantalla.fillRect(78, 25, 26, 6, SSD1306_BLACK);
    pantalla.fillRect(78, 30, 6, 3, SSD1306_BLACK);
    pantalla.fillRect(98, 30, 6, 3, SSD1306_BLACK);

    pantalla.fillRect(35, 32, 5, 5, SSD1306_BLACK);
    pantalla.fillRect(89, 32, 5, 5, SSD1306_BLACK);

    pantalla.drawLine(27, 42, 33, 43, SSD1306_WHITE);
    pantalla.drawLine(45, 42, 49, 41, SSD1306_WHITE);
    pantalla.drawLine(79, 41, 83, 42, SSD1306_WHITE);
    pantalla.drawLine(95, 43, 101, 42, SSD1306_WHITE);

    pantalla.fillRect(57, 48, 14, 2, SSD1306_WHITE);

    pantalla.display();
}


void dibujar_ojos_poderosos(void)
{
    pantalla.clearDisplay();

    pantalla.drawLine(22, 18, 34, 13, SSD1306_WHITE);
    pantalla.drawLine(34, 13, 50, 19, SSD1306_WHITE);
    pantalla.drawLine(22, 19, 34, 14, SSD1306_WHITE);
    pantalla.drawLine(34, 14, 50, 20, SSD1306_WHITE);

    pantalla.drawLine(78, 19, 94, 13, SSD1306_WHITE);
    pantalla.drawLine(94, 13, 106, 18, SSD1306_WHITE);
    pantalla.drawLine(78, 20, 94, 14, SSD1306_WHITE);
    pantalla.drawLine(94, 14, 106, 19, SSD1306_WHITE);

    pantalla.fillRect(24, 27, 26, 13, SSD1306_WHITE);
    pantalla.fillRect(28, 24, 18, 4, SSD1306_WHITE);
    pantalla.fillRect(28, 40, 18, 2, SSD1306_WHITE);

    pantalla.fillRect(78, 27, 26, 13, SSD1306_WHITE);
    pantalla.fillRect(82, 24, 18, 4, SSD1306_WHITE);
    pantalla.fillRect(82, 40, 18, 2, SSD1306_WHITE);

    pantalla.fillRect(34, 29, 7, 9, SSD1306_BLACK);
    pantalla.fillRect(87, 29, 7, 9, SSD1306_BLACK);

    pantalla.fillRect(35, 30, 2, 2, SSD1306_WHITE);
    pantalla.fillRect(88, 30, 2, 2, SSD1306_WHITE);

    pantalla.drawLine(24, 38, 29, 42, SSD1306_WHITE);
    pantalla.drawLine(29, 42, 45, 42, SSD1306_WHITE);
    pantalla.drawLine(45, 42, 50, 38, SSD1306_WHITE);

    pantalla.drawLine(78, 38, 83, 42, SSD1306_WHITE);
    pantalla.drawLine(83, 42, 99, 42, SSD1306_WHITE);
    pantalla.drawLine(99, 42, 104, 38, SSD1306_WHITE);

    pantalla.drawLine(15, 27, 20, 23, SSD1306_WHITE);
    pantalla.drawLine(16, 32, 21, 32, SSD1306_WHITE);

    pantalla.drawLine(113, 27, 108, 23, SSD1306_WHITE);
    pantalla.drawLine(112, 32, 107, 32, SSD1306_WHITE);

    pantalla.drawLine(62, 14, 64, 10, SSD1306_WHITE);
    pantalla.drawLine(64, 10, 66, 14, SSD1306_WHITE);

    pantalla.fillRect(53, 49, 22, 3, SSD1306_WHITE);
    pantalla.fillRect(57, 53, 14, 2, SSD1306_WHITE);

    pantalla.display();
}


void dibujar_ojos_pacificos(void)
{
    pantalla.clearDisplay();

    pantalla.drawLine(24, 31, 29, 27, SSD1306_WHITE);
    pantalla.drawLine(29, 27, 35, 25, SSD1306_WHITE);
    pantalla.drawLine(35, 25, 41, 25, SSD1306_WHITE);
    pantalla.drawLine(41, 25, 47, 27, SSD1306_WHITE);
    pantalla.drawLine(47, 27, 50, 31, SSD1306_WHITE);

    pantalla.drawLine(24, 32, 29, 28, SSD1306_WHITE);
    pantalla.drawLine(29, 28, 35, 26, SSD1306_WHITE);
    pantalla.drawLine(35, 26, 41, 26, SSD1306_WHITE);
    pantalla.drawLine(41, 26, 47, 28, SSD1306_WHITE);
    pantalla.drawLine(47, 28, 50, 32, SSD1306_WHITE);

    pantalla.drawLine(78, 31, 83, 27, SSD1306_WHITE);
    pantalla.drawLine(83, 27, 89, 25, SSD1306_WHITE);
    pantalla.drawLine(89, 25, 95, 25, SSD1306_WHITE);
    pantalla.drawLine(95, 25, 101, 27, SSD1306_WHITE);
    pantalla.drawLine(101, 27, 104, 31, SSD1306_WHITE);

    pantalla.drawLine(78, 32, 83, 28, SSD1306_WHITE);
    pantalla.drawLine(83, 28, 89, 26, SSD1306_WHITE);
    pantalla.drawLine(89, 26, 95, 26, SSD1306_WHITE);
    pantalla.drawLine(95, 26, 101, 28, SSD1306_WHITE);
    pantalla.drawLine(101, 28, 104, 32, SSD1306_WHITE);

    pantalla.drawLine(52, 43, 57, 47, SSD1306_WHITE);
    pantalla.drawLine(57, 47, 63, 49, SSD1306_WHITE);
    pantalla.drawLine(63, 49, 65, 49, SSD1306_WHITE);
    pantalla.drawLine(65, 49, 71, 47, SSD1306_WHITE);
    pantalla.drawLine(71, 47, 76, 43, SSD1306_WHITE);

    pantalla.drawLine(52, 44, 57, 48, SSD1306_WHITE);
    pantalla.drawLine(57, 48, 63, 50, SSD1306_WHITE);
    pantalla.drawLine(63, 50, 65, 50, SSD1306_WHITE);
    pantalla.drawLine(65, 50, 71, 48, SSD1306_WHITE);
    pantalla.drawLine(71, 48, 76, 44, SSD1306_WHITE);

    pantalla.drawLine(60, 18, 62, 14, SSD1306_WHITE);
    pantalla.drawLine(62, 14, 64, 18, SSD1306_WHITE);
    pantalla.drawLine(64, 18, 66, 14, SSD1306_WHITE);
    pantalla.drawLine(66, 14, 68, 18, SSD1306_WHITE);
    pantalla.drawLine(60, 19, 68, 19, SSD1306_WHITE);

    pantalla.drawLine(14, 23, 17, 21, SSD1306_WHITE);
    pantalla.drawLine(17, 21, 20, 23, SSD1306_WHITE);

    pantalla.drawLine(108, 23, 111, 21, SSD1306_WHITE);
    pantalla.drawLine(111, 21, 114, 23, SSD1306_WHITE);

    pantalla.display();
}


void dibujar_ojos_ansiosos(void)
{
    pantalla.clearDisplay();

    pantalla.drawLine(24, 18, 31, 12, SSD1306_WHITE);
    pantalla.drawLine(31, 12, 40, 15, SSD1306_WHITE);
    pantalla.drawLine(40, 15, 50, 21, SSD1306_WHITE);
    pantalla.drawLine(24, 19, 31, 13, SSD1306_WHITE);
    pantalla.drawLine(31, 13, 40, 16, SSD1306_WHITE);
    pantalla.drawLine(40, 16, 50, 22, SSD1306_WHITE);

    pantalla.drawLine(78, 21, 88, 15, SSD1306_WHITE);
    pantalla.drawLine(88, 15, 97, 12, SSD1306_WHITE);
    pantalla.drawLine(97, 12, 104, 18, SSD1306_WHITE);
    pantalla.drawLine(78, 22, 88, 16, SSD1306_WHITE);
    pantalla.drawLine(88, 16, 97, 13, SSD1306_WHITE);
    pantalla.drawLine(97, 13, 104, 19, SSD1306_WHITE);

    pantalla.fillRect(24, 23, 26, 18, SSD1306_WHITE);
    pantalla.fillRect(78, 23, 26, 18, SSD1306_WHITE);

    pantalla.fillRect(32, 29, 7, 9, SSD1306_BLACK);
    pantalla.fillRect(89, 28, 6, 9, SSD1306_BLACK);

    pantalla.fillRect(33, 30, 2, 2, SSD1306_WHITE);
    pantalla.fillRect(90, 29, 2, 2, SSD1306_WHITE);

    pantalla.drawLine(17, 25, 20, 28, SSD1306_WHITE);
    pantalla.drawLine(20, 28, 17, 31, SSD1306_WHITE);

    pantalla.drawLine(108, 31, 111, 28, SSD1306_WHITE);
    pantalla.drawLine(111, 28, 108, 25, SSD1306_WHITE);

    pantalla.drawLine(53, 27, 57, 30, SSD1306_WHITE);
    pantalla.drawLine(71, 30, 75, 27, SSD1306_WHITE);

    pantalla.drawLine(114, 17, 111, 22, SSD1306_WHITE);
    pantalla.drawLine(111, 22, 114, 27, SSD1306_WHITE);
    pantalla.drawLine(114, 27, 117, 22, SSD1306_WHITE);
    pantalla.drawLine(117, 22, 114, 17, SSD1306_WHITE);

    pantalla.drawLine(52, 48, 58, 45, SSD1306_WHITE);
    pantalla.drawLine(58, 45, 63, 49, SSD1306_WHITE);
    pantalla.drawLine(63, 49, 68, 45, SSD1306_WHITE);
    pantalla.drawLine(68, 45, 76, 48, SSD1306_WHITE);

    pantalla.drawLine(52, 49, 58, 46, SSD1306_WHITE);
    pantalla.drawLine(58, 46, 63, 50, SSD1306_WHITE);
    pantalla.drawLine(63, 50, 68, 46, SSD1306_WHITE);
    pantalla.drawLine(68, 46, 76, 49, SSD1306_WHITE);

    pantalla.display();
}


void dibujar_ojos_culpables(void)
{
    pantalla.clearDisplay();

    pantalla.drawLine(24, 19, 31, 16, SSD1306_WHITE);
    pantalla.drawLine(31, 16, 40, 13, SSD1306_WHITE);
    pantalla.drawLine(40, 13, 50, 17, SSD1306_WHITE);
    pantalla.drawLine(24, 20, 31, 17, SSD1306_WHITE);
    pantalla.drawLine(31, 17, 40, 14, SSD1306_WHITE);
    pantalla.drawLine(40, 14, 50, 18, SSD1306_WHITE);

    pantalla.drawLine(78, 17, 88, 13, SSD1306_WHITE);
    pantalla.drawLine(88, 13, 97, 16, SSD1306_WHITE);
    pantalla.drawLine(97, 16, 104, 19, SSD1306_WHITE);
    pantalla.drawLine(78, 18, 88, 14, SSD1306_WHITE);
    pantalla.drawLine(88, 14, 97, 17, SSD1306_WHITE);
    pantalla.drawLine(97, 17, 104, 20, SSD1306_WHITE);

    pantalla.fillRect(24, 24, 26, 16, SSD1306_WHITE);
    pantalla.fillRect(78, 24, 26, 16, SSD1306_WHITE);

    pantalla.fillRect(24, 24, 26, 6, SSD1306_BLACK);
    pantalla.fillRect(78, 24, 26, 6, SSD1306_BLACK);

    pantalla.fillRect(37, 32, 6, 6, SSD1306_BLACK);
    pantalla.fillRect(85, 32, 6, 6, SSD1306_BLACK);

    pantalla.fillRect(38, 33, 2, 2, SSD1306_WHITE);
    pantalla.fillRect(86, 33, 2, 2, SSD1306_WHITE);

    pantalla.drawLine(17, 37, 20, 40, SSD1306_WHITE);
    pantalla.drawLine(21, 38, 24, 41, SSD1306_WHITE);
    pantalla.drawLine(104, 38, 107, 41, SSD1306_WHITE);
    pantalla.drawLine(108, 37, 111, 40, SSD1306_WHITE);

    pantalla.drawLine(27, 44, 31, 42, SSD1306_WHITE);
    pantalla.drawLine(33, 45, 37, 43, SSD1306_WHITE);
    pantalla.drawLine(91, 43, 95, 45, SSD1306_WHITE);
    pantalla.drawLine(97, 42, 101, 44, SSD1306_WHITE);

    pantalla.drawLine(57, 47, 62, 49, SSD1306_WHITE);
    pantalla.drawLine(62, 49, 66, 49, SSD1306_WHITE);
    pantalla.drawLine(66, 49, 71, 47, SSD1306_WHITE);

    pantalla.drawLine(57, 48, 62, 50, SSD1306_WHITE);
    pantalla.drawLine(62, 50, 66, 50, SSD1306_WHITE);
    pantalla.drawLine(66, 50, 71, 48, SSD1306_WHITE);

    pantalla.display();
}


void dibujar_ojos_tristes(void)
{
    pantalla.clearDisplay();

    pantalla.drawLine(24, 18, 50, 12, SSD1306_WHITE);
    pantalla.drawLine(24, 19, 50, 13, SSD1306_WHITE);

    pantalla.drawLine(78, 12, 104, 18, SSD1306_WHITE);
    pantalla.drawLine(78, 13, 104, 19, SSD1306_WHITE);

    pantalla.fillRect(24, 24, 26, 16, SSD1306_WHITE);
    pantalla.fillRect(78, 24, 26, 16, SSD1306_WHITE);

    pantalla.drawLine(24, 30, 50, 25, SSD1306_BLACK);
    pantalla.drawLine(24, 31, 50, 26, SSD1306_BLACK);

    pantalla.drawLine(78, 25, 104, 30, SSD1306_BLACK);
    pantalla.drawLine(78, 26, 104, 31, SSD1306_BLACK);

    pantalla.fillRect(34, 31, 7, 7, SSD1306_BLACK);
    pantalla.fillRect(87, 31, 7, 7, SSD1306_BLACK);

    pantalla.fillRect(35, 32, 2, 2, SSD1306_WHITE);
    pantalla.fillRect(88, 32, 2, 2, SSD1306_WHITE);

    pantalla.drawLine(18, 34, 15, 38, SSD1306_WHITE);
    pantalla.drawLine(15, 38, 15, 42, SSD1306_WHITE);
    pantalla.drawLine(15, 42, 18, 45, SSD1306_WHITE);
    pantalla.drawLine(18, 45, 21, 42, SSD1306_WHITE);
    pantalla.drawLine(21, 42, 21, 38, SSD1306_WHITE);
    pantalla.drawLine(21, 38, 18, 34, SSD1306_WHITE);

    pantalla.drawLine(110, 34, 107, 38, SSD1306_WHITE);
    pantalla.drawLine(107, 38, 107, 42, SSD1306_WHITE);
    pantalla.drawLine(107, 42, 110, 45, SSD1306_WHITE);
    pantalla.drawLine(110, 45, 113, 42, SSD1306_WHITE);
    pantalla.drawLine(113, 42, 113, 38, SSD1306_WHITE);
    pantalla.drawLine(113, 38, 110, 34, SSD1306_WHITE);

    pantalla.drawLine(27, 42, 33, 44, SSD1306_WHITE);
    pantalla.drawLine(45, 44, 49, 42, SSD1306_WHITE);
    pantalla.drawLine(79, 42, 83, 44, SSD1306_WHITE);
    pantalla.drawLine(95, 44, 101, 42, SSD1306_WHITE);

    pantalla.drawLine(51, 48, 57, 44, SSD1306_WHITE);
    pantalla.drawLine(57, 44, 64, 42, SSD1306_WHITE);
    pantalla.drawLine(64, 42, 71, 44, SSD1306_WHITE);
    pantalla.drawLine(71, 44, 77, 48, SSD1306_WHITE);

    pantalla.drawLine(51, 49, 57, 45, SSD1306_WHITE);
    pantalla.drawLine(57, 45, 64, 43, SSD1306_WHITE);
    pantalla.drawLine(64, 43, 71, 45, SSD1306_WHITE);
    pantalla.drawLine(71, 45, 77, 49, SSD1306_WHITE);

    pantalla.display();
}

void dibujar_ojos_humillados(void)
{
    pantalla.clearDisplay();

    pantalla.drawLine(24, 14, 50, 20, SSD1306_WHITE);
    pantalla.drawLine(24, 15, 50, 21, SSD1306_WHITE);

    pantalla.drawLine(78, 20, 104, 14, SSD1306_WHITE);
    pantalla.drawLine(78, 21, 104, 15, SSD1306_WHITE);

    pantalla.fillRect(24, 24, 26, 14, SSD1306_WHITE);
    pantalla.fillRect(78, 24, 26, 14, SSD1306_WHITE);

    pantalla.drawLine(24, 24, 50, 29, SSD1306_BLACK);
    pantalla.drawLine(24, 25, 50, 30, SSD1306_BLACK);

    pantalla.drawLine(78, 29, 104, 24, SSD1306_BLACK);
    pantalla.drawLine(78, 30, 104, 25, SSD1306_BLACK);

    pantalla.fillRect(34, 31, 9, 7, SSD1306_BLACK);
    pantalla.fillRect(85, 31, 9, 7, SSD1306_BLACK);

    pantalla.drawPixel(35, 32, SSD1306_WHITE);
    pantalla.drawPixel(86, 32, SSD1306_WHITE);

    pantalla.drawLine(27, 40, 34, 42, SSD1306_WHITE);
    pantalla.drawLine(34, 42, 40, 40, SSD1306_WHITE);

    pantalla.drawLine(88, 40, 94, 42, SSD1306_WHITE);
    pantalla.drawLine(94, 42, 101, 40, SSD1306_WHITE);

    pantalla.drawLine(57, 49, 62, 47, SSD1306_WHITE);
    pantalla.drawLine(62, 47, 67, 47, SSD1306_WHITE);
    pantalla.drawLine(67, 47, 72, 49, SSD1306_WHITE);

    pantalla.drawLine(58, 50, 62, 48, SSD1306_WHITE);
    pantalla.drawLine(62, 48, 67, 48, SSD1306_WHITE);
    pantalla.drawLine(67, 48, 71, 50, SSD1306_WHITE);

    pantalla.drawLine(27, 46, 31, 47, SSD1306_WHITE);
    pantalla.drawLine(33, 47, 37, 46, SSD1306_WHITE);

    pantalla.drawLine(91, 46, 95, 47, SSD1306_WHITE);
    pantalla.drawLine(97, 47, 101, 46, SSD1306_WHITE);

    pantalla.display();
}

void dibujar_ojos_rechazados(void)
{
    pantalla.clearDisplay();

    pantalla.drawLine(24, 15, 50, 21, SSD1306_WHITE);
    pantalla.drawLine(24, 16, 50, 22, SSD1306_WHITE);

    pantalla.drawLine(78, 21, 104, 15, SSD1306_WHITE);
    pantalla.drawLine(78, 22, 104, 16, SSD1306_WHITE);

    pantalla.fillRect(24, 25, 26, 13, SSD1306_WHITE);
    pantalla.fillRect(78, 25, 26, 13, SSD1306_WHITE);

    pantalla.drawLine(24, 25, 50, 30, SSD1306_BLACK);
    pantalla.drawLine(24, 26, 50, 31, SSD1306_BLACK);

    pantalla.drawLine(78, 30, 104, 25, SSD1306_BLACK);
    pantalla.drawLine(78, 31, 104, 26, SSD1306_BLACK);

    pantalla.fillRect(27, 31, 8, 7, SSD1306_BLACK);
    pantalla.fillRect(96, 31, 8, 7, SSD1306_BLACK);

    pantalla.drawPixel(28, 32, SSD1306_WHITE);
    pantalla.drawPixel(97, 32, SSD1306_WHITE);

    pantalla.drawLine(28, 42, 35, 44, SSD1306_WHITE);
    pantalla.drawLine(40, 43, 46, 41, SSD1306_WHITE);

    pantalla.drawLine(82, 41, 88, 43, SSD1306_WHITE);
    pantalla.drawLine(93, 44, 100, 42, SSD1306_WHITE);

    pantalla.drawLine(54, 47, 61, 50, SSD1306_WHITE);
    pantalla.drawLine(61, 50, 68, 50, SSD1306_WHITE);
    pantalla.drawLine(68, 50, 75, 47, SSD1306_WHITE);

    pantalla.drawLine(55, 48, 61, 51, SSD1306_WHITE);
    pantalla.drawLine(61, 51, 68, 51, SSD1306_WHITE);
    pantalla.drawLine(68, 51, 74, 48, SSD1306_WHITE);

    pantalla.display();
}

void dibujar_ojos_celosos(void)
{
    pantalla.clearDisplay();

    pantalla.drawLine(24, 20, 50, 12, SSD1306_WHITE);
    pantalla.drawLine(24, 21, 50, 13, SSD1306_WHITE);

    pantalla.drawLine(78, 12, 104, 20, SSD1306_WHITE);
    pantalla.drawLine(78, 13, 104, 21, SSD1306_WHITE);

    pantalla.fillRect(24, 24, 26, 16, SSD1306_WHITE);
    pantalla.fillRect(78, 24, 26, 16, SSD1306_WHITE);

    pantalla.drawLine(24, 24, 50, 29, SSD1306_BLACK);
    pantalla.drawLine(24, 25, 50, 30, SSD1306_BLACK);

    pantalla.drawLine(78, 29, 104, 24, SSD1306_BLACK);
    pantalla.drawLine(78, 30, 104, 25, SSD1306_BLACK);

    pantalla.fillRect(38, 30, 8, 9, SSD1306_BLACK);
    pantalla.fillRect(80, 30, 8, 9, SSD1306_BLACK);

    pantalla.drawPixel(39, 31, SSD1306_WHITE);
    pantalla.drawPixel(81, 31, SSD1306_WHITE);

    pantalla.drawLine(27, 42, 34, 40, SSD1306_WHITE);
    pantalla.drawLine(43, 40, 49, 42, SSD1306_WHITE);

    pantalla.drawLine(79, 42, 85, 40, SSD1306_WHITE);
    pantalla.drawLine(94, 40, 101, 42, SSD1306_WHITE);

    pantalla.drawLine(55, 47, 73, 47, SSD1306_WHITE);
    pantalla.drawLine(55, 48, 73, 48, SSD1306_WHITE);

    pantalla.drawLine(51, 46, 54, 48, SSD1306_WHITE);
    pantalla.drawLine(74, 48, 77, 46, SSD1306_WHITE);

    pantalla.display();
}

void dibujar_ojos_odiosos(void)
{
    pantalla.clearDisplay();

    pantalla.drawLine(24, 20, 50, 10, SSD1306_WHITE);
    pantalla.drawLine(24, 21, 50, 11, SSD1306_WHITE);
    pantalla.drawLine(24, 22, 50, 12, SSD1306_WHITE);

    pantalla.drawLine(78, 10, 104, 20, SSD1306_WHITE);
    pantalla.drawLine(78, 11, 104, 21, SSD1306_WHITE);
    pantalla.drawLine(78, 12, 104, 22, SSD1306_WHITE);

    pantalla.fillRect(24, 25, 26, 13, SSD1306_WHITE);
    pantalla.fillRect(78, 25, 26, 13, SSD1306_WHITE);

    pantalla.fillTriangle(24, 25, 50, 25, 50, 32, SSD1306_BLACK);
    pantalla.fillTriangle(78, 25, 104, 25, 78, 32, SSD1306_BLACK);

    pantalla.fillRect(39, 30, 6, 7, SSD1306_BLACK);
    pantalla.fillRect(83, 30, 6, 7, SSD1306_BLACK);

    pantalla.drawPixel(40, 31, SSD1306_WHITE);
    pantalla.drawPixel(84, 31, SSD1306_WHITE);

    pantalla.drawLine(27, 41, 34, 39, SSD1306_WHITE);
    pantalla.drawLine(34, 39, 40, 41, SSD1306_WHITE);

    pantalla.drawLine(88, 41, 94, 39, SSD1306_WHITE);
    pantalla.drawLine(94, 39, 101, 41, SSD1306_WHITE);

    pantalla.drawLine(53, 47, 59, 45, SSD1306_WHITE);
    pantalla.drawLine(59, 45, 69, 45, SSD1306_WHITE);
    pantalla.drawLine(69, 45, 75, 47, SSD1306_WHITE);

    pantalla.drawLine(53, 48, 59, 46, SSD1306_WHITE);
    pantalla.drawLine(59, 46, 69, 46, SSD1306_WHITE);
    pantalla.drawLine(69, 46, 75, 48, SSD1306_WHITE);

    pantalla.drawLine(51, 45, 54, 47, SSD1306_WHITE);
    pantalla.drawLine(74, 47, 77, 45, SSD1306_WHITE);

    pantalla.display();
}

void dibujar_ojos_desquiciados(void)
{
    pantalla.clearDisplay();

    pantalla.drawLine(23, 15, 48, 8, SSD1306_WHITE);
    pantalla.drawLine(23, 16, 48, 9, SSD1306_WHITE);
    pantalla.drawLine(23, 17, 48, 10, SSD1306_WHITE);

    pantalla.drawLine(79, 10, 105, 17, SSD1306_WHITE);
    pantalla.drawLine(79, 11, 105, 18, SSD1306_WHITE);
    pantalla.drawLine(79, 12, 105, 19, SSD1306_WHITE);

    pantalla.fillRect(24, 20, 27, 23, SSD1306_WHITE);
    pantalla.fillRect(77, 20, 27, 23, SSD1306_WHITE);

    pantalla.drawLine(24, 20, 30, 24, SSD1306_BLACK);
    pantalla.drawLine(30, 24, 39, 21, SSD1306_BLACK);
    pantalla.drawLine(39, 21, 51, 25, SSD1306_BLACK);

    pantalla.drawLine(77, 24, 85, 20, SSD1306_BLACK);
    pantalla.drawLine(85, 20, 94, 24, SSD1306_BLACK);
    pantalla.drawLine(94, 24, 104, 20, SSD1306_BLACK);

    pantalla.fillRect(42, 29, 6, 8, SSD1306_BLACK);
    pantalla.fillRect(80, 31, 6, 8, SSD1306_BLACK);

    pantalla.drawPixel(43, 30, SSD1306_WHITE);
    pantalla.drawPixel(81, 32, SSD1306_WHITE);

    pantalla.drawLine(25, 45, 32, 43, SSD1306_WHITE);
    pantalla.drawLine(35, 45, 40, 47, SSD1306_WHITE);

    pantalla.drawLine(86, 44, 92, 46, SSD1306_WHITE);
    pantalla.drawLine(96, 44, 103, 46, SSD1306_WHITE);

    pantalla.drawLine(53, 49, 59, 45, SSD1306_WHITE);
    pantalla.drawLine(59, 45, 65, 48, SSD1306_WHITE);
    pantalla.drawLine(65, 48, 70, 44, SSD1306_WHITE);
    pantalla.drawLine(70, 44, 76, 48, SSD1306_WHITE);

    pantalla.drawLine(54, 50, 59, 46, SSD1306_WHITE);
    pantalla.drawLine(59, 46, 65, 49, SSD1306_WHITE);
    pantalla.drawLine(65, 49, 70, 45, SSD1306_WHITE);
    pantalla.drawLine(70, 45, 75, 49, SSD1306_WHITE);

    pantalla.display();
}

void dibujar_ojos_vengativos(void)
{
    pantalla.clearDisplay();

    pantalla.drawLine(23, 19, 50, 9, SSD1306_WHITE);
    pantalla.drawLine(23, 20, 50, 10, SSD1306_WHITE);
    pantalla.drawLine(23, 21, 50, 11, SSD1306_WHITE);

    pantalla.drawLine(78, 9, 105, 19, SSD1306_WHITE);
    pantalla.drawLine(78, 10, 105, 20, SSD1306_WHITE);
    pantalla.drawLine(78, 11, 105, 21, SSD1306_WHITE);

    pantalla.fillRect(24, 24, 26, 15, SSD1306_WHITE);
    pantalla.fillRect(78, 24, 26, 15, SSD1306_WHITE);

    pantalla.fillTriangle(24, 24, 50, 24, 50, 31, SSD1306_BLACK);
    pantalla.fillTriangle(78, 24, 104, 24, 78, 31, SSD1306_BLACK);

    pantalla.drawLine(25, 38, 32, 40, SSD1306_BLACK);
    pantalla.drawLine(32, 40, 43, 40, SSD1306_BLACK);
    pantalla.drawLine(43, 40, 49, 37, SSD1306_BLACK);

    pantalla.drawLine(79, 37, 85, 40, SSD1306_BLACK);
    pantalla.drawLine(85, 40, 96, 40, SSD1306_BLACK);
    pantalla.drawLine(96, 40, 103, 38, SSD1306_BLACK);

    pantalla.fillRect(34, 30, 8, 9, SSD1306_BLACK);
    pantalla.fillRect(86, 30, 8, 9, SSD1306_BLACK);

    pantalla.drawPixel(35, 31, SSD1306_WHITE);
    pantalla.drawPixel(87, 31, SSD1306_WHITE);

    pantalla.drawLine(48, 40, 53, 37, SSD1306_WHITE);
    pantalla.drawLine(75, 37, 80, 40, SSD1306_WHITE);

    pantalla.drawLine(55, 47, 73, 47, SSD1306_WHITE);
    pantalla.drawLine(55, 48, 73, 48, SSD1306_WHITE);
    pantalla.drawLine(53, 46, 55, 48, SSD1306_WHITE);
    pantalla.drawLine(73, 48, 76, 46, SSD1306_WHITE);

    pantalla.display();
}

void dibujar_ojos_frustrados(void)
{
    pantalla.clearDisplay();

    pantalla.drawLine(24, 19, 50, 12, SSD1306_WHITE);
    pantalla.drawLine(24, 20, 50, 13, SSD1306_WHITE);
    pantalla.drawLine(24, 21, 50, 14, SSD1306_WHITE);

    pantalla.drawLine(78, 12, 104, 19, SSD1306_WHITE);
    pantalla.drawLine(78, 13, 104, 20, SSD1306_WHITE);
    pantalla.drawLine(78, 14, 104, 21, SSD1306_WHITE);

    pantalla.fillRect(24, 25, 26, 15, SSD1306_WHITE);
    pantalla.fillRect(78, 25, 26, 15, SSD1306_WHITE);

    pantalla.fillTriangle(24, 25, 50, 25, 50, 31, SSD1306_BLACK);
    pantalla.fillTriangle(78, 25, 104, 25, 78, 31, SSD1306_BLACK);

    pantalla.drawLine(25, 38, 31, 40, SSD1306_BLACK);
    pantalla.drawLine(31, 40, 44, 40, SSD1306_BLACK);
    pantalla.drawLine(44, 40, 49, 38, SSD1306_BLACK);

    pantalla.drawLine(79, 38, 84, 40, SSD1306_BLACK);
    pantalla.drawLine(84, 40, 97, 40, SSD1306_BLACK);
    pantalla.drawLine(97, 40, 103, 38, SSD1306_BLACK);

    pantalla.fillRect(34, 27, 8, 8, SSD1306_BLACK);
    pantalla.fillRect(86, 27, 8, 8, SSD1306_BLACK);

    pantalla.drawPixel(35, 28, SSD1306_WHITE);
    pantalla.drawPixel(87, 28, SSD1306_WHITE);

    pantalla.drawLine(57, 20, 61, 24, SSD1306_WHITE);
    pantalla.drawLine(61, 24, 64, 20, SSD1306_WHITE);

    pantalla.drawLine(65, 20, 68, 24, SSD1306_WHITE);
    pantalla.drawLine(68, 24, 72, 20, SSD1306_WHITE);

    pantalla.drawLine(53, 46, 59, 49, SSD1306_WHITE);
    pantalla.drawLine(59, 49, 69, 49, SSD1306_WHITE);
    pantalla.drawLine(69, 49, 75, 46, SSD1306_WHITE);

    pantalla.drawLine(54, 47, 59, 50, SSD1306_WHITE);
    pantalla.drawLine(59, 50, 69, 50, SSD1306_WHITE);
    pantalla.drawLine(69, 50, 74, 47, SSD1306_WHITE);

    pantalla.display();
}

void dibujar_ojos_distantes(void)
{
    pantalla.clearDisplay();

    pantalla.drawLine(24, 16, 50, 18, SSD1306_WHITE);
    pantalla.drawLine(24, 17, 50, 19, SSD1306_WHITE);

    pantalla.drawLine(78, 18, 104, 16, SSD1306_WHITE);
    pantalla.drawLine(78, 19, 104, 17, SSD1306_WHITE);

    pantalla.fillRect(24, 24, 26, 16, SSD1306_WHITE);
    pantalla.fillRect(78, 24, 26, 16, SSD1306_WHITE);

    pantalla.drawLine(24, 24, 50, 27, SSD1306_BLACK);
    pantalla.drawLine(24, 25, 50, 28, SSD1306_BLACK);

    pantalla.drawLine(78, 27, 104, 24, SSD1306_BLACK);
    pantalla.drawLine(78, 28, 104, 25, SSD1306_BLACK);

    pantalla.fillRect(26, 30, 7, 7, SSD1306_BLACK);
    pantalla.fillRect(95, 30, 7, 7, SSD1306_BLACK);

    pantalla.drawPixel(27, 31, SSD1306_WHITE);
    pantalla.drawPixel(96, 31, SSD1306_WHITE);

    pantalla.drawLine(28, 42, 35, 43, SSD1306_WHITE);
    pantalla.drawLine(40, 43, 47, 42, SSD1306_WHITE);

    pantalla.drawLine(81, 42, 88, 43, SSD1306_WHITE);
    pantalla.drawLine(92, 43, 99, 42, SSD1306_WHITE);

    pantalla.drawLine(53, 47, 75, 47, SSD1306_WHITE);
    pantalla.drawLine(53, 48, 75, 48, SSD1306_WHITE);

    pantalla.display();
}

void dibujar_ojos_dinero(void)
{
    pantalla.clearDisplay();

    pantalla.drawLine(24, 17, 50, 13, SSD1306_WHITE);
    pantalla.drawLine(24, 18, 50, 14, SSD1306_WHITE);

    pantalla.drawLine(78, 13, 104, 17, SSD1306_WHITE);
    pantalla.drawLine(78, 14, 104, 18, SSD1306_WHITE);

    pantalla.fillRect(24, 24, 26, 20, SSD1306_WHITE);
    pantalla.fillRect(78, 24, 26, 20, SSD1306_WHITE);

    pantalla.setTextSize(2);
    pantalla.setTextColor(SSD1306_BLACK);
    pantalla.setCursor(29, 26);
    pantalla.print("$");

    pantalla.setCursor(83, 26);
    pantalla.print("$");

    pantalla.drawPixel(26, 25, SSD1306_WHITE);
    pantalla.drawPixel(80, 25, SSD1306_WHITE);

    pantalla.drawLine(48, 49, 55, 53, SSD1306_WHITE);
    pantalla.drawLine(55, 53, 64, 55, SSD1306_WHITE);
    pantalla.drawLine(64, 55, 73, 53, SSD1306_WHITE);
    pantalla.drawLine(73, 53, 80, 49, SSD1306_WHITE);

    pantalla.display();
}

void dibujar_ojos_guinando(void)
{
    pantalla.clearDisplay();

    pantalla.drawLine(24, 17, 50, 17, SSD1306_WHITE);
    pantalla.drawLine(24, 18, 50, 18, SSD1306_WHITE);

    pantalla.drawLine(78, 17, 104, 13, SSD1306_WHITE);
    pantalla.drawLine(78, 18, 104, 14, SSD1306_WHITE);

    pantalla.fillRect(24, 24, 26, 20, SSD1306_WHITE);

    pantalla.drawLine(24, 24, 50, 24, SSD1306_BLACK);
    pantalla.drawLine(24, 25, 50, 25, SSD1306_BLACK);

    pantalla.fillRect(33, 29, 9, 12, SSD1306_BLACK);

    pantalla.fillRect(34, 30, 3, 3, SSD1306_WHITE);

    pantalla.drawLine(78, 35, 84, 31, SSD1306_WHITE);
    pantalla.drawLine(84, 31, 91, 29, SSD1306_WHITE);
    pantalla.drawLine(91, 29, 98, 31, SSD1306_WHITE);
    pantalla.drawLine(98, 31, 104, 35, SSD1306_WHITE);

    pantalla.drawLine(78, 36, 84, 32, SSD1306_WHITE);
    pantalla.drawLine(84, 32, 91, 30, SSD1306_WHITE);
    pantalla.drawLine(91, 30, 98, 32, SSD1306_WHITE);
    pantalla.drawLine(98, 32, 104, 36, SSD1306_WHITE);

    pantalla.drawLine(80, 39, 84, 41, SSD1306_WHITE);
    pantalla.drawLine(98, 41, 102, 39, SSD1306_WHITE);

    pantalla.drawLine(48, 48, 55, 52, SSD1306_WHITE);
    pantalla.drawLine(55, 52, 64, 54, SSD1306_WHITE);
    pantalla.drawLine(64, 54, 73, 52, SSD1306_WHITE);
    pantalla.drawLine(73, 52, 80, 48, SSD1306_WHITE);

    pantalla.display();
}

void dibujar_ojos_halloween(void)
{
    pantalla.clearDisplay();

    pantalla.drawLine(23, 20, 50, 12, SSD1306_WHITE);
    pantalla.drawLine(23, 21, 50, 13, SSD1306_WHITE);

    pantalla.drawLine(78, 12, 105, 20, SSD1306_WHITE);
    pantalla.drawLine(78, 13, 105, 21, SSD1306_WHITE);

    pantalla.fillRect(24, 24, 26, 20, SSD1306_WHITE);
    pantalla.fillRect(78, 24, 26, 20, SSD1306_WHITE);

    pantalla.drawLine(24, 24, 50, 32, SSD1306_BLACK);
    pantalla.drawLine(25, 24, 50, 33, SSD1306_BLACK);

    pantalla.drawLine(78, 32, 104, 24, SSD1306_BLACK);
    pantalla.drawLine(78, 33, 103, 24, SSD1306_BLACK);

    pantalla.fillRect(34, 33, 6, 8, SSD1306_BLACK);
    pantalla.fillRect(88, 33, 6, 8, SSD1306_BLACK);

    pantalla.drawPixel(35, 34, SSD1306_WHITE);
    pantalla.drawPixel(89, 34, SSD1306_WHITE);

    pantalla.drawLine(20, 38, 24, 41, SSD1306_WHITE);
    pantalla.drawLine(50, 40, 54, 37, SSD1306_WHITE);

    pantalla.drawLine(74, 37, 78, 40, SSD1306_WHITE);
    pantalla.drawLine(104, 41, 108, 38, SSD1306_WHITE);

    pantalla.drawLine(45, 48, 52, 45, SSD1306_WHITE);
    pantalla.drawLine(52, 45, 59, 49, SSD1306_WHITE);
    pantalla.drawLine(59, 49, 66, 45, SSD1306_WHITE);
    pantalla.drawLine(66, 45, 73, 49, SSD1306_WHITE);
    pantalla.drawLine(73, 49, 82, 46, SSD1306_WHITE);

    pantalla.fillTriangle(51, 46, 57, 46, 54, 52, SSD1306_WHITE);
    pantalla.fillTriangle(69, 47, 75, 47, 72, 53, SSD1306_WHITE);

    pantalla.display();
}

void dibujar_ojos_bailarines(void)
{
    pantalla.clearDisplay();

    pantalla.drawLine(24, 16, 35, 11, SSD1306_WHITE);
    pantalla.drawLine(35, 11, 50, 16, SSD1306_WHITE);
    pantalla.drawLine(24, 17, 35, 12, SSD1306_WHITE);
    pantalla.drawLine(35, 12, 50, 17, SSD1306_WHITE);

    pantalla.drawLine(78, 16, 91, 10, SSD1306_WHITE);
    pantalla.drawLine(91, 10, 104, 16, SSD1306_WHITE);
    pantalla.drawLine(78, 17, 91, 11, SSD1306_WHITE);
    pantalla.drawLine(91, 11, 104, 17, SSD1306_WHITE);

    pantalla.fillRoundRect(24, 23, 26, 20, 4, SSD1306_WHITE);
    pantalla.fillRoundRect(78, 23, 26, 20, 4, SSD1306_WHITE);

    pantalla.fillRect(29, 27, 8, 11, SSD1306_BLACK);
    pantalla.fillRect(91, 26, 8, 11, SSD1306_BLACK);

    pantalla.fillRect(30, 28, 3, 3, SSD1306_WHITE);
    pantalla.fillRect(92, 27, 3, 3, SSD1306_WHITE);

    pantalla.drawLine(27, 41, 33, 44, SSD1306_WHITE);
    pantalla.drawLine(33, 44, 42, 44, SSD1306_WHITE);
    pantalla.drawLine(42, 44, 48, 41, SSD1306_WHITE);

    pantalla.drawLine(81, 41, 87, 44, SSD1306_WHITE);
    pantalla.drawLine(87, 44, 96, 44, SSD1306_WHITE);
    pantalla.drawLine(96, 44, 102, 41, SSD1306_WHITE);

    pantalla.drawLine(49, 49, 56, 53, SSD1306_WHITE);
    pantalla.drawLine(56, 53, 64, 55, SSD1306_WHITE);
    pantalla.drawLine(64, 55, 72, 53, SSD1306_WHITE);
    pantalla.drawLine(72, 53, 79, 49, SSD1306_WHITE);

    pantalla.drawLine(15, 25, 15, 32, SSD1306_WHITE);
    pantalla.drawLine(15, 25, 21, 23, SSD1306_WHITE);
    pantalla.fillCircle(13, 33, 2, SSD1306_WHITE);

    pantalla.drawLine(109, 20, 109, 27, SSD1306_WHITE);
    pantalla.drawLine(109, 20, 115, 18, SSD1306_WHITE);
    pantalla.fillCircle(107, 28, 2, SSD1306_WHITE);

    pantalla.display();
}

void dibujar_desconfiados(void)
{
    pantalla.clearDisplay();

    pantalla.fillRect(24, 26, 26, 12, SSD1306_WHITE);

    pantalla.fillRect(42, 26, 8, 12, SSD1306_BLACK);

    pantalla.drawLine(20, 18, 50, 12, SSD1306_WHITE);
    pantalla.drawLine(20, 19, 50, 13, SSD1306_WHITE);

    pantalla.fillRect(78, 26, 26, 12, SSD1306_WHITE);

    pantalla.fillRect(96, 26, 8, 12, SSD1306_BLACK);

    pantalla.drawLine(78, 16, 108, 20, SSD1306_WHITE);
    pantalla.drawLine(78, 17, 108, 21, SSD1306_WHITE);
    pantalla.drawLine(52, 46, 62, 44, SSD1306_WHITE);
    pantalla.drawLine(62, 44, 76, 46, SSD1306_WHITE);

    pantalla.display();
}

void dibujar_sarcasticos(void)
{
    pantalla.clearDisplay();

    pantalla.fillRect(24, 28, 26, 8, SSD1306_WHITE);

    pantalla.fillRect(42, 28, 8, 8, SSD1306_BLACK);

    pantalla.drawLine(22, 20, 50, 16, SSD1306_WHITE);
    pantalla.drawLine(22, 21, 50, 17, SSD1306_WHITE);

    pantalla.fillRect(78, 28, 26, 8, SSD1306_WHITE);

    pantalla.fillRect(96, 28, 8, 8, SSD1306_BLACK);

    pantalla.drawLine(78, 16, 106, 20, SSD1306_WHITE);
    pantalla.drawLine(78, 17, 106, 21, SSD1306_WHITE);

    pantalla.drawLine(50, 46, 62, 48, SSD1306_WHITE);
    pantalla.drawLine(62, 48, 76, 44, SSD1306_WHITE);
    pantalla.drawLine(76, 44, 82, 42, SSD1306_WHITE);

    pantalla.display();
}

void dibujar_maliciosos(void)
{
    pantalla.clearDisplay();

    pantalla.fillRect(24, 24, 26, 14, SSD1306_WHITE);
    pantalla.fillRect(42, 24, 5, 6, SSD1306_BLACK);

    pantalla.drawLine(22, 22, 50, 30, SSD1306_BLACK);

    pantalla.drawLine(20, 16, 50, 21, SSD1306_WHITE);
    pantalla.drawLine(20, 17, 50, 22, SSD1306_WHITE);

    pantalla.fillRect(78, 24, 26, 14, SSD1306_WHITE);
    pantalla.fillRect(80, 24, 5, 6, SSD1306_BLACK);

    pantalla.drawLine(78, 30, 106, 22, SSD1306_BLACK);

    pantalla.drawLine(78, 21, 108, 16, SSD1306_WHITE);
    pantalla.drawLine(78, 22, 108, 17, SSD1306_WHITE);

    pantalla.fillRect(44, 29, 4, 5, SSD1306_BLACK);
    pantalla.fillRect(80, 29, 4, 5, SSD1306_BLACK);

    pantalla.drawLine(48, 46, 58, 49, SSD1306_WHITE);
    pantalla.drawLine(58, 49, 70, 47, SSD1306_WHITE);
    pantalla.drawLine(70, 47, 82, 42, SSD1306_WHITE);

    pantalla.display();
}

void dibujar_avergonzados(void)
{
    pantalla.clearDisplay();

    pantalla.fillRect(24, 22, 26, 16, SSD1306_WHITE);
    pantalla.fillRect(34, 32, 8, 6, SSD1306_BLACK);

    pantalla.drawLine(24, 22, 50, 22, SSD1306_BLACK);

    pantalla.drawLine(24, 17, 50, 19, SSD1306_WHITE);
    pantalla.drawLine(24, 18, 50, 20, SSD1306_WHITE);

    pantalla.fillRect(78, 22, 26, 16, SSD1306_WHITE);
    pantalla.fillRect(88, 32, 8, 6, SSD1306_BLACK);

    pantalla.drawLine(78, 22, 104, 22, SSD1306_BLACK);

    pantalla.drawLine(78, 19, 104, 17, SSD1306_WHITE);
    pantalla.drawLine(78, 20, 104, 18, SSD1306_WHITE);

    pantalla.fillRect(20, 40, 3, 3, SSD1306_WHITE);
    pantalla.fillRect(24, 43, 3, 3, SSD1306_WHITE);
    pantalla.fillRect(28, 40, 3, 3, SSD1306_WHITE);

    pantalla.fillRect(97, 40, 3, 3, SSD1306_WHITE);
    pantalla.fillRect(101, 43, 3, 3, SSD1306_WHITE);
    pantalla.fillRect(105, 40, 3, 3, SSD1306_WHITE);

    pantalla.drawLine(57, 48, 70, 48, SSD1306_WHITE);
    pantalla.drawLine(57, 49, 70, 49, SSD1306_WHITE);

    pantalla.display();
}

void dibujar_suplicantes(void)
{
    pantalla.clearDisplay();

    pantalla.fillRect(20, 23, 30, 17, SSD1306_WHITE);
    pantalla.fillRect(78, 23, 30, 17, SSD1306_WHITE);

    pantalla.fillRect(30, 23, 9, 7, SSD1306_BLACK);
    pantalla.fillRect(88, 23, 9, 7, SSD1306_BLACK);

    pantalla.drawLine(20, 17, 30, 12, SSD1306_WHITE);
    pantalla.drawLine(30, 12, 50, 17, SSD1306_WHITE);

    pantalla.drawLine(78, 17, 88, 12, SSD1306_WHITE);
    pantalla.drawLine(88, 12, 108, 17, SSD1306_WHITE);

    pantalla.drawLine(54, 47, 62, 44, SSD1306_WHITE);
    pantalla.drawLine(62, 44, 70, 47, SSD1306_WHITE);

    pantalla.display();
}


void dibujar_adormilados(void)
{
    pantalla.clearDisplay();

    pantalla.fillRect(24, 25, 26, 12, SSD1306_WHITE);
    pantalla.fillRect(78, 25, 26, 12, SSD1306_WHITE);

    pantalla.fillRect(34, 32, 7, 5, SSD1306_BLACK);
    pantalla.fillRect(88, 32, 7, 5, SSD1306_BLACK);

    pantalla.drawLine(24, 25, 50, 32, SSD1306_BLACK);
    pantalla.drawLine(78, 32, 104, 25, SSD1306_BLACK);

    pantalla.drawLine(24, 19, 50, 20, SSD1306_WHITE);
    pantalla.drawLine(78, 20, 104, 19, SSD1306_WHITE);

    pantalla.drawLine(58, 47, 70, 47, SSD1306_WHITE);

    pantalla.display();
}


void dibujar_mareados(void)
{
    pantalla.clearDisplay();

    pantalla.fillRect(23, 24, 28, 15, SSD1306_WHITE);
    pantalla.fillRect(77, 24, 28, 15, SSD1306_WHITE);

    pantalla.fillRect(27, 27, 7, 7, SSD1306_BLACK);
    pantalla.fillRect(94, 31, 7, 7, SSD1306_BLACK);

    pantalla.drawLine(22, 20, 18, 24, SSD1306_WHITE);
    pantalla.drawLine(18, 24, 22, 28, SSD1306_WHITE);

    pantalla.drawLine(106, 28, 110, 24, SSD1306_WHITE);
    pantalla.drawLine(110, 24, 106, 20, SSD1306_WHITE);

    pantalla.drawLine(54, 47, 60, 44, SSD1306_WHITE);
    pantalla.drawLine(60, 44, 66, 48, SSD1306_WHITE);
    pantalla.drawLine(66, 48, 72, 44, SSD1306_WHITE);

    pantalla.display();
}


void dibujar_en_shock(void)
{
    pantalla.clearDisplay();

    pantalla.fillRect(18, 19, 34, 22, SSD1306_WHITE);
    pantalla.fillRect(76, 19, 34, 22, SSD1306_WHITE);

    pantalla.fillRect(33, 28, 5, 5, SSD1306_BLACK);
    pantalla.fillRect(91, 28, 5, 5, SSD1306_BLACK);

    pantalla.drawLine(18, 12, 50, 8, SSD1306_WHITE);
    pantalla.drawLine(78, 8, 110, 12, SSD1306_WHITE);

    pantalla.drawRect(56, 44, 16, 7, SSD1306_WHITE);

    pantalla.display();
}


void dibujar_confiados(void)
{
    pantalla.clearDisplay();

    pantalla.fillRect(24, 27, 26, 9, SSD1306_WHITE);
    pantalla.fillRect(78, 27, 26, 9, SSD1306_WHITE);

    pantalla.fillRect(34, 30, 7, 6, SSD1306_BLACK);
    pantalla.fillRect(88, 30, 7, 6, SSD1306_BLACK);

    pantalla.drawLine(22, 19, 50, 19, SSD1306_WHITE);
    pantalla.drawLine(78, 19, 106, 19, SSD1306_WHITE);

    pantalla.drawLine(54, 45, 62, 48, SSD1306_WHITE);
    pantalla.drawLine(62, 48, 70, 48, SSD1306_WHITE);
    pantalla.drawLine(70, 48, 78, 45, SSD1306_WHITE);

    pantalla.display();
}


void dibujar_investigadores(void)
{
    pantalla.clearDisplay();

    pantalla.fillRect(22, 24, 28, 14, SSD1306_WHITE);
    pantalla.fillRect(33, 27, 8, 8, SSD1306_BLACK);

    pantalla.fillRect(80, 28, 24, 9, SSD1306_WHITE);
    pantalla.fillRect(91, 29, 7, 7, SSD1306_BLACK);

    pantalla.drawLine(22, 18, 50, 16, SSD1306_WHITE);
    pantalla.drawLine(80, 21, 104, 19, SSD1306_WHITE);

    pantalla.fillRect(54, 46, 22, 3, SSD1306_WHITE);

    pantalla.display();
}


void dibujar_nerviosos(void)
{
    pantalla.clearDisplay();

    pantalla.fillRect(23, 22, 28, 18, SSD1306_WHITE);
    pantalla.fillRect(77, 22, 28, 18, SSD1306_WHITE);

    pantalla.fillRect(35, 28, 5, 6, SSD1306_BLACK);
    pantalla.fillRect(89, 28, 5, 6, SSD1306_BLACK);

    pantalla.drawLine(22, 16, 50, 20, SSD1306_WHITE);
    pantalla.drawLine(78, 20, 106, 16, SSD1306_WHITE);

    pantalla.drawLine(56, 47, 72, 47, SSD1306_WHITE);
    pantalla.drawLine(58, 45, 70, 45, SSD1306_WHITE);

    pantalla.display();
}

void dibujar_fastidiados(void)
{
    pantalla.clearDisplay();

    pantalla.fillRect(24, 24, 26, 14, SSD1306_WHITE);
    pantalla.fillRect(78, 24, 26, 14, SSD1306_WHITE);

    pantalla.fillRect(34, 24, 8, 5, SSD1306_BLACK);
    pantalla.fillRect(88, 24, 8, 5, SSD1306_BLACK);

    pantalla.drawLine(22, 18, 50, 20, SSD1306_WHITE);
    pantalla.drawLine(78, 20, 106, 18, SSD1306_WHITE);

    pantalla.drawLine(55, 48, 63, 45, SSD1306_WHITE);
    pantalla.drawLine(63, 45, 73, 48, SSD1306_WHITE);

    pantalla.display();
}

void dibujar_aliviados(void)
{
    pantalla.clearDisplay();

    pantalla.drawLine(22, 30, 30, 34, SSD1306_WHITE);
    pantalla.drawLine(30, 34, 40, 34, SSD1306_WHITE);
    pantalla.drawLine(40, 34, 50, 30, SSD1306_WHITE);

    pantalla.drawLine(78, 30, 88, 34, SSD1306_WHITE);
    pantalla.drawLine(88, 34, 98, 34, SSD1306_WHITE);
    pantalla.drawLine(98, 34, 106, 30, SSD1306_WHITE);

    pantalla.drawLine(24, 21, 50, 21, SSD1306_WHITE);
    pantalla.drawLine(78, 21, 104, 21, SSD1306_WHITE);

    pantalla.drawLine(58, 46, 63, 48, SSD1306_WHITE);
    pantalla.drawLine(63, 48, 68, 48, SSD1306_WHITE);
    pantalla.drawLine(68, 48, 73, 46, SSD1306_WHITE);

    pantalla.display();
}

void dibujar_traviesos(void)
{
    pantalla.clearDisplay();

    pantalla.fillRect(24, 24, 26, 14, SSD1306_WHITE);
    pantalla.fillRect(78, 24, 26, 14, SSD1306_WHITE);

    pantalla.drawLine(24, 24, 50, 31, SSD1306_BLACK);
    pantalla.drawLine(78, 31, 104, 24, SSD1306_BLACK);

    pantalla.fillRect(40, 29, 7, 7, SSD1306_BLACK);
    pantalla.fillRect(81, 29, 7, 7, SSD1306_BLACK);

    pantalla.drawLine(22, 18, 50, 21, SSD1306_WHITE);
    pantalla.drawLine(78, 21, 106, 18, SSD1306_WHITE);

    pantalla.drawLine(52, 45, 61, 48, SSD1306_WHITE);
    pantalla.drawLine(61, 48, 72, 47, SSD1306_WHITE);
    pantalla.drawLine(72, 47, 81, 42, SSD1306_WHITE);

    pantalla.display();
}

void dibujar_congelados(void)
{
    pantalla.clearDisplay();

    pantalla.fillRect(20, 21, 30, 20, SSD1306_WHITE);
    pantalla.fillRect(78, 21, 30, 20, SSD1306_WHITE);

    pantalla.fillRect(34, 28, 5, 6, SSD1306_BLACK);
    pantalla.fillRect(90, 28, 5, 6, SSD1306_BLACK);

    pantalla.drawLine(20, 14, 50, 12, SSD1306_WHITE);
    pantalla.drawLine(78, 12, 108, 14, SSD1306_WHITE);

    pantalla.drawLine(14, 25, 10, 22, SSD1306_WHITE);
    pantalla.drawLine(14, 34, 9, 36, SSD1306_WHITE);
    pantalla.drawLine(108, 25, 112, 22, SSD1306_WHITE);
    pantalla.drawLine(108, 34, 113, 36, SSD1306_WHITE);

    pantalla.drawLine(54, 47, 59, 45, SSD1306_WHITE);
    pantalla.drawLine(59, 45, 64, 48, SSD1306_WHITE);
    pantalla.drawLine(64, 48, 69, 45, SSD1306_WHITE);
    pantalla.drawLine(69, 45, 75, 47, SSD1306_WHITE);

    pantalla.display();
}

void dibujar_timidos(void)
{
    pantalla.clearDisplay();

    pantalla.fillRect(24, 25, 26, 13, SSD1306_WHITE);
    pantalla.fillRect(78, 25, 26, 13, SSD1306_WHITE);

    pantalla.fillRect(42, 28, 7, 7, SSD1306_BLACK);
    pantalla.fillRect(79, 28, 7, 7, SSD1306_BLACK);

    pantalla.drawLine(24, 20, 50, 23, SSD1306_WHITE);
    pantalla.drawLine(78, 23, 104, 20, SSD1306_WHITE);

    pantalla.drawLine(59, 48, 69, 48, SSD1306_WHITE);

    pantalla.display();
}

void dibujar_fascinados(void)
{
    pantalla.clearDisplay();

    pantalla.fillRect(20, 22, 30, 18, SSD1306_WHITE);
    pantalla.fillRect(78, 22, 30, 18, SSD1306_WHITE);

    pantalla.fillRect(29, 25, 12, 12, SSD1306_BLACK);
    pantalla.fillRect(87, 25, 12, 12, SSD1306_BLACK);

    pantalla.fillRect(31, 25, 3, 3, SSD1306_WHITE);
    pantalla.fillRect(89, 25, 3, 3, SSD1306_WHITE);

    pantalla.drawLine(20, 15, 50, 11, SSD1306_WHITE);
    pantalla.drawLine(78, 11, 108, 15, SSD1306_WHITE);

    pantalla.drawRect(57, 44, 15, 7, SSD1306_WHITE);

    pantalla.display();
}

void dibujar_exhaustos(void)
{
    pantalla.clearDisplay();

    pantalla.fillRect(24, 24, 26, 13, SSD1306_WHITE);
    pantalla.fillRect(78, 24, 26, 13, SSD1306_WHITE);

    pantalla.drawLine(24, 24, 50, 31, SSD1306_BLACK);
    pantalla.drawLine(78, 31, 104, 24, SSD1306_BLACK);

    pantalla.fillRect(35, 31, 6, 5, SSD1306_BLACK);
    pantalla.fillRect(89, 31, 6, 5, SSD1306_BLACK);

    pantalla.drawLine(24, 19, 50, 21, SSD1306_WHITE);
    pantalla.drawLine(78, 21, 104, 19, SSD1306_WHITE);

    pantalla.drawRect(56, 44, 16, 8, SSD1306_WHITE);

    pantalla.display();
}

void dibujar_pensativos(void)
{
    pantalla.clearDisplay();

    pantalla.fillRect(24, 24, 26, 14, SSD1306_WHITE);
    pantalla.fillRect(78, 24, 26, 14, SSD1306_WHITE);

    pantalla.fillRect(34, 24, 7, 7, SSD1306_BLACK);

    pantalla.fillRect(94, 28, 7, 7, SSD1306_BLACK);

    pantalla.drawLine(22, 18, 50, 15, SSD1306_WHITE);
    pantalla.drawLine(78, 18, 104, 21, SSD1306_WHITE);

    pantalla.drawLine(57, 47, 64, 45, SSD1306_WHITE);
    pantalla.drawLine(64, 45, 72, 47, SSD1306_WHITE);

    pantalla.display();
}

void dibujar_orgullosos(void)
{
    pantalla.clearDisplay();

    pantalla.fillRect(24, 27, 26, 9, SSD1306_WHITE);
    pantalla.fillRect(78, 27, 26, 9, SSD1306_WHITE);

    pantalla.fillRect(34, 30, 7, 6, SSD1306_BLACK);
    pantalla.fillRect(88, 30, 7, 6, SSD1306_BLACK);

    pantalla.drawLine(22, 17, 50, 13, SSD1306_WHITE);
    pantalla.drawLine(78, 13, 106, 17, SSD1306_WHITE);

    pantalla.fillRect(54, 46, 22, 4, SSD1306_WHITE);

    pantalla.display();
}

void dibujar_exasperados(void)
{
    pantalla.clearDisplay();

    pantalla.fillRect(24, 24, 26, 14, SSD1306_WHITE);
    pantalla.fillRect(78, 24, 26, 14, SSD1306_WHITE);

    pantalla.fillRect(34, 24, 8, 5, SSD1306_BLACK);
    pantalla.fillRect(88, 24, 8, 5, SSD1306_BLACK);

    pantalla.drawLine(22, 18, 50, 20, SSD1306_WHITE);
    pantalla.drawLine(78, 20, 106, 18, SSD1306_WHITE);

    pantalla.drawLine(55, 48, 63, 45, SSD1306_WHITE);
    pantalla.drawLine(63, 45, 73, 48, SSD1306_WHITE);

    pantalla.display();
}

void dibujar_despreciativos(void)
{
    pantalla.clearDisplay();

    pantalla.fillRect(24, 28, 26, 7, SSD1306_WHITE);
    pantalla.fillRect(78, 28, 26, 7, SSD1306_WHITE);

    pantalla.fillRect(43, 28, 7, 7, SSD1306_BLACK);
    pantalla.fillRect(96, 28, 7, 7, SSD1306_BLACK);

    pantalla.drawLine(22, 22, 50, 19, SSD1306_WHITE);
    pantalla.drawLine(78, 19, 106, 22, SSD1306_WHITE);

    pantalla.drawLine(54, 48, 76, 46, SSD1306_WHITE);

    pantalla.display();
}

void dibujar_incomodos(void)
{
    pantalla.clearDisplay();

    pantalla.fillRect(22, 23, 28, 16, SSD1306_WHITE);
    pantalla.fillRect(78, 23, 28, 16, SSD1306_WHITE);

    pantalla.fillRect(35, 28, 5, 6, SSD1306_BLACK);
    pantalla.fillRect(89, 28, 5, 6, SSD1306_BLACK);

    pantalla.drawLine(22, 17, 50, 21, SSD1306_WHITE);
    pantalla.drawLine(78, 21, 106, 17, SSD1306_WHITE);

    pantalla.drawLine(55, 47, 75, 47, SSD1306_WHITE);
    pantalla.drawLine(58, 45, 72, 45, SSD1306_WHITE);

    pantalla.display();
}

void dibujar_coquetos(void)
{
    pantalla.clearDisplay();

    pantalla.drawLine(22, 31, 32, 35, SSD1306_WHITE);
    pantalla.drawLine(32, 35, 42, 35, SSD1306_WHITE);
    pantalla.drawLine(42, 35, 50, 31, SSD1306_WHITE);

    pantalla.fillRect(78, 24, 26, 14, SSD1306_WHITE);
    pantalla.fillRect(96, 28, 7, 7, SSD1306_BLACK);

    pantalla.drawLine(24, 20, 48, 18, SSD1306_WHITE);
    pantalla.drawLine(80, 19, 106, 22, SSD1306_WHITE);

    pantalla.drawLine(54, 46, 62, 48, SSD1306_WHITE);
    pantalla.drawLine(62, 48, 73, 46, SSD1306_WHITE);
    pantalla.drawLine(73, 46, 80, 43, SSD1306_WHITE);

    pantalla.display();
}

void dibujar_sospechosos(void)
{
    pantalla.clearDisplay();

    pantalla.fillRect(24, 25, 26, 13, SSD1306_WHITE);
    pantalla.fillRect(78, 25, 26, 13, SSD1306_WHITE);

    pantalla.drawLine(20, 24, 52, 31, SSD1306_BLACK);
    pantalla.drawLine(76, 31, 108, 24, SSD1306_BLACK);
    pantalla.drawLine(22, 22, 50, 28, SSD1306_WHITE);
    pantalla.drawLine(78, 28, 106, 22, SSD1306_WHITE);

    pantalla.fillRect(40, 30, 7, 6, SSD1306_BLACK);
    pantalla.fillRect(81, 30, 7, 6, SSD1306_BLACK);

    pantalla.display();
}

void dibujar_intelectuales(void)
{
    pantalla.clearDisplay();

    pantalla.fillRect(24, 25, 26, 13, SSD1306_WHITE);
    pantalla.fillRect(78, 25, 26, 13, SSD1306_WHITE);

    pantalla.fillRect(35, 29, 5, 6, SSD1306_BLACK);
    pantalla.fillRect(89, 29, 5, 6, SSD1306_BLACK);

    pantalla.drawLine(22, 18, 50, 21, SSD1306_WHITE);
    pantalla.drawLine(78, 21, 106, 18, SSD1306_WHITE);

    pantalla.fillRect(55, 47, 20, 3, SSD1306_WHITE);

    pantalla.display();
}

void dibujar_derretidos(void)
{
    pantalla.clearDisplay();

    pantalla.fillRect(24, 23, 26, 13, SSD1306_WHITE);
    pantalla.fillRect(78, 23, 26, 13, SSD1306_WHITE);

    pantalla.fillRect(34, 28, 7, 7, SSD1306_BLACK);
    pantalla.fillRect(88, 28, 7, 7, SSD1306_BLACK);

    pantalla.fillRect(29, 34, 5, 7, SSD1306_WHITE);
    pantalla.fillRect(39, 34, 4, 10, SSD1306_WHITE);
    pantalla.fillRect(84, 34, 5, 10, SSD1306_WHITE);
    pantalla.fillRect(94, 34, 5, 7, SSD1306_WHITE);

    pantalla.display();
}

void dibujar_temblorosos(void)
{
    pantalla.clearDisplay();

    pantalla.fillRect(24, 25, 26, 13, SSD1306_WHITE);
    pantalla.fillRect(78, 25, 26, 13, SSD1306_WHITE);

    pantalla.fillRect(37, 28, 7, 7, SSD1306_BLACK);
    pantalla.fillRect(85, 29, 7, 7, SSD1306_BLACK);

    pantalla.drawLine(18, 23, 14, 20, SSD1306_WHITE);
    pantalla.drawLine(17, 32, 12, 34, SSD1306_WHITE);
    pantalla.drawLine(108, 23, 112, 20, SSD1306_WHITE);
    pantalla.drawLine(109, 32, 114, 34, SSD1306_WHITE);

    pantalla.drawLine(52, 21, 55, 17, SSD1306_WHITE);
    pantalla.drawLine(75, 21, 72, 17, SSD1306_WHITE);

    pantalla.display();
}

void dibujar_aturdidos(void)
{
    pantalla.clearDisplay();

    pantalla.fillRect(24, 27, 26, 9, SSD1306_WHITE);
    pantalla.fillRect(78, 27, 26, 9, SSD1306_WHITE);

    pantalla.fillRect(28, 29, 5, 5, SSD1306_BLACK);
    pantalla.fillRect(98, 30, 5, 5, SSD1306_BLACK);

    pantalla.drawLine(24, 27, 50, 32, SSD1306_BLACK);
    pantalla.drawLine(78, 32, 104, 27, SSD1306_BLACK);

    pantalla.drawLine(55, 47, 75, 47, SSD1306_WHITE);

    pantalla.display();
}

void dibujar_desorientados(void)
{
    pantalla.clearDisplay();

    pantalla.fillRect(23, 22, 28, 15, SSD1306_WHITE);
    pantalla.fillRect(78, 29, 27, 14, SSD1306_WHITE);

    pantalla.fillRect(42, 25, 7, 7, SSD1306_BLACK);
    pantalla.fillRect(80, 34, 7, 7, SSD1306_BLACK);

    pantalla.drawLine(22, 17, 50, 19, SSD1306_WHITE);
    pantalla.drawLine(78, 22, 106, 20, SSD1306_WHITE);

    pantalla.display();
}

void dibujar_boquiabiertos(void)
{
    pantalla.clearDisplay();

    pantalla.fillRect(20, 21, 30, 19, SSD1306_WHITE);
    pantalla.fillRect(78, 21, 30, 19, SSD1306_WHITE);

    pantalla.fillRect(32, 27, 8, 8, SSD1306_BLACK);
    pantalla.fillRect(90, 27, 8, 8, SSD1306_BLACK);

    pantalla.drawLine(20, 14, 50, 11, SSD1306_WHITE);
    pantalla.drawLine(78, 11, 108, 14, SSD1306_WHITE);

    pantalla.drawCircle(64, 48, 6, SSD1306_WHITE);

    pantalla.display();
}

void dibujar_sorprendidos_ocultos(void)
{
    pantalla.clearDisplay();

    pantalla.fillRect(22, 22, 28, 17, SSD1306_WHITE);
    pantalla.fillRect(78, 22, 28, 17, SSD1306_WHITE);

    pantalla.fillRect(34, 28, 7, 7, SSD1306_BLACK);
    pantalla.fillRect(88, 28, 7, 7, SSD1306_BLACK);

    pantalla.drawLine(22, 22, 50, 26, SSD1306_BLACK);
    pantalla.drawLine(78, 26, 106, 22, SSD1306_BLACK);

    pantalla.drawLine(22, 16, 50, 14, SSD1306_WHITE);
    pantalla.drawLine(78, 14, 106, 16, SSD1306_WHITE);

    pantalla.drawLine(58, 47, 70, 47, SSD1306_WHITE);

    pantalla.display();
}

void dibujar_agotados(void)
{
    pantalla.clearDisplay();

    pantalla.fillRect(24, 24, 26, 13, SSD1306_WHITE);
    pantalla.fillRect(78, 24, 26, 13, SSD1306_WHITE);

    pantalla.drawLine(24, 24, 50, 31, SSD1306_BLACK);
    pantalla.drawLine(78, 31, 104, 24, SSD1306_BLACK);

    pantalla.fillRect(35, 31, 6, 5, SSD1306_BLACK);
    pantalla.fillRect(89, 31, 6, 5, SSD1306_BLACK);

    pantalla.drawRect(57, 45, 14, 6, SSD1306_WHITE);

    pantalla.display();
}

void dibujar_bostezando(void)
{
    pantalla.clearDisplay();

    pantalla.fillRect(24, 26, 26, 11, SSD1306_WHITE);
    pantalla.fillRect(78, 26, 26, 11, SSD1306_WHITE);

    pantalla.drawLine(24, 26, 50, 32, SSD1306_BLACK);
    pantalla.drawLine(78, 32, 104, 26, SSD1306_BLACK);

    pantalla.fillRect(35, 32, 6, 4, SSD1306_BLACK);
    pantalla.fillRect(89, 32, 6, 4, SSD1306_BLACK);

    pantalla.drawCircle(64, 48, 9, SSD1306_WHITE);
    pantalla.fillCircle(64, 48, 5, SSD1306_BLACK);

    pantalla.display();
}

void dibujar_firmes(void)
{
    pantalla.clearDisplay();

    pantalla.fillRect(24, 25, 26, 13, SSD1306_WHITE);
    pantalla.fillRect(78, 25, 26, 13, SSD1306_WHITE);

    pantalla.fillRect(34, 28, 8, 7, SSD1306_BLACK);
    pantalla.fillRect(88, 28, 8, 7, SSD1306_BLACK);

    pantalla.fillRect(22, 17, 29, 3, SSD1306_WHITE);
    pantalla.fillRect(77, 17, 29, 3, SSD1306_WHITE);

    pantalla.fillRect(55, 47, 19, 3, SSD1306_WHITE);

    pantalla.display();
}

void dibujar_serios_absolutos(void)
{
    pantalla.clearDisplay();

    pantalla.fillRect(24, 28, 26, 7, SSD1306_WHITE);
    pantalla.fillRect(78, 28, 26, 7, SSD1306_WHITE);

    pantalla.fillRect(24, 20, 26, 3, SSD1306_WHITE);
    pantalla.fillRect(78, 20, 26, 3, SSD1306_WHITE);

    pantalla.fillRect(53, 47, 23, 3, SSD1306_WHITE);

    pantalla.display();
}

void dibujar_silenciosos(void)
{
    pantalla.clearDisplay();

    pantalla.fillRect(24, 25, 26, 13, SSD1306_WHITE);
    pantalla.fillRect(78, 25, 26, 13, SSD1306_WHITE);

    pantalla.fillRect(35, 29, 7, 6, SSD1306_BLACK);
    pantalla.fillRect(89, 29, 7, 6, SSD1306_BLACK);

    pantalla.drawLine(24, 19, 50, 19, SSD1306_WHITE);
    pantalla.drawLine(78, 19, 104, 19, SSD1306_WHITE);

    pantalla.drawLine(59, 48, 69, 48, SSD1306_WHITE);

    pantalla.display();
}

void dibujar_indiferentes(void)
{
    pantalla.clearDisplay();

    pantalla.fillRect(24, 27, 26, 9, SSD1306_WHITE);
    pantalla.fillRect(78, 27, 26, 9, SSD1306_WHITE);

    pantalla.fillRect(34, 29, 8, 7, SSD1306_BLACK);
    pantalla.fillRect(88, 29, 8, 7, SSD1306_BLACK);

    pantalla.drawLine(24, 20, 50, 20, SSD1306_WHITE);
    pantalla.drawLine(78, 20, 104, 20, SSD1306_WHITE);

    pantalla.fillRect(56, 47, 17, 3, SSD1306_WHITE);

    pantalla.display();
}

void dibujar_decepcionados(void)
{
    pantalla.clearDisplay();

    pantalla.fillRect(24, 25, 26, 13, SSD1306_WHITE);
    pantalla.fillRect(78, 25, 26, 13, SSD1306_WHITE);

    pantalla.fillRect(34, 32, 7, 6, SSD1306_BLACK);
    pantalla.fillRect(88, 32, 7, 6, SSD1306_BLACK);

    pantalla.drawLine(22, 17, 50, 21, SSD1306_WHITE);
    pantalla.drawLine(78, 21, 106, 17, SSD1306_WHITE);

    pantalla.drawLine(54, 47, 64, 49, SSD1306_WHITE);
    pantalla.drawLine(64, 49, 76, 46, SSD1306_WHITE);

    pantalla.display();
}

void dibujar_desanimados(void)
{
    pantalla.clearDisplay();

    pantalla.fillRect(24, 25, 26, 13, SSD1306_WHITE);
    pantalla.fillRect(78, 25, 26, 13, SSD1306_WHITE);

    pantalla.fillRect(35, 32, 7, 6, SSD1306_BLACK);
    pantalla.fillRect(89, 32, 7, 6, SSD1306_BLACK);

    pantalla.drawLine(22, 18, 50, 23, SSD1306_WHITE);
    pantalla.drawLine(78, 23, 106, 18, SSD1306_WHITE);

    pantalla.drawLine(55, 49, 63, 46, SSD1306_WHITE);
    pantalla.drawLine(63, 46, 72, 49, SSD1306_WHITE);

    pantalla.display();
}

void dibujar_preocupados(void)
{
    pantalla.clearDisplay();

    pantalla.fillRect(23, 23, 28, 16, SSD1306_WHITE);
    pantalla.fillRect(77, 23, 28, 16, SSD1306_WHITE);

    pantalla.fillRect(35, 29, 6, 7, SSD1306_BLACK);
    pantalla.fillRect(89, 29, 6, 7, SSD1306_BLACK);

    pantalla.drawLine(20, 12, 34, 18, SSD1306_WHITE);
    pantalla.drawLine(34, 18, 50, 13, SSD1306_WHITE);

    pantalla.drawLine(78, 13, 94, 18, SSD1306_WHITE);
    pantalla.drawLine(94, 18, 108, 12, SSD1306_WHITE);

    pantalla.display();
}

void dibujar_angustiados(void)
{
    pantalla.clearDisplay();

    pantalla.fillRect(20, 20, 31, 20, SSD1306_WHITE);
    pantalla.fillRect(77, 20, 31, 20, SSD1306_WHITE);

    pantalla.fillRect(34, 28, 5, 6, SSD1306_BLACK);
    pantalla.fillRect(91, 28, 5, 6, SSD1306_BLACK);

    pantalla.drawLine(20, 14, 50, 20, SSD1306_WHITE);
    pantalla.drawLine(78, 20, 108, 14, SSD1306_WHITE);

    pantalla.drawLine(54, 47, 60, 44, SSD1306_WHITE);
    pantalla.drawLine(60, 44, 68, 47, SSD1306_WHITE);
    pantalla.drawLine(68, 47, 76, 44, SSD1306_WHITE);

    pantalla.display();
}

void dibujar_aterrorizados(void)
{
    pantalla.clearDisplay();

    pantalla.fillRect(17, 18, 35, 23, SSD1306_WHITE);
    pantalla.fillRect(75, 18, 35, 23, SSD1306_WHITE);

    pantalla.fillRect(33, 27, 5, 5, SSD1306_BLACK);
    pantalla.fillRect(91, 27, 5, 5, SSD1306_BLACK);

    pantalla.drawLine(18, 10, 50, 15, SSD1306_WHITE);
    pantalla.drawLine(78, 15, 110, 10, SSD1306_WHITE);

    pantalla.drawRect(55, 43, 18, 9, SSD1306_WHITE);

    pantalla.display();
}

void dibujar_completamente_mareados(void)
{
    pantalla.clearDisplay();

    pantalla.fillRect(20, 21, 31, 20, SSD1306_WHITE);
    pantalla.fillRect(77, 21, 31, 20, SSD1306_WHITE);

    pantalla.drawCircle(35, 31, 7, SSD1306_BLACK);
    pantalla.drawCircle(93, 31, 7, SSD1306_BLACK);

    pantalla.drawLine(35, 24, 35, 28, SSD1306_WHITE);
    pantalla.drawLine(35, 34, 40, 31, SSD1306_WHITE);

    pantalla.drawLine(93, 24, 93, 28, SSD1306_WHITE);
    pantalla.drawLine(93, 34, 98, 31, SSD1306_WHITE);

    pantalla.display();
}

void dibujar_locos(void)
{
    pantalla.clearDisplay();

    pantalla.fillRect(22, 21, 28, 19, SSD1306_WHITE);
    pantalla.fillRect(80, 27, 24, 13, SSD1306_WHITE);

    pantalla.fillRect(42, 25, 7, 7, SSD1306_BLACK);
    pantalla.fillRect(81, 30, 7, 7, SSD1306_BLACK);

    pantalla.drawLine(20, 15, 50, 20, SSD1306_WHITE);
    pantalla.drawLine(80, 19, 106, 14, SSD1306_WHITE);

    pantalla.drawLine(51, 45, 58, 49, SSD1306_WHITE);
    pantalla.drawLine(58, 49, 65, 44, SSD1306_WHITE);
    pantalla.drawLine(65, 44, 72, 49, SSD1306_WHITE);
    pantalla.drawLine(72, 49, 81, 44, SSD1306_WHITE);

    pantalla.display();
}

void dibujar_mirando_fijamente(void)
{
    pantalla.clearDisplay();

    pantalla.fillRect(19, 20, 32, 21, SSD1306_WHITE);
    pantalla.fillRect(77, 20, 32, 21, SSD1306_WHITE);

    pantalla.fillRect(31, 27, 9, 9, SSD1306_BLACK);
    pantalla.fillRect(89, 27, 9, 9, SSD1306_BLACK);

    pantalla.drawLine(20, 14, 50, 14, SSD1306_WHITE);
    pantalla.drawLine(78, 14, 108, 14, SSD1306_WHITE);

    pantalla.display();
}

void dibujar_vacios(void)
{
    pantalla.clearDisplay();

    pantalla.fillRect(22, 22, 29, 18, SSD1306_BLACK);
    pantalla.fillRect(77, 22, 29, 18, SSD1306_BLACK);

    pantalla.drawRect(22, 22, 29, 18, SSD1306_WHITE);
    pantalla.drawRect(77, 22, 29, 18, SSD1306_WHITE);

    pantalla.fillRect(55, 47, 20, 3, SSD1306_WHITE);

    pantalla.display();
}

void dibujar_alienigenas(void)
{
    pantalla.clearDisplay();

    pantalla.fillRoundRect(20, 17, 31, 28, 7, SSD1306_WHITE);
    pantalla.fillRoundRect(77, 17, 31, 28, 7, SSD1306_WHITE);

    pantalla.fillRect(34, 27, 4, 8, SSD1306_BLACK);
    pantalla.fillRect(90, 27, 4, 8, SSD1306_BLACK);

    pantalla.display();
}

void dibujar_roboticos(void)
{
    pantalla.clearDisplay();

    pantalla.fillRect(22, 24, 29, 15, SSD1306_WHITE);
    pantalla.fillRect(77, 24, 29, 15, SSD1306_WHITE);

    pantalla.fillRect(34, 28, 8, 7, SSD1306_BLACK);
    pantalla.fillRect(89, 28, 8, 7, SSD1306_BLACK);

    pantalla.drawLine(26, 20, 47, 20, SSD1306_WHITE);
    pantalla.drawLine(81, 20, 102, 20, SSD1306_WHITE);

    pantalla.fillRect(56, 47, 17, 3, SSD1306_WHITE);

    pantalla.display();
}

void dibujar_fantasmales(void)
{
    pantalla.clearDisplay();

    pantalla.fillRect(23, 22, 28, 18, SSD1306_WHITE);
    pantalla.fillRect(77, 22, 28, 18, SSD1306_WHITE);

    pantalla.fillRect(35, 28, 5, 6, SSD1306_BLACK);
    pantalla.fillRect(89, 28, 5, 6, SSD1306_BLACK);

    pantalla.drawLine(58, 48, 70, 48, SSD1306_WHITE);

    pantalla.display();
}

void dibujar_inocentes(void)
{
    pantalla.clearDisplay();

    pantalla.fillRect(22, 22, 29, 18, SSD1306_WHITE);
    pantalla.fillRect(77, 22, 29, 18, SSD1306_WHITE);

    pantalla.fillRect(33, 28, 9, 9, SSD1306_BLACK);
    pantalla.fillRect(88, 28, 9, 9, SSD1306_BLACK);

    pantalla.drawLine(22, 16, 35, 13, SSD1306_WHITE);
    pantalla.drawLine(35, 13, 50, 16, SSD1306_WHITE);

    pantalla.drawLine(78, 16, 93, 13, SSD1306_WHITE);
    pantalla.drawLine(93, 13, 106, 16, SSD1306_WHITE);

    pantalla.drawLine(58, 46, 63, 48, SSD1306_WHITE);
    pantalla.drawLine(63, 48, 69, 48, SSD1306_WHITE);
    pantalla.drawLine(69, 48, 74, 46, SSD1306_WHITE);

    pantalla.display();
}

void dibujar_demoniacos(void)
{
    pantalla.clearDisplay();

    pantalla.fillRect(22, 24, 28, 15, SSD1306_WHITE);
    pantalla.fillRect(78, 24, 28, 15, SSD1306_WHITE);

    pantalla.drawLine(22, 24, 50, 32, SSD1306_BLACK);
    pantalla.drawLine(78, 32, 106, 24, SSD1306_BLACK);

    pantalla.fillRect(35, 26, 5, 12, SSD1306_BLACK);
    pantalla.fillRect(89, 26, 5, 12, SSD1306_BLACK);

    pantalla.drawLine(20, 17, 50, 21, SSD1306_WHITE);
    pantalla.drawLine(78, 21, 108, 17, SSD1306_WHITE);

    pantalla.display();
}

void dibujar_al_borde_de_llorar(void)
{
    pantalla.clearDisplay();

    pantalla.fillRect(21, 21, 30, 19, SSD1306_WHITE);
    pantalla.fillRect(77, 21, 30, 19, SSD1306_WHITE);

    pantalla.fillRect(32, 27, 9, 9, SSD1306_BLACK);
    pantalla.fillRect(88, 27, 9, 9, SSD1306_BLACK);

    pantalla.fillRect(24, 39, 4, 6, SSD1306_WHITE);
    pantalla.fillRect(101, 39, 4, 6, SSD1306_WHITE);

    pantalla.drawLine(21, 15, 50, 20, SSD1306_WHITE);
    pantalla.drawLine(78, 20, 107, 15, SSD1306_WHITE);

    pantalla.drawLine(57, 48, 63, 46, SSD1306_WHITE);
    pantalla.drawLine(63, 46, 70, 48, SSD1306_WHITE);

    pantalla.display();
}

void dibujar_llorando(void)
{
    pantalla.clearDisplay();

    pantalla.fillRect(22, 22, 29, 18, SSD1306_WHITE);
    pantalla.fillRect(77, 22, 29, 18, SSD1306_WHITE);

    pantalla.fillRect(33, 28, 8, 8, SSD1306_BLACK);
    pantalla.fillRect(88, 28, 8, 8, SSD1306_BLACK);

    pantalla.fillRect(27, 38, 7, 10, SSD1306_WHITE);
    pantalla.fillRect(95, 38, 7, 10, SSD1306_WHITE);

    pantalla.fillRect(29, 48, 3, 5, SSD1306_WHITE);
    pantalla.fillRect(97, 48, 3, 5, SSD1306_WHITE);

    pantalla.drawRect(57, 44, 15, 8, SSD1306_WHITE);

    pantalla.display();
}

void dibujar_llorando_de_risa(void)
{
    pantalla.clearDisplay();

    pantalla.drawLine(22, 29, 31, 35, SSD1306_WHITE);
    pantalla.drawLine(31, 35, 40, 35, SSD1306_WHITE);
    pantalla.drawLine(40, 35, 50, 29, SSD1306_WHITE);

    pantalla.drawLine(78, 29, 88, 35, SSD1306_WHITE);
    pantalla.drawLine(88, 35, 98, 35, SSD1306_WHITE);
    pantalla.drawLine(98, 35, 106, 29, SSD1306_WHITE);

    pantalla.fillRect(28, 35, 5, 8, SSD1306_WHITE);
    pantalla.fillRect(96, 35, 5, 8, SSD1306_WHITE);

    pantalla.fillRoundRect(48, 43, 32, 10, 3, SSD1306_WHITE);
    pantalla.fillRect(54, 43, 20, 4, SSD1306_BLACK);

    pantalla.display();
}

void dibujar_ojos_buscando(void)
{
    pantalla.clearDisplay();

    pantalla.fillRect(24, 25, 26, 14, SSD1306_WHITE);

    pantalla.fillRect(24, 28, 8, 8, SSD1306_BLACK);

    pantalla.fillRect(78, 25, 26, 14, SSD1306_WHITE);

    pantalla.fillRect(96, 28, 8, 8, SSD1306_BLACK);

    pantalla.drawLine(22, 18, 50, 16, SSD1306_WHITE);
    pantalla.drawLine(78, 16, 106, 18, SSD1306_WHITE);

    pantalla.drawLine(17, 29, 11, 29, SSD1306_WHITE);
    pantalla.drawLine(111, 29, 117, 29, SSD1306_WHITE);

    pantalla.fillRect(56, 47, 16, 3, SSD1306_WHITE);

    pantalla.display();
}


void dibujar_buscando_wifi(void)
{
    pantalla.clearDisplay();

    pantalla.fillCircle(64, 48, 3, SSD1306_WHITE);

    pantalla.drawLine(55, 43, 59, 39, SSD1306_WHITE);
    pantalla.drawLine(59, 39, 64, 38, SSD1306_WHITE);
    pantalla.drawLine(64, 38, 69, 39, SSD1306_WHITE);
    pantalla.drawLine(69, 39, 73, 43, SSD1306_WHITE);

    pantalla.drawLine(48, 37, 53, 32, SSD1306_WHITE);
    pantalla.drawLine(53, 32, 59, 29, SSD1306_WHITE);
    pantalla.drawLine(59, 29, 64, 28, SSD1306_WHITE);
    pantalla.drawLine(64, 28, 69, 29, SSD1306_WHITE);
    pantalla.drawLine(69, 29, 75, 32, SSD1306_WHITE);
    pantalla.drawLine(75, 32, 80, 37, SSD1306_WHITE);

    pantalla.drawLine(40, 29, 46, 23, SSD1306_WHITE);
    pantalla.drawLine(46, 23, 54, 19, SSD1306_WHITE);
    pantalla.drawLine(54, 19, 64, 17, SSD1306_WHITE);
    pantalla.drawLine(64, 17, 74, 19, SSD1306_WHITE);
    pantalla.drawLine(74, 19, 82, 23, SSD1306_WHITE);
    pantalla.drawLine(82, 23, 88, 29, SSD1306_WHITE);

    pantalla.display();
}


void dibujar_error_wifi(void)
{
    pantalla.clearDisplay();

    pantalla.drawLine(42, 29, 48, 23, SSD1306_WHITE);
    pantalla.drawLine(48, 23, 56, 19, SSD1306_WHITE);
    pantalla.drawLine(56, 19, 64, 18, SSD1306_WHITE);

    pantalla.drawLine(64, 18, 72, 19, SSD1306_WHITE);
    pantalla.drawLine(72, 19, 78, 23, SSD1306_WHITE);

    pantalla.drawLine(51, 36, 56, 32, SSD1306_WHITE);
    pantalla.drawLine(56, 32, 64, 30, SSD1306_WHITE);
    pantalla.drawLine(64, 30, 72, 32, SSD1306_WHITE);
    pantalla.drawLine(72, 32, 77, 36, SSD1306_WHITE);

    pantalla.fillCircle(64, 45, 3, SSD1306_WHITE);

    pantalla.drawLine(87, 38, 103, 52, SSD1306_WHITE);
    pantalla.drawLine(103, 38, 87, 52, SSD1306_WHITE);

    pantalla.display();
}


void dibujar_conexion_exitosa(void)
{
    pantalla.clearDisplay();

    pantalla.drawLine(39, 29, 45, 23, SSD1306_WHITE);
    pantalla.drawLine(45, 23, 53, 19, SSD1306_WHITE);
    pantalla.drawLine(53, 19, 64, 17, SSD1306_WHITE);
    pantalla.drawLine(64, 17, 75, 19, SSD1306_WHITE);
    pantalla.drawLine(75, 19, 83, 23, SSD1306_WHITE);
    pantalla.drawLine(83, 23, 89, 29, SSD1306_WHITE);

    pantalla.drawLine(48, 36, 54, 31, SSD1306_WHITE);
    pantalla.drawLine(54, 31, 64, 28, SSD1306_WHITE);
    pantalla.drawLine(64, 28, 74, 31, SSD1306_WHITE);
    pantalla.drawLine(74, 31, 80, 36, SSD1306_WHITE);

    pantalla.fillCircle(64, 44, 3, SSD1306_WHITE);

    pantalla.drawLine(91, 43, 97, 49, SSD1306_WHITE);
    pantalla.drawLine(97, 49, 108, 36, SSD1306_WHITE);

    pantalla.display();
}

void actualizar_emocion(enum e_Emociones nuevo_estado)
{
    emocion_actual = nuevo_estado;
    printf("Emocion actualizada a la numero: %d\n", (int)emocion_actual);
}

enum e_Emociones obtener_emocion(void)
{
    return emocion_actual;
}