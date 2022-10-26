/*
 * jugador.h
 *
 *  Created on: 13 oct. 2022
 *      Author: delle
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "confederacion.h"
#ifndef JUGADOR_H_
#define JUGADOR_H_

typedef struct
{
	int id;
	char nombre[50];
	char posicion[50];
	int numeroCamiseta;
	float salario;
	int idConfederacion;
	int aniosContrato;
	int isEmpty;

}eJugador;

#endif /* JUGADOR_H_ */

int altaJugador(eJugador vec[],int tam, eConfederacion confederaciones[], int tamConf, int* pLegajo);
int bajaJugador(eJugador vec[], int tam, eConfederacion confederaciones[], int tamC);
int modificarJugador(eJugador vec[], int tam, eConfederacion confederaciones[],int tamC);


int inicializarJugador(eJugador vec[], int tam);
int buscarJugadorLibre(eJugador vec[], int tam, int* pIndex);
int buscarJugador(eJugador vec[], int tam,int legajo, int *pIndex);


int mostrarJugador(eJugador e,eConfederacion confederaciones[],int tam);
int listarJugador(eJugador vec[], int tam, eConfederacion confederaciones[], int tamConf);



