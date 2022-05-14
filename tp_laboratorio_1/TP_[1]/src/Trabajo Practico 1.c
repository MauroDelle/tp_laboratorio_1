/*
 ============================================================================
 Name        : Trabajo.c
 Author      : Mauro Delle
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "tp.h"


int main(void) {

	setbuf(stdout,NULL);

	int opcion;

	float kilometros;
	float aerolineas;
	float latam;

	// a) Tarjeta de débito (descuento 10%)
	float porcentajeDebitoAerolineas;
	float porcentajeDebitoLatam;

	//b) Tarjeta de crédito (interés 25%)
	float interesCreditoAerolineas;
	float interesCreditoLatam;

	//c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)
	float precioLatamBTC;
	float precioAerolineasBTC;

	//d) Mostrar precio por km (precio unitario)
	float precioUnitarioAero;
	float precioUnitarioLatam;

	//e) Mostrar diferencia de precio ingresada (Latam - Aerolíneas)
	float diferenciaDePrecio;

	//Para que no se pueda ejecutar nada sin haber ingresado datos previamente.
	int flagIngresoOpcion1;
	int flagIngresoOpcion2;
	int flagIngresoOpcion3;

	flagIngresoOpcion1 = 0;
	flagIngresoOpcion2 = 0;
	flagIngresoOpcion3 = 0;




	do{

		opcion = menu();

		switch(opcion)
		{

		case 1:
			kilometros = kilometrosIngresados();
			flagIngresoOpcion1 = 1;
			break;
		case 2:
			if(flagIngresoOpcion1 == 0)
			{
				printf("No puede ingresar el precio sin haber ingresado kilometros\n\n");
			}
			else{
				ingresoPrecio(&aerolineas, &latam);
				flagIngresoOpcion2 = 1;
			}

			break;
		case 3:
			if(flagIngresoOpcion2 == 0)
			{
				printf("3-No se pueden calcular los costos si no se ingreso ningun dato\n\n");
			}
			else
			{
				precioUnitarioAero = precioUnitarioViajes(aerolineas, kilometros);
				precioUnitarioLatam = precioUnitarioViajes(latam, kilometros);
				diferenciaDePrecio = diferenciaPrecio(aerolineas, latam);


				precioAerolineasBTC = precioBTC(aerolineas);
				porcentajeDebitoAerolineas = descuentoDebito(aerolineas);
				interesCreditoAerolineas = interesCredito(aerolineas);


				porcentajeDebitoLatam = descuentoDebito(latam);
				interesCreditoLatam = interesCredito(latam);
				precioLatamBTC = precioBTC(latam);

				flagIngresoOpcion3 = 1;
			}
			break;
		case 4:

			if(flagIngresoOpcion3 == 0)
			{
				printf("No se pueden mostrar resultados que todavia no fueron ingresados.\n\n");

			}
			else{

			menuResultados(diferenciaDePrecio, aerolineas, latam, kilometros, precioUnitarioAero, interesCreditoLatam,  porcentajeDebitoAerolineas,  porcentajeDebitoLatam,  interesCreditoAerolineas,  precioLatamBTC,  precioAerolineasBTC,  precioUnitarioLatam);
			}
			break;
		case 5:
		cargaforzada();

			break;
		case 6:
			printf("Adios\n");
			break;

		default:
			printf("\nIngrese una opcion valida\n");
		}

		system("pause");

	}while(opcion != 6);




	return 0;
}







