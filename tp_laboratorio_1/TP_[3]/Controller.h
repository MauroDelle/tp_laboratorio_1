#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "utn.h"

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger);

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger);

/** \brief alta de pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger);///[DONE]

/**
 * @fn int controller_selectMenuOption()
 * @brief muestra un menu
 *
 * @return la opcion int
 */
int controller_selectMenuOption();

/** \brief modifica datos de los pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger);

/** \brief Baja de pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger);

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger);

/**
 * @fn int controller_showOptionMenuSort()
 * @brief submenu del sort
 *
 * @return opcion int
 */
int controller_showOptionMenuSort();

/** \brief orden de pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger);

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger);

/** \brief Guarda los datos de los pasajeros en el archivo data.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger);

/**
 * \brief obtiene un id
 * \param int* puntero a id
 * \return	Retorna 1 si pudo sino 0.
 */
int obtainID(int* id);

/**
 * \brief mete un upgrade a los ids
 * \param int id
 * \return	Retorna 1 si pudo sino 0.
 */
int upgradeID(int id);

/**
 * @fn int controller_saveBinaryLastId(FILE*, char*, LinkedList*)
 * @brief pasa a binario la id maxima
 *
 * @param pFile
 * @param path
 * @param pArrayListPassenger
 * @return 1 si salio todo bien o 0 si salio algo mal
 */
int controller_saveBinaryLastId(FILE* pFile,char* path, LinkedList* pArrayListPassenger);

/**
 * @fn int saveAsBinary_LastID(FILE*, char*, LinkedList*)
 * @brief GUARDA LA ID MAXIMA DE LA LISTA EN BINARIO!
 *
 * @param pFile
 * @param path
 * @param pArrayListPassenger
 * @return 1 si salio todo bien o 0 si salio algo mal
 */
int saveAsBinary_LastID(FILE* pFile, LinkedList* pArrayListPassenger,int* maxID);
