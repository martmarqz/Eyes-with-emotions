#ifndef AI_PROTOCOL_H
#define AI_PROTOCOL_H

#include <Arduino.h>

struct RespuestaIA
{
    int version;
    String comando;
    String valor;
    String respuesta;
};

#endif