#include "LinkedList.h"
#include "Passenger.h"
#include "utn.h"
 #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"parser.h"


int saveAsBinary_LastID(FILE* pFile, LinkedList* pArrayListPassenger,int* maxID)//baus 6/6
{
    Passenger* passenger;

    int len_LL;
    int id;
    int maxId;
    int flag = 0;
    int todoOk = 0;


    if(pFile != NULL && pArrayListPassenger != NULL)
    {
        len_LL = ll_len(pArrayListPassenger);

        for(int i=0; i<len_LL; i++)
        {
        	passenger = ll_get(pArrayListPassenger,i);
        	if(passenger!=NULL)
        	{
                Passenger_getHigherId(passenger,&id);
                if(flag==0 || id>maxId)
                {
                	maxId = id;
                	flag=1;
                }
                todoOk = 1;
        	}
        }
    }
    *maxID = maxId;
    return todoOk;
}

int controller_saveBinaryLastId(FILE* pFile,char* path, LinkedList* pArrayListPassenger)
{
    int todoOk = 0;
    int maxID;

    if(pFile !=NULL && saveAsBinary_LastID(pFile,pArrayListPassenger,&maxID))
    {
        todoOk = 1;
        fprintf(pFile,"%d\n",maxID+1);
    }
    return todoOk;
}
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	int todoOk=0;

	FILE* pFile;
	FILE* pFile2;

	pFile=fopen(path, "r");
	pFile2=fopen("ultimaID.bin","wb");

	if(pFile != NULL)
	{
		parser_PassengerFromText(pFile, pArrayListPassenger);
		fclose(pFile);
		todoOk=1;
	}
	if(controller_saveBinaryLastId(pFile2,"ultimaID.bin", pArrayListPassenger))
	{
		fclose(pFile2);
	}

    return todoOk;
}


int controller_loadFromBinary(char* path , LinkedList *pArrayListPassenger)
{
	int todoOk=0;

	FILE* pFile;
	FILE* pFile2;

	pFile=fopen(path, "rb");
	pFile2=fopen("ultimaID.bin","wb");

	if(pFile != NULL)
	{
		parser_PassengerFromBinary(pFile, pArrayListPassenger);
		fclose(pFile);
		todoOk=1;
	}

	if(controller_saveBinaryLastId(pFile2,"ultimaID.bin", pArrayListPassenger))
	{
		fclose(pFile2);
	}

    return todoOk;
}


int obtainID(int* id)
{
	int todoOk = 0;
	int newID;
	FILE* pFile;
	pFile = fopen("ultimaID.bin","rb");
	if(pFile!=NULL)
	{
		fscanf(pFile, "%d\n", &newID);
		*id = newID;
		fclose(pFile);
		todoOk = 1;
	}
	return todoOk;
}

int upgradeID(int id)
{
	int nextID = ++id;
	int todoOk = 0;
	FILE* pFile;
	pFile = fopen("ultimaID.bin","wb");
	if(pFile!=NULL)
	{
		fprintf(pFile,"%d\n",nextID);
		fclose(pFile);
		todoOk = 1;
	}
	return todoOk;
}


