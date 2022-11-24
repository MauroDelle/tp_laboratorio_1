/*
 * ingresoDatos.c
 *
 *  Created on: 23 nov. 2022
 *      Author: Mauro delle
 */
#include <stdlib.h>
#include <stdio.h>
#include "utn.h"
#include "LinkedList.h"
#include "ingresoDatos.h"

int utn_getPosicionValida(char* pResultado)
{
	int todoOk = 0;
	int banderaPosicionValida = 1;
	if(pResultado != NULL)
	{
		do
		{
			if(banderaPosicionValida == 0)
			{
				printf("\n[ERROR. INGRESE UNA POSICION VALIDA]");
			}
			utn_getNombre(pResultado, 28, "\nPOSICIONES: \nDelantero centro\nPortero\nDefensa central\nLateral izquierdo\nLateral derecho\nPivote\nMediocentro\nExtremo izquierdo\nExtremo derecho\nMediocentro ofensivo\nMediapunta\nINGRESE POSICION DEL JUGADOR: ", "\n[ERROR SOLO LETRAS, MAX. 28 CARACTERES Y SIN ESPACIOS.]", 100);
			banderaPosicionValida = utn_esPosicionValida(pResultado);
		}while(banderaPosicionValida == 0);
	}
	return todoOk;
}

int utn_getConfederacionValida(char* pResultado)
{
	int todoOk = 0;
	int banderaConfeValida = 1;
	if(pResultado != NULL)
	{
		do
		{
			if(banderaConfeValida == 0)
			{
				printf("\n[ERROR. INGRESE UNA CONFEDERACION VALIDA]");
			}
			utn_getNombre(pResultado, 28, "\nCONFEDERACIONES: \nAFC\nCAF\nCONCACAF\nCONMEBOL\nUEFA\nINGRESE CONFEDERACION: ", "\n[ERROR SOLO LETRAS, MAX. 28 CARACTERES Y SIN ESPACIOS.]", 100);
			banderaConfeValida = utn_esConfederacionValida(pResultado);
		}while(banderaConfeValida == 0);
	}
	return todoOk;
}

int utn_esConfederacionValida(char* confederacion)
{
	int todoOk = 0;
	char confederaciones[][28] =
	{
		"AFC",
		"CAF",
		"CONCACAF",
		"CONMEBOL",
		"UEFA"
	};
	for(int i = 0; i < 11; i++)
	{
		if(strcmp(confederacion, confederaciones[i])==0)
		{
			todoOk = 1;
			break;
		}
	}
	return todoOk;
}

int utn_esPosicionValida(char* posicion)
{
	int todoOk = 0;
	char posiciones[][28] =
	{
		"Delantero centro",
		"Portero",
		"Defensa central",
		"Lateral izquierdo",
		"Lateral derecho",
		"Pivote",
		"Mediocentro",
		"Extremo izquierdo",
		"Extremo derecho",
		"Mediocentro ofensivo",
		"Mediapunta"
	};
	for(int i = 0; i < 11; i++)
	{
		if(strcmp(posicion, posiciones[i])==0)
		{
			todoOk = 1;
			break;
		}
	}
	return todoOk;
}

