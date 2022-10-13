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
#define TAM 8
#define TAMC 5
int main(void){

	setbuf(stdout,NULL);

	int opcion;
	int flagIngreso = 0;

	int proximoId = 1;

	eJugador lista[TAM];
	eConfederacion confederaciones[TAMC];

	inicializarJugadores(lista, TAM);
	hardcodearJugadores(lista, TAM, 5, &proximoId);


	do
	{
		opcion = menuPrincipal();

		switch(opcion)
		{
			case 1:
				printf("Hola");
				altaJugador(lista, TAM, confederaciones, TAMC, &proximoId);	//averiguar pq no toma esto
				flagIngreso = 1;

				break;
			case 2:
					if(flagIngreso == 0)
					{
						printf("Primero de un jugador de alta!\n");
					}
					else
					{

					}
				break;
			case 3:
				if(flagIngreso == 0)
				{
					printf("Primero de un jugador de alta!\n");
				}
				else
				{

				}
				break;
			case 4:
				if(flagIngreso == 0)
				{
					printf("Primero de un jugador de alta!\n");
				}
				else
				{

					listarJugadores(lista, TAM, confederaciones, TAMC);

				}
				break;
			case 5:
					printf("Adios..!\n");
				break;

		}

	}while(opcion != 5);





	return 0;
}




