/*
 * ArrayPassenger.c
 *
 *  Created on: 22 abril. 2022
 *      Author: delle
 */
#include "defines.h"
#include "ArrayPassenger.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int initPassanger(ePassenger list[], int len)
{
	int todoOk = 0;

	if(list != NULL && len>0)
	{
		for(int i = 0;i<len;i++)
		{
			list[i].isEmpty = 1;
		}
		todoOk =1;
	}
	return todoOk;
}





int searchFreeSpacePassenger(ePassenger list[], int len)
{

	int index = -1;

	if(list!=NULL && len >0 )
	{

		for(int i = 0;i<len;i++){
			if(list[i].isEmpty)
			{
				index = i;
				break;
			}
		}
	}
	return index;
}


int findPassengerById(ePassenger list[], int len,int pId,int* pIndex)
{
	int todoOk = 0;

	if(list!=NULL && len >0 && pIndex !=NULL && pId>0)
	{
		*pIndex= -1;
		for(int i = 0;i<len;i++){
			if(list[i].isEmpty == 0 && list[i].id == pId)
			{
				*pIndex = i;
				break;
			}
		}
		todoOk =1;
	}
	return todoOk;
}


int removePassenger(ePassenger list[],int len, int id,eStatusFlight status[],int tam_status,eTypeFlight typePassenger[],int tamPassenger)
{
	int todoOk = 0;
	int idIngresada;
	int pIndex;
	char opcion;

	if(list!=NULL && len >0)
	{

		printf("\n                                                            ");
		printf("\n                baja pasajeros                        \n");
		printf("\n\n");
		printf("						  ***LISTADO DE PASAJEROS***                                        | ");
		printf("|  id |	 nombre    |	lastName        |   precio  |      flyCode     |   typePassenger  |   flightStatus    |   ");
		printPassengers(list, len,status,tam_status,typePassenger,tamPassenger);

		getValidInt("\nIngrese id: ", "\nid invalida: ", "\nSOLO NUMEROS: ", 1, 20001, &idIngresada);

		if(findPassengerById(list, len, idIngresada, &pIndex) == 1)
		{
			if(pIndex == -1)
			{
				printf("\n	No se encontro un pasajero\n");
			}
			else
			{

				showMessage("						  **Lista Passengers***                                                    ");

				printf("|  id |	 nombre    |	lastName        |   precio  |      flyCode     |   typePassenger  |   flightStatus    |   ");
				showOnePassenger(list[pIndex],status,tam_status,typePassenger,tamPassenger);
				printf("--------------------------------------------------------------------------------------------------------------------------|\n");

				getUserConfirmation(&opcion, "\nELIMINAR EMPLEADO?\n", "\n**Error. Reingrese por favor:\n");
				if(opcion !='s')
				{
					printf("\nOperacion Abortada\n");
				}
				else
				{
					list[pIndex].isEmpty =1;
					printf("\nBaja exitosa\n");
					todoOk =1;
				}
			}
		}
		else
		{
			printf("\n	*Error al buscar employee*\n");
		}
	}


	return todoOk;
}




