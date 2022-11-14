
#ifndef PARSER_H_
#define PARSER_H_

/// \brief guarda a texto las selecciones
///
/// \pre
/// \post
/// \param pArchivo
/// \param pArrayListSeleccion
/// \return
int parser_saveAsTextSeleccion(FILE* pArchivo, LinkedList* pArrayListSeleccion);

/// \brief guarda a texto(.csv)
///
/// \pre
/// \post
/// \param pArchivo
/// \param pArrayListJugador
/// \return
int parser_saveAsText(FILE* pArchivo, LinkedList* pArrayListJugador);
int parser_JugadorFromText(FILE* pFile , LinkedList* pArrayListJugador);
int parser_JugadorFromBinary(FILE* pFile , LinkedList* pArrayListJugador);
int parser_SeleccionFromText(FILE* pFile , LinkedList* pArrayListSeleccion);

/// \brief guarda como binario
///
/// \pre
/// \post
/// \param pFile
/// \param pArrayListSeleccion
/// \return
int parser_saveAsBinary(FILE* pFile , LinkedList* pArrayListSeleccion);



#endif /* PARSER_H_ */
