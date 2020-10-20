/*
 ============================================================================
 Name        : sindicato.c
 Author      : thread_away
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "sindicato.h"

int main(int argc, char **argv) {

	puts("Inicio Proceso SINDICATO");

	/* 0. Setear config path */
	char* path_config = getConfigPath(argv[1]);

	/* 1. Configuración */
	cargarConfigSindicato(path_config);

	/* 2. Log */
	char* path_log = getLogPath(PATH_LOG);
	logger = configurar_logger(path_log, "sindicato");
	mostrar_propiedades();
	/* 3. File System */
	montarFileSystem();

	/* 4. Hilos */
	/* 4. Escuchando conexiones*/
	escuchar_conexiones_sindicato();
	crearHiloConsola();

//	destruir_config(config);
//	destruir_logger(logger);

	sleep(30);

	puts("Fin Proceso SINDICATO");
	return EXIT_SUCCESS;
}
