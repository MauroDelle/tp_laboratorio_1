/*
 * jugador.h
 *
 *  Created on: 13 oct. 2022
 *      Author: delle
 */
#define TAMC 6
#define TAM 22
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
/// @fn int altaJugador(eJugador[], int, eConfederacion[], int, int*)
/// @brief funcion en la que le permite al usuario dar de alta un nuevo jugador
/// @param vec array de la estructura eJugador
/// @param tam tamanio del array de eJugador
/// @param confederaciones array de la estructura eConfederacion
/// @param tamConf tamanio del array de la estuctura eConfederacion
/// @param pLegajo puntero al que se le pasa el proximo id
/// @return	retorna un booleano para saber si pudo ejecutarse o no
int altaJugador(eJugador vec[],int tam, eConfederacion confederaciones[], int tamConf, int* pLegajo);

/// @fn int bajaJugador(eJugador[], int, eConfederacion[], int)
/// @brief funcion en la que le permite al usuario dar de baja a un jugador existente
/// @param vec array de la estructura eJugador
/// @param tam tamanio del array de eJugador
/// @param confederaciones array de la estructura eConfederacion
/// @param tamConf tamanio del array de la estuctura eConfederacion
/// @return retorna un booleano para saber si pudo ejecutarse o no
int bajaJugador(eJugador vec[], int tam, eConfederacion confederaciones[], int tamC);

/// @fn int modificarJugador(eJugador[], int, eConfederacion[], int)
/// @brief funcion en la que le permite al usuario modificar los campos de la estructura jugador
/// @param vec array de la estructura eJugador
/// @param tam tamanio del array de eJugador
/// @param confederaciones array de la estructura eConfederacion
/// @param tamConf tamanio del array de la estuctura eConfederacion
/// @return retorna un booleano para saber si pudo ejecutarse o no
int modificarJugador(eJugador vec[], int tam, eConfederacion confederaciones[],int tamC);

/// @fn int inicializarJugador(eJugador[], int)
/// @brief inicializo al jugador
/// @param vec array de la estructura eJugador
/// @param tam tamanio del array de eJugador
/// @return retorna 0 si hay error.
int inicializarJugador(eJugador vec[], int tam);

/// @fn int buscarJugadorLibre(eJugador[], int, int*)
/// @brief Recorre el array y busca un espacio libre
/// @param vec array de la estructura eJugador
/// @param tam tamanio del array de eJugador
/// @param pIndex
/// @return retorna 0 si hay error.
int buscarJugadorLibre(eJugador vec[], int tam, int* pIndex);

/// @fn int buscarJugador(eJugador[], int, int, int*)
/// @brief Busca un pasajero por su id
/// @param vec array de la estructura eJugador
/// @param tam tamanio del array de eJugador
/// @param legajo
/// @param pIndex
/// @return retorna 0 si hay error.
int buscarJugador(eJugador vec[], int tam,int legajo, int *pIndex);

/// @fn int hardcodearJugadores(eJugador[], int, int, int*)
/// @brief funcion en la que se hardcodean jugadores para la prueba de informes
/// @param vec array de la estructura eJugador
/// @param tam tamanio del array de eJugador
/// @param cant
/// @param pLegajo
/// @return retorna 0 si hay error.
int hardcodearJugadores(eJugador vec[], int tam, int cant, int* pLegajo);

/// @fn int mostrarJugador(eJugador, eConfederacion[], int)
/// @brief	funcion que printea un jugador
/// @param e
/// @param confederaciones
/// @param tam
/// @return retorna 0 si hay error.
int mostrarJugador(eJugador e,eConfederacion confederaciones[],int tam);

/// @fn int listarJugador(eJugador[], int, eConfederacion[], int)
/// @brief funcion que lista los jugadores
/// @param vec array de la estructura eJugador
/// @param tam tamanio del array de eJugador
/// @param confederaciones
/// @param tamConf
/// @return retorna 0 si hay error.
int listarJugador(eJugador vec[], int tam, eConfederacion confederaciones[], int tamConf);
