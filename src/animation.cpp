#include "animation.h"
#include "status.h"
#include "hardware.h"
#include <stdio.h>
#include <Arduino.h>

unsigned long tiempo_ultimo_parpadeo = 0;

void actualizar_animacion(void)
{
    reflejo_de_acercamiento();
}

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
    int medidaActual = medir_distancia();

    if(medidaActual >= 2 && medidaActual <= 5)
    {
        dibujar_emocion(&ojosDescansando);
    }
}

void guino(void)
{
    dibujar_emocion(&ojosNeutros);
    delay(150);
    dibujar_emocion(&ojosGuino); 
    delay(300);
    dibujar_emocion(&ojosNeutros);
}

void dormir(void)
{
    dibujar_emocion(&ojosCansados);
    delay(800);
    dibujar_emocion(&ojosDescansando);
}

void sorpresa(void)
{
    dibujar_emocion(&ojosSorprendidos);
    delay(500);
    dibujar_emocion(&ojosExclamacion);
    delay(800);
    dibujar_emocion(&ojosNeutros);
}

void baile_feliz(void)
{
    for(int i = 0; i < 3; i++) 
    {
        dibujar_emocion(&ojosBailarin);
        delay(250);
        dibujar_emocion(&ojosFelices);
        delay(250);
    }
    dibujar_emocion(&ojosNeutros);
}

void buscando(void)
{
    dibujar_emocion(&ojosInteresados);
    delay(500);
    dibujar_emocion(&ojosDistantes);
    delay(500);
    dibujar_emocion(&ojosInteresados);
    delay(500);
    dibujar_emocion(&ojosNeutros);
}

void cortocircuito(void)
{
    for(int i = 0; i < 4; i++) 
    {
        dibujar_emocion(&ojosDesquisiados); 
        delay(80);
        dibujar_emocion(&ojosConfundidos);
        delay(80);
        dibujar_emocion(&ojosExclamacion);
        delay(80);
    }
    dibujar_emocion(&ojosNeutros);
}

void timidez(void)
{
    dibujar_emocion(&ojosEnamorados);
    delay(800);
    dibujar_emocion(&ojosCulpables); 
    delay(600);
    dibujar_emocion(&ojosNeutros);
}

void terror(void)
{
    dibujar_emocion(&ojosHalloween);
    delay(400);
    dibujar_emocion(&ojosMiedo);
    delay(200);
    dibujar_emocion(&ojosAsustados);
    delay(600);
    dibujar_emocion(&ojosNeutros);
}

void sospecha(void)
{
    dibujar_emocion(&ojosCriticos);
    delay(500);
    dibujar_emocion(&ojosCelosos);
    delay(500);
    dibujar_emocion(&ojosMolestos);
    delay(500);
    dibujar_emocion(&ojosNeutros);
}

void tristeza_profunda(void)
{
    dibujar_emocion(&ojosTristes);
    delay(600);
    dibujar_emocion(&ojosHeridos);
    delay(600);
    dibujar_emocion(&ojosHumillados);
    delay(600);
    dibujar_emocion(&ojosDescansando); 
    delay(400);
    dibujar_emocion(&ojosNeutros);
}

void mareado(void)
{
    dibujar_emocion(&ojosBorrachos);
    delay(400);
    dibujar_emocion(&ojosConfundidos);
    delay(400);
    dibujar_emocion(&ojosAsqueados);
    delay(400);
    dibujar_emocion(&ojosNeutros);
}

void dinero(void)
{
    dibujar_emocion(&ojosInteresados);
    delay(300);
    
    for(int i = 0; i < 3; i++) 
    {
        dibujar_emocion(&ojosPesos);
        delay(200);
        dibujar_emocion(&ojosPoderosos);
        delay(200);
    }
    dibujar_emocion(&ojosNeutros);
}

void berrinche(void)
{
    dibujar_emocion(&ojosFrustrados);
    delay(400);
    dibujar_emocion(&ojosEnojados);
    delay(300);
    dibujar_emocion(&ojosOdiosos);
    delay(300);
    
    for(int i = 0; i < 3; i++) 
    {
        dibujar_emocion(&ojosVengativos);
        delay(100);
        dibujar_emocion(&ojosFuriosos);
        delay(100);
    }
    dibujar_emocion(&ojosNeutros);
}

void meditacion(void)
{
    dibujar_emocion(&ojosPacificos);
    delay(1000);
    dibujar_emocion(&ojosDescansando);
    delay(1200);
    dibujar_emocion(&ojosPacificos);
    delay(1000);
    dibujar_emocion(&ojosNeutros);
}

void ataque_ansiedad(void)
{
    dibujar_emocion(&ojosAnsiosos);
    delay(400);
    dibujar_emocion(&ojosConfundidos);
    delay(300);
    
    for(int i = 0; i < 4; i++) 
    {
        dibujar_emocion(&ojosAsustados);
        delay(150);
        dibujar_emocion(&ojosMiedo);
        delay(150);
    }
    dibujar_emocion(&ojosNeutros);
}

void ignorando(void)
{
    dibujar_emocion(&ojosAburridos);
    delay(800);
    dibujar_emocion(&ojosDistantes);
    delay(800);
    dibujar_emocion(&ojosRechazados);
    delay(600);
    dibujar_emocion(&ojosAburridos);
    delay(600);
    dibujar_emocion(&ojosNeutros);
}

void despertar_golpe(void)
{
    dibujar_emocion(&ojosDescansando);
    delay(1000);
    dibujar_emocion(&ojosSorprendidos);
    delay(300);
    dibujar_emocion(&ojosExclamacion);
    delay(400);
    dibujar_emocion(&ojosAnsiosos);
    delay(800);
    dibujar_emocion(&ojosNeutros);
}

void recalibrando(void)
{
    for(int i = 0; i < 3; i++) 
    {
        dibujar_emocion(&ojosConfundidos);
        delay(150);
        dibujar_emocion(&ojosInteresados);
        delay(150);
        dibujar_emocion(&ojosDistantes);
        delay(150);
    }
    dibujar_emocion(&ojosNeutros);
}