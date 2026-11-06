/**
 * @file reactividad.h
 * @brief Implementacion de reacciones segun proximidad con sensor
 * @author Jose Monje
 */

 #include <Arduino.h>
 #include "reactividad.h"
 #include "sensores.h"
 #include "status.h"
 #include "animation.h"
 #include "special.h"

 enum Zona { ZONA_NINGUNA, ZONA_TOUCH, ZONA_MUY_CERCA, ZONA_CERCA, ZONA_MEDIA, ZONA_LEJOS, ZONA_REPOSO};

static Zona zona_anterior = ZONA_NINGUNA;
static unsigned long proximo_parpadeo = 0;

static void programar_parpadeo(void)
{
    proximo_parpadeo = millis() + random(2000, 6000);
}

void actualizar_emocion_por_proximidad(int distancia)
{
    // Touch: ejecuta la animación especial (gatos)
    if (touch_presionado())
    {
        ejecutar_animacion_calabazas();

        // Esperar a que suelte el touch para que no se repita
        while (touch_presionado())
        {
            delay(10);
        }

        zona_anterior = ZONA_NINGUNA; // fuerza a redibujar la cara
        return;
    }

    Zona zona;

    if (distancia <= 0)            zona = ZONA_REPOSO;
    else if (distancia <= 10)      zona = ZONA_MUY_CERCA;
    else if (distancia <= 30)      zona = ZONA_CERCA;
    else if (distancia <= 70)      zona = ZONA_MEDIA;
    else                           zona = ZONA_LEJOS;

    // Si cambió la zona, dibujar la cara nueva
    if (zona != zona_anterior)
    {
        zona_anterior = zona;

        switch (zona)
        {
            case ZONA_MUY_CERCA: dibujar_ojos_furiosos();    break;
            case ZONA_CERCA:     dibujar_ojos_interesados(); break;
            case ZONA_MEDIA:     dibujar_ojos_descansando(); break;
            case ZONA_LEJOS:     dibujar_ojos_neutros();     break;
            case ZONA_REPOSO:
                dibujar_ojos_neutros();
                programar_parpadeo();
                break;
            default: break;
        }
    }

    // En reposo: parpadear cada tanto
    if (zona == ZONA_REPOSO && (long)(millis() - proximo_parpadeo) >= 0)
    {
        parpadeo();
        programar_parpadeo();
    }
}