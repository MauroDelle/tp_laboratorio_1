/*
 * calculos.h
 *
 *  Created on: 20 sep. 2022
 *      Author: delle
 */

#ifndef CALCULOS_H_
#define CALCULOS_H_
#include "utn.h"
#include "jugadores.h"
#include "costos.h"
#include "menu.h"



/// @brief Buenas, lo que hace esta funcion es recibir los contadores de cada confederacion y
///         devolver los promedios de las mismas sobre el total de jugadores
///
///
/// @param contadorUEFA
/// @param contadorCONMEBOL
/// @param contadorCONCACAF
/// @param contadorAFC
/// @param contadorOFC
/// @param contadorCAF
/// @param totalJugadores
/// @param promUEFA
/// @param promCONMEBOL
/// @param promCONCACAF
/// @param promAFC
/// @param promOFC
/// @param promCAF
/// @return Retorna los promedios de la cantidad de jugadores de cada confederacion sobre el total de todas conf.
float realizarPromedios(int contadorUEFA, int contadorCONMEBOL,
		int contadorCONCACAF, int contadorAFC, int contadorOFC, int contadorCAF,
		int totalJugadores, float *promUEFA, float *promCONMEBOL, float *promCONCACAF,
		float *promAFC, float *promOFC, float *promCAF);

/// @brief esta funcion suma la cantidad de jugadores ingresados y los almacena en la variable totalJugadores
///        declarada en el main
///
/// @param arqueros
/// @param defensores
/// @param mediocampistas
/// @param delanteros
/// @param totalJugadores
/// @return Retorna el total de jugadores ingresados.
int calcularTotal(int arqueros, int defensores,int mediocampistas,int delanteros,int  *totalJugadores);

/// @brief	Lo que hace esta funcion es calcular la cantidad que hay en todas las confederaciones
///
/// @param afc
/// @param caf
/// @param concacaf
/// @param conmebol
/// @param ofc
/// @param totalConfederaciones
/// @return Retorna la cantidad de ingresados en confederaciones que hubo y lo almacena en la variable
///             totalConfederaciones declarada en la funcion menu_principal
int calcular_totalConfederaciones(int afc, int caf, int concacaf, int conmebol, int ofc, int *totalConfederaciones);
/// @brief Lo que hace esta funcion es calcular la cantidad de ingresados en todas las confedeeraciones
///              	EXCEPTO los de UEFA(confederacion europea)
///
/// @param totalJugadores
/// @param contUefa
/// @param restaUEFA
/// @return Retorta la cantidad de jugadores que hay en las confederaciones SIN uefa
int calcular_totalSinUEFA(int totalJugadores, int contUefa, int *restaUEFA);


#endif /* CALCULOS_H_ */









