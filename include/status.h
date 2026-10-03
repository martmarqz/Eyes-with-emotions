#ifndef STATUS_H
#define STATUS_H

#ifdef __cplusplus
extern "C" {
#endif

//ENUMS

enum e_Emociones
{
    ENAMORADO,
    ASUSTADO,
    CANSADO,
    DESCANSANDO,
    ESCUCHANDO,
    FURIOSO,
    MOLESTO,
    MIEDO,
    ASQUEADO,
    CONFUNDIDO,
    INTERESADO,
    ABURRIDO,
    PODEROSO,
    PACIFICO,
    ANSIOSO,
    CULPABLE,
    CRITICO,
    SORPRENDIDO,
    ENOJADO,
    FELIZ,
    TRISTE,
    HERIDO,
    NEUTRO,
    HUMILLADO,
    RECHAZADO,
    CELOSO,
    ODIOSO,
    DESQUICIADO, 
    VENGATIVO,
    FRUSTRADO,
    DISTANTE,
    BORRACHO,
    BAILARIN,
    HALLOWEEN,
};

//STRUCTS
struct s_Emotion
{
    int ojoDerecho[8][8];
    int ojoIzquierdo[8][8];
    int volumenAltavoz;

}; typedef struct s_Emotion Emotion;

//VARIABLES EXTERNAS PARA QUE LAS LEA C++
extern Emotion ojosNeutros;
extern Emotion ojosDescansando;
extern Emotion ojosEnamorados;
extern Emotion ojosCansados;
extern Emotion ojosSorprendidos;

//PROTOTIPO FUNCIONES
void actualizar_emocion(enum e_Emociones nuevo_estado);

#ifdef __cplusplus
}
#endif


#endif