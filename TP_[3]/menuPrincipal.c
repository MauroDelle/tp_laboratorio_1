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
	utn_getNumero(&opcion, "\nINGRESE UNA OPCION: ", "\n[VALOR INVALIDO, REINTENTE.]", 1, 4, 50);
	return opcion;

}

int menu()
{
	int opcion;

	printf("\n_____________________________________________________________________________");
	printf("\n                                                                              |");
	printf("\n                       BIENVENIDO A FIFA                                      |");
	printf("\n______________________________________________________________________________|");
	printf("\n_________________________________________________________________________________");
	printf("\n1)CARGA DE ARCHIVOS  (EN MODO TEXTO)                                           ||"
			"\n2)ALTA DE JUGADOR                                                              ||"
			"\n3)MODIFICACION DE JUGADOR                                                      ||"
			"\n4)BAJA DE JUGADOR                                                              ||"
			"\n5)LISTADOS                                                                     ||"
			"\n6)CONVOCAR JUGADORES                                                           ||"
			"\n7)ORDENAR Y LISTAR                                                             ||"
			"\n8)GENERAR ARCHIVO BINARIO                                                      ||"
			"\n9)CARGAR ARCHIVO BINARIO                                                       ||"
			"\n10)GUARDAR ARCHIVOS .CSV                                                       ||"
			"\n11)SALIR                                                                       ||");
	printf("\n|______________________________________________________________________________||");
	utn_getNumero(&opcion, "\nINGRESE UNA OPCION: ", "\n[VALOR INVALIDO, REINTENTE.] ", 1, 11, 11);
	return opcion;
}


void pFunction(char* messageError1,char* messageError2,char* messageSucess,int* flag,int flagValue,
				LinkedList* array,int(*pFuncion)(LinkedList*))
{
	int flagForCompare = *flag;

	if(flagForCompare==flagValue)
	{
		printf("\n%s\n",messageError1);
	}else
	{
		if (!pFuncion(array))
		{
			printf("\n%s\n",messageError2);
		} else
		{
			printf("\n%s\n",messageSucess);
		}
	}
}

void pFunction2(char* messageError1,char* messageError2,char* messageSucess,int* flag,int flagValue,
				LinkedList* array, LinkedList* array2 ,int(*pFuncion)(LinkedList*, LinkedList*))
{
	int flagForCompare = *flag;

	if(flagForCompare==flagValue)
	{
		printf("\n%s\n",messageError1);
	}else
	{
		if (!pFuncion(array, array2))
		{
			printf("\n%s\n",messageError2);
		} else
		{
			printf("\n%s\n",messageSucess);
		}
	}
}
