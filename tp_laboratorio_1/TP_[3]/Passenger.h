/*
 * Passenger.h
 *
 *  Created on: 19 may. 2022
 *
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_

typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	int tipoPasajero;

	char codigoVuelo[8];
	int statusFlight;

}Passenger;


/**
 * @fn Passenger Passenger_new*()
 * @brief ES EL CONSTRUCTOR DONDE PEDIMOS ESPACIO EN LA MEMORIA DINAMICA
 *
 * @return esa direccion que encontro
 */
Passenger* Passenger_new();

/**
 * @fn Passenger Passenger_newParametros*(char*, char*, char*, char*, char*, char*, char*)
 * @brief ANIADE NUEVOS PARAMETROS CON LOS SETTERS
 *
 * @param idStr char*
 * @param nombreStr char*
 * @param tipoPasajeroStr char*
 * @param apellidoStr char*
 * @param statusFlight char*
 * @param precioStr char*
 * @param codigoVuelo char*
 * @return la direccion en memoria de this
 */
Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* tipoPasajeroStr,char* apellidoStr,char* statusFlight,char* precioStr,char* codigoVuelo);//LE AGREGUE apellidoStr y STATUSFKIGHT

/**
 * @fn void Passenger_delete(Passenger*)
 * @brief LO QUE HACE ES ELIMINAR A UN PASAJERO DE LA LISTA CON FREE();
 *
 * @param this
 */
void Passenger_delete(Passenger* this);

/**
 * @fn int Passenger_setId(Passenger*, int)
 * @brief SETTER DE LA ID
 *
 * @param this
 * @param id
 * @return
 */
int Passenger_setId(Passenger* this,int id);

/**
 * @fn int Passenger_getId(Passenger*, int*)
 * @brief  OBTIENE UNA ID
 *
 * @param this
 * @param id
 * @return
 */
int Passenger_getId(Passenger* this,int* id);

/**
 * @fn int Passenger_getHigherID(Passenger*, int*)
 * @brief OBTIENE LA ID MAXIMA DE LA LISTA
 *
 * @param this
 * @param id
 * @return
 */
int Passenger_getHigherId(Passenger* this,int* id);

/**
 * @fn int Passenger_setNombre(Passenger*, char*)
 * @brief SETTEAR NOMBRE
 *
 * @param this
 * @param nombre
 * @return
 */
int Passenger_setNombre(Passenger* this,char* nombre);

/**
 * @fn int Passenger_getNombre(Passenger*, char*)
 * @brief OBTIENE UN NOMBRE
 *
 * @param this
 * @param nombre
 * @return
 */
int Passenger_getNombre(Passenger* this,char* nombre);

/**
 * @fn int Passenger_setApellido(Passenger*, char*)
 * @brief SETTEAR APELLIDO
 *
 * @param this
 * @param apellido
 * @return
 */
int Passenger_setApellido(Passenger* this,char* apellido);

/**
 * @fn int Passenger_getApellido(Passenger*, char*)
 * @brief OBTIENE UN APELLIDO
 *
 * @param this
 * @param apellido
 * @return
 */
int Passenger_getApellido(Passenger* this,char* apellido);

/**
 * @fn int Passenger_setCodigoVuelo(Passenger*, char*)
 * @brief SETTEAS CODIGO DE VUELO
 *
 * @param this
 * @param codigoVuelo
 * @return
 */
int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);
/**
 * @fn int Passenger_getCodigoVuelo(Passenger*, char*)
 * @brief OBTIENE CODIGO DE VUELO
 *
 * @param this
 * @param codigoVuelo
 * @return
 */
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);

/**
 * @fn int Passenger_setTipoPasajero(Passenger*, int)
 * @brief SETTEAR TIPO DE PASAJERO
 *
 * @param this
 * @param tipoPasajero
 * @return
 */
int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero);

/**
 * @fn int Passenger_getTipoPasajero(Passenger*, int*)
 * @brief OBTIENE EL TIPO DE PASAJERO
 *
 * @param this
 * @param tipoPasajero
 * @return
 */
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero);

/**
 * @fn int Passenger_getDescripcionTipoPasajero(int, char*)
 * @brief CARGA LA DESCRIPCION CORRESPONDIENTE AL TIPO DE PASAJERO
 *
 * @param typePassenger
 * @param desc
 * @return
 */
int Passenger_getDescripcionTipoPasajero(int typePassenger,char* desc);

/**
 * @fn int Passenger_setPrecio(Passenger*, float)
 * @brief SETTEAR PRECIO
 *
 * @param this
 * @param precio
 * @return
 */
int Passenger_setPrecio(Passenger* this,float precio);

/**
 * @fn int Passenger_getPrecio(Passenger*, float*)
 * @brief OBTIENE EL PRECIO
 *
 * @param this
 * @param precio
 * @return
 */
