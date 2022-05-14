/*
 * ArrayPassenger.h
 *
 *  Created on: 22 abril. 2022
 *      Author: delle
 */
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

#include "utn.h"
#include "statusFlight.h"
#include "typePassenger.h"



typedef struct{
	int id;
	char name[51];
	char lastName[51];
	float price;
	char flycode[10];
	int typePassenger;
	int statusFlight;
	int isEmpty;
}ePassenger;

#endif /* ARRAYPASSENGER_H_ */



/// \brief Inicializo pasajero.
/// \param le paso el array de la estructura a recorrer.
/// \param le paso el tamanio del array
/// \return retorna -1 si hay error.
int initPassanger(ePassenger list[], int tam);


/// \brief Recorre el array y busca un espacio libre
/// \param le paso el array de la estructura a recorrer
/// \param le paso el tamanio del array
/// \return retorna -1 si hay error
int searchFreeSpacePassenger(ePassenger list[], int len);

/// \brief Agrega un array de Passanger.
/// \param list le paso el array de la estructura a recorrer
/// \param len El tamanio del array
/// \param name variable para guardar un dato string en la estructura
/// \param lastName  variable para guardar un dato string en la estructura
/// \param price variable flotante para guardar el dato Precio en la estructura de Employee
/// \param flycode variable char para guardar el dato flycode en la estructura de Employee
/// \param typePassenger variable int  para guardar el tipo de pasajero en la estructura
/// \param statusFlight variable entera para guardar el estado de vuelo
/// \param id variable id es un puntero*
/// \param status el array de estatus de la estructura eStatusF
/// \param tam_status una variable int array de tamanio
/// \param typePassenger2 es una variable tipo puntero al array de los tipos de pasajeros
/// \param tamPassenger el array tamanio
/// \return devuelve -1 si hay un error
int addPassenger(ePassenger* list,int len,char name[],char lastName[],float price,char flycode[],int typePassenger,int statusFlight,int id,eStatusFlight status[], int tam_status,eTypeFlight typePassenger2[],int tamPassenger);

/// @brief Busca un pasajero por su id
/// @param list array pasajero
/// @param len int tamanio array pasajero
/// @param id id ingresada para buscar
/// @return -devuelve -1 si hay un error
int findPassengerById(ePassenger list[], int len,int pId,int* pIndex);

/// @brief Borra a un pasajero en base a la id ingresada
/// @param list array pasajeros
/// @param len tamanio array pasajeros
/// @param id id ingresada para buscar
/// @param status array de la estructura eStatusF
/// @param tam_status tamanio array de estructura eStatusF
/// @param typePassenger2 array tipo de pasajeros
/// @param tamPassenger tamanio array typePasenger
/// @return devuelve -1 si hay un error
int removePassenger(ePassenger list[],int len,int id,eStatusFlight status[],int tam_status,eTypeFlight typePassenger[],int tamPassenger);

/// @brief modifica pasajero
/// @param list array pasajero
/// @param len tamanio array pasajeros
/// @param status array de la estructura eStatusF
/// @param tam_status tamanio array de estructura eStatusF
/// @param typePassenger2 array tipo de pasajeros
/// @param tamPassenger tamanio array typePasenger
/// @return devuelve -1 si hay un error
int modifyPassenger(ePassenger list[], int len,eStatusFlight status[], int tam_status,eTypeFlight typePassenger2[],int tamPassenger);


/// @brief se hardcodean los pasajeros
/// @param list array pasajeros
/// @param len tamanio array pasajeros
/// @param cant cant de pasajeros del menu
/// @param id puntero de las ids
/// @return devuelve -1 si hay un error
int altaForzadaPassengers(ePassenger* list, int len, int cant,int* id);


/// @brief ordena array de pasajeros
/// @param list array pasajeros
/// @param len tamanio array pasajeros
/// @param order criterio de ordenamiento
/// @return devuelve -1 si hay un error
int sortPassengers(ePassenger* list, int len, int order);

/// @brief menu de ordenamientos
/// @param list array pasajeros
/// @param len tamanio array pasajeros
/// @param status eStatusFlight al array de status
/// @param tam_status int array tamaño
/// @param typePassenger2 punterero al array de typePass-
/// @param tamPassenger tamanio array
/// @return devuelve -1 si hay error
int submenueInform(ePassenger list[],int len,eStatusFlight status[], int tam_status,eTypeFlight typePassenger[],int tamPassenger);


/// @brief muestra la documentacion de un pasajero
/// @param list array de pasajeros
/// @param status status del array eStatusFlight
/// @param tam_status int array tamaño
/// @param typePassenger2 array de tipo de pasajeros
/// @param tamPassenger tamanio del array
void showOnePassenger(ePassenger list,eStatusFlight status[],int tam,eTypeFlight typePassenger[],int tamPassenger);


/// @brief Muestra el array de pasajeros
/// @param list array de la estructura
/// @param len tamanio del array
/// @param status eStatusFlight statusd e array eStatusFlight
/// @param tam_status tamanio del array
/// @param typePassenger2 array del tipo de pasajero
/// @param tamPassenger tamanio del array
/// @return devuelve -1 si hay errork
void printPassengers(ePassenger list[], int len,eStatusFlight status[],int tam_status,eTypeFlight typePassenger[],int tamPassenger);

/// @brief Ordena el array de pasajeros por PRECIO DE VUELO
/// @param  list Muestra el array de pasajeros
/// @param len tamanio del array
/// @param order int criterio de ordenamiento
/// @param status eStatusFlight al array de status
/// @param tam_status tamanio del array
/// @param typePassenger2 PUNTERO al array de tipos de pasajeros
/// @param tamPassenger tamanio del array
/// @return devuelve -1 si hay error
int informPrice(ePassenger list[],int len,float* acumPrecio,int* cantPassengers, int* contPassengerSuperior,float* promedioPrecios);

/// @brief Ordena el array de pasajeros por codigo de vuelo y estado de vuelo
/// @param list  Muestra el array de pasajeros
/// @param len tamanio del array
/// @param order int criterio de ordenamiento
/// @param status eStatusFlight al array de status
/// @param tam_status tamanio del array
/// @param typePassenger2 PUNTERO al array de tipos de pasajeros
/// @param tamPassenger tamanio del array
/// @return devuelve -1 si hay error
int sortPassengersByCode(ePassenger* list,int len,eStatusFlight status[],int tam_status,eTypeFlight typePassenger[],int tamPassenger,int order);
