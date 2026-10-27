#Herramientas para crear el servidor web de forma moderna y manejar múltiples tareas al mismo tiempo.
import asyncio 
from fastapi import FastAPI, Request
from fastapi.responses import JSONResponse

#Conecta este archivo con las otras partes del proyecto
from speech import convertir_audio_a_texto
from ia import interpretar_texto
from tts import hablar_respuesta

#Enciende el servidor web 
app = FastAPI()

#Crea ruta de prueba 
@app.get("/") 
def estado():
    return {
        "estado": "ok",
        "servicio": "robot-voz"
    }
#Puerta para enviar los datos de voz
@app.post("/robot/voz")
async def robot_voz(request: Request): #Define la tarea que manejara al llegar la grabacion
    try: #Si algo falla el programa no colapsa
        audio = await request.body() # Recibe y descarga el audio crudo que envia el microcontrolador

        if not audio: #Si no llega el sonido responde con una estructura predefinida 
            return JSONResponse(
                status_code=400,
                content={
                    "version": 1,
                    "comando": "NINGUNO",
                    "valor": "",
                    "respuesta": "No recibí audio."
                }
            )

        texto = convertir_audio_a_texto(audio)

        if not texto: #Si la transcripción falla o hubo puro ruido, devuelve un comando 
            return {
                "version": 1,
                "comando": "NINGUNO",
                "valor": "",
                "respuesta": "No pude entenderte."
            }

        resultado = interpretar_texto(texto) #Envía el texto limpio a la inteligencia artificial para que decida qué acción debe tomar el robot

        # Reproduce la voz en segundo plano mientras le devuelve la cara al ESP32
        asyncio.create_task(hablar_respuesta(resultado.get("respuesta", "")))

        return resultado

    except Exception as error: #Si algo se rompe en cualquier punto, atrapa el error, lo imprime en pantalla.
        print("Error:", error)
        return JSONResponse(
            status_code=500,
            content={
                "version": 1,
                "comando": "NINGUNO",
                "valor": "",
                "respuesta": "Ocurrió un error."
            }
        )

#El cerebro que une todo