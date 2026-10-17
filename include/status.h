#ifndef STATUS_H
#define STATUS_H

#ifdef __cplusplus
extern "C" {
#endif

// ENUM y STRUCTS

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
    EXCLAMACION,
    GUINO
};

//FUNCIONES
void dibujar_mirada_reojo(void);
void dibujar_ojos_descansando(void);
void dibujar_ojos_escuchando(void);
void dibujar_ojos_asqueados(void);
void dibujar_ojos_enamorados(void);
void dibujar_ojos_cansados(void);
void dibujar_ojos_sorprendidos(void);
void dibujar_ojos_neutros(void);
void dibujar_ojos_felices(void);
void dibujar_ojos_borrachos(void);
void dibujar_ojos_asustados(void);
void dibujar_ojos_furiosos(void);
void dibujar_ojos_exclamacion(void);
void dibujar_ojos_heridos(void);
void dibujar_ojos_miedo(void);
void dibujar_ojos_molestos(void);
void dibujar_ojos_confundidos(void);
void dibujar_ojos_interesados(void);
void dibujar_ojos_aburridos(void);
void dibujar_ojos_poderosos(void);
void dibujar_ojos_pacificos(void);
void dibujar_ojos_ansiosos(void);
void dibujar_ojos_culpables(void);
void dibujar_ojos_tristes(void);
void dibujar_ojos_humillados(void);
void dibujar_ojos_rechazados(void);
void dibujar_ojos_celosos(void);
void dibujar_ojos_odiosos(void);
void dibujar_ojos_desquiciados(void);
void dibujar_ojos_vengativos(void);
void dibujar_ojos_frustrados(void);
void dibujar_ojos_distantes(void);
void dibujar_ojos_dinero(void);
void dibujar_ojos_guinando(void);
void dibujar_ojos_halloween(void);
void dibujar_ojos_bailarines(void);
void dibujar_desconfiados(void);
void dibujar_sarcasticos(void);
void dibujar_maliciosos(void);
void dibujar_avergonzados(void);
void dibujar_suplicantes(void);
void dibujar_adormilados(void);
void dibujar_mareados(void);
void dibujar_en_shock(void);
void dibujar_confiados(void);
void dibujar_investigadores(void);
void dibujar_nerviosos(void);
void dibujar_fastidiados(void);
void dibujar_aliviados(void);
void dibujar_traviesos(void);
void dibujar_congelados(void);
void dibujar_timidos(void);
void dibujar_fascinados(void);
void dibujar_exhaustos(void);
void dibujar_pensativos(void);
void dibujar_orgullosos(void);
void dibujar_exasperados(void);
void dibujar_despreciativos(void);
void dibujar_incomodos(void);
void dibujar_coquetos(void);
void dibujar_sospechosos(void);
void dibujar_intelectuales(void);
void dibujar_derretidos(void);
void dibujar_temblorosos(void);
void dibujar_aturdidos(void);
void dibujar_desorientados(void);
void dibujar_boquiabiertos(void);
void dibujar_sorprendidos_ocultos(void);
void dibujar_agotados(void);
void dibujar_bostezando(void);
void dibujar_firmes(void);
void dibujar_serios_absolutos(void);
void dibujar_silenciosos(void);
void dibujar_indiferentes(void);
void dibujar_decepcionados(void);
void dibujar_desanimados(void);
void dibujar_preocupados(void);
void dibujar_angustiados(void);
void dibujar_aterrorizados(void);
void dibujar_completamente_mareados(void);
void dibujar_locos(void);
void dibujar_mirando_fijamente(void);
void dibujar_vacios(void);
void dibujar_alienigenas(void);
void dibujar_roboticos(void);
void dibujar_fantasmales(void);
void dibujar_inocentes(void);
void dibujar_al_borde_de_llorar(void);
void dibujar_llorando(void);
void dibujar_llorando_de_risa(void);
void dibujar_ojos_demoniacos(void);
void dibujar_ojos_desquiciados(void);
void dibujar_ojos_enojados(void);
void dibujar_ojos_criticos(void);

void dibujar_ojos_buscando(void);
void dibujar_buscando_wifi(void);
void dibujar_error_wifi(void);
void dibujar_conexion_exitosa(void);

void actualizar_emocion(enum e_Emociones nuevo_estado);

enum e_Emociones obtener_emocion(void);

#ifdef __cplusplus
}
#endif

#endif