int controller_addPassenger(LinkedList *pArrayListPassenger)
{
	int todoOk=0;

	Passenger *pAuxPassenger;
	pAuxPassenger = Passenger_new();
	char confirmation;


	int auxId;
	char auxName[50];
	char auxLastName[50];
	char auxCodeFlight[8];
	int auxTypePassenger;
	float auxPrice;
	int auxStatusFlight;

	if(pArrayListPassenger!=NULL)
	{

		printf("\n                                                                          ");
		printf("\n                           PASSENGER ADD                                  \n");
		obtainID(&auxId);
		utn_getNombre(auxName, 48, "\nIngrese el nombre del pasajero: ", "\nError! solo letras! ", 50);
		convertFirstLetterStringUpper(auxName);

		utn_getNombre(auxLastName, 48, "\nApellido: ", "\nError! solo letras! . ", 50);
		convertFirstLetterStringUpper(auxLastName);

		utn_getNumero(&auxTypePassenger, "\nIngrese type Passenger (1-ECONOMIC,2-FIRST CLASS,3-CREW MEMBER,4-EXECUTIVE CLASS): ", "\nError! Reingrese ", 1, 4, 50);

		getValidStringAlpha("\nINGRESE EL FLIGHT CODE (7 VALORES): ", "\nERROR!REINGRESE ", auxCodeFlight, 7, 7);
		strupr(auxCodeFlight);
		utn_getNumeroFlotante(&auxPrice, "\nINGRESE EL PRECIO (10000-500000): ", "\nERROR!REINGRESE", 10000, 500000, 50);

		utn_getNumero(&auxStatusFlight, "\nINGRESE EL STATUS FLIGHT (1-LANDED,2-ON TIME,3-IN FLIGHT,4-DELAYED): ", "\nERROR!REINGRESE", 1, 4, 50);

		getUserConfirmation(&confirmation, "\nDESEA AGREGAR UN PASAJERO(S/N)?: ", "\nERROR!REINGRESE (S/N): ");
		if(confirmation=='s')
		{
			if(pAuxPassenger!=NULL)
			{
				Passenger_setId(pAuxPassenger, auxId);
				Passenger_setNombre(pAuxPassenger, auxName);
				Passenger_setApellido(pAuxPassenger, auxLastName);
				Passenger_setPrecio(pAuxPassenger, auxPrice);
				Passenger_setCodigoVuelo(pAuxPassenger, auxCodeFlight);
				Passenger_setTipoPasajero(pAuxPassenger, auxTypePassenger);
				Passenger_setStatusFlight(pAuxPassenger, auxStatusFlight);
				ll_add(pArrayListPassenger, pAuxPassenger);
				upgradeID(auxId);
				todoOk=1;
			}
		}
		else
		{
			printf("\nOPERACION ABORTADA!!\n");
			todoOk=1;
		}

	}
    return todoOk;
}


int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
	int todoOk = 0;

	Passenger *pAuxPassenger;
	int sizeOf;

	if(pArrayListPassenger==NULL)
	{
		printf("\nNO HAY PASAJEROS!");
	}
	else
	{
		printf("\n\n");
		printf("|						                       PASSENGERS LIST                                                                     |");
		printf("\n\n");
		printf("|-----|----------------|----------------------|-----------------|--------------------------|---------------------|-----------------|\n");
		printf("|  ID |	    NOMBRE     |	  APELLIDO        |     PRECIO      |       CODE FLIGHT        |    TYPE PASSENGER   |   STATUS FLIGHT |\n");
		printf("|-----|----------------|----------------------|-----------------|--------------------------|---------------------|-----------------|\n");
		todoOk=1;
		sizeOf = ll_len(pArrayListPassenger);
		for(int i=0;i<sizeOf;i++)
		{
			pAuxPassenger = (Passenger*) ll_get(pArrayListPassenger, i);
			if(pAuxPassenger!=NULL)
			{
				Passenger_ShowOnlyOne(pAuxPassenger);
			}
		}
	}
    return todoOk;
}

int controller_selectMenuOption()
{
	int opcion;

	printf("\n1)NOMBRE                 \n"
			"2)APELLIDO               \n"
			"3)FLIGHT CODE             \n"
			"4)FLIGHT PRICE            \n"
			"5)TYPE PASSENGER          \n"
			"6)SALIR                    \n");

	utn_getNumero(&opcion, "\nINGRESE OPCION:", "\nERROR!REINGRESE", 1, 6, 50);
	return opcion;
}


