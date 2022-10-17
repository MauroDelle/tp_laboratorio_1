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

int listarConfederaciones(eConfederacion confederaciones[], int tam);
int cargarDescripcionConfederaciones(eConfederacion confederaciones[], int tam, int id, char nombre[]);
int buscarConfederacion(eConfederacion confederaciones[], int tam, int id, int* pIndice);
int validarConfederacion(eConfederacion confederaciones[],int tam, int id);
