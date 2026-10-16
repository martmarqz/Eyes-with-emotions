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
    dibujar_ojos_neutros();
    delay(100);
    dibujar_ojos_descansando();
    delay(100);
    dibujar_ojos_neutros();   
}

void espacio_personal(void)
{
    float medidaActual = medir_distancia();

    if(medidaActual <= 2.0)
    {
        dibujar_ojos_furiosos();
    }
}

void reflejo_de_acercamiento(void)
{
    int medidaActual = medir_distancia();

    if(medidaActual >= 2 && medidaActual <= 5)
    {
        dibujar_ojos_descansando();
    }
}

void guino(void)
{
    dibujar_ojos_neutros();
    delay(150);
    dibujar_ojos_guinando(); 
    delay(300);
    dibujar_ojos_neutros();
}

void dormir(void)
{
    dibujar_ojos_cansados();
    delay(800);
    dibujar_ojos_descansando();
}

void sorpresa(void)
{
    dibujar_ojos_sorprendidos();
    delay(500);
    dibujar_ojos_exclamacion();
    delay(800);
    dibujar_ojos_neutros();
}

void baile_feliz(void)
{
    for(int i = 0; i < 3; i++) 
    {
        dibujar_ojos_bailarines();
        delay(250);
        dibujar_ojos_felices();
        delay(250);
    }
    dibujar_ojos_neutros();
}

void buscando(void)
{
    dibujar_ojos_interesados();
    delay(500);
    dibujar_ojos_distantes();
    delay(500);
    dibujar_ojos_interesados();
    delay(500);
    dibujar_ojos_neutros();
}

void cortocircuito(void)
{
    for(int i = 0; i < 4; i++) 
    {
        dibujar_ojos_desquiciados(); 
        delay(80);
        dibujar_ojos_confundidos();
        delay(80);
        dibujar_ojos_exclamacion();
        delay(80);
    }
    dibujar_ojos_neutros();
}

void timidez(void)
{
    dibujar_ojos_enamorados();
    delay(800);
    dibujar_ojos_culpables(); 
    delay(600);
    dibujar_ojos_neutros();
}

void terror(void)
{
    dibujar_ojos_halloween();
    delay(400);
    dibujar_ojos_miedo();
    delay(200);
    dibujar_ojos_asustados();
    delay(600);
    dibujar_ojos_neutros();
}

void sospecha(void)
{
    dibujar_sospechosos();
    delay(500);
    dibujar_ojos_celosos();
    delay(500);
    dibujar_ojos_molestos();
    delay(500);
    dibujar_ojos_neutros();
}

void tristeza_profunda(void)
{
    dibujar_ojos_tristes();
    delay(600);
    dibujar_ojos_heridos();
    delay(600);
    dibujar_ojos_humillados();
    delay(600);
    dibujar_ojos_descansando(); 
    delay(400);
    dibujar_ojos_neutros();
}

void mareado(void)
{
    dibujar_ojos_borrachos();
    delay(400);
    dibujar_ojos_confundidos();
    delay(400);
    dibujar_ojos_asqueados();
    delay(400);
    dibujar_ojos_neutros();
}

void dinero(void)
{
    dibujar_ojos_interesados();
    delay(300);
    
    for(int i = 0; i < 3; i++) 
    {
        dibujar_ojos_dinero();
        delay(200);
        dibujar_ojos_poderosos();
        delay(200);
    }
    dibujar_ojos_neutros();
}

void berrinche(void)
{
    dibujar_ojos_frustrados();
    delay(400);
    dibujar_fastidiados();
    delay(300);
    dibujar_ojos_odiosos();
    delay(300);
    
    for(int i = 0; i < 3; i++) 
    {
        dibujar_ojos_vengativos();
        delay(100);
        dibujar_ojos_furiosos();
        delay(100);
    }
    dibujar_ojos_neutros();
}

void meditacion(void)
{
    dibujar_ojos_pacificos();
    delay(1000);
    dibujar_ojos_descansando();
    delay(1200);
    dibujar_ojos_pacificos();
    delay(1000);
    dibujar_ojos_neutros();
}

void ataque_ansiedad(void)
{
    dibujar_ojos_ansiosos();
    delay(400);
    dibujar_ojos_confundidos();
    delay(300);
    
    for(int i = 0; i < 4; i++) 
    {
        dibujar_ojos_asustados();
        delay(150);
        dibujar_ojos_miedo();
        delay(150);
    }
    dibujar_ojos_neutros();
}

