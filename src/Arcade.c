/*
 * Arcade.c
 * Author: Gabriel Servia
 */
#include "Arcade.h"

/**
 * \brief Creates memory space for one Arcade
 * \return pArcade Pointer to an Arcade
 */
Arcade* arcade_new()
{
	Arcade* pArcade = (Arcade*) malloc(sizeof(Arcade));

	return pArcade;
}


/**
 * \brief Arcade setting parametres
 * \param idStr
 * \param nacionalidadStr
 * \param tipo_sonidoStr
 * \param cant_jugStr
 * \param fichas_maxStr
 * \param salonStr
 * \param nombreJuegoStr
 * \return pArcade Pointer to an Arcade
 */
Arcade* arcade_newParametros(char* idStr, char* nacionalidadStr, char* tipo_sonidoStr, char* cant_jugStr, char* fichas_maxStr, char* salonStr, char* nombreJuegoStr)
{
	Arcade* pArcade = NULL;
	pArcade = arcade_new();

	if (idStr != NULL && esNumerica(idStr, sizeof(idStr)) == 1 && nacionalidadStr != NULL && tipo_sonidoStr != NULL &&
			cant_jugStr != NULL && esNumerica(cant_jugStr, sizeof(cant_jugStr)) == 1 &&
			fichas_maxStr != NULL && esNumerica(fichas_maxStr, sizeof(fichas_maxStr)) == 1 &&
			salonStr != NULL && nombreJuegoStr != NULL)
	{
		arcade_setId(pArcade, atoi(idStr));
		arcade_setNacionalidad(pArcade, nacionalidadStr);
		if (strcmp(tipo_sonidoStr, "MONO") == 0)
		{
			arcade_setTipoSonido(pArcade, 1);
		}
		else if (strcmp(tipo_sonidoStr, "STEREO") == 0)
		{
			arcade_setTipoSonido(pArcade, 2);
		}
		arcade_setCantJug(pArcade, atoi(cant_jugStr));
		arcade_setFichasMax(pArcade, atoi(fichas_maxStr));
		arcade_setSalon(pArcade, salonStr);
		arcade_setNombreJuego(pArcade, nombreJuegoStr);
	}
	return pArcade;
}


/**
 * \brief Delete memory space of one Arcade
 * \param this Pointer to Arcade
 */
void arcade_delete(Arcade* this)
{
	if (this != NULL)
	{
		free(this);
	}
}


/**
 * \brief Setter id
 * \param this Arcade*
 * \param id int
 * \return Returns 0 if it OK, or -1 if it gives an Error
 */
int arcade_setId(Arcade* this, int id)
{
	int state = -1;

	if (this != NULL && id >= 0)
	{
		this->id = id;
		state = 0;
	}
	return state;
}


/**
 * \brief Getter id
 * \param this Arcade*
 * \param id int*
 * \return Returns 0 if it OK, or -1 if it gives an Error
 */
int arcade_getId(Arcade* this, int* id)
{
	int state = -1;

	if (this != NULL && id != NULL)
	{
		*id = this->id;
		state = 0;
	}
	return state;
}


/**
 * \brief Setter nacionalidad
 * \param this Arcade*
 * \param nacionalidad char*
 * \return Returns 0 if it OK, or -1 if it gives an Error
 */
int arcade_setNacionalidad(Arcade* this, char* nacionalidad)
{
	int state = -1;

	if (this != NULL && nacionalidad != NULL)
	{
		if (esTexto(nacionalidad, NOMBRE_LEN) == 1)
		{
			strncpy(this->nacionalidad, nacionalidad, NOMBRE_LEN);
			state = 0;
		}
	}
	return state;
}


/**
 * \brief Getter nacionalidad
 * \param this Arcade*
 * \param nacionalidad char*
 * \return Returns 0 if it OK, or -1 if it gives an Error
 */
int arcade_getNacionalidad(Arcade* this, char* nacionalidad)
{
	int state = -1;

	if (this != NULL && nacionalidad != NULL)
	{
			strncpy(nacionalidad, this->nacionalidad, NOMBRE_LEN);
			state = 0;
	}
	return state;
}


