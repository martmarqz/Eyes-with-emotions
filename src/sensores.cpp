/**
 * @file sensores.h
 * @brief Implementacion de la lectura de sensores, con apoyo en hardware.h
 * @author Jose Monje
 */
#include "sensores.h"

void inicializar_sensores(void)
{
    pinMode(MOVE_SENSOR_TRIG, OUTPUT);
    pinMode(MOVE_SENSOR_ECHO, INPUT);
    digitalWrite(MOVE_SENSOR_TRIG, LOW);

    pinMode(MICROPHONE_PIN, INPUT);
    analogReadResolution(12);

    Serial.println("[SENSORES] Inicializados Correctamente.");
}

float obtener_distancia_cm(void)
{
    digitalWrite(MOVE_SENSOR_TRIG, LOW);
    delayMicroseconds(2);
    digitalWrite(MOVE_SENSOR_TRIG, HIGH);
    delayMicroseconds(10);
    digitalWrite(MOVE_SENSOR_TRIG, LOW);

    long duracion = pulseIn(MOVE_SENSOR_ECHO, HIGH, TIMEOUT_US);
    if (duracion == 0) return -1.0f; // Timeout, no se detectó un pulso

    return (duracion * 0.0343f) / 2.0f;
}

int obtener_nivel_mic(void)
{
   return analogRead(MICROPHONE_PIN);
}

bool touch_presionado(void)
{
    uint32_t valor_touch = touchRead(TOUCH_PIN);
    return (valor_touch > UMBRAL_TOUCH);
}
   