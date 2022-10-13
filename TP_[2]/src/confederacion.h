/*
 * confederacion.h
 *
 *  Created on: 13 oct. 2022
 *      Author: delle
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef CONFEDERACION_H_
#define CONFEDERACION_H_

typedef struct
{
	int id;
	char nombre[50];
	char region[50];
	int anioCreacion;

}eConfederacion;


#endif /* CONFEDERACION_H_ */

int cargarDescripcionConfederacion(eConfederacion list[], int tam, int id, char nombre[], char region[]);
int buscarConfederacion(eConfederacion list[], int tam, int id, int *pIndice);
int listarConfederacion(eConfederacion list[], int tam);
int validarConfederacion(eConfederacion list[], int tam, int id);
