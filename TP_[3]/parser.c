#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Jugador.h"
#include "Seleccion.h"


int parser_saveAsBinary(FILE* pFile , LinkedList* pArrayListJugadores)
{
	int retorno = 0;
	int escrito;

	Jugador* auxJugador = NULL;

	for(int i = 0;i<ll_len(pArrayListJugadores);i++)
	{
		auxJugador = ll_get(pArrayListJugadores, i);
		escrito = fwrite(auxJugador,sizeof(Jugador),1,pFile);
		if(escrito < 1)
		{
			retorno = -1;
			break;
		}
	}
	return retorno;
}

/** \brief Parsea los datos de los jugadores desde el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 */
int parser_JugadorFromText(FILE* pFile , LinkedList* pArrayListJugador)
{
    int todoOk = 0;
    int elementoUno = 1;

    //auxiliares
    Jugador *pAuxJugador;
    char auxId[5000];
    char nombreCompleto[5000];
    char edad[5000];
    char posicion[5000];
    char nacionalidad[5000];
    char idSeleccion[5000];

    if(pFile != NULL)
    {
    	while(!feof(pFile))
    	{
    		if(elementoUno)
    		{
    			fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",auxId,
    					                                     nombreCompleto,
															 edad,
															 posicion,
															 nacionalidad,
															 idSeleccion);
    			elementoUno = 0;
    		}

			fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",auxId,
					                                     nombreCompleto,
														 edad,
														 posicion,
														 nacionalidad,
														 idSeleccion);
			pAuxJugador = jug_newParametros(auxId, nombreCompleto, edad, posicion, nacionalidad, idSeleccion);

			if(pAuxJugador != NULL)
			{
				ll_add(pArrayListJugador,pAuxJugador);
				todoOk = 1;
			}
    	}
    }
    return todoOk;
}

/** \brief Parsea los datos de los jugadores desde el archivo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int parser_JugadorFromBinary(FILE* pFile , LinkedList* pArrayListJugador)
{
    return 1;
}


/** \brief Parsea los datos de los selecciones desde el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int parser_SeleccionFromText(FILE* pFile , LinkedList* pArrayListSeleccion)
{
	int todoOk = 0;
	int elementoUno=1;

	Seleccion * pAuxSeleccion;

	char auxId[5000];
	char auxPais[5000];
	char auxConfederacion[5000];
	char auxConvocados[5000];

	if(pFile != NULL)
	{
		while(!feof(pFile))
		{
			if(elementoUno)
			{
				fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",auxId,auxPais,auxConfederacion,auxConvocados);
				elementoUno = 0;
			}
			fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",auxId,auxPais,auxConfederacion,auxConvocados);

			pAuxSeleccion = selec_newParametros(auxId, auxPais, auxConfederacion, auxConvocados);

			if(pAuxSeleccion != NULL)
			{
				ll_add(pArrayListSeleccion, pAuxSeleccion);
				todoOk = 1;
			}
		}
	}

	return todoOk;
}


int parser_saveAsText(FILE* pArchivo, LinkedList* pArrayListJugador)
{
	int retorno;
	Jugador* jugadorAux = NULL;

	int idAux;
	int idSeleccion;
	int edadAux;
	char nombreCompleto[100], posicion[30], nacionalidad[30];

	fprintf(pArchivo,"id,nombre completo,edad,posicion,nacionalidad,id seleccion\n");
		for(int i = 0; i< ll_len(pArrayListJugador); i++)
		{
			jugadorAux=ll_get(pArrayListJugador, i);
			if(jugadorAux!=NULL)
			{
				jug_getId(jugadorAux, &idAux);
				jug_getNombreCompleto(jugadorAux, nombreCompleto);
				jug_getEdad(jugadorAux, &edadAux);
				jug_getPosicion(jugadorAux, posicion);
				jug_getNacionalidad(jugadorAux, nacionalidad);
				jug_getSIdSeleccion(jugadorAux, &idSeleccion);
				fprintf(pArchivo,"%d,%s,%d,%s,%s,%d\n",idAux,nombreCompleto,edadAux,posicion,nacionalidad,idSeleccion);

			}
			else
			{
				retorno = -1;
				break;
			}
		}
	return retorno;
}

int parser_saveAsTextSeleccion(FILE* pArchivo, LinkedList* pArrayListSeleccion)
{
	int retorno = 0;
	Seleccion* seleccionAux = NULL;

	int idAux;
	char pais[30];
	char confederacion[30];
	int auxConvocados;

	fprintf(pArchivo,"id,pais,confederacion,convocados\n");

	for(int i = 0;i< ll_len(pArrayListSeleccion); i++)
	{
		seleccionAux = ll_get(pArrayListSeleccion, i);
		if(seleccionAux != NULL)
		{
			selec_getId(seleccionAux, &idAux);
			selec_getPais(seleccionAux, pais);
			selec_getConfederacion(seleccionAux, confederacion);
			selec_getConvocados(seleccionAux, &auxConvocados);
			fprintf(pArchivo,"%d,%s,%s,%d\n",idAux,pais,confederacion,auxConvocados);
		}
		else
		{
			retorno = -1;
			break;
		}
	}
	return retorno;
}




