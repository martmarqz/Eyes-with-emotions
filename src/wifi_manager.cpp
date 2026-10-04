#include "wifi_manager.h"
#include <Arduino.h>
#include <WiFi.h>
#include <stdio.h>

WiFiUDP udp;
const int PUERTO_UDP = 4242;

void inicializar_wifi(const char* ssid, const char* password) 
{
    printf("\nConectando a la red Wi-Fi: %s\n", ssid);
    
    // Configura el ESP32 como estación
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);

    // El código se detiene aquí hasta que el router entregue una IP
    while (WiFi.status() != WL_CONNECTED) 
    {
        delay(500);
        printf(".");
    }

    printf("\n¡Wi-Fi conectado exitosamente!\n");

    // Imprimimos la IP para saber a qué dirección enviar los datos desde Python
    printf("Dirección IP asignada: %s\n", WiFi.localIP().toString().c_str());
}

int wifi_conectado(void) 
{
    if (WiFi.status() == WL_CONNECTED) {
        return 1;
    } else {
        return 0;
    }
}

void inicializar_udp(void) 
{
    udp.begin(PUERTO_UDP);
    printf("Robot escuchando ondas cerebrales en el puerto UDP: %d\n", PUERTO_UDP);
}

int escuchar_estado_udp(void) 
{
    int tamano_paquete = udp.parsePacket();
    
    // Si llegan datos
    if (tamano_paquete) 
    {
        char buffer[255];
        int longitud = udp.read(buffer, 255);

        if (longitud > 0) 
        {
            buffer[longitud] = '\0'; // Cerramos la cadena de texto
        }
        
        // Convierte el texto recibido a un número entero

        int nuevo_estado = atoi(buffer);
        printf("Señal recibida: %d\n", nuevo_estado);
        return nuevo_estado;
    }
    
    return -1; //no hay datos nuevos en este milisegundo
}