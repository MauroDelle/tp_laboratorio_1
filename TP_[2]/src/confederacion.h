/*
 * confederacion.h
 *
 *  Created on: 13 oct. 2022
 *      Author: delle
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#ifndef CONFEDERACION_H_
#define CONFEDERACION_H_

typedef struct
{
	int id;
	char nombre[50];
	char region[50];
	int anioCreacion;
	int isEmpty;

}eConfederacion;


#endif /* CONFEDERACION_H_ */

int listarConfederaciones(eConfederacion confederaciones[], int tam);
int cargarDescripcionConfederaciones(eConfederacion confederaciones[], int tam, int id, char nombre[]);
int buscarConfederacion(eConfederacion confederaciones[], int tam, int id, int* pIndice);
int validarConfederacion(eConfederacion confederaciones[],int tam, int id);
int cargarNombreYRegion(eConfederacion confederaciones[], int tam, int id,char nombre[], char region[]);
int mostrarConfederacion(eConfederacion e, int tam,eConfederacion confederaciones[],int tamC);
int hardcodearConfederaciones(eConfederacion vec[], int tam, int cant,int* pLegajo);

//alta
int altaConfederacion(eConfederacion vec[], int tam, int* pLegajo);
int inicializarConfederacion(eConfederacion vec[],int tam);
int buscarConfederacionLibre(eConfederacion vec[], int tam, int* pIndex);
int bajaConfederacion(eConfederacion vec[], int tam);


