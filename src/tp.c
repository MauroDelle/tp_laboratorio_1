/*
 * tp.c
 *
 *  Created on: 3 abr. 2022
 *      Author: delle
 */
#include <stdio.h>
#include <stdlib.h>
#include "tp.h"

#define hardCodeKilometros 7090
#define hardCodeAerolineas 162965
#define hardCodeLatam 159339
#define BITCOIN 4606954.55


int menu(void){

	int ingreso;

	system("cls");
	printf("*****Menu de Opciones*****\n\n");
	printf("1. Ingresar Kilómetros: ( km=x)\n");
	printf("2.Ingresar Precio de Vuelos: (Aerolíneas=y, Latam=z)\n");
	printf("3. Calcular todos los costos:\n");
	printf("4. Informar Resultados\n");
	printf("5. Carga forzada de datos\n");
	printf("6. Salir\n");
	printf("Ingrese una opcion:\n");
	system("cls");

	scanf("%d", &ingreso);


	return ingreso;
}




float kilometrosIngresados()
{
	float km;


	printf("Ingrese los kilometros recorridos:\n");
	scanf("%f", &km);

	while(km < 1)
	{
		printf("Error.Ingrese los kilometros recorridos:\n");
		scanf("%f", &km);
	}

	return km;

}



float ingresoPrecio(float *aerolineas, float *latam)
{
	float retorno;
	float x;
	float y;

	retorno = 0;

	if(aerolineas != NULL && latam != NULL){

	printf("Ingrese el precio de Aerolineas\n\n");
	scanf("%f", &x);

	printf("Ingrese el precio de Latam:\n\n");
	scanf("%f", &y);
	printf("El precio de aerolineas es: %f\n Y el precio de Latam es: %f\n\n", x, y);

	*aerolineas= x;
	*latam = y;

	retorno = 1;

	}


	return retorno;
}


void menuResultados(float diferenciaDePrecio, float aerolineas, float latam, float kilometros, float precioUnitarioAero,float interesCreditoLatam, float porcentajeDebitoAerolineas, float porcentajeDebitoLatam, float interesCreditoAerolineas, float precioLatamBTC, float precioAerolineasBTC, float precioUnitarioLatam)
{
	system("cls");
	printf("***Informe de Resultados***\n\n");

	printf("Latam: %.7f\n", latam);
	printf("a) Precio con tarjeta de débito: %.7f\n", porcentajeDebitoLatam);
	printf("b) Precio con tarjeta de crédito: %.7f\n", interesCreditoLatam);
	printf("c) Precio pagando con bitcoin : %.7f\n", precioLatamBTC);
	printf("d) Precio unitario: %.7f\n\n", precioUnitarioLatam);

	printf("Aerolineas: %.7f\n", aerolineas);
	printf("a) Precio con tarjeta de débito: %.7f\n", porcentajeDebitoAerolineas );
	printf("b) Precio con tarjeta de crédito: %.7f\n", interesCreditoAerolineas);
	printf("c) Precio pagando con bitcoin : %.7f\n", precioAerolineasBTC);
	printf("d) Precio unitario: %.7f\n", precioUnitarioAero);

	printf("La diferencia de precio es : %.7f\n", diferenciaDePrecio);
	system("cls");

}



float descuentoDebito(float precioBrutoVuelos)
{
	float descuento = 0;
	float total = 0;

	descuento = (float)((precioBrutoVuelos * 10) / 100);

	total = precioBrutoVuelos - descuento;

	return total;
}


float interesCredito(float interesVuelos)
{
	float precioVuelos;
	float interes;

	precioVuelos = interesVuelos;

	interes = (float) ((precioVuelos * 25) / 100);

	precioVuelos += interes;


	return precioVuelos;
}


float precioBTC(float precioBitcoin)
{
	float precioFinal;

	precioFinal = (precioBitcoin / BITCOIN);


	return precioFinal;
}


float precioUnitarioViajes(float avion, float kilometros)
{
	float precioA;

		precioA = avion / kilometros;


	return precioA;
}


float diferenciaPrecio(float aerolineas, float latam)
{
	float resta;

	resta = aerolineas - latam;

	return resta;
}


void cargaforzada()
{
	float diferenciaPrecioHardCode;

	float precioUnitarioHardCodeA;
	float precioUnitarioHardCodeL;

	float hardCodeBTCLatam;
	float hardCodeBTCAerolineas;

	float hardCodeInteresAerolineas;
	float hardCodeInteresLatam;

	float descuentoDebitoHardCodeA;
	float descuentoDebitoHardCodeL;



	diferenciaPrecioHardCode = diferenciaPrecio(hardCodeAerolineas, hardCodeLatam);

	precioUnitarioHardCodeA = precioUnitarioViajes(hardCodeAerolineas, hardCodeKilometros);
	precioUnitarioHardCodeL = precioUnitarioViajes(hardCodeLatam, hardCodeKilometros);

	hardCodeBTCLatam = precioBTC (hardCodeAerolineas);
	hardCodeBTCAerolineas = precioBTC (hardCodeLatam);

	hardCodeInteresAerolineas = interesCredito(hardCodeAerolineas);
	hardCodeInteresLatam = interesCredito(hardCodeLatam);

	descuentoDebitoHardCodeA = descuentoDebito (hardCodeAerolineas);
	descuentoDebitoHardCodeL = descuentoDebito (hardCodeLatam);


	printf("\n--------------------------------------\n");

	printf("\n\n--***Carga Forzada de datos***--\n\n");

	printf("Kilometros Ingresados : 7090 km\n\n");

	printf("Latam: $159339\n");
	printf("a) Precio con tarjeta de débito: %.7f\n", descuentoDebitoHardCodeL);
	printf("b) Precio con tarjeta de crédito: %.7f\n", hardCodeInteresLatam);
	printf("c) Precio pagando con bitcoin : %.7f\n", hardCodeBTCLatam);
	printf("d) Precio unitario: %.7f\n", precioUnitarioHardCodeL);

	printf("\n--------------------------------------\n");

	printf("Aerolineas: $162965\n");
	printf("a) Precio con tarjeta de débito: %.7f\n", descuentoDebitoHardCodeA);
	printf("b) Precio con tarjeta de crédito: %.7f\n", hardCodeInteresAerolineas);
	printf("c) Precio pagando con bitcoin : %.7f\n", hardCodeBTCAerolineas);
	printf("d) Precio unitario: %.7f\n\n", precioUnitarioHardCodeA);

	printf("La diferencia de precio es: %.7f\n", diferenciaPrecioHardCode);

	printf("\n--------------------------------------\n");

}








