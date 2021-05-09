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

void InicializarEstructura(eTrabajo trabajo[], int extensionTrabajo)
{
	int i;
	for(i = 0; i < extensionTrabajo; i++)
	{
		trabajo[i].estado = VACIO;
		trabajo[i].id = 0;
	}
}


void HardcodearTrabajo(eTrabajo trabajo[],int extensionTrabajo)
{
	int cantidadDeProductosHardcodeados = 7;
	int i; //estado, id, nombreMascota, idServicio, Fecha
	int estado[]={LLENO,LLENO,LLENO,LLENO,LLENO,LLENO,LLENO,};
	int id[]={45,47,48,43,41,38,50};
	char nombreMascota[][25]={"Roco","Tobi","Coco","Yago","Blanca","Pato","Pancho"};
	int idServicio[]={DESPARASITADO, CORTE,CASTRADO,CASTRADO,CORTE,DESPARASITADO,CASTRADO};

	int dia[] = {4,23,15,16,20,12,6};
	int mes[] = {3,4,2,5,2,6,8};
	int anio[] = {2023,2022,2021,2021,2022,2023,2024};

	for(i=0;i<cantidadDeProductosHardcodeados;i++)
	{
		trabajo[i].estado=estado[i];

		trabajo[i].id = id[i];
		strcpy(trabajo[i].nombreMascota,nombreMascota[i]);
		trabajo[i].idServicio = idServicio[i];

		trabajo[i].fecha.anio = anio[i];
		trabajo[i].fecha.mes = mes[i];
		trabajo[i].fecha.dia = dia[i];
	}
}


int BuscarLibreTrabajo(eTrabajo trabajo[],int extensionTrabajo)
 {
	int i;
	int indice;
	indice = LLENO;

	for (i = 0; i < extensionTrabajo; i++)
	{
		if (trabajo[i].estado == VACIO)
		{
			indice = i;
			break;
		}
	}
	return indice;
 }

int BuscarVacio(eTrabajo trabajo[],int extensionTrabajo)
 {
	int i;
	int banderaVacio;
	banderaVacio = TRUE;

	for (i = 0; i < extensionTrabajo; i++)
	{
		if (trabajo[i].estado == LLENO)
		{
			banderaVacio = FALSE;
			break;
		}
	}
	return banderaVacio;
 }


eTrabajo CargarDatosDeTrabajo(eTrabajo trabajo[], int extensionTrabajo, eServicio servicio[], int extensionServicio)
 {
    eTrabajo TrabajoAuxiliar;

    int indiceServicio;

    TrabajoAuxiliar.id = getIdTrabajo(trabajo, extensionTrabajo);

    getString("Ingrese nombre de la mascota: ", TrabajoAuxiliar.nombreMascota);

    indiceServicio = BuscarIdServicio(servicio, extensionServicio);
    TrabajoAuxiliar.idServicio = servicio[indiceServicio].idServicio;

    TrabajoAuxiliar.fecha.dia = getInt("Ingrese día: ", "Error, intente nuevamente", 1, 31, TRUE );
    TrabajoAuxiliar.fecha.mes = getInt("Ingrese mes: ", "Error, intente nuevamente", 1, 12, TRUE );
    TrabajoAuxiliar.fecha.anio = getInt("Ingrese año: ", "Error, intente nuevamente", 2021, 2025, TRUE );

    TrabajoAuxiliar.estado = LLENO;

    return TrabajoAuxiliar;
 }


void Alta(eTrabajo trabajo[], int extensionTrabajo, int indice, eServicio servicio[], int extensionServicio)
 {

	switch (trabajo[indice].estado)
	{
		case LLENO:
			printf("No hay lugar disponible para cargar nuevos trabajos.\n\n");
			break;
		case VACIO:
			trabajo[indice] = CargarDatosDeTrabajo(trabajo, extensionTrabajo, servicio, extensionServicio);
		break;
	}
 }



void MostrarUnTrabajo(eTrabajo trabajo, int anchoDeCadenas, eServicio servicio[], int extensionServicio)
{
	int indiceServicio;

	if(trabajo.estado == LLENO)
	{
		indiceServicio = BuscarServicioDeTrabajo(trabajo, servicio, extensionServicio);

		printf("|%d| ", trabajo.id);
		printf("|%*s| ", anchoDeCadenas, trabajo.nombreMascota);
		printf("|%d. ", trabajo.idServicio);
		printf("%-13s - ", servicio[indiceServicio].descripcionServicio);
		printf("$%.2f| ", servicio[indiceServicio].precio);
		printf("|%-2d - %-2d - %d| \n", trabajo.fecha.dia, trabajo.fecha.mes, trabajo.fecha.anio);
	}
}

void MostrarTodosLosTrabajos(eTrabajo trabajo[], int extensionTrabajo, eServicio servicio[], int extensionServicio)
{
	int i;
	int anchoDeCadenas;

	anchoDeCadenas = AnchoDeCadenas(trabajo, extensionTrabajo) * -1;

	for (i = 0; i < extensionTrabajo; i++)
	{
		MostrarUnTrabajo(trabajo[i], anchoDeCadenas, servicio, extensionServicio);
	}

	printf("\n\n");
}

int AnchoDeCadenas(eTrabajo trabajo[], int extensionTrabajo)
{
	int anchoMaximo;
	int anchoActual;
	int i;

	for (i = 0; i < extensionTrabajo; i++)
	{
		anchoActual = strlen(trabajo[i].nombreMascota);

		if (anchoActual > anchoMaximo || i == 0)
		{
			anchoMaximo = anchoActual;
		}
	}
	return anchoMaximo;
}


