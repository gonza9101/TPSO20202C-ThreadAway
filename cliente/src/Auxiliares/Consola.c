/*
 * Consola.c
 *
 *  Created on: 6 sep. 2020
 *      Author: utnso
 */

#include "Consola.h"

//char* comandos_str[] = { "ejecutar", "status", "finalizar", "metricas", "salir", NULL };

bool validarPrimerParametro(char*);
int procesar_comando(char*);
void procesar_solicitud(char**);


void leer_consola(){
	char* line = readline(">");

	while(strcmp(line, "exit") != 0) {
			procesar_comando(line);
			free(line);
			line = readline(">");
	}
	free(line);
	terminar_programa(0);
}

void procesar_solicitud_app_restaurante(char** parametros){

	t_tipoMensaje tipo_mensaje = tipo_mensaje_string_to_enum(parametros[0]);
	log_info(logger, "Mensaje a enviar: %s\n", parametros[0]);

	switch(tipo_mensaje) {
		case CONSULTAR_RESTAURANTES:;
			enviar_mensaje_vacio(CONSULTAR_RESTAURANTES,socket_envio,logger);
			break;
		case SELECCIONAR_RESTAURANTE:;
			break;
		case OBTENER_RESTAURANTE:;
			break;
		case CONSULTAR_PLATOS:;
			break;
		case CREAR_PEDIDO:;
			break;
		case GUARDAR_PEDIDO:;
			break;
		case ANADIR_PLATO:;
			break;
		case GUARDAR_PLATO:;
			break;
		case CONFIRMAR_PEDIDO:;
			break;
		case PLATO_LISTO:;
			break;
		case CONSULTAR_PEDIDO:;
			break;
		case OBTENER_PEDIDO:;
			break;
		case FINALIZAR_PEDIDO:;
			break;
		case TERMINAR_PEDIDO:;
			break;
		default:;
			puts("No se reconoce el mensaje.\n");
			break;
	}
}

