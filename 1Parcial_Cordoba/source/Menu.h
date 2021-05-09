
#ifndef MENU_H_
#define MENU_H_

/**
 * @brief Muestra las opciones del menú principal
 * 
 * @return int Devuelve la opción seleccionada
 */
int MenuPrincipal();

/**
 * @brief Submenú para modificar un trabajo
 * 
 * @return int Devuelve la opción seleccionada
 */
int MenuModificarTrabajo();

/**
 * @brief Contiene el switch del menú de modificar trabajo
 * 
 * @param opcion Opción seleccionada
 * @param trabajo Array trabajo
 * @param extensionTrabajo Extensión del array trabajo
 * @param servicio Array servicio
 * @param extensionServicio Extensión del array servicio
 */
void SwitchModificarTrabajo(int opcion,eTrabajo trabajo[], int extensionTrabajo, eServicio servicio[], int extensionServicio);

#endif /* MENU_H_ */
