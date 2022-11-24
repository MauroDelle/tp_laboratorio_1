#include "LinkedList.h"

#ifndef jug_H_INCLUDED
#define jug_H_INCLUDED

typedef struct
{

	int id;
	char nombreCompleto[100];
	int edad;
	char posicion[30];
	int idSeleccion;


	char nacionalidad[30];
}Jugador;
/// \brief ES EL CONSTRUCTOR DONDE PEDIMOS ESPACIO EN LA MEMORIA DINAMICA
///
/// \pre
/// \post
/// \return
Jugador* jug_new();	//lista

/// \brief ANIADE NUEVOS PARAMETROS CON LOS SETTERS
///
/// \pre
/// \post
/// \param idStr
/// \param nombreCompletoStr
/// \param edadStr
/// \param posicionStr
/// \param nacionalidadStr
/// \param idSelccionStr
/// \return
Jugador* jug_newParametros(char* idStr,char* nombreCompletoStr,char* edadStr, char* posicionStr, char* nacionalidadStr, char* idSelccionStr);

/// \brief LO QUE HACE ES ELIMINAR A UN JUGADOR DE LA LISTA CON FREE();
///
/// \pre
/// \post
/// \param this
void jug_delete(Jugador* this);


/// \brief SETTER DE LA ID
///
/// \pre
/// \post
/// \param this
/// \param id
/// \return
int jug_setId(Jugador* this,int id);

/// \brief OBTIENE UNA ID
///
///
/// \pre
/// \post
/// \param this
/// \param id
/// \return
int jug_getId(Jugador* this,int* id);

/// \brief OBTIENE LA ID MAXIMA DE LA LISTA
///
/// \pre
/// \post
/// \param this
/// \param id
/// \return
int jug_getHigherId(Jugador* this,int* id);

/// \brief muestra solamente un unico jugador
///
/// \pre
/// \post
/// \param Jugador
/// \return
int jug_ShowOnlyOne(Jugador *Jugador, char* nombreSeleccion);

/// \brief setter de nombre completp
///
/// \pre
/// \post
/// \param this
/// \param nombreCompleto
/// \return
int jug_setNombreCompleto(Jugador* this,char* nombreCompleto);

/// \brief getter del nombre completo
///
/// \pre
/// \post
/// \param this
/// \param nombreCompleto
/// \return
int jug_getNombreCompleto(Jugador* this,char* nombreCompleto);

/// \brief setter de posicion
///
/// \pre
/// \post
/// \param this
/// \param posicion
/// \return
int jug_setPosicion(Jugador* this,char* posicion);

/// \brief obtiene la posicion
///
/// \pre
/// \post
/// \param this
/// \param posicion
/// \return
int jug_getPosicion(Jugador* this,char* posicion);

/// \brief setter de nacionalidad
///
/// \pre
/// \post
/// \param this
/// \param nacionalidad
/// \return
int jug_setNacionalidad(Jugador* this,char* nacionalidad);

/// \brief obtiene la nacionalidad
///
/// \pre
/// \post
/// \param this
/// \param nacionalidad
/// \return
int jug_getNacionalidad(Jugador* this,char* nacionalidad);

/// \brief setter de edad
///
/// \pre
/// \post
/// \param this
/// \param edad
/// \return
int jug_setEdad(Jugador* this,int edad);

/// \brief obtiene la edad
///
/// \pre
/// \post
/// \param this
/// \param edad
/// \return
int jug_getEdad(Jugador* this,int* edad);

/// \brief setter de id de seleccion
///
/// \pre
/// \post
/// \param this
/// \param idSeleccion
/// \return
int jug_setIdSeleccion(Jugador* this,int idSeleccion);

/// \brief obtiene el id de la seleccion
///
/// \pre
/// \post
/// \param this
/// \param idSeleccion
/// \return
int jug_getSIdSeleccion(Jugador* this,int* idSeleccion);

/// \brief copara por id
///
/// \pre
/// \post
/// \param arg1
/// \param arg2
/// \return
int jug_compareById(void* arg1, void* arg2);

/// \brief ordena por nacionalidad
///
/// \pre
/// \post
/// \param arg1
/// \param arg2
/// \return
int jug_sortByNacionalidad(void* arg1,void* arg2);

/// brief ordena por edad
///
/// \pre
/// \post
/// \param arg1
/// \param arg2
/// \return
int jug_sortByEdad(void* arg1, void* arg2);

/// \brief ordena por nombre
///
/// \pre
/// \post
/// \param name1
/// \param name2
/// \return
int jug_sortByName(void* name1,void* name2);

/*
int jug_setIsEmpty(Jugador* this,int isEmpty);
int jug_getIsEmpty(Jugador* this,int* isEmpty);
*/

#endif // jug_H_INCLUDED
