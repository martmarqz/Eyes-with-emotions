#include "client_ia.h"
#include "config.h"
#include <Arduino.h>
#include <HTTPClient.h>
#include <WiFi.h>
#include <ArduinoJson.h>

bool ia_procesar_audio(const uint8_t* audio, size_t bytesAudio, RespuestaIA& respuesta)
{
    if (audio == nullptr || bytesAudio == 0)
    {
        Serial.println("[IA] ERROR: no hay audio para enviar");
        return false;
    }

    if (WiFi.status() != WL_CONNECTED)
    {
        Serial.println("[IA] ERROR: sin WiFi");
        return false;
    }

    Serial.printf("[IA] Enviando %u bytes a %s\n", (unsigned)bytesAudio, IA_SERVER_URL);

    HTTPClient http;
    http.begin(IA_SERVER_URL);
    http.addHeader("Content-Type", "audio/wav");
    http.setTimeout(IA_TIMEOUT_MS);

    int codigo = http.POST((uint8_t*)audio, bytesAudio);
    Serial.printf("[IA] HTTP codigo: %d\n", codigo);

    if (codigo <= 0)
    {
        Serial.printf("[IA] ERROR de conexion: %s\n", http.errorToString(codigo).c_str());
        http.end();
        return false;
    }

    String contenido = http.getString();
    http.end();

    if (codigo != HTTP_CODE_OK)
    {
        Serial.printf("[IA] ERROR: el servidor respondio %d: %s\n", codigo, contenido.c_str());
        return false;
    }

    JsonDocument documento;
    DeserializationError error = deserializeJson(documento, contenido);

    if (error)
    {
        Serial.printf("[IA] ERROR: JSON invalido: %s\n", contenido.c_str());
        return false;
    }

    if (!documento["comando"].is<const char*>() || !documento["valor"].is<const char*>())
    {
        Serial.printf("[IA] ERROR: faltan campos en el JSON: %s\n", contenido.c_str());
        return false;
    }

    respuesta.version   = documento["version"] | 1;
    respuesta.comando   = documento["comando"].as<String>();
    respuesta.valor     = documento["valor"].as<String>();
    respuesta.respuesta = documento["respuesta"].as<String>();

    return true;
}