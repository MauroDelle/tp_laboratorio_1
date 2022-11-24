/*
 * utn.h
 *
 *  Created on: 1 nov. 2022
 *      Author: delle
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#ifndef UTN_H_
#define UTN_H_

int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);
int utn_getNombre(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);
int utn_getDescripcion(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);
int utn_getDni(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);
int getAlphabeticText(char mensaje[], char destino[], int len);
int stringIsAlphabetic(char string[]);
//WHAT I ADDED:
int getUserMenuOptionInt(int* confirUser,char message[],char errorMessage[],int minOption,int maxOption);
int getUserMenuOption(char* confirUser,char message[],char errorMessage[]);

int utn_presioneUnaTecla(char message[],char errorMessage[]);
void showMessage(char string[]);
void limpioPantalla();

int stringIsPath(char string[]);

int getUserConfirmation(char* confirUser,char message[],char errorMessage[]);

int esAlfaNumerico(char string[],char message[],int maxLimit);
int getValidStringAlpha(char requestMessage[],char errorMessageLenght[],char input[], int lowLimit,int maxLenght);


char getChar(char mensaje[]);

int getGender(char message[],char errorMessage[],char userGender[]);

int convertFirstLetterStringUpper(char string1[]);
int  limpiarBarraN(char cadena[], int tam);

void getStringAlfanumerica(char mensaje[],char input[]);
/**
 * @brief Busca si un string es solo numeros
 * @param string char* a recorrer
 * @return 1 si es solo numero 0 si contiene algun caracter no numerico
 */
int stringIsInt(char string[]);

#endif /* UTN_H_ */
