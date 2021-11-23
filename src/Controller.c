#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Arcade.h"
#include "Juego.h"
#include "Controller.h"


/** \brief Carga los datos de los arcades desde el archivo .csv
 *
 * \param path char*
 * \param pArrayListArcade LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListArcade)
{
	int state = -1;
	FILE* f = fopen(path, "r");

	if (f != NULL)
	{
		if (parser_ArcadeFromText(f, pArrayListArcade) == 0)
		{
			state = 0;
		}
		fclose(f);
	}
    return state;
}


/** \brief Alta de arcade
 *
 * \param path char*
 * \param pArrayListArcade LinkedList*
 * \return int
 *
 */
int controller_addArcade(LinkedList* pArrayListArcade)
{
	int state = -1;
	int idAux;
	int flagIdLoaded;
	Arcade* pArcadeAux;

	pArcadeAux = arcade_new();

	flagIdLoaded = -1;

	if (pArcadeAux != NULL)
	{
		printf("\nALTA DE ARCADE\n");

		if (controller_getLastIdFromFile("idMaxInput.csv", &idAux) == 0) // Busca el ultimo ID ingresado al sistema
		{
			flagIdLoaded = 0;
		}
		else
		{
			if (controller_createIdMaxFile("idMaxInput.csv", pArrayListArcade) == 0) // Si no encuentra archivo de ID, lo crea
			{
				if (controller_getLastIdFromFile("idMaxInput.csv", &idAux) == 0)
				{
					flagIdLoaded = 0;
				}
			}
		}

		if (flagIdLoaded == 0)
		{
			if (arcade_load(pArcadeAux) == 0)
			{
				if (arcade_setId(pArcadeAux, idAux) == 0)
				{
					ll_add(pArrayListArcade, pArcadeAux);
					controller_increaseIdMaxInFile("idMaxInput.csv", idAux);
					state = 0;
				}
			}
		}
	}
    return state;
}

/** \brief Aumentar en 1 el ultimo ID creado en archivo
 *
 * \param path char*
 * \param id int
 * \return Retorna 0 si tuvo exito
 *
 */
int controller_increaseIdMaxInFile(char* path, int id)
{
	int state = -1;

	FILE* f = fopen(path, "w");

	if (f != NULL)
	{
		id++;
		fprintf(f, "%d\n", id);
		fclose(f);
		state = 0;
	}
    return state;
}

/** \brief Crear archivo en primera ejecucion con ID maximo
 *
 * \param path char*
 * \return Retorna 0 si tuvo exito
 *
 */
int controller_createIdMaxFile(char* path, LinkedList* pArrayArcade)
{
	int state = -1;
	int idMax;

	idMax = controller_findLastId(pArrayArcade);
	idMax++;

	FILE* f = fopen(path, "w");

	if (f != NULL)
	{
		fprintf(f, "%d\n", idMax);
		fclose(f);
		state = 0;
	}
    return state;
}


/** \brief Busca el ID maximo en la primer ejecucion del programa
 *
 * \param pArrayArcade LinkedList*
 * \return Retorna el id maximo del archivo
 *
 */
int controller_findLastId(LinkedList* pArrayArcade)
{
	int len;
	int i;
	int id;
	int idMax = -1;
	Arcade* pElemento;

	idMax = 0;

	if(pArrayArcade != NULL)
	{
		len = ll_len(pArrayArcade);

		for (i = 0; i < len; i++)
		{
			if (ll_get(pArrayArcade, i) != NULL)
			{
				pElemento = ll_get(pArrayArcade, i);
				arcade_getId(pElemento, &id);

				if (id > idMax)
				{
					idMax = id;
				}
			}
		}
	}
	return idMax;
}


/** \brief Lee el ultimo ID ingresado el sistema
 *
 * \param path char*
 * \param id int*
 * \return Retorna 0 si tuvo exito
 *
 */
int controller_getLastIdFromFile(char* path, int* id)
{
	int state = -1;
	char idTxt[128];

	// "IdMaxInput.csv"
	FILE* f = fopen(path, "r");

	if (f != NULL)
	{
		if (fscanf(f, "%[^\n]\n", idTxt) == 1)
		{
			*id = atoi(idTxt);
			state = 0;
		}
	}
	fclose(f);
	return state;
}


