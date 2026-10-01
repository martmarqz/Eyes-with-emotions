#include "hardware.h"
#include <stdio.h> 

Adafruit_SSD1306 pantalla(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void inicializar_hardware(void) 
{
    printf("Iniciando configuración del ESP32-S3...\n");
    Wire.begin(DISPLAY_SDA, DISPLAY_SCL); // Inicializa la comunicación I2C para la pantalla OLED
    pantalla.begin(SSD1306_SWITCHCAPVCC, 0x3C); // Dirección I2C de la pantalla OLED

    //En C++ hhay que poner objeto.accion
    pantalla.clearDisplay();
    pantalla.display(); // Muestra la pantalla lo hecho
}

void dibujar_emocion(Emotion *sentimiento) 
{
    int i,j;
    printf("Dibujando emoción en la pantalla:\n");
    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        {
            if(sentimiento->ojoDerecho[i][j] == 1)
                pantalla.fillRect(j * 8 + 64, i * 8, 8, 8, SSD1306_WHITE); // Ojo derecho
            else
                pantalla.fillRect(j * 8 + 64, i * 8, 8, 8, SSD1306_BLACK);
        }
    
    }
    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        {
            if(sentimiento->ojoIzquierdo[i][j] == 1)
                pantalla.fillRect(j * 8, i * 8, 8, 8, SSD1306_WHITE); // Ojo izquierdo
            else
                pantalla.fillRect(j * 8, i * 8, 8, 8, SSD1306_BLACK);
        }
        
    }
    pantalla.display();
}