/**
 * \brief Setter tipo_sonido
 * \param this Arcade*
 * \param tipo_sonido int
 * \return Returns 0 if it OK, or -1 if it gives an Error
 */
int arcade_setTipoSonido(Arcade* this, int tipo_sonido)
{
	int state = -1;

	if (this != NULL && tipo_sonido >= 0)
	{
		this->tipo_sonido = tipo_sonido;
		state = 0;
	}
	return state;
}


/**
 * \brief Getter tipo_sonido
 * \param this Arcade*
 * \param tipo_sonido int*
 * \return Returns 0 if it OK, or -1 if it gives an Error
 */
int arcade_getTipoSonido(Arcade* this, int* tipo_sonido)
{
	int state = -1;

	if (this != NULL && tipo_sonido != NULL)
	{
		*tipo_sonido = this->tipo_sonido;
		state = 0;
	}
	return state;
}


/**
 * \brief Setter cant_jug
 * \param this Arcade*
 * \param cant_jug int
 * \return Returns 0 if it OK, or -1 if it gives an Error
 */
int arcade_setCantJug(Arcade* this, int cant_jug)
{
	int state = -1;

	if (this != NULL && cant_jug >= 0)
	{
		this->cant_jug = cant_jug;
		state = 0;
	}
	return state;
}


/**
 * \brief Getter cant_jug
 * \param this Arcade*
 * \param cant_jug int*
 * \return Returns 0 if it OK, or -1 if it gives an Error
 */
int arcade_getCantJug(Arcade* this, int* cant_jug)
{
	int state = -1;

	if (this != NULL && cant_jug != NULL)
	{
		*cant_jug = this->cant_jug;
		state = 0;
	}
	return state;
}


/**
 * \brief Setter fichas_max
 * \param this Arcade*
 * \param fichas_max int
 * \return Returns 0 if it OK, or -1 if it gives an Error
 */
int arcade_setFichasMax(Arcade* this, int fichas_max)
{
	int state = -1;

	if (this != NULL && fichas_max >= 0)
	{
		this->fichas_max = fichas_max;
		state = 0;
	}
	return state;
}


/**
 * \brief Getter fichas_max
 * \param this Arcade*
 * \param fichas_max int*
 * \return Returns 0 if it OK, or -1 if it gives an Error
 */
int arcade_getFichasMax(Arcade* this, int* fichas_max)
{
	int state = -1;

	if (this != NULL && fichas_max != NULL)
	{
		*fichas_max = this->fichas_max;
		state = 0;
	}
	return state;
}


/**
 * \brief Setter salon
 * \param this Arcade*
 * \param salon char*
 * \return Returns 0 if it OK, or -1 if it gives an Error
 */
int arcade_setSalon(Arcade* this, char* salon)
{
	int state = -1;

	if (this != NULL && salon != NULL)
	{
		if (esTexto(salon, NOMBRE_LEN) == 1)
		{
			strncpy(this->salon, salon, NOMBRE_LEN);
			state = 0;
		}
	}
	return state;
}


/**
 * \brief Getter salon
 * \param this Arcade*
 * \param salon char*
 * \return Returns 0 if it OK, or -1 if it gives an Error
 */
int arcade_getSalon(Arcade* this, char* salon)
{
	int state = -1;

	if (this != NULL && salon != NULL)
	{
			strncpy(salon, this->salon, NOMBRE_LEN);
			state = 0;
	}
	return state;
}


/**
 * \brief Setter nombreJuego
 * \param this Arcade*
 * \param nombreJuego char*
 * \return Returns 0 if it OK, or -1 if it gives an Error
 */
int arcade_setNombreJuego(Arcade* this, char* nombreJuego)
{
	int state = -1;

	if (this != NULL && nombreJuego != NULL)
	{
		if (esTexto(nombreJuego, NOMBRE_LEN) == 1)
		{
			strncpy(this->nombreJuego, nombreJuego, NOMBRE_LEN);
			state = 0;
		}
	}
	return state;
}


/**
 * \brief Getter nombreJuego
 * \param this Arcade*
 * \param nombreJuego char*
 * \return Returns 0 if it OK, or -1 if it gives an Error
 */
