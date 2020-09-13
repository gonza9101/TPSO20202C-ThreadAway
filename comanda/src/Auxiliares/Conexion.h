/*
 * Conexion.h
 *
 *  Created on: 1 sep. 2020
 *      Author: utnso
 */

#ifndef AUXILIARES_CONEXION_H_
#define AUXILIARES_CONEXION_H_
#define IP_COMANDA "127.0.0.1"

#include <shared.h>
#include "Configuracion.h"

int socket_comanda;
int socket_cliente;

void escuchar_conexiones();

#endif /* AUXILIARES_CONEXION_H_ */
