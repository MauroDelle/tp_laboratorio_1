#include <stdio.h>
#include <stdlib.h>

#include "Jugador.h"
#include "Seleccion.h"
#include "parser.h"
#include "utn.h"
#include "Controller.h"
#include "LinkedList.h"




int controller_filtrarConvocados(LinkedList* pArrayListSelecciones,LinkedList* pArrayListJugador,LinkedList* pArrayJugadoresFiltrados)
{
	int retorno = 0;
	int auxIdSeleccion;
	int cantConvocados;
	Jugador* pAuxJugador = NULL;
	int idSeleccionDelJugador;



	if(pArrayListSelecciones != NULL && pArrayListJugador != NULL)
	{
		controller_listarSelecciones(pArrayListSelecciones);
		utn_getNumero(&auxIdSeleccion, "INGRESE EL ID DE LA SELECCION: ", "ERROR, REINTENTE: ", 1, ll_len(pArrayListSelecciones), 50);
        Seleccion* seleccion = ll_get(pArrayListSelecciones, selec_searchForId(pArrayListSelecciones,auxIdSeleccion));

        if(selec_getConvocados(seleccion, &cantConvocados) != -1  && cantConvocados > 0)
        {
    		for(int indice = 0; indice < ll_len(pArrayListJugador);indice++)
    		{
    			pAuxJugador = ll_get(pArrayListJugador, indice);
    			if(jug_getSIdSeleccion(pAuxJugador, &idSeleccionDelJugador) != -1 && idSeleccionDelJugador == auxIdSeleccion)
    			{
    				ll_add(pArrayJugadoresFiltrados, pAuxJugador);
    			}
    		}

    		printf("SE GUARDO EN BINARIO\n");

        }
        else
        {
        	printf("\nNO NO HAY CONVOCADOS\n");
        	retorno = -1;
        }
	}

	return retorno;
}


int controller_listarConvocados(LinkedList* pArrayListSelecciones, LinkedList* pArrayListJugador)
{
	int todoOk = 0;

	Jugador *pAuxJugador;
	int sizeOf;

	if(pArrayListJugador == NULL)
	{
		printf("\nNO PLAYERS REGISTERED!");
	}
	else
	{
		printf("\n\n");
		printf("|--------------------------------------------------------------------------------------------------------------------------------------|\n");
		printf("|						       PLAYERS LIST                                                                                        ");
		printf("|--------------------------------------------------------------------------------------------------------------------------------------|\n");
		printf("|  ID |	    NOMBRE             |	EDAD       |      POSICION         |       NACIONALIDAD    |    ID SELECCION   |\n");
		printf("|-----|------------------------|-------------------|-----------------------|-----------------------|-------------------|\n");
		todoOk=1;

		sizeOf = ll_len(pArrayListJugador);

		for(int i = 0;i< sizeOf;i++)
		{
			pAuxJugador = (Jugador*) ll_get(pArrayListJugador, i);
			if(pAuxJugador != NULL && pAuxJugador->idSeleccion != 0)
			{
				jug_ShowOnlyOne(pAuxJugador);
			}
		}
		system("Pause");
	}

	return todoOk;
}