int addPassenger(ePassenger* list,int len,char name[],char lastName[],float price,char flycode[],int typePassenger,int statusFlight,int id,eStatusFlight status[], int tam_status,eTypeFlight typePassenger2[],int tamPassenger)
{
	int todoOk =-1;

	int indice;

	char auxName[51];
	char auxLastName[51];
	float auxFloatPrice;
	char auxFlycode;

	char opcion;


	if(list!=NULL && len >0 && id && name!=NULL && lastName!=NULL && flycode!=NULL)
	{
		printf("\n                alta pasajeros                       |\n");

			indice = searchFreeSpacePassenger(list, len);

			if(indice == -1)
			{
				printf("\nNo hay mas espacio!\n");

			}
			else
			{
				list[indice].id = id;

				getValidString("\nNombre:\n","\nSolo letras!!:\n","\nLimmit exceded:\n",auxName, 4,51);
				strcpy(list[indice].name,auxName);


				getValidString("\nApellido:\n","\nSolo letras!!:\n","\nError! Excediste el limite:\n",auxLastName, 3,51);
				strcpy(list[indice].lastName,auxLastName);


				getFloatValidation( &auxFloatPrice,"\nIngrese el precio!: ($10000 - $700000000): \n","\nLos valores deben ser entre: ($10000 - $700000000), Error! Reingrese: \n", 10000, 700000000);
				list[indice].price = auxFloatPrice;
				getValidStringAlpha("\nCodigo 9 digitos!: ",
									"\nError! Reingrese: ", &auxFlycode, 9, 9);
				strcpy(list[indice].flycode,&auxFlycode);
				limpioPantalla();
				listarTypePassenger(typePassenger2, tamPassenger);
				utn_getNumero(&typePassenger, "INGRESE EL TIPO DE PASAJERO: ", "ERROR REINGRESE UN VALOR VALIDO. ", 1, 4, 100);
				list[indice].typePassenger = typePassenger;

				limpioPantalla();
				listarStatusFlight(status, tam_status);
				utn_getNumero(&statusFlight, "INGRESE EL ESTADO DEL VUELO: ", "ERROR REINGRESE UN VALOR VALIDO. ", 1, 3, 100);
				list[indice].statusFlight = statusFlight;

				list[indice].isEmpty = 0;


				printf("						  ***LISTADO DE PASAJEROS***                                                      | ");
				printf("|  id |	 nombre    |	lastName        |   precio  |      flyCode     |   typePassenger  |   flightStatus    |   ");
				showOnePassenger(list[indice],status,tam_status,typePassenger2,tamPassenger);
				printf("\n**Dar de alta? s/n: ");
				printf("\nOpcion: ");
				opcion=toupper(opcion);
				scanf("%c",&opcion);
				if(opcion!='s' && opcion!='S')
				{
					printf("\nCancelado!");
					id--;
					list[indice].isEmpty = 1;
				}
				else
				{
					showMessage("\nCarga realizada!\n");
				}

				todoOk = 1;
			}
	}

	return todoOk;
}



void showOnePassenger(ePassenger list,eStatusFlight status[],int tam,eTypeFlight typePassenger[],int tamPassenger)
{
	char descriptStatus[20];
	char descriptTypePassenger[25];
	cargarDescripcionStatus(status, tam, list.statusFlight, descriptStatus);
	cargarDescripcionStatusTypePassenger(typePassenger, tamPassenger, list.typePassenger, descriptTypePassenger);
	printf("|%4d | %-10s |    %-10s	|    $%-11.2f |       %-11s	     |	  %-13s    |       %-9s      |\n", list.id,
																					                       list.name,
																										   list.lastName,
																										   list.price,
																										   list.flycode,
																										   descriptTypePassenger,
																										   descriptStatus
																																);
}


void printPassengers(ePassenger list[], int len,eStatusFlight status[],int tam_status,eTypeFlight typePassenger[],int tamPassenger)
{
	int bandera=0;

		for(int i =0; i<len;i++)
		{
			if(!list[i].isEmpty)
			{
				showOnePassenger(list[i],status,tam_status,typePassenger,tamPassenger);
				bandera=1;
			}
		}
		if(bandera==0)
		{
			showMessage("\n**No hay pasajeros!*\n");
		}
}


