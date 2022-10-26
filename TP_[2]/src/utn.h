/*
 * utn.h
 *
 *  Created on: 25 oct. 2022
 *      Author: delle
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#ifndef UTN_H_
#define UTN_H_


//						CHICHES
/**
* \brief 'Barre' la consola ya que el system(CLS) no funciona en eclipse
*/
void limpioPantalla();
/**
* \brief IMPRIME UN MENSAJE
*/
void showMessage(char string[]);

/**
* \brief Se le pregunta al usuario LA OPCION DEL MENU
* \param mensaje el mensaje que le vamos a mostrar al usuario "Ingrese...."
* \param errorMensaje el mensaje de ERROR que le vamos a mostrar al usuario
* \param input Array donde cargamos lo que se nos ingreso
* \return Retorna 0 (EXITO) y -1 (ERROR) si no
*/
int getUserMenuOption(char* confirUser,char message[],char errorMessage[]);


/**
* \brief Se le pregunta al usuario LA OPCION DEL MENU DE ENTEROS
* \param mensaje el mensaje que le vamos a mostrar al usuario "Ingrese...."
* \param errorMensaje el mensaje de ERROR que le vamos a mostrar al usuario
* \param input Array donde cargamos lo que se nos ingreso
* \param minOption int numero minimo de menu
* \param maxOption int numero minimo de menu
* \return Retorna 0 (EXITO) y -1 (ERROR) si no
*/
int getUserMenuOptionInt(int* confirUser,char message[],char errorMessage[],int minOption,int maxOption);


/**
* \brief RECIBE EL ANIO Y VERIFICA SI ES O NO BISIESTO
* \return Retorna 0 (si no) y -1 (si es) si no
*/
int  esAnioBisiesto(int year);
/**
* \brief VALIDA LA FECHA, ANIO, DIA Y MES
* \return Retorna 0 (si no) y -1 (si es) si no
*/

//int isValidDate(eFecha *validDate);				///SE USA CON ESTUCTURAS
//-------------------------------------------------------------------------------
//										ENTEROS:

/**
* \brief Lee de stdin hasta que encuentra un '\n' o hasta que haya copiado en cadena
* un máximo de 'longitud - 1' caracteres.
* \param cadena Puntero al espacio de memoria donde se copiara la cadena obtenida
* \param longitud Define el tamaño de cadena
* \return Retorna 0 (EXITO) si se obtiene una cadena y -1 (ERROR) si no
*
*/
int myGets(char* cadena, int longitud);


/**
* \brief Verifica si la cadena ingresada es numerica
* \param cadena Cadena de caracteres a ser analizada
* \return Retorna 1 (vardadero) si la cadena es numerica y 0 (falso) si no lo es
*/
int esNumerica(char* cadena, int limite);

/**
* \brief Obtiene un NUMERO ENTERO
* \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
* \return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
*/
int getInt(int* pResultado);

/**
 * pResultado: Puntero a variable donde se escribirá el valor ingresado en el caso de ser correcto.
 * mensaje: Puntero a cadena de caracteres con mensaje a imprimir antes de pedirle al usuario datos por consola.
 * mensajeError: Puntero a cadena de caracteres con mensaje de error en el caso de que el dato ingresado no sea válido.
 *minimo: Valor mínimo admitido (inclusive)
 *maximo: Valor máximo admitido (inclusive)
 *reintentos: Cantidad de veces que se le volverá a pedir al usuario que ingrese un dato en caso de error.
 */
int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);

/**
* \brief verifica si la cadena obtenida CONTIENE NUMEROS Y LETRAS UNICAMENTE
* \param string el string a analizar
* \return Retorna 0 (EXITO) y -1 (ERROR) si no
*/
int esAlfaNumerico(char string[],char message[],int maxLimit);


int getValidStringAlpha(char requestMessage[],char errorMessageLenght[],char input[], int lowLimit,int maxLenght);

//-------------
int esNumericoII(char str[]);

void getStringInValid(char mensaje[],char input[]);

int getStringNumerosEnteros(char mensaje[],char input[]);

int getValidInt(char requestMessage[],char errorLenghtMessage[],char errorMessage[], int lowLimit, int hiLimit,int* input);
//-------------------------------------------------------------------------------
//									FLOTANTES:
/**
* \brief Obtiene un NUMERO FLOTANTE
* \param message el mensaje para pedir el valor
* \return Retorna auxFlotante el flotante
*/
float getFloat(char message[],float auxFloat);


/**
* \brief Verifica si la cadena ingresada es de FLOTANTES
* \param stringFloat Cadena de flotantes a ser analizada
* \return Retorna 1 (vardadero) si la cadena es numerica y 0 (falso) si no lo es
*/
int esFloat(char stringFloat[]);


/**
* \brief Obtiene una cadena DE FLOTANTES del usuario y verifica QUE SEA FLOTANTE Y NO SE PASE
* UTILIZA FUNCIONES INTERNAS!
* \param message el mensaje que le vamos a mostrar al usuario "Ingrese...."
* \param errorMessage le decimos que NO ES FLOTANTE LO QUE INGRESO
* \param errorWithLenght le decimos que se paso con la cadena ingresada
* \param minLimit es lo MINIMO q ingresa (ej. 1 caracter)
* \param maxiLenth es lo MAXIMO que puede ingresar (ej. 30 caracteres)
* \param *input Array donde cargamos lo que se nos ingreso
* \return Retorna 0 (EXITO) y -1 (ERROR) si no
*/
int getValidFloat(char message[],char errorMessage[],char errorMessageLenght[], float lowLimit, float highLimit, float* input);

