/*
 * jugadores.c
 *
 *  Created on: 14 sep. 2022
 *      Author: delle
 */

#include "jugadores.h"

void carga_Arquero(int *confederacion){

	int numero;

	printf("Numero de camiseta: (1-99)\n");
	scanf("%d", &numero);

	while (numero < 1 || numero > 99) {
		printf("Numero de camiseta: (1-99)\n");
		scanf("%d", &numero);
	}

	*confederacion = menu_confederacion();

	limpiar();

}

int carga_jugadores(int *contArq, int *contDef, int *contMed, int *contDel,
		int *arqueroConfed) {

	int opcion;
	int retorno = 0;

	int contadorArq = 0;
	int contadorDef = 0;
	int contadorMed = 0;
	int contadorDel = 0;

	if (contArq != NULL && contDef != NULL && contMed != NULL && contDel != NULL) {
		do {
			opcion = menu_jugadores();

			switch (opcion) {
			case 1:
				contadorArq++;
				carga_Arquero(arqueroConfed);
				break;
			case 2:
				contadorDef++;
				break;
			case 3:
				contadorMed++;
				break;
			case 4:
				contadorDel++;
				break;
			case 5:
				break;
			default:
				printf("Ingrese una opcion válida (1-5)\n");
			}

		} while (opcion != 5);

		retorno = 1;

	}

	*contArq += contadorArq;
	*contDef += contadorDef;
	*contMed += contadorMed;
	*contDel += contadorDel;

	return retorno;
}



