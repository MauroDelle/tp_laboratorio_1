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



void menuprincipal()
{

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

}



