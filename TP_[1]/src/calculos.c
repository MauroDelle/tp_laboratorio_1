/*
 * calculos.c
 *
 *  Created on: 20 sep. 2022
 *      Author: delle
 */

#include "calculos.h"



void realizarPromedios(int contadorUEFA, int contadorCONMEBOL,
		int contadorCONCACAF, int contadorAFC, int contadorOFC, int contadorCAF, int totalJugadores)
{
	float promedioUEFA;
	float promedioCONMEBOL;
	float promedioCONCACAF;
	float promedioAFC;
	float promedioOFC;
	float promedioCAF;

	promedioUEFA = (float)(contadorUEFA * 100) / totalJugadores;
	promedioCONMEBOL = (float)(contadorCONMEBOL * 100) / totalJugadores;
	promedioCONCACAF = (float)(contadorCONCACAF * 100) / totalJugadores;
	promedioAFC = (float)(contadorAFC * 100) / totalJugadores;
	promedioOFC = (float)(contadorOFC * 100) / totalJugadores;
	promedioCAF = (float)(contadorCAF * 100) / totalJugadores;


	printf("Porcentaje Uefa %0.2f\n"
		   "Porcentaje Conmebol %0.2f\n"
		   "Porcentaje Concacaf %0.2f\n"
		   "Porcentaje Afc %0.2f\n"
		   "Porcentaje Ofc %0.2f\n"
		   "Porcentaje Caf %0.2f\n",promedioUEFA,
		                     promedioCONMEBOL,
							 promedioCONCACAF,
							      promedioAFC,
								  promedioOFC,
								  promedioCAF);

}







