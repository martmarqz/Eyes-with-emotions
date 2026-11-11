#include <Arduino.h>

#include "hardware.h"
#include "voice.h"
#include "command_router.h"
#include "wifi_manager.h"
#include "animation.h"
#include "sensores.h"
#include "reactividad.h"
#include "config.h"
#include "special.h"
#include "status.h"

void setup()
{
    Serial.begin(115200);

    inicializar_hardware();

    inicializar_especial();

    inicializar_wifi();

    inicializar_udp();

    voz_inicializar();

    inicializar_sensores();

    Serial.println(
        "Sistema de voz listo"
    );
}


void loop()
{
#if USAR_SENSOR_DISTANCIA
    int distancia = medir_distancia();
#else
    int distancia = -1;
#endif

    actualizar_emocion_por_proximidad(distancia);

    if (distancia > 0)
        Serial.printf("Distancia: %d cm | ", distancia);
    else
        Serial.print("Distancia: No detectada | ");

    Serial.printf("Mic ADC: %d | ", obtener_nivel_mic());
    Serial.println(touch_presionado() ? "Touch presionado" : "Touch no presionado");

    if (wifi_conectado() && digitalRead(SWITCH_PIN) == LOW)
    {
        Serial.println("Escuchando... habla ahora (5 segundos)");
        dibujar_ojos_escuchando();

        bool resultado = voz_procesar();

        if (resultado)
        {
            Serial.println("Comando ejecutado");
        }
        else
        {
            Serial.println("Error procesando voz");
            dibujar_ojos_confundidos();
        }

        reactividad_mostrar_emocion_temporal(6000);

        while (digitalRead(SWITCH_PIN) == LOW)
        {
            delay(10);
        }
        delay(200);
    }

    delay(100);
}

