/*
 ============================================================================
 Name        : 0.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

int main(void){

	setbuf(stdout, NULL);

	//Acumuladores
	int acumuladorOceania = 0;
	int acumuladorAsia = 0;
	int acumuladorAfrica = 0;
	int acumuladorCNorte = 0;
	int acumuladorSudamerica = 0;
	int acumuladorEuropa = 0;

	//Costos
	int costoComida = 0;
	int costoHospedaje = 0;
	int costoTransporte = 0;
	float totalMantenimiento = 0.0;
	float costoMantenimientoFinal;

	//Variable para menu
	int opcionUno;
	int opcionDos;
	int opcionTres;
	int opcionConfederacion = 0;

	//contadores de jugadores
	int arqueros = 0;
	int defensores = 0;
	int mediocampistas = 0;
	int delanteros = 0;
	int totalJugadores = 0;
	int numeroDeCamiseta;

	//Promedios
	float promedioAsia = 0.0;
	float promedioAfrica = 0.0;
	float promedioNorte = 0.0;
	float promedioConmebol = 0.0;
	float promedioUefa = 0.0;
	float promedioOceania = 0.0;
	float promedioAumentoUefa;

	//Flags de ingreso
	int flagUno = 0;
	int flagDos = 0;
    int flagTres = 0;
    int flagCuatro = 0;

	do {

		printf("                 MENU PRINCIPAL    \n");
		printf("\n1. Ingreso de los costos de mantenimiento:\n");
		printf(
				" Costo de hospedaje -> $%d\n Costo de comida -> $%d\n Costo de transporte -> $%d",
				costoHospedaje, costoComida, costoTransporte);
		printf("\n2. Carga de jugadores\n");
		printf(
				" Arqueros ingresados actualmente -> %d\n Defensores ingresados actualmente -> %d\n Mediocampistas ingresados actualmente -> %d\n Delanteros ingresados actualmente -> %d\n",
				arqueros, defensores, mediocampistas, delanteros);
		printf("3. Realizar todos los calculos\n");
		printf("4. Informar todos los resultados\n");
		printf("5. Salir\n");

		utn_getInt(&opcionUno, "\nINGRESE UNA OPCION:", "ERROR! REINTENTE: \n",
				5, 1, 99);

		switch (opcionUno) {
		case 1:
			do {
				printf(
						"                     MENU OPCION 1 - Ingreso de los costos de mantenimiento:\n");
				printf("\n1. Ingresar costo de hospedaje: \n");
				printf("2. Ingresar costo de comida: \n");
				printf("3. Ingresar costo de transporte: \n");
				printf("4. Volver al menu principal.\n");

				utn_getInt(&opcionDos, "\nINGRESE UNA OPCION:",
						"ERROR! REINTENTE: \n", 4, 1, 99);

				switch (opcionDos) {
				case 1:
					utn_getInt(&costoHospedaje, "\nIngrese costo de hospedaje:",
							"Costo ingresado no es valido.\n", 999999999, 1,
							99);
					flagUno = 1;
					break;
				case 2:
					utn_getInt(&costoComida, "\nIngrese costo de comida:",
							"Error! REINTENTE: \n", 999999999, 1, 99);
					flagUno = 1;
					break;
				case 3:
					utn_getInt(&costoTransporte,
							"\nIngrese costo de Transporte:",
							"Error! REINTENTE: \n", 999999999, 1, 99);
					flagUno = 1;
					break;
				}
			} while (opcionDos != 4);
			break;
		case 2:
			do {
				opcionConfederacion = 0;
				if (totalJugadores < 22) {
					printf("Carga de jugadores\n");
					printf(
							"\n1. Cargar Arquero:  | Arqueros actuales ingresados: %d (Maximo 2)\n",
							arqueros);
					printf(
							"2. Cargar Defensor:  | Defensores actuales ingresados: %d (Maximo 8)\n",
							defensores);
					printf(
							"3. Cargar Mediocampista:  | Mediocampistas actuales ingresados: %d (Maximo 8)\n",
							mediocampistas);
					printf(
							"4. Cargar Delantero:  | Delanteros actuales ingresados: %d (Maximo 4)\n",
							delanteros);
					printf("5. Volver al menu principal.\n");

					utn_getInt(&opcionTres, "\nINGRESE UNA OPCION:",
							"ERROR! REINTENTE: \n", 5, 1, 99);
				} else {
					printf("Maximo de jugadores (22) fue alcanzado.\n");
					break;
				}

				switch (opcionTres) {
				case 1:
					if (arqueros < 2) {
						printf("Ingrese numero de la camiseta del arquero: ");
						scanf("%d", &numeroDeCamiseta);
						do {
							printf("\nConfederacion a la que pertenece:\n");
							printf("1. 'AFC' - Confederacion de Asia.\n");
							printf("2.'CAF' - Confederacion de Africa.\n");
							printf(
									"3.'CONCACAF' - Confederacion de Zona Norte.\n");
							printf(
									"4.'CONMEBOL' - Confederacion de Sudamerica.\n");
							printf("5.'UEFA' - Confederacion de Europa.\n");
							printf("6.'OFC' - Confederacion de Oceania.\n");

							utn_getInt(&opcionConfederacion,
									"\nINGRESE UNA OPCION:",
									"ERROR! REINGRESE: \n", 6, 1, 99);

							switch (opcionConfederacion) {
							case 1:
								acumuladorAsia += 1;
								break;
							case 2:
								acumuladorAfrica += 1;
								break;
							case 3:
								acumuladorCNorte += 1;
								break;
							case 4:
								acumuladorSudamerica += 1;
								break;
							case 5:
								acumuladorEuropa += 1;
								break;
							case 6:
								acumuladorOceania += 1;
								break;
							}
							arqueros++;
							totalJugadores++;
							flagDos = 1;

						} while (opcionConfederacion == 0);
					} else {
						printf(
								"Cantidad maxima de arqueros permitida (2) fue alcanzado.\n");
					}
					break;
				case 2:
					if (defensores < 8) {
						printf("Ingrese numero de la camiseta del defensor: ");
						scanf("%d", &numeroDeCamiseta);
						do {
							printf("\nConfederacion a la que pertenece:\n");
							printf("1. 'AFC' - Confederacion de Asia.\n");
							printf("2.'CAF' - Confederacion de Africa.\n");
							printf(
									"3.'CONCACAF' - Confederacion de Zona Norte.\n");
							printf(
									"4.'CONMEBOL' - Confederacion de Sudamerica.\n");
							printf("5.'UEFA' - Confederacion de Europa.\n");
							printf("6.'OFC' - Confederacion de Oceania.\n");

							utn_getInt(&opcionConfederacion,
									"\nSeleccione una opcion:",
									"ERROR! REINGRESE: \n", 6, 1, 99);

							switch (opcionConfederacion) {
							case 1:
								acumuladorAsia += 1;
								break;
							case 2:
								acumuladorAfrica += 1;
								break;
							case 3:
								acumuladorCNorte += 1;
								break;
							case 4:
								acumuladorSudamerica += 1;
								break;
							case 5:
								acumuladorEuropa += 1;
								break;
							case 6:
								acumuladorOceania += 1;

								break;
							}

							defensores++;
							totalJugadores++;
							flagDos = 1;

						} while (opcionConfederacion == 0);
					} else {
						printf("Ya se ingresaron 8 defensores\n");
					}
					break;
				case 3:
					if (mediocampistas < 8) {
						printf(
								"Ingrese numero de la camiseta del mediocampista: ");
						scanf("%d", &numeroDeCamiseta);
						do {
							printf("\nConfederacion a la que pertenece:\n");
							printf("1. 'AFC' - Confederacion de Asia.\n");
							printf("2.'CAF' - Confederacion de Africa.\n");
							printf(
									"3.'CONCACAF' - Confederacion de Zona Norte.\n");
							printf(
									"4.'CONMEBOL' - Confederacion de Sudamerica.\n");
							printf("5.'UEFA' - Confederacion de Europa.\n");
							printf("6.'OFC' - Confederacion de Oceania.\n");

							utn_getInt(&opcionConfederacion,
									"\nINGRESE UNA OPCION:",
									"ERROR! REINTENTE: \n", 6, 1, 99);

							switch (opcionConfederacion) {
							case 1:
								acumuladorAsia += 1;
								break;
							case 2:
								acumuladorAfrica += 1;
								break;
							case 3:
								acumuladorCNorte += 1;
								break;
							case 4:
								acumuladorSudamerica += 1;
								break;
							case 5:
								acumuladorEuropa += 1;
								break;
							case 6:
								acumuladorOceania += 1;
								break;
							}

							mediocampistas++;
							totalJugadores++;
							flagDos = 1;

						} while (opcionConfederacion == 0);
					} else {
						printf(
								"Cantidad maxima de mediocampistas permitida (8) fue alcanzado.\n");
					}
					break;
				case 4:
					if (delanteros < 4) {
						printf("Ingrese numero de la camiseta del delantero: ");
						scanf("%d", &numeroDeCamiseta);
						do {
							printf("\nConfederacion a la que pertenece:\n");
							printf("1. 'AFC' - Confederacion de Asia.\n");
							printf("2.'CAF' - Confederacion de Africa.\n");
							printf(
									"3.'CONCACAF' - Confederacion de Zona Norte.\n");
							printf(
									"4.'CONMEBOL' - Confederacion de Sudamerica.\n");
							printf("5.'UEFA' - Confederacion de Europa.\n");
							printf("6.'OFC' - Confederacion de Oceania.\n");

							utn_getInt(&opcionConfederacion,
									"\nINGRESE UNA OPCION:",
									"ERROR! REINTENTE: \n", 6, 1, 99);

							switch (opcionConfederacion) {
							case 1:
								acumuladorAsia += 1;
								break;
							case 2:
								acumuladorAfrica += 1;
								break;
							case 3:
								acumuladorCNorte += 1;
								break;
							case 4:
								acumuladorSudamerica += 1;
								break;
							case 5:
								acumuladorEuropa += 1;
								break;
							case 6:
								acumuladorOceania += 1;
								break;
							}
							delanteros++;
							totalJugadores++;
							flagDos = 1;
						} while (opcionConfederacion == 0);
					} else {
						printf(
								"Cantidad maxima de delanteros permitida (4) fue alcanzado.\n");
					}
					break;
				}
			} while (opcionTres != 5);
			break;
		case 3:
			if (flagUno == 1 && flagDos == 1 && totalJugadores >= 3
					&& costoComida > 0 && costoHospedaje > 0
					&& costoTransporte > 0) {
				promedioConfederaciones(&promedioAsia, acumuladorAsia,
						totalJugadores);
				promedioConfederaciones(&promedioAfrica, acumuladorAfrica,
						totalJugadores);
				promedioConfederaciones(&promedioNorte, acumuladorCNorte,
						totalJugadores);
				promedioConfederaciones(&promedioConmebol, acumuladorSudamerica,
						totalJugadores);
				promedioConfederaciones(&promedioUefa, acumuladorEuropa,
						totalJugadores);
				promedioConfederaciones(&promedioOceania, acumuladorOceania,
						totalJugadores);

				costoMantenimiento(&totalMantenimiento, costoComida,
						costoHospedaje, costoTransporte);

				if (promedioUefa > promedioAsia && promedioUefa > promedioAfrica
						&& promedioUefa > promedioNorte
						&& promedioUefa > promedioConmebol
						&& promedioUefa > promedioOceania) {
					promedioAumentoUefa = totalMantenimiento * 35 / 100;
					costoMantenimientoFinal = totalMantenimiento
							+ promedioAumentoUefa;
					flagTres = 1;
				}
				printf("\nLos Calculos se realizaron existosamente! \n");

				flagCuatro = 1;

			} else {
				printf(
						"ERROR! Debe de ingresar los costos de mantenimiento y tener al menos 3 jugadores ingresados\n");
			}
			break;
		case 4:
			if (flagCuatro == 1) {
				printf("\nPromedio Uefa %.2f\n", promedioUefa);
				printf("Promedio Conmebol %.2f\n", promedioConmebol);
				printf("Promedio Concacaf %.2f\n", promedioNorte);
				printf("Promedio Afc %.2f\n", promedioAsia);
				printf("Promedio Ofc %.2f\n", promedioOceania);
				printf("Promedio Caf %.2f\n", promedioAfrica);
				if (flagTres == 1) {
					printf(
							"El costo de mantenimiento era de %.2f y recibio de aumento %.2f, su nuevo valor es de: %.2f\n",
							totalMantenimiento, promedioAumentoUefa,
							costoMantenimientoFinal);
				} else {
					printf("El costo de mantenimiento es: %2.f\n",
							totalMantenimiento);
				}
			} else {
				printf("Error! Primero hay que realizar los calculos! \n");
			}
			break;
		case 5:
			printf("Adios!\n");
			break;
		}
	} while (opcionUno != 5);

	return 0;
}
