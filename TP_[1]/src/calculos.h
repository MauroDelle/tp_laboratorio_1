/*
 * calculos.h
 *
 *  Created on: 20 sep. 2022
 *      Author: delle
 */

#ifndef CALCULOS_H_
#define CALCULOS_H_
#include "utn.h"
#include "jugadores.h"
#include "costos.h"
#include "menu.h"




float realizarPromedios(int contadorUEFA, int contadorCONMEBOL,
		int contadorCONCACAF, int contadorAFC, int contadorOFC, int contadorCAF,
		int totalJugadores, float *promUEFA, float *promCONMEBOL, float *promCONCACAF,
		float *promAFC, float *promOFC, float *promCAF);


int calcularTotal(int arqueros, int defensores,int mediocampistas,int delanteros,int  *totalJugadores);
int calcular_totalConfederaciones(int afc, int caf, int concacaf, int conmebol, int ofc, int *totalConfederaciones);
int calcular_totalSinUEFA(int totalJugadores, int contUefa, int *restaUEFA);


#endif /* CALCULOS_H_ */
