
#ifndef PARSER_H_
#define PARSER_H_

int parser_saveAsTextSeleccion(FILE* pArchivo, LinkedList* pArrayListSeleccion);
int parser_saveAsText(FILE* pArchivo, LinkedList* pArrayListJugador);
int parser_JugadorFromText(FILE* pFile , LinkedList* pArrayListJugador);
int parser_JugadorFromBinary(FILE* pFile , LinkedList* pArrayListJugador);
int parser_SeleccionFromText(FILE* pFile , LinkedList* pArrayListSeleccion);


#endif /* PARSER_H_ */
