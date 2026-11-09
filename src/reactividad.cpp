/**
 * @file reactividad.cpp
 * @brief Reacciones según touch, proximidad y modo reposo (parpadeo, miradas, dormir)
 * @author Jose Monje
 */

#include <Arduino.h>
#include "reactividad.h"
#include "sensores.h"
#include "status.h"
#include "animation.h"
#include "special.h"

// ===== Ajustes del modo reposo =====
#define TIEMPO_PARA_DORMIR_MS   60000   // 1 minuto sin actividad -> se duerme
#define PARPADEO_MIN_MS         2000
#define PARPADEO_MAX_MS         6000
#define VISTAZO_MIN_MS          6000    // cada cuánto mira de reojo
#define VISTAZO_MAX_MS          14000
#define DURACION_VISTAZO_MIN_MS 600     // cuánto tiempo se queda mirando al costado
#define DURACION_VISTAZO_MAX_MS 1200
#define PROB_DOBLE_PARPADEO     20      // % de veces que parpadea dos veces

enum Zona { ZONA_NINGUNA, ZONA_MUY_CERCA, ZONA_CERCA, ZONA_MEDIA, ZONA_LEJOS, ZONA_REPOSO };
enum EstadoReposo { DESPIERTO, MIRANDO_COSTADO, DORMIDO };

static Zona zona_anterior = ZONA_NINGUNA;
static EstadoReposo estado_reposo = DESPIERTO;

static unsigned long proximo_parpadeo = 0;
static unsigned long proximo_vistazo = 0;
static unsigned long fin_vistazo = 0;
static unsigned long ultima_actividad = 0;
static unsigned long reposo_bloqueado_hasta = 0;

// true si ya llegó el momento 't' (funciona aunque millis() se desborde)
static bool llego(unsigned long t)
{
    return (long)(millis() - t) >= 0;
}

static void programar_parpadeo(void)
{
    proximo_parpadeo = millis() + random(PARPADEO_MIN_MS, PARPADEO_MAX_MS);
}

static void programar_vistazo(void)
{
    proximo_vistazo = millis() + random(VISTAZO_MIN_MS, VISTAZO_MAX_MS);
}

static void registrar_actividad(void)
{
    ultima_actividad = millis();
}

void reactividad_mostrar_emocion_temporal(unsigned long ms)
{
    reposo_bloqueado_hasta = millis() + ms;
    zona_anterior = ZONA_NINGUNA;   // al terminar, vuelve a dibujar el reposo
    estado_reposo = DESPIERTO;
    registrar_actividad();
}

// Comportamiento cuando no hay nadie cerca
static void actualizar_reposo(void)
{
    switch (estado_reposo)
    {
        case DESPIERTO:
            // ¿Mucho tiempo sin actividad? -> dormir
            if (millis() - ultima_actividad >= TIEMPO_PARA_DORMIR_MS)
            {
                dormir();   // cansados -> descansando
                estado_reposo = DORMIDO;
                Serial.println("[REPOSO] Durmiendo...");
                break;
            }

            // ¿Toca mirar de reojo?
            if (llego(proximo_vistazo))
            {
                if (random(2) == 0) dibujar_mirada_reojo();
                else                dibujar_mirada_reojo_derecha();

                fin_vistazo = millis() + random(DURACION_VISTAZO_MIN_MS, DURACION_VISTAZO_MAX_MS);
                estado_reposo = MIRANDO_COSTADO;
                break;
            }

            // ¿Toca parpadear?
            if (llego(proximo_parpadeo))
            {
                parpadeo();
                if (random(100) < PROB_DOBLE_PARPADEO)
                {
                    delay(120);
                    parpadeo();
                }
                programar_parpadeo();
            }
            break;

        case MIRANDO_COSTADO:
            if (llego(fin_vistazo))
            {
                dibujar_ojos_neutros();
                estado_reposo = DESPIERTO;
                programar_vistazo();
                programar_parpadeo();
            }
            break;

        case DORMIDO:
            // Se queda con los ojos cerrados hasta que lo toquen
            break;
    }
}

void actualizar_emocion_por_proximidad(int distancia)
{
    // ===== Touch =====
    if (touch_presionado())
    {
        if (estado_reposo == DORMIDO)
        {
            Serial.println("[REPOSO] Despertando!");
            despertar_golpe();
        }
        else
        {
            ejecutar_animacion_calabazas();
        }

        while (touch_presionado())   // esperar a que suelte
        {
            delay(10);
        }

        registrar_actividad();
        estado_reposo = DESPIERTO;
        zona_anterior = ZONA_NINGUNA;   // fuerza a redibujar
        return;
    }

    // ===== Emoción temporal (por ejemplo, de la IA) =====
    if (!llego(reposo_bloqueado_hasta))
    {
        return;
    }

    // ===== Zona según distancia =====
    Zona zona;
    if (distancia <= 0)       zona = ZONA_REPOSO;
    else if (distancia <= 10) zona = ZONA_MUY_CERCA;
    else if (distancia <= 30) zona = ZONA_CERCA;
    else if (distancia <= 70) zona = ZONA_MEDIA;
    else                      zona = ZONA_LEJOS;

    if (zona != zona_anterior)
    {
        zona_anterior = zona;

        switch (zona)
        {
            case ZONA_MUY_CERCA: dibujar_ojos_furiosos();    registrar_actividad(); break;
            case ZONA_CERCA:     dibujar_ojos_interesados(); registrar_actividad(); break;
            case ZONA_MEDIA:     dibujar_ojos_descansando(); registrar_actividad(); break;
            case ZONA_LEJOS:     dibujar_ojos_neutros();     break;
            case ZONA_REPOSO:
                dibujar_ojos_neutros();
                estado_reposo = DESPIERTO;
                programar_parpadeo();
                programar_vistazo();
                break;
            default: break;
        }
    }

    if (zona == ZONA_REPOSO)
    {
        actualizar_reposo();
    }
}