/*
 ============================================================================
 Name        : TP_[2].c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include "utn.h"
#include <stdio.h>
#include <stdlib.h>
#include "confederacion.h"
#include "menu.h"
#include "jugador.h"
#include "informes.h"

int main(void){

	setbuf(stdout,NULL);

	int opcion;
	int flagIngreso = 0;
	int proximoId = 1;
	int proximoIdConfederaciones = 100;
	char preguntaSalir;
	char salir = 'n';
	int opcionInforme;


	eJugador jugadores[TAM];
	eConfederacion confederaciones[TAMC];

	inicializarJugador(jugadores, TAM);
	hardcodearJugadores(jugadores, TAM, 10, &proximoId);
	inicializarConfederacion(confederaciones, TAMC);
	hardcodearConfederaciones(confederaciones, TAMC, 6, &proximoIdConfederaciones);
	flagIngreso = 1;


	do
	{
		opcion = menuPrincipal();

		switch(opcion)
		{
			case 1:
				if(altaJugador(jugadores, TAM, confederaciones, TAMC, &proximoId))
				{
					printf("Jugador agregado con exito!\n");
					flagIngreso = 1;
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
					printf("\nINFORMES\n"
						   "1. LISTADO DE LOS JUGADORES ORDENADOS ALFABÉTICAMENTE POR NOMBRE DE CONFEDERACION Y NOMBRE DE JUGADOR\n"
						   "2. LISTADO DE CONFEDERACIONES CON SUS JUGADORES.\n"
						   "3. TOTAL Y PROMEDIO DE TODOS LOS SALARIOS Y CUANTOS JUGADORES COBRAN MÁS DEL SALARIO PROMEDIO\n"
						   "4. INFORMAR LA CONFEDERACION CON MAYOR CANTIDAD DE AÑOS DE CONTRATOS TOTAL\n"
						   "5. INFORMAR PORCENTAJE DE JUGADORES POR CADA CONFEDERACIÓN\n"
						   "6. INFORMAR CUAL ES LA REGIÓN CON MÁS JUGADORES Y EL LISTADO DE LOS MISMOS\n"
					       "7. INFORME GENERAL\n\n");
					utn_getNumero(&opcionInforme, "SELECCIONE EL INFORME QUE DESEA VER: ", "ERROR. ", 1, 7, 3);

					switch(opcionInforme)
					{
						case 1:
							primerListado(jugadores, TAM, confederaciones, TAMC, 0);
							break;
						case 2:
							listarConfederacionesYJugadores(jugadores, TAM, confederaciones, TAMC);
							break;
						case 3:
							calcularSalarios(jugadores, TAM, confederaciones, TAMC);
							break;
						case 4:
							confederacionMayorAniosContrato(jugadores, TAM, confederaciones, TAMC);
							break;
						case 5:

							break;
						case 6:
							break;
						case 7:
							listarJugador(jugadores, TAM, confederaciones, TAMC);
							break;
					}
				}
				break;
			case 5:
				getUserConfirmation(&preguntaSalir, "Desea salir? (s-n)", "Solamente (S-N)");
				if(preguntaSalir == 's')
				{
					salir = 's';
				}
				break;
		}
	}while(salir != 's');

	return 0;
}




