/*
 * costos.h
 *
 *  Created on: 13 sep. 2022
 *      Author: delle
 */

#ifndef COSTOS_H_
#define COSTOS_H_
#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "utn.h"


/// @brief  Esta funcion toma los valores de hospedaje, comida y transporte y los almacena en dichas
///          variables halladas en el main.
///
/// @param costoH
/// @param costoC
/// @param costoT
/// @return Retorna el valor ingresado en cada una a las variables en el main
int ingresoMantenimiento(float *costoH, float *costoC, float *costoT);
/// @brief	costo_hospedaje, costo_comida, costo_transporte las tres hacen lo mismo,
///           cada una toma el costo y valida que sea entre 500000 y 1000000
///
/// @return	no retornan nada
float costo_hospedaje();
float costo_comida(void);
float costo_transporte();


#endif /* COSTOS_H_ */
