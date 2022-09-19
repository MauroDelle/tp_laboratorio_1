/*
 * utn.h
 *
 *  Created on: 13 sep. 2022
 *      Author: delle
 */

#ifndef UTN_H_
#define UTN_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "costos.h"
#include "menu.h"


int esNumerica(char* cadena, int limite);
int myGets(char* cadena, int longitud);
int getInt(int* pResultado);
int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int getValidInt(char requestMessage[],char errorLenghtMessage[],char errorMessage[], int lowLimit, int hiLimit,float* input);
int getStringNumerosEnteros(char mensaje[],char input[]);
int esNumericoII(char str[]);
void getStringInValid(char mensaje[],char input[]);
int utn_getString(char mensaje[], char mensajeError[], int tam, int reintentos, char input[]);
int getString(char input[], int tam);
int esValido(char string[]);
void limpiar();

#endif /* UTN_H_ */
