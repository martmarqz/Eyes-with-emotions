#include <Arduino.h>

#include "hardware.h"
#include "voice.h"
#include "command_router.h"
#include "wifi_manager.h"
#include "animation.h"
#include "sensores.h"

void setup()
{
    Serial.begin(115200);

    inicializar_hardware();

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
    //Proximidad
    float distancia = medir_distancia();
    if(distancia>0)
    {
        Serial.printf("Distancia: ½.2f cm | ", distancia);
    }
    else
    {
        Serial.print("Distancia: No detectada | ");
    }

    //Micrófono
    int mic_val = obtener_nivel_mic();
    Serial.printf("Mic ADC: %d | ", mic_val);

    //Touch
    if(touch_presionado())
    {
        Serial.println("Touch presionado");
    }
    else
    {
        Serial.println("Touch no presionado");  
    }
    delay(200);

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

