/*
 * Main.c
 *
 *  Created on: 22 abril. 2022
 *      Author: delle
 */


#include <stdio.h>
#include <stdlib.h>
#include "main.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utn.h"
#include  "ArrayPassenger.h"
#include "statusFlight.h"
#include "typePassenger.h"


#define TAM 2000

#define TAM_STATFGHT 3

#define TAM_TYPEP 4

void menuPrincipal()
{
	int opcion;
	int siguienteId=1;
	int banderaHarcode = 1;
	ePassenger list[TAM];
	ePassenger pasajeroIngresado;


	//hardcodeo de estructuras

	eStatusFlight status[TAM_STATFGHT] = {
		{1,"ACTIVO"},
		{2,"DEMORADO"},
		{3,"CANCELADO"}
};

	eTypeFlight typePassenger[TAM_TYPEP] = {
		{1,"ECONOMICO"},
		{2,"PRIMERA CLASE"},
		{3,"TURISTA"},
		{4,"TRIPULANTE"}
};

	initPassanger(list, TAM);

	do
	{
		printf("\n   AGENCIA DE VIAJES \n");

		printf("\n1)ALTA  \n"
				"2)MODIFICAR\n"
				"3)BAJA\n"
				"4)INFORME\n"
				"5)ALTA FORZADA \n"
				"6)SALIR\n");
		getValidInt("\nIngrese opcion: ", "\nError! Reingrese: ","\nSolamente numeros!: " ,1, 6, &opcion);

		switch(opcion)
		{
			case 1:
				printf("\n\n\n\n\n\n");
				if(addPassenger(list, TAM, pasajeroIngresado.name,pasajeroIngresado.lastName,pasajeroIngresado.price,pasajeroIngresado.flycode,pasajeroIngresado.typePassenger,pasajeroIngresado.statusFlight,siguienteId,status,TAM_STATFGHT,typePassenger,TAM_TYPEP)) //si devuelve 1 todo salio bien
				{
					siguienteId++;

				}
				else
				{
					printf("\n	*Hubo un error al cargar al pasajero*\n");
				}

				system("pause");
			break;
			case 2:
				printf("\n\n\n\n\n");
					if(banderaHarcode ==1)
					{
						showMessage("\n	*Todavia no se dio el alta!\n");
					}
					else
					{
						modifyPassenger(list, TAM,status,TAM_STATFGHT,typePassenger,TAM_TYPEP);
					}
				system("pause");
			break;
			case 3:
				limpioPantalla();
				limpioPantalla();
				if(banderaHarcode==1)
				{
					showMessage("\n**Todavia no se dio el alta!*\n");
				}
				else
				{
					if(removePassenger(list, TAM,pasajeroIngresado.id,status,TAM_STATFGHT,typePassenger,TAM_TYPEP) == 0)
					{
						showMessage("\n**Hubo un error al remover al pasajero**\n");
					}
				}
				system("pause");
			break;
			case 4:
				limpioPantalla();
				limpioPantalla();
				if(banderaHarcode==1)
				{
					showMessage("\n***Todavia no se dio el alta!**\n");
				}
				else
				{
					submenueInform(list, TAM,status,TAM_STATFGHT,typePassenger,TAM_TYPEP);
				}
				system("pause");
			break;
			case 5:
				banderaHarcode = 0;
				limpioPantalla();
				limpioPantalla();
				altaForzadaPassengers(list,TAM,5,&siguienteId);
				showMessage(" ***Listado Pasajeros**");
				printf(" id |	 nombre    |	lastName        |   precio  |      flyCode     |   typePassenger  |   flightStatus   ");
				printPassengers(list, TAM,status,TAM_STATFGHT,typePassenger,TAM_TYPEP);
				printf("\n\n\n");
				system("pause");
			break;
			default:
				limpioPantalla();
				limpioPantalla();
				showMessage("\n	 **Operacion Finalizada**.\n");
				system("pause");
			break;
		}

	}while(opcion!=6);
}
