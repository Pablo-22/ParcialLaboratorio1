

#ifndef TRABAJO_H_
#define TRABAJO_H_

typedef struct {
	int estado;
	int id;
	char nombreMascota[25];
	int idServicio;
	eFecha fecha;
}eTrabajo;

/**
 * @brief Inicialización de la estructura Trabajo. Coloca todos los trabajo.estado en VACIO (0).
 * 
 * @param trabajo array de la estructura trabajo
 * @param extensionProducto extensión de la estructura.
 */
void InicializarEstructura(eTrabajo trabajo[], int extensionProducto);

/**
 * @brief Busca un lugar libre en el array de la estructura de trabajos para guardar nuevos datos.
 * 
 * @param trabajo Array de estructura trabajo 
 * @param extensionTrabajo extensión del array
 * @return int devuelve el índice encontrado, o LLENO (-1) si no se encontró espacio libre
 */
int BuscarLibreTrabajo(eTrabajo trabajo[],int extensionTrabajo);

/**
 * @brief Similar a BuscarLibreTrabajo, pero esta función se fija si el vector de trabajo está completamente vacío,
 * 
 * @param trabajo Array de trabajo
 * @param extensionTrabajo Extensión de Array trabajo
 * @return int Devuelve TRUE (1) si está vacío o FALSE(0) si está lleno
 */
int BuscarVacio(eTrabajo trabajo[],int extensionTrabajo);

/**
 * @brief Carga los datos del trabajo nuevo en un eTrabajo auxiliar.
 * 
 * @param trabajo Array de trabajo. Se necesita para la función de getID
 * @param extensionTrabajo Extensión del array trabajo
 * @param servicio Array de servicio
 * @param extensionServicio Extensión del array servicio
 * @return eTrabajo Devuelve un eTrabajo con todos los datos ingresados.
 */
eTrabajo CargarDatosDeTrabajo(eTrabajo trabajo[], int extensionTrabajo, eServicio servicio[], int extensionServicio);

/**
 * @brief Llama a la función CargarDatosDeTrabajo, y si todo está correcto, integra el eTrabajo devuelto por esta, en el array de trabajo original,
 * 
 * @param trabajo Array de trabajo
 * @param extensionTrabajo Extensión de array trabajo
 * @param indice Indice del trabajo a modificar
 * @param servicio Array servicio
 * @param extensionServicio Extensión del array servicio.
 */
void Alta(eTrabajo trabajo[], int extensionTrabajo, int indice, eServicio servicio[], int extensionServicio);

/**
 * @brief Esta función es específicamente para modificar el nombre de una mascota en el array trabajo
 * 
 * @param trabajo array trabajo 
 * @param indice indice del trabajo a modificar
 * @return int devuelve 1 si todo está correcto
 */
int ModificarNombreDeMascotaTrabajo(eTrabajo trabajo[], int indice);

/**
 * @brief Esta función es específicamente para modificar el servicio de un trabajo en el array trabajo
 * 
 * @param trabajo array trabajo 
 * @param indice indice del trabajo a modificar
 * @param servicio Array servicio
 * @param extensionServicio Extensión del array servicio
 * @return int devuelve 1 si todo está correcto
 */
int ModificarServicioDeTrabajo(eTrabajo trabajo[], int indice, eServicio servicio[], int extensionServicio);

/**
 * @brief Muestra los trabajos, pide una id y busca esa id en el array de trabajo. Se valida en esta misma función.
 * 
 * @param trabajo Array trabajo
 * @param extensionTrabajo Extensión del array de trabajo
 * @param servicio Array servicio
 * @param extensionServicio Extensión del array servicio
 * @return int Devuelve el indice del trabajo encontrado en el array
 */
int BuscarTrabajo(eTrabajo trabajo[], int extensionTrabajo, eServicio servicio[], int extensionServicio);

/**
 * @brief Hardcodea los datos de trabajo
 * 
 * @param trabajo Array trabajo
 * @param extensionTrabajo Extensión del array trabajo
 */
