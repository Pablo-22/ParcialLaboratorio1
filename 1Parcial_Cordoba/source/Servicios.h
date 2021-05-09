#ifndef SERVICIOS_H_
#define SERVICIOS_H_

typedef struct
{
	int estado;
	int idServicio;
	char descripcionServicio[25];
	float precio;
}eServicio;

/**
 * @brief Hardcodea los datos del array servicio
 * 
 * @param servicio Array servicio
 * @param extensionServicio Extensión del array servicio
 */
void HardcodearServicio(eServicio servicio[], int extensionServicio);

/**
 * @brief Muestra un servicio
 * 
 * @param servicio Recibe un único servicio para mostrar
 */
void MostrarServicio(eServicio servicio);

/**
 * @brief Llama repetídamente a la función MostrarServicio
 * 
 * @param servicio Array servicio
 * @param extensionServicio Extensión del array servicio
 */
void MostrarServicios(eServicio servicio[], int extensionServicio);

/**
 * @brief Busca el indice de un servicio en el array, por su ID
 * 
 * @param servicio Array servicio
 * @param extensionServicio Extensión del array servicio
 * @return int Devuelve el índice del servicio encontrado en el array Servicio
 */
int BuscarIdServicio(eServicio servicio[], int extensionServicio);





#endif /* SERVICIOS_H_ */