int arcade_getNombreJuego(Arcade* this, char* nombreJuego)
{
	int state = -1;

	if (this != NULL && nombreJuego != NULL)
	{
			strncpy(nombreJuego, this->nombreJuego, NOMBRE_LEN);
			state = 0;
	}
	return state;
}


/**
 * \brief Finds an Arcade by ID
 * \param listArcades LinkedList*
 * \param id to find
 * \return Returns position if it's found, or -1 if it's not [Error]
 */
int arcade_findById(LinkedList* listArcades, int id)
{
	int position = -1;
	int i;
	int listLen;
	Arcade* pArcadeAux;

	if (listArcades != NULL && id > 0)
	{
		listLen = ll_len(listArcades);

		for (i = 0; i < listLen; i++)
		{
			pArcadeAux = ll_get(listArcades, i);

			if (pArcadeAux->id == id)
			{
				position = i;
				break;
			}
		}
	}
	return position;
}


/**
 * \brief Load data of one Arcade
 * \param pArcade
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if OK
 */
int arcade_load(Arcade* pArcade)
{
	int state = -1;
    char nacionalidadAux[NOMBRE_LEN];
    int tipo_sonidoAux;
    int cant_jugAux;
    int fichas_maxAux;
    char salonAux[NOMBRE_LEN];
    char nombreJuegoAux[NOMBRE_LEN];

    if (utn_getText(nacionalidadAux, NOMBRE_LEN, "Ingresar nacionalidad: ", "Error en la carga de la nacionalidad\n", 0) == 0)
    {
    	if (utn_getInt(&tipo_sonidoAux, "Seleccionar tipo de sonido\n 1. Mono\n 2. Estereo\nIngresar opcion deseada: ",
    			"Error en la carga del tipo de sonido\n", 1, 2, 0) == 0)
    	{
			if (utn_getInt(&cant_jugAux, "Ingresar cantidad de jugadores: ", "Error en la carga de la cantidad de jugadores\n",
			    				1, 999999, 0) == 0)
    		{
	    		if (utn_getInt(&fichas_maxAux, "Ingresar numero de fichas maximo: ", "Error en la carga de cantidad de fichas\n",
	    				1, 999999, 0) == 0)
    			{
	    		    if (utn_getText(salonAux, NOMBRE_LEN, "Ingresar nombre de salon: ",
	    		    		"Error en la carga del salon\n", 0) == 0)
	    		    {
		    		    if (utn_getText(nombreJuegoAux, NOMBRE_LEN, "Ingresar nombre del juego: ",
		    		    		"Error en la carga del nombre\n", 0) == 0)
		    		    {
		    		    	arcade_setNacionalidad(pArcade, nacionalidadAux);
		    		    	arcade_setTipoSonido(pArcade, tipo_sonidoAux);
		    		    	arcade_setCantJug(pArcade, cant_jugAux);
		    		    	arcade_setFichasMax(pArcade, fichas_maxAux);
		    		    	arcade_setSalon(pArcade, salonAux);
		    		    	arcade_setNombreJuego(pArcade, nombreJuegoAux);
		    		    	state = 0;
		    		    }
	    		    }
    			}
    		}
    	}
    }
	return state;
}


/**
 * \brief Edit data of one Arcade
 * \param pArcade
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if OK
 */
int arcade_edit(Arcade* pArcade, int option)
{
	int state = -1;
    int cant_jugAux;
    char nombreJuegoAux[NOMBRE_LEN];

	do {
			switch (option)
			{
				case 1:
					if (utn_getInt(&cant_jugAux, "Ingresar cantidad de jugadores: ", "Error en la carga de la cantidad de jugadores\n",
								    				1, 999999, 0) == 0)
					{
						arcade_setCantJug(pArcade, cant_jugAux);
						printf("\n=== Cantidad de jugadores modificada con exito ===\n\n");
						option = 3;
						state = 0;
						break;
					}
					else
					{
						state = -1;
					}
					break;
				case 2:
					if (utn_getText(nombreJuegoAux, NOMBRE_LEN, "\nIngresar nombre del juego: ",
							    		    		"Error en la carga del nombre\n", 0) == 0)
					{
						arcade_setNombreJuego(pArcade, nombreJuegoAux);
						printf("\n=== Nombre de juego modificado con exito ===\n\n");
						state = 0;
						option = 3;
						break;
					}
					else
					{
						state = -1;
					}
					break;
				case 3:
					printf("=== Regreso al menu principal ===\n");
					break;
				default:
					printf("Solo se aceptan opciones de 1 a 3\n");
					break;
			}
	} while (option != 3);
	return state;
}


