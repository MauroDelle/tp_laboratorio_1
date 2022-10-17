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


int menuModificarJugador()
{
	int opcion;

	printf("     *** Campos a modificar ***\n");
	printf("1- NOMBRE\n"
		   "2- POSICIÓN\n"
		   "3- N°CAMISETA\n"
		   "4- CONFEDERACIÓN\n"
		   "5- SALARIO\n"
		   "6- AÑOS de CONTRATO\n"
		   "7- SALIR\n"
		   "SELECCIONE UNA OPCION: ");
	scanf("%d", &opcion);

	return opcion;
}



