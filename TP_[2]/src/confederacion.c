/*
 * confederacion.c
 *
 *  Created on: 13 oct. 2022
 *      Author: delle
 */
#include "confederacion.h"



int listarConfederaciones(eConfederacion confederaciones[], int tam)
{
	int todoOk = 0;

    if(confederaciones != NULL && tam > 0)
    {
        printf("   *** Lista de Confederaciones  ***\n");
        printf("  ID      NOMBRE        REGION          AÑO CREACION\n");
        printf("---------------------------------------------------------\n");
        for(int i=0; i < tam; i++){
            printf("%4d        %20s          %20s              %d  \n", confederaciones[i].id, confederaciones[i].nombre,
            		                 confederaciones[i].region,confederaciones[i].anioCreacion);
        }
        printf("\n\n");
        todoOk = 1;
    }
 return todoOk;
}


int cargarDescripcionConfederaciones(eConfederacion confederaciones[], int tam, int id, char nombre[])
{
	int retorno = 0;
	int indice;

	buscarConfederacion(confederaciones, tam, id, &indice);

	if(nombre != NULL && indice != -1)
	{
		strcpy(nombre, confederaciones[indice].nombre);
		retorno = 1;
	}

	return retorno;
}


int buscarConfederacion(eConfederacion confederaciones[], int tam, int id, int* pIndice)
{
    int todoOk = 0;
    if(confederaciones != NULL && tam > 0 && pIndice != NULL){
            *pIndice = -1;
            for(int i=0; i < tam; i++){
                if(confederaciones[i].id == id){
                    *pIndice = i;
                    break;
                }
            }
        todoOk = 1;
    }
    return todoOk;
}

int validarConfederacion(eConfederacion confederaciones[],int tam, int id)
{
    int esValido = 0;
    int indice;

    buscarConfederacion(confederaciones, tam, id, &indice);

    if(indice != -1)
    {
        esValido = 1;
    }
    return esValido;

}








