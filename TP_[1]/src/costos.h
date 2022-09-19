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



int ingresoMantenimiento(float *costoH, float *costoC, float *costoT);
float  costo_hospedaje();
float costo_comida(void);
float costo_transporte();


#endif /* COSTOS_H_ */