void ignorando(void)
{
    dibujar_ojos_aburridos();
    delay(800);
    dibujar_ojos_distantes();
    delay(800);
    dibujar_ojos_rechazados();
    delay(600);
    dibujar_ojos_aburridos();
    delay(600);
    dibujar_ojos_neutros();
}

void despertar_golpe(void)
{
    dibujar_ojos_descansando();
    delay(1000);
    dibujar_ojos_sorprendidos();
    delay(300);
    dibujar_ojos_exclamacion();
    delay(400);
    dibujar_ojos_ansiosos();
    delay(800);
    dibujar_ojos_neutros();
}

void recalibrando(void)
{
    for(int i = 0; i < 3; i++) 
    {
        dibujar_ojos_confundidos();
        delay(150);
        dibujar_ojos_interesados();
        delay(150);
        dibujar_ojos_distantes();
        delay(150);
    }
    dibujar_ojos_neutros();
}

void mirando_alrededor(void)
{
    dibujar_ojos_neutros();
    delay(300);

    dibujar_mirada_reojo();
    delay(500);

    dibujar_ojos_neutros();
    delay(200);

    dibujar_mirada_reojo();
    delay(500);

    dibujar_ojos_neutros();
}

void no_entendi(void)
{
    dibujar_ojos_interesados();
    delay(400);

    dibujar_ojos_confundidos();
    delay(600);

    dibujar_ojos_exclamacion();
    delay(400);

    dibujar_ojos_confundidos();
    delay(400);

    dibujar_ojos_neutros();
}

void idea(void)
{
    dibujar_ojos_neutros();
    delay(300);

    dibujar_ojos_sorprendidos();
    delay(500);

    dibujar_ojos_felices();
    delay(500);

    dibujar_ojos_poderosos();
    delay(700);

    dibujar_ojos_neutros();
}

void genio(void)
{
    dibujar_pensativos();
    delay(500);

    dibujar_intelectuales();
    delay(700);

    dibujar_confiados();
    delay(500);

    dibujar_ojos_poderosos();
    delay(800);

    dibujar_ojos_neutros();
}

void sospechando(void)
{
    dibujar_desconfiados();
    delay(500);

    dibujar_mirada_reojo();
    delay(600);

    dibujar_sospechosos();
    delay(600);

    dibujar_desconfiados();
    delay(400);

    dibujar_ojos_neutros();
}

void mentiroso(void)
{
    dibujar_ojos_neutros();
    delay(300);

    dibujar_mirada_reojo();
    delay(400);

    dibujar_coquetos();
    delay(500);

    dibujar_sarcasticos();
    delay(600);

    dibujar_ojos_neutros();
}

void verguenza(void)
{
    dibujar_avergonzados();
    delay(700);

    dibujar_ojos_humillados();
    delay(600);

    dibujar_ojos_descansando();
    delay(500);

    dibujar_ojos_neutros();
}

void celebracion(void)
{
    for(int i = 0; i < 3; i++)
    {
        dibujar_ojos_felices();
        delay(200);

        dibujar_ojos_bailarines();
        delay(200);

        dibujar_ojos_felices();
        delay(200);

        dibujar_ojos_poderosos();
        delay(200);
    }

    dibujar_ojos_neutros();
}

void panico(void)
{
    dibujar_ojos_neutros();
    delay(300);

    dibujar_ojos_sorprendidos();
    delay(250);

    dibujar_ojos_miedo();
    delay(200);

    for(int i = 0; i < 4; i++)
    {
        dibujar_ojos_asustados();
        delay(120);

        dibujar_ojos_miedo();
        delay(120);
    }

    dibujar_ojos_neutros();
}

void procesando(void)
{
    dibujar_ojos_interesados();
    delay(300);

    dibujar_ojos_confundidos();
    delay(300);

    dibujar_pensativos();
    delay(500);

    dibujar_intelectuales();
    delay(500);

    dibujar_ojos_interesados();
    delay(300);

    dibujar_ojos_neutros();
}

void error(void)
{
    for(int i = 0; i < 3; i++)
    {
        dibujar_ojos_confundidos();
        delay(100);

        dibujar_ojos_exclamacion();
        delay(100);

        dibujar_ojos_desquiciados();
        delay(100);
    }

    dibujar_ojos_neutros();
}

