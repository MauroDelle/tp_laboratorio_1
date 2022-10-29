/*
 * jugador.c
 *
 *  Created on: 13 oct. 2022
 *      Author: delle
 */


#include "jugador.h"
#include "confederacion.h"
#include "utn.h"
#include "menu.h"



int hardcodearJugadores(eJugador vec[], int tam, int cant, int* pLegajo)
{
	int todoOk = 0;

	eJugador jugadores[] =
	{
			{0,"Lionel Messi", "Delantero", 10,200000,101,4},
			{0,"Givanildo Vieira", "Delantero", 7,100000,100,3},
			{0,"Mohamed El Shenawy", "Arquero", 1,80000,103,2},
			{0,"Enzo Copetti", "Delantero", 9,86000,100,4},
			{0,"Keylor Navas", "Arquero", 1,84000,101,5},
			{0,"Mauro Delle", "Delantero", 30,89000,104,3},
			{0,"Ezequiel Taboada", "Defensor", 2,250000,100,4},
			{0,"Martin Cauteruccio", "Delantero", 9,75000,100,2},
			{0,"Toto Salvio", "Delantero", 11,90000,104,4},
			{0,"Bernardo Silva", "Mediocampista", 8,150000,101,2}
	};

	if(vec != NULL && tam > 0 && pLegajo != NULL && cant > 0 && cant <= tam)
	{
		for(int i = 0;i < cant; i++)
		{
			vec[i] = jugadores[i];
			vec[i].id = *pLegajo;
			*pLegajo = *pLegajo + 1;
		}
		todoOk = 1;
	}

	return todoOk;
}




int modificarJugador(eJugador vec[], int tam, eConfederacion confederaciones[],int tamC)
{
    int todoOk = 0;
    int indice;
    int legajo;
    char salir = 'n';

    char auxCad[100];
    char auxPosicion[100];
    int auxConfederacion;
    int auxCamiseta;
    float auxFloat;
    int auxContrato;

	if(vec != NULL && tam > 0)
	{

		listarJugador(vec, tam, confederaciones, tamC);
		getValidInt("\nINGRESE EL ID DEL JUGADOR: ", "\nINGRESE UN VALOR VALIDO ", "\nINGRESE NUMEROS UNICAMENTE: ", 1,100, &legajo);

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
							getValidString("Ingrese el nombre del jugador: ", "\nError, solo letras", "nINGRESE EN UN RANGO VALIDO: ", auxCad, 1, 50);
		                    strcpy(vec[indice].nombre, auxCad);
		                    printf("Se ha modificado el nombre\n");
							break;
						case 2:
							getValidString("Ingrese la posicion: ", "\nError, solo letras", "nINGRESE EN UN RANGO VALIDO: ", auxPosicion, 1, 50);
		                    strcpy(vec[indice].posicion, auxPosicion);
		                    printf("Se ha modificado la posicion\n");
							break;
						case 3:
							getValidInt("\nINGRESE LA CAMISETA: ", "\nINGRESE UN VALOR VALIDO ", "\nINGRESE NUMEROS UNICAMENTE: ", 1,99, &auxCamiseta);
	                        vec[indice].numeroCamiseta = auxCamiseta;
	                        printf("Se ha modificado el Numero de Camiseta\n");
							break;
						case 4:
							listarConfederaciones(confederaciones, tamC);

							getValidInt("\nINGRESE LA CONFEDERACION: ", "\nINGRESE UN VALOR VALIDO ", "\nINGRESE NUMEROS UNICAMENTE: ", 100,105, &auxConfederacion);
							vec[indice].idConfederacion = auxConfederacion;

							break;
						case 5:
							getFloatValidation(&auxFloat, "Ingrese el salario del jugador: ", "Error! Entre 65000-250000", 50000, 250000);
	                        vec[indice].salario = auxFloat;
	                        printf("Se ha modificado el salario\n");
							break;
						case 6:
							getValidInt("\nINGRESE LOS AÑOS DE CONTRATO: ", "\nINGRESE UN VALOR VALIDO ", "\nINGRESE NUMEROS UNICAMENTE: ", 1,6, &auxContrato);
							vec[indice].aniosContrato = auxContrato;
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
		getValidInt("\nINGRESE EL ID DEL JUGADOR: ", "\nINGRESE UN VALOR VALIDO ", "\nINGRESE NUMEROS UNICAMENTE: ", 0,20, &legajo);

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

	int auxCamiseta;
	char auxCad[100];
	char auxPosicion[100];
	float auxFloat;
	int auxContrato;
	int auxConfe;


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

				getValidString("Ingrese el nombre del jugador: ", "\nError, solo letras", "nINGRESE EN UN RANGO VALIDO: ", auxCad, 1, 50);
				strcpy(nuevoJugador.nombre, auxCad);

				getValidString("Ingrese la posicion: ", "\nError, solo letras", "nINGRESE EN UN RANGO VALIDO: ", auxPosicion, 1, 50);
				strcpy(nuevoJugador.posicion, auxPosicion);

				getValidInt("\nINGRESE LA CAMISETA: ", "\nINGRESE UN VALOR VALIDO ", "\nINGRESE NUMEROS UNICAMENTE: ", 1,99, &auxCamiseta);
				nuevoJugador.numeroCamiseta= auxCamiseta;

				getFloatValidation(&auxFloat, "Ingrese el salario del jugador: ", "Error! Entre 65000-250000", 50000, 250000);
				nuevoJugador.salario = auxFloat;

				getValidInt("\nINGRESE LOS AÑOS DE CONTRATO: ", "\nINGRESE UN VALOR VALIDO ", "\nINGRESE NUMEROS UNICAMENTE: ", 1,6, &auxContrato);
				nuevoJugador.aniosContrato = auxContrato;

                listarConfederaciones(confederaciones, tamConf);
				getValidInt("\nINGRESE LA CONFEDERACION: ", "\nINGRESE UN VALOR VALIDO ", "\nINGRESE NUMEROS UNICAMENTE: ", 100,105, &auxConfe);
				nuevoJugador.idConfederacion = auxConfe;

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


    	printf("|%4d  |  %-20s       |  %-13s    |    %4d       |  %11.2f  |        %4d      |    %-11s|\n",e.id,
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
		printf("|        					*** LISTADO DE JUGADORES ***                                                |\n");
		printf("|                                                                                                                           |\n");
		printf("|------|-----------------------------|-------------------|---------------|---------------|------------------|---------------|\n");
		printf("|  ID  |   NOMBRE                    |   POSICION        |   N°CAMISETA  |    SUELDO     | AÑOS de CONTRATO | CONFEDERACION |\n");
        printf("|------|-----------------------------|-------------------|---------------|---------------|------------------|---------------|\n");

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




