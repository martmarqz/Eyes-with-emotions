#Herramientas
import io #Permite manejar datos en la memoria
import edge_tts #convierte de texto a voz
import pygame #reproduce el sonido

#Enciende y prepara el sistema de audio del programa, para que emita sonido
pygame.mixer.init()


async def hablar_respuesta(texto: str): # Recibe el textoa leer
    if not texto:
        return
    comunicador = edge_tts.Communicate(texto, voice="es-CL-CatalinaNeural") # Configura el entorno de voz
    audio_bytes = b"" #Crea un espacio en la memoria donde se guarda el audio
    async for chunk in comunicador.stream(): #Recibe y procesa fragmentos de audio y los reproduce inmediatamente
        if chunk["type"] == "audio": #Se asegura de que sea audio puro y los agrega en la memoria que los dejamos
            audio_bytes += chunk["data"] 

    if audio_bytes: #Verifica que el paso anterior no falle
        sonido = pygame.mixer.Sound(io.BytesIO(audio_bytes)) # Lo transforma en un sonido que la maquina entienda
        sonido.play() #Activa los altavoces y reproduce el texto hablando

#Lee texto en voz alta