/**
* \brief Obtiene una cadena DE FLOTANTES del usuario y verifica QUE NO SE PASE
* \param message el mensaje que le vamos a mostrar al usuario "Ingrese...."
* \param errorWithLenght le decimos que se paso con la cadena ingresada
* \param minLimit es lo MINIMO q ingresa (ej. 1 caracter)
* \param maxiLenth es lo MAXIMO que puede ingresar (ej. 30 caracteres)
* \param *input Array donde cargamos lo que se nos ingreso
* \return Retorna 0 (EXITO) y -1 (ERROR) si no
*/
int getFloatValidation(float* input, char message[],char errorMessage[], float lowLimit, float highLimit);
//-----------------------------------------------------------------------
//							STRINGS FUNCTIONS BELOW

/**
* \brief Se le pregunta al usuario si quiere continuar
* \param mensaje el mensaje que le vamos a mostrar al usuario "Ingrese...."
* \param errorMensaje el mensaje de ERROR que le vamos a mostrar al usuario
* \param input Array donde cargamos lo que se nos ingreso
* \return Retorna 0 (EXITO) y -1 (ERROR) si no
*/
int getUserConfirmation(char* confirUser,char message[],char errorMessage[]);


/**
* \brief Se le pregunta al usuario su sexo
* \param mensaje el mensaje que le vamos a mostrar al usuario "Ingrese...."
* \param errorMensaje el mensaje de ERROR que le vamos a mostrar al usuario
* \param input Array donde cargamos lo que se nos ingreso
* \return Retorna 0 (EXITO) y -1 (ERROR) si no
*/
int getGender(char message[],char errorMessage[],char userGender[]);


/**
* \brief Recibe una cadena y convierte sus primeras letras en mayusculas
* \param string1 la string a cambiar
* \return Retorna 0 (EXITO) y -1 (ERROR) si no
*/
int convertFirstLetterStringUpper(char string1[]);



/**
* \brief Obtiene una cadena string del usuario
* \param message el mensaje que le vamos a mostrar al usuario "Ingrese...."
* \param input Array donde cargamos lo que se nos ingreso
* \return Retorna 0 (EXITO) y -1 (ERROR) si no
*/
void getString(char mensaje[],char input[]);


/**
* \brief Obtiene una cadena string del usuario y comienza a verificar ya que cuenta con funciones INTERNAS
* \param message el mensaje que le vamos a mostrar al usuario "Ingrese...."
* \param input Array donde cargamos lo que se nos ingreso
* \return Retorna 0 (EXITO) y -1 (ERROR) si no
*/
int getStringCaracteres(char mensaje[],char input[]);


/**
* \brief Obtiene una cadena string del usuario y VERIFICA QUE ESTE CONTENGA SOLAMENTE LAS LETRAS
* CONECTA CON getStringWord (recibe la cadena) y la VALIDA (ES  FUNCION INTERNA)
* \param string Array donde recibimos su input
* \return Retorna 0 (EXITO) y -1 (ERROR) si no
*/
int sonLetras(char str[]);

/**
* \brief Obtiene una cadena string del usuario y verifica el tamaño
* \param message el mensaje que le vamos a mostrar al usuario "Ingrese...."
* \param errorWithLenght le decimos que se paso con la cadena ingresada
* \param minLimit es lo MINIMO q ingresa (ej. 1 caracter)
* \param maxiLenth es lo MAXIMO que puede ingresar (ej. 30 caracteres)
* \param input Array donde cargamos lo que se nos ingreso
* \return Retorna 0 (EXITO) y -1 (ERROR) si no
*/
int getValidString(char requestMessage[],char errorMessage[], char errorMessageLenght[],char input[], int lowLimit,int maxLenght);

/**
* \brief LIMPIA EL \n DE FGETS
* \param cadena la string a remover su \n
** \param largo de la cadena
* \return Retorna 0 (EXITO) y -1 (ERROR) si no
*/
int  limpiarBarraN(char cadena[], int tam);


//------------------------------------------------------------
// 				INIT USER OR SEARCH FREE SPACE BELOW
/**
* \brief Se incializa el usuario pero es PARA ESTRUCTURAS (usa .isEmpty)
* \param variable lo que inicializa
* \param maxQuantity la cantidad del array
*/
//void initUser(variable, maxQuantity);


/**
* \brief Se incializa el usuario pero es PARA ARRAYS
* \param variable lo que inicializa
* \param max la cantidad del array
*/
int initUserWithArrays(int elementos[],int max);



/**
* \brief Se busca espacio LIBRE EN ARRAY
* \param elementos el array
* \param max maxima cantidad del array
* \param *pIndex el index para saber si esta LIBRE O NO
* \return Retorna 0 (EXITO) y -1 (ERROR) si no
*/
int searchFreeSpace(int elementos[],int max,int* pIndex);


#endif /* UTN_H_ */
