/*
 * informes.c
 *
 *  Created on: 29 oct. 2022
 *      Author: delle
 */

#include "informes.h"
#include <ctype.h>
#define OCUPADO 1

int superanSueldoPromedio(eJugador list[], int tam, float promedio,eConfederacion confederaciones[], int tamC)
{
    int i;
    int isOk=-1;

    if(list != NULL && tam > 0 && promedio > 0)
    {
        printf(" jugadores que superan el salario promedio: \n");
        for(i = 0; i < tam; i++)
        {
            if((list[i].isEmpty!= 1) && (list[i].salario > promedio))
            {
            	mostrarJugador(list[i], confederaciones, tamC);
            	isOk = 0;
            }
        }
    }

    return isOk;
}

int calcularSalarios(eJugador list[], int tam,eConfederacion confederaciones[], int tamC)
{
	int todoOk = 0;
	float promedio;
	float acumulador = 0;
	int contador = 0;

	if(list != NULL && tam > 0)
	{
		for(int i = 0;i< tam;i++)
		{
			if(list[i].isEmpty != 1)
			{
				acumulador += list[i].salario;
				contador++;
				todoOk = 1;
			}
		}
		promedio = acumulador /contador;
		printf("El total de los salarios es: %.3f\n", acumulador);
		printf("El promedio de los sueldo es: %.3f\n",promedio);

		superanSueldoPromedio(list, tam, promedio, confederaciones, tamC);

	}

	return todoOk;
}


int confederacionMayorAniosContrato(eJugador vec[], int tam,eConfederacion confederaciones[], int tamC)
{
	int todoOk = 0;
	int totalContrato[tamC];
	int mayor;
	int flag = 1;

	if(vec != NULL && confederaciones != NULL && tam > 0 && tamC > 0)
	{
        system("cls");
        printf("   *** Confederacion que mas años de contrato tienen ***\n");
        printf("------------------------------------------------------------\n");

        for(int i = 0; i< tamC; i++)
        {
        	totalContrato[i] = 0;
        }
        for(int s = 0; s< tamC;s++)
        {
        	for(int e = 0;e < tam; e++)
        	{
        		if(!vec[e].isEmpty && vec[e].idConfederacion == confederaciones[s].id)
        		{
        			totalContrato[s] += vec[e].aniosContrato;
        		}
        	}
        }
        for(int s = 0; s< tamC;s++)
        {
        	if(flag || totalContrato[s] > mayor)
        	{
        		mayor = totalContrato[s];
        		flag = 0;
        	}
        }
        printf("La confederacion con mayor cantidad de años de contratos tiene: %d y es: \n", mayor);
        for(int s = 0; s < tamC;s++)
        {
        	if(totalContrato[s] == mayor)
        	{
        		printf("%s\n", confederaciones[s].nombre);
        	}
        }

        todoOk = 1;
	}

	return todoOk;
}






int primerListado(eJugador jugadores[], int tamJ,eConfederacion confederaciones[], int tamC, int order)
{
	int retorno = 0;
    char confederacionJugador1[50];
    char confederacionJugador2[50];
    eJugador aux;



    if(jugadores != NULL && tamJ > 0 && confederaciones != NULL && tamC > 0)
    {
    	if(order == 0)
    	{ // A to Z sorting
    			for(int i=0;i<tamJ - 1;i++){
    				for(int j = i + 1;j<tamJ;j++)
    				{
    					    for(int y = 0; y < tamC; y ++ )
    					    {
    					        if(confederaciones[y].id == jugadores[i].idConfederacion)
    					        {
    					            strcpy(confederacionJugador1, confederaciones[y].nombre);
    					            break;
    					        }
    					    }
    	                    for(int y = 0; y < tamC; y ++ )
    					    {
    					        if(confederaciones[y].id == jugadores[j].idConfederacion)
    					        {
    					            strcpy(confederacionJugador2, confederaciones[y].nombre);
    					            break;
    					        }
    					    }

    						if(strcmp(confederacionJugador1, confederacionJugador2)>0){
    							// COPY TO AUXILIAR VAR

    							aux = jugadores[i];

    							// SWAP of values

    							jugadores[i] = jugadores[j];

    							// RE-SET OF VALUES

    							jugadores[j]=aux;
    						}
    						else{
    							if(strcmp(confederacionJugador1, confederacionJugador2)==0){
    								if(strcmp(jugadores[i].nombre, jugadores[j].nombre) > 0){ // FROM MAX TO MIN
    									// COPY TO AUXILIAR VAR

    									aux = jugadores[i];

    									// SWAP of values

    									jugadores[i] = jugadores[j];

    									// RE-SET OF VALUES

    									jugadores[j]=aux;
    								}
    							}
    						}
    				}
    			}

    		}

    	for(int t = 0; t < tamJ; t++)
    	{
    		mostrarJugador(jugadores[t], confederaciones, tamC);
    	}

    	retorno = 1;
    }


	return retorno;
}



