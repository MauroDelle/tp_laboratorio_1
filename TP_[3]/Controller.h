/// \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
///
/// \pre
/// \post
/// \param path
/// \param pArrayListJugador
/// \return	int
int controller_cargarJugadoresDesdeTexto(char* path , LinkedList* pArrayListJugador);	//DONE
/// \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
///
/// \pre
/// \post
/// \param path
/// \param pArrayListJugador
/// \return int
int controller_cargarJugadoresDesdeBinario(char* path , LinkedList* pArrayListJugador);

/// \brief Alta de pasajero
///
/// \pre
/// \post
/// \param pArrayListJugador
/// \return	int
int controller_agregarJugador(LinkedList* pArrayListJugador);//DONE

/// \brief modifica un jugador
///
/// \pre
/// \post
/// \param pArrayListJugador
/// \return	int
int controller_editarJugador(LinkedList* pArrayListJugador);

/// \brief quita un jugador del sistema
///
/// \pre
/// \post
/// \param pArrayListJugador
/// \return	int
int controller_removerJugador(LinkedList* pArrayListJugador);

/// \brief lista todos los jugadores
///
/// \pre
/// \post
/// \param pArrayListJugador
/// \return
int controller_listarJugadores(LinkedList* pArrayListJugador);	//DONE

/// \brief ordena jugadores
///
/// \pre
/// \post
/// \param pArrayListJugador
/// \return int
int controller_ordenarJugadores(LinkedList* pArrayListJugador);

/// \brief guarda jugadores en modo texto (.csv)
///
/// \pre
/// \post
/// \param path
/// \param pArrayListJugador
/// \return	int
int controller_guardarJugadoresModoTexto(char* path , LinkedList* pArrayListJugador);

/// \brief guarda jugadores en modo binario
///
/// \pre
/// \post
/// \param path
/// \param pArrayListJugador
/// \return	int
int controller_guardarJugadoresModoBinario(char* path , LinkedList* pArrayListJugador);

/// \brief convoca jugadores a una seleccion
///
/// \pre
/// \post
/// \param pArrayListSelecciones
/// \param pArrayListSeleccion
/// \return	int
int controller_convocarJugadores(LinkedList* pArrayListSelecciones, LinkedList* pArrayListSeleccion);

/// \brief lista los jugadores previamente convocados
///
/// \pre
/// \post
/// \param pArrayListSelecciones
/// \param pArrayListJugador
/// \return	int
int controller_listarConvocados(LinkedList* pArrayListSelecciones, LinkedList* pArrayListJugador);

/// \brief ingresa a los convocados y los quita del listado
///
/// \pre
/// \post
/// \param pArrayListSelecciones
/// \param pArrayListJugador
/// \return	int
int controller_removerConvocados(LinkedList* pArrayListSelecciones, LinkedList* pArrayListJugador);

/// \brief crea una nueva linkedlist y guarda los jugadores convocados de una conf en particular
///
/// \pre
/// \post
/// \param pArrayListSelecciones
/// \param pArrayListJugador
/// \return	int
int controller_filtrarConvocados(LinkedList* pArrayListSelecciones,LinkedList* pArrayListJugador);


/// \brief carga las selecciones desde texto(.csv)
///
/// \pre
/// \post
/// \param path
/// \param pArrayListSeleccion
/// \return
int controller_cargarSeleccionesDesdeTexto(char* path , LinkedList* pArrayListSeleccion);//DONE

int controller_editarSeleccion(LinkedList* pArrayListSeleccion);

/// \brief lista selecciones
///
/// \pre
/// \post
/// \param pArrayListSeleccion
/// \return	int
int controller_listarSelecciones(LinkedList* pArrayListSeleccion);

/// \brief ordena las selecciones de orden ascendete y edscendente
///
/// \pre
/// \post
/// \param pArrayListSeleccion
/// \return
int controller_ordenarSelecciones(LinkedList* pArrayListSeleccion);

/// \briefguarda selecciones en modo texto
///
/// \pre
/// \post
/// \param path
/// \param pArrayListSeleccion
/// \return
int controller_guardarSeleccionesModoTexto(char* path , LinkedList* pArrayListSeleccion);

/// \brief lista jugadoresde una sola seleccion
///
/// \pre
/// \post
/// \param pArrayListJugador
/// \param idSeleccion
/// \return	int
int controller_listarJugadoresDeUnaSeleccion(LinkedList* pArrayListJugador, int idSeleccion);

/// \brief guarda el ultimo id en biario
///
/// \pre
/// \post
/// \param pFile
/// \param path
/// \param pArrayListJugador
/// \return int
int controller_saveBinaryLastId(FILE* pFile,char* path, LinkedList* pArrayListJugador);

/// \brief 	guarda el ultimo id ingresado
///
/// \pre
/// \post
/// \param pFile
/// \param pArrayListJugador
/// \param maxID
/// \return
int saveAsBinary_LastID(FILE* pFile, LinkedList* pArrayListJugador,int* maxID);

/// \brief es una especie de get id
///
/// \pre
/// \post
/// \param id
/// \return
int obtainID(int* id);

/// \brief incrementa id
///
/// \pre
/// \post
/// \param id
/// \return
int upgradeID(int id);

/// \brief menu de opciones
///
/// \pre
/// \post
/// \return
int controller_selectMenuOption();

/// \brief menu de opciones
///
/// \pre
/// \post
/// \return
int controller_selectMenuOption2();
