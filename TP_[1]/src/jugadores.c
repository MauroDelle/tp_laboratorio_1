/*
 * jugadores.c
 *
 *  Created on: 14 sep. 2022
 *      Author: delle
 */

#include "jugadores.h"

void carga_Confederaciones(int *AFC, int *CAF, int *CONCACAF, int *CONMEBOL,
		                                                int *UEFA, int *OFC)
{
	int numero;
	int opcion;

	int contAFC = 0;
	int contCAF = 0;
	int contCONCACAF = 0;
	int contCONMEBOL = 0;
	int contUEFA = 0;
	int contOFC = 0;

	printf("Numero de camiseta: (1-99)\n");
	scanf("%d", &numero);

	while (numero < 1 || numero > 99) {
		printf("Numero de camiseta: (1-99)\n");
		scanf("%d", &numero);
	}

	opcion = menu_confederacion();

	switch(opcion)
	{
		case 1:
			contAFC++;
			break;
		case 2:
			contCAF++;
			break;
		case 3:
			contCONCACAF++;
			break;
		case 4:
			contCONMEBOL++;
			break;
		case 5:
			contUEFA++;
			break;
		case 6:
			contOFC++;
			break;
		default:
			printf("Opcion incorrecta!");
	}

	*AFC += contAFC;
	*CAF += contCAF;
	*CONCACAF += contCONCACAF;
	*CONMEBOL += contCONMEBOL;
	*UEFA += contUEFA;
	*OFC +=  contOFC;


	limpiar();

}

int carga_jugadores(int *contArq, int *contDef, int *contMed, int *contDel, int *AFC, int *CAF, int *CONCACAF, int *CONMEBOL,
		int *UEFA, int *OFC) {

	int opcion;
	int retorno = 0;

	int contadorArq = 0;
	int contadorDef = 0;
	int contadorMed = 0;
	int contadorDel = 0;

	int contAfc = 0;
	int contCaf = 0;
	int contConcacaf = 0;
	int contConmbol = 0;
	int contUefa = 0;
	int contOfc = 0;

	if (contArq != NULL && contDef != NULL && contMed != NULL && contDel != NULL) {
		do {
			opcion = menu_jugadores();

			switch (opcion) {
			case 1:
				contadorArq++;
				carga_Confederaciones(&contAfc,&contCaf,&contConcacaf,&contConmbol,&contUefa,&contOfc);
				break;
			case 2:
				carga_Confederaciones(&contAfc,&contCaf,&contConcacaf,&contConmbol,&contUefa,&contOfc);
				contadorDef++;
				break;
			case 3:
				carga_Confederaciones(&contAfc,&contCaf,&contConcacaf,&contConmbol,&contUefa,&contOfc);
				contadorMed++;
				break;
			case 4:
				carga_Confederaciones(&contAfc,&contCaf,&contConcacaf,&contConmbol,&contUefa,&contOfc);
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

	*AFC += contAfc;
	*CAF += contCaf;
	*CONCACAF += contConcacaf;
	*CONMEBOL += contConmbol;
	*UEFA += contUefa;
	*OFC += contOfc;
	*contArq += contadorArq;
	*contDef += contadorDef;
	*contMed += contadorMed;
	*contDel += contadorDel;

	return retorno;
}




