/*
 * confederacion.c
 *
 *  Created on: 13 oct. 2022
 *      Author: delle
 */
#include "confederacion.h"



int listarConfederacion(eConfederacion list[], int tam)
{
	int retorno;

	if(list != NULL && tam > 0)
	{
		printf("---- LISTADO CONFEDERACIONES ----\n\n"
			   "ID     NOMBRE     REGION      AÑO CREACION");
		printf("-----------------------\n");

		for(int i = 0; i < tam; i++)
		{
			printf("%d     %s      %s       %4d", list[i].id, list[i].nombre, list[i].region, list[i].anioCreacion);

		}
		printf("\n\n");
		retorno = 1;
	}

	return retorno;
}


int cargarDescripcionConfederacion(eConfederacion list[], int tam, int id, char nombre[], char region[])
{
	int retorno = 0;
	int indice;

	buscarConfederacion(list, tam, id, &indice);

	if(nombre != NULL && region != NULL && indice != -1)
	{
		strcpy(nombre, list[indice].nombre);
		strcpy(region, list[indice].region);
		retorno = 1;
	}

	return retorno;
}


int buscarConfederacion(eConfederacion list[], int tam, int id, int *pIndice)
{
	int retorno = 0;

	if(list != NULL && tam > 0 && pIndice != NULL)
	{
		*pIndice = -1;

			for(int i = 0; i < tam; i++)
			{
				if(list[i].id == id)
				{
					*pIndice = i;
					break;
				}

			}
			retorno = 1;
	}

	return retorno;
}


int validarConfederacion(eConfederacion list[], int tam, int id)
{
	int retorno = 0;
	int indice;

	buscarConfederacion(list, tam, id, &indice);

	if(indice != -1)
	{
		retorno = 1;
	}

	return retorno;
}










