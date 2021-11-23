/*
 * ListaJuego.h
 * Author: Gabriel Servia
 */

#ifndef LISTAJUEGO_H_
#define LISTAJUEGO_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "utn.h"
#include "input_validation.h"
#include "Arcade.h"
#include "Juego.h"

#define NOMBRE_LEN 63

int listaJuego_createGamesFile(LinkedList* pArrayListArcade, LinkedList* pArrayListJuego);
int listaJuego_gameInList(LinkedList* pArrayList, char* nombreJuego);
int listaJuego_ListGame(LinkedList* pArrayList);
int listaJuego_saveGamesFile(char* path , LinkedList* pArrayList);

#endif /* LISTAJUEGO_H_ */
