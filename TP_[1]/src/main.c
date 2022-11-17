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
	int acumuladorConfederacionOceania = 0;
	int acumuladorConfederacionAsia = 0;
	int acumuladorConfederacionAfrica = 0;
	int acumuladorConfederacionNorte = 0;
	int acumuladorConfederacionSudamerica = 0;
	int acumuladorConfederacionEuropa = 0;

	//Costos
	int costoComida = 0;
	int costoHospedaje = 0;
	int costoTransporte = 0;
	float costoTotalMantenimiento = 0.0;
	float costoMantenimientoFinal;

	//Variable para menu
	int opcionMenu;
	int opcionMenuCostos;
	int opcionMenuCargaJugadores;
	int opcionConfederacion = 0;

	int arquerosIngresados = 0;
	int defensoresIngresados = 0;
	int mediocampistasIngresados = 0;
	int delanterosIngresados = 0;
	int contadorJugadoresIngresados = 0;
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
		printf(" Costo de hospedaje -> $%d\n Costo de comida -> $%d\n Costo de transporte -> $%d",costoHospedaje, costoComida,costoTransporte);
		printf("\n2. Carga de jugadores\n");
		printf(" Arqueros ingresados actualmente -> %d\n Defensores ingresados actualmente -> %d\n Mediocampistas ingresados actualmente -> %d\n Delanteros ingresados actualmente -> %d\n",arquerosIngresados, defensoresIngresados,mediocampistasIngresados, delanterosIngresados);
		printf("3. Realizar todos los calculos\n");
		printf("4. Informar todos los resultados\n");
		printf("5. Salir\n");

		utn_getInt(&opcionMenu, "\nINGRESE UNA OPCION:","ERROR! REINTENTE: \n", 5, 1, 99);

		switch (opcionMenu) {
		case 1:
			do {
				printf(
						"                     MENU OPCION 1 - Ingreso de los costos de mantenimiento:\n");
				printf("\n1. Ingresar costo de hospedaje: \n");
				printf("2. Ingresar costo de comida: \n");
				printf("3. Ingresar costo de transporte: \n");
				printf("4. Volver al menu principal.\n");

				utn_getInt(&opcionMenuCostos, "\nINGRESE UNA OPCION:","ERROR! REINTENTE: \n", 4, 1,99);

				switch (opcionMenuCostos) {
				case 1:
					utn_getInt(&costoHospedaje,"\nIngrese costo de hospedaje:","Costo ingresado no es valido.\n",999999999,1, 99);
					flagUno = 1;
					break;
				case 2:utn_getInt(&costoComida,"\nIngrese costo de comida:","Error! REINTENTE: \n",999999999,1, 99);
					flagUno = 1;
					break;
				case 3:
					utn_getInt(&costoTransporte,"\nIngrese costo de Transporte:","Error! REINTENTE: \n",999999999,1, 99);
					flagUno = 1;
					break;
				}
			} while (opcionMenuCostos != 4);
			break;
		case 2:
			do {
				opcionConfederacion = 0;
				if(contadorJugadoresIngresados < 22)
				{
				printf("Carga de jugadores\n");
				printf(
						"\n1. Cargar Arquero:  | Arqueros actuales ingresados: %d (Maximo 2)\n",arquerosIngresados);
				printf("2. Cargar Defensor:  | Defensores actuales ingresados: %d (Maximo 8)\n",defensoresIngresados);
				printf("3. Cargar Mediocampista:  | Mediocampistas actuales ingresados: %d (Maximo 8)\n",mediocampistasIngresados);
				printf("4. Cargar Delantero:  | Delanteros actuales ingresados: %d (Maximo 4)\n",delanterosIngresados);
				printf("5. Volver al menu principal.\n");

				utn_getInt(&opcionMenuCargaJugadores,"\nINGRESE UNA OPCION:","ERROR! REINTENTE: \n", 5, 1,99);
				}
				else
				{
					printf("Maximo de jugadores (22) fue alcanzado.\n");
					break;
				}


				switch (opcionMenuCargaJugadores) {
				case 1:
					if (arquerosIngresados < 2) {
						printf("Ingrese numero de la camiseta del arquero: ");
						scanf("%d", &numeroDeCamiseta);
						do {
							printf("\nConfederacion a la que pertenece:\n");
							printf("1. 'AFC' - Confederacion de Asia.\n");
							printf("2.'CAF' - Confederacion de Africa.\n");
							printf("3.'CONCACAF' - Confederacion de Zona Norte.\n");
							printf("4.'CONMEBOL' - Confederacion de Sudamerica.\n");
							printf("5.'UEFA' - Confederacion de Europa.\n");
							printf("6.'OFC' - Confederacion de Oceania.\n");

							utn_getInt(&opcionConfederacion,"\nINGRESE UNA OPCION:","ERROR! REINGRESE: \n",6, 1, 99);

							switch (opcionConfederacion){
							case 1:
								acumuladorConfederacionAsia += 1;
								break;
							case 2:
								acumuladorConfederacionAfrica += 1;
								break;
							case 3:
								acumuladorConfederacionNorte += 1;
								break;
							case 4:
								acumuladorConfederacionSudamerica += 1;
								break;
							case 5:
								acumuladorConfederacionEuropa += 1;
								break;
							case 6:
								acumuladorConfederacionOceania += 1;
								break;
							}
							arquerosIngresados++;
							contadorJugadoresIngresados++;
							flagDos = 1;

						} while (opcionConfederacion == 0);
					} else {
						printf("Cantidad maxima de arqueros permitida (2) fue alcanzado.\n");
					}
					break;
				case 2:
					if (defensoresIngresados < 8) {
						printf("Ingrese numero de la camiseta del defensor: ");
						scanf("%d", &numeroDeCamiseta);
						do {
							printf("\nConfederacion a la que pertenece:\n");
							printf("1. 'AFC' - Confederacion de Asia.\n");
							printf("2.'CAF' - Confederacion de Africa.\n");
							printf("3.'CONCACAF' - Confederacion de Zona Norte.\n");
							printf("4.'CONMEBOL' - Confederacion de Sudamerica.\n");
							printf("5.'UEFA' - Confederacion de Europa.\n");
							printf("6.'OFC' - Confederacion de Oceania.\n");

							utn_getInt(&opcionConfederacion,"\nSeleccione una opcion:","ERROR! REINGRESE: \n",6, 1, 99);

							switch (opcionConfederacion) {
							case 1:
								acumuladorConfederacionAsia += 1;
								break;
							case 2:
								acumuladorConfederacionAfrica += 1;
								break;
							case 3:
								acumuladorConfederacionNorte += 1;
								break;
							case 4:
								acumuladorConfederacionSudamerica += 1;
								break;
							case 5:
								acumuladorConfederacionEuropa += 1;
								break;
							case 6:
								acumuladorConfederacionOceania += 1;

								break;
							}

							defensoresIngresados++;
							contadorJugadoresIngresados++;
							flagDos = 1;

						} while (opcionConfederacion == 0);
					} else {
						printf("Cantidad maxima de defensores permitida (8) fue alcanzado.\n");
					}
					break;
				case 3:
					if (mediocampistasIngresados < 8) {
						printf("Ingrese numero de la camiseta del mediocampista: ");
						scanf("%d", &numeroDeCamiseta);
						do {
							printf("\nConfederacion a la que pertenece:\n");
							printf("1. 'AFC' - Confederacion de Asia.\n");
							printf("2.'CAF' - Confederacion de Africa.\n");
							printf("3.'CONCACAF' - Confederacion de Zona Norte.\n");
							printf("4.'CONMEBOL' - Confederacion de Sudamerica.\n");
							printf("5.'UEFA' - Confederacion de Europa.\n");
							printf("6.'OFC' - Confederacion de Oceania.\n");

							utn_getInt(&opcionConfederacion,"\nINGRESE UNA OPCION:","ERROR! REINTENTE: \n",6, 1, 99);

							switch (opcionConfederacion) {
							case 1:
								acumuladorConfederacionAsia += 1;
								break;
							case 2:
								acumuladorConfederacionAfrica += 1;
								break;
							case 3:
								acumuladorConfederacionNorte += 1;
								break;
							case 4:
								acumuladorConfederacionSudamerica += 1;
								break;
							case 5:
								acumuladorConfederacionEuropa += 1;
								break;
							case 6:
								acumuladorConfederacionOceania += 1;
								break;
							}

							mediocampistasIngresados++;
							contadorJugadoresIngresados++;
							flagDos = 1;

						} while (opcionConfederacion == 0);
					} else {
						printf("Cantidad maxima de mediocampistas permitida (8) fue alcanzado.\n");
					}
					break;
				case 4:
					if (delanterosIngresados < 4) {
						printf("Ingrese numero de la camiseta del delantero: ");
						scanf("%d", &numeroDeCamiseta);
						do {
							printf("\nConfederacion a la que pertenece:\n");
							printf("1. 'AFC' - Confederacion de Asia.\n");
							printf("2.'CAF' - Confederacion de Africa.\n");
							printf("3.'CONCACAF' - Confederacion de Zona Norte.\n");
							printf("4.'CONMEBOL' - Confederacion de Sudamerica.\n");
							printf("5.'UEFA' - Confederacion de Europa.\n");
							printf("6.'OFC' - Confederacion de Oceania.\n");

							utn_getInt(&opcionConfederacion,"\nINGRESE UNA OPCION:","ERROR! REINTENTE: \n",6, 1, 99);

							switch (opcionConfederacion) {
							case 1:
								acumuladorConfederacionAsia += 1;
								break;
							case 2:
								acumuladorConfederacionAfrica += 1;
								break;
							case 3:
								acumuladorConfederacionNorte += 1;
								break;
							case 4:
								acumuladorConfederacionSudamerica += 1;
								break;
							case 5:
								acumuladorConfederacionEuropa += 1;
								break;
							case 6:
								acumuladorConfederacionOceania += 1;
								break;
							}

							delanterosIngresados++;
							contadorJugadoresIngresados++;
							flagDos = 1;

						} while (opcionConfederacion == 0);
					} else {
						printf("Cantidad maxima de delanteros permitida (4) fue alcanzado.\n");
					}
					break;
				}
			} while (opcionMenuCargaJugadores != 5);
			break;
		case 3:
			if(flagUno == 1 && flagDos == 1 && contadorJugadoresIngresados >= 3 && costoComida > 0 && costoHospedaje > 0 && costoTransporte > 0)
			{
			utn_getPromedioPorMercado(&promedioAsia,acumuladorConfederacionAsia, contadorJugadoresIngresados);
			utn_getPromedioPorMercado(&promedioAfrica,acumuladorConfederacionAfrica, contadorJugadoresIngresados);
			utn_getPromedioPorMercado(&promedioNorte,acumuladorConfederacionNorte, contadorJugadoresIngresados);
			utn_getPromedioPorMercado(&promedioConmebol,acumuladorConfederacionSudamerica, contadorJugadoresIngresados);
			utn_getPromedioPorMercado(&promedioUefa,acumuladorConfederacionEuropa, contadorJugadoresIngresados);
			utn_getPromedioPorMercado(&promedioOceania,acumuladorConfederacionOceania, contadorJugadoresIngresados);

			utn_getCostoMantenimiento(&costoTotalMantenimiento,costoComida,costoHospedaje,costoTransporte);

			if(promedioUefa > promedioAsia && promedioUefa > promedioAfrica && promedioUefa > promedioNorte && promedioUefa > promedioConmebol && promedioUefa > promedioOceania)
			{
				promedioAumentoUefa = costoTotalMantenimiento * 35 / 100;
				costoMantenimientoFinal = costoTotalMantenimiento + promedioAumentoUefa;
				flagTres = 1;
			}

			printf("\nSe realizaron exitosamente los siguientes calculos:\n");
			printf("1.Promedio de jugadores de cada mercado.\n");
			printf("2.Costos de mantenimiento.\n");
			flagCuatro = 1;
			}else
			{
				printf("¡ERROR! Debe ingresar primero los datos 1 y 2. Y tener al menos 3 jugadores ingresados\n");
			}
			break;
		case 4:
			if(flagCuatro == 1)
			{
			printf("\nPromedio Uefa %.2f\n", promedioUefa);
			printf("Promedio Conmebol %.2f\n", promedioConmebol);
			printf("Promedio Concacaf %.2f\n", promedioNorte);
			printf("Promedio Afc %.2f\n", promedioAsia);
			printf("Promedio Ofc %.2f\n", promedioOceania);
			printf("Promedio Caf %.2f\n", promedioAfrica);
			if(flagTres == 1)
			{
			printf("El costo de mantenimiento era de %.2f y recibio de aumento %.2f, su nuevo valor es de: %.2f\n", costoTotalMantenimiento,promedioAumentoUefa,costoMantenimientoFinal);
			}else
			{
			printf("El costo de mantenimiento es: %2.f\n",costoTotalMantenimiento);
			}
			}else
			{
				printf("¡ERROR! - Primero deben realizarse los calculos de la opcion 3.\n");
			}
			break;
		case 5:
			printf("\nPROGRAMA FINALIZADO.\n");
			break;
		}
	} while (opcionMenu != 5);

	return 0;
}
