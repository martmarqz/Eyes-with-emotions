#include "animation.h"
#include "status.h"
#include<stdio.h>
#include <Arduino.h>

void parpadeo(void)
{
    dibujar_emocion(&ojosNeutros);
    delay(100);
    dibujar_emocion(&ojosDescansando);
    delay(100);
    dibujar_emocion(&ojosNeutros);   
}

void espacio_personal(void)
{
    float medidaActual = medir_distancia();

    if(medidaActual <= 2.0)
    {
        dibujar_emocion(&ojosFuriosos);
    }
}

void reflejo_de_acercamiento(void)
{
    float medidaActual = medir_distancia();

    if(medidaActual <= 2.1 && medidaActual >= 5.0)
    {
        dibujar_emocion(&ojosDescansando);
    }
}