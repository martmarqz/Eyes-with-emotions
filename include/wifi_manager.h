#ifndef WIFI_MANAGER_H
#define WIFI_MANAGER_H

#ifdef __cplusplus
extern "C" {
#endif

//FUNCIONES

/**
 * @brief Se conecta a wifi
 * 
 * @author Martina Marquez
 * 
 */
void inicializar_wifi(void);

/**
 * @brief Verifica la conexion a wifi
 * 
 * @return int 
 * 
 * @author Martina Marquez
 */
int wifi_conectado(void);

/**
 * @brief inicializa el UDP
 * 
 * @author Martina Marquez
 * 
 */
void inicializar_udp(void);

/**
 * @brief Verifica el estado del UDP
 * 
 * @return int 
 * 
 * @author Martina Marquez
 */
int escuchar_estado_udp(void);

#ifdef __cplusplus
}
#endif

#endif