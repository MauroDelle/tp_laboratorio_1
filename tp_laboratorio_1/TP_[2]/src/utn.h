/*
 * utn.h
 *
 *  Created on: 22 abril. 2022
 *      Author: delle
 */

#ifndef UTN_H_
#define UTN_H_
#include "string.h"
#include <stdio.h>
#include <stdlib.h>
#include "defines.h"

#endif /* UTN_H_ */




int getUserMenuOption(char* confirUser,char message[],char errorMessage[]);

int getUserMenuOptionInt(int* confirUser,char message[],char errorMessage[],int minOption,int maxOption);
int  esAnioBisiesto(int year);

int esNumerica(char* cadena);

int getInt(int* pResultado);
int myGets(char* cadena, int longitud);

int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);


int getValidStringAlpha(char requestMessage[],char errorMessageLenght[],char input[], int lowLimit,int maxLenght);
void limpioPantalla();

int esNumericoII(char str[]);

void getStringInValid(char mensaje[],char input[]);

int getStringNumerosEnteros(char mensaje[],char input[]);

int getValidInt(char requestMessage[],char errorLenghtMessage[],char errorMessage[], int lowLimit, int hiLimit,int* input);
void showMessage(char string[]);
float getFloat(char message[]);

int esFloat(char stringFloat[]);


int getFloatValidation(float* input, char message[],char errorMessage[], float lowLimit, float highLimit);

int esAlfaNumerico(char string[],char message[],int maxLimit);
int getUserConfirmation(char* confirUser,char message[],char errorMessage[]);

int getGender(char message[],char errorMessage[],char userGender[]);

int getValidFloat(char message[],char errorMessage[],char errorMessageLenght[], float lowLimit, float highLimit, float* input);
int convertFirstLetterStringUpper(char string1[]);

void getString(char mensaje[],char input[]);

int getStringCaracteres(char mensaje[],char input[]);

int sonLetras(char str[]);

int getValidString(char requestMessage[],char errorMessage[], char errorMessageLenght[],char input[], int lowLimit,int maxLenght);

int  limpiarBarraN(char cadena[], int tam);

int initUserWithArrays(int elementos[],int max);

int searchFreeSpace(int elementos[],int max,int* pIndex);
