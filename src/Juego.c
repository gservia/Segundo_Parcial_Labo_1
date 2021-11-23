/*
 * Juego.c
 * Author: Gabriel Servia
 */
#include "Juego.h"


/**
 * \brief Creates memory space for one Juego
 * \return pJuego Pointer to an Juego
 */
Juego* juego_new()
{
	Juego* pJuego = (Juego*) malloc(sizeof(Juego));

	return pJuego;
}


/**
 * \brief Juego setting parametres
 * \param nombreJuegoStr
 * \return pJuego Pointer to a Juego
 */
Juego* juego_newParametros(char* nombreJuegoStr)
{
	Juego* pJuego = NULL;
	pJuego = juego_new();

	if (pJuego != NULL && nombreJuegoStr != NULL)
	{
		juego_setNombreJuego(pJuego, nombreJuegoStr);
	}
	return pJuego;
}


/**
 * \brief Setter nombreJuego
 * \param this Juego*
 * \param nombreJuego char*
 * \return Returns 0 if it OK, or -1 if it gives an Error
 */
int juego_setNombreJuego(Juego* this, char* nombreJuego)
{
	int state = -1;

	if(this != NULL && nombreJuego != NULL)
	{
		if(esTexto(nombreJuego, NOMBRE_LEN) == 1)
		{
			strncpy(this->nombreJuego, nombreJuego, NOMBRE_LEN);
			state = 0;
		}
	}
	return state;
}


/**
 * \brief Getter nombreJuego
 * \param this Juego*
 * \param nombreJuego char*
 * \return Returns 0 if it OK, or -1 if it gives an Error
 */
int juego_getNombreJuego(Juego* this, char* nombreJuego)
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
 * \brief Print one Juego
 * \param this Juego*
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if OK
 */
int juego_print(Juego* this)
{
	int state = -1;
	char nombreJuegoAux[NOMBRE_LEN];

	if (this != NULL)
	{
		juego_getNombreJuego(this, nombreJuegoAux);
		printf("%s\n", nombreJuegoAux);
		state = 0;
	}
	return state;
}

