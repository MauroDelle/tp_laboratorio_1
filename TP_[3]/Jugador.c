#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "LinkedList.h"
#include "Jugador.h"
#include "utn.h"

//							STATIC LIBRARIES
//static int esNombre(char* cadena,int longitud);

void jug_delete(Jugador* this)
{
	if(this!=NULL)
	{
		free(this);
	}
}



Jugador* jug_new()
{
	Jugador* auxJugador;

	auxJugador = (Jugador*) malloc(sizeof(Jugador));


	if(auxJugador != NULL)// inicializo los campos de la estructura
	{
		auxJugador->id = 0;
		strcpy(auxJugador->nombreCompleto, "NN");			//NONAME
		auxJugador->edad = 0;
		strcpy(auxJugador->posicion,"NP");					//NO POSITION
		strcpy(auxJugador->nacionalidad,"NN");				//NO NACIONALIDAD
		auxJugador->idSeleccion = 0;
	}
	return auxJugador;
}

Jugador* jug_newParametros(char* idStr,char* nombreCompletoStr,char* edadStr, char* posicionStr, char* nacionalidadStr, char* idSelccionStr)
{
	Jugador *this;

	this = jug_new(); //guardo lo que devuelve la funcion

	int auxId;
	int auxIdSeleccion;
	int auxEdad;

	auxEdad = atoi(edadStr);
	auxId = atoi(idStr);
	auxIdSeleccion = atoi(idSelccionStr);

	if(this != NULL && idStr != NULL && nombreCompletoStr != NULL && edadStr != NULL && posicionStr != NULL && nacionalidadStr != NULL && idSelccionStr != NULL)
	{
		if(!(jug_setId(this, auxId) && jug_setNombreCompleto (this, nombreCompletoStr) && jug_setEdad(this, auxEdad) &&
				jug_setPosicion(this, posicionStr) && jug_setNacionalidad(this, nacionalidadStr) && jug_setIdSeleccion(this, auxIdSeleccion)))
		{
			jug_delete(this);
			this = NULL;

		}

	}

	return this;

}

//GETTERS

int jug_getHigherId(Jugador* this,int* id)
{
    int todoOk = -1;

    if(this != NULL)
    {
        jug_getId(this,id);
        todoOk = 0;
    }
    return todoOk;
}


int jug_getSIdSeleccion(Jugador* this,int* idSeleccion)
{
	int todoOk = -1;

	if(this != NULL && idSeleccion > 0)
	{
		*idSeleccion = this->idSeleccion;
		todoOk = 1;

	}

	return todoOk;
}


int jug_getEdad(Jugador* this,int* edad)
{
	int todoOk=-1;

	if(this!=NULL && edad>=0)
	{
		 *edad = this->edad;
		todoOk=1;
	}
	return todoOk;

}

int jug_getNacionalidad(Jugador* this,char* nacionalidad)
{
	int todoOk = -1;
	if(this!=NULL && nacionalidad!=NULL)
	{
		todoOk=1;
		strcpy(nacionalidad,this->nacionalidad);
	}
	return todoOk;
}

int jug_getPosicion(Jugador* this,char* posicion)
{
	int todoOk = -1;
	if(this!=NULL && posicion!=NULL)
	{
		todoOk=1;
		strcpy(posicion,this->posicion);
	}
	return todoOk;
}

int jug_getId(Jugador* this,int* id)
{
	int retorno = 0;

	if(this!=NULL && id!=NULL)
	{
		*id = this->id;
		retorno = 1;
	}

	return retorno;
}


int jug_getNombreCompleto(Jugador* this,char* nombreCompleto)
{
	int todoOk=-1;
	if(this!=NULL && nombreCompleto!=NULL)
	{
		todoOk=1;
		strcpy(nombreCompleto,this->nombreCompleto);
	}
	return todoOk;

}



//SETTERS

int jug_setIdSeleccion(Jugador* this,int idSeleccion)
{
	int todoOk = -1;

	if(this != NULL && idSeleccion >= 0)
	{
		this->idSeleccion = idSeleccion;

		todoOk = 1;

	}

	return todoOk;
}


int jug_setEdad(Jugador* this,int edad)
{
	int todoOk=-1;

	if(this!=NULL && edad>17)
	{
		this->edad = edad;
		todoOk=1;
	}

	return todoOk;

}


