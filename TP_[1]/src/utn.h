/*
 * utn.h
 *
 *  Created on: 17 nov. 2022
 *      Author: delle
 */

#ifndef UTN_H_
#define UTN_H_

/// @brief  Solicita un numero de tipo int al usuario, luego de verificarlo devuelve el resultado.
///
/// @param pNumeroIngresado Puntero al espacio de memoria donde se dejara el resultado de la funcion.
/// @param mensaje
/// @param mensajeError
/// @param maximo
/// @param minimo
/// @param maximoDeReintentos
/// @return Retorna 0 si se obtuvo correctamente el numero y -1 en caso de error.
int utn_getInt(int * pNumeroIngresado,char * mensaje,char * mensajeError,int maximo, int minimo, int maximoDeReintentos);

/// @brief  Solicita un numero de tipo flotante al usuario, luego de verificarlo devuelve el resultado.
///
/// @param pNumeroIngresado Puntero al espacio de memoria donde se dejara el resultado de la funcion.
/// @param mensaje Mensaje que se muestra.
/// @param mensajeError Mensaje de error que se muestra.
/// @param maximo Maximo numero permitido.
/// @param minimo Numero minimo permitido.
/// @param maximoDeReintentos Maximo de reintentos permitidos.
/// @return Retorna 0 si se obtuvo correctamente el numero y -1 en caso de error.
int utn_getFloat(float * pNumeroIngresado,char * mensaje,char * mensajeError,float maximo, float minimo, int maximoDeReintentos);

/// @brief  Calcula y despues de verificar devuelve el promedio de jugadores por mercado.
///
/// @param pPromedio Puntero al espacio de memoria donde se dejara el resultado de la funcion.
/// @param totalJuagoresConfederacion la cantidad de jugadores por confederacion
/// @param totalJugadoresIngresados el total de los jugadores ingresados
/// @return Retorna 0 si se realizo correctamente la operacion y -1 en caso de error.
int promedioConfederaciones(float * pPromedio, float totalJuagoresConfederacion, float totalJugadoresIngresados);

/// @brief  Calcula y despues de verificar devuelve el total del costo de mantenimiento.
///
/// @param ptotalMantenimiento Puntero al espacio de memoria donde se dejara el resultado de la funcion.
/// @param costoNumeroUno
/// @param costoNumeroDos
/// @param costoNumeroTres
/// @return Retorna 0 si se realizo correctamente la operacion y -1 en caso de error.
int costoMantenimiento(float * pCostoTotalMantenimiento, int costoNumeroUno, int costoNumeroDos, int costoNumeroTres);

/// @brief  Solicita un dato de tipo char al usuario, luego de verificarlo devuelve el resultado.
///
/// @param pNumeroIngresado Puntero al espacio de memoria donde se dejara el resultado de la funcion.
/// @param mensaje
/// @param mensajeError
/// @param maximo
/// @param minimo
/// @param maximoDeReintentos
/// @return Retorna 0 si se obtuvo correctamente el char y -1 en caso de error.
int utn_getChar(char * pNumeroIngresado,char * mensaje,char * mensajeError,char maximo, char minimo, int maximoDeReintentos);



#endif /* UTN_H_ */
