/*
 ============================================================================
 Name        : 1Parcial_Cordoba.c
 Author      : Pablo Córdoba
 Version     :
 Copyright   : Prohibida la venta y distribución de este código dentro de los límites de la República Argentina
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>

#include "estructuras&define.h"
#include "Fecha.h"
#include "Servicios.h"
#include "Trabajo.h"
#include "terminalFunctions.h"
#include "getFunctions.h"
#include "Menu.h"

int main(void) {

	eTrabajo trabajo[X];
	eServicio servicio[CANT_SERVICIO];

	int indice;
	int banderaVacio;
	int totalEnPesosPorLosServiciosPrestados;
	int opcion;

	InicializarEstructura(trabajo, X);

	HardcodearServicio(servicio, CANT_SERVICIO);
	HardcodearTrabajo(trabajo, X);
	

	do
	{
		opcion = MenuPrincipal();

		switch (opcion)
		{
			case 1:
				//ALTA
				LimpiarConsola();
				indice = BuscarLibreTrabajo(trabajo, X);
				Alta(trabajo, X, indice, servicio, CANT_SERVICIO);
				break;
			case 2:
				//MODIFICAR
				LimpiarConsola();
				banderaVacio = BuscarVacio(trabajo, X);
				if(banderaVacio == FALSE)
				{
					opcion = MenuModificarTrabajo();
					SwitchModificarTrabajo(opcion, trabajo, X, servicio, CANT_SERVICIO);
				}
				else
				{
					printf("No hay elementos para modificar. \n\n");
				}
				
				break;
			case 3:
				//BAJA
				LimpiarConsola();
				banderaVacio = BuscarVacio(trabajo, X);
				if(banderaVacio == FALSE)
				{
					indice = BuscarTrabajo(trabajo, X, servicio, CANT_SERVICIO);
					EliminarTrabajo(trabajo, indice, servicio, CANT_SERVICIO);
				}
				else
				{
					printf("No hay elementos para eliminar. \n\n");
				}
				break;
			case 4:
				//LISTADO TRABAJOS
				LimpiarConsola();
				banderaVacio = BuscarVacio(trabajo, X);
				if(banderaVacio == FALSE)
				{
					OrdenamientoPorAnioYNombreMascota(trabajo, X);
					MostrarTodosLosTrabajos(trabajo, X, servicio, CANT_SERVICIO);
				}
				else
				{
					printf("No hay elementos para mostrar. \n\n");
				}
				break;
			case 5:
				//LISTADO SERVICIOS
				LimpiarConsola();
				MostrarServicios(servicio, CANT_SERVICIO);
				break;
			case 6:
				//LISTADO SERVICIOS
				LimpiarConsola();
				totalEnPesosPorLosServiciosPrestados = TotalEnPesosPorlosServiciosPrestados(trabajo, X, servicio, CANT_SERVICIO);

				printf("Total por los servicios prestados: $%d \n\n", totalEnPesosPorLosServiciosPrestados);

			break;
		}
	} while(opcion != 7);

	return 1;
}
