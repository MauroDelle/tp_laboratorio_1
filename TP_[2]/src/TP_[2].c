/*
 ============================================================================
 Name        : TP_[2].c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "confederacion.h"
#include "menu.h"
#include "jugador.h"
#define TAMC 6
#define TAM 10
int main(void){

	setbuf(stdout,NULL);

	int opcion;
	int flagIngreso = 0;
	int proximoId = 1;


	eJugador jugadores[TAM];
	eConfederacion confederaciones[TAMC] =
	{
			{100,"CONMEBOL","SUDAMERICA",1916},
			{101,"UEFA","EUROPA",1954},
			{102,"AFC","ASIA",1954},
			{103,"CAF","AFRICA",1957},
			{104,"CONCACAF","NORTE Y CENTRO AMERICA",1961},
			{105,"OFC","OCEANIA",1966}
	};

	inicializarJugador(jugadores, TAM);


	do
	{
		opcion = menuPrincipal();

		switch(opcion)
		{
			case 1:
				flagIngreso = 1;

				if(altaJugador(jugadores, TAM, confederaciones, TAMC, &proximoId))
				{
					printf("Jugador agregado con exito!\n");
				}
				else
				{
					printf("Hubo un problema al hacer el alta del jugador\n");
				}

				break;
			case 2:
					if(flagIngreso == 0)
					{
						printf("Primero de un jugador de alta!\n");
					}
					else
					{
						if(bajaJugador(jugadores, TAM, confederaciones, TAMC) == 0)
						{
							printf("Problema al realizar la baja del jugador :(\n");
						}
					}
				break;
			case 3:
				if(flagIngreso == 0)
				{
					printf("Primero de un jugador de alta!\n");
				}
				else
				{
					if(modificarJugador(jugadores, TAM, confederaciones, TAMC) == 0)
					{
						printf("Hubo un problema al modificar el jugador\n");
					}
				}
				break;
			case 4:
				if(flagIngreso == 0)
				{
					printf("Primero de un jugador de alta!\n");
				}
				else
				{

						listarJugador(jugadores, TAM, confederaciones, TAMC);

				}
				break;
			case 5:
					printf("Adios..!\n");
				break;

		}

	}while(opcion != 5);





	return 0;
}




