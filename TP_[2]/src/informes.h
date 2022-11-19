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
/// @fn int listarConfederacionesYJugadores(eJugador[], int, eConfederacion[], int)
/// @brief listado de confederaciones con sus jugadores
///
/// @pre
/// @post
/// @param vec
/// @param tam
/// @param confederaciones
/// @param tamC
/// @return	retorna 0 si hubo un error
int listarConfederacionesYJugadores(eJugador vec[], int tam,eConfederacion confederaciones[], int tamC);

/// @fn int primerListado(eJugador[], int, eConfederacion[], int, int)
/// @brief	funcion que realiza un listado alfabetico por nombre y confederacion
///
/// @pre
/// @post
/// @param jugadores
/// @param tamJ
/// @param confederaciones
/// @param tamC
/// @param order
/// @return	retorna 0 si hubo un error
int primerListado(eJugador jugadores[], int tamJ,eConfederacion confederaciones[], int tamC, int order);


/// @fn int confederacionMayorAniosContrato(eJugador[], int, eConfederacion[], int)
/// @brief	funcion que informa la confederacion con mayor cantidad de años de contratos total hay
///
/// @pre
/// @post
/// @param vec
/// @param tam
/// @param confederaciones
/// @param tamC
/// @return	retorna 0 si hubo un error
int confederacionMayorAniosContrato(eJugador vec[], int tam,eConfederacion confederaciones[], int tamC);


/// @fn int contador_porConfederacion(eJugador, eConfederacion[], int, int*)
/// @brief	funcion para contar jugadores por cada confederacion
///
/// @pre
/// @post
/// @param unJugador
/// @param listConfederacion
/// @param tamConf
/// @param contador
/// @return	retorna 0 si hubo un error
int contador_porConfederacion(eJugador unJugador,eConfederacion listConfederacion[], int tamConf, int* contador);


/// @fn int maximo_JugadoresPorConfederacion(eJugador[], int, eConfederacion[], int, int*)
/// @brief	funcion para saber el maximo de ugadores que hay en cada confedercion
///
/// @pre
/// @post
/// @param jugadores
/// @param tamJ
/// @param confederaciones
/// @param tamC
/// @param cantidadJugadores
/// @return	retorna 0 si hubo un error
int maximo_JugadoresPorConfederacion(eJugador jugadores[], int tamJ,eConfederacion confederaciones[],int tamC,int* cantidadJugadores);



/// @fn int calcularSalarios(eJugador[], int, eConfederacion[], int)
/// @brief	funcion para saber elk total y promedio de todos los salarios y cuanto jugadores cobran mas del salario promedio
///
/// @pre
/// @post
/// @param list
/// @param tam
/// @param confederaciones
/// @param tamC
/// @return	retorna 0 si hubo un error
int calcularSalarios(eJugador list[], int tam,eConfederacion confederaciones[], int tamC);


/// @fn int superanSueldoPromedio(eJugador[], int, float, eConfederacion[], int)
/// @brief	funcion para saber cuantos jguadores cobran mas del salario promedio
///
/// @pre
/// @post
/// @param list
/// @param tam
/// @param promedio
/// @param confederaciones
/// @param tamC
/// @return	retorna 0 si hubo un error
int superanSueldoPromedio(eJugador list[], int tam, float promedio,eConfederacion confederaciones[], int tamC);

/// @fn int porcentajeJugadoresXConfederacion(eJugador[], int, eConfederacion[], int)
/// @brief calcula el porcentaje de jugadores por cada una de las confederaciones
/// @param jugadores	le paso el array de la estructura jugadores
/// @param tam	le paso el tamanio de la estructura jugadores
/// @param confederaciones	le paso el array de la estructura confederacion
/// @param tamC	le paso el tamanio del array de la estructura confederacion
/// @return	retorna -1 si rompe y si no 1 si funciona
int porcentajeJugadoresXConfederacion(eJugador jugadores[], int tam, eConfederacion confederaciones[], int tamC);

/// @fn int contarCantidadJugadores(eJugador[], int, int, int*)
/// @brief
///
/// @pre
/// @post
/// @param jugadores
/// @param tam
/// @param id
/// @param cantidad
/// @return
int contarCantidadJugadores(eJugador jugadores[], int tam,int id,int* cantidad);
int sacarPorcentaje(int cant1,int cantidad2,float* retorno);
int cantJugadoresMayorConfederacion(eJugador jugadores[], int tam, int* cant);
int listarRegionMasJugadores(eJugador jugadores[], int tam, eConfederacion confederaciones[], int tamC);
int mostrar_Por_Id(eJugador jugadores[], int tam,eConfederacion tipos[], int tamT , int id);

#endif /* INFORMES_H_ */
