/*
 * getFunctions.h
 *
 *  Created on: 2 may. 2021
 *      Author: pablo22
 */

#ifndef GETFUNCTIONS_H_
#define GETFUNCTIONS_H_

/**
 * @brief Get the Int object
 * 
 * @param mensaje  Mensaje que se mostrará al usuario.
 * @param mensajeDeError Mensaje en caso de que se ingrese un dato erróneo.
 * @param minimo Valor mínimo que debe tener el número ingresado.
 * @param maximo Valor máximo que debe tener el número ingresado.
 * @param realizarValidaciones 0 si no se realizarán las validaciones, 1 si se realizarán. (Se ha definido TRUE 1 y FALSE 0).
 * @return int Se devuelve el entero obtenido.
 */
int getInt(char mensaje[], char mensajeDeError[], int minimo, int maximo, int realizarValidaciones);

/**
 * @brief Get the Float object
 * 
 * @param mensaje Mensaje que se mostrará al usuario.
 * @param mensajeDeError Mensaje en caso de que se ingrese un dato erróneo.
 * @param minimo Valor mínimo que debe tener el número ingresado.
 * @param maximo Valor máximo que debe tener el número ingresado.
 * @param realizarValidaciones 0 si no se realizarán las validaciones, 1 si se realizarán. (Se ha definido TRUE 1 y FALSE 0).
 * @return float Se devuelve el valor obtenido.
 */
float getFloat(char mensaje[], char mensajeDeError[], float minimo, int maximo, int realizarValidaciones);

/**
 * @brief Get the Char object
 * 
 * @param mensaje Mensaje que se mostrará al usuario.
 * @param mensajeDeError Mensaje en caso de que se ingrese un dato erróneo.
 * @param opcion1 El caracter ingresado podrá tomar el valor indicado en esta variable.
 * @param opcion2 El caracter ingresado podrá tomar el valor indicado en esta variable.
 * @param realizarValidaciones 0 si no se realizarán las validaciones, 1 si se realizarán. (Se ha definido TRUE 1 y FALSE 0). 
 * @return char Se devuelve el valor obtenido.
 */
char getChar(char mensaje[], char mensajeDeError[], char opcion1, char opcion2, int realizarValidaciones);

/**
 * @brief Get the String object
 * 
 * @param mensaje Mensaje que se mostrará al usuario.
 * @param cadenaDeSalida variable char[] donde se guardará la cadena obtenida.
 */
void getString(char mensaje[], char cadenaDeSalida[]);

/**
 * @brief Generador de ID autoincremental. Busca el mayor valor entre las ID existentes, y le suma 1.
 * 
 * @param trabajo Estructura sobre la que se generará el ID.
 * @param extensionTrabajo Extensión de la estructura.
 * @return int Devuelve el ID generado.
 */
int getIdTrabajo(eTrabajo trabajo[], int extensionTrabajo);

/**
 * @brief Las funciones de búsqueda de índices, retornan -1 en caso de no encontrar el índice buscado. En ese caso, esta función devuelve un mensaje de error.
 * 
 * @param indice Indice devuelto por la función de buscar índice.
 */
void ValidarIndice(int indice);

/**
 * @brief Este función inicializa todos los valores de un vector de enteros. se utiliza para contadores.
 * 
 * @param vector Vector a inicializar.
 * @param extensionVector Extensión del vector.
 * @param valorDeInicio El valor con el que se inicializará el vector.
 */
void InicializarVector(int vector[], int extensionVector, int valorDeInicio);

#endif /* GETFUNCTIONS_H_ */
