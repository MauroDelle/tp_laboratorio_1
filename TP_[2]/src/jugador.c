/*
 * jugador.c
 *
 *  Created on: 13 oct. 2022
 *      Author: delle
 */
#include "jugador.h"
#include "confederacion.h"
#include "menu.h"



int modificarJugador(eJugador vec[], int tam, eConfederacion confederaciones[],int tamC)
{
    int todoOk = 0;
    int indice;
    int legajo;
    char salir = 'n';
    char auxCad[100];
    char auxPosicion[100];
    eJugador nuevoJugador;

	if(vec != NULL && tam > 0)
	{

		listarJugador(vec, tam, confederaciones, tamC);
		printf("Ingrese el ID del jugador que desea modificar: ");
		scanf("%d", &legajo);

		if(buscarJugador(vec, tam, legajo, &indice))
		{
			if(indice == -1)
			{
				printf("no hay un jugador con el ID %d\n", legajo);
			}
			else
			{
				mostrarJugador(vec[indice], confederaciones, tamC);

				do
				{
					switch(menuModificarJugador())
					{
						case 1:
							printf("Ingrese nuevo nombre: ");
		                    fflush(stdin);
		                    gets(auxCad);
		                    strcpy(vec[indice].nombre, auxCad);
		                    printf("Se ha modificado el nombre\n");
							break;
						case 2:
							printf("Ingrese la nueva posicion: ");
		                    fflush(stdin);
		                    gets(auxPosicion);
		                    strcpy(vec[indice].posicion, auxPosicion);
		                    printf("Se ha modificado la posicion\n");
							break;
						case 3:
	                        printf("Ingrese el nuevo Numero de Camiseta: ");
	                        scanf("%d", &vec[indice].numeroCamiseta);
	                        printf("Se ha modificado el Numero de Camiseta\n");
							break;
						case 4:




							break;
						case 5:
	                        printf("Ingrese nuevo salario: ");
	                        scanf("%f", &vec[indice].salario);
	                        printf("Se ha modificado el salario\n");
							break;
						case 6:
	                        printf("Ingrese los años de contrato: ");
	                        scanf("%d", &vec[indice].aniosContrato);
	                        printf("Se han modificado los años de contrato\n");
							break;
						case 7:
							salir = 's';
							break;
					}
				}while(salir != 's');
			}
		}
		else
		{
			printf("Ocurrio un problema al buscar al jugador!\n");
		}

		todoOk = 1;

	}

    return todoOk;
}

int bajaJugador(eJugador vec[], int tam, eConfederacion confederaciones[], int tamC)
{
    int todoOk = 0;
    int indice;
    int legajo;
    char confirma;


    if(vec != NULL && tam > 0)
    {
    	listarJugador(vec, tam, confederaciones, tamC);
    	printf("Ingrese ID: ");
    	scanf("%d", &legajo);

    	if(buscarJugador(vec, tam, legajo, &indice))
    	{

    			if(indice == -1)
    			{
    				printf("No hay un jugador con el ID  %d\n", legajo);
    			}
    			else
    			{
    				mostrarJugador(vec[indice], confederaciones, tamC);
    				printf("Confirmar Baja?: ");
    				fflush(stdin);
    				scanf("%c", &confirma);

    				if(confirma != 'S' && confirma != 's')
    				{
    					printf("Baja cancelada por el usuario!\n");
    				}
    				else
    				{
    					vec[indice].isEmpty = 1;
    					printf("Baja realizada con exito!\n");
    					todoOk = 1;
    				}
    			}
    	}
    	else
    	{
    		printf("Ocurrio un problema al buscar el jugador!\n");

    	}

    	todoOk = 1;
    }

    return todoOk;
}


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

                printf("Ingrese los años de contrato: ");
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
		printf("|ID  |   NOMBRE   |     | POSICION   | N°CAMISETA |  SUELDO    | AÑOS de CONTRATO  | CONFEDERACION |\n");
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




