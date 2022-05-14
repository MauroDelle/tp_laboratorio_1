/*
 * utn.c
 *
 *  Created on: 22 abril. 2022
 *      Author: delle
 *
 *
 *      Carpeta Utn.c Baus 5/4
 *
 */



#include "defines.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>




int getUserConfirmation(char* confirUser,char message[],char errorMessage[])
{
	int todoOk = -1;

	char auxConf;

	if(confirUser!=NULL && message!=NULL && errorMessage!=NULL)
	{
		printf("%s ", message);
		fflush(stdin);
		scanf("%c", &auxConf);
		auxConf=tolower(auxConf);
		while(auxConf!='s' && auxConf!='n')
		{
			printf("%s ", errorMessage);
			fflush(stdin);
			scanf("%c", &auxConf);
			auxConf=tolower(auxConf);
		}

		*confirUser = auxConf;
		todoOk=0;
	}

	return todoOk;
}

void limpioPantalla()
{
	printf("\n\n\n\n\n");
}

void showMessage(char string[])
{
	printf("%s\n",string);
}

int getUserMenuOption(char* confirUser,char message[],char errorMessage[])
{
	int todoOk = -1;

	char auxConf;

	if(confirUser!=NULL && message!=NULL && errorMessage!=NULL)
	{
		printf("%s ", message);
		fflush(stdin);
		scanf("%c", &auxConf);
		auxConf=toupper(auxConf);
		while(auxConf!='A' && auxConf!='B' && auxConf!='C' && auxConf!='D'  && auxConf!='E')
		{
			printf("%s ", errorMessage);
			fflush(stdin);
			scanf("%c", &auxConf);
			auxConf=toupper(auxConf);
		}

		*confirUser = auxConf;
		todoOk=0;
	}

	return todoOk;
}


int getUserMenuOptionInt(int* confirUser,char message[],char errorMessage[],int minOption,int maxOption)
{
	int todoOk = -1;

	int auxConf;

	if(confirUser!=NULL && message!=NULL && errorMessage!=NULL)
	{
		printf("%s ", message);
		scanf("%d", &auxConf);
		while(auxConf<minOption || auxConf>maxOption)
		{
			printf("%s ", errorMessage);
			scanf("%d", &auxConf);
		}
		*confirUser = auxConf;
		todoOk=0;
	}
	return todoOk;
}

