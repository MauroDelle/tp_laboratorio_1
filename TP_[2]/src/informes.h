/*
 * informes.h
 *
 *  Created on: 29 oct. 2022
 *      Author: delle
 */
#include "confederacion.h"
#include <ctype.h>
#include <string.h>
#include "jugador.h"
#ifndef INFORMES_H_
#define INFORMES_H_

//informes

int listarConfederacionesYJugadores(eJugador vec[], int tam,eConfederacion confederaciones[], int tamC);
int cantidadJugadoresConfederacion(eJugador vec[], int tam,eConfederacion confederaciones[], int tamC);

int primerListado(eJugador jugadores[], int tamJ,eConfederacion confederaciones[], int tamC, int order);
int confederacionMayorAniosContrato(eJugador vec[], int tam,eConfederacion confederaciones[], int tamC);
int contador_porConfederacion(eJugador unJugador,eConfederacion listConfederacion[], int tamConf, int* contador);
int maximo_JugadoresPorConfederacion(eJugador jugadores[], int tamJ,eConfederacion confederaciones[],int tamC,int* cantidadJugadores);



int calcularSalarios(eJugador list[], int tam,eConfederacion confederaciones[], int tamC);
int superanSueldoPromedio(eJugador list[], int tam, float promedio,eConfederacion confederaciones[], int tamC);

#endif /* INFORMES_H_ */
