/*
 * menuPrincipal.h
 *
 *  Created on: 1 nov. 2022
 *      Author: delle
 */

#ifndef MENUPRINCIPAL_H_
#define MENUPRINCIPAL_H_

int menu_listado();
int menu();
void pFunction(char* messageError1,char* messageError2,char* messageSucess,int* flag,int flagValue,
				LinkedList* array,int(*pFunction)(LinkedList*));

#endif /* MENUPRINCIPAL_H_ */
