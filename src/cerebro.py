# Aqui se realiza la asistencia (tipo Alexa)

import os
import io
import socket
import speech_recognition as sr
from gtts import gTTS
from pydub import AudioSegment
from pydub.playback import play
from transformers import pipeline

#CONFIGURACIÓN UDP (ESP32)
ESP32_IP = "192.168.1.100"  # IP
ESP32_PORT = 4210
sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

EMOCIONES = {
    "ESCUCHANDO": 4,
    "INTERESADO": 10, 
    "FELIZ": 19,    
    "NEUTRO": 22
}

def cambiar_cara(emocion_nombre):
    """Simula el envío UDP al ESP32 para cambiar la animación OLED"""
    print(f"Cambiando animación a: {emocion_nombre}")
    # Descomentaremos esto cuando el ESP32 esté encendido:
    # sock.sendto(str(EMOCIONES[emocion_nombre]).encode(), (ESP32_IP, ESP32_PORT))

print("Cargando modelo local Gazelle en memoria... (Esto puede tomar unos segundos)")
generador = pipeline("text-generation", model="./gazelle-env")
print("Modelo cargado con éxito.")

#VOZ
reconocedor = sr.Recognizer()

def escuchar():
    with sr.Microphone() as source:
        cambiar_cara("ESCUCHANDO")
        print("\nTe escucho...")
        reconocedor.adjust_for_ambient_noise(source, duration=1)
        audio = reconocedor.listen(source)
    try:
        texto = reconocedor.recognize_google(audio, language="es-ES")
        print(f"Tú: {texto}")
        return texto
    except sr.UnknownValueError:
        print("Error fatal: No detecté voz clara.")
        return ""
    except sr.RequestError:
        print("Error fatal: no hay conexión con el servicio de reconocimiento.")
        return ""

def hablar(texto):
    cambiar_cara("FELIZ")
    print(f"Gazelle: {texto}")
    
    # texto a voz
    tts = gTTS(text=texto, lang='es')
    fp = io.BytesIO()
    tts.write_to_fp(fp)
    fp.seek(0)
    
    # Reproduce el audio en Linux 
    audio = AudioSegment.from_file(fp, format="mp3")
    play(audio)
    
    cambiar_cara("NEUTRO")

#Bucle principal

if __name__ == "__main__":
    cambiar_cara("NEUTRO")
    hablar("Sistema iniciado. Hola, estoy listo.")
    
    while True:
        entrada_usuario = escuchar()
        
        if entrada_usuario:
            if "apagar" in entrada_usuario.lower() or "salir" in entrada_usuario.lower():
                hablar("Apagando sistema. Hasta pronto.")
                break
            
            cambiar_cara("INTERESADO")
            print("Generando respuesta...")
            
            # Pasa el texto de voz al modelo local de IA
            resultado = generador(
                entrada_usuario, 
                max_length=150, 
                num_return_sequences=1,
                truncation=True
            )
            respuesta_cruda = resultado[0]['generated_text']
            
            # Limpia la respuesta para no repetir lo que se dijo
            respuesta_limpia = respuesta_cruda.replace(entrada_usuario, "").strip()
            
            # El robot responde
            hablar(respuesta_limpia)