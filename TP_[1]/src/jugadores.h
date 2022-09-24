/*
 * jugadores.h
 *
 *  Created on: 14 sep. 2022
 *      Author: delle
 */

#ifndef JUGADORES_H_
#define JUGADORES_H_
#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "utn.h"

/// @brief Esta funcion permite al usuario seleccionar que posicion
///            jugador quiere ingresar y contar cuantos son ingresador por cada case
///
/// @param contArq
/// @param contDef
/// @param contMed
/// @param contDel
/// @param AFC
/// @param CAF
/// @param CONCACAF
/// @param CONMEBOL
/// @param UEFA
/// @param OFC
/// @return Retorna la cantidad de jugadores y confederaciones ingresadas por separado
int carga_jugadores(int *contArq,  int *contDef, int *contMed, int *contDel, int *AFC, int *CAF,
		                                                                          int *CONCACAF,
																				  int *CONMEBOL,
																				  	  int *UEFA,
																					  int *OFC);
/// @brief Esta funcion permite tomar el numero de la camiseta y seleccionar que confederacion quiere ingresar
///
/// @param AFC
/// @param CAF
/// @param CONCACAF
/// @param CONMEBOL
/// @param UEFA
/// @param OFC
void carga_Confederaciones(int *AFC, int *CAF, int *CONCACAF, int *CONMEBOL,int *UEFA, int *OFC);


#endif /* JUGADORES_H_ */