int  limpiarBarraN(char cadena[], int tam)
{
    int todoOk = 0;

    if(cadena != NULL && tam > 0)
    {
        for(int i=0; i < tam; i++)
        {
            if(cadena[i] == '\n')
            {
                cadena[i] = '\0';
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int convertFirstLetterStringUpper(char string1[])
{
	int todoOk = -1;

	if(string1!=NULL)
	{
		for(int i = 0; string1[i]!= '\0';i++)
		{
			if(i==0)
			{
				if((string1[i]>'a' && string1[i]<='z'))
				{
					string1[i] = string1[i]-32;
					continue;
				}
			}
			if(string1[i]== ' ')
			{
				i++;
				if((string1[i]>'a' && string1[i]<='z'))
				{
					string1[i] = string1[i]-32;
					continue;
				}
			}
			else
			{
				if(string1[i]>='A' && string1[i]<='Z')
				{
					string1[i]=string1[i]+32;
				}
			}
		}
	}
	return todoOk;
}

void getString(char mensaje[],char input[])
{
    printf("%s",mensaje);
    fflush(stdin);
    fgets(input,300,stdin);
    limpiarBarraN(input,300);
}



int sonLetras(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
           return 0;
       i++;
   }
   return 1;
}

int getStringCaracteres(char mensaje[],char input[])
{
    char aux[750];
    getString(mensaje,aux);
    convertFirstLetterStringUpper(aux);
    if(sonLetras(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

int getValidString(char requestMessage[],char errorMessage[], char errorMessageLenght[],char input[], int lowLimit,int maxLenght)
{
    int retorno=-1;
    char buffer[999];

    while(1)
    {
        if (!getStringCaracteres(requestMessage,buffer))
        {
            printf ("%s\n",errorMessage);
            continue;
        }
        if(strlen(buffer) > maxLenght || strlen(buffer) < lowLimit)
        {
            printf ("%s",errorMessageLenght);
            continue;

        }
        retorno=0;
        strcpy(input,buffer);
        break;

    }

     return retorno;
}




int getGender(char message[],char errorMessage[],char userGender[])
{
	int todoOk = -1;

	char auxSex;

	if(userGender!=NULL && message!=NULL && errorMessage!=NULL)
	{
		printf("%s ", message);
		fflush(stdin);
		scanf("%c", &auxSex);
		auxSex=tolower(auxSex);
		while(auxSex!='f' && auxSex!='m' && auxSex!='b')
		{
			printf("%s ", errorMessage);
			fflush(stdin);
			scanf("%c", &auxSex);
			auxSex=tolower(auxSex);
		}
		todoOk=0;
	}

	*userGender = auxSex;

	return todoOk;
}

char getChar(char mensaje[])
{
    char auxiliar;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%c",&auxiliar);
    auxiliar=toupper(auxiliar);
    return auxiliar;
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


int getValidInt(char requestMessage[],char errorLenghtMessage[],char errorMessage[], int lowLimit, int hiLimit,int* input)
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



int getValidStringAlpha(char requestMessage[],char errorMessageLenght[],char input[], int lowLimit,int maxLenght)
{
    int retorno=-1;
    char buffer[999];

    while(1)
    {
    	getString(requestMessage, buffer);
        if(strlen(buffer) > maxLenght || strlen(buffer) < lowLimit)
        {
            printf ("%s",errorMessageLenght);
            continue;

        }
        retorno=0;
        strcpy(input,buffer);
        break;
    }

     return retorno;
}


int esAlfaNumerico(char string[],char message[],int maxLimit)
{
	int todoOk = 0;
	int i = 0;

	if(string!=NULL)
	{
		getString(message, string);
		while(string[i]!='\0')
		{
			if((string[i]!=' ')&&(string[i]<'a' || string[i]>'z')&&(string[i]<'A'||string[i]>'Z')&&(string[i]<'0' || string[i]>'9'))
			{
				todoOk = 0;
				i++;
			}
			else if((string[i]>maxLimit))
			{
				printf("\nSE EXCEDIO EL LIMITE");
				todoOk = 1;
			}
		}
	}
	return todoOk;
}


float getFloat(char message[],float auxFloat)
{
	float auxFlotante;

	printf("%s", message);
	fflush(stdin);
	scanf("%f",&auxFlotante);

	return auxFlotante;
}

int esFloat(char stringFloat[])
{
	int i = 0;

	int quantityDots = 0;
	while(stringFloat[i] != '\0')
	{
		if(stringFloat[i] == '.' && quantityDots == 0)
		{
			quantityDots=quantityDots+1;
			i++;
			continue;
		}

		if(stringFloat[i]<'0' || stringFloat[i]>9)
		{
			return 0;
			i++;
		}
	}
	return 1;
}

int getStringFloat(char message[], char userInputFloat[])
{
	int todoOk = -1;
	char auxiliarFloat [1000];

	getString(message,auxiliarFloat);
	if(esFloat(auxiliarFloat))
	{
		strcpy(userInputFloat,auxiliarFloat);
		todoOk = 0;
	}
	return todoOk;
}


int getValidFloat(char message[],char errorMessage[],char errorMessageLenght[], float lowLimit, float highLimit, float* input)
{
    char auxString[256];
    float auxiliarFloat;
    int todoOk=-1;
    while(1)
    {
        if (!getStringFloat(message,auxString))
        {
            printf ("%s\n",errorMessage);
            continue;
        }

        auxiliarFloat = atof(auxString);

        if(auxiliarFloat < lowLimit || auxiliarFloat > highLimit)
        {
            printf ("%s",errorMessageLenght);
            continue;

        }
        todoOk=0;
        *input=auxiliarFloat;
        break;

    }

    return todoOk;
}


int getFloatValidation(float* input, char message[],char errorMessage[], float lowLimit, float highLimit)
{
	int todoOk = -1;
	float auxFloat;

	if(input!=NULL && lowLimit<highLimit)
	{
		printf("%s",message);
		fflush(stdin);
		scanf("%f", &auxFloat);
		while(auxFloat < lowLimit || auxFloat>highLimit)
		{
			printf("%s",errorMessage);
			fflush(stdin);
			scanf("%f", &auxFloat);
		}
		*input = auxFloat;
		todoOk = 0;
	}
	return todoOk;
}


int initUserWithArrays(int elementos[],int max)
{
	int todoOk = -1;

	if(elementos!=NULL && max>0)
	{
		for(int i=0;i<max;i++)
		{
			elementos[i] = -1;
		}
		todoOk = 0;
	}
	return todoOk;
}

int searchFreeSpace(int elementos[],int max,int* pIndex)
{
	int todoOk = -1;

	int index;

	if(elementos!=NULL && max>0 && pIndex!=NULL)
	{
		for(int i=0;i<max;i++)
		{
			if(elementos[i] == -1)
			{
				index = i;
				break;
			}
		}
		*pIndex = index;
		todoOk = 0;
	}
	return todoOk;
}
