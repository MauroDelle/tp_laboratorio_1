/*
 * typePassenger.h
 *
 *  Created on: 22 abril. 2022
 *      Author: delle
 */

#ifndef TYPEPASSENGER_H_
#define TYPEPASSENGER_H_

typedef struct{

	int id;
	char descripcion[20];
}eTypeFlight;

#endif /* TYPEPASSENGER_H_ */


/// @brief modifica el typepassenger a string
/// @param type array de la estructura
/// @param tam tamanio del array
/// @param id un int de la id
/// @param descripcion char de lo q representa como strin g
/// @return devuelve -1 si hay un error
int cargarDescripcionStatusTypePassenger(eTypeFlight type[], int tam, int id,char descripcion[]);

/// @brief listado de id y descripcion
/// @param type array de la estructura
/// @param tam tamanio del array
/// @return devuelve -1 si hay un error
int listarTypePassenger(eTypeFlight type[], int tam);
