/*
 * utn.c
 *
 *  Created on: 17 nov. 2022
 *      Author: delle
 */
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"


/// @brief  Solicita un numero de tipo int al usuario, luego de verificarlo devuelve el resultado.
///
/// @param pNumeroIngresado Puntero al espacio de memoria donde se dejara el resultado de la funcion.
/// @param mensaje Mensaje que se muestra.
/// @param mensajeError Mensaje de error que se muestra.
/// @param maximo Maximo numero permitido.
/// @param minimo Numero minimo permitido.
/// @param maximoDeReintentos Maximo de reintentos permitidos.
/// @return Retorna 0 si se obtuvo correctamente el numero y -1 en caso de error.


int utn_getInt(int * pNumeroIngresado,char * mensaje,char * mensajeError,int maximo, int minimo, int maximoDeReintentos){

    int auxNumeroIngresado;
    int retorno= -1;


    if(pNumeroIngresado != NULL && maximo >= minimo && maximoDeReintentos>= 0){
        do{
            printf("%s", mensaje);
            scanf("%d", &auxNumeroIngresado);
            maximoDeReintentos--;

            if(auxNumeroIngresado >= minimo && auxNumeroIngresado <= maximo){
                        *pNumeroIngresado = auxNumeroIngresado;
                        retorno = 0;
                        break;
            }else{
                printf("%s", mensajeError);
            }

        }while(maximoDeReintentos > 0);

    }
    return retorno;
}

/// @brief  Solicita un numero de tipo flotante al usuario, luego de verificarlo devuelve el resultado.
///
/// @param pNumeroIngresado Puntero al espacio de memoria donde se dejara el resultado de la funcion.
/// @param mensaje Mensaje que se muestra.
/// @param mensajeError Mensaje de error que se muestra.
/// @param maximo Maximo numero permitido.
/// @param minimo Numero minimo permitido.
/// @param maximoDeReintentos Maximo de reintentos permitidos.
/// @return Retorna 0 si se obtuvo correctamente el numero y -1 en caso de error.

int utn_getFloat(float * pNumeroIngresado,char * mensaje,char * mensajeError,float maximo, float minimo, int maximoDeReintentos){

    float auxNumeroIngresado;
    int retorno;
    retorno = -1;

    if(pNumeroIngresado != NULL && maximo >= minimo && maximoDeReintentos>= 0){
        do{
            printf("%s", mensaje);
            scanf("%f", &auxNumeroIngresado);
            maximoDeReintentos--;

            if(auxNumeroIngresado >= minimo && auxNumeroIngresado <= maximo){
                        *pNumeroIngresado = auxNumeroIngresado;
                        retorno = 0;
                        break;
            }else{
                printf("%s", mensajeError);
            }

        }while(maximoDeReintentos > 0);
    }

    return retorno;
}

/// @brief  Solicita un dato de tipo char al usuario, luego de verificarlo devuelve el resultado.
///
/// @param pNumeroIngresado Puntero al espacio de memoria donde se dejara el resultado de la funcion.
/// @param mensaje Mensaje que se muestra.
/// @param mensajeError Mensaje de error que se muestra.
/// @param maximo Maximo char permitido.
/// @param minimo Char minimo permitido.
/// @param maximoDeReintentos Maximo de reintentos permitidos.
/// @return Retorna 0 si se obtuvo correctamente el char y -1 en caso de error.

int utn_getChar(char * pNumeroIngresado,char * mensaje,char * mensajeError,char maximo, char minimo, int maximoDeReintentos)
{
	int retorno = -1;
	char auxCharIngresado;

	if(pNumeroIngresado != NULL && maximo >= minimo && maximoDeReintentos>= 0){
	        do{
	            printf("%s", mensaje);
	            scanf("%c", &auxCharIngresado);
	            maximoDeReintentos--;

	            if(auxCharIngresado >= minimo && auxCharIngresado <= maximo){
	                        *pNumeroIngresado = auxCharIngresado;
	                        retorno = 0;
	                        break;
	            }else{
	                printf("%s", mensajeError);
	            }

	        }while(maximoDeReintentos > 0);
	    }


 return retorno;
}

/// @brief  Calcula y despues de verificar devuelve el promedio de jugadores por mercado.
///
/// @param pPromedio Puntero al espacio de memoria donde se dejara el resultado de la funcion.
/// @param totalJuagoresConfederacion Cantidad de jugadores por cada mercado.
/// @param totalJugadoresIngresados Total de jugadores ingresados.
/// @return Retorna 0 si se realizo correctamente la operacion y -1 en caso de error.

int utn_getPromedioPorMercado(float * pPromedio, float totalJuagoresConfederacion, float totalJugadoresIngresados){

	float auxPromedio;
	int retorno = -1;


        if(pPromedio != NULL)
        {
		auxPromedio = totalJuagoresConfederacion * 100 / totalJugadoresIngresados;
		*pPromedio = auxPromedio;

		retorno = 0;
        }else
        {
        	retorno = -1;
        }



    return retorno;
}

/// @brief  Calcula y despues de verificar devuelve el total del costo de mantenimiento.
///
/// @param pCostoTotalMantenimiento Puntero al espacio de memoria donde se dejara el resultado de la funcion.
/// @param costoNumeroUno Costo numero uno ingresado por el usuario.
/// @param costoNumeroDos Costo numero dos ingresado por el usuario.
/// @param costoNumeroTres Costo numero tres ingresado por el usuario.
/// @return Retorna 0 si se realizo correctamente la operacion y -1 en caso de error.

int utn_getCostoMantenimiento(float * pCostoTotalMantenimiento, int costoNumeroUno, int costoNumeroDos, int costoNumeroTres)
{
	float auxCostoTotalMantenimiento;
	int retorno = -1;

        if(pCostoTotalMantenimiento != NULL)
        {
		auxCostoTotalMantenimiento = (float) costoNumeroUno + costoNumeroDos + costoNumeroTres;
		*pCostoTotalMantenimiento = auxCostoTotalMantenimiento;

		retorno = 0;
        }else
        {
        	retorno = -1;
        }


 return retorno;
}
