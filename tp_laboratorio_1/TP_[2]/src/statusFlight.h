/*
 * statusFlight.h
 *
 *  Created on: 22 abril. 2022
 *      Author: delle
 */

#ifndef STATUSFLIGHT_H_
#define STATUSFLIGHT_H_

typedef struct{

	int id;
	char descripcion[20];
}eStatusFlight;

#endif /* STATUSFLIGHT_H_ */



/// @brief listado de id's y descripcion
/// @param status array de los tipos de pasajeros
/// @param tam tamanio del array
/// @return devuelve -1 si hay un error
int listarStatusFlight(eStatusFlight status[], int tam);

/// @brief modifica el status de fligh a string
/// @param status array de la estructura
/// @param tam tamanio del array
/// @param id int la id que representa
/// @param descripcion char lo qye representa como string
/// @return deveuelve -1 si hay un error
int cargarDescripcionStatus(eStatusFlight status[], int tam, int id,char descripcion[]);
