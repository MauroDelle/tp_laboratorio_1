/*
 * utn.c
 *
 *  Created on: 25 oct. 2022
 *      Author: delle
 */

#include "utn.h"

#define MAX_YR  2025 //MAXIMO DE AÑO
#define MIN_YR  1900 //MINIMO DE AÑO

///											CHICHES
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

/*
int  esAnioBisiesto(int year)
{
    return (((year % 4 == 0) &&
             (year % 100 != 0)) ||
            (year % 400 == 0));
}
// returns 1 if given date is valid.
int isValidDate(int validDate[])
{
    //check range of year,month and day
    if (validDate->anio > MAX_YR ||
            validDate->anio < MIN_YR)
        return 0;
    if (validDate->mes < 1 || validDate->mes > 12)
        return 0;
    if (validDate->dia < 1 || validDate->dia > 31)
        return 0;
    //Handle feb days in leap year
    if (validDate->mes == 2)
    {
        if (esAnioBisiesto(validDate->anio))
            return (validDate->dia <= 29);
        else
            return (validDate->dia <= 28);
    }
    //handle months which has only 30 days
    if (validDate->mes == 4 || validDate->mes == 6 ||
            validDate->mes== 9 || validDate->mes == 11)
        return (validDate->dia <= 30);
    return 1;
}
*/







//									STRINGS OBTENER Y VERIFICARLAS

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
		for(int i = 0; string1[i]!= '\0';i++)//RECORREMOS CADENA MIENTRAS SEA DISTINTO A \0
		{
			if(i==0)//NOS FIJAMOS SI ES MINUSCULA
			{
				if((string1[i]>'a' && string1[i]<='z'))
				{
					string1[i] = string1[i]-32; // LA HACEMOS MAYUSCULAS MEDIANTE CODIGO ASCII
					continue;
				}
			}
			if(string1[i]== ' ')//BUSCAMOS EL ESPACIO
			{
				i++;//Si encuentra ESPACIO va al siguiente lugar de la cadena
				if((string1[i]>'a' && string1[i]<='z'))
				{
					string1[i] = string1[i]-32; // LA HACEMOS MAYUSCULAS MEDIANTE CODIGO ASCII
					continue;
				}
			}
			else
			{
				if(string1[i]>='A' && string1[i]<='Z')//TODAS LAS MAYUSCYLAS PASAN A MINUSCULAS
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






//								NUMEROS ENTEROS

int myGets(char* cadena, int longitud)
{
	int todoOk = -1;
	char bufferString [4096];

	if(cadena != NULL && longitud>0)
	{
		fflush(stdin);//Limpiamos siempre
		if(fgets(bufferString,sizeof(bufferString), stdin)!= NULL)
		{
			if(bufferString[strnlen(bufferString,sizeof(bufferString))-1] =='\n')//Si encuentra un \n (el enter)
			{
				bufferString[strnlen(bufferString,sizeof(bufferString))-1] ='\0'; //Lo cambia por un \0 y corta cadena
			}
			if(strnlen(bufferString,sizeof(bufferString))<= longitud)//Si la longitud de la cadena es menor a LONGITUD
			{
				strncpy(cadena,bufferString,longitud);//Copio cadena(destino) bufferString(origen)
				todoOk=0;//Y recien ahi valido  que salio todo bien
			}
		}
	}

	return todoOk;

}

int esNumerica(char* cadena, int limite)//BufferString de getInt es su limite
 {
 	int todoOk = 1; // VERDADERO
 	int i;
 	for(i=0;i<limite && cadena[i] != '\0';i++)//Mientras i sea menor a limite y la  cadena sea distinto de \0 se va a seguir ejecutando
 	{
 		if(i==0 && (cadena[i] == '+' || cadena[i] == '-'))//SOLAMENTE si i = 0, validamos signos
 		{
 			continue;	//Continua, lo que hace es volver a iterar al for y evalua si vale la pena dar una vuelta y me saltearia el if de abajo
 		}
 		if(cadena[i] > '9' || cadena[i] < '0')
 		{
 			todoOk = 0;
 			break;
 		}
 		//CONTINUE
 	}
 	//BREAK
 	return todoOk;
 }

int getInt(int* pResultado)
 {
     int todoOk=-1;
     char bufferString[50];	//Debemos de crear un buffer string
     if(pResultado != NULL &&		//more sofisticated
     	myGets(bufferString,sizeof(bufferString)) == 0 &&
     	esNumerica(bufferString,sizeof(bufferString)))//Pregunto si salio todo bien,, se puede poner en el mismo IF
 	{
    	 todoOk=0;
 		*pResultado = atoi(bufferString); //atoi SE USA PARA CONVERTIR UNA CADENA EN NUMERO

 	}
     return todoOk;
 }

int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int todoOk = -1;
	int bufferInt;//Interactuar con el usario en un buffer
	do
	{
		printf("%s",mensaje); //Le imprimimos al usuario un mensaje sobre el ingreso de datos
		if(	getInt(&bufferInt) == 0 &&
			bufferInt >= minimo &&
			bufferInt <= maximo)
		{
			todoOk = 0;
			*pResultado = bufferInt;//Aca lo que estaba estacionado en bufferInt pasa a la direccion de mememoria de pResultado
			break;//Si tuve exito lo rompo directamente, deja de reintentar.
		}
			printf("%s",mensajeError);

		reintentos--;//si hubo un error lo decrementa y toma como valor -1, decrementa a 0 entonces se la otro reintento
	}while(reintentos>=0);

	return todoOk;
}
//--------------------OTROS ENTEREOS

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





///------------------------

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
		while(string[i]!='\0')//UN WHILE O FOR SERIA LO MISMO
		{
			if((string[i]!=' ')&&(string[i]<'a' || string[i]>'z')&&(string[i]<'A'||string[i]>'Z')&&(string[i]<'0' || string[i]>'9'))
			{
				todoOk = 0;
				//continue;
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



//									FLOTANTES

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

	int quantityDots = 0; //Incializar contador!
	while(stringFloat[i] != '\0')
	{
		if(stringFloat[i] == '.' && quantityDots == 0)
		{
			quantityDots=quantityDots+1;
			i++;
			continue;//que siga analizando
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

	getString(message,auxiliarFloat); //Llamamos a get string (para obtener cadena de flotantes)
	if(esFloat(auxiliarFloat))//Verificamos que efectivamente sea FLOTATE
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

        auxiliarFloat = atof(auxString);//DEVUELVE VALOR CONVERTIDO (ES DECIR, UNA CADENA TIPO "STRING" A FLOTANTES

        if(auxiliarFloat < lowLimit || auxiliarFloat > highLimit)//SI SE PASA DE LENGHT ERROR
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



//INIT OR SEARCH FOR FREE SPACE

/*void initUser(variable, maxQuantity)
{
	for(int i = 0;i<maxQuantity;i++)
	{
		//variable.isEmpty = 1;
	}
}
*/

int initUserWithArrays(int elementos[],int max)
{
	int todoOk = -1;

	if(elementos!=NULL && max>0)
	{
		//INCIALIZO CADA ELEMENTO EN  -1 (ESTAN VACIOS), me baso en el legajo.
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

	int index; //primer indice donde guardo el dato

	if(elementos!=NULL && max>0 && pIndex!=NULL)
	{
		for(int i=0;i<max;i++)
		{
			if(elementos[i] == -1)//SI SE CUMPLE ENCONTRE ESPACIO LIBRE
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

