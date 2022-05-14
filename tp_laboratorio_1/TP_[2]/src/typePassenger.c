/*
 * typePassenger.c
 *
 *  Created on: 22 abril. 2022
 *      Author: delle
 */

#include "defines.h"
#include "typePassenger.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>




int listarTypePassenger(eTypeFlight type[], int tam)
{
	int todoOk = 0;
	if(type!=NULL && tam>0)
	{

		printf("\n Listado pasajeros       \n");
		printf("   id    |         tipo        ");
		for(int i=0;i<tam;i++)
		{
			printf("  %4d    |  %15s    |\n", type[i].id, type[i].descripcion);
		}
		todoOk = 1;
	}
	return todoOk;
}

int cargarDescripcionStatusTypePassenger(eTypeFlight type[], int tam, int id,char descripcion[])
{
	int todoOk = 0;
	if(type!=NULL && tam>0 && id>=1 && id<=4 && descripcion!=NULL)
	{

		for(int i = 0;i<tam;i++)
		{
			if(type[i].id == id)
			{
				strcpy(descripcion, type[i].descripcion);
				break;
			}
		}

		todoOk = 1;
	}
	return todoOk;
}
