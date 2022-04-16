/*
 * tp.h
 *
 *  Created on: 3 abr. 2022
 *      Author: delle
 */

#ifndef TP_H_
#define TP_H_

/// @fn int menu(void)
/// @brief Es el menu principal el cual contiene las opciones que se pueden seleccionar.
///
/// @pre
/// @post
/// @return devuelve la opcion ingresada desde el 1 al 6.
int menu();

/**
 * @fn float kilometrosIngresados()
 * @brief recibe y guarda los kilometros ingresados por el usuario.
 *
 * @return No retorno nada al usuario. solamente almacena los kilometros ingresados.
 */
float kilometrosIngresados();

/// @fn float ingresoPrecio(float*, float*)
/// @brief Recibe el precio de las aerolineas ingresadas por el usuario.
///
/// @param aerolineas Es para guardar el precio de aerolineas.
/// @param latam Es para guardar el precio de Latam.
///
/// @return Almacena el precio de sus respectivas variable.
float ingresoPrecio(float *aerolineas, float *latam);

/// @fn float descuentoDebito(float)
/// @brief Aplica un 10% de descuento a las variables Aerolineas y Latam.
///
/// @param precioBrutoVuelos Recibe el valor de Aeorlineas o Latam y aplica el descuento.
/// @return Devuelve el valor ingresado inicialmente con un descuento del 10% aplicado.
///
float descuentoDebito(float precioBrutoVuelos);

/// @fn float interesCredito(float)
/// @brief Aplica un interes del 25% sobre el monto ingresado de Aerolineas o Latam.
///
/// @param interesVuelos Recibe el monto de Aerolineas o Latam.
/// @return Devuelve el precio inicialmente ingresado con un interes del 25% (+)
float interesCredito(float interesVuelos);

/// @fn float precioBTC(float)
/// @brief Calcula el precio en BTC del monto ingresado, ya se Latam o aerolineas.
///
/// @param precioBitcoin Recibe el monto ingresado por el usuario y calcula el precio.
/// @return Retorna el monto final en bitcoin.
///
float precioBTC(float precioBitcoin);

/// @fn float precioUnitarioViajes(float, float)
/// @brief Calcula el precio por kilometros.
///
/// @param avion Recibe el valor de Aerolineas o Latam.
/// @param kilometros Recibe los kilometros ingresados anteriormente.
/// @return Devuelve el precio por kilometro, ya sea Aerolineas o Latam.
///
float precioUnitarioViajes(float avion, float kilometros);

/// @fn float diferenciaPrecio(float, float)
/// @brief calcula la diferencia de precio entre un vuelo y otro.
///
/// @param aerolineas Recibe el valor ingresado de Aerolineas.
/// @param latam Recibe el valor ingresado de latam.
/// @return Devuelve la diferencia de precio entre un vuelo y otro
///
float diferenciaPrecio(float aerolineas, float latam);

/// @fn void menuResultados(float, float, float, float, float, float, float, float, float, float, float, float)
/// @brief Es el menu del case 5 en el cual se muestran todos los resultados.
///
///
///
///	Variables para poder llamar a sus respectivas funciones y pasarle los valores necesarios como para realizar las operaciones anteriormente explicadas.
///
/// @param diferenciaDePrecio
/// @param aerolineas
/// @param latam
/// @param kilometros
/// @param precioUnitarioAero
/// @param interesCreditoLatam
/// @param porcentajeDebitoAerolineas
/// @param porcentajeDebitoLatam
/// @param interesCreditoAerolineas
/// @param precioLatamBTC
/// @param precioAerolineasBTC
/// @param precioUnitarioLatam
void menuResultados(float diferenciaDePrecio, float aerolineas, float latam, float kilometros, float precioUnitarioAero,float interesCreditoLatam, float porcentajeDebitoAerolineas, float porcentajeDebitoLatam, float interesCreditoAerolineas, float precioLatamBTC, float precioAerolineasBTC, float precioUnitarioLatam);

/// @fn void cargaforzada(void)
/// @brief Realiza el calculo sobre los montos hardcodeados de Aerolineas, latam y los kilometros.
void cargaforzada(void);

#endif /* TP_H_ */

