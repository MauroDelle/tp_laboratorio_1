/*
 * jugador.c
 *
 *  Created on: 13 oct. 2022
 *      Author: delle
 */


#include "jugador.h"
#include "confederacion.h"

/*
 * 	int id;
	char nombre[50];
	char posicion[50];
	int numeroCamiseta;
	int idConfederacion;
	float salario;
	int aniosContrato;
	int isEmpty;
 *
 */

int altaJugador(eJugador vec[], int tam,eConfederacion list[], int tamConf, int* pId)
{
	int retorno = 0;

	int indice;
	char auxNombre[100];
	char auxPosicion[100];
	eJugador nuevoJugador;


	if(vec != NULL && tam > 0 && pId != NULL)
	{
		if(buscarJugadorLibre(vec, tam, &indice))
		{
			if(indice == -1)
			{
				printf("No hay lugar en el sistema\n");
			}
			else
			{
				printf("Ingrese el nombre del jugador: ");
				fflush(stdin);
				gets(auxNombre);

				while(strlen(auxNombre) > 50)
				{
					printf("Ingrese el nombre del jugador: ");
					fflush(stdin);
					gets(auxNombre);
				}
				strcpy(nuevoJugador.nombre, auxNombre);


				printf("Ingrese su posicion: ");
				fflush(stdin);
				gets(auxPosicion);

				while(strlen(auxPosicion) > 50)
				{
					printf("Ingrese su posicion: ");
					fflush(stdin);
					gets(auxPosicion);
				}
				strcpy(nuevoJugador.posicion, auxPosicion);

				printf("Ingrese el numero de camiseta: ");
				scanf("%d", &nuevoJugador.numeroCamiseta);

				while(nuevoJugador.numeroCamiseta < 1 && nuevoJugador.numeroCamiseta > 99)
				{
					printf("Ingrese el numero de camiseta: ");
					scanf("%d", &nuevoJugador.numeroCamiseta);
				}


				printf("Ingrese el sueldo: ");
				scanf("%f", &nuevoJugador.salario);

				while(nuevoJugador.salario > 200000)
				{
					printf("Ingrese el sueldo: ");
					scanf("%f", &nuevoJugador.salario);
				}

				printf("Ingrese cuantos años tiene de contrato: ");
				scanf("%d", &nuevoJugador.aniosContrato);


				while(nuevoJugador.aniosContrato > 8)
				{
					printf("Ingrese cuantos años tiene de contrato: ");
					scanf("%d", &nuevoJugador.aniosContrato);
				}


				listarConfederacion(list, tamConf);

				printf("Ingrese el id de la confederacion: ");
				scanf("%d", &nuevoJugador.idConfederacion);

				while(!validarConfederacion(list, tamConf, nuevoJugador.idConfederacion))
				{
					printf("Confederacion Invalida. Ingrese id confederacion: ");
					scanf("%d", &nuevoJugador.idConfederacion);

				}

				nuevoJugador.isEmpty = 0;
				nuevoJugador.id = *pId;
				*pId = *pId + 1;
				vec[indice] = nuevoJugador;
				retorno = 1;
			}
		}
	}

	return retorno;
}








int mostrarJugador(eJugador e, eConfederacion list[], int tam)
{
	int retorno = 0;
	char nombreConf[50];
	char regionConf[50];


	if(list != NULL && tam > 0)
	{
		cargarDescripcionConfederacion(list, tam, e.idConfederacion, nombreConf, regionConf);

		printf("%4d    %s     %s     %d      %d      %f      %d    %s     %s\n",
				e.id,
				e.nombre,
				e.posicion,
				e.numeroCamiseta,
				e.idConfederacion,
				e.salario,
				e.aniosContrato,
				nombreConf,
				regionConf);

		retorno = 1;
	}



	return retorno;
}


int listarJugadores(eJugador vec[], int tam, eConfederacion list[], int tamConf)
{
	int retorno = 0;
    int flag = 0;


    if(vec != NULL && tam > 0)
    {
    	printf("       ------ Listado Jugadores ------\n\n");

    	printf("   ID       NOMBRE         POSICION         N° CAMISETA       CONFEDERACION           AÑOS CONTRATO          ");
    	printf("--------------------------------------------------------------------------------\n");

    	for(int i = 0; i < tam; i++)
    	{
    		if(!vec[i].isEmpty)
    		{
    			mostrarJugador(vec[i], list, tamConf);
    			flag++;
    		}
    	}
    	if(flag == 0)
    	{
    		printf("No hay jugadores en el sistema!\n");

    	}

    	retorno = 1;
    }


	return retorno;
}








int inicializarJugadores(eJugador list[], int tam)
{
	int retorno = 0;

	if(list != NULL && tam > 0)
	{
		for(int i = 0; i < tam; i++)
		{
			list[i].isEmpty = 1;
		}
		retorno = 1;
	}

	return retorno;
}

int buscarJugadorLibre(eJugador list[], int tam, int* pIndex)
{
	int retorno = 0;

	if(list != NULL && tam > 0 && pIndex != NULL)
	{
		*pIndex = -1;

		for(int i = 0; i < tam; i++)
		{
			if(list[i].isEmpty)
			{
				*pIndex = i;
				break;
			}
		}
	}

	return retorno;
}


int buscarJugador(eJugador list[], int tam, int id, int *pIndex)
{
	int retorno = 0;

	if(list != NULL && tam > 0 && id > 0 && pIndex != NULL)
	{
		*pIndex = -1;
		for(int i = 0; i < tam; i++)
		{
			if(list[i].isEmpty == 0 && list[i].id == id)
			{
				*pIndex = i;
				break;
			}
		}
	}

	return retorno;
}


int hardcodearJugadores(eJugador list[], int tam, int cant, int* pId)
{
	int retorno = 0;

	eJugador jugadores[] =
	{
			{0,"Lionel Messi","Delantero",30,0,200000,2},
			{0,"Givanildo Vieira(Hulk)","Delantero",7,0,800000,3},
			{0,"Mohamed El Shenawy","Arquero",1,0,790000,3},
			{0,"Enzo Copetti","Delantero",9,0,500000,2},
			{0,"Critian Romero","Defensor",2,0,980000,4},
			{0,"Hugo Lloris","Arquero",1,0,800000,2},
			{0,"Eerling Haaland","Delantero",9,0,300000,5},
			{0,"Martín Campaña","Arquero",1,0,600000,3},
			{0,"Martín Benitez","Delantero",10,0,90000,3},
			{0,"Cristiano Ronaldo","Delantero",7,0,160000,2}
	};

	if(list != NULL && tam > 0 && pId != NULL && cant > 0 && cant <= tam)
	{
		for(int i = 0; i < cant; i++)
		{
			list[i] = jugadores[i];
			list[i].id = *pId;
			*pId = *pId + 1;

		}
		retorno = 1;
	}

	return retorno;
}





