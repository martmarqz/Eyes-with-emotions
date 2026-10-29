/**
 * @file reactividad.h
 * @brief Implementacion de reacciones segun proximidad con sensor
 * @author Jose Monje
 */

 #include "reactividad.h"
 #include "sensores.h"
 #include "status.h"
 #include "animation.h"

 void actualizar_emocion_por_proximidad(void)
 {

    if(touch_presionado())
    {
        //Si el touch està presionado, dibuja ojos de furia
        dibujar_ojos_demoniacos();
        return;
    }   
    float distancia = medir_distancia();

    if(distancia>0)
    {
        if(distancia<=10.0f)
        {
            //Si el objeto està muy cerca
            dibujar_ojos_furiosos();
        }
        else if(distancia>10.0f && distancia<=30.0f)
        {
            //Si el objeto està cerca 
            dibujar_ojos_interesados();
        }
        else if(distancia>30.0f && distancia<=70.0f)
        {
            //Si el objeto està a una distancia media
            dibujar_ojos_descansando();
        }
        else
        {
            //Si el objeto està lejos
            dibujar_ojos_neutros();
        }
    }

    else
    {
        //No detecta nada o està fuera de rango del sensor
        dibujar_ojos_aburridos();
    }
 }