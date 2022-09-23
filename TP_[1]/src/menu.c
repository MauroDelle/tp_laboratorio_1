/*
 * menu.c
 *
 *  Created on: 12 sep. 2022
 *      Author: delle
 */

#include "menu.h"



int menu(float ingresoH, float ingresoC, float ingresoT, int contArq, int contDef, int contMed, int contDel)
{
	int ingreso;

	printf("---------  Menu Principal  ---------");
	printf("\n\n");
	printf("1. Ingreso de los costos de Mantenimiento\n");
	printf("Costo de Hospedaje -> $%.0f", ingresoH);
	printf("\n");
	printf("Costo de Comida -> $%.0f", ingresoC);
	printf("\n");
	printf("Costo de Transporte -> $%.0f", ingresoT);
	printf("\n");
	printf("2. Carga de Jugadores\n");
	printf("Arqueros -> %d", contArq);
	printf("\n");
	printf("Defensores -> %d",contDef);
	printf("\n");
	printf("Mediocampistas -> %d",contMed);
	printf("\n");
	printf("Delanteros -> %d", contDel);
	printf("\n");
	printf("3. Realizar todos los calculos\n");
	printf("4. Informar todos los calculos\n");
	printf("5. Salir\n");
	printf("Seleccione una opcion: \n");
	scanf("%d", &ingreso);

	return ingreso;
}


int menuMantenimiento(void)
{
	int ingreso;

	printf("-------- SUB MENU --------");
	printf("\n\n");
	printf("Seleccione que costo desea ingresar\n");
	printf("1- Costo de hospedaje\n");
	printf("2- Costo de comida\n");
	printf("3- Costo de transporte\n");
	printf("4- Menu Principal\n");
	printf("Ingrese una opcion(1-4): ");
	scanf("%d", &ingreso);

	return ingreso;
}



int menu_jugadores()
{
	int ingreso;

	printf("-------- SUB MENU --------\n\n");
	printf("1- Arquero\n");
	printf("2- Defensor\n");
	printf("3- Mediocampista\n");
	printf("4- Delantero\n");
	printf("5- Menu Principal\n");
	printf("Seleccione la posicion que desea ingresar:");
	scanf("%d", &ingreso);

	return ingreso;
}



int menu_confederacion()
{
	int ingreso;

	printf("-------- CONFEDERACIONES --------\n\n");
	printf("1- AFC (Asia)\n");
	printf("2- CAF (África)\n");
	printf("3- CONCACAF (Norteamerica)\n");
	printf("4- CONMEBOL (Sudamérica)\n");
	printf("5- UEFA (Europa)\n");
	printf("6- OFC (Oceanía)\n");
	printf("Seleccione la confederacion: ");
	scanf("%d", &ingreso);

	return ingreso;
}

void menu_resultados(float costoMantenimiento, float pUEFA,
											float pCONMEBOL,
											float pCONCACAF,
											float pAFC,
											float pOFC,
											float pCAF,
											float aumentoUEFA,
											float aumentoMantenimiento)
{

	printf("\n          Informar todos los Resultados          \n\n");
	printf("Porcentaje Uefa %0.2f\n"
		   "Porcentaje Conmebol %0.2f\n"
		   "Porcentaje Concacaf %0.2f\n"
		   "Porcentaje Afc %0.2f\n"
		   "Porcentaje Ofc %0.2f\n"
		   "Porcentaje Caf %0.2f\n",    pUEFA,
								    pCONMEBOL,
								    pCONCACAF,
								    pAFC,
								    pOFC,
								    pCAF);
	printf("El costo de mantenimiento era %0.2f de  y recibio un aumento de %0.2f, su nuevo valor es de %0.2f: \n",
			                                                                               costoMantenimiento,
																						   aumentoUEFA,
																						   aumentoMantenimiento);
}