int controller_removerConvocados(LinkedList* pArrayListSelecciones, LinkedList* pArrayListJugador)
{
	int retorno = -2;
	int auxIdJugador;
	int cantConvocados;
	int idSeleccion;

	if(pArrayListSelecciones != NULL && pArrayListJugador != NULL && ll_len(pArrayListSelecciones) > 0 && ll_len(pArrayListSelecciones) > 0)
	{
		controller_listarConvocados(pArrayListSelecciones, pArrayListJugador);
		utn_getNumero(&auxIdJugador, "INGRESE EL ID DEL JUGADADOR A DESCONVOCAR: ", "ERROR, REINTENTE: ", 1, ll_len(pArrayListJugador), 50);
		Jugador* jugador = ll_get(pArrayListJugador, jug_searchForId(pArrayListJugador,auxIdJugador));

		if(jug_getSIdSeleccion(jugador, &idSeleccion) != -1 && idSeleccion != 0)
		{
	        Seleccion* seleccion = ll_get(pArrayListSelecciones, selec_searchForId(pArrayListSelecciones,idSeleccion));

	        if(selec_getConvocados(seleccion, &cantConvocados) != -1  && cantConvocados > 0)
	        {
	        	  selec_setConvocados(seleccion, cantConvocados - 1);
	        	  jug_setIdSeleccion(jugador,0);
	        	  printf("EL JUGADOR FUE ELIMINADO\n");
	        	  retorno = 1;
	        }
	        else
	        {
	            printf("\nNOOOOOOOOOOOOOO LA SELESION NO TIENE CONVOCADOOO GIOOOO\n");
	            retorno = 0;
	        }
		}
		else
		{
	        printf("NO PÁ\n");
	        retorno = -1;
		}
	}
	return retorno;
}

int controller_convocarJugadores(LinkedList* pArrayListSelecciones, LinkedList* pArrayListJugador)
{
	int retorno = -2;
	int auxIdJugador;
	int auxIdSeleccion;
	int cantConvocados;
	int idSeleccion;
	int topeConvocados = 26;

	if(pArrayListSelecciones != NULL && pArrayListJugador != NULL && ll_len(pArrayListSelecciones) > 0 && ll_len(pArrayListSelecciones) > 0)
	{
		controller_listarJugadoresDeUnaSeleccion(pArrayListJugador, 0);
		utn_getNumero(&auxIdJugador, "INGRESE EL ID DEL JUGADOR A CONVOCAR: ", "ERROR, REINTENTE: ", 1, ll_len(pArrayListJugador), 50);
		Jugador* jugador = ll_get(pArrayListJugador, jug_searchForId(pArrayListJugador,auxIdJugador));

		if(jug_getSIdSeleccion(jugador, &idSeleccion) != -1 && idSeleccion == 0)
		{
			controller_listarSelecciones(pArrayListSelecciones);
			utn_getNumero(&auxIdSeleccion, "INGRESE EL ID DE LA SELECCION: ", "ERROR, REINTENTE: ", 1, ll_len(pArrayListSelecciones), 50);
	        Seleccion* seleccion = ll_get(pArrayListSelecciones, selec_searchForId(pArrayListSelecciones,auxIdSeleccion));

	        if(selec_getConvocados(seleccion, &cantConvocados) != -1  && cantConvocados < topeConvocados)
	        {
	        	  selec_setConvocados(seleccion, cantConvocados + 1);
	        	  selec_getId(seleccion, &auxIdSeleccion);
	        	  jug_setIdSeleccion(jugador, auxIdSeleccion);
	        	  printf("EL JUGADOR FUE CONVOCADO\n");
	        	  retorno = 1;
	        }
	        else
	        {
	            printf("NOOO!!! NO TIENE MAS ESPACIO LA SELECCION!!");
	            retorno = 0;
	        }
		}
		else
		{
	        printf("Este jugador ya tiene seleccion...");
	        retorno = -1;
		}
	}
	return retorno;
}

int controller_selectMenuOption2()
{
	int opcion;

	printf("____________________________");
	printf("\n|1)JUGADORES POR NACIONALIDAD\n"
			"2)SELECCIONES POR CONFEDERACION\n"
			"3)JUGADORES POR EDAD\n"
			"4)JUGADORES POR NOMBRE\n"
			"5)EXIT                    |\n");
	printf("|__________________________|");
	utn_getNumero(&opcion, "\nENTER OPTION: ", "\n[INVALID VALUE, PLEASE TRY AGAIN.]", 1, 5, 50);
	return opcion;

}


