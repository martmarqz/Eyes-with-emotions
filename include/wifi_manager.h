#ifndef WIFI_MANAGER_H
#define WIFI_MANAGER_H

#ifdef __cplusplus
extern "C" {
#endif

//FUNCIONES
void inicializar_wifi(const char* ssid, const char* password);
int wifi_conectado(void);
void inicializar_udp(void);
int escuchar_estado_udp(void);

#ifdef __cplusplus
}
#endif

#endif