int modifyPassenger(ePassenger list[], int len,eStatusFlight status[], int tam_status,eTypeFlight typePassenger2[],int tamPassenger)
{
	int todoOk = 0;
	int idIngresada;
	int pIndex;
	char opcion;
	char auxCadena [51];
	float auxFloat;
	int auxTypePassenger;

	if(list!=NULL && len >0)
	{

		printf("\n       Modificacion pasajeros         \n");
		printf("\n\n");
		printf("						  ***Listado de pasajeros***  ");
		printf("  id |	 nombre    |	lastName        |   precio  |      flyCode     |   typePassenger  |   flightStatus    ");
		printPassengers(list, len,status,tam_status,typePassenger2,tamPassenger);
		getValidInt("\nIngrese id: ", "\nError! Reingrese: ", "\nError! Solo numeros: ", 1, 2000, &idIngresada);
		if(findPassengerById(list, len, idIngresada, &pIndex) == 1)
		{
			if(pIndex == -1)
			{
				showMessage("\nNo se encontro dicho pasajero en el sistema\n");
			}
			else
			{
				printf("						  *Passenger List*                                                  ");
				printf("  id |	 nombre    |	lastName        |   precio  |      flyCode     |   typePassenger  |   flightStatus    ");
				showOnePassenger(list[pIndex],status,tam_status,typePassenger2,tamPassenger);
				getUserConfirmation(&opcion, "\nModificar :(S/N)?  ", "\nError!(S/N): ");
				printf("\n\n");
				if(opcion =='s')
				{
					printf("\nA)Nombre\n"
							"B)Apellido:\n"
							"C)Precio:\n"
							"D)CODIGO:\n"
							"E)TypePassenger:\n"
							"6)Salir\n");
					getUserMenuOption(&opcion, "\nQue va a modificar?: ","\nError, Reingrese: ");
					switch(opcion)
					{
						case 'A':
							getValidString("\nIngrese el nombre:\n","\nSolo letras:\n","\nTe pasaste!:\n",auxCadena, 3,51);
							getUserConfirmation(&opcion, "\nModificar nombre? S/N\n","\n Error! Reingrese:");
							if(opcion=='s')
							{
								strcpy(list[pIndex].name,auxCadena);
								showMessage("\nModificacion exitosa\n");
							}
							else
							{
								showMessage("\n*Modificacion cancelada!*\n");
							}
						break;
						case 'B':
							getValidString("\nIngrese apellido:\n","\nSolo letras!:\n","\nTe pasaste!:\n",auxCadena, 3,51);
							getUserConfirmation(&opcion, "\nModificar Apellido? S/N\n","\nError! reingrese");
							if(opcion=='s')
							{
								strcpy(list[pIndex].lastName,auxCadena);
								showMessage("\nModificacion Exitosa\n");
							}
							else
							{
								showMessage("\n*Modificacion Cancelada*\n");
							}
						break;
						case 'C':
							getFloatValidation( &auxFloat,
												"\nIngrese el precio ($10000 - $700000000): \n","\nError! Reingrese : \n", 10000, 700000000);
							getUserConfirmation(&opcion, "\nModificar precio de vuelo? S/N\n","\nError! Reingrese:");
							if(opcion=='s')
							{
								list[pIndex].price = auxFloat;
								showMessage("\n		Modificacion Exitosa\n");
							}
							else
							{
								showMessage("\n	Modificacion Cancelada\n");
							}
						break;
						case 'D':
							getValidStringAlpha("\nCodigo 9 digitos: ","\n*Error! Reingrese: ", auxCadena, 9, 9);
							strcpy(list[pIndex].flycode,auxCadena);
							if(opcion=='s')
							{
								strcpy(list[pIndex].flycode, auxCadena);
								showMessage("\n	Modificacion Exitosa*\n");
							}
							else
							{
								showMessage("\nModificacion Cancelada!\n");
							}
						break;
						case 'E':
							listarTypePassenger(typePassenger2, tamPassenger);
							utn_getNumero(&auxTypePassenger, "Ingrese tipo pasajero ", "Ingrese valor Valido ", 1, 4, 100);
							list[pIndex].typePassenger = auxTypePassenger;
							if(opcion=='s')
							{
								list[pIndex].typePassenger = auxTypePassenger;
								showMessage("\n	Modificacion Exitosa\n");
							}
							else
							{
								showMessage("\nModificacion cancelada\n");
							}
						break;

					}

				}
				else
				{
					showMessage("\nModificacion Cancelada!");
				}
			todoOk =1;
			}
		}
		else
		{
			showMessage("\nOcurrio un Error!\n");
		}
	}
return todoOk;
}