int controller_selectMenuOption()
{
	int opcion;

	printf("____________________________");
	printf("\n|1)NOMBRE                |\n|"
			"2)POSICION                |\n|"
			"3)EDAD                    |\n|"
			"4)NACIONALIDAD            |\n|"
			"5)EXIT                    |\n");
	printf("|__________________________|");
	utn_getNumero(&opcion, "\nENTER OPTION: ", "\n[INVALID VALUE, PLEASE TRY AGAIN.]", 1, 5, 50);
	return opcion;

}


int obtainID(int* id)
{
	int todoOk = 0;
	int newID;
	FILE* pFile;
	pFile = fopen("ultimaID.bin","rb"); //OPEN FILE
	if(pFile!=NULL)
	{
		fscanf(pFile, "%d\n", &newID);//LEO LA ID
		*id = newID;
		fclose(pFile); //IF CAN BE OPENED THEN CLOSE IT AT THE END
		todoOk = 1;
	}
	return todoOk;
}

int upgradeID(int id)
{
	int nextID = ++id; //UPGRADE'S ID
	int todoOk = 0;
	FILE* pFile;
	pFile = fopen("ultimaID.bin","wb"); //OPEN
	if(pFile!=NULL)
	{
		fprintf(pFile,"%d\n",nextID);//LA ESCRIBO EN EL ARCHIVO
		fclose(pFile); //IF CAN BE OPENED THE CLOSE IT AT THE END
		todoOk = 1;
	}
	return todoOk;
}



int saveAsBinary_LastID(FILE* pFile, LinkedList* pArrayListJugador,int* maxID)
{
	Jugador* jugador;

	int id;
	int len_LL;
	int todoOk = 0;
	int maxId;
	int flag = 0;

	if(pFile != NULL && pArrayListJugador != NULL)
	{
		len_LL = ll_len(pArrayListJugador);

		for(int i = 0; i < len_LL;i++)
		{
			jugador = ll_get(pArrayListJugador,i);
			if(jugador!=NULL)
			{
				jug_getHigherId(jugador, &id);
				if(flag == 0 || id > maxId)
				{
					maxId = id;
					flag = 1;
				}
				todoOk = 1;
			}
		}
	}
	*maxID = maxId;

	return todoOk;
}


int controller_saveBinaryLastId(FILE* pFile,char* path, LinkedList* pArrayListJugador)
{
    int todoOk = 0;
    int maxID;

    if(pFile !=NULL && saveAsBinary_LastID(pFile,pArrayListJugador,&maxID))
    {
        todoOk = 1;
        fprintf(pFile,"%d\n",maxID+1);
    }
    return todoOk;

}

