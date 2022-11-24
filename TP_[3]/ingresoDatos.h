/*
 * ingresoDatos.h
 *
 *  Created on: 23 nov. 2022
 *      Author: Mauro delle
 */

#ifndef INGRESODATOS_H_
#define INGRESODATOS_H_

int utn_getPosicionValida(char* pResultado);
int utn_getConfederacionValida(char* pResultado);
int utn_esConfederacionValida(char* confederacion);
int utn_getConfederacionValida(char* pResultado);
int utn_esPosicionValida(char* posicion);

int utn_getSeleccionValida(LinkedList* pArrayListSeleccion, int* pResultado);

#endif /* INGRESODATOS_H_ */
