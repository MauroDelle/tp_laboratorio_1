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
#define TRUE 1
#define FALSE 0

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

	float aumentoUEFA;
	int totalConfederaciones = 0;
    int restaUEFA;

    float aumentoMantenimiento;

	int contAfc = 0;
	int contCaf = 0;
	int contConcacaf = 0;
	int contConmbol = 0;
	int contUefa = 0;
	int contOfc = 0;
	int totalJugadores = 0;

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

				//hacer todo esto en un a funcion asi no queda todo despelotado.

				calcularTotal(contadorArqueros, contadorDefensores, contadorMediocampistas, contadorDelanteros, &totalJugadores);
				calcular_totalConfederaciones(contAfc, contCaf, contConcacaf, contConmbol, contOfc, &totalConfederaciones);
				calcular_totalSinUEFA(totalJugadores, contUefa, &restaUEFA);

				if(contUefa > restaUEFA)
				{
					aumentoUEFA = (costoMantenimiento * 35) / 100;
					aumentoMantenimiento = costoMantenimiento + aumentoUEFA;
				}
				else
				{
					printf("No se aplica aumento de 35 porciento\n");
					aumentoMantenimiento = 0;
					aumentoUEFA = 0;
				}

				//printf("%d\n", restaUEFA);
				flagIngreso2 = 1;
			}
			break;
		case 3:
			if (flagIngreso2 == 0 || totalJugadores == 0) {
				printf("Debe Ingresar al menos un Jugadoros para realizar los calculos!!\n\n");
			}
			else{
				//A-B-C
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
			}else
			{
				menu_resultados(costoMantenimiento,promUEFA,promCONMEBOL,promCONCACAF,promAFC,promOFC,promCAF,
						                                                    aumentoUEFA,aumentoMantenimiento);
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
