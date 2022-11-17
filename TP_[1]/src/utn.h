/*
 * utn.h
 *
 *  Created on: 17 nov. 2022
 *      Author: delle
 */

#ifndef UTN_H_
#define UTN_H_

int utn_getInt(int * pNumeroIngresado,char * mensaje,char * mensajeError,int maximo, int minimo, int maximoDeReintentos);
int utn_getFloat(float * pNumeroIngresado,char * mensaje,char * mensajeError,float maximo, float minimo, int maximoDeReintentos);
int utn_getPromedioPorMercado(float * pPromedio, float totalJuagoresConfederacion, float totalJugadoresIngresados);
int utn_getCostoMantenimiento(float * pCostoTotalMantenimiento, int costoNumeroUno, int costoNumeroDos, int costoNumeroTres);
int utn_getChar(char * pNumeroIngresado,char * mensaje,char * mensajeError,char maximo, char minimo, int maximoDeReintentos);



#endif /* UTN_H_ */