void procesar_solicitud_comanda_sindicato(char** parametros){

	t_tipoMensaje tipo_mensaje = tipo_mensaje_string_to_enum(parametros[0]);
	log_info(logger, "Mensaje a enviar: %s\n", get_nombre_mensaje(tipo_mensaje));

	int socket_bidireccional = conectar_a_server();

	switch(tipo_mensaje) {//TODO:FALTAN ALGUNOS DE SINDICATO

		case OBTENER_RESTAURANTE:;
			break;
		case CONSULTAR_PLATOS:;
			break;
		case GUARDAR_PEDIDO:{
			if (parametros[1]==NULL || parametros [2]==NULL){
				puts("Faltan parametros para enviar el mensaje\n");
				break;
			}
			t_guardar_pedido* msg_guardar_pedido = malloc(sizeof(t_guardar_pedido));
			strcpy(msg_guardar_pedido->restaurante, parametros[1]);
			msg_guardar_pedido->id_pedido = atoi(parametros[2]);
			log_info(logger, "Parametros a enviar: Restaurante: %s, ID_Pedido: %d", msg_guardar_pedido->restaurante, msg_guardar_pedido->id_pedido);
			enviar_guardar_pedido(msg_guardar_pedido, socket_bidireccional, logger);
			free(msg_guardar_pedido);
			t_tipoMensaje tipo_rta = recibir_tipo_mensaje(socket_bidireccional, logger);
			if (tipo_rta == RTA_GUARDAR_PEDIDO){
				uint32_t resultado = recibir_entero(socket_bidireccional, logger);
				log_info(logger, "Resultado recibido: %s",resultado? "OK":"FAIL");
			}
		}
		break;
		case GUARDAR_PLATO:{
			if (parametros[1]==NULL || parametros [2]==NULL || parametros[3]==NULL || parametros [4]==NULL){
				puts("Faltan parametros para enviar el mensaje\n");
				break;
			}
			t_guardar_plato* msg_guardar_plato = malloc(sizeof(t_guardar_plato));
			strcpy(msg_guardar_plato->restaurante, parametros[1]);
			msg_guardar_plato->id_pedido = atoi(parametros[2]);
			strcpy(msg_guardar_plato->plato, parametros[3]);
			msg_guardar_plato->cantPlato = atoi(parametros[4]);
			log_info(logger, "Parametros a enviar: Restaurante: %s, ID_Pedido: %d, Comida: %s, Cantidad: %d", msg_guardar_plato->restaurante, msg_guardar_plato->id_pedido, msg_guardar_plato->plato, msg_guardar_plato->cantPlato);
			enviar_guardar_plato(msg_guardar_plato, socket_bidireccional, logger);
			free(msg_guardar_plato);
			t_tipoMensaje tipo_rta = recibir_tipo_mensaje(socket_bidireccional, logger);
			if (tipo_rta == RTA_GUARDAR_PLATO){
				uint32_t resultado = recibir_entero(socket_bidireccional, logger);
				log_info(logger, "Resultado recibido: %s",resultado? "OK":"FAIL");
			}
		}
		break;
		case CONFIRMAR_PEDIDO:{
			if (parametros[1]==NULL || parametros [2]==NULL){
				puts("Faltan parametros para enviar el mensaje\n");
				break;
			}
			t_confirmar_pedido* msg_confirmar_pedido = malloc(sizeof(t_confirmar_pedido));
			strcpy(msg_confirmar_pedido->restaurante, parametros[2]);
			msg_confirmar_pedido->id_pedido = atoi(parametros[1]);
			log_info(logger, "Parametros a enviar: ID_Pedido: %d, Restaurante: %s", msg_confirmar_pedido->id_pedido, msg_confirmar_pedido->restaurante);
			enviar_confirmar_pedido(msg_confirmar_pedido, socket_bidireccional, logger);
			free(msg_confirmar_pedido);
			t_tipoMensaje tipo_rta = recibir_tipo_mensaje(socket_bidireccional, logger);
			if (tipo_rta == RTA_CONFIRMAR_PEDIDO){
				uint32_t resultado = recibir_entero(socket_bidireccional, logger);
				log_info(logger, "Resultado recibido: %s",resultado? "OK":"FAIL");
			}
		}
		break;
		case PLATO_LISTO:{
			if (parametros[1]==NULL || parametros [2]==NULL || parametros [3]==NULL){
				puts("Faltan parametros para enviar el mensaje\n");
				break;
			}
			t_plato_listo* msg_plato_listo = malloc(sizeof(t_plato_listo));
			strcpy(msg_plato_listo->restaurante, parametros[1]);
			msg_plato_listo->id_pedido = atoi(parametros[2]);
			strcpy(msg_plato_listo->plato, parametros[3]);
			log_info(logger, "Parametros a enviar: Restaurante: %s, ID_Pedido: %d, Comida: %s", msg_plato_listo->restaurante, msg_plato_listo->id_pedido, msg_plato_listo->plato);
			enviar_plato_listo(msg_plato_listo, socket_bidireccional, logger);
			free(msg_plato_listo);
			t_tipoMensaje tipo_rta = recibir_tipo_mensaje(socket_bidireccional, logger);
			if (tipo_rta == RTA_PLATO_LISTO){
				uint32_t resultado = recibir_entero(socket_bidireccional, logger);
				log_info(logger, "Resultado recibido: %s",resultado? "OK":"FAIL");
			}
		}
		break;
		case OBTENER_PEDIDO:{
			if (parametros[1]==NULL || parametros [2]==NULL){
				puts("Faltan parametros para enviar el mensaje\n");
				break;
			}
			t_obtener_pedido* msg_obtener_pedido = malloc(sizeof(t_obtener_pedido));
			strcpy(msg_obtener_pedido->restaurante, parametros[1]);
			msg_obtener_pedido->id_pedido = atoi(parametros[2]);
			log_info(logger, "Parametros a enviar: Restaurante: %s, ID_Pedido: %d", msg_obtener_pedido->restaurante, msg_obtener_pedido->id_pedido);
			enviar_obtener_pedido(msg_obtener_pedido, socket_bidireccional, logger);
			free(msg_obtener_pedido);
			t_tipoMensaje tipo_rta = recibir_tipo_mensaje(socket_bidireccional, logger);
			if (tipo_rta == RTA_OBTENER_PEDIDO){
				t_rta_obtener_pedido* respuesta = recibir_rta_obtener_pedido(socket_bidireccional, logger);
				log_info(logger, "Estado del pedido: %d", respuesta->estado);//TODO: FALTA QUE LO MUESTRE COMO STRING
				for(int i = 0; i < respuesta->cantComidas; i++){
					t_comida* comida_i = list_get(respuesta->comidas, i);
					log_info(logger, "Comida %d: %s, Cant. total: %d, Cant. lista: %d", i+1, comida_i->nombre, comida_i->cantTotal, comida_i->cantLista);
				}
				list_destroy_and_destroy_elements(respuesta->comidas, free);
				free(respuesta);
			}
		}
		break;
		case FINALIZAR_PEDIDO:{
			if (parametros[1]==NULL || parametros [2]==NULL){
				puts("Faltan parametros para enviar el mensaje\n");
				break;
			}
			t_finalizar_pedido* msg_finalizar_pedido = malloc(sizeof(t_finalizar_pedido));
			strcpy(msg_finalizar_pedido->restaurante, parametros[1]);
			msg_finalizar_pedido->id_pedido = atoi(parametros[2]);
			log_info(logger, "Parametros a enviar: Restaurante: %s, ID_Pedido: %d", msg_finalizar_pedido->restaurante, msg_finalizar_pedido->id_pedido);
			enviar_finalizar_pedido(msg_finalizar_pedido, socket_bidireccional, logger);
			free(msg_finalizar_pedido);
			t_tipoMensaje tipo_rta = recibir_tipo_mensaje(socket_bidireccional, logger);
			if (tipo_rta == RTA_FINALIZAR_PEDIDO){
				uint32_t resultado = recibir_entero(socket_bidireccional, logger);
				log_info(logger, "Resultado recibido: %s",resultado? "OK":"FAIL");
			}
		}
		break;
		case TERMINAR_PEDIDO:{
			if (parametros[1]==NULL || parametros [2]==NULL){
				puts("Faltan parametros para enviar el mensaje\n");
				break;
			}
			t_terminar_pedido* msg_terminar_pedido = malloc(sizeof(t_terminar_pedido));
			strcpy(msg_terminar_pedido->restaurante, parametros[1]);
			msg_terminar_pedido->id_pedido = atoi(parametros[2]);
			log_info(logger, "Parametros a enviar: Restaurante: %s, ID_Pedido: %d", msg_terminar_pedido->restaurante, msg_terminar_pedido->id_pedido);
			enviar_terminar_pedido(msg_terminar_pedido, socket_bidireccional, logger);
			free(msg_terminar_pedido);
			t_tipoMensaje tipo_rta = recibir_tipo_mensaje(socket_bidireccional, logger);
			if (tipo_rta == RTA_TERMINAR_PEDIDO){
				uint32_t resultado = recibir_entero(socket_bidireccional, logger);
				log_info(logger, "Resultado recibido: %s",resultado? "OK":"FAIL");
			}
		}
		break;
		case OBTENER_RECETA:;
			break;
		default:;
			puts("No se reconoce el mensaje.\n");
			break;
	}
	close(socket_bidireccional);
}