int controller_editPassenger(LinkedList* pArrayListPassenger)
{
	int todoOk=0;

	Passenger *pAuxPassenger;
	int auxTypePassenger;
	char auxName[50];
	char auxLastName[50];
	char auxFlightCode[8];
	float auxPrice;

	int index;
	int maxId;
	int idSearch;
	char confirmation;

	if(pArrayListPassenger!=NULL)
	{

		printf("\n                                                                          ");
		printf("\n                      PASSENGER MODIFICATION                              \n");


		obtainID(&maxId);
		controller_ListPassenger(pArrayListPassenger);
		utn_getNumero(&idSearch, "\nINGRESE ID A MODIFICAR", "\nERROR!REINGRESE", 0, (maxId-1), 50);

		index = Passenger_searchForId(pArrayListPassenger, idSearch);

		if(index==1)
		{
			printf("\n NO HAY PASAJERO CON DICHA ID Nº%d",idSearch);
		}
		else
		{
			pAuxPassenger = ll_get(pArrayListPassenger, index);
			if(pAuxPassenger!=NULL)
			{
				printf("\n\n");
				printf("|						                       PASSENGERS LIST                                                                     |");
				printf("\n\n");
				printf("|-----|----------------|----------------------|-----------------|--------------------------|---------------------|-----------------|\n");
				printf("|  ID |	    NOMBRE     |	  APELLIDO        |     PRECIO      |       CODE FLIGHT        |    TYPE PASSENGER   |   STATUS FLIGHT |\n");
				printf("|-----|----------------|----------------------|-----------------|--------------------------|---------------------|-----------------|\n");
				Passenger_ShowOnlyOne(pAuxPassenger);

				switch(controller_selectMenuOption())
				{
					case 1:
					utn_getNombre(auxName, 48, "\nINGRESE UN NUEVO NOMBRE: ", "\nERROR!INGRESE ALGO VALIDO  ", 50);
					getUserConfirmation(&confirmation, "\nDESEA MODIFICAR EL NOMBRE? (S/N)?: ", "\nERROR!REINGRESE (S/N): ");
					if(confirmation=='s')
					{
						convertFirstLetterStringUpper(auxName);
						printf("\nEL NOMBRE SE ACTUALIZO A %s\n",auxName);
						Passenger_setNombre(pAuxPassenger, auxName);
					}
					else
					{
						printf("\nOPERACION ABORTADA!");
					}
					todoOk=1;
					system("Pause");
					break;
					case 2:
						utn_getNombre(auxLastName, 48, "\nINGRESE EL APELLIDO", "\nERROR!REINGRESE ", 50);
						getUserConfirmation(&confirmation, "\nDESEA MODIFICAR EL APELLIDO(S/N)?: ", "\nERROR!REINGRESE (S/N): ");
						if(confirmation=='s')
						{
							convertFirstLetterStringUpper(auxLastName);
							printf("\nSE ACTUALIZO EL APELLIDO A: %s\n",auxLastName);
							Passenger_setApellido(pAuxPassenger, auxLastName);
						}
						else
						{
							printf("\nOPERACION ABORTADA!");
						}
						todoOk=1;
						system("Pause");
					break;
					case 3:
						getValidStringAlpha("\nINGRESE UN NUEVO FLIGHT CODE ", "\nERROR!REINGRESE ", auxFlightCode, 7, 7);
						getUserConfirmation(&confirmation, "\nDESEA MODIFICAR EL FLIGHT CODE: (S/N)?: ", "\nERROR!REINGRESE (S/N): ");
						strupr(auxFlightCode);
						if(confirmation=='s')
						{
							printf("\nSE MODIFICO EL FLIGHT CODE %s A ",auxFlightCode);
							Passenger_setCodigoVuelo(pAuxPassenger, auxFlightCode);
							strupr(auxFlightCode);
							printf("%s\n",auxFlightCode);
						}
						else
						{
							printf("\nOPERACION ABORTADA!");
						}
						todoOk=1;
						system("Pause");
					break;
					case 4:
						utn_getNumeroFlotante(&auxPrice, "\nINGRESE EL NUEVO PRECIO: ", "\nERROR!REINGRESE", 10000, 500000, 50);
						getUserConfirmation(&confirmation, "\nDESEA MODIFICAR EL PRECIO DE VUELO? (S/N)?: ", "\nERROR!REINGRESE (S/N): ");
						if(confirmation=='s')
						{
							Passenger_setPrecio(pAuxPassenger, auxPrice);
							printf("\nSE ACTUALIZO EL PRECIO: $%.2f\n",auxPrice);
						}
						else
						{
							printf("\nOPERACION ABORTADA!");
						}
						todoOk=1;
						system("Pause");
					break;
					case 5:
						utn_getNumero(&auxTypePassenger,"\nINGRESE EL NUEVO TIPO DE PASAJERO (1-ECONOMIC,2-FIRST CLASS,3-CREW MEMBER,4-EXECUTIVE CLASS): ", "\nERROR! REINGRESE", 1, 4, 50);
						getUserConfirmation(&confirmation, "\nDESEA MODIFICAR EL TIPO :(S/N)?: ", "\nERROR!REINGRESE (S/N): ");
						if(confirmation=='s')
						{
							Passenger_setTipoPasajero(pAuxPassenger, auxTypePassenger);
							printf("\nSE ACTUALIZO EL TYPE A: %d\n",auxTypePassenger);
						}
						else
						{
							printf("\nOPERACION ABORTADA!");
						}
					todoOk=1;
						system("Pause");
					break;
					case 6:
						printf("\nSALIR:");
						system("Pause");
					break;
				}
			}
		}
	}
    return todoOk;
}


