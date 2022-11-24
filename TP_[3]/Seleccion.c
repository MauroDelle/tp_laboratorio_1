#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Seleccion.h"
#include "utn.h"



Seleccion* selec_newParametros(char* idStr,char* paisStr,char* confederacionStr, char* convocadosStr)
{
	Seleccion* this;

	this = selec_new();

	if(this != NULL && idStr != NULL && paisStr != NULL && confederacionStr != NULL && convocadosStr != NULL && stringIsInt(idStr)&& stringIsInt(convocadosStr))
	{
		this->id = atoi(idStr);
		this->convocados = atoi(convocadosStr);
		strcpy(this->pais, paisStr);
		strcpy(this->confederacion, confederacionStr);
	}

	return this;
}

Seleccion* selec_new()
{
	Seleccion* auxSelec;

	auxSelec = (Seleccion*) malloc(sizeof(Seleccion));

	/*
	if(auxSelec != NULL)
	{
		auxSelec->convocados = 0;
	}
	*/

	return auxSelec;
}

void selec_delete(Seleccion* this)
{
	if(this != NULL)
	{
		free(this);
	}
}



	//GETTERS


int selec_getId(Seleccion* this,int* id)
{
	int todoOk=-1;

	if(this!=NULL && id!=NULL)
	{
		*id = this->id;
		todoOk = 1;
	}
	return todoOk;
}

int selec_sortByConfederacion(void* arg1, void* arg2)
{
	int todoOk = 0;

	Seleccion* auxPas1;
	Seleccion* auxPas2;

	if(arg1!=NULL && arg2!=NULL)
	{
		auxPas1 = (Seleccion*) arg1;
		auxPas2 = (Seleccion*) arg2;

		todoOk = strcmp(auxPas1->confederacion,auxPas2->confederacion);
	}

	return todoOk;
}

int selec_getPais(Seleccion* this,char* pais)
{
	int todoOk=-1;
	if(this!=NULL && pais!=NULL)
	{
		todoOk=1;
		strcpy(pais,this->pais);
	}
	return todoOk;
}

int selec_getConfederacion(Seleccion* this,char* confederacion)
{
	int todoOk=-1;
	if(this!=NULL && confederacion!=NULL)
	{
		todoOk=1;
		strcpy(confederacion,this->confederacion);
	}
	return todoOk;
}


int selec_getConvocados(Seleccion* this,int* convocados)
{
	int todoOk=-1;

	if(this!=NULL && convocados>=0)
	{
		 *convocados = this->convocados;
		todoOk=1;
	}
	return todoOk;

}


	//SETTERS

int selec_setConvocados(Seleccion* this,int convocados)
{
	int todoOk=-1;

	if(this!=NULL && convocados>0)
	{
		this->convocados = convocados;
		todoOk=1;
	}

	return todoOk;

}

int selec_setId(Seleccion* this,int id)
{
	int todoOk=-1;

	if(this!=NULL && id>=0)
	{
		this->id = id;
		todoOk=1;
	}

	return todoOk;
}

int selec_setPais(Seleccion* this,char* pais)
{
	int todoOk = -1;
	if(this!=NULL && pais!=NULL && strlen(pais)<28 && strlen(pais)>=2)
	{
			strlwr(pais);
			pais[0] = toupper(pais[0]);
			strncpy(this->pais,pais,27);
			todoOk=1;

	}
	return todoOk;

}

int selec_setConfederacion(Seleccion* this,char* confederacion)
{
	int todoOk = -1;
	if(this!=NULL && confederacion!=NULL && strlen(confederacion)<28 && strlen(confederacion)>=2)
	{
			strlwr(confederacion);
			confederacion[0] = toupper(confederacion[0]);
			strncpy(this->confederacion,confederacion,27);
			todoOk=1;

	}
	return todoOk;
}


int selec_ShowOnlyOne(Seleccion *Seleccion)
{
	int todoOk=0;


	int id;
	char pais[30];
	char confederacion[30];
	int convocados;

	if(Seleccion != NULL)
	{
		selec_getId(Seleccion, &id);
		selec_getPais(Seleccion, pais);
		selec_getConfederacion(Seleccion, confederacion);
		selec_getConvocados(Seleccion, &convocados);

		printf("|%3d  |     %-8s       |      %-13s|   %4d     |\n",id,pais,confederacion,convocados);
		printf("|-----------------------------------------------------------------|\n");

		todoOk=1;
	}

	return todoOk;
}





