int controller_cargarJugadoresDesdeTexto(char* path , LinkedList* pArrayListJugador);	//DONE
int controller_cargarJugadoresDesdeBinario(char* path , LinkedList* pArrayListJugador);
int controller_agregarJugador(LinkedList* pArrayListJugador);//DONE
int controller_editarJugador(LinkedList* pArrayListJugador);
int controller_removerJugador(LinkedList* pArrayListJugador);
int controller_listarJugadores(LinkedList* pArrayListJugador);	//DONE
int controller_ordenarJugadores(LinkedList* pArrayListJugador);
int controller_guardarJugadoresModoTexto(char* path , LinkedList* pArrayListJugador);
int controller_guardarJugadoresModoBinario(char* path , LinkedList* pArrayListJugador);
int controller_convocarJugadores(LinkedList* pArrayListSelecciones, LinkedList* pArrayListSeleccion);
int controller_listarConvocados(LinkedList* pArrayListSelecciones, LinkedList* pArrayListJugador);
int controller_removerConvocados(LinkedList* pArrayListSelecciones, LinkedList* pArrayListJugador);
int controller_filtrarConvocados(LinkedList* pArrayListSelecciones,LinkedList* pArrayListJugador);
int controller_cargarSeleccionesDesdeTexto(char* path , LinkedList* pArrayListSeleccion);//DONE
int controller_editarSeleccion(LinkedList* pArrayListSeleccion);
int controller_listarSelecciones(LinkedList* pArrayListSeleccion);
int controller_ordenarSelecciones(LinkedList* pArrayListSeleccion);
int controller_guardarSeleccionesModoTexto(char* path , LinkedList* pArrayListSeleccion);
int controller_listarJugadoresDeUnaSeleccion(LinkedList* pArrayListJugador, int idSeleccion);
int controller_saveBinaryLastId(FILE* pFile,char* path, LinkedList* pArrayListJugador);
int saveAsBinary_LastID(FILE* pFile, LinkedList* pArrayListJugador,int* maxID);
int obtainID(int* id);
int upgradeID(int id);
int controller_selectMenuOption();
int controller_selectMenuOption2();