/** \brief Modificar datos de arcade
 *
 * \param path char*
 * \param pArrayListArcade LinkedList*
 * \return int
 *
 */
int controller_editArcade(LinkedList* pArrayListArcade, LinkedList* pArrayListJuego)
{
	int state = -1;
	int idToEdit;
	int position;
	int option;
	Arcade* pArcadeAux;

	if (pArrayListArcade != NULL)
	{
		if (controller_ListArcade(pArrayListArcade) == 0)
		{
			if (utn_getInt(&idToEdit, "\nIngresar el ID del arcade a modificar: ", "Error: comando no valido\n", 1, 999999, 0) == 0)
			{
				position = arcade_findById(pArrayListArcade, idToEdit);
				if (position > -1)
				{
					pArcadeAux = ll_get(pArrayListArcade, position);

					if (pArcadeAux != NULL)
					{
						printf("¿Que campo desea modificar?\n 1. Cantidad de jugadores\n 2. Nombre del juego\n 3. Finalizar y regresar al menu\n");

						if (utn_getInt(&option, "Ingresar la opcion deseada: ", "Error: comando no valido\n", 1, 3, 0) == 0)
						{
							if (option == 1)
							{
								if (arcade_edit(pArcadeAux, option) == 0)
								{
									state = 0;
								}
							}
							else if (option == 2)
							{
								if (listaJuego_createGamesFile(pArrayListArcade, pArrayListJuego) == 0)
								{
									listaJuego_ListGame(pArrayListJuego);
									if (arcade_edit(pArcadeAux, option) == 0)
									{
										state = 0;
									}
								}
							}
							else if (option == 3)
							{
								if (arcade_edit(pArcadeAux, option) == 0)
								{
									state = 0;
								}
							}
						}
					}
					else
					{
						printf("\n=== ID ingresado inexistente ===\n");
					}
				}
				else
				{
					printf("\n=== ID ingresado inexistente ===\n");
				}
			}
		}
	}
    return state;
}


/** \brief Baja de arcade
 *
 * \param path char*
 * \param pArrayListArcade LinkedList*
 * \return int
 *
 */
int controller_removeArcade(LinkedList* pArrayListArcade)
{
	int state = -1;
	int idToEdit;
	int position;
	int confirm;
	Arcade* pArcadeAux;

	if (pArrayListArcade != NULL)
	{
		controller_ListArcade(pArrayListArcade);

		if (utn_getInt(&idToEdit, "\nIngresar el ID del arcade a dar de baja: ", "Error: comando no valido\n", 1, 999999, 0) == 0)
		{
			position = arcade_findById(pArrayListArcade, idToEdit);
			if (position > -1)
			{
				pArcadeAux = ll_get(pArrayListArcade, position);

				if (pArcadeAux != NULL)
				{
					printf("\nID	| NACIONALIDAD 	| SONIDO	| JUGADORES	| FICHAS MAX	| SALON		| NOMBRE DEL JUEGO\n");
					arcade_print(pArcadeAux);
					if (utn_getInt(&confirm, "\n¿Estas seguro que quieres eliminar a este arcade? Toda su informacion sera eliminada\n 1. Si\n 2. No\nIngrese una opcion: ",
								"Error: comando no valido\n", 1, 2, 0) == 0)
					{
						switch (confirm)
						{
							case 1:
								ll_remove(pArrayListArcade, position);
								arcade_delete(pArcadeAux);
								state = 0;
								break;
							case 2:
								printf("\n=== Baja cancelada ===\n");
								break;
						}
					}
				}
				else
				{
					printf("\n=== ID ingresado inexistente ===\n");
				}
			}
			else
			{
				printf("\n=== ID ingresado inexistente ===\n");
			}
		}
	}
    return state;
}

/** \brief Listar arcades
 *
 * \param path char*
 * \param pArrayListArcade LinkedList*
 * \return int
 *
 */
