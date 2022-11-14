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
    LinkedList* listaJugadores = ll_newLinkedList(); //init
    LinkedList* listaSelecciones = ll_newLinkedList();
    char confirmation = 'n';
    int fileState = 0;
    int banderaExit = 0;

    	//importante LEER README***

    do{

    	limpioPantalla();
        switch(menu())
        {
            case 1:
            	limpioPantalla();

            	if(controller_cargarJugadoresDesdeTexto("jugadores.csv",listaJugadores) == 1)
            	{
            		printf("\nTHE JUGADORES.CSV FILE HAS BEEN OPENNED SUCCESSFULLY IN TEXT MODE!\n");
            		fileState = 1;
            	}
            	else
            	{
            		printf("\nEXISTING ERROR WHILE OPENING JUGADORES.CSV IN TEXT MODE!\n");
            	}

            	if(controller_cargarSeleccionesDesdeTexto("selecciones.csv", listaSelecciones) == 1)
            	{
               		printf("\nTHE SELECCIONES.CSV HAS BEEN OPENNED SUCCESSFULLY IN TEXT MODE!\n");
                	fileState = 1;
            	}
            	else
            	{
            		printf("\nEXISTING ERROR WHILE OPENING SELECCIONES.CSV IN TEXT MODE!\n");
            	}


            	system("Pause");
                break;
            case 2:
				limpioPantalla();

				pFunction("\nYOU NEED TO LOAD THE FILE FIRST!",
						"\nTHERE WAS AN ERROR WHILE TRYING TO ADD THE PASSENGER! ",
						"\nYOU HAVE EXITED THE ADD!",
						&fileState, STATE_FILE_CLOSED, listaJugadores, controller_agregarJugador);

				system("Pause");
            	break;
            case 3:
				pFunction("\nYOU NEED TO LOAD THE FILE FIRST!",
						"\nTHERE WAS AN ERROR WHILE TRYING TO ADD THE PASSENGER! ",
						"\nYOU HAVE EXITED THE ADD!",
						&fileState, STATE_FILE_CLOSED, listaJugadores, controller_editarJugador);

            	break;
            case 4:
				pFunction("\nYOU NEED TO LOAD THE FILE FIRST!",
						"\nTHERE WAS AN ERROR WHILE TRYING TO ADD THE PASSENGER! ",
						"\nYOU HAVE EXITED THE ADD!",
						&fileState, STATE_FILE_CLOSED, listaJugadores, controller_removerJugador);
            	break;
            case 5:
					switch(menu_listado())
					{
					case 1:
						limpioPantalla();
						pFunction("\nYOU NEED TO LOAD THE FILE FIRST!",
								"\nTHERE WAS AN ERROR TRYING TO LIST THE PASSENGERS, TRY AGAIN! ",
								"\nTHE LIST OF PASSENGERS HAS BEEN SHOWED SUCCESFULLY!",
								&fileState, STATE_FILE_CLOSED, listaJugadores, controller_listarJugadores);
						system("Pause");
						break;
					case 2:
						pFunction("\nYOU NEED TO LOAD THE FILE FIRST!",
								"\nTHERE WAS AN ERROR TRYING TO LIST THE PASSENGERS, TRY AGAIN! ",
								"\nTHE LIST OF PASSENGERS HAS BEEN SHOWED SUCCESFULLY!",
								&fileState, STATE_FILE_CLOSED, listaSelecciones, controller_listarSelecciones);
						system("Pause");
						break;
					case 3:
						controller_listarConvocados(listaSelecciones, listaJugadores);
						break;
					case 4:

						break;
					}
            	break;
            case 6:
            	controller_convocarJugadores(listaSelecciones, listaJugadores);
            	break;
            case 7:
         	   utn_getNumero(&opcion,"ORDEN:\n- 1. ORDENAR JUGADORES.\n- 2. SELECCION.\n INGRESE ORDEN:","ERROR, INGRESE UNA OPCION VALIDA(1-2):\n",1,2,50);

         	   	  if(opcion == 1)
         	   	  {
					controller_ordenarJugadores(listaJugadores);

         	   	  }
         	   	  else
         	   	  {
         	   		 controller_ordenarSelecciones(listaSelecciones);
         	   	  }
            	break;
            case 8:
            	//controller_removerConvocados(listaSelecciones, listaJugadores);
            	controller_filtrarConvocados(listaSelecciones, listaJugadores);
            	break;
            case 9:
            	break;
            case 10:
            	controller_guardarJugadoresModoTexto("jugadores.csv", listaJugadores);
            	controller_guardarSeleccionesModoTexto("selecciones.csv",listaSelecciones);
            	banderaExit = 1;
            	break;
            case 11:
            	limpioPantalla();
            		if(banderaExit ==0)
            		{
            			printf("No guardó lo cambios!\n");
            		}
					getUserConfirmation(&confirmation, "\nDO YOU REALLY WANT TO CLOSE THE APP (S/N)?: ", "\nINVALID VALUE, TRY AGAIN (S/N)!: ");
					if(confirmation=='s')
					{
						printf("YOU HAVE CHOOSEN TO CLOSE THE APP!\nSEE YOU SOON.....\n");
						ll_deleteLinkedList(listaJugadores);
					}
					else
					{
						printf("YOU HAVE CHOOSEN TO CONTINUE USING THE APP!\n");
					}
            	system("Pause");
            	break;
        }
    }while(confirmation != 's');

    return 0;
}

