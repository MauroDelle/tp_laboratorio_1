/*
 * utn.c
 *
 *  Created on: 13 sep. 2022
 *      Author: delle
 */


#include "utn.h"



int esNumerica(char* cadena, int limite)
 {
 	int todoOk = 1;
 	int i;
 	for(i=0;i<limite && cadena[i] != '\0';i++)
 	{
 		if(i==0 && (cadena[i] == '+' || cadena[i] == '-'))
 		{
 			continue;
 		}
 		if(cadena[i] > '9' || cadena[i] < '0')
 		{
 			todoOk = 0;
 			break;
 		}
 	}

 	return todoOk;
 }


int myGets(char* cadena, int longitud)
{
	int todoOk = -1;
	char bufferString [4096];

	if(cadena != NULL && longitud>0)
	{
		fflush(stdin);
		if(fgets(bufferString,sizeof(bufferString), stdin)!= NULL)
		{
			if(bufferString[strnlen(bufferString,sizeof(bufferString))-1] =='\n')
			{
				bufferString[strnlen(bufferString,sizeof(bufferString))-1] ='\0';
			}
			if(strnlen(bufferString,sizeof(bufferString))<= longitud)
			{
				strncpy(cadena,bufferString,longitud);
				todoOk=0;
			}
		}
	}

	return todoOk;

}


int getInt(int* pResultado)
 {
     int todoOk=-1;
     char bufferString[50];
     if(pResultado != NULL &&
     	myGets(bufferString,sizeof(bufferString)) == 0 &&
     	esNumerica(bufferString,sizeof(bufferString)))
 	{
    	 todoOk=0;
 		*pResultado = atoi(bufferString);

 	}
     return todoOk;
 }


int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int todoOk = -1;
	int bufferInt;
	do
	{
		printf("%s",mensaje);
		if(	getInt(&bufferInt) == 0 &&
			bufferInt >= minimo &&
			bufferInt <= maximo)
		{
			todoOk = 0;
			*pResultado = bufferInt;
			break;
		}
			printf("%s",mensajeError);

		reintentos--;
	}while(reintentos>=0);

	return todoOk;
}


int getValidInt(char requestMessage[],char errorLenghtMessage[],char errorMessage[], int lowLimit, int hiLimit,float* input)
{
    char auxStr[256];
    int auxInt;
    int myReturn=-1;
    while(1)
    {
        if (!getStringNumerosEnteros(requestMessage,auxStr))
        {
        	printf ("%s\n",errorMessage);
            continue;

        }
        auxInt = atoi(auxStr);
        if(auxInt < lowLimit || auxInt > hiLimit)
        {
            printf ("%s\n",errorLenghtMessage);
            continue;

        }
        myReturn=0;
        *input=auxInt;
        break;

    }

    return myReturn;
}

void getStringInValid(char mensaje[],char input[])
{
    printf("%s",mensaje);
    scanf ("%s", input);
}

int getStringNumerosEnteros(char mensaje[],char input[])
{
    char aux[256];
    getStringInValid(mensaje,aux);
    if(esNumericoII(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

int esNumericoII(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if(str[i] < '0' || str[i] > '9')
           return 0;
       i++;
   }
   return 1;
}



int getString(char input[], int tam)
{
    char auxiliarStr[tam];
    int isOk = -1;

    if (input != NULL && tam > 0)
    {
        fflush(stdin);
        fgets(auxiliarStr,tam,stdin);
        if (auxiliarStr[strlen(auxiliarStr)-1]=='\n')
        {
        	auxiliarStr[strlen(auxiliarStr)-1]='\0';
        }
        if(strlen(auxiliarStr)<= tam)
        {
            strncpy(input, auxiliarStr, tam);
            isOk=0;
        }
    }

    return isOk;
}

void limpiar()
{
	printf("\n\n\n");

}




int utn_getString(char mensaje[], char mensajeError[], int tam, int reintentos, char input[])
{
	int isOk = 1;
    char auxiliarStr[tam];

    if(input != NULL && mensaje != NULL && mensajeError != NULL && tam > 0 && reintentos >= 0)
    {
        do{
        	printf("%s", mensaje);
            if(!(getString(auxiliarStr,tam)) && !(esValido(auxiliarStr)))
            {
                strncpy(input,auxiliarStr,tam);
                isOk = 0;
                break;
            }
            else
            {
            	printf("%s", mensajeError);
            	reintentos--;
            }

        }while(reintentos>=0);
    }

    return isOk;
}

int esValido(char string[])
{
	int isOk;
	int i;
	int strTam = strlen(string);

	isOk = 0;


	for(i = 0; i<strTam; i++)
	{
		if((string[i] != ' ') && (string[i] < 'a' || string[i] > 'z') && (string[i] < 'A' || string[i] > 'Z'))
		{

			isOk = -1;
		}

	}

	return isOk;
}


