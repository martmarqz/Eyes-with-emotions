#include "command_router.h"

#include "status.h"
#include "animation.h"

struct ComandoFuncion
{
    const char* nombre;
    void (*funcion)(void);
};

static const ComandoFuncion emociones[] =
{
    {"ENAMORADO", dibujar_ojos_enamorados},
    {"ASUSTADO", dibujar_ojos_asustados},
    {"CANSADO", dibujar_ojos_cansados},
    {"DESCANSANDO", dibujar_ojos_descansando},
    {"ESCUCHANDO", dibujar_ojos_escuchando},
    {"FURIOSO", dibujar_ojos_furiosos},
    {"MOLESTO", dibujar_ojos_molestos},
    {"MIEDO", dibujar_ojos_miedo},
    {"ASQUEADO", dibujar_ojos_asqueados},
    {"CONFUNDIDO", dibujar_ojos_confundidos},
    {"INTERESADO", dibujar_ojos_interesados},
    {"ABURRIDO", dibujar_ojos_aburridos},
    {"PODEROSO", dibujar_ojos_poderosos},
    {"PACIFICO", dibujar_ojos_pacificos},
    {"ANSIOSO", dibujar_ojos_ansiosos},
    {"CULPABLE", dibujar_ojos_culpables},
    {"CRITICO", dibujar_ojos_criticos},
    {"SORPRENDIDO", dibujar_ojos_sorprendidos},
    {"ENOJADO", dibujar_ojos_enojados},
    {"FELIZ", dibujar_ojos_felices},
    {"TRISTE", dibujar_ojos_tristes},
    {"HERIDO", dibujar_ojos_heridos},
    {"NEUTRO", dibujar_ojos_neutros},
    {"HUMILLADO", dibujar_ojos_humillados},
    {"RECHAZADO", dibujar_ojos_rechazados},
    {"CELOSO", dibujar_ojos_celosos},
    {"ODIOSO", dibujar_ojos_odiosos},
    {"DESQUICIADO", dibujar_ojos_desquiciados},
    {"VENGATIVO", dibujar_ojos_vengativos},
    {"FRUSTRADO", dibujar_ojos_frustrados},
    {"DISTANTE", dibujar_ojos_distantes},
    {"BORRACHO", dibujar_ojos_borrachos},
    {"MILLONETA", dibujar_ojos_dinero},
    {"EXCLAMACION", dibujar_ojos_exclamacion},
    {"GUINO", dibujar_ojos_guinando},

    {"HALLOWEEN", dibujar_ojos_halloween},
    {"BAILARINES", dibujar_ojos_bailarines},
    {"DESCONFIADO", dibujar_desconfiados},
    {"SARCASTICO", dibujar_sarcasticos},
    {"MALICIOSO", dibujar_maliciosos},
    {"AVERGONZADO", dibujar_avergonzados},
    {"SUPLICANTE", dibujar_suplicantes},
    {"ADORMILADO", dibujar_adormilados},
    {"MAREADO", dibujar_mareados},
    {"SHOCK", dibujar_en_shock},
    {"CONFIADO", dibujar_confiados},
    {"INVESTIGADOR", dibujar_investigadores},
    {"NERVIOSO", dibujar_nerviosos},
    {"FASTIDIADO", dibujar_fastidiados},
    {"ALIVIADO", dibujar_aliviados},
    {"TRAVIESO", dibujar_traviesos},
    {"CONGELADO", dibujar_congelados},
    {"TIMIDO", dibujar_timidos},
    {"FASCINADO", dibujar_fascinados},
    {"EXHAUSTO", dibujar_exhaustos},
    {"PENSATIVO", dibujar_pensativos},
    {"ORGULLOSO", dibujar_orgullosos},
    {"EXASPERADO", dibujar_exasperados},
    {"DESPRECIATIVO", dibujar_despreciativos},
    {"INCOMODO", dibujar_incomodos},
    {"COQUETO", dibujar_coquetos},
    {"SOSPECHOSO", dibujar_sospechosos},
    {"INTELECTUAL", dibujar_intelectuales},
    {"DERRETIDO", dibujar_derretidos},
    {"TEMBLOROSO", dibujar_temblorosos},
    {"ATURDIDO", dibujar_aturdidos},
    {"DESORIENTADO", dibujar_desorientados},
    {"BOQUIABIERTO", dibujar_boquiabiertos},
    {"SORPRENDIDO_OCULTO", dibujar_sorprendidos_ocultos},
    {"AGOTADO", dibujar_agotados},
    {"BOSTEZANDO", dibujar_bostezando},
    {"FIRME", dibujar_firmes},
    {"SERIO_ABSOLUTO", dibujar_serios_absolutos},
    {"SILENCIOSO", dibujar_silenciosos},
    {"INDIFERENTE", dibujar_indiferentes},
    {"DECEPCIONADO", dibujar_decepcionados},
    {"DESANIMADO", dibujar_desanimados},
    {"PREOCUPADO", dibujar_preocupados},
    {"ANGUSTIADO", dibujar_angustiados},
    {"ATERRORIZADO", dibujar_aterrorizados},
    {"COMPLETAMENTE_MAREADO", dibujar_completamente_mareados},
    {"LOCO", dibujar_locos},
    {"MIRANDO_FIJAMENTE", dibujar_mirando_fijamente},
    {"VACIO", dibujar_vacios},
    {"ALIENIGENA", dibujar_alienigenas},
    {"ROBOTICO", dibujar_roboticos},
    {"FANTASMAL", dibujar_fantasmales},
    {"INOCENTE", dibujar_inocentes},
    {"AL_BORDE_DE_LA_GRACIA", dibujar_al_borde_de_llorar},
    {"LLORANDO", dibujar_llorando},
    {"LLORANDO_DE_RISA", dibujar_llorando_de_risa},
    {"DEMONIACO", dibujar_ojos_demoniacos},
    {"BUSCANDO", dibujar_ojos_buscando}
};

