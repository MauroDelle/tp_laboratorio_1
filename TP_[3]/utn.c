/*
 * utn.c
 *
 *  Created on: 1 nov. 2022
 *      Author: delle
 */

#include "utn.h"


static int esNumerica(char* cadena, int limite);
static int getInt(int* pResultado);
static int esFlotante(char* cadena);
static int getFloat(float* pResultado);
static int getString(char* cadena, int longitud);
static int esNombre(char* cadena,int longitud);
static int getNombre(char* pResultado,int longitud);
static int esDescripcion(char* cadena,int longitud);
static int getDescripcion(char* pResultado, int longitud);

int stringIsPath(char string[]){
	int retorno=1;
	int i;
	if(string!=NULL){
		for(i=0;i<strlen(string);i++){
			if(string[i]==' '){
				retorno=0;
				break;
			}
		}
	}
	return retorno;
}


/**
 * \brief 	Lee de stdin hasta que encuentra un '\n' o hasta que haya copiado en cadena
 * 			un m�ximo de 'longitud - 1' caracteres.
 * \param pResultado Puntero al espacio de memoria donde se copiara la cadena obtenida
 * \param longitud Define el tama�o de cadena
 * \return Retorna 0 (EXITO) si se obtiene una cadena y -1 (ERROR) si no
 *
 */
static int getString(char* cadena, int longitud)
{
	int retorno=-1;
	char bufferString[4096]; // *****************************

	if(cadena != NULL && longitud > 0)
	{
		fflush(stdin);
		if(fgets(bufferString,sizeof(bufferString),stdin) != NULL)
		{
			if(bufferString[strnlen(bufferString,sizeof(bufferString))-1] == '\n')
			{
				bufferString[strnlen(bufferString,sizeof(bufferString))-1] = '\0';
			}
			if(strnlen(bufferString,sizeof(bufferString)) <= longitud)
			{
				strncpy(cadena,bufferString,longitud);
				retorno=0;
			}
		}
	}
	return retorno;
}

/**
 * \brief Obtien un numero entero
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
 *
 */
static int getInt(int* pResultado)
{
    int retorno=-1;
    char bufferString[50];
    if(	pResultado != NULL &&
    	getString(bufferString,sizeof(bufferString)) == 0 &&
    	esNumerica(bufferString,sizeof(bufferString)))
	{
		retorno=0;
		*pResultado = atoi(bufferString) ;

	}
    return retorno;
}

/**
 * \brief Verifica si la cadena ingresada es numerica
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (verdadero) si la cadena es numerica, 0 (falso) si no lo es y -1 en caso de error
 *
 */
static int esNumerica(char* cadena, int limite)
{
	int retorno = -1; // ERROR
	int i;
	if(cadena != NULL && limite > 0)
	{
		retorno = 1; // VERDADERO
		for(i=0;i<limite && cadena[i] != '\0';i++)
		{
			if(i==0 && (cadena[i] == '+' || cadena[i] == '-'))
			{
				continue;
			}
			if(cadena[i] < '0'||cadena[i] > '9')
			{
				retorno = 0;
				break;
			}
			//CONTINUE
		}
		//BREAK
	}
	return retorno;
}

