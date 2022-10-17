/*
 * jugador.c
 *
 *  Created on: 13 oct. 2022
 *      Author: delle
 */
#include "jugador.h"
#include "confederacion.h"




int altaJugador(eJugador vec[],int tam, eConfederacion confederaciones[], int tamConf, int* pLegajo)
{
	int todoOk = 0;
	int indice;
	char auxCad[100];
	char auxPosicion[100];
	eJugador nuevoJugador;


	if(vec != NULL && tam > 0 && pLegajo != NULL)
	{
		if(buscarJugadorLibre(vec, tam, &indice))
		{
			if(indice == -1)
			{
				printf("No hay lugar en el sistema!\n");
			}
			else
			{
				printf("Ingrese el nombre del jugador: ");
                fflush(stdin);
                gets(auxCad);

                while(strlen(auxCad) >= 50)
                {
    				printf("Nombre demasiado largo. Reingrese nombre: ");
                    fflush(stdin);
                    gets(auxCad);
                }
                strcpy(nuevoJugador.nombre, auxCad);


                printf("Ingrese la posicion del jugador: ");
                fflush(stdin);
                gets(auxPosicion);

                while(strlen(auxPosicion) >= 50)
                {
    				printf("La posicion es demasiado larga. Reingrese posicion: ");
                    fflush(stdin);
                    gets(auxPosicion);
                }
                strcpy(nuevoJugador.posicion, auxPosicion);


                printf("Ingrese el numero de camiseta: ");
                scanf("%d", &nuevoJugador.numeroCamiseta);


                printf("Ingrese el salario del jugador: ");
                scanf("%f", &nuevoJugador.salario);

                printf("Ingrese los a�os de contrato: ");
                scanf("%d", &nuevoJugador.aniosContrato);

                listarConfederaciones(confederaciones, tamConf);

                printf("Ingrese el ID de la Confederacion: ");
                scanf("%d", &nuevoJugador.idConfederacion);

                while(!validarConfederacion(confederaciones, tamConf, nuevoJugador.idConfederacion))
                {
                	printf("Confederacion Invalida. Reingrese ID: ");
                	scanf("%d", &nuevoJugador.idConfederacion);

                }

                nuevoJugador.isEmpty = 0;
                nuevoJugador.id = *pLegajo;
                *pLegajo = *pLegajo + 1;
                vec[indice] = nuevoJugador;
                todoOk = 1;
			}
		}
		else
		{
			printf("Ocurrio un problema con los parametros!\n");
		}
	}
	return todoOk;
}



int mostrarJugador(eJugador e,eConfederacion confederaciones[],int tam)
{
    int todoOk = 0;
    char nombreConfederacion[20];

    if(confederaciones != NULL && tam > 0)
    {
    	cargarDescripcionConfederaciones(confederaciones, tam, e.idConfederacion, nombreConfederacion);


    	printf("%d     %s         %s        %d         %0.1f          %d               %s\n",e.id,
    			                                                                     e.nombre,
																				   e.posicion,
																		     e.numeroCamiseta,
																			        e.salario,
																			  e.aniosContrato,
																		  nombreConfederacion);
    	todoOk = 1;
    }


    return todoOk;
}


int listarJugador(eJugador vec[], int tam, eConfederacion confederaciones[], int tamConf)
{
	int todoOk = 0;
	int flag = 0;


	if(vec != NULL && tam >0)
	{
		printf("          *** Listado de Jugadores ***\n\n");
		printf("|ID  |   NOMBRE   |     | POSICION   | N�CAMISETA |  SUELDO    | A�OS de CONTRATO  | CONFEDERACION |\n");
        printf("-----------------------------------------------------------------------------------------------------\n");

        for(int i = 0; i < tam; i++)
        {
        	if(!vec[i].isEmpty)
        	{
        		mostrarJugador(vec[i], confederaciones, tam);
        		flag++;
        	}
        }
        if(flag == 0)
        {
        	printf("No hay jugadores en el sistema!\n");
        }
        printf("\n\n");

        todoOk = 1;
	}

	return todoOk;
}








int inicializarJugador(eJugador vec[], int tam)
{
    int todoOk = 0;
    if(vec != NULL && tam > 0)
    {
        for(int i=0; i < tam; i++)
        {
            vec[i].isEmpty = 1;
        }
        todoOk = 1;
    }
    return todoOk;
}


int buscarJugadorLibre(eJugador vec[], int tam, int* pIndex)
{
    int todoOk = 0;
    if(vec != NULL && tam > 0 && pIndex != NULL)
    {
        *pIndex = -1;
        for(int i=0; i < tam; i++)
        {
            if( vec[i].isEmpty )
            {
                *pIndex = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;

}

int buscarJugador(eJugador vec[], int tam,int legajo, int *pIndex)
{
    int todoOk = 0;
    if(vec != NULL && tam > 0 && pIndex != NULL && legajo > 0)
    {
        *pIndex = -1;
        for(int i=0; i < tam; i++)
        {
            if(vec[i].isEmpty == 0 &&  vec[i].id == legajo)
            {
                *pIndex = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;

}