int Passenger_getPrecio(Passenger* this,float* precio);

/**
 * @fn int Passenger_setStatusFlight(Passenger*, int)
 * @brief SETTEA EL ESTADO DE VUELO
 *
 * @param this
 * @param statusFlight
 * @return
 */
int Passenger_setStatusFlight(Passenger* this,int statusFlight);

/**
 * @fn int Passenger_getStatusFlight(Passenger*, int*)
 * @brief OBTIENE EL ESTADO DE VUELO
 *
 * @param this
 * @param statusFlight
 * @return
 */
int Passenger_getStatusFlight(Passenger* this,int* statusFlight);

/**
 * @fn int Passenger_getDescripcionStatusFlight(int, char*)
 * @brief CARGA LA DESCRIPCION CORRESPONDIENTE AL ESTADO DE VUELO
 *
 * @param statusFlight
 * @param desc
 * @return
 */
int Passenger_getDescripcionStatusFlight(int statusFlight,char* desc);
/**
 * @fn int Passenger_getAll(Passenger*, char*, char*, float*, char*, int*, int*, int*)
 * @brief JUNTA TODOS LOS GETTERS EN UNA UNICA FUNCION
 *
 * @param this Passenger*
 * @param name char*
 * @param lastname char*
 * @param price float*
 * @param flightCode char*
 * @param type int*
 * @param status int*
 * @param id int*
 * @return int 0 todoOk, 1 algo salio mal
 */
int Passenger_getAll(Passenger* this,char* name,char* lastname,float* price,char* flightCode,int* type,int* status,int* id);


/**
 * @fn int Passenger_searchForId(LinkedList*, int)
 * @brief BUSCAMOS A UN PASAJERO MEDIANTE SU ID, UN ELEMENTO DE LA LISTA LINKEDLIST
 *
 * @param pArrayListPassengers LinkedList*
 * @param id int
 * @return si encontro retorna la posicion, si no -1
 */
int Passenger_searchForId(LinkedList* pArrayListPassengers, int id);

/**
 * @fn int Passenger_ShowOnlyOne(Passenger*)
 * @brief IMPRIME A UN UNICO PASAJERO DE LA LISTA
 *
 * @param Passenger
 * @return 1 si todoOk, 0 si error
 */
int Passenger_ShowOnlyOne(Passenger *Passenger);

/**
 * @fn int Passenger_sortByName(void*, void*)
 * @brief ORDENA LA LISTA DE PASAJEROS DE FORMA ASCENDENTE POR NOMBRES
 *
 * @param name1 void*
 * @param name2 void*
 * @return 0 si no pudo, 1 si pudo, -1 si es menor
 */
int Passenger_sortByName(void* name1,void* name2);

/**
 * @fn int Passenger_sortByLastName(void*, void*)
 * @brief ORDENA LA LISTA DE PASAJEROS DE FORMA ASCENDENTE POR APELLIDOS
 *
 * @param lastName1 void*
 * @param lastName2 void*
 * @return  0 si no pudo, 1 si pudo, -1 si es menor
 */
int Passenger_sortByLastName(void* lastName1,void* lastName2);

/**
 * @fn int Passenger_sortByCodeFlight(void*, void*)
 * @brief ORDENA LA LISTA DE PASAJEROS DE FORMA ASCENDENTE POR CODIGO DE VUELO
 *
 * @param flightCode1 void*
 * @param flightCode2 void*
 * @return  0 si no pudo, 1 si pudo, -1 si es menor
 */
int Passenger_sortByCodeFlight(void* flightCode1,void* flightCode2);

/**
 * @fn int Passenger_sortByPrice(void*, void*)
 * @brief ORDENA LA LISTA DE PASAJEROS DE FORMA ASCENDENTE POR PRECIO
 *
 * @param price1 void*
 * @param price2 void*
 * @return  0 si no pudo, 1 si pudo, -1 si es menor
 */
int Passenger_sortByPrice(void* price1,void* price2);

/**
 * @fn int Passenger_sortByTypePassenger(void*, void*)
 * @brief ORDENA LA LISTA DE PASAJEROS DE FORMA ASCENDENTE PO TIPO DE PASAJERO
 *
 * @param type1 void*
 * @param type2 void*
 * @return  0 si no pudo, 1 si pudo, -1 si es menor
 */
int Passenger_sortByTypePassenger(void* type1,void* type2);

/**
 * @fn int Passenger_sortByStatusFlight(void*, void*)
 * @brief ORDENA LA LISTA DE PASAJEROS DE FORMA ASCENDENTE POR ESTADO DE VUELO
 *
 * @param status1 void*
 * @param status2 void*
 * @return  0 si no pudo, 1 si pudo, -1 si es menor
 */
int Passenger_sortByStatusFlight(void* status1,void* status2);

#endif /* PASSENGER_H_ */