int sortPassengers(ePassenger* list, int len, int order)
{
	int todoOk = 1;

	ePassenger auxiPasajero;

	if(list!=NULL && len>0)
	{
		for(int i = 0; i<len;i++)
		{
			for(int j = i;j<len;j++)
			{
				if(!list[i].isEmpty && !list[j].isEmpty)
				{
					if(((list[i].typePassenger == list[j].typePassenger) && strcmp(list[i].lastName,list[j].lastName)>0 && order ==1)
						|| (list[i].typePassenger != list[j].typePassenger && list[i].typePassenger > list[j].typePassenger&& order ==1)
						||(list[i].typePassenger == list[j].typePassenger && strcmp(list[i].lastName,list[j].lastName)<0 && order ==0)
						||(list[i].typePassenger != list[j].typePassenger && list[i].typePassenger < list[j].typePassenger&& order ==0))
					{
						auxiPasajero = list[i];
						list[i] = list[j];
						list[j] = auxiPasajero;
					}
				}
			}
		}
	}
	return todoOk;
}


int informPrice(ePassenger list[],int len,float* acumPrecio,int* cantPassengers, int* contPassengerSuperior,float* promedioPrecios)
{
	int todoOk =-1;

	float acumPasaje = 0.00;
	int cantPasajeros = 0;
	float promedio;

	int cantidadPassengerPromedio=0;

	if(list!=NULL && len>0 && acumPrecio!=NULL && cantPassengers!=NULL && promedioPrecios!=NULL)
	{
		for(int i = 0; i<len;i++)
		{
			if(list[i].price>0 && list[i].isEmpty==0)
			{
				cantPasajeros++;
				acumPasaje=list[i].price  + acumPasaje;
			}


		}


		promedio=(float)(acumPasaje/cantPasajeros);
		for(int i=0; i<len;i++)
		{
			if(list[i].price>promedio && list[i].isEmpty==0)
			{
				cantidadPassengerPromedio++;
			}
		}
		*cantPassengers = cantPasajeros;
		*acumPrecio= acumPasaje;
		*promedioPrecios = promedio;
		*contPassengerSuperior = cantidadPassengerPromedio;

		todoOk =0;
	}

	return todoOk;
}



int sortPassengersByCode(ePassenger* list,int len,eStatusFlight status[],int tam_status,eTypeFlight typePassenger[],int tamPassenger,int order)
{
	int todoOk = -1;
	ePassenger auxPassanger;

	if(list!=NULL && len>0)
	{
		for(int i = 0;i<len;i++)
		{
			for(int j = i;j<len;j++)
			{
				if(!list[i].isEmpty && !list[j].isEmpty )
				{
					if(order==1)
					{
						if(strcmp(list[i].flycode,list[j].flycode)>0 )
						{
							auxPassanger = list[i];
							list[i]= list[j];
							list[j]= auxPassanger;
						}
					}
					else if(order==0)//
					{
						if(strcmp(list[i].flycode,list[j].flycode)<0)
						{
							auxPassanger = list[i];
							list[i]= list[j];
							list[j]= auxPassanger;
						}
					}
				}
			}
		}

		showMessage("			  *Listado Passengers*               ");
		printf("  id |	 nombre    |	lastName        |   precio  |      flyCode     |   typePassenger  |   flightStatus    ");
		for(int i =0; i<len;i++)
		{
			if(!list[i].isEmpty && list[i].statusFlight == 1)
			{
				 showOnePassenger(list[i],status,tam_status,typePassenger,tamPassenger);
			}
		}


		todoOk=0;
	}
	return todoOk;
}



