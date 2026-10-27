#include <Arduino.h>

#include "hardware.h"
#include "voice.h"
#include "command_router.h"
#include "wifi_manager.h"
#include "animation.h"

void setup()
{
    Serial.begin(115200);

    inicializar_hardware();

    inicializar_wifi();

    inicializar_udp();

    voz_inicializar();

    Serial.println(
        "Sistema de voz listo"
    );
}

void loop()
{
    if(wifi_conectado())
    {
        if(digitalRead(SWITCH_PIN) == LOW)
        {
            Serial.println("Escuchando...");

            bool resultado = voz_procesar();

            if(resultado)
            {
                Serial.println("Comando ejecutado");
            }
            else
            {
                Serial.println("Error procesando voz");
            }

            while(digitalRead(SWITCH_PIN) == LOW)
            {
                delay(10);
            }

            delay(200);
        }
    }

    actualizar_animacion();

    delay(10);
}