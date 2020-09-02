/*
 * Configuracion.h
 *
 *  Created on: 1 sep. 2020
 *      Author: utnso
 */

#ifndef AUXILIARES_CONFIGURACION_H_
#define AUXILIARES_CONFIGURACION_H_

#include <shared.h>
#include "Logueo.h"

// Definición de tipos
typedef struct {
	int tamanio_memoria;
	int tamanio_swap;
	char* algoritmo_reemplazo;
	int puerto_comanda;
	int frecuencia_compactacion;
	char* archivo_log;

} t_comanda_conf;

// Variables globales
t_config* config;
t_comanda_conf comanda_conf;


void cargar_configuracion_comanda(char *path_config);
void mostrar_propiedades();

#endif /* AUXILIARES_CONFIGURACION_H_ */
