/*
 * menuPrincipal.h
 *
 *  Created on: 1 nov. 2022
 *      Author: delle
 */

#ifndef MENUPRINCIPAL_H_
#define MENUPRINCIPAL_H_

/// \brief menu de los listados
///
/// \pre
/// \post
/// \return
int menu_listado();

/// \brief menu principal
///
/// \pre
/// \post
/// \return
int menu();

/// \brief validador de datos
///
/// \pre
/// \post
/// \param messageError1
/// \param messageError2
/// \param messageSucess
/// \param flag
/// \param flagValue
/// \param array
/// \param pFunction
void pFunction(char* messageError1,char* messageError2,char* messageSucess,int* flag,int flagValue,
				LinkedList* array,int(*pFunction)(LinkedList*));

#endif /* MENUPRINCIPAL_H_ */
