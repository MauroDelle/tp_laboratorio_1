/*
 * utn.h
 *
 *  Created on: 11 jun. 2022
 *      Author: delle
 */

#ifndef UTN_H_
#define UTN_H_


#endif /* UTN_H_ */


int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);
int utn_getNombre(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);
int utn_getDescripcion(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);
int utn_getDni(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);
int getUserMenuOptionInt(int* confirUser,char message[],char errorMessage[],int minOption,int maxOption);
int getUserMenuOption(char* confirUser,char message[],char errorMessage[]);
void showMessage(char string[]);
void limpioPantalla();
int getUserConfirmation(char* confirUser,char message[],char errorMessage[]);
int esAlfaNumerico(char string[],char message[],int maxLimit);
int getValidStringAlpha(char requestMessage[],char errorMessageLenght[],char input[], int lowLimit,int maxLenght);
char getChar(char mensaje[]);
int getGender(char message[],char errorMessage[],char userGender[]);
int convertFirstLetterStringUpper(char string1[]);
int  limpiarBarraN(char cadena[], int tam);
void getStringAlfanumerica(char mensaje[],char input[]);
