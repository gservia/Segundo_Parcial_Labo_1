#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Arcade.h"

/** \brief Parsea los datos los datos de los arcades desde el archivo .csv
 *
 * \param path char*
 * \param pArrayListArcade LinkedList*
 * \return int
 *
 */
int parser_ArcadeFromText(FILE* pFile, LinkedList* pArrayListArcade)
{
	int state = -1;
	Arcade* pArcadeAux;
	char idAux[NOMBRE_LEN];
    char nacionalidadAux[NOMBRE_LEN];
    char tipo_sonidoAux[NOMBRE_LEN];
    char cant_jugAux[NOMBRE_LEN];
    char fichas_maxAux[NOMBRE_LEN];
    char salonAux[NOMBRE_LEN];
    char nombreJuegoAux[NOMBRE_LEN];

	if (pFile != NULL && pArrayListArcade != NULL)
	{
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", idAux, nacionalidadAux, tipo_sonidoAux, cant_jugAux,
				fichas_maxAux, salonAux, nombreJuegoAux); // Saltea encabezado

		do
		{
			if (fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", idAux, nacionalidadAux, tipo_sonidoAux, cant_jugAux,
					fichas_maxAux, salonAux, nombreJuegoAux) == 7)
			{
				pArcadeAux = arcade_newParametros(idAux, nacionalidadAux, tipo_sonidoAux, cant_jugAux,
						fichas_maxAux, salonAux, nombreJuegoAux);

				if (pArcadeAux != NULL)
				{
					ll_add(pArrayListArcade, pArcadeAux);
					state = 0;
				}
			}
			else
			{
				arcade_delete(pArcadeAux);
				break;
			}
		} while (feof(pFile) == 0);
	}

    return state;
}
