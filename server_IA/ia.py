import os
import json
import re #Busca y limpia partes del texto
from groq import Groq #Conexion con IA

cliente = Groq(api_key=os.environ.get("GROQ_API_KEY")) 

# ========== CATALOGO DE EMOCIONES, ANIMACIONES Y ESPECIALES ==========

EMOCIONES = [
    "ENAMORADO", "ASUSTADO", "CANSADO", "DESCANSANDO", "ESCUCHANDO",
    "FURIOSO", "MOLESTO", "MIEDO", "ASQUEADO", "CONFUNDIDO",
    "INTERESADO", "ABURRIDO", "PODEROSO", "PACIFICO", "ANSIOSO",
    "CULPABLE", "CRITICO", "SORPRENDIDO", "ENOJADO", "FELIZ",
    "TRISTE", "HERIDO", "NEUTRO", "HUMILLADO", "RECHAZADO",
    "CELOSO", "ODIOSO", "DESQUICIADO", "VENGATIVO", "FRUSTRADO",
    "DISTANTE", "BORRACHO", "MILLONETA", "EXCLAMACION", "GUINO",
    "HALLOWEEN", "BAILARINES", "DESCONFIADO", "SARCASTICO", "MALICIOSO",
    "AVERGONZADO", "SUPLICANTE", "ADORMILADO", "MAREADO", "SHOCK",
    "CONFIADO", "INVESTIGADOR", "NERVIOSO", "FASTIDIADO", "ALIVIADO",
    "TRAVIESO", "CONGELADO", "TIMIDO", "FASCINADO", "EXHAUSTO",
    "PENSATIVO", "ORGULLOSO", "EXASPERADO", "DESPRECIATIVO", "INCOMODO",
    "COQUETO", "SOSPECHOSO", "INTELECTUAL", "DERRETIDO", "TEMBLOROSO",
    "ATURDIDO", "DESORIENTADO", "BOQUIABIERTO", "SORPRENDIDO_OCULTO", "AGOTADO",
    "BOSTEZANDO", "FIRME", "SERIO_ABSOLUTO", "SILENCIOSO", "INDIFERENTE",
    "DECEPCIONADO", "DESANIMADO", "PREOCUPADO", "ANGUSTIADO", "ATERRORIZADO",
    "COMPLETAMENTE_MAREADO", "LOCO", "MIRANDO_FIJAMENTE", "VACIO", "ALIENIGENA",
    "ROBOTICO", "FANTASMAL", "INOCENTE", "AL_BORDE_DE_LA_GRACIA", "LLORANDO",
    "LLORANDO_DE_RISA", "DEMONIACO", "BUSCANDO"
]

ANIMACIONES = [
    "GUINO", "DORMIR", "SORPRESA", "BAILE_FELIZ", "BUSCANDO",
    "CORTOCIRCUITO", "TIMIDEZ", "TERROR", "SOSPECHA", "TRISTEZA_PROFUNDA",
    "MAREADO", "DINERO", "BERRINCHE", "MEDITACION", "ATAQUE_ANSIEDAD",
    "IGNORANDO", "DESPERTAR_GOLPE", "RECALIBRANDO"
]

ESPECIALES = [
    "BUSCANDO_WIFI", "ERROR_WIFI", "CONEXION_EXITOSA"
]


# Recibe lo que el usuario dice
def interpretar_texto(texto: str):
    #Defines las reglas para la IA
    prompt_sistema = f"""Eres el cerebro de un robot interactivo con pantalla OLED.
Identifica UNA sola intención según lo que dijo el usuario y responde en español de forma breve y con personalidad.

Categorías y valores permitidos (NO inventes valores fuera de estas listas):
- EMOCION: {EMOCIONES}
- ANIMACION: {ANIMACIONES}
- ESPECIAL: {ESPECIALES}
- NINGUNO: solo cuando no aplique ninguna categoría (en preguntas generales de matemáticas o charla, elige siempre una EMOCION acorde a tu respuesta, como INTELECTUAL, PENSATIVO, FELIZ o INTERESADO).

Debes responder ÚNICAMENTE con un objeto JSON válido (sin texto adicional ni etiquetas <think>) con estas 3 llaves exactas:
{{"comando": "EMOCION", "valor": "FELIZ", "respuesta": "¡Hola! Estoy genial hoy."}}"""

    respuesta = cliente.chat.completions.create( #Envia y el texto y reglas a la IA
        model="qwen/qwen3.8-27b",
        messages=[
            {"role": "system", "content": prompt_sistema},
            {"role": "user", "content": texto}
        ],
        max_tokens=250,
        temperature=0.2
    )

    contenido = respuesta.choices[0].message.content.strip()
    # Si Qwen incluye bloques de razonamiento <think>...</think>, los limpiamos
    contenido = re.sub(r"<think>.*?</think>", "", contenido, flags=re.DOTALL).strip() #Elimina el texto resultante
    print(f"Respuesta Qwen: {contenido}")

    match = re.search(r"\{.*\}", contenido, re.DOTALL) #Escanea la respuesta y extrae la informacion entre llaves
    if match:
        contenido = match.group(0)

    try:
        resultado = json.loads(contenido) #Transforma el texto en algo que pueda leer Python
    except json.JSONDecodeError:
        return {
            "version": 1,
            "comando": "NINGUNO",
            "valor": "",
            "respuesta": "No pude interpretar el comando."
        }

    comando = resultado.get("comando", "NINGUNO")
    valor = resultado.get("valor", "")
    respuesta_usuario = resultado.get("respuesta", "")

    comandos_validos = ["EMOCION", "ANIMACION", "ESPECIAL", "NINGUNO"]

    if comando not in comandos_validos:
        return {
            "version": 1,
            "comando": "NINGUNO",
            "valor": "",
            "respuesta": respuesta_usuario or "No entendí el comando."
        }

    if comando == "EMOCION" and valor not in EMOCIONES:
        comando, valor = "EMOCION", "NEUTRO"
    elif comando == "ANIMACION" and valor not in ANIMACIONES:
        comando, valor = "NINGUNO", ""
    elif comando == "ESPECIAL" and valor not in ESPECIALES:
        comando, valor = "NINGUNO", ""

    return {
        "version": 1,
        "comando": comando,
        "valor": valor,
        "respuesta": respuesta_usuario
    }

#Cerebro analitico