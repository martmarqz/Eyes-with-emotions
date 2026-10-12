# Aqui se realiza la asistencia (tipo Alexa)

from transformers import pipeline

# Reemplaza esto con la ruta exacta de la carpeta en tu Linux Mint
RUTA_GAZELLE = "/home/martina/Documentos/T. Integracion/Proyecto/Gazelle"

print("Despertando a Gazelle desde el disco local. Esto puede tomar unos segundos...")
# Al usar la ruta local, Python cargará los tensores y configuraciones de tu carpeta
generador = pipeline("text-generation", model=RUTA_GAZELLE)

def procesar_intencion(texto):
    print(f"Escuchado: {texto}")
    
    prompt = f"Eres un robot asistente. Responde en una sola oración breve y hablada. Usuario: {texto}\nRobot:"
    
    # Inferencia local
    resultado = generador(prompt, max_new_tokens=40, do_sample=True, temperature=0.7)
    respuesta_ia = resultado[0]['generated_text'].split("Robot:")[-1].strip()
    
    # Evaluación de emociones basada en el texto generado
    emocion_id = 22 # NEUTRO por defecto
    texto_min = respuesta_ia.lower()
    
    if "feliz" in texto_min or "encanta" in texto_min or "alegría" in texto_min: 
        emocion_id = 19 # FELIZ
    elif "pensando" in texto_min or "buscando" in texto_min: 
        emocion_id = 10 # INTERESADO
    elif "no entiendo" in texto_min or "disculpa" in texto_min: 
        emocion_id = 9  # CONFUNDIDO
    elif "dormir" in texto_min or "descansar" in texto_min:
        emocion_id = 3  # DESCANSANDO
        
    return respuesta_ia, emocion_id