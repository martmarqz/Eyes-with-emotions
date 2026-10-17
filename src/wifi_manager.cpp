#include "wifi_manager.h"
#include <WiFi.h>
#include <WiFiManager.h>
#include "status.h"
#include <stdio.h>

WiFiUDP udp;
const int PUERTO_UDP = 4242;

void configModeCallback(WiFiManager *myWiFiManager)
{
    printf("Configuracion activada...\n");
    printf("Conectate a la red: %s\n", myWiFiManager->getConfigPortalSSID().c_str());

    dibujar_error_wifi();
}

void inicializar_wifi(void)
{
    WiFiManager wifiManager;

    wifiManager.setAPCallback(configModeCallback);

    printf("\nBuscando redes Wi-Fi guardadas...\n");

    dibujar_buscando_wifi();

    if (!wifiManager.autoConnect("Robot-Asistente"))
    {
        printf("Error fatal: Fallo al conectar y tiempo de espera agotado\n");

        ESP.restart();
        delay(1000);
    }

    printf("\nWi-Fi conectado exitosamente!\n");
    printf("Direccion IP asignada: %s\n", WiFi.localIP().toString().c_str());

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

    printf("Escuchando comandos en el puerto UDP: %d\n", PUERTO_UDP);
}

int escuchar_estado_udp(void)
{
    int estado = -1;
    int paquetes = udp.parsePacket();
    int cantidad;

    if (paquetes)
    {
        char buffer[32];

        cantidad = udp.read(buffer, sizeof(buffer) - 1);

        if (cantidad > 0)
        {
            buffer[cantidad] = '\0';

            estado = atoi(buffer);

            actualizar_emocion((enum e_Emociones)estado);
        }
    }

    return estado;
}