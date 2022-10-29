/*
 * confederacion.c
 *
 *  Created on: 13 oct. 2022
 *      Author: delle
 */
#include "confederacion.h"
#include "jugador.h"









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
    if(confederaciones != NULL && tam > 0 && pIndice != NULL)
    {
            *pIndice = -1;
            for(int i=0; i < tam; i++)
            {
                if(confederaciones[i].id == id)
                {
                    *pIndice = i;
                    break;
                }
            }
        todoOk = 1;
    }
    return todoOk;
}
/*
int ordenarAlfabeticoNombreYConfederacion(eConfederacion confederaciones[], int tam,eJugador jugadores[], int tamJ)
{
	int todoOk = 0;
	int indice;
	eConfederacion conf;
	eJugador jugador;


	if(confederaciones != NULL && tam > 0 && jugadores != NULL && tamJ > 0)
	{
		for(int i = 0; i < tamJ - 1; i++)
		{
			if(jugadores[i].isEmpty != 1)
			{
				for(int j = i + 1; j < tam; j++)
				{
					if(buscarConfederacion(confederaciones, tam, jugador[i].idConfederacion, &indice))
					{



					}
				}
			}
		}
	}

	return todoOk;
}
*/

int hardcodearConfederaciones(eConfederacion vec[], int tam, int cant,int* pLegajo)
{
	int todoOk = 0;
	eConfederacion confederaciones[TAMC] =
	{
			{0,"CONMEBOL","SUDAMERICA",1916},
			{0,"UEFA","EUROPA",1954},
			{0,"AFC","ASIA",1954},
			{0,"CAF","AFRICA",1957},
			{0,"CONCACAF","NORTE Y CENTRO AMERICA",1961},
			{0,"OFC","OCEANIA",1966}
	};

	if(vec != NULL && tam > 0 && pLegajo != NULL && cant > 0 && cant <= tam)
	{
		for(int i = 0;i < cant; i++)
		{
			vec[i] = confederaciones[i];
			vec[i].id = *pLegajo;
			*pLegajo = *pLegajo + 1;
		}
		todoOk = 1;
	}


	return todoOk;
}

int inicializarConfederacion(eConfederacion vec[],int tam)
{
    int todoOk = 0;
    if(vec != NULL && tam > 0)
    {
        for(int i=0; i < tam; i++)
        {
            vec[i].isEmpty = 1;
        }
        todoOk = 1;
    }
    return todoOk;
}

int buscarConfederacionLibre(eConfederacion vec[], int tam, int* pIndex)
{
    int todoOk = 0;
    if(vec != NULL && tam > 0 && pIndex != NULL)
    {
        *pIndex = -1;
        for(int i=0; i < tam; i++)
        {
            if( vec[i].isEmpty )
            {
                *pIndex = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}



int mostrarConfederacion(eConfederacion e, int tam,eConfederacion confederaciones[],int tamC)
{
	int todoOk = 0;
	char auxNombre[50];
	char auxRegion[50];

	if(tam > 0)
	{
		cargarNombreYRegion(confederaciones, tam, e.id, auxNombre, auxRegion);

		printf("%d       %s         %s         %d",e.id,e.nombre,e.region,e.anioCreacion);

		todoOk = 1;
	}


	return todoOk;
}


int bajaConfederacion(eConfederacion vec[], int tam)
{
	int todoOk = 0;
	int indice;
	int legajo;
	char confirma;

	if(vec != NULL && tam > 0)
	{
		listarConfederaciones(vec, tam);
		getValidInt("\nINGRESE EL ID DE LA CONFEDERACION: ", "\nINGRESE UN VALOR VALIDO ", "\nINGRESE NUMEROS UNICAMENTE: ", 100,110, &legajo);

		if(buscarConfederacion(vec, tam, legajo, &indice))
		{

			if(indice == -1)
			{
				printf("No hay una confederacion con el ID  %d\n", legajo);

			}
			else
			{
				mostrarConfederacion(vec[indice], tam, vec, tam);
				printf("Confirmar Baja?: ");
				fflush(stdin);
				scanf("%c", &confirma);
				if(confirma != 'S' && confirma != 's')
				{
					printf("Baja cancelada por el usuario!\n");
				}
				else
				{
					vec[indice].isEmpty = 1;
					printf("Baja realizada con exito!\n");
					todoOk = 1;
				}
			}
		}
		else
		{
			printf("ocurrio un problema!\n");

		}
		todoOk = 1;


	}

	return todoOk;
}



int altaConfederacion(eConfederacion vec[], int tam, int* pLegajo)
{
	int todoOk = 0;
	int indice;
	char auxNombre[50];
	char auxRegion[50];
	int auxAnioCreacion;
	eConfederacion nuevaConfederacion;



	if(vec != NULL && tam > 0 && pLegajo != NULL)
	{
        system("cls");
        printf("       *** Alta Confederacion *** \n");
        printf("-------------------------------------------\n\n");

        if(buscarConfederacionLibre(vec, tam, &indice))
        {
        	if(indice == -1)
        	{
        		printf("No hay lugar en el sistema!\n");
        	}
        	else
        	{
        		getValidString("ingrese el nombre de la confederacion: ", "Error! Reingrese: ", "Solamente letras! Reingrese: ", auxNombre, 2, 50);
        		fflush(stdin);
        		strcpy(vec[indice].nombre, auxNombre);

        		getValidString("ingrese la región: ", "Error! Reingrese", "Error! Solo letras: ", auxRegion, 2, 50);
        		strcpy(vec[indice].region, auxRegion);

        		getValidInt("\nIngrese el año de creación: ", "\nError! Solamente numeros: ", "\nError! Ingrese un año valido: ", 1910,2022, &auxAnioCreacion);
        		nuevaConfederacion.anioCreacion = auxAnioCreacion;

        		nuevaConfederacion.isEmpty = 0;
        		nuevaConfederacion.id = *pLegajo;
        		*pLegajo = *pLegajo + 1;
        		vec[indice] = nuevaConfederacion;
        		todoOk = 1;
        	}
        }
        else
        {
        	printf("Ocurrio un problema con los parametros\n");
        }

	}

	return todoOk;
}





int listarConfederaciones(eConfederacion confederaciones[], int tam)
{
	int todoOk = 0;

    if(confederaciones != NULL && tam > 0)
    {
        printf("   *** Lista de Confederaciones  ***\n");
        printf("  ID         NOMBRE        REGION          AÑO CREACION\n");
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

int cargarNombreYRegion(eConfederacion confederaciones[], int tam, int id,char nombre[], char region[])
{
	int retorno = 0;
	int indice;

	buscarConfederacion(confederaciones, tam, id, &indice);

	if(nombre != NULL && indice != -1)
	{
		strcpy(nombre, confederaciones[indice].nombre);
		strcpy(region,confederaciones[indice].region);
		retorno = 1;
	}

	return retorno;
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