int jug_setNacionalidad(Jugador* this,char* nacionalidad)
{
	int todoOk = -1;
	if(this!=NULL && nacionalidad!=NULL && strlen(nacionalidad)<28 && strlen(nacionalidad)>=2)
	{
			strlwr(nacionalidad);
			nacionalidad[0] = toupper(nacionalidad[0]);
			strncpy(this->nacionalidad,nacionalidad,27);
			todoOk=1;

	}
	return todoOk;
}

int jug_setPosicion(Jugador* this,char* posicion)
{
	int todoOk = -1;
	if(this!=NULL && posicion!=NULL && strlen(posicion)<35 && strlen(posicion)>=2)
	{
			strlwr(posicion);
			posicion[0] = toupper(posicion[0]);
			strncpy(this->posicion,posicion,35);
			todoOk=1;

	}
	return todoOk;
}


int jug_setNombreCompleto(Jugador* this,char* nombreCompleto)
{
	int todoOk = -1;
	if(this!=NULL && nombreCompleto!=NULL && strlen(nombreCompleto)<98 && strlen(nombreCompleto)>=2)
	{
			strlwr(nombreCompleto);
			nombreCompleto[0] = toupper(nombreCompleto[0]);
			strncpy(this->nombreCompleto,nombreCompleto,48);
			todoOk=1;

	}
	return todoOk;

}


int jug_setId(Jugador* this,int id){

	int todoOk = -1;

	if(this != NULL && id > 0)
	{
		this->id = id;
		todoOk = 1;
	}

	return todoOk;
}


int jug_ShowOnlyOne(Jugador *Jugador, char* nombreSeleccion)
{
	int todoOk=0;

	int id;
	char nombreCompleto[100];
	int edad;
	char posicion[30];
	char nacionalidad[30];

	if(Jugador != NULL)
	{
		jug_getId(Jugador, &id);
		jug_getNombreCompleto(Jugador, nombreCompleto);
		jug_getEdad(Jugador, &edad);
		jug_getPosicion(Jugador, posicion);
		jug_getNacionalidad(Jugador, nacionalidad);

		printf("|%4d | %-21s  |         %2d	   |   %-15s     |       %-20s | %14s    |\n",id,nombreCompleto,edad,posicion,nacionalidad,nombreSeleccion);
		printf("------------------------------------------------------------------------------------------------------------------\n");

		todoOk=1;
	}

	return todoOk;
}

int jug_compareById(void* arg1, void* arg2)
{
	int retorno=0;
	int idArg1, idArg2;
	if(arg1!=NULL&&arg2!=NULL){
		jug_getId((Jugador*)arg1, &idArg1);
		jug_getId((Jugador*)arg2, &idArg2);
		if(idArg1>idArg2){
			retorno=1;
		} else if(idArg1<idArg2){
			retorno=-1;
		}
	}
	return retorno;
}

//Sort
int jug_sortByNacionalidad(void* arg1,void* arg2)
{
	int retorno=0;
	char Nacionalidad1[50], Nacionalidad2[50];
	if(arg1!=NULL&&arg2!=NULL)
	{
		jug_getNacionalidad((Jugador*)arg1, Nacionalidad1);
		jug_getNacionalidad((Jugador*)arg2, Nacionalidad2);
		if(strncmp(Nacionalidad2,Nacionalidad1,4)<0)
		{
			retorno=1;
		} else if(strncmp(Nacionalidad2,Nacionalidad1,4)>0){
			retorno=-1;
		}
	}
	return retorno;
}

int jug_sortByEdad(void* arg1, void* arg2)
{
	int retorno=0;
	int idArg1, idArg2;
	if(arg1!=NULL&&arg2!=NULL)
	{
		jug_getEdad((Jugador*)arg1, &idArg1);
		jug_getEdad((Jugador*)arg2, &idArg2);
		if(idArg1>idArg2)
		{
			retorno=1;
		} else if(idArg1<idArg2){
			retorno=-1;
		}
	}
	return retorno;
}

int jug_sortByName(void* name1,void* name2)
{
	int todoOk = 0;


	Jugador* auxPas1;
	Jugador* auxPas2;

	if(name1!=NULL && name2!=NULL)
	{
		auxPas1 = (Jugador*) name1;
		auxPas2 = (Jugador*) name2;

		todoOk = strcmp(auxPas1->nombreCompleto,auxPas2->nombreCompleto);
	}

	return todoOk;
}


