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


int MenuPrincipal()
{
	int opcion;
	opcion = 0;

	printf("1. ALTA TRABAJO \n");
	printf("2. MODIFICAR TRABAJO \n");
	printf("3. BAJA TRABAJO \n");
	printf("4. LISTAR TRABAJOS \n");
	printf("5. LISTAR SERVICIOS \n");
	printf("6. TOTAL en pesos por los servicios prestados \n");
	printf("7. SALIR \n");

	opcion = getInt("\n Elija una opción: ", "Error, intente nuevamente", 1, 7, TRUE);

	return opcion;
}

int MenuModificarTrabajo()
{
	int opcion;
	opcion = 0;

	printf("1. Modificar NOMBRE de mascota \n");
	printf("2. Modificar SERVICIO \n");

	opcion = getInt("\n Elija una opción: ", "Error, intente nuevamente", 1, 2, TRUE);
	return opcion;
}

void SwitchModificarTrabajo(int opcion,eTrabajo trabajo[], int extensionTrabajo, eServicio servicio[], int extensionServicio)
{
	int indice;

	indice = BuscarTrabajo(trabajo, extensionTrabajo, servicio, extensionServicio);
	if(indice > -1)
	{
		switch (opcion)
		{
			case 1:
				ModificarNombreDeMascotaTrabajo(trabajo, indice);
				break;
			case 2:
				ModificarServicioDeTrabajo(trabajo, indice, servicio, extensionServicio);
			break;
		}
	}
}
