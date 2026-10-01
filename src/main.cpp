#include <Arduino.h>
#include "hardware.h"
#include "animation.h"
#include "status.h"

//pantalla de 128 px de alto y 64 px de ancho, con 8x8 px por ojo, dejando 32 px de espacio entre los ojos

// Variable global para rastrear el estado del robot (ej. escuchando, reposo)
// (Asumiendo que definiste algo como 'RobotState' en status.h)
int estado_actual = 0; 

void setup() {
  // Iniciar la comunicación serie a 115200 baudios para poder leer 
  // mensajes de prueba y errores en la terminal
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

  // 2. Establecer el estado inicial al encender
  // estado_actual = ESTADO_REPOSO; 
}

void loop() {
  // Aquí ocurrirá el ciclo de vida continuo del robot:
  
  // 1. Leer los sensores (micrófono INMP441, sensor de distancia)
  // 2. Procesar esa información y actualizar 'estado_actual' (status.c)
  // 3. Dibujar los ojos en la pantalla basándose en el estado (animation.c)

  // Una pequeña pausa de 10 milisegundos ayuda a no saturar el procesador 
  // del ESP32-S3 de forma innecesaria
  delay(10); 
}