void HardcodearTrabajo(eTrabajo trabajo[],int extensionTrabajo);

/**
 * @brief Elimina un trabajo por id
 * 
 * @param trabajo Array trabajo
 * @param indice Indice del trabajo a eliminar
 * @param servicio Array servicio
 * @param extensionServicio Extensión del array servicio
 */
void EliminarTrabajo(eTrabajo trabajo[], int indice, eServicio servicio[], int extensionServicio);

/**
 * @brief Busca el servicio de un trabajo, por el idServicio.
 * 
 * @param trabajo Array trabajo
 * @param servicio Array servicio
 * @param extensionServicio Extensión del array servicio
 * @return int Devuelve el índice del servicio encontrado en el array servicio
 */
int BuscarServicioDeTrabajo(eTrabajo trabajo, eServicio servicio[], int extensionServicio);

/**
 * @brief Muestra un trabajo
 * 
 * @param trabajo Array trabajo
 * @param anchoDeCadenas El ancho que tendrá la sección de nombreMascota, debido a que es la única sección con ancho variable. Se utiliza para mantener la alineación al mostrar
 * @param servicio Array servicio 
 * @param extensionServicio Extensión del array servicio
 */
void MostrarUnTrabajo(eTrabajo trabajo, int anchoDeCadenas, eServicio servicio[], int extensionServicio);

/**
 * @brief Llama repetidamente a la función MostrarUnTrabajo
 * 
 * @param trabajo Array trabajo
 * @param extensionTrabajo Extensión del array trabajo
 * @param servicio Array servicio
 * @param extensionServicio Extensión del array servicio
 */
void MostrarTodosLosTrabajos(eTrabajo trabajo[], int extensionTrabajo, eServicio servicio[], int extensionServicio);

/**
 * @brief Busca el ancho máximo que tendrá la sección de nombreMascota, debido a que es la única sección con ancho variable. Se utiliza para mantener la alineación al mostrar
 * 
 * @param trabajo array trabajo
 * @param extensionTrabajo Extensión del array trabajo
 * @return int Devuelve el máximo ancho de la cadena nombreMascota en el array de trabajo.
 */
int AnchoDeCadenas(eTrabajo trabajo[], int extensionTrabajo);

/**
 * @brief Burbujeo, realizando ordenamiento por año, y en caso de que dos años sean iguales, los ordena por nombre alfabéticamente.
 * 
 * @param trabajo Array trabajo
 * @param extensionTrabajo Extensión del array trabajo
 */
void OrdenamientoPorAnioYNombreMascota(eTrabajo trabajo[], int extensionTrabajo);

/**
 * @brief Comparación de dos años. Se utiliza para el ordenamiento.
 * 
 * @param trabajo Array trabajo
 * @param indice1 Indice del primer valor a comparar
 * @param indice2 Indice del segundo valor a comparar
 * @return int Devuelve TRUE (1) si se cumple la condición que contiene y FALSE (0) si no se cumple 
 */
int ComparacionPorAnio(eTrabajo trabajo[], int indice1, int indice2);

/**
 * @brief Comparación de dos nombres. Se utiliza para el ordenamiento.
 * 
 * @param trabajo Array trabajo
 * @param indice1 Indice del primer valor a comparar
 * @param indice2 Indice del segundo valor a comparar
 * @return int Devuelve TRUE (1) si se cumple la condición que contiene y FALSE (0) si no se cumple 
 */
int ComparacionPorNombreMascota(eTrabajo trabajo[], int indice1, int indice2);

/**
 * @brief Suma el precio de todos los trabajos realizados.
 * 
 * @param trabajo Array trabajo
 * @param extensionTrabajo Extensión del array trabajo
 * @param servicio Array servicio
 * @param extensionServicio Extensión del array servicio
 * @return int Devuelve el precio total de los trabajos realizados.
 */
int TotalEnPesosPorlosServiciosPrestados(eTrabajo trabajo[], int extensionTrabajo, eServicio servicio[], int extensionServicio);

#endif /* TRABAJO_H_ */
