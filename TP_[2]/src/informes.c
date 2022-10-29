/*
 * informes.c
 *
 *  Created on: 29 oct. 2022
 *      Author: delle
 */

#include "informes.h"
#include <ctype.h>



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






