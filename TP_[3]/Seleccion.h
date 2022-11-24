#include "LinkedList.h"

#ifndef selec_H_INCLUDED
#define selec_H_INCLUDED

typedef struct
{
	int id;
	char pais[30];
	char confederacion[30];
	int convocados;

}Seleccion;
/// \brief ES EL CONSTRUCTOR DONDE PEDIMOS ESPACIO EN LA MEMORIA DINAMICA
///
/// \pre
/// \post
/// \return
Seleccion* selec_new(); //DONE

/// \brief ANIADE NUEVOS PARAMETROS CON LOS SETTERS
///
/// \pre
/// \post
/// \param idStr
/// \param paisStr
/// \param confederacionStr
/// \param convocadosStr
/// \return
Seleccion* selec_newParametros(char* idStr,char* paisStr,char* confederacionStr, char* convocadosStr);	//DONE

/// \brief LO QUE HACE ES ELIMINAR A UN JUGADOR DE LA LISTA CON FREE();
///
/// \pre
/// \post
/// \param this
void selec_delete(Seleccion* this); //DONE

/// \brief getter de id
///
/// \pre
/// \post
/// \param this
/// \param id
/// \return
int selec_getId(Seleccion* this,int* id);//DONE

/// \brief 	getter del pais
///
/// \pre
/// \post
/// \param this
/// \param pais
/// \return
int selec_getPais(Seleccion* this,char* pais);	//DONE

/// \brief getter de confederacion
///
/// \pre
/// \post
/// \param this
/// \param confederacion
/// \return
int selec_getConfederacion(Seleccion* this,char* confederacion);	//DONE
int selec_getIsEmpty(Seleccion* this,int* isEmpty);

/// \brief setter de convocados
///
/// \pre
/// \post
/// \param this
/// \param convocados
/// \return
int selec_setConvocados(Seleccion* this,int convocados);	//DONE

/// \brief obtiene los convocados
///
/// \pre
/// \post
/// \param this
/// \param convocados
/// \return
int selec_getConvocados(Seleccion* this,int* convocados);	//DONE

/// \brief ordena por confederacion
///
/// \pre
/// \post
/// \param arg1
/// \param arg2
/// \return
int selec_sortByConfederacion(void* arg1, void* arg2);

/// \brief muestra tan solo una seleccion
///
/// \pre
/// \post
/// \param Seleccion
/// \return
int selec_ShowOnlyOne(Seleccion *Seleccion);


#endif // selec_H_INCLUDED
