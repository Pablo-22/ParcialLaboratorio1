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

void HardcodearServicio(eServicio servicio[], int extensionServicio)
{
	int i;

	int estado[CANT_SERVICIO] = {LLENO, LLENO, LLENO};
	int idServicio[CANT_SERVICIO]={CORTE,DESPARASITADO,CASTRADO};
	char descripcionServicio[CANT_SERVICIO][14]={"Corte","Desparasitado","Castrado"};
    float precioServicio[CANT_SERVICIO] = {250, 300, 400};

	for (i = 0; i < extensionServicio; i++)
	{
		servicio[i].estado = estado[i];
		servicio[i].idServicio=idServicio[i];
		strcpy(servicio[i].descripcionServicio, descripcionServicio[i]);
        servicio[i].precio = precioServicio[i];
	}
}


void MostrarServicio(eServicio servicio)
{
	if (servicio.estado == LLENO)
	{
		printf("%d. %s - %.2f \n", servicio.idServicio, servicio.descripcionServicio, servicio.precio);
	}
}



void MostrarServicios(eServicio servicio[], int extensionServicio)
{
	int i;

	for (i = 0; i < extensionServicio; i++)
	{
		MostrarServicio(servicio[i]);
	}
	printf("\n");
}



int BuscarIdServicio(eServicio servicio[], int extensionServicio)
{
	int indice;
	int id;
	do
	{
		printf("ServicioS\n");
		MostrarServicios(servicio, extensionServicio);
		id = getInt("Ingrese id del servicio de producto: ", "Error, intente nuevamente", FALSE, FALSE, FALSE);
		for (int i = 0; i < extensionServicio; i++)
		{
			if (id == servicio[i].idServicio && servicio[i].estado == LLENO)
			{
				indice = i;
				break;
			}
			else
			{
				indice = -1;
			}
		}
		ValidarIndice(indice);
	} while (indice == -1);
	return indice;
}



int BuscarServicioDeTrabajo(eTrabajo trabajo, eServicio servicio[], int extensionServicio)
{
	int i;
	int indiceServicio;

	indiceServicio = -1;

	for (i = 0; i < extensionServicio; i++)
	{
		if(trabajo.idServicio == servicio[i].idServicio && servicio[i].estado == LLENO)
		{
			indiceServicio = i;
			break;
		}
	}
	return indiceServicio;
}

