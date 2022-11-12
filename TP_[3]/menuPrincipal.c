/*
 * menuPrincipal.c
 *
 *  Created on: 1 nov. 2022
 *      Author: delle
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Jugador.h"
#include "utn.h"
#include "menuPrincipal.h"

int menu_listado()
{
	int opcion;

	printf("____________________________");
	printf("\n|1)TODOS LOS JUGADORES   |\n|"
			"2)TODAS LAS SELECCIONES   |\n|"
			"3)JUGADORES CONVOCADOS    |\n|"
			"4)SALIR                   |\n");
	printf("|__________________________|");
	utn_getNumero(&opcion, "\nENTER OPTION: ", "\n[INVALID VALUE, PLEASE TRY AGAIN.]", 1, 4, 50);
	return opcion;

}

int menu()
{
	int opcion;

	printf("\n__________________________________________________________________________");
	printf("\n                                                                          |");
	printf("\n                       WELCOME TO FIFA                                  |\n");
	printf("__________________________________________________________________________|\n");
	printf("_________________________________________________________________________________");
	printf("\n|1)CARGA DE ARCHIVOS  (IN TEXT MODE)                                            |\n|"
			"2)ALTA DE JUGADOR                                                              |\n|"
			"3)MODIFICACIÓN DE JUGADOR                                                      |\n|"
			"4)BAJA DE JUGADOR                                                              |\n|"
			"5)LISTADOS                                                                     |\n|"
			"6)CONVOCAR JUGADORES                                                           |\n|"
			"7)ORDENAR Y LISTAR                                                             |\n|"
			"8)GENERAR ARCHIVO BINARIO                                                      |\n|"
			"9)CARGAR ARCHIVO BINARIO                                                       |\n|"
			"10)GUARDAR ARCHIVOS .CSV:                                                      |\n|"
			"11)SALIR                                                                       |\n");
	printf("|_______________________________________________________________________________|");
	utn_getNumero(&opcion, "\nENTER AN OPTION: ", "\n[INVALID VALUE, TRY AGAIN.] ", 1, 11, 11);
	return opcion;
}


void pFunction(char* messageError1,char* messageError2,char* messageSucess,int* flag,int flagValue,
				LinkedList* array,int(*pFunction)(LinkedList*))
{
	int flagForCompare = *flag;

	if(flagForCompare==flagValue)
	{
		printf("\n%s\n",messageError1);
	}else
	{
		if (!pFunction(array))
		{
			printf("\n%s\n",messageError2);
		} else
		{
			printf("\n%s\n",messageSucess);
		}
	}
}
