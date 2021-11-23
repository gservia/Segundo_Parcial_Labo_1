/*
 * menu.c
 * Author: Gabriel Servia
 */
#include "menu.h"

/**
 * \brief Options Menu. Request a option to user
 * \return Return selected option
 */
int menu()
{
	int option;
	int optionAux;

	printf("\n===================================================================");
	printf("\n===========================    MENU    ============================\n");
	printf(" 1. LEER ARCADES DESDE ARCHIVO CSV\n");
	printf(" 2. INCORPORAR ARCADE\n");
	printf(" 3. MODIFICAR ARCADE\n");
	printf(" 4. ELIMINAR ARCADE\n");
	printf(" 5. IMPRIMIR ARCADES ORDENADOS\n");
	printf(" 6. GENERAR ARCHIVO CON JUEGOS\n");
	printf(" 7. GENERAR UN ARCHIVO CON ARCADES “Multijugador” (MAS DE 1 JUGADOR)\n");
	printf(" 8. ACTUALIZAR CANTIDAD DE FICHAS\n");
	printf(" 9. GUARDAR INFORMACION Y SALIR\n");

	if (utn_getInt(&optionAux, "\nINGRESAR UNA OPCION: ", "ERROR: Comando no valido.\n", 1, 9, 0) == 0)
	{
		option = optionAux;
	}
	return option;
}
