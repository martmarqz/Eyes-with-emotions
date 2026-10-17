#include "client_ia.h"
#include "config.h"
#include <Arduino.h>
#include <HTTPClient.h>
#include <WiFi.h>
#include <ArduinoJson.h>

bool ia_procesar_audio(const uint8_t* audio, size_t bytesAudio, RespuestaIA& respuesta)
{
    if(audio == nullptr)
    {
        return false;
    }

    if(bytesAudio == 0)
    {
        return false;
    }

    if(WiFi.status() != WL_CONNECTED)
    {
        return false;
    }

    HTTPClient http;

    http.begin(IA_SERVER_URL);

    http.addHeader("Content-Type", "audio/wav");

    http.setTimeout(IA_TIMEOUT_MS);

    int codigo = http.POST((uint8_t*)audio, bytesAudio);

    if(codigo <= 0)
    {
        http.end();
        return false;
    }

    if(codigo != HTTP_CODE_OK)
    {
        http.end();
        return false;
    }

    String contenido = http.getString();

    http.end();

    JsonDocument documento;

    DeserializationError error = deserializeJson(documento, contenido);

    if(error)
    {
        return false;
    }

    if(!documento["version"].is<int>())
    {
        return false;
    }

    if(!documento["comando"].is<const char*>())
    {
        return false;
    }

    if(!documento["valor"].is<const char*>())
    {
        return false;
    }

    respuesta.version = documento["version"];

    respuesta.comando = documento["comando"].as<String>();

    respuesta.valor = documento["valor"].as<String>();

    respuesta.respuesta = documento["respuesta"].as<String>();

    return true;
}