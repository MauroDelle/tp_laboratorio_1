#include "LinkedList.h"

#ifndef selec_H_INCLUDED
#define selec_H_INCLUDED

typedef struct
{
	int id;
	char pais[30];
	char confederacion[30];
	int convocados;

}Seleccion;

Seleccion* selec_new(); //DONE
Seleccion* selec_newParametros(char* idStr,char* paisStr,char* confederacionStr, char* convocadosStr);	//DONE
void selec_delete(Seleccion* this); //DONE

int selec_searchForId(LinkedList* pArrayListSeleccion, int id);

int selec_getId(Seleccion* this,int* id);//DONE
int selec_getPais(Seleccion* this,char* pais);	//DONE
int selec_getConfederacion(Seleccion* this,char* confederacion);	//DONE
int selec_getIsEmpty(Seleccion* this,int* isEmpty);


int selec_setConvocados(Seleccion* this,int convocados);	//DONE
int selec_getConvocados(Seleccion* this,int* convocados);	//DONE

int selec_sortByConfederacion(void* arg1, void* arg2);

int selec_ShowOnlyOne(Seleccion *Seleccion);


#endif // selec_H_INCLUDED
