/*
 * ListaJuego.c
 * Author: Gabriel Servia
 */
#include "ListaJuego.h"

/** \brief Crea un archivo .txt con una lista de todos los juegos cargados en sistema sin repetir
 *
 * \param pArrayListArcade LinkedList*
 * \return int
 *
 */
int listaJuego_createGamesFile(LinkedList* pArrayListArcade, LinkedList* pArrayListJuego)
{
	int state = -1;
	int i;
	Arcade* arcadeAux;
	Juego* juegoAux;
	char nombreJuegoAux[NOMBRE_LEN];

	if (pArrayListArcade != NULL && pArrayListJuego != NULL)
	{
		for (i = 0; i < ll_len(pArrayListArcade); i++)
		{
			arcadeAux = ll_get(pArrayListArcade, i);

			strncpy(nombreJuegoAux, arcadeAux->nombreJuego, NOMBRE_LEN);

			if (listaJuego_gameInList(pArrayListJuego, nombreJuegoAux) != 0)
			{
				juegoAux = juego_newParametros(nombreJuegoAux);
				ll_add(pArrayListJuego, juegoAux);
			}
		}
		state = 0;
	}
	return state;
}

/** \brief Verifica que si se repite un juego en la lista
 *
 * \param pArrayList LinkedList*
 * \param nombreJuego char*
 * \return int
 *
 */
int listaJuego_gameInList(LinkedList* pArrayList, char* nombreJuego)
{
	int state = -1;
	int i;
	Juego* juegoAux;

	if (pArrayList != NULL && nombreJuego != NULL)
	{
		for(i = 0; i < ll_len(pArrayList); i++)
		{
			juegoAux = ll_get(pArrayList, i);

			if(strncmp(juegoAux->nombreJuego, nombreJuego, NOMBRE_LEN) == 0)
			{
				state = 0;
				break;
			}
		}
	}
	return state;
}


/** \brief Listar juegos
 *
 * \param path char*
 * \param pArrayList LinkedList*
 * \return int
 *
 */
int listaJuego_ListGame(LinkedList* pArrayList)
{
	int state = -1;
	int i;
	int len;
	Juego* pJuegoAux;

	if (pArrayList != NULL)
	{
		len = ll_len(pArrayList);
		if (len > 0)
		{
			printf("\nNOMBRES DE JUEGOS\n");

			for (i = 0; i < len; i++)
			{
				pJuegoAux = ll_get(pArrayList, i);
				if (pJuegoAux != NULL)
				{
					juego_print(pJuegoAux);
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


/** \brief Guarda los datos de los juegos en el archivo .csv
 *
 * \param path char*
 * \param pArrayListArcade LinkedList*
 * \return int
 *
 */
int listaJuego_saveGamesFile(char* path , LinkedList* pArrayList)
{
	int state = -1;
	int i;
    char nombreJuegoAux[NOMBRE_LEN];
	Juego* pJuegoAux;

	FILE* f = fopen(path, "w");

	if (f != NULL)
	{
		for(i = 0; i < ll_len(pArrayList); i++)
		{
			pJuegoAux = ll_get(pArrayList, i);

			juego_getNombreJuego(pJuegoAux, nombreJuegoAux);

			fprintf(f, "%s\n", nombreJuegoAux);
		}
		state = 0;
		fclose(f);
	}
    return state;
}
