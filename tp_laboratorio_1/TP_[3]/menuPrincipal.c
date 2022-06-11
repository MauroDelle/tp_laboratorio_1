/*
 * menuPrincipal.c
 *
 *  Created on: 11 jun. 2022
 *      Author: delle
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "menuPrincipal.h"
#include "utn.h"


#define STATE_FILE_OPEN 1
#define STATE_FILE_CLOSED 0


/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

int menu()
{
	int opcion;

	printf("\n|1)Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).   \n"
			"2)Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).\n"
			"3)Alta de pasajero                                                       \n"
			"4)Modificar datos de pasajero                                         \n"
			"5)Baja de pasajero                                                     \n"
			"6)Listar pasajero                                                       \n"
			"7)Ordenar pasajero                                                       \n"
			"8) Guardar los datos de los pasajeros en el archivo data.csv (modo texto).\n"
			"9)Guardar los datos de los pasajeros en el archivo data.csv (modo binario).\n"
			"10)Salir                                                                    \n");


	utn_getNumero(&opcion, "\nINGRESE SU OPCION", "\nERROR!REINGRESE:", 1, 10, 10);
	return opcion;
}

void pFunction(char* messageError1,char* messageError2,char* messageSucess,int* flag,int flagValue,
				LinkedList* array,int(*pFunction)(LinkedList*)){
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


void menuDefinitivo()
{
	char confirmation = 'n';
	int fileState = 0;
	int binaryState=0;

    LinkedList *listaPasajeros = ll_newLinkedList();

    do
    {
    	limpioPantalla();
    	switch(menu())
    	{
			case 1:
				limpioPantalla();
				if(controller_loadFromText("data.csv", listaPasajeros) == 1)
				{
					printf("\nSE ABRIO EL ARCHIVO:\n");
					fileState = 1;
				}
				else
				{
					printf("\nHUBO UN ERROR!\n");
				}
				system("Pause");
			break;
			case 2:
				limpioPantalla();
				if(binaryState==0)
				{
					printf("\nERROR! ABRI EL ARCHIVO PAPU!\n");
				}
				else
				{
					if(controller_loadFromBinary("data.bin", listaPasajeros) == 1)
					{
						printf("\nSE ABRIO EL ARCHIVO EN BINARIO!\n");
						fileState = 1;
					}
					else
					{
						printf("\nHUBO UN ERRROR!\n");
					}

				}
				system("Pause");
			break;
			case 3:
				limpioPantalla();
				pFunction("\nNO TE APURES!",
						"\nHUBO UN ERROR! ",
						"\nSALISTE!",
						&fileState, STATE_FILE_CLOSED, listaPasajeros, controller_addPassenger);
				system("Pause");
			break;
			case 4:
				limpioPantalla();
				pFunction("\nNO TE APURES!",
						"\nHUBO UN ERROR AL MODIFICAR!",
						"\nCHAUU!",
						&fileState, STATE_FILE_CLOSED, listaPasajeros, controller_editPassenger);
				system("Pause");
			break;
			case 5:
				limpioPantalla();
				pFunction("\nNO TE APURES!",
						"\nHUBO UN ERROR AL BORRAR! ",
						"\nADIOOOSSS!",
						&fileState, STATE_FILE_CLOSED, listaPasajeros, controller_removePassenger);
				system("Pause");
			break;
			case 6:
				limpioPantalla();
				pFunction("\nNO TE APURES!",
						"\nHUBO UN ERROR! ",
						"\nSALIO TODO BIEN!",
						&fileState, STATE_FILE_CLOSED, listaPasajeros, controller_ListPassenger);
				system("Pause");
			break;
			case 7:
				pFunction("\nNO TE APURES!",
						"\nHUBO UN ERROR! ",
						"\nSALIO TODO BIEN!",
						&fileState, STATE_FILE_CLOSED, listaPasajeros, controller_sortPassenger);
			break;
			case 8:
				limpioPantalla();
				if(fileState==1)
				{
					controller_saveAsText("data.csv", listaPasajeros);
					fileState = 0;
					printf("\nOPERACION EXITOSA!!\n");
				}
				else
				{
					printf("\nNO TE APURES!\n");
				}
				system("Pause");
			break;
			case 9:
				limpioPantalla();
				if(fileState==1)
				{
					controller_saveAsBinary("data.bin", listaPasajeros);
					fileState = 0;
					printf("\nOPERACION EXITOSA!!\n");
					binaryState=1;
				}
				else
				{
					printf("\nNO TE APURES!\n");
				}
				system("Pause");
			break;
			case 10:
				limpioPantalla();
				if(fileState!=0)
				{
					printf("\nNO TE APURES!\n");
				}
				else
				{
					getUserConfirmation(&confirmation, "\nTE QUERES IR? (S/N)?: ", "\nERROR!REINGRESE! (S/N)!: ");
					if(confirmation=='s')
					{
						printf(" THATS ALL FOLKS!.....\n");
					}
					else
					{
						printf("QUE HAY DE NUEVO VIEJO?\n");
					}
				}
				system("Pause");
				break;
    	}
    }while(confirmation!='s');
}
