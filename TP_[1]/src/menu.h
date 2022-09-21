/*
 * menu.h
 *
 *  Created on: 12 sep. 2022
 *      Author: delle
 */

#ifndef MENU_H_
#define MENU_H_
#include <stdio.h>
#include <stdlib.h>


int menu(float ingresoH, float ingresoC, float ingresoT, int contArq, int contDef, int contMed, int contDel);
int menuMantenimiento(void) ;
int menu_jugadores();
int menu_confederacion();
void menu_resultados(float costoMantenimiento, float pUEFA,
											float pCONMEBOL,
											float pCONCACAF,
											float pAFC,
											float pOFC,
											float pCAF);


#endif /* MENU_H_ */
