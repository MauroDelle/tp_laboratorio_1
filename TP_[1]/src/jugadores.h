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


int carga_jugadores(int *contArq,  int *contDef, int *contMed, int *contDel, int *AFC, int *CAF, int *CONCACAF, int *CONMEBOL,
		int *UEFA, int *OFC);
void carga_Confederaciones(int *AFC, int *CAF, int *CONCACAF, int *CONMEBOL,int *UEFA, int *OFC);


#endif /* JUGADORES_H_ */
