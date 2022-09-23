/*
 * costos.c
 *
 *  Created on: 13 sep. 2022
 *      Author: delle
 */

#include "costos.h"



float costo_hospedaje() {
	float costo;

	printf("Ingrese el costo del  hospedaje: ($500000-$1.000000)");
	scanf("%f", &costo );

	while (costo < 500000 || costo > 1000000) {
		printf("Error! Ingrese el costo del hospedaje: (500000-1000000)\n");
		scanf("%f", &costo);
	}

	return costo;
}

float costo_comida() {
	float costo;

	printf("Ingrese el costo de la comida: (500000-1000000)");
	scanf("%f", &costo);

	while (costo < 500000 || costo > 1000000) {
		printf("Error! Ingrese el costo de la comida: (500000-1000000)\n");
		scanf("%f", &costo);
	}

	return costo;
}

float costo_transporte() {
	float costo;

	printf("Ingrese el coste del transporte: (500000-1000000)");
	scanf("%f", &costo);

	while (costo < 500000 || costo > 1000000) {
		printf("Error!Ingrese el costo del transporte: (500000-1000000)\n");
		scanf("%f", &costo);
	}

	return costo;
}

int ingresoMantenimiento(float *costoH, float *costoC, float *costoT) {
	int opcion;
	int retorno = 0;


	//ultimo antes de irme: ver una forma de pasar los costos para que el menu vaya mostrando los valores.

	if (costoH != NULL && costoC != NULL && costoT != NULL) {
		do {
			opcion = menuMantenimiento();

			switch (opcion) {
			case 1:
				*costoH = costo_hospedaje();
				break;
			case 2:
				*costoC = costo_comida();
				break;
			case 3:
				*costoT = costo_transporte();
				break;
			case 4:
				printf("Operacion Abortada-.\n");
				break;
			default:
				printf("Ingrese una opcion válida (1-4)\n");
			}

		} while (opcion != 4);

		retorno = 1;
	}

	return retorno;

}