int listarConfederacionesYJugadores(eJugador vec[], int tam,eConfederacion confederaciones[], int tamC)
{
	int todoOk = 0;
	int flag;

	if(vec != NULL && tam > 0 && confederaciones != NULL && tamC > 0)
	{
        printf("    *** Listado de Confederaciones con sus jugadores  ***\n");
        printf("------------------------------------------------------------\n");

        for(int i = 0; i < tamC; i++)
        {
        	printf("Confederacion: %s\n",confederaciones[i].nombre);
        	printf(" ID          NOMBRE        POSICION    CAMISETA    SALARIO        CONTRATO       CONFEDERACION\n\n\n");
        	flag = 1;

        	for(int e = 0; e < tam; e++)
        	{
        		if(!vec[e].isEmpty && vec[e].idConfederacion == confederaciones[i].id)
        		{
        			mostrarJugador(vec[e], confederaciones, tamC);

        			flag = 0;
        		}
        	}
        	if(flag)
        	{
        		printf("No hay jugadores\n");
        	}
        	printf("\n\n");
        }
		todoOk = 1;
	}
	return todoOk;
}




/*
int informe_RegionConMasJugadores(eJugador jugadores[], int tamJ,eConfederacion confederaciones[],int tamC)
{
	int retorno = 0;
	int cantidadMaxPendientes;
	int contadorPendientes;
	int i;
	int j;

	if(jugadores != NULL && tamJ > 0 && confederaciones != NULL && tamC)
	{
		if(maximo_JugadoresPorConfederacion(jugadores, tamJ, confederaciones, tamC, &cantidadMaxPendientes) == 1)
		{

			printf("\n");
			printf("\n                         REGION CON MAS JUGADORES                                    \n");
			printf(" ID          NOMBRE        POSICION    CAMISETA    SALARIO        CONTRATO       REGION\n\n\n");

			for(i=0;i<tamJ;i++)
			{

				if(jugadores[i].isEmpty != 1)
				{

					for(j=0;j<tamC;j++)


				}
			}
		}
	}

	return retorno;
}
*/


int maximo_JugadoresPorConfederacion(eJugador jugadores[], int tamJ,eConfederacion confederaciones[],int tamC,int* cantidadJugadores)
{
	int retorno = 0;
	int contadorJugadores;
	int auxCantidadJugadores;
	int i;

	if(jugadores != NULL && tamJ > 0 && confederaciones != NULL && tamC > 0 && cantidadJugadores != NULL)
	{
		for(i = 0; i < tamJ; i++)
		{
			if(jugadores[i].isEmpty  != 1)
			{
				if(contador_porConfederacion(jugadores[i], confederaciones, tamC, &contadorJugadores) == 1)
				{
					if(contadorJugadores > auxCantidadJugadores)
					{
						auxCantidadJugadores = contadorJugadores;
					}
					contadorJugadores = 0;
				}
			}
		}
		retorno = 1;
		*cantidadJugadores = auxCantidadJugadores;
	}
	return retorno;
}





int contador_porConfederacion(eJugador unJugador,eConfederacion listConfederacion[], int tamConf, int* contador)
{
	int retorno = 0;
	int auxContador = 0;
	int i;

	if(listConfederacion != NULL && tamConf > 0 && contador != NULL)
	{
		for(i = 0; i< tamConf; i++)
		{
			if(listConfederacion[i].isEmpty != 1 && listConfederacion[i].id == unJugador.idConfederacion)
			{
				auxContador++;
				retorno = 1;
			}
		}
	}

	*contador = auxContador;

	return retorno;
}




int porcentajeJugadoresXConfederacion(eJugador jugadores[], int tam, eConfederacion confederaciones[], int tamC)
{
	int retorno = -1;


	if(jugadores != NULL && confederaciones != NULL && tam >0 && tamC > 0)
	{






	}

	return retorno;
}


int contarCantidadJugadores(eJugador jugadores[], int tam,int id,int* cantidad)
{
	int retorno = -1;
	int contadorJugador = 0;

	if(jugadores != NULL && tam > 0)
	{
		for(int i = 0;i< tam;i++)
		{
			if(jugadores[i].isEmpty == OCUPADO && jugadores[i].idConfederacion == id)
			{
				contadorJugador++;
				*cantidad = contadorJugador;
			}
		}
		*cantidad = contadorJugador;
		retorno = 1;
	}
	return retorno;
}

