/** \brief Carga los datos de los jugadores desde el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_cargarJugadoresDesdeTexto(char* path , LinkedList* pArrayListJugador)
{
	int todoOk = 0;

	FILE* pFile; //guardar pasajeros
	FILE* pFile2; //subir next id

	pFile = fopen(path,"r");
	pFile2 = fopen("ultimaID.bin","wb");

	if(pFile != NULL)
	{
		parser_JugadorFromText(pFile, pArrayListJugador);
		fclose(pFile);
		todoOk = 1;
	}
	if(controller_saveBinaryLastId(pFile2, "ultimaID.bin", pArrayListJugador))
	{
		fclose(pFile2);
	}
	return todoOk;
}

/** \brief Carga los datos de los jugadores desde el archivo generado en modo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_cargarJugadoresDesdeBinario(char* path , LinkedList* pArrayListJugador)
{
	int todoOk=0;

	FILE* pFile;
	Jugador *pAuxPassenger;
	int sizeOfList;

	if(path!=NULL && pArrayListJugador!=NULL)
	{
		pFile = fopen(path,"wb");//OPEN FILE AS BINARY
		sizeOfList = ll_len(pArrayListJugador);
		for(int i=0;i<sizeOfList;i++)
		{
			pAuxPassenger = (Jugador*) ll_get(pArrayListJugador, i);//CAST IF ERROR
			if(pAuxPassenger!=NULL)
			{
				fwrite(pAuxPassenger,sizeof(Jugador),1,pFile);//WRITE ON THE FILE
			}
		}
		fclose(pFile);//CLOSE FILE
		ll_clear(pArrayListJugador);//CLEAR LIST
		todoOk=1;
	}
    return todoOk;
}

/** \brief Alta de jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_agregarJugador(LinkedList* pArrayListJugador)
{
	int todoOk=0;

	Jugador *pAuxJugador;
	pAuxJugador = jug_new();
	char confirmation;

	//auxiliares
	int auxId;
	char nombreCompleto[100];
	int auxEdad;
	char auxPosicion[30];
	char auxNacionalidad[30];

	if(pArrayListJugador != NULL)
	{
		printf("\n__________________________________________________________________________");
		printf("\n                                                                          |");
		printf("\n                           JUGADOR ADD                                  |\n");
		printf("__________________________________________________________________________|");
		obtainID(&auxId);
		utn_getNombre(nombreCompleto,98, "\nINGRESE EL NOMBRE DEL JUGADOR: ", "\n[ERROR ONLY LETTERS, A MAX OF 48 CHARACTERS & NO SPACES.] ", 50);
		convertFirstLetterStringUpper(nombreCompleto);

		utn_getNumero(&auxEdad, "\nINGRESE LA EDAD DEL JUGADOR: ", "\n[ERROR ONLY LETTERS, A MAX OF 48 CHARACTERS & NO SPACES.]. ", 20, 44, 50);
		utn_getNombre(auxPosicion, 28, "\nINGRESE LA POSICION: ", "\n[ERROR ONLY LETTERS, A MAX OF 28 CHARACTERS & NO SPACES.] ", 50);
		utn_getNombre(auxNacionalidad, 28, "\nINGRESE LA NACIONALIDAD: ", "\n[ERROR ONLY LETTERS, A MAX OF 28 CHARACTERS & NO SPACES.] ", 50);


		getUserConfirmation(&confirmation, "\nDESEA AGREGAR AL JUGADOR?(S/N): ", "\nERROR, REINTENTE: ");

		if(confirmation == 's')
		{
			if(pAuxJugador != NULL)
			{
				jug_setId(pAuxJugador, auxId);
				jug_setNombreCompleto(pAuxJugador, nombreCompleto);
				jug_setEdad(pAuxJugador, auxEdad);
				jug_setPosicion(pAuxJugador, auxPosicion);
				jug_setNacionalidad(pAuxJugador, auxNacionalidad);
				ll_add(pArrayListJugador, pAuxJugador);
				upgradeID(auxId);
				todoOk = 1;
			}
		}
		else
		{
			printf("\nTHE ADDITION HAS BEEN CANCELLED!\n");
			todoOk=1;
		}

	}

	return todoOk;
}

/** \brief Modificar datos del jugador
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_editarJugador(LinkedList* pArrayListJugador)
{
    int todoOk = 0;
    Jugador *pAuxjugador;

    char nacionalidad[30];
    //auxiliares



    char auxNombre[100];
    int auxEdad;
    char auxPosicion[30];

    int index;
    int maxId;
    int idSearch;
    char confirmation;


    if(pArrayListJugador != NULL)
    {
		printf("\n__________________________________________________________________________");
		printf("\n                                                                          |");
		printf("\n                      PLAYER MODIFICATION                                 |\n");
		printf("__________________________________________________________________________|");
		obtainID(&maxId);
		controller_listarJugadores(pArrayListJugador);
		utn_getNumero(&idSearch, "\nENTER PLAYER'S IDs TO MODIFY: ", "\n[INVALID VALUES, PLEASE TRY AGAIN.]", 1, (maxId-1), 50);

		index = jug_searchForId(pArrayListJugador, idSearch);

		if(index == 1)
		{
			printf("\n THERE IS NO PLAYER WITH ID Nº%d",idSearch);
		}
		else
		{
			pAuxjugador = ll_get(pArrayListJugador, index);
			if(pAuxjugador != NULL)
			{
				printf("\n\n");
				printf("|--------------------------------------------------------------------------------------------------------------------------------------|\n");
				printf("|						       PLAYERS LIST                                                                                        ");
				printf("|--------------------------------------------------------------------------------------------------------------------------------------|\n");
				printf("|  ID |	    NOMBRE             |	EDAD       |      POSICION         |       NACIONALIDAD    |    ID SELECCION   |\n");
				printf("|-----|------------------------|-------------------|-----------------------|-----------------------|-------------------|\n");
				jug_ShowOnlyOne(pAuxjugador);

				switch(controller_selectMenuOption())
				{
					case 1:
						utn_getNombre(auxNombre, 98, "\nENTER THE PLAYER'S NEW NAME: ", "\n[ERROR ONLY LETTERS, A MAX OF 98 CHARACTERS & NO SPACES.]", 50);
						getUserConfirmation(&confirmation, "\nDO YOU REALLY WANT TO CHANGE THE PLAYER'S NAME (S/N)?: ", "\nINVALID VALUE, PLEASE TRY AGAIN (S/N): ");

						if(confirmation == 's')
						{
							convertFirstLetterStringUpper(auxNombre);
							printf("\nPLAYER'S NAME HAS BEEN UPDATED TO %s\n",auxNombre);
							jug_setNombreCompleto(pAuxjugador, auxNombre);
						}
						else
						{
							printf("\nTHE MODIFICATION HAS BEEN CANCELLED!");
						}
						todoOk = 1;
						system("Pause");
					   break;

					case 2:
						utn_getNombre(auxPosicion, 28, "\nENTER THE PLAYER'S NEW POSITION: ", "\n[ERROR ONLY LETTERS, A MAX OF 28 CHARACTERS & NO SPACES.]", 50);
						getUserConfirmation(&confirmation, "\nDO YOU REALLY WANT TO CHANGE THE PLAYER'S POSITION (S/N)?: ", "\nINVALID VALUE, PLEASE TRY AGAIN (S/N): ");

						if(confirmation == 's')
						{
							convertFirstLetterStringUpper(auxPosicion);
							printf("\nPASSENGER POSITION HAS BEEN UPDATED TO %s\n",auxPosicion);
							jug_setPosicion(pAuxjugador, auxPosicion);
						}
						else
						{
							printf("\nTHE MODIFICATION HAS BEEN CANCELLED!");
						}
						todoOk=1;
						system("Pause");
						break;

					case 3:
						utn_getNumero(&auxEdad, "\nINGRESE LA EDAD DEL JUGADOR: ", "\n[INVALID VALUES, PLEASE TRY AGAIN.]", 19, 43, 50);
						getUserConfirmation(&confirmation, "\nDO YOU REALLY WANT TO CHANGE THE PLAYERS'S AGE (S/N)?: ", "\nINVALID VALUE, PLEASE TRY AGAIN (S/N): ");

						if(confirmation == 's')
						{
							jug_setEdad(pAuxjugador, auxEdad);
							printf("\nPASSENGER AGE HAS BEEN UPDATED TO %d\n",auxEdad);
						}
						else
						{
							printf("\nTHE MODIFICATION HAS BEEN CANCELLED!");
						}
						todoOk=1;
							system("Pause");

						break;

					case 4:
						utn_getNombre(nacionalidad, 28, "\nENTER THE PLAYER'S NEW NATIONALITY: ", "\n[ERROR ONLY LETTERS, A MAX OF 28 CHARACTERS & NO SPACES.]", 50);
						getUserConfirmation(&confirmation, "\nDO YOU REALLY WANT TO CHANGE THE PLAYER'S NATIONALITY (S/N)?: ", "\nINVALID VALUE, PLEASE TRY AGAIN (S/N): ");

						if(confirmation == 's')
						{
							convertFirstLetterStringUpper(nacionalidad);
							printf("\nPASSENGER NATIONALITY HAS BEEN UPDATED TO %s\n",nacionalidad);
							jug_setNacionalidad(pAuxjugador, nacionalidad);
						}
						else
						{
							printf("\nTHE MODIFICATION HAS BEEN CANCELLED!");
						}
						todoOk=1;
						system("Pause");
						break;

					case 5:
						printf("\nEXIT MENU MODIFICATIONS.....");
						system("Pause");
						break;
				}
			}
		}
    }
    return todoOk;
}

/** \brief Baja del jugador
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_removerJugador(LinkedList* pArrayListJugador)
{
	int todoOk = 0;

	Jugador *pJugador;

	int index;
	int idJugador;
	int obtainedID;
	char confirmation;
	int maxID;
	obtainID(&maxID);

	if(pArrayListJugador != NULL)
	{
		printf("\n__________________________________________________________________________");
		printf("\n                                                                          |");
		printf("\n                        PLAYER REMOVE                                  |\n");
		printf("__________________________________________________________________________|");
		controller_listarJugadores(pArrayListJugador);
		utn_getNumero(&idJugador, "\nENTER THE PLAYER'S ID THAT YOU WANT TO REMOVE FROM THE LIST: ", "\n[INVALID VALUE, TRY AGAIN.] ", 1, (maxID-1), 50);

		index = jug_searchForId(pArrayListJugador, idJugador);

		pJugador = ll_get(pArrayListJugador, index);

		if(pJugador != NULL)
		{
			jug_getId(pJugador, &obtainedID);

			if(obtainedID == idJugador)
			{
				printf("\n\n");
				printf("|--------------------------------------------------------------------------------------------------------------------------------------|\n");
				printf("|						       PLAYERS LIST                                                                                        ");
				printf("|--------------------------------------------------------------------------------------------------------------------------------------|\n");
				printf("|  ID |	    NOMBRE             |	EDAD       |      POSICION         |       NACIONALIDAD    |    ID SELECCION   |\n");
				printf("|-----|------------------------|-------------------|-----------------------|-----------------------|-------------------|\n");
				jug_ShowOnlyOne(pJugador);
				getUserConfirmation(&confirmation, "\nDO YOU REALLY WANT TO REMOVE THE PLAYER FROM THE LIST (S/N)?: ",  "\nINVALID VALUE, PLEASE TRY AGAIN PRESSING (S/N):");

				if(confirmation == 's')
				{
					ll_remove(pArrayListJugador,index);
					if(pArrayListJugador != NULL)
					{
						jug_delete(pJugador);
						printf("\nTHE PLAYER HAS BEEN REMOVED SUCCESSFULLY!");
					}
				}
				else
				{
					printf("\nTHE PLAYER'S REMOVAL HAS BEEN CANCELLED!");
				}
				todoOk = 1;
			}
		}
	}

	return todoOk;
}

/** \brief Listar jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_listarJugadores(LinkedList* pArrayListJugador)
{
	int todoOk = 0;

	Jugador *pAuxJugador;
	int sizeOf;

	if(pArrayListJugador == NULL)
	{
		printf("\nNO PLAYERS REGISTERED!");
	}
	else
	{
		printf("\n\n");
		printf("|--------------------------------------------------------------------------------------------------------------------------------------|\n");
		printf("|						       PLAYERS LIST                                                                                        ");
		printf("|--------------------------------------------------------------------------------------------------------------------------------------|\n");
		printf("|  ID |	    NOMBRE             |	EDAD       |      POSICION         |       NACIONALIDAD    |    ID SELECCION   |\n");
		printf("|-----|------------------------|-------------------|-----------------------|-----------------------|-------------------|\n");
		todoOk=1;

		sizeOf = ll_len(pArrayListJugador);

		for(int i = 0;i< sizeOf;i++)
		{
			pAuxJugador = (Jugador*) ll_get(pArrayListJugador, i);
			if(pAuxJugador != NULL)
			{
				jug_ShowOnlyOne(pAuxJugador);
			}
		}
		system("Pause");
	}

	return todoOk;
}

/** \brief Ordenar jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_ordenarJugadores(LinkedList* pArrayListJugador)
{
   int retorno = -1;
   int opcion;

   int (*pFuncion)(void* arg1, void* arg2);

   if(pArrayListJugador != NULL && !ll_isEmpty(pArrayListJugador))
   {
	   utn_getNumero(&opcion, "CRITERIOS:\n- 1. JUGADORES POR NACIONALIDAD.\n-."
			                    "\n-3.JUGADORES POR EDAD.\n -4.JUGADORES POR NOMBRE.\n INGRESE CRITERIO:",
			                    "ERROR! INGRESE UNA OPCION VALIDA: (1-4)", 1, 3, 50);

	   if(opcion == 1)
	   {
		   pFuncion = jug_sortByNacionalidad;
	   }
	   if(opcion == 2)
	   {
		   pFuncion = jug_sortByEdad;
	   }
	   if(opcion==3)
	   {
		   pFuncion = jug_sortByName;
	   }
		// 1:Ascendiente
		// 0:Descendiente

	   utn_getNumero(&opcion,"ORDEN:\n- 1. ASCENDIENTE.\n- 2. DESCENDIENTE.\n INGRESE ORDEN:","ERROR, INGRESE UNA OPCION VALIDA(1-4):\n",1,2,50);
		if(opcion==1)
		{
			printf("- ORDENANDO PASAJEROS PORFAVOR ESPERE...\n");
			retorno=ll_sort(pArrayListJugador, pFuncion, 1);
		} else {
			printf("- ORDENANDO PASAJEROS PORFAVOR ESPERE...\n");
			retorno=ll_sort(pArrayListJugador, pFuncion, 0);
		}
   }

   return retorno;

}

/** \brief Guarda los datos de los jugadores en el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_guardarJugadoresModoTexto(char* path , LinkedList* pArrayListJugador)
{
	int retorno = -2;
	FILE* pArchivo;
	pArchivo = fopen(path,"w");
	if(pArchivo != NULL && stringIsPath(path)&&pArrayListJugador != NULL)
	{
		printf("REALIZANDO ESCRITURA....\n");
		retorno = parser_saveAsText(pArchivo, pArrayListJugador);
	}
	fclose(pArchivo);
	return retorno;
}

/** \brief Guarda los datos de los jugadores en el archivo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_guardarJugadoresModoBinario(char* path , LinkedList* pArrayListJugador)
{
    int retorno = 0;
    FILE* pArchivo;

    pArchivo = fopen(path,"wb");

    if(pArchivo != NULL && stringIsPath(path) && pArrayListJugador != NULL)
    {
    	printf("\nREALIZANDO ESCRITURA...\n");
    	retorno = parser_saveAsBinary(pArchivo, pArrayListJugador);

    }
    fclose(pArchivo);

    return retorno;
}



/** \brief Carga los datos de los selecciones desde el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_cargarSeleccionesDesdeTexto(char* path , LinkedList* pArrayListSeleccion)
{
	int todoOk=0;

	FILE* pFile;//SAVE SELECCIONES
	FILE* pFile2;//UPDATE NEXT ID

	pFile=fopen(path, "r");
	pFile2=fopen("IDSelecciones.bin","wb");

	if(pFile != NULL)
	{
		parser_SeleccionFromText(pFile, pArrayListSeleccion);
		fclose(pFile);
		todoOk=1;
	}
	if(controller_saveBinaryLastId(pFile2, "IDSelecciones.bin", pArrayListSeleccion))
	{
		fclose(pFile2);
	}

	return todoOk;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_editarSeleccion(LinkedList* pArrayListSeleccion)
{
    return 1;
}


/** \brief Listar selecciones
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_listarSelecciones(LinkedList* pArrayListSeleccion)
{
   int todoOk = 0;

   Seleccion *pAuxSeleccion;
   int sizeOf;

   if(pArrayListSeleccion == NULL)
   {
	   printf("\nNO HAY SELECCIONES REGISTRADAS!");
   }
   else
   {
	   printf("\n\n");
	   printf("|----------------------------------------------------------------------|\n");
	   printf("|						 SELECCIONES LIST                             |");
	   printf("|----------------------------------------------------------------------|\n");
	   printf("|  ID |	    PAIS       |	  CONFEDERACION      |    CONVOCADOS      | \n");
	   printf("|-----|-----------------|-------------------------|--------------------|\n");
	   todoOk = 1;
	   sizeOf = ll_len(pArrayListSeleccion);
	   for(int i = 0; i < sizeOf;i++)
	   {
		   pAuxSeleccion = (Seleccion*) ll_get(pArrayListSeleccion, i);
		   if(pAuxSeleccion != NULL)
		   {
			   selec_ShowOnlyOne(pAuxSeleccion);
		   }
	   }
   }
   return todoOk;
}

/** \brief Ordenar selecciones
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_ordenarSelecciones(LinkedList* pArrayListSeleccion)
{
    int retorno = -1;
    int opcion;

    int (*pFuncion)(void* arg1, void* arg2);
	// 1:Ascendiente
	// 0:Descendiente
    if(pArrayListSeleccion!=NULL&&!ll_isEmpty(pArrayListSeleccion))
    {
    	pFuncion = selec_sortByConfederacion;
 	   utn_getNumero(&opcion,"ORDEN:\n- 1. ASCENDIENTE.\n- 2. DESCENDIENTE.\n INGRESE ORDEN:","ERROR, INGRESE UNA OPCION VALIDA(1-4):\n",1,2,50);
		if(opcion==1){
			printf("- ORDENANDO PASAJEROS PORFAVOR ESPERE...\n");
			retorno=ll_sort(pArrayListSeleccion, pFuncion, 1);
		} else {
			printf("- ORDENANDO PASAJEROS PORFAVOR ESPERE...\n");
			retorno=ll_sort(pArrayListSeleccion, pFuncion, 0);
		}
    }

    return retorno;
}

/** \brief Guarda los datos de los selecciones en el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_guardarSeleccionesModoTexto(char* path , LinkedList* pArrayListSeleccion)
{
    int retorno = -2;
    FILE* pArchivo;
    pArchivo = fopen(path,"w");
    if(pArchivo != NULL && stringIsPath(path)&&pArrayListSeleccion != NULL)
    {
    	printf("-REALIZANDO ESCRITURA...\n");
    	retorno = parser_saveAsTextSeleccion(pArchivo, pArrayListSeleccion);
    }
    fclose(pArchivo);

    return retorno;
}




int controller_listarJugadoresDeUnaSeleccion(LinkedList* pArrayListJugador, int idSeleccion)
{
	int todoOk = 0;

	Jugador *pAuxJugador;
	int sizeOf;

	if(pArrayListJugador == NULL)
	{
		printf("\nNO PLAYERS REGISTERED!");
	}
	else
	{
		printf("\n\n");
		printf("|--------------------------------------------------------------------------------------------------------------------------------------|\n");
		printf("|						       PLAYERS LIST                                                                                        ");
		printf("|--------------------------------------------------------------------------------------------------------------------------------------|\n");
		printf("|  ID |	    NOMBRE             |	EDAD       |      POSICION         |       NACIONALIDAD    |    ID SELECCION   |\n");
		printf("|-----|------------------------|-------------------|-----------------------|-----------------------|-------------------|\n");
		todoOk=1;

		sizeOf = ll_len(pArrayListJugador);

		for(int i = 0;i< sizeOf;i++)
		{
			pAuxJugador = (Jugador*) ll_get(pArrayListJugador, i);
			if(pAuxJugador != NULL && pAuxJugador->idSeleccion == idSeleccion)
			{
				jug_ShowOnlyOne(pAuxJugador);
			}
		}
		system("Pause");
	}

	return todoOk;
}