static const ComandoFuncion animaciones[] =
{
    {"GUINO", guino},
    {"DORMIR", dormir},
    {"SORPRESA", sorpresa},
    {"BAILE_FELIZ", baile_feliz},
    {"BUSCANDO", buscando},
    {"CORTOCIRCUITO", cortocircuito},
    {"TIMIDEZ", timidez},
    {"TERROR", terror},
    {"SOSPECHA", sospecha},
    {"TRISTEZA_PROFUNDA", tristeza_profunda},
    {"MAREADO", mareado},
    {"DINERO", dinero},
    {"BERRINCHE", berrinche},
    {"MEDITACION", meditacion},
    {"ATAQUE_ANSIEDAD", ataque_ansiedad},
    {"IGNORANDO", ignorando},
    {"DESPERTAR_GOLPE", despertar_golpe},
    {"RECALIBRANDO", recalibrando}
};

static const ComandoFuncion especiales[] =
{
    {"BUSCANDO_WIFI", dibujar_buscando_wifi},
    {"ERROR_WIFI", dibujar_error_wifi},
    {"CONEXION_EXITOSA", dibujar_conexion_exitosa}
};

static bool buscar_y_ejecutar(const String& valor, const ComandoFuncion* lista, size_t cantidad)
{
    for(size_t i = 0; i < cantidad; i++)
    {
        if(valor.equalsIgnoreCase(lista[i].nombre))
        {
            lista[i].funcion();
            return true;
        }
    }

    return false;
}

bool ejecutar_comando(const String& comando, const String& valor)
{
    if(comando.equalsIgnoreCase("EMOCION"))
    {
        return buscar_y_ejecutar(valor, emociones, sizeof(emociones) / sizeof(emociones[0]));
    }

    if(comando.equalsIgnoreCase("ANIMACION"))
    {
        return buscar_y_ejecutar(valor, animaciones, sizeof(animaciones) / sizeof(animaciones[0]));
    }

    if(comando.equalsIgnoreCase("ESPECIAL"))
    {
        return buscar_y_ejecutar(valor, especiales, sizeof(especiales) / sizeof(especiales[0]));
    }

    return false;
}