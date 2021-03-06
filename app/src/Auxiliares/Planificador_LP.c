/*
 * Planificador_LP.c
 *
 *  Created on: 1 nov. 2020
 *      Author: utnso
 */


#include "Planificador_LP.h"

void* planificador_largo_plazo() {

	while(1) {

		sem_wait(&sem_repartidor_disponible);
		sem_wait(&sem_pedidos);

		pthread_mutex_lock(&mutex_nuevos);
		t_pcb* pcb = list_remove(pedidos_planificables, 0);
		pthread_mutex_unlock(&mutex_nuevos);
		t_repartidor* repartidor1 = repartidor_mas_cercano(pcb->restaurante_posX, pcb->restaurante_posY);

		asignar_repartidor(repartidor1, pcb);

		pthread_mutex_lock(&mutex_listos);
		list_add(listos, pcb);
		pthread_mutex_unlock(&mutex_listos);
		log_info(logger, "Repartidor N°%d | Pasa a READY | Asignado a pedido N°%d, Restaurante %s", pcb->id_repartidor, pcb->id_pedido, pcb->restaurante);

		sem_post(&sem_ready);

	}
}
