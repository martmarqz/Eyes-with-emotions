#include "hardware.h"
#include <stdio.h>
#include <Wire.h>
#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <SPI.h>
#include <SD.h>
#include <driver/adc.h>

Adafruit_SSD1306 pantalla(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void inicializar_hardware(void)
{
    delay(1000);

    Serial.println("\nIniciando ESP32-S3...");

    inicializar_pantalla();
    inicializar_sensor_movimiento();
    inicializar_amplificador();
    inicializar_microfono();
    inicializar_microsd();
    inicializar_touch();
    inicializar_interruptor();

    Serial.println("Hardware inicializado con exito\n");
}

void inicializar_pantalla(void)
{
    Wire.begin(DISPLAY_SDA, DISPLAY_SCL);
    Wire.setClock(100000);

    Serial.println("I2C INICIANDO\n");
    Serial.println("Conectando a la pantalla...");

    if(!pantalla.begin(SSD1306_SWITCHCAPVCC, 0x3C))
    {
        Serial.println("Error fatal: No se encontro la pantalla");

        while(true)
        {
            delay(100);
        }
    }

    pantalla.clearDisplay();

    Serial.println("Ejecutando clearDisplay...");

    pantalla.display();

    Serial.println("display ejecutando...");
}

void inicializar_sensor_movimiento(void)
{
    pinMode(MOVE_SENSOR_ECHO, INPUT);
    pinMode(MOVE_SENSOR_TRIG, OUTPUT);

    Serial.println("Iniciando sensor de distancia...");
}

void inicializar_microfono(void)
{
    pinMode(MICROPHONE_PIN, INPUT);

    analogReadResolution(12);

    analogSetPinAttenuation((adc1_channel_t) MICROPHONE_PIN, ADC_11db);

    Serial.println("Inicializando microfono analogico KS0035...");
}

int leer_microfono(void)
{
    return analogRead(MICROPHONE_PIN);
}

void inicializar_microsd(void)
{
    SPI.begin(SD_SCK, SD_MISO, SD_MOSI, SD_CS);

    if(!SD.begin(SD_CS))
    {
        Serial.println("Micro SD no detectada...\nEl robot seguira sin ella.");
    }
    else
    {
        Serial.println("Micro SD conectada y lista...");
    }
}

void inicializar_touch(void)
{
    pinMode(TOUCH_PIN, INPUT);

    Serial.println("Iniciando sensor touch...");
}

void inicializar_amplificador(void)
{
    pinMode(AMP_BCLK, OUTPUT);
    pinMode(AMP_LRC, OUTPUT);
    pinMode(AMP_DOUT, OUTPUT);

    Serial.println("Amplificador listo...");
}

void inicializar_interruptor(void)
{
    pinMode(SWITCH_PIN, INPUT_PULLUP);

    Serial.println("Interruptor listo...");
}

int medir_distancia()
{
    long duracion;
    int distancia;

    digitalWrite(MOVE_SENSOR_TRIG, LOW);
    delayMicroseconds(2);

    digitalWrite(MOVE_SENSOR_TRIG, HIGH);
    delayMicroseconds(10);

    digitalWrite(MOVE_SENSOR_TRIG, LOW);

    duracion = pulseIn(MOVE_SENSOR_ECHO, HIGH);

    distancia = duracion / 58;

    return distancia;
}