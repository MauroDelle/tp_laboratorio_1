#include "LinkedList.h"

#ifndef jug_H_INCLUDED
#define jug_H_INCLUDED

typedef struct
{

	int id;
	char nombreCompleto[100];
	int edad;
	char posicion[30];
	int idSeleccion;


	char nacionalidad[30];
}Jugador;

Jugador* jug_new();	//lista
Jugador* jug_newParametros(char* idStr,char* nombreCompletoStr,char* edadStr, char* posicionStr, char* nacionalidadStr, char* idSelccionStr);

int jug_searchForId(LinkedList* pArrayListJugadores, int id);

void jug_delete(Jugador* this);

int jug_setId(Jugador* this,int id);
int jug_getId(Jugador* this,int* id);

int jug_getHigherId(Jugador* this,int* id);
int jug_ShowOnlyOne(Jugador *Jugador);

int jug_setNombreCompleto(Jugador* this,char* nombreCompleto);
int jug_getNombreCompleto(Jugador* this,char* nombreCompleto);

int jug_setPosicion(Jugador* this,char* posicion);
int jug_getPosicion(Jugador* this,char* posicion);

int jug_setNacionalidad(Jugador* this,char* nacionalidad);
int jug_getNacionalidad(Jugador* this,char* nacionalidad);

int jug_setEdad(Jugador* this,int edad);
int jug_getEdad(Jugador* this,int* edad);

int jug_setIdSeleccion(Jugador* this,int idSeleccion);
int jug_getSIdSeleccion(Jugador* this,int* idSeleccion);

int jug_compareById(void* arg1, void* arg2);
int jug_sortByNacionalidad(void* arg1,void* arg2);
int jug_sortByEdad(void* arg1, void* arg2);
int jug_sortByName(void* name1,void* name2);

/*
int jug_setIsEmpty(Jugador* this,int isEmpty);
int jug_getIsEmpty(Jugador* this,int* isEmpty);
*/

#endif // jug_H_INCLUDED
