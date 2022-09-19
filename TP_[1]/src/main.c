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

int main(void) {

	setbuf(stdout, NULL);

	int opcion;

	float ingresoH = 0;
	float ingresoC = 0;
	float ingresoT = 0;

	int flagIngreso1 = 0;
	int flagIngreso2 = 0;
	int flagIngreso4 = 0;

	int contadorArqueros =  0;
	int contadorDefensores  = 0;
	int contadorMediocampistas = 0;
	int contadorDelanteros =  0;

	int contAfc = 0;
	int contCaf = 0;
	int contConcacaf = 0;
	int contConmbol = 0;
	int contUefa = 0;
	int contOfc = 0;


	//ya pude pasar la cantidad de jugadores por confederacion, ahora a sacar los porcentajes dale


	do {
		opcion = menu(ingresoH, ingresoC, ingresoT, contadorArqueros,
				contadorDefensores, contadorMediocampistas, contadorDelanteros);

		switch (opcion) {
		case 1:
			ingresoMantenimiento(&ingresoH, &ingresoC, &ingresoT);
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

				printf("%d\n", contConmbol);

				flagIngreso2 = 1;
			}
			break;
		case 3:
			if (flagIngreso2 == 0) {
				printf("Ingrese los costos de mantenimiento primero !\n\n");

			} else {

				flagIngreso4 = 1;
			}

			break;
		case 4:
			if (flagIngreso4 == 0) {
				printf(
						"Debe de calcular todos los calculos antes de poder mostrarlos! \n");
			} else {




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
