#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "LinkedList.h"
#include "Controller.h"
#include "Jugador.h"
#include "menuPrincipal.h"
#include "utn.h"

#define STATE_FILE_OPEN 1
#define STATE_FILE_CLOSED 0


int main()
{
	setbuf(stdout,NULL);
	int opcion;
    int opcion2;
    LinkedList* listaJugadores = ll_newLinkedList(); //init
    LinkedList* listaSelecciones = ll_newLinkedList();
    LinkedList* listaFiltrada = ll_newLinkedList();
    char confirmation = 'n';
    int fileState = 0;
    int flagArchivoBinario = 0;
    int banderaExit = 0;
    int banderaConvocados = 0;

    	//importante LEER README***

    do{

    	limpioPantalla();
        switch(menu())
        {
            case 1:
            	limpioPantalla();
            	if(fileState == 1)
            	{
            		printf("\nYA SE HA CARGADO UN ARCHIVO!\n");
            	}
            	else
            	{
					if(controller_cargarJugadoresDesdeTexto("jugadores.csv",listaJugadores) == 1)
					{
						printf("\nSE ABRIO EL ARCHIVO 'jugadores.csv' EN MODO TEXTO CON EXITO!\n");
						fileState = 1;
					}
					else
					{
						printf("\nNO SE PUDO ABRIR EL ARCHIVO 'jugadores.csv' EN MODO TEXTO\n");
					}

					if(controller_cargarSeleccionesDesdeTexto("selecciones.csv", listaSelecciones) == 1)
					{
						printf("\nSE ABRIO EL ARCHIVO 'selecciones.csv' EN MODO TEXTO CON EXITO!\n");
						fileState = 1;
					}
					else
					{
						printf("\nNO SE PUDO ABRIR EL ARCHIVO 'selecciones.csv' EN MODO TEXTO\n");
					}
        		}
            	utn_presioneUnaTecla("\nPRESIONE ENTER PARA CONTINUAR... ", "\nERROR. PRESIONE ENTER...");
                break;
            case 2:
				limpioPantalla();

				pFunction("\nDEBE CARGAR ALGUN ARCHIVO PRIMERO!",
						"\nERROR AL INTENTAR AGREGAR EL JUGADOR! ",
						"\nSE SALIO CORRECTAMENTE!",
						&fileState, STATE_FILE_CLOSED, listaJugadores, controller_agregarJugador);

				utn_presioneUnaTecla("\nPRESIONE ENTER PARA CONTINUAR... ", "\nERROR. PRESIONE ENTER...");
            	break;
            case 3:
				pFunction2("\nDEBE CARGAR ALGUN ARCHIVO PRIMERO!",
						"\nERROR AL INTENTAR MODIFICAR EL JUGADOR! ",
						"\nSE SALIO CORRECTAMENTE!",
						&fileState, STATE_FILE_CLOSED, listaJugadores, listaSelecciones, controller_editarJugador);

            	break;
            case 4:
				pFunction2("\nDEBE CARGAR ALGUN ARCHIVO PRIMERO!",
						"\nERROR AL INTENTAR ELIMINAR EL JUGADOR! ",
						"\nSE SALIO CORRECTAMENTE!",
						&fileState, STATE_FILE_CLOSED, listaJugadores, listaSelecciones, controller_removerJugador);
            	break;
            case 5:
					switch(menu_listado())
					{
					case 1:
						limpioPantalla();
						pFunction2("\nDEBE CARGAR ALGUN ARCHIVO PRIMERO!",
								"\nRROR AL INTENTAR MOSTRAR LOS JUGADORES!",
								"\nSE MOSTRO LA LISTA CON EXITO!",
								&fileState, STATE_FILE_CLOSED, listaJugadores, listaSelecciones, controller_listarJugadores);
						utn_presioneUnaTecla("\nPRESIONE ENTER PARA CONTINUAR... ", "\nERROR. PRESIONE ENTER...");
						break;
					case 2:
						pFunction("\nDEBE CARGAR ALGUN ARCHIVO PRIMERO!",
								"\nRROR AL INTENTAR MOSTRAR LOS JUGADORES!",
								"\nSE MOSTRO LA LISTA CON EXITO!",
								&fileState, STATE_FILE_CLOSED, listaSelecciones, controller_listarSelecciones);
						utn_presioneUnaTecla("\nPRESIONE ENTER PARA CONTINUAR... ", "\nERROR. PRESIONE ENTER...");
						break;
					case 3:
						if(banderaConvocados == 0)
						{
							printf("DEBE CONVOCAR AL MENOS UN JUGADOR!\n");

						}
						else
						{
							controller_listarConvocados(listaSelecciones, listaJugadores);
						}
						break;
					case 4:
						break;
					}
            	break;
            case 6:
          	   utn_getNumero(&opcion2,"MENU:\n- 1. CONVOCAR JUGADORES.\n- 2.REVOCAR CONVOCATORIA.\n INGRESE:","ERROR, INGRESE UNA OPCION VALIDA(1-2):\n",1,2,50);
          	   if(opcion2 == 1)
          	   {
          		   controller_convocarJugadores(listaSelecciones, listaJugadores);
          		   banderaConvocados = 1;
          	   }
          	   else
          	   {
          		   controller_removerConvocados(listaSelecciones, listaJugadores);
          	   }
            	break;
            case 7:
            	if(fileState == 1)
            	{
             	    utn_getNumero(&opcion,"ORDEN:\n- 1. ORDENAR JUGADORES.\n- 2. SELECCION.\n INGRESE ORDEN:","ERROR, INGRESE UNA OPCION VALIDA(1-2):\n",1,2,50);
    				if(opcion == 1)
    				{
    					controller_ordenarJugadores(listaJugadores);
    					controller_listarJugadores(listaJugadores, listaSelecciones);
    				}
    				else
    				{
    				controller_ordenarSelecciones(listaSelecciones);
    				//controller_listarJugadores(listaSelecciones, listaSelecciones);
    				controller_listarSelecciones(listaSelecciones);
    				}
             	   	printf("\nMOSTRANDO LISTA ORDENADA...\n");
             	   	utn_presioneUnaTecla("\nPRESIONE ENTER PARA CONTINUAR...\n", "\nERROR. PRESIONE ENTER...\n");
            	}
            	else
            	{
            		printf("NO SE PUEDE ORDENAR SI NO HAY NADA EN EL SISTEMA!\n");
            	}
            	break;
            case 8:
            	if(fileState == 1)
            	{
					controller_filtrarConvocados(listaSelecciones, listaJugadores, listaFiltrada);
					controller_guardarJugadoresModoBinario("FiltradosConfederacion.bin", listaFiltrada);
					flagArchivoBinario = 1;
            	}
            	else
            	{
            		printf("DEBE CARGAR AL MENOS UN JUGADOR!\n");
            	}
            	break;
            case 9:
            	if(flagArchivoBinario == 1)
            	{
					printf("\nMOSTRANDO LISTA FILTRADA...\n");
					controller_listarConvocados(listaSelecciones, listaFiltrada);
					utn_presioneUnaTecla("\nPRESIONE ENTER PARA CONTINUAR...\n", "\nERROR. PRESIONE ENTER...\n");
            	}
            	else
            	{
            		printf("DEBE GENERAR EL ARCHIVO BINARIO ANTES!\n");
            	}
            	break;
            case 10:
            	if(fileState == 1)
				{
					controller_guardarJugadoresModoTexto("jugadores.csv", listaJugadores);
					controller_guardarSeleccionesModoTexto("selecciones.csv",listaSelecciones);
				 	banderaExit = 1;
            	}
            	break;
            case 11:
            	limpioPantalla();
            		if(banderaExit ==0)
            		{
            			printf("CUIDADO! NO GUARDO LOS CAMBIOS REALIZADOS!\n");
            		}
					getUserConfirmation(&confirmation, "\nESTA SEGURO QUE DESEA SALIR? (S/N): ", "\nERROR. VALOR INVALIDO. REINTENTE (S/N): ");
					if(confirmation=='s')
					{
						printf("SE SALIO DE LA APLICACION!\nNOS VEMOS.....\n");
						ll_deleteLinkedList(listaJugadores);
					}
					else
					{
						printf("SE CANCELO EL CIERRE DE LA APLICACION!\n");
					}
				utn_presioneUnaTecla("\nPRESIONE ENTER PARA CONTINUAR... ", "\nERROR. PRESIONE ENTER...");
            	break;
        }
    }while(confirmation != 's');

    return 0;
}