int controller_removePassenger(LinkedList* pArrayListPassenger)
{
	int todoOk=0;

	Passenger *pPassenger;

	int index;
	int idPassenger;
	int obtainedID;
	char confirmation;
	int maxID;
	obtainID(&maxID);
	if(pArrayListPassenger!=NULL)
	{

		printf("\n                        BAJA PASSENGER                                  \n");
		printf("__________________________________________________________________________");
		controller_ListPassenger(pArrayListPassenger);
		utn_getNumero(&idPassenger, "\nINGRESE EL ID DEL QUE QUIERE ELIMINAR: ", "\nINVALIDO, REINGRESE", 1, (maxID-1), 500);

		index = Passenger_searchForId(pArrayListPassenger, idPassenger);

		pPassenger = ll_get(pArrayListPassenger, index);
		if(pPassenger!=NULL)
		{
			Passenger_getId(pPassenger, &obtainedID);

			if(obtainedID == idPassenger)
			{
				printf("\n\n");

				printf("|						                       PASSENGERS LIST                                                                     |");
				printf("\n\n");
				printf("|-----|----------------|----------------------|-----------------|--------------------------|---------------------|-----------------|\n");
				printf("|  ID |	    NOMBRE     |	  APELLIDO        |     PRECIO      |       CODE FLIGHT        |    TYPE PASSENGER   |   STATUS FLIGHT |\n");
				printf("|-----|----------------|----------------------|-----------------|--------------------------|---------------------|-----------------|\n");
				Passenger_ShowOnlyOne(pPassenger);
				getUserConfirmation(&confirmation, "\nDESEA ELIMINAR AL PASAJERO?", "\nERROR! REINGRESE(S/N): ");
				if(confirmation=='s')
				{
					ll_remove(pArrayListPassenger, index);
					if(pArrayListPassenger!=NULL)
					{
						Passenger_delete(pPassenger);
						printf("\nLO BORRASTE PAPU!!");
					}
				}
				else
				{
					printf("\nOPEACION ABORTADA!!");
				}
				todoOk=1;
			}
		}
	}
    return todoOk;
}


