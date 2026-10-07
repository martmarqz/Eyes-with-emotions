# Proyecto: Ojos con emociones

Integrantes: Martina Márquez y José Matias Monje

# Comandos Makefile

make --> compilar <br>
make upload --> sube la ultima version compilada <br>
make monitor --> Abre el monitor serie para leer los mensajes del sistema y las lecturas de los sensores en tiempo real. <br>
make flash --> Compila el código, lo sube al microcontrolador y abre automáticamente el monitor serie. <br>
make clean --> Elimina los archivos temporales generados en construcciones anteriores para forzar una compilación limpia.

# Estructura proyecto

status.c --> En status van todas las emociones dibujadas<br>
main.cpp --> Es el codigo principal donde se maneja todo<br>
hardware.cpp --> controla todo lo que tiene que ver con el hardware<br>
animation.c --> Aqui se realizan las funciones de las animaciones <br>
status.h --> Aqui se declaran las emociones, es la cabecera de status.c<br>
hardware.h --> Es la cabecera de hardware.cpp<br>
animation.h --> Es la cabecera de animation.c

# Convenciones del codigo

Variables: camelCase <br>
Funciones: snake_case <br>
Define: CONSTANT_CASE <br>
Estructuras: s_NombreEstructura <br>
Enums: e_NombreEnum 