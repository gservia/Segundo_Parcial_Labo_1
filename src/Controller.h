#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Arcade.h"
#include "Juego.h"
#include "ListaJuego.h"
#include "parser.h"

int controller_loadFromText(char* path , LinkedList* pArrayListArcade);
int controller_addArcade(LinkedList* pArrayListArcade);
int controller_increaseIdMaxInFile(char* path, int id);
int controller_createIdMaxFile(char* path, LinkedList* pArrayArcade);
int controller_findLastId(LinkedList* pArrayArcade);
int controller_getLastIdFromFile(char* path, int* id);
int controller_editArcade(LinkedList* pArrayListArcade, LinkedList* pArrayListJuego);
int controller_removeArcade(LinkedList* pArrayListArcade);
int controller_ListArcade(LinkedList* pArrayListArcade);
int controller_sortArcade(LinkedList* pArrayListArcade);
int controller_saveAsText(char* path , LinkedList* pArrayListArcade);
