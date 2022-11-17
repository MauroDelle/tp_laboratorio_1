/*
 * utn.c
 *
 *  Created on: 17 nov. 2022
 *      Author: delle
 */
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"



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



int promedioConfederaciones(float * pPromedio, float totalJuagoresConfederacion, float totalJugadoresIngresados){
	float auxPromedio;
	int retorno = -1;


        if(pPromedio != NULL)
        {
		auxPromedio = (totalJuagoresConfederacion) / totalJugadoresIngresados;
		*pPromedio = auxPromedio;

		retorno = 0;
        }else
        {
        	retorno = -1;
        }



    return retorno;
}


int costoMantenimiento(float * ptotalMantenimiento, int costoNumeroUno, int costoNumeroDos, int costoNumeroTres)
{
	float auxtotalMantenimiento;
	int retorno = -1;

        if(ptotalMantenimiento != NULL)
        {
		auxtotalMantenimiento = (float) costoNumeroUno + costoNumeroDos + costoNumeroTres;
		*ptotalMantenimiento = auxtotalMantenimiento;

		retorno = 0;
        }else
        {
        	retorno = -1;
        }


 return retorno;
}