int procesar_comando(char *line){

	char** parametros = string_split(line, " ");

	if(!validarPrimerParametro(parametros[0])){
		printf("El servidor de %s no soporta el mensaje ingresado\n", get_nombre_proceso(tipo_proceso_server));
		liberar_lista(parametros);
		return -1;
	}

	procesar_solicitud(parametros);
	liberar_lista(parametros);

	return 0;
}

bool validarPrimerParametro(char* parametro){

	bool rta = true;

	if (parametro == NULL)
		rta = false;

	else{

		t_tipoMensaje mensaje = tipo_mensaje_string_to_enum(parametro);

		switch(tipo_proceso_server){

			case APP:
				if (mensaje != CONSULTAR_RESTAURANTES && mensaje != SELECCIONAR_RESTAURANTE && mensaje != CONSULTAR_PLATOS &&
					mensaje != CREAR_PEDIDO && mensaje != ANADIR_PLATO && mensaje != CONFIRMAR_PEDIDO && mensaje != PLATO_LISTO && mensaje != CONSULTAR_PEDIDO)
					rta = false;
				break;
			case COMANDA:
				if (mensaje != GUARDAR_PEDIDO && mensaje != GUARDAR_PLATO && mensaje != OBTENER_PEDIDO &&
					mensaje != CONFIRMAR_PEDIDO && mensaje != PLATO_LISTO && mensaje != FINALIZAR_PEDIDO)
					rta = false;
				break;
			case RESTAURANTE:
				if (mensaje != CONSULTAR_PLATOS && mensaje != CREAR_PEDIDO && mensaje != ANADIR_PLATO && mensaje != CONFIRMAR_PEDIDO && mensaje != CONSULTAR_PEDIDO)
					rta = false;
				break;
			case SINDICATO:
				if (mensaje != OBTENER_RESTAURANTE && mensaje != CONSULTAR_PLATOS && mensaje != GUARDAR_PEDIDO && mensaje != GUARDAR_PLATO
					&& mensaje != CONFIRMAR_PEDIDO && mensaje != PLATO_LISTO && mensaje != OBTENER_PEDIDO && mensaje != TERMINAR_PEDIDO && mensaje != OBTENER_RECETA)
					rta = false;
				break;
			default:
				rta = false;
		}

	}
	return rta;
}

void procesar_solicitud(char** parametros){
	if(tipo_proceso_server == APP || tipo_proceso_server == RESTAURANTE)
		procesar_solicitud_app_restaurante(parametros);
	else if(tipo_proceso_server == COMANDA || tipo_proceso_server == SINDICATO)
		procesar_solicitud_comanda_sindicato(parametros);
}

