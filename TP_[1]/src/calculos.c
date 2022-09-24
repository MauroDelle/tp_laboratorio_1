/*
 * calculos.c
 *
 *  Created on: 20 sep. 2022
 *      Author: delle
 */

#include "calculos.h"



float realizarPromedios(int contadorUEFA, int contadorCONMEBOL,
		int contadorCONCACAF, int contadorAFC, int contadorOFC, int contadorCAF,
		int totalJugadores, float *promUEFA, float *promCONMEBOL, float *promCONCACAF,
		float *promAFC, float *promOFC, float *promCAF)
{
	float retorno = 0;

	//verifico si los punteros son  != NULL
	if(promUEFA != NULL && promCONMEBOL != NULL && promCONCACAF != NULL && promAFC != NULL && promOFC != NULL && promCAF != NULL)
	{

		*promUEFA = (contadorUEFA * 100) / totalJugadores;
		*promCONMEBOL = (contadorCONMEBOL * 100) / totalJugadores;
		*promCONCACAF = (contadorCONCACAF * 100) / totalJugadores;
		*promAFC = (contadorAFC * 100) / totalJugadores;
		*promOFC = (contadorOFC * 100) / totalJugadores;
		*promCAF = (contadorCAF * 100) / totalJugadores;

		retorno = 1;
	}


	return retorno;
}


int calcularTotal(int arqueros, int defensores,int mediocampistas,int delanteros,int  *totalJugadores)
{
	int retorno = 0;
	if(totalJugadores != NULL)
	{
		*totalJugadores = arqueros + defensores + mediocampistas + delanteros;

		retorno = 1;
	}

	return retorno;
}


int calcular_totalConfederaciones(int afc, int caf, int concacaf, int conmebol, int ofc, int *totalConfederaciones)
{
	int retorno = 0;

	if(totalConfederaciones != NULL)
	{
		*totalConfederaciones = afc + caf + concacaf + conmebol + ofc;

		retorno = 1;
	}

	return retorno;
}


int calcular_totalSinUEFA(int totalJugadores, int contUefa, int *restaUEFA)
{
	int retorno = 0;

	if(restaUEFA != NULL)
	{
		*restaUEFA = totalJugadores - contUefa;
		retorno = 1;
	}

	return retorno;
}










