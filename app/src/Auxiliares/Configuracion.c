/*
 * Configuracion.c
 *
 *  Created on: 10 sep. 2020
 *      Author: utnso
 */

#include "Configuracion.h"

void cargar_configuracion_app(char * path_config) {
	config = config_create(path_config);

	if (!config_has_property(config, "IP_APP"))
		error_show("Error al cargar IP_APP de archivo de configuracion");

	if (!config_has_property(config, "PUERTO_ESCUCHA"))
		error_show("Error al cargar PUERTO_ESCUCHA de archivo de configuracion");

	if (config_has_property(config, "IP_COMANDA")) {
		app_conf.ip_comanda = config_get_string_value(config, "IP_COMANDA");
	} else {
		error_show("Error al cargar IP_COMANDA de archivo de configuracion");
	}
	if (config_has_property(config, "PUERTO_COMANDA")) {
		app_conf.puerto_comanda = config_get_string_value(config, "PUERTO_COMANDA");
	} else {
		error_show("Error al cargar PUERTO_COMANDA de archivo de configuracion");
	}
	if (config_has_property(config, "RETARDO_CICLO_CPU")) {
		app_conf.retardo_ciclo_cpu = config_get_int_value(config, "RETARDO_CICLO_CPU");
	} else {
		error_show("Error al cargar RETARDO_CICLO_CPU de archivo de configuracion");
	}
	if (config_has_property(config, "GRADO_DE_MULTIPROCESAMIENTO")) {
		app_conf.grado_multiprocesamiento = config_get_int_value(config, "GRADO_DE_MULTIPROCESAMIENTO");
	} else {
		error_show("Error al cargar GRADO_DE_MULTIPROCESAMIENTO de archivo de configuracion");
	}
	if (config_has_property(config, "ALGORITMO_DE_PLANIFICACION")) {
		app_conf.algoritmo_planificacion = config_get_string_value(config, "ALGORITMO_DE_PLANIFICACION");
	} else {
		error_show("Error al cargar ALGORITMO_DE_PLANIFICACION de archivo de configuracion");
	}
	if (config_has_property(config, "ALPHA")) {
		app_conf.alpha = config_get_double_value(config, "ALPHA");
	} else {
		error_show("Error al cargar ALPHA de archivo de configuracion");
	}
	if (config_has_property(config, "ESTIMACION_INICIAL")) {
		app_conf.estimacion_inicial = config_get_double_value(config, "ESTIMACION_INICIAL");
	} else {
		error_show("Error al cargar ESTIMACION_INICIAL de archivo de configuracion");
	}
	if (config_has_property(config, "REPARTIDORES")) {
		app_conf.repartidores = config_get_array_value(config, "REPARTIDORES");
	} else {
		error_show("Error al cargar REPARTIDORES de archivo de configuracion");
	}
	if (config_has_property(config, "FRECUENCIA_DE_DESCANSO")) {
		app_conf.frecuencias_descanso = config_get_array_value(config, "FRECUENCIA_DE_DESCANSO");
	} else {
		error_show("Error al cargar FRECUENCIA_DE_DESCANSO de archivo de configuracion");
	}
	if (config_has_property(config, "TIEMPO_DE_DESCANSO")) {
		app_conf.tiempos_descanso = config_get_array_value(config, "TIEMPO_DE_DESCANSO");
	} else {
		error_show("Error al cargar TIEMPO_DE_DESCANSO de archivo de configuracion");
	}
	if (!config_has_property(config, "ARCHIVO_LOG"))
		error_show("Error al cargar ARCHIVO_LOG de archivo de configuracion");

	if (config_has_property(config, "PLATOS_DEFAULT")) {
		app_conf.platos_default = config_get_array_value(config, "PLATOS_DEFAULT");
	} else {
		error_show("Error al cargar PLATOS_DEFAULT de archivo de configuracion");
	}
	if (config_has_property(config, "POSICION_REST_DEFAULT_X")) {
		app_conf.pos_rest_default_x = config_get_int_value(config, "POSICION_REST_DEFAULT_X");
	} else {
		error_show("Error al cargar POSICION_REST_DEFAULT_X de archivo de configuracion");
	}
	if (config_has_property(config, "POSICION_REST_DEFAULT_Y")) {
		app_conf.pos_rest_default_y = config_get_int_value(config, "POSICION_REST_DEFAULT_Y");
	} else {
		error_show("Error al cargar POSICION_REST_DEFAULT_Y de archivo de configuracion");
	}
	free(path_config);
}

void cargar_logger_app() {
	int carpeta_creada;

	carpeta_creada = crear_carpeta_log(config_get_string_value(config, "ARCHIVO_LOG"));
	if (carpeta_creada){
		logger = log_create(config_get_string_value(config, "ARCHIVO_LOG"), "App", 0, LOG_LEVEL_TRACE);
		log_trace(logger, "*************** NUEVO LOG ***************");
	}
	else{
		puts("Error al crear la carpera del log");
		exit(2);
	}
}

void mostrar_propiedades() {

	log_trace(logger,"Propiedades cargadas:");
	log_trace(logger,"\tPuerto escucha: %s.", config_get_string_value(config, "PUERTO_ESCUCHA"));
	log_trace(logger,"\tIP comanda: %s.", app_conf.ip_comanda);
	log_trace(logger,"\tPuerto comanda: %s.", app_conf.puerto_comanda);
	log_trace(logger,"\tGrado multiprocesamiento: %d.", app_conf.grado_multiprocesamiento);
	log_trace(logger,"\tAlgoritmo planificacion: %s.", app_conf.algoritmo_planificacion);
	log_trace(logger,"\tAlpha: %f.", app_conf.alpha);
	log_trace(logger,"\tEstimacion inicial: %d.", app_conf.estimacion_inicial);
	log_trace(logger,"\tArchivo log: %s.", config_get_string_value(config, "ARCHIVO_LOG"));
	log_trace(logger,"\tPos rest. default X: %d.", app_conf.pos_rest_default_x);
	log_trace(logger,"\tPos rest. default Y: %d.", app_conf.pos_rest_default_y);
	int i=0;
	while(app_conf.repartidores[i]){
		log_trace(logger, "\tREPARTIDOR %d: Posicion:%s, Frecuencia descanso:%s, Tiempo descanso:%s.",i+1,app_conf.repartidores[i],app_conf.frecuencias_descanso[i],app_conf.tiempos_descanso[i]);
		i++;
	}
	int j=0;
	while(app_conf.platos_default[j]){
		log_trace(logger, "\tPlato default: %s.", app_conf.platos_default[j]);
		j++;
	}
}
