/*
 ============================================================================
 Name        : main.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "costos.h"
#include "jugadores.h"
#include "calculos.h"

int main(void) {

	setbuf(stdout,NULL);

	int opcion;

	int flagIngreso1 = 0;
	int flagIngreso2 = 0;
	int flagIngreso4 = 0;

	float ingresoH = 0;
	float ingresoC = 0;
	float ingresoT = 0;
	float costoMantenimiento;

	int contadorArqueros =  0;
	int contadorDefensores  = 0;
	int contadorMediocampistas = 0;
	int contadorDelanteros =  0;

	int aumentoUEFA;
	int totalConfederaciones;
    int restaUEFA;

	int contAfc = 0;
	int contCaf = 0;
	int contConcacaf = 0;
	int contConmbol = 0;
	int contUefa = 0;
	int contOfc = 0;
	int totalJugadores;

	float promUEFA;
	float promCONMEBOL;
	float promCONCACAF;
	float promAFC;
	float promOFC;
	float promCAF;



	do{
		opcion = menu(ingresoH, ingresoC, ingresoT, contadorArqueros,
				contadorDefensores, contadorMediocampistas, contadorDelanteros);

		switch (opcion){
		case 1:
			ingresoMantenimiento(&ingresoH, &ingresoC, &ingresoT);

			costoMantenimiento = ingresoH + ingresoC + ingresoT;

			flagIngreso1 = 1;
			break;
		case 2:
			if (flagIngreso1 == 0) {
				printf("Ingrese los costos de mantenimiento primero !\n\n");
			} else {

				carga_jugadores(&contadorArqueros, &contadorDefensores,
						&contadorMediocampistas, &contadorDelanteros,
				        &contAfc,&contCaf,&contConcacaf,
						&contConmbol,&contUefa,&contOfc);



				totalJugadores = contadorArqueros + contadorDefensores + contadorMediocampistas + contadorDelanteros;

				totalConfederaciones = contAfc + contCaf + contConcacaf + contConmbol + contOfc;

				restaUEFA = totalJugadores - contUefa;

				if(contUefa > restaUEFA)
				{
					aumentoUEFA = (costoMantenimiento * 35) / 100;

					costoMantenimiento = costoMantenimiento + aumentoUEFA;
				}


				printf("%d\n", totalJugadores);

				flagIngreso2 = 1;
			}
			break;
		case 3:
			if (flagIngreso2 == 0 || totalJugadores == 0) {
				printf("Debe Ingresar al menos un Jugadoros para realizar los calculos!!\n\n");
			}
			else{

				realizarPromedios(contUefa, contConmbol, contConcacaf, contAfc, contOfc, contCaf, totalJugadores,&promUEFA,
						                                                                                         &promCONMEBOL,
																												 &promCONCACAF,
																												 &promAFC,&promOFC,
																												 &promCAF);
				printf("Promedio Realizado! \n");
				flagIngreso4 = 1;
			}

			break;
		case 4:
			if (flagIngreso4 == 0) {
				printf(
						"Debe de calcular todos los calculos antes de poder mostrarlos! \n");
			} else {

				menu_resultados(costoMantenimiento,promUEFA,promCONMEBOL,promCONCACAF,promAFC,promOFC,promCAF);


			}
			break;
		case 5:
			printf("\nHasta la vista baby!");
			break;

		default:
			printf("\nIngrese una opcion valida\n");
		}

	} while (opcion != 5);

	return 0;
}