int stringIsInt(char string[])
{
    int retorno=1;
    if(string!=NULL){
        for(int i=0;i<strlen(string)-1;i++){
            if(isdigit(string[i])==0){
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}


/**
 * \brief Solicita un numero al usuario, leuego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param minimo Es el numero maximo a ser aceptado
 * \param maximo Es el minimo minimo a ser aceptado
 * \return Retorna 0 si se obtuvo el numero y -1 si no
 *
 */
int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno = -1;
	int bufferInt;
	do
	{
		printf("%s",mensaje);
		if(	getInt(&bufferInt) == 0 &&
			bufferInt >= minimo &&
			bufferInt <= maximo)
		{
			retorno = 0;
			*pResultado = bufferInt;
			break;
		}
		printf("%s",mensajeError);
		reintentos--;
	}while(reintentos>=0);

	return retorno;
}

/**
 * \brief Verifica si la cadena ingresada es flotante
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero flotante y -1 (ERROR) si no
 *
 */
static int getFloat(float* pResultado)
{
    int retorno=-1;
    char buffer[64];

    if(pResultado != NULL)
    {
    	if(getString(buffer,sizeof(buffer))==0 && esFlotante(buffer))
    	{
			*pResultado = atof(buffer);
			retorno = 0;
		}
    }
    return retorno;
}

/**
 * \brief Verifica si la cadena ingresada es flotante
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (vardadero) si la cadena es flotante y 0 (falso) si no lo es
 *
 */
static int esFlotante(char* cadena)
{
	int i=0;
	int retorno = 1;
	int contadorPuntos=0;

	if(cadena != NULL && strlen(cadena) > 0)
	{
		for(i=0 ; cadena[i] != '\0'; i++)
		{
			if(i==0 && (cadena[i] == '-' || cadena[i] == '+'))
			{
				continue;
			}
			if(cadena[i] < '0' || cadena[i] > '9' )
			{
				if(cadena[i] == '.' && contadorPuntos == 0)
				{
					contadorPuntos++;
				}
				else
				{
					retorno = 0;
					break;
				}
			}
		}
	}
	return retorno;
}

/**
 * \brief Solicita un numero flotante al usuario, luego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param minimo Es el numero maximo a ser aceptado
 * \param maximo Es el minimo minimo a ser aceptado
 * \return Retorna 0 si se obtuvo el numero flotante y -1 si no
 *
 */
int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos)
{
	float bufferFloat;
	int retorno = -1;
	while(reintentos>=0)
	{
		reintentos--;
		printf("%s",mensaje);
		if(getFloat(&bufferFloat) == 0)
		{
			if(bufferFloat >= minimo && bufferFloat <= maximo)
			{
				*pResultado = bufferFloat;
				retorno = 0;
				break;
			}
		}
		printf("%s",mensajeError);
	}
	return retorno;
}

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
		strlwr(string1);

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




/**
 * \brief Obtiene un string valido como nombre
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero flotante y -1 (ERROR) si no
 *
 */
static int getNombre(char* pResultado, int longitud)
{
    int retorno=-1;
    char buffer[4096];

    if(pResultado != NULL)
    {
    	if(	getString(buffer,sizeof(buffer))==0 &&
    		esNombre(buffer,sizeof(buffer)) &&
			strnlen(buffer,sizeof(buffer))<longitud)
    	{
    		strncpy(pResultado,buffer,longitud);
			retorno = 0;
		}
    }
    return retorno;
}

/**
 * \brief Verifica si la cadena ingresada es un nombre valido
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (verdadero) si la cadena es valida y 0 (falso) si no lo es
 *
 */
static int esNombre(char* cadena,int longitud)
{
	int i=0;
	int retorno = 1;

	if(cadena != NULL && longitud > 0)
	{
		for(i=0 ; cadena[i] != '\0' && i < longitud; i++)
		{
			if(cadena[i] == ' ')
			{
				continue;
			}
			if((cadena[i] < 'A' || cadena[i] > 'Z' ) && (cadena[i] < 'a' || cadena[i] > 'z' ))
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

/**
 * \brief Solicita un nombre al usuario, luego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param longitud Es la longitud del array resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param reintentos Cantidad de reintentos
 * \return Retorna 0 si se obtuvo el numero flotante y -1 si no
 *
 */
int utn_getNombre(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos)
{
	char bufferString[4096];
	int retorno = -1;
	int esNombreValido = 0;
	while(!esNombreValido && reintentos>=0)
	{
		reintentos--;
		printf("%s",mensaje);
		if(getNombre(bufferString,sizeof(bufferString)) == 0 && strnlen(bufferString,sizeof(bufferString)) < longitud && esNombre(bufferString, longitud))
		{
			strncpy(pResultado,bufferString,longitud);
			retorno = 0;
			break;
		}
		printf("%s",mensajeError);
	}
	return retorno;
}



/**
 * \brief Obtiene un string valido como descripcion
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero flotante y -1 (ERROR) si no
 *
 */
static int getDescripcion(char* pResultado, int longitud)
{
    int retorno=-1;
    char buffer[4096];

    if(pResultado != NULL)
    {
    	if(	getString(buffer,sizeof(buffer))==0 &&
    		esDescripcion(buffer,sizeof(buffer)) &&
			strnlen(buffer,sizeof(buffer))<longitud)
    	{
    		strncpy(pResultado,buffer,longitud);
			retorno = 0;
		}
    }
    return retorno;
}

/**
 * \brief Verifica si la cadena ingresada es una descripcion valida
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (verdadero) si la cadena es valida y 0 (falso) si no lo es
 *
 */
static int esDescripcion(char* cadena,int longitud)
{
	int i=0;
	int retorno = 1;

	if(cadena != NULL && longitud > 0)
	{
		for(i=0 ; cadena[i] != '\0' && i < longitud; i++)
		{
			if(cadena[i] != '.' && cadena[i] != ' ' && (cadena[i] < 'A' || cadena[i] > 'Z' ) && (cadena[i] < 'a' || cadena[i] > 'z' ) && (cadena[i] < '0' || cadena[i] > '9' ) )
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

/**
 * \brief Solicita una descripcion al usuario, luego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param longitud Es la longitud del array resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param reintentos Cantidad de reintentos
 * \return Retorna 0 si se obtuvo el numero flotante y -1 si no
 *
 */
int utn_getDescripcion(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos)
{
	char bufferString[4096];
	int retorno = -1;
	while(reintentos>=0)
	{
		reintentos--;
		printf("%s",mensaje);
		if(getDescripcion(bufferString,sizeof(bufferString)) == 0 && strnlen(bufferString,sizeof(bufferString)) < longitud )
		{
			strncpy(pResultado,bufferString,longitud);
			retorno = 0;
			break;
		}
		printf("%s",mensajeError);
	}
	return retorno;
}


/**
 * \brief Obtiene un string valido como DNI
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero flotante y -1 (ERROR) si no
 *
 */
static int getDni(char* pResultado, int longitud)
{
    int retorno=-1;
    char buffer[4096];

    if(pResultado != NULL)
    {
    	if(	getString(buffer,sizeof(buffer))==0 &&
    		esNumerica(buffer,sizeof(buffer)) &&
			strnlen(buffer,sizeof(buffer))<longitud)
    	{
    		strncpy(pResultado,buffer,longitud);
			retorno = 0;
		}
    }
    return retorno;
}



/**
 * \brief Solicita un DNI al usuario, luego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param longitud Es la longitud del array resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param reintentos Cantidad de reintentos
 * \return Retorna 0 si se obtuvo el numero flotante y -1 si no
 *
 */
int utn_getDni(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos)
{
	char bufferString[4096];
	int retorno = -1;
	while(reintentos>=0)
	{
		reintentos--;
		printf("%s",mensaje);
		if(getDni(bufferString,sizeof(bufferString)) == 0 && strnlen(bufferString,sizeof(bufferString)) < longitud )
		{
			strncpy(pResultado,bufferString,longitud);
			retorno = 0;
			break;
		}
		printf("%s",mensajeError);
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
		auxSex=toupper(auxSex);
		while(auxSex!='F' && auxSex!='M' && auxSex!='B')
		{
			printf("%s ", errorMessage);
			fflush(stdin);
			scanf("%c", &auxSex);
			auxSex=toupper(auxSex);
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

void getStringAlfanumerica(char mensaje[],char input[])
{
    printf("%s",mensaje);
    fflush(stdin);
    fgets(input,300,stdin);
    limpiarBarraN(input,300);
}


int getValidStringAlpha(char requestMessage[],char errorMessageLenght[],char input[], int lowLimit,int maxLenght)
{
    int retorno=-1;
    char buffer[999];

    while(1)
    {
    	getStringAlfanumerica(requestMessage, buffer);
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
		getStringAlfanumerica(message, string);
		while(string[i]!='\0')//UN WHILE O FOR SERIA LO MISMO
		{
			if((string[i]!=' ')&&(string[i]<'a' || string[i]>'z')&&(string[i]<'A'||string[i]>'Z')&&(string[i]<'0' || string[i]>'9') && (string[i]!='.'))
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

int utn_presioneUnaTecla(char message[],char errorMessage[])
{
	int todoOk = -1;
	char auxConf;

	if(message!=NULL && errorMessage!=NULL)
	{
		printf("%s ", message);
		fflush(stdin);
		scanf("%c", &auxConf);
		while(auxConf!='\n')
		{
			printf("%s ", errorMessage);
			fflush(stdin);
			scanf("%c", &auxConf);
		}
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


int stringIsAlphabetic(char string[]){
	int retorno=1;
	int i;
	if(string!=NULL){
		for(i=0;i<strlen(string);i++){
			if((isalpha(string[i])==0&&string[i]!=' '&&string[i]!='\n')||(i==0&&string[i]=='\n')){
				retorno=0;
				break;
			}
		}
	}
	return retorno;
}

int getAlphabeticText(char mensaje[], char destino[], int len) {
	int retorno=-1;
	if(mensaje!=NULL && destino!=NULL && len>0) {
		printf("%s \n", mensaje);
		fflush(stdin);
		fgets(destino,len,stdin);
		if(stringIsAlphabetic(destino)){
			destino[strlen(destino)-1]='\0';
			retorno=0;
		} else {
			printf("- INGRESE SOLO LETRAS.\n");
		}
	}
	return retorno;
}

