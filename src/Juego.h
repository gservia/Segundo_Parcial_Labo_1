/*
 * Juego.h
 * Author: Gabriel Servia
 */

#ifndef JUEGO_H_
#define JUEGO_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "utn.h"
#include "input_validation.h"

#define NOMBRE_LEN 63

typedef struct {
	char nombreJuego[NOMBRE_LEN];
}Juego;

Juego* juego_new();
Juego* juego_newParametros(char* nombreJuegoStr);

int juego_setNombreJuego(Juego* this, char* nombreJuego);
int juego_getNombreJuego(Juego* this, char* nombreJuego);

int juego_print(Juego* this);

#endif /* JUEGO_H_ */