void reiniciando(void)
{
    dibujar_ojos_confundidos();
    delay(300);

    dibujar_ojos_descansando();
    delay(500);

    dibujar_ojos_neutros();
    delay(300);

    dibujar_ojos_sorprendidos();
    delay(400);

    dibujar_ojos_felices();
    delay(500);

    dibujar_ojos_neutros();
}

void wifi_buscando(void)
{
    dibujar_buscando_wifi();
    delay(700);

    dibujar_ojos_interesados();
    delay(400);

    dibujar_buscando_wifi();
    delay(700);

    dibujar_ojos_neutros();
}

void wifi_error(void)
{
    dibujar_buscando_wifi();
    delay(600);

    dibujar_ojos_confundidos();
    delay(300);

    dibujar_error_wifi();
    delay(800);

    dibujar_ojos_molestos();
    delay(500);

    dibujar_ojos_neutros();
}

void wifi_conectado(void)
{
    dibujar_buscando_wifi();
    delay(500);

    dibujar_ojos_sorprendidos();
    delay(300);

    dibujar_conexion_exitosa();
    delay(800);

    dibujar_ojos_felices();
    delay(600);

    dibujar_ojos_neutros();
}

void risa(void)
{
    for(int i = 0; i < 3; i++)
    {
        dibujar_ojos_felices();
        delay(180);

        dibujar_llorando_de_risa();
        delay(220);
    }

    dibujar_ojos_felices();
    delay(400);

    dibujar_ojos_neutros();
}

void llorando(void)
{
    dibujar_ojos_tristes();
    delay(500);

    dibujar_al_borde_de_llorar();
    delay(500);

    dibujar_llorando();
    delay(800);

    dibujar_ojos_descansando();
    delay(400);

    dibujar_ojos_neutros();
}

void enojo_creciente(void)
{
    dibujar_ojos_molestos();
    delay(400);

    dibujar_fastidiados();
    delay(400);

    dibujar_ojos_enojados();
    delay(400);

    dibujar_ojos_frustrados();
    delay(400);

    dibujar_ojos_furiosos();
    delay(700);

    dibujar_ojos_neutros();
}

void mirada_asesina(void)
{
    dibujar_desconfiados();
    delay(400);

    dibujar_ojos_odiosos();
    delay(500);

    dibujar_ojos_vengativos();
    delay(500);

    dibujar_ojos_furiosos();
    delay(800);

    dibujar_ojos_neutros();
}

void coqueteando(void)
{
    dibujar_ojos_neutros();
    delay(300);

    dibujar_ojos_guinando();
    delay(500);

    dibujar_coquetos();
    delay(600);

    dibujar_ojos_enamorados();
    delay(800);

    dibujar_ojos_neutros();
}

void que_verguenza(void)
{
    dibujar_ojos_sorprendidos();
    delay(300);

    dibujar_avergonzados();
    delay(700);

    dibujar_ojos_humillados();
    delay(700);

    dibujar_ojos_descansando();
    delay(400);

    dibujar_ojos_neutros();
}

void me_dio_un_susto(void)
{
    dibujar_ojos_neutros();
    delay(500);

    dibujar_ojos_sorprendidos();
    delay(150);

    dibujar_ojos_miedo();
    delay(200);

    dibujar_ojos_asustados();
    delay(600);

    dibujar_ojos_neutros();
}

void estoy_cansado(void)
{
    dibujar_ojos_cansados();
    delay(500);

    dibujar_adormilados();
    delay(700);

    dibujar_agotados();
    delay(600);

    dibujar_bostezando();
    delay(800);

    dibujar_ojos_descansando();
    delay(500);

    dibujar_ojos_neutros();
}

void borrachera(void)
{
    for(int i = 0; i < 2; i++)
    {
        dibujar_ojos_borrachos();
        delay(400);

        dibujar_mareados();
        delay(400);

        dibujar_ojos_confundidos();
        delay(400);
    }

    dibujar_ojos_descansando();
    delay(500);

    dibujar_ojos_neutros();
}

void estoy_harto(void)
{
    dibujar_ojos_molestos();
    delay(400);

    dibujar_fastidiados();
    delay(500);

    dibujar_exasperados();
    delay(600);

    dibujar_fastidiados();
    delay(400);

    dibujar_ojos_neutros();
}

void glitch(void)
{
    for(int i = 0; i < 5; i++)
    {
        dibujar_ojos_desquiciados();
        delay(50);

        dibujar_ojos_confundidos();
        delay(50);

        dibujar_ojos_exclamacion();
        delay(50);
    }

    dibujar_ojos_neutros();
}