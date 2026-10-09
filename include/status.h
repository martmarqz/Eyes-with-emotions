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
    MILLONETA,
    EXCLAMACION
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
extern Emotion ojosFuriosos;
extern Emotion ojosFelices;
extern Emotion ojosBorrachos;
extern Emotion ojosAsustados;
extern Emotion ojosExclamacion;
extern Emotion ojosHeridos;
extern Emotion ojosMiedo;
extern Emotion ojosMolestos;
extern Emotion ojosEscuchando;
extern Emotion ojosAsqueados;
extern Emotion ojosConfundidos;
extern Emotion ojosInteresados;
extern Emotion ojosAburridos;
extern Emotion ojosPoderosos;
extern Emotion ojosPacificos;
extern Emotion ojosAnsiosos;
extern Emotion ojosCulpables;
extern Emotion ojosCriticos;
extern Emotion ojosEnojados;
extern Emotion ojosTristes;
extern Emotion ojosHumillados;
extern Emotion ojosRechazados;
extern Emotion ojosCelosos;
extern Emotion ojosOdiosos;
extern Emotion ojosDesquisiados;
extern Emotion ojosVengativos;
extern Emotion ojosFrustrados;
extern Emotion ojosDistantes;
extern Emotion ojosBailarin;
extern Emotion ojosHalloween;
extern Emotion ojosPesos;
extern Emotion ojosGuino;


//FUNCIONES
void actualizar_emocion(enum e_Emociones nuevo_estado);

#ifdef __cplusplus
}
#endif


#endif