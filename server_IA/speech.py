import os #Lee la configuracion del sistema operativo
from groq import Groq #Servicio en la nube

#Busca la API en la computadora 
cliente = Groq(api_key=os.environ.get("GROQ_API_KEY"))

def convertir_audio_a_texto(audio: bytes) -> str: #Recibe el audio y lo transcribe a texto
    resultado = cliente.audio.transcriptions.create( #Le envia la grabacion a la IA para que la procese 
        file=("audio.wav", audio), #Le pasa el sonido
        model="whisper-large-v3-turbo", #Modelo que va a realizar el trabajo
        language="es" #Idioma del audio
    )
    texto = resultado.text.strip() #Extrae lo que dijo la IA
    print(f"Texto escuchado: {texto}") #Imprime lo que entendio la maquina
    return texto #Entrega el texto final

# Oido del programa              "respuest