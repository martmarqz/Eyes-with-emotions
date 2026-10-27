COMANDOS = { #sabe cambiar una emoción en su pantalla OLED, ejecutar una animación o simplemente no hacer ninguna acción
    "EMOCION",
    "ANIMACION",
    "NINGUNO"
}

def crear_respuesta( #Crea una plantilla o molde para armar fácilmente los mensajes que se enviarán de regreso
    comando: str,
    valor: str,
    respuesta: str
):

    return { #Toma esos tres ingredientes y los empaqueta en una estructura ordenada que el microcontrolador puede leer de forma automática.
        "version": 1,
        "comando": comando,
        "valor": valor,
        "respuesta": respuesta
    }

#Libro de reglas