int submenueInform(ePassenger list[],int len,eStatusFlight status[], int tam_status,eTypeFlight typePassenger[],int tamPassenger)
{
	int todoOk =1;

	int opcion;
	int order;

	float acumuladorPrecio = 0.0;
	int cantPassengers=0;
	int cantPassengersPromedioPrecioMayor = 0;
	float promedioFinal = 0.0;


	if(list!=NULL && len>0)
	{

		printf("\n                                                            ");
		printf("\n                informes                                  \n");
		printf("\n1)Orden alfabetico apellido y typePassenger\n""2)Total y promedio:\n""3)Codigo de vuelo y estado de vuelo:\n");
		utn_getNumero(&opcion, "\ningreso: ", "\nError! Reingrese:", 1 , 3, 5000);
		switch (opcion)
		{
			case 1:
				printf("\n\n");
				printf("\n|1)ASCENDENTE         \n""0)DESCENDENTE        \n");
				utn_getNumero(&order, "\nINGRESE COMO DESEA VER LA LISTA:", "\nERROR, REINGRESE VALOR VALIDO ", 0, 1, 10000);
				sortPassengers(list, len, order);
				showMessage("						  ***LISTADO DE PASAJEROS***                                                      | ");
				printf("  id |	 nombre    |	lastName        |   precio  |      flyCode     |   typePassenger  |   flightStatus    ");
				printPassengers(list, len,status,tam_status,typePassenger,tamPassenger);
			break;
			case 2:
				limpioPantalla();


				showMessage("						  ***Listado Pasajeros***                                                       ");
				printf("  id |	 nombre    |	lastName        |   precio  |      flyCode     |   typePassenger  |   flightStatus    ");
				informPrice(list, len, &acumuladorPrecio, &cantPassengers,&cantPassengersPromedioPrecioMayor, &promedioFinal);
				printPassengers(list, len,status,tam_status,typePassenger,tamPassenger);

				printf("\nEl total de precio de vuelo: $%.2f",acumuladorPrecio);
				printf("\nEl promedio de los precios del vuelo: $%.2f",promedioFinal);
				printf("\nLos pasajeros que superan el promedio es: %d",cantPassengersPromedioPrecioMayor);
			break;
			case 3:
				printf("\n\n");
				printf("\n1)ASCENDENTE\n"
						"0)DESCENDENTE\n");
				utn_getNumero(&order, "\nComo quiere ver la lista: ", "\nError! Reingrese", 0, 1, 10000);
				sortPassengersByCode(list, len,status,tam_status,typePassenger,tamPassenger,order);
			break;
		}
	}
	return todoOk;
}


int altaForzadaPassengers(ePassenger* list, int len, int cant,int* id)
{
	//Hardcodeo modificado de Baus
	ePassenger impostores[] =
	   {
		       {0, "Mauro", "Delle",100000,"k34maj4d9",1,1,0},
		        {0, "esteban", "Firulais",120000,"majkrn39j",2,2,0},
		        {0, "Esteban","Lamothe", 140000,"maor2j4d6",3,3,0},
		        {0, "Camila", "Delle",120000,"m3jHb4n52",2,1,0},
		        {0, "Claudio", "Palmer", 110000,"pj4hn7J3d",4,2,0},
		        {0, "Susana", "Gimenez", 130000,"ln5Gn6g38",1,1,0},
		        {0, "Moria", "Casan", 120000,"mh3jkf7ah",2,3,0},
		        {0, "Alfonso", "Robles", 150000,"knfl57483",3,2,0},
		        {0, "Daniel", "Sonto", 120000,"ahb4ja6f9",1,2,0},
		        {0, "Franco", "Sinatra", 110000,"al4b38na8",4,1,0}
	    };
	int todoOk = 0;
	if(list!=NULL && len >0 && id!=NULL && cant>0 && cant<=len)
	{
		for(int i = 0;i<cant;i++)
		{
			list[i] = impostores[i];
			list[i].id = *id;
			*id = *id+1;
		}
		todoOk = 1;
	}

	return todoOk;
}
