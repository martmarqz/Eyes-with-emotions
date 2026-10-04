#include <Arduino.h>
#include "hardware.h"
#include "animation.h"
#include "status.h"
#include "wifi_manager.h"

//pantalla de 128 px de alto y 64 px de ancho, con 8x8 px por ojo, dejando 32 px de espacio entre los ojos

void setup() 
{
  // Iniciar la comunicación serie a 115200 baudios para poder leer 
  Serial.begin(115200);
  Serial.println("Iniciando sistema del robot...");

  inicializar_wifi("Emerita", "pascua834"); //Nombre y password del wifi
  inicializar_udp(); 
  inicializar_hardware();
  dibujar_emocion(&ojosNeutros);
 
}

void loop() 
{
  // Aquí ocurrirá el ciclo de vida continuo del robot:
  
  // 1. Leer los sensores (micrófono INMP441, sensor de distancia)
  // 2. Procesar esa información y actualizar 'estado_actual' (status.c)
  // 3. Dibujar los ojos en la pantalla basándose en el estado (animation.c)
  
  int estado_mental = escuchar_estado_udp();
  int estadoActual = 0; 

  if (estado_mental != -1) 
  {
      if (estado_mental == 1) {
          dibujar_emocion(&ojosDescansando); // Relajación/Ondas Alfa
      } 
      else if (estado_mental == 2) {
          dibujar_emocion(&ojosSorprendidos); // Alerta/Ondas Beta
      }
      else {
          dibujar_emocion(&ojosNeutros); // Estado base
      }
  }
 
  if(estadoActual==0)
  {
    parpadeo();
  }
  else
  {
    dibujar_emocion(&ojosEnamorados);
  }

  reflejo_de_acercamiento();

  delay(3000); 
}