/**
 * \brief Print one Arcade
 * \param pArcade
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if OK
 */
int arcade_print(Arcade* pArcade)
{
	int state = -1;
	int idAux;
    char nacionalidadAux[NOMBRE_LEN];
    int tipo_sonidoAux;
    char tipo_sonidoTxt[NOMBRE_LEN];
    int cant_jugAux;
    int fichas_maxAux;
    char salonAux[NOMBRE_LEN];
    char nombreJuegoAux[NOMBRE_LEN];

	if (pArcade != NULL)
	{
		arcade_getId(pArcade, &idAux);
		arcade_getNacionalidad(pArcade, nacionalidadAux);
		arcade_getTipoSonido(pArcade, &tipo_sonidoAux);
		switch (tipo_sonidoAux)
		{
			case 1:
				strncpy(tipo_sonidoTxt, "MONO", sizeof(tipo_sonidoTxt));
				break;
			case 2:
				strncpy(tipo_sonidoTxt, "STEREO", sizeof(tipo_sonidoTxt));
				break;
		}
		arcade_getCantJug(pArcade, &cant_jugAux);
		arcade_getFichasMax(pArcade, &fichas_maxAux);
		arcade_getSalon(pArcade, salonAux);
		arcade_getNombreJuego(pArcade, nombreJuegoAux);

		printf("%d	| %s	| %s	| %d	| %d	| %s	| %s\n", idAux, nacionalidadAux, tipo_sonidoTxt, cant_jugAux, fichas_maxAux,
				salonAux, nombreJuegoAux);
		state = 0;
	}
	return state;
}


/**
 * \brief Set the criteria to Sort list of Arcade by Game Name
 * \param pArcadeA
 * \param pArcadeB
 * \return int Return (-1) or (1) to set sorting criteria
 *                    (0) if nombreJuegoUno and nombreJuegoDos are equals
 */
int arcade_compareByNombreJuego(void* pArcadeA, void* pArcadeB)
{
	int state = 0;

    char nombreJuegoUno[NOMBRE_LEN];
    char nombreJuegosDos[NOMBRE_LEN];

    if(pArcadeA != NULL && pArcadeB != NULL)
	{
		arcade_getNombreJuego((Arcade*)pArcadeA, nombreJuegoUno);
		arcade_getNombreJuego((Arcade*)pArcadeB, nombreJuegosDos);

		if (strcmp(nombreJuegoUno, nombreJuegosDos) < 0)
		{
			state = -1;
		}
		else
		{
			if (strcmp(nombreJuegoUno, nombreJuegosDos) > 0)
			{
				state = 1;
			}
		}
	}
	return state;
}


/**
 * \brief Set the criteria to Sort list of Arcade by ID
 * \param pArcadeA
 * \param pArcadeB
 * \return int Return (-1) or (1) to set sorting criteria
 *                    (0) if nombreJuegoUno and nombreJuegoDos are equals
 */
int arcade_compareById(void* pArcadeA, void* pArcadeB)
{
	int state = 0;

	if (((Arcade*)pArcadeA)->id > ((Arcade*)pArcadeB)->id)
	{
		state = 1;
	}
	if (((Arcade*)pArcadeA)->id < ((Arcade*)pArcadeB)->id)
	{
		state = -1;
	}
	return state;
}


/**
 * \brief Compare if one Arcade is multiplayer
 * \param pArcade
 * \return int Return (1) if cant_jug > 1
 *                    (0) if cant_jug <= 1
 */
int arcade_compareMultijugador(void* pArcade)
{
	int state = 0;

	if (((Arcade*)pArcade)->cant_jug > 1)
	{
		state = 1;
	}
	return state;
}


/**
 * \brief Set the double of fichas_max in each Arcade
 * \param pAux
 */
void doubleFichasMax(void* pAux)
{
	((Arcade*)pAux)->fichas_max = (((Arcade*)pAux)->fichas_max) * 2;
}