int controller_ListArcade(LinkedList* pArrayListArcade)
{
	int state = -1;
	int i;
	int len;
	Arcade* pArcadeAux;

	if (pArrayListArcade != NULL)
	{
		len = ll_len(pArrayListArcade);
		if (len > 0)
		{
			printf("\nID	| NACIONALIDAD 	| SONIDO	| JUGADORES	| FICHAS MAX	| SALON		| NOMBRE DEL JUEGO\n");

			for (i = 0; i < len; i++)
			{
				pArcadeAux = ll_get(pArrayListArcade, i);
				if (pArcadeAux != NULL)
				{
					arcade_print(pArcadeAux);
				}
			}
			state = 0;
		}
		else
		{
			printf("=== No hay elementos en la lista ===\n");
		}
	}
    return state;
}

/** \brief Ordenar arcades
 *
 * \param path char*
 * \param pArrayListArcade LinkedList*
 * \return int
 *
 */
int controller_sortArcade(LinkedList* pArrayListArcade)
{
	int state = -1;
	int optionOne;
	int optionTwo;
	int criteria;

	if (pArrayListArcade != NULL)
	{
		if (utn_getInt(&optionOne, "Ordenar lista por:\n 1. Nombre de juego\n 2. ID\nIngresar la opcion deseada: ",
						"Error: comando no valido\n", 1, 2, 0) == 0)
		{
			if (utn_getInt(&optionTwo, "¿Como desea ordenarlo?\n 1. Ascendente\n 2. Descendente\nIngresar la opcion deseada: ",
							"Error: comando no valido\n", 1, 2, 0) == 0)
			{
				if (optionTwo == 1)
				{
					criteria = 1;
				}
				else if (optionTwo == 2)
				{
					criteria = 0;
				}

				if (optionOne == 1)
				{
					if (ll_sort(pArrayListArcade, arcade_compareByNombreJuego, criteria) == 0)
					{
						state = 0;
					}
				}
				else if (optionOne == 2)
				{
					if (ll_sort(pArrayListArcade, arcade_compareById, criteria) == 0)
					{
						state = 0;
					}
				}
			}
		}
	}
    return state;
}


/** \brief Guarda los datos de los arcades en el archivo .csv
 *
 * \param path char*
 * \param pArrayListArcade LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListArcade)
{
	int state = -1;
	int i;
	int idAux;
    char nacionalidadAux[NOMBRE_LEN];
    int tipo_sonidoAux;
    char tipo_sonidoTxt[NOMBRE_LEN];
    int cant_jugAux;
    int fichas_maxAux;
    char salonAux[NOMBRE_LEN];
    char nombreJuegoAux[NOMBRE_LEN];
	Arcade* pArcadeAux;

	FILE* f = fopen(path, "w");

	if (f != NULL)
	{
		fprintf(f, "id,nacionalidad,tipo_sonido,cant_jug,fichas_max,salon,game\n");

		for(i = 0; i < ll_len(pArrayListArcade); i++)
		{
			pArcadeAux = ll_get(pArrayListArcade, i);

			arcade_getId(pArcadeAux, &idAux);
			arcade_getNacionalidad(pArcadeAux, nacionalidadAux);
			arcade_getTipoSonido(pArcadeAux, &tipo_sonidoAux);
			switch (tipo_sonidoAux)
			{
				case 1:
					strncpy(tipo_sonidoTxt, "MONO", sizeof(tipo_sonidoTxt));
					break;
				case 2:
					strncpy(tipo_sonidoTxt, "STEREO", sizeof(tipo_sonidoTxt));
					break;
			}
			arcade_getCantJug(pArcadeAux, &cant_jugAux);
			arcade_getFichasMax(pArcadeAux, &fichas_maxAux);
			arcade_getSalon(pArcadeAux, salonAux);
			arcade_getNombreJuego(pArcadeAux, nombreJuegoAux);

			fprintf(f, "%d,%s,%s,%d,%d,%s,%s\n", idAux, nacionalidadAux, tipo_sonidoTxt, cant_jugAux, fichas_maxAux,
					salonAux, nombreJuegoAux);
		}
		state = 0;
		fclose(f);
	}
    return state;
}