int BuscarTrabajo(eTrabajo trabajo[], int extensionTrabajo, eServicio servicio[], int extensionServicio)
{
	int i;
	int idIngresado;
	int trabajoEncontrado;

	LimpiarConsola();
	do
	{
		MostrarTodosLosTrabajos(trabajo, extensionTrabajo, servicio, extensionServicio);

		idIngresado = getInt("Ingrese ID del trabajo: ", "", FALSE, FALSE, FALSE);

		for (i = 0; i < extensionTrabajo; i++)
		{
			if (idIngresado == trabajo[i].id && trabajo[i].estado == LLENO)
			{
				trabajoEncontrado = i;
				break;
			}
			else
			{
				trabajoEncontrado = -1;
			}
		}
		ValidarIndice(trabajoEncontrado);
	} while (trabajoEncontrado == -1);

	return trabajoEncontrado;
}


int ModificarNombreDeMascotaTrabajo(eTrabajo trabajo[], int indice)
{
	char respuestaIngresada;
	char auxiliarNombre[25];

	LimpiarConsola();
	getString("Ingrese el nombre nuevo: ", auxiliarNombre);

	printf("El nombre de mascota (trabajo ID: %d) pasará a ser: %s \n\n", trabajo[indice].id, auxiliarNombre);

	respuestaIngresada = getChar("¿Desea confirmar este cambio? (s/n): ", "Error, intente nuevamente", 's', 'n', TRUE);
	if(respuestaIngresada == 's')
	{
		strcpy(trabajo[indice].nombreMascota, auxiliarNombre);
	}
	LimpiarConsola();
	return 1;
}

int ModificarServicioDeTrabajo(eTrabajo trabajo[], int indice, eServicio servicio[], int extensionServicio)
{
	char respuestaIngresada;
	int indiceServicioNuevo;
	
	LimpiarConsola();
	indiceServicioNuevo = BuscarIdServicio(servicio, extensionServicio);
	
	printf("El servicio del trabajo de ID %d pasará a ser: %s. \n\n", trabajo[indice].id, servicio[indiceServicioNuevo].descripcionServicio);
	respuestaIngresada = getChar("¿Desea confirmar este cambio? (s/n): ", "Error, intente nuevamente", 's', 'n', TRUE);
	if(respuestaIngresada == 's')
	{
		trabajo[indice].idServicio = servicio[indiceServicioNuevo].idServicio;
	}
	LimpiarConsola();
	return 1;
}



void EliminarTrabajo(eTrabajo trabajo[], int indice, eServicio servicio[], int extensionServicio)
{
	char confirmacion;
	int anchoDeCadena;

	anchoDeCadena = AnchoDeCadenas(trabajo, 1);
	MostrarUnTrabajo(trabajo[indice], anchoDeCadena, servicio, extensionServicio);

	__fpurge(stdin);
	printf("¿Está seguro de que desea eliminar este trabajo? (s/n): ");
	scanf("%c", &confirmacion);

	if(confirmacion == 's')
	{
		trabajo[indice].estado = VACIO;
		printf("\nTrabajo eliminado\n");
	}
	else
	{
		printf("\nEliminación cancelada\n");
	}
}


void OrdenamientoPorAnioYNombreMascota(eTrabajo trabajo[], int extensionTrabajo)
{
    int i;
    int j;
	int flagAniosDistintos;

    for (i = 0; i < extensionTrabajo - 1; i++)
	{
		for (j = i+1; j < extensionTrabajo; j++)
		{
            flagAniosDistintos = ComparacionPorAnio(trabajo, i, j);
			if (flagAniosDistintos == FALSE)
			{
				ComparacionPorNombreMascota(trabajo, i, j);
			}
		}
	}
}

int ComparacionPorAnio(eTrabajo trabajo[], int indice1, int indice2)
{
	eTrabajo auxiliar;
	int flagCondicionCumplida = TRUE;

	if (trabajo[indice1].fecha.anio > trabajo[indice2].fecha.anio)
	{
		auxiliar = trabajo[indice1];
		trabajo[indice1] = trabajo[indice2];
		trabajo[indice2] = auxiliar;
		flagCondicionCumplida = TRUE;
	}
	else
	{
		if (trabajo[indice1].fecha.anio == trabajo[indice2].fecha.anio)
		{
			flagCondicionCumplida = FALSE;
		}
	}
	
	return flagCondicionCumplida;
}

int ComparacionPorNombreMascota(eTrabajo trabajo[], int indice1, int indice2)
{
	eTrabajo auxiliar;
	int flagCondicionCumplida = FALSE;

	char cadena1[25];
    char cadena2[25];
    char resultadoDeLaComparacionDeCadenas;

	strcpy(cadena1, trabajo[indice1].nombreMascota);
	strcpy(cadena2, trabajo[indice2].nombreMascota);

	resultadoDeLaComparacionDeCadenas = strcmp(cadena1, cadena2);

	if (resultadoDeLaComparacionDeCadenas > TRUE)
	{
		auxiliar = trabajo[indice1];
		trabajo[indice1] = trabajo[indice2];
		trabajo[indice2] = auxiliar;
		flagCondicionCumplida = 1;
	}
	return flagCondicionCumplida;
}


int TotalEnPesosPorlosServiciosPrestados(eTrabajo trabajo[], int extensionTrabajo, eServicio servicio[], int extensionServicio)
{
	int indiceServicio;
	int totalEnPesosPorlosServiciosPrestados = 0;

	for (int i = 0; i < extensionTrabajo; i++)
	{
		if (trabajo[i].estado == LLENO)
		{
			indiceServicio = BuscarServicioDeTrabajo(trabajo[i], servicio, extensionServicio);
			if (indiceServicio > -1)
			{
				totalEnPesosPorlosServiciosPrestados += servicio[indiceServicio].precio;
			}
		}
	}
	return totalEnPesosPorlosServiciosPrestados;	
}
