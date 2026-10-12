#include "hardware.h"
#include <stdio.h> 
#include <Wire.h>
#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

Adafruit_SSD1306 pantalla(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void inicializar_hardware(void) 
{
    delay(1000);
    Serial.println("Iniciando configuración del ESP32-S3...");
    
    Wire.begin(DISPLAY_SDA, DISPLAY_SCL); 
    Wire.setClock(100000); // Forzamos una velocidad estándar para que la transferencia no se congele
    
    Serial.println("I2C iniciado. Conectando a la pantalla...");
    
    if(!pantalla.begin(SSD1306_SWITCHCAPVCC, 0x3C)) 
    {
        Serial.println("Error: No se encontro la pantalla OLED");
        while(true) { delay(100); }
    }

    Serial.println("Paso 1: Pantalla conectada con éxito.");
    
    pantalla.clearDisplay();
    Serial.println("Paso 2: clearDisplay ejecutado.");
    
    pantalla.display(); 
    Serial.println("Paso 3: display ejecutado.");

    //pinMode(TOUCH_PIN, INPUT);
    //Serial.println("Paso 4: pinMode ejecutado.");
}

void dibujar_emocion(Emotion *sentimiento)
{
    if (sentimiento == NULL || sentimiento->dibujar == NULL)
    {
        return;
    }

    sentimiento->dibujar();
}

int medir_distancia()
{
    long duracion;
    int distancia;

    //SENSOR MOVIMIENTO
    pinMode(MOVE_SENSOR_TRIG, OUTPUT);
    pinMode(MOVE_SENSOR_ECHO, INPUT);
    digitalWrite(MOVE_SENSOR_TRIG, LOW);
    delayMicroseconds(2);
    digitalWrite(MOVE_SENSOR_TRIG, HIGH);
    delayMicroseconds(10);
    digitalWrite(MOVE_SENSOR_TRIG,LOW);
    duracion=pulseIn(MOVE_SENSOR_ECHO,HIGH);
    distancia=duracion/58;
    return distancia;

}