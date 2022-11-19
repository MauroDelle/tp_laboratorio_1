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

/// @fn int menuModificarConfederacion()
/// @brief printeo que muestra el menu para modificar los campos de confederacion
///
/// @pre
/// @post
/// @return retorna la opcion seleccionada del menu
int menuModificarConfederacion();


/// @fn int listarConfederaciones(eConfederacion[], int)
/// @brief funcion que lista las confederaciones
/// @param confederaciones array de confederaciones
/// @param tam	tamanio del array de confederaciones
/// @return retorna un entero para saber si se pudo ejecutar correctamente
int listarConfederaciones(eConfederacion confederaciones[], int tam);


/// @fn int cargarDescripcionConfederaciones(eConfederacion[], int, int, char[])
/// @brief carga el nombre de las confederaciones
/// @param confederaciones array de confederaciones
/// @param tam	tamanio del array de confederaciones
/// @param id	recibe el id de la confederacion
/// @param nombre	recibe el nombre de la confederacion
/// @return retorna 0 si hay error
int cargarDescripcionConfederaciones(eConfederacion confederaciones[], int tam, int id, char nombre[]);

/// @fn int buscarConfederacion(eConfederacion[], int, int, int*)
/// @brief	busca confederacion por id
/// @param confederaciones array de confederaciones
/// @param tam	tamanio del array de confederaciones
/// @param id	recibe el id de la confederacion para realizar la busqueda
/// @return retorna 0 si hay error
int buscarConfederacion(eConfederacion confederaciones[], int tam, int id, int* pIndice);

/// @fn int validarConfederacion(eConfederacion[], int, int)
/// @brief	valida si hay espacio disponible
/// @param confederaciones array de confederaciones
/// @param tam	tamanio del array de confederacionesm
/// @param id	recibe la id de la confederacion
/// @return	retorna 0 si hay error
int validarConfederacion(eConfederacion confederaciones[],int tam, int id);

/// @fn int cargarNombreYRegion(eConfederacion[], int, int, char[], char[])
/// @brief	carga el string de nombre y region
/// @param confederaciones array de confederaciones
/// @param tam	tamanio del array de confederaciones
/// @param id	recibe el id de las confederaciones
/// @param nombre recibe el nombre de la confederacion
/// @param region recibe la region de la confederacion
/// @return retorna 0 si hay error
int cargarNombreYRegion(eConfederacion confederaciones[], int tam, int id,char nombre[], char region[]);

/// @fn int mostrarConfederacion(eConfederacion, int, eConfederacion[], int)
/// @brief	mustra una confederacion
/// @param e recibe la estructura confederacion
/// @param tam paso el tamanio de confederacion
/// @param confederaciones array de confederaciones
/// @param tam	tamanio del array de confederaciones
/// @return	retorna 0 si hay error
int mostrarConfederacion(eConfederacion e, int tam,eConfederacion confederaciones[],int tamC);

/// @fn int hardcodearConfederaciones(eConfederacion[], int, int, int*)
/// @brief	datos de confederacion hardcodeados
///
/// @pre
/// @post
/// @param vec array de la estructura confederaciones
/// @param tam tamanio del array de confederaciones
/// @param cant
/// @param pLegajo
/// @return	retorna 0 si hay error
int hardcodearConfederaciones(eConfederacion vec[], int tam, int cant,int* pLegajo);

/// @fn int modificarConfederacion(eConfederacion[], int)
/// @brief	funcion para modificar los campos de laestructura confederacion
///
/// @pre
/// @post
/// @param vec array de la estructura confederaciones
/// @param tam tamanio del array de confederaciones
/// @return	retorna 0 si hay error
int modificarConfederacion(eConfederacion vec[], int tam);
//alta

/// @fn int altaConfederacion(eConfederacion[], int, int*)
/// @brief	funcion para dar de alta una confederacion
///
/// @pre
/// @post
/// @param vec array de la estructura confederaciones
/// @param tam tamanio del array de confederaciones
/// @param pLegajo
/// @return	retorna 0 si hay error
int altaConfederacion(eConfederacion vec[], int tam, int* pLegajo);

/// @fn int inicializarConfederacion(eConfederacion[], int)
/// @brief	inicializa el arrayy de confederacion
///
/// @pre
/// @post
/// @param vec array de la estructura confederaciones
/// @param tam tamanio del array de confederaciones
/// @return	retorna 0 si hay error
int inicializarConfederacion(eConfederacion vec[],int tam);

/// @fn int buscarConfederacionLibre(eConfederacion[], int, int*)
/// @brief	busca si hay espacio libre en el array de confederacion
///
/// @pre
/// @post
/// @param vec array de la estructura confederaciones
/// @param tam tamanio del array de confederaciones
/// @param pIndex
/// @return	retorna 0 si hay error
int buscarConfederacionLibre(eConfederacion vec[], int tam, int* pIndex);
/// @fn int bajaConfederacion(eConfederacion[], int)
/// @brief	funcion que sirve para realizar la baja de una confederacion
///
/// @pre
/// @post
/// @param vec array de la estructura confederaciones
/// @param tam tamanio del array de confederaciones
/// @return	retorna 0 si hay error
int bajaConfederacion(eConfederacion vec[], int tam);


