#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"


int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)//baus 6/6
{
	int todoOk = 0;
	int elementoUno=1;

	Passenger *pAuxPassenger;
	char auxId[5000];
	char auxName[5000];
	char auxLastName[5000];
	char auxPrice[5000];
	char auxCodeFlight[5000];
	char auxTypePassenger[5000];
	char auxStatus[5000];

	if(pFile!=NULL)
	{
		while (!feof(pFile))
		{
			if(elementoUno)
			{
				fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", auxId, auxName,
						auxLastName,auxPrice,auxCodeFlight,auxTypePassenger,auxStatus);
				elementoUno = 0;
			}
			fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", auxId, auxName,
					auxLastName,auxPrice,auxCodeFlight,auxTypePassenger,auxStatus);

			pAuxPassenger = Passenger_newParametros(auxId, auxName, auxTypePassenger, auxLastName, auxStatus, auxPrice, auxCodeFlight);

			if(pAuxPassenger!=NULL)
			{
				ll_add(pArrayListPassenger, pAuxPassenger);
				todoOk=1;
			}
		}
	}
    return todoOk;
}


int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)//baus 6/6
{
	int todoOk=0;

	Passenger *pAuxPassenger;

	if(pFile!=NULL)
	{
		while(!feof(pFile))
		{
			pAuxPassenger = Passenger_new();
			if(fread(pAuxPassenger,sizeof(Passenger),1,pFile) ==1)
			{
				ll_add(pArrayListPassenger, pAuxPassenger);
			}
		}
		todoOk=1;
	}
    return todoOk;
}
