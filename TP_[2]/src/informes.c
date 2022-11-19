/*
 * informes.c
 *
 *  Created on: 29 oct. 2022
 *      Author: delle
 */

#include "informes.h"
#include "utn.h"
#include <ctype.h>
#define OCUPADO 0

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
		int auxConme;
		int auxUefa;
		int audOfc;
		int auxAfc;
		int auxConcacaf;
		int auxCaf;
		int total;
		float porcentaje;

		contarCantidadJugadores(jugadores, tam, 100, &auxConme);
		contarCantidadJugadores(jugadores, tam, 101, &auxUefa);
		contarCantidadJugadores(jugadores, tam, 102, &audOfc);
		contarCantidadJugadores(jugadores, tam, 103, &auxAfc);
		contarCantidadJugadores(jugadores, tam, 104, &auxConcacaf);
		contarCantidadJugadores(jugadores, tam, 105, &auxCaf);
		total = auxConme + auxUefa + audOfc + auxAfc + auxConcacaf + auxCaf;
		limpioPantalla();

		if(sacarPorcentaje(auxConme, total, &porcentaje) == 1)
		{
			printf("El porcentaje de jugadores en conmebol es : %.2f\n",porcentaje);
		}
		if(sacarPorcentaje(auxUefa, total, &porcentaje) == 1)
		{
			printf("El porcentaje de jugadores en uefa es : %.2f\n",porcentaje);
		}
		if(sacarPorcentaje(audOfc, total, &porcentaje) == 1)
		{
			printf("El porcentaje de jugadores en ofc es : %.2f\n",porcentaje);
		}
		if(sacarPorcentaje(auxAfc, total, &porcentaje) == 1)
		{
			printf("El porcentaje de jugadores en AFC es : %.2f\n",porcentaje);
		}
		if(sacarPorcentaje(auxConcacaf, total, &porcentaje) == 1)
		{
			printf("El porcentaje de jugadores en concacaf es : %.2f\n",porcentaje);
		}
		if(sacarPorcentaje(auxCaf, total, &porcentaje) == 1)
		{
			printf("El porcentaje de jugadores en caf es : %.2f\n",porcentaje);
		}

		limpioPantalla();

		retorno = 1;
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


int sacarPorcentaje(int cant1,int cantidad2,float* retorno)
{
	int todoOk = -1;
	float resultado;

	if(cantidad2 != 0)
	{
		resultado = (float)cant1 * 100 / cantidad2;
		*retorno = resultado;
		todoOk = 1;
	}
	else
	{
		todoOk = 0;
	}

	return todoOk;
}

int listarRegionMasJugadores(eJugador jugadores[], int tam, eConfederacion confederaciones[], int tamC)
{
	int todoOk=-1;
	int contador=0;
	int cantidadMayor;
	cantJugadoresMayorConfederacion(jugadores, tam, &cantidadMayor);
	if(jugadores!=NULL&&tam>0&&confederaciones!=NULL&&tamC>0)
	{
		for(int i=0;i<tamC;i++)
		{
			contador=0;
			for(int j=0;j<tam;j++)
			{
				if(jugadores[j].isEmpty==OCUPADO&&confederaciones[i].id==jugadores[j].idConfederacion)
				{
					contador++;
					if(contador>=cantidadMayor)
					{
						printf("\nLa REGION %s tiene mayor cantidad de jugadores : %d\n",confederaciones[i].nombre,cantidadMayor);
						mostrar_Por_Id(jugadores, tam, confederaciones, tamC, confederaciones[i].id);

					}
				}
			}
		}
		todoOk=1;
	}

	return todoOk;
}




int cantJugadoresMayorConfederacion(eJugador jugadores[], int tam, int* cant)
{
	int todoOk = -1;
	if (jugadores != NULL && tam > 0) {
		int auxRetConnme;
		int auxRetUefa;
		int auxRetOfc;
		int auxRetAfc;
		int auxRetConcaf;
		int auxRetCaf;
		contarCantidadJugadores(jugadores, tam, 100, &auxRetConnme);
		contarCantidadJugadores(jugadores, tam, 101, &auxRetUefa);
		contarCantidadJugadores(jugadores, tam, 102, &auxRetCaf);
		contarCantidadJugadores(jugadores, tam, 103, &auxRetAfc);
		contarCantidadJugadores(jugadores, tam, 104, &auxRetConcaf);
		contarCantidadJugadores(jugadores, tam, 105, &auxRetOfc);
		if (auxRetConnme >= auxRetUefa && auxRetConnme >= auxRetCaf
				&& auxRetConnme >= auxRetAfc && auxRetConnme >= auxRetConcaf
				&& auxRetConnme >= auxRetOfc) {
			*cant = auxRetConnme;
		} else {
			if (auxRetUefa >= auxRetCaf && auxRetUefa >= auxRetAfc
					&& auxRetUefa >= auxRetConcaf && auxRetUefa >= auxRetOfc) {
				*cant = auxRetUefa;
			} else {
				if (auxRetCaf >= auxRetAfc && auxRetCaf >= auxRetConcaf
						&& auxRetCaf >= auxRetOfc) {
					*cant = auxRetCaf;
				} else {
					if (auxRetAfc >= auxRetConcaf && auxRetAfc >= auxRetOfc) {
						*cant = auxRetAfc;
					} else {
						if (auxRetConcaf >= auxRetOfc) {
							*cant = auxRetConcaf;
						} else {
							*cant = auxRetOfc;
						}
					}
				}
			}
		}
		todoOk = 1;
	}

	return todoOk;
}


int mostrar_Por_Id(eJugador jugadores[], int tam,eConfederacion tipos[], int tamT , int id)
{
	int todoOk=-1;
		for(int i=0;i<tam;i++)
		{
			if(jugadores[i].isEmpty==OCUPADO&&jugadores[i].idConfederacion==id)
			{
				mostrarJugador(jugadores[i], tipos, tamT);
			}
		}
	return todoOk;
}





