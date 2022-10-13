/*
 * menu.c
 *
 *  Created on: 13 oct. 2022
 *      Author: delle
 */

#include "menu.h"



int menuPrincipal()
{
	int opcion;


	printf("<----- BIENVENIDO ----->\n\n"
		   "1- ALTA DE JUGADOR  <\n"
		   "2- BAJA DE JUGADOR  <\n"
		   "3- MODIFICACIÓN DE JUGADOR  <\n"
		   "4- INFORMES  <\n"
		   "5- SALIR  <\n\n"

		   "INGRESE UNA OPCION:");
	scanf("%d", &opcion);


	return opcion;
}
