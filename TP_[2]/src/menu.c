/*
 * menu.c
 *
 *  Created on: 13 oct. 2022
 *      Author: delle
 */

#include "menu.h"
#include "utn.h"



int menuPrincipal()
{
	int opcion;


	printf("<----- BIENVENIDO ----->\n\n"
		   "1- ALTA DE JUGADOR  <\n"
		   "2- BAJA DE JUGADOR  <\n"
		   "3- MODIFICACIÓN DE JUGADOR  <\n"
		   "4- INFORMES  <\n"
		   "5- SALIR  <\n\n");
	utn_getNumero(&opcion, "\nINGRESE UNA OPCION: ","\nERROR! SELECCIONE UNA OPCION VÁLIDA",1,5, 50);

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
		   "7- SALIR\n");
	utn_getNumero(&opcion, "\nINGRESE UNA OPCION: ","\nERROR! SELECCIONE UNA OPCION VÁLIDA",1,7, 50);

	return opcion;
}


int menuModificarConfederacion()
{
	int opcion;
	printf("     *** Campos a modificar ***\n");
	printf("1- NOMBRE\n"
		   "2- REGION\n"
		   "3- AÑO CREACION\n"
		   "4- SALIR\n");
	utn_getNumero(&opcion, "\nINGRESE UNA OPCION: ","\nERROR! SELECCIONE UNA OPCION VÁLIDA",1,4, 50);

	return opcion;
}




