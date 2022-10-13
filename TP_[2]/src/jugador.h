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
	int idConfederacion;
	float salario;
	int aniosContrato;
	int isEmpty;

}eJugador;

#endif /* JUGADOR_H_ */
int altaJugador(eJugador vec[], int tam,eConfederacion list[], int tamConf, int* pId);
int inicializarJugadores(eJugador list[], int tam);
int buscarJugadorLibre(eJugador list[], int tam, int* pIndex);
int buscarJugador(eJugador list[], int tam, int id, int *pIndex);
int hardcodearJugadores(eJugador list[], int tam, int cant, int* pId);
int mostrarJugador(eJugador e, eConfederacion list[], int tam);
int listarJugadores(eJugador vec[], int tam, eConfederacion list[], int tamConf);
