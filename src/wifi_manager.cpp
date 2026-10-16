#include "wifi_manager.h"
#include <WiFi.h>
#include <WiFiManager.h> 
#include "status.h"     
#include <stdio.h>

WiFiUDP udp;
const int PUERTO_UDP = 4242;

void configModeCallback(WiFiManager *myWiFiManager) 
{
    printf("Modo Configuración activado...\n Conéctate a la red: %s\n", myWiFiManager->getConfigPortalSSID().c_str());
    
    dibujar_error_wifi(); 
}

void inicializar_wifi(void) 
{
    WiFiManager wifiManager;

    wifiManager.setAPCallback(configModeCallback);

    printf("\nBuscando redes Wi-Fi guardadas en memoria...\n");

    dibujar_buscando_wifi();

    if (!wifiManager.autoConnect("Robot-Asistente")) 
    {
        printf("Fallo al conectar y tiempo de espera agotado\n");
        
        ESP.restart();
        delay(1000);
    }

    printf("\nWi-Fi conectado exitosamente!\n");
    printf("Dirección IP asignada: %s\n", WiFi.localIP().toString().c_str());
    
    dibujar_conexion_exitosa();
}

int wifi_conectado(void) 
{
    if (WiFi.status() == WL_CONNECTED) 
    { 
        return 1; 
    } 
    else 
    {
        return 0; 
    }
}

void inicializar_udp(void) 
{
    udp.begin(PUERTO_UDP); 
    printf("Robot escuchando comandos en el puerto UDP: %d\n", PUERTO_UDP);
}