int controller_showOptionMenuSort()
{
	int opcion;

	printf("\n1)POR NOMBRE                 \n"
			"2)POR APELLIDO                 \n"
			"3)POR PRECIO                    \n"
			"4)POR TYPE PASSENGER             \n"
			"5)POR STATUS FLIGHT               \n"
			"6)POR CODE FLIGHT                  \n");

	utn_getNumero(&opcion, "\nINGRESE UNA OPCION", "\nINVALIDO! REINGRESE", 1, 6, 10);

	return opcion;
}



int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
	int todoOk=0;

	if(pArrayListPassenger!=NULL)
	{
		switch(controller_showOptionMenuSort())
		{
			case 1:
				printf("\nSorting...\n");
				ll_sort(pArrayListPassenger, Passenger_sortByName, 1);
				printf("\nListo el Pollo!\n");
				system("Pause");
			break;
			case 2:
				printf("\nSorting...\n");
				ll_sort(pArrayListPassenger, Passenger_sortByLastName, 1);
				printf("\nListo el Pollo!\n");
				system("Pause");
			break;
			case 3:
				printf("\nSorting...\n");
				ll_sort(pArrayListPassenger, Passenger_sortByPrice, 1);
				printf("\nListo el Pollo!\n");
				system("Pause");
			break;
			case 4:
				printf("\nSorting...\n");
				ll_sort(pArrayListPassenger, Passenger_sortByTypePassenger, 1);
				printf("\nListo el Pollo!\n");
				system("Pause");
			break;
			case 5:
				printf("\nSorting...\n");
				ll_sort(pArrayListPassenger, Passenger_sortByStatusFlight, 1);
				printf("\nListo el Pollo!\n");
				system("Pause");
			break;
			case 6:
				printf("\nSorting...\n");
				ll_sort(pArrayListPassenger, Passenger_sortByCodeFlight, 1);
				printf("\nListo el Pollo!\n");
				system("Pause");
			break;
		}
		todoOk=1;
	}
	return todoOk;
}


int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
	int todoOk=0;

	FILE* pFile;
	Passenger *pAuxPassenger;
	int sizeOfList;

	if(path!=NULL && pArrayListPassenger!=NULL)
	{
		pFile = fopen(path,"wb");
		sizeOfList = ll_len(pArrayListPassenger);
		for(int i=0;i<sizeOfList;i++)
		{
			pAuxPassenger = (Passenger*) ll_get(pArrayListPassenger, i);
			if(pAuxPassenger!=NULL)
			{
				fwrite(pAuxPassenger,sizeof(Passenger),1,pFile);
			}
		}
		fclose(pFile);
		ll_clear(pArrayListPassenger);
		todoOk=1;
	}
    return todoOk;
}

int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
	int retorno=-1;
	int i;

	FILE* fpArchivo;

	Passenger *pPassenger;
	int id;
	char name[5000];
	char lastName[5000];
	char flightCode[1000];
	int typePassenger;
	float flightPrice;
	int statusFlight;
	int sizeOfList;

	if(pArrayListPassenger != NULL && path != NULL)
	{

		fpArchivo = fopen(path,"w");

		if(fpArchivo!=NULL)
		{
			retorno=0;
			sizeOfList = ll_len(pArrayListPassenger);
			for(i=0;i<sizeOfList;i++)
			{

            	pPassenger=(Passenger*)ll_get(pArrayListPassenger,i);
            	if(pPassenger!=NULL)
            	{
                    Passenger_getId(pPassenger, &id);
                    Passenger_getNombre(pPassenger, name);
                    Passenger_getApellido(pPassenger, lastName);
                    Passenger_getPrecio(pPassenger, &flightPrice);
                    Passenger_getCodigoVuelo(pPassenger, flightCode);
                    Passenger_getTipoPasajero(pPassenger, &typePassenger);
                    Passenger_getStatusFlight(pPassenger, &statusFlight);
    				fprintf(fpArchivo,"%d,%s,%s,%f,%s,%d,%d\n",id,name,lastName,flightPrice,flightCode,typePassenger,statusFlight);

            	}
			}
		}

			fclose(fpArchivo);
	}
	return retorno;
}
