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
#include "menu.h"
#include "costos.h"
#include "jugadores.h"
#include "calculos.h"

/// @brief Esta funcion es el menu principal del trabajo, le paso los valores de mantenimiento
///                y la cantidad de jugadores por posicion para que se vayan actualizando los valores en el menu.
///
/// @param ingresoH
/// @param ingresoC
/// @param ingresoT
/// @param contArq
/// @param contDef
/// @param contMed
/// @param contDel
/// @return La opcion seleccionada
int menu(float ingresoH, float ingresoC, float ingresoT, int contArq, int contDef, int contMed, int contDel);
/// @brief Muetra un submenu para seleccionar que costo de mantenimiento el usuario desea ingresar
///
/// @return La opcion seleccionada
int menuMantenimiento(void);
/// @brief Muestra un submenu para seleccionar que posicion el usuario desea ingresar
///
/// @return La opcion seleccionada
int menu_jugadores();
/// @brief Muestra un submenu para seleccionar que confederacion el usuario desea ingresar
///
/// @return La opcion seleccionada
int menu_confederacion();
/// @brief Menu donde le passo los valores para que muestre todos los resultados de las cuentas realizadas
///         en el punto 3;
///
/// @param costoMantenimiento
/// @param pUEFA
/// @param pCONMEBOL
/// @param pCONCACAF
/// @param pAFC
/// @param pOFC
/// @param pCAF
/// @param aumentoUEFA
/// @param aumentoMantenimiento
void menu_resultados(float costoMantenimiento, float pUEFA,
											float pCONMEBOL,
											float pCONCACAF,
											float pAFC,
											float pOFC,
											float pCAF,
											float aumentoUEFA,
											float aumentoMantenimiento);

/// @brief Menu principal del trabajo practico.
///
void menuprincipal();

#endif /* MENU_H_ */
