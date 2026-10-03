#include <Arduino.h>
#include "hardware.h"
#include "animation.h"
#include "status.h"

//pantalla de 128 px de alto y 64 px de ancho, con 8x8 px por ojo, dejando 32 px de espacio entre los ojos

void setup() 
{
  // Iniciar la comunicación serie a 115200 baudios para poder leer 
  Serial.begin(115200);
  Serial.println("Iniciando sistema del robot...");

  inicializar_hardware();

  Emotion ojosNeutros =
  {
    .ojoDerecho =
    {
        {0,0,0,0,0,0,0,0},
        {0,1,1,1,1,1,1,0},
        {0,1,1,1,1,1,1,0},
        {0,1,1,1,1,1,1,0},
        {0,1,1,1,1,1,1,0},
        {0,1,1,1,1,1,1,0},
        {0,1,1,1,1,1,1,0},
        {0,0,0,0,0,0,0,0}
    },
    .ojoIzquierdo =
    {
        {0,0,0,0,0,0,0,0},
        {0,1,1,1,1,1,1,0},
        {0,1,1,1,1,1,1,0},
        {0,1,1,1,1,1,1,0},
        {0,1,1,1,1,1,1,0},
        {0,1,1,1,1,1,1,0},
        {0,1,1,1,1,1,1,0},
        {0,0,0,0,0,0,0,0}
    },
    .volumenAltavoz = 200
  };

  dibujar_emocion(&ojosNeutros);
 
}

void loop() 
{
  // Aquí ocurrirá el ciclo de vida continuo del robot:
  
  // 1. Leer los sensores (micrófono INMP441, sensor de distancia)
  // 2. Procesar esa información y actualizar 'estado_actual' (status.c)
  // 3. Dibujar los ojos en la pantalla basándose en el estado (animation.c)
  
  int estadoActual = 0; 
 
  if(estadoActual==0)
  {
    parpadeo();
  }
  else
  {
    dibujar_emocion(&ojosEnamorados);
  }

  delay(3000); 
}