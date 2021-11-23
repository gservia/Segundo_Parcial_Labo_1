/*
 * Arcade.h
 * Author: Gabriel Servia
 */

#ifndef ARCADE_H_
#define ARCADE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "utn.h"
#include "input_validation.h"

#define NOMBRE_LEN 63
#define MONO 1
#define STEREO 2

typedef struct
{
    int id;
    char nacionalidad[NOMBRE_LEN];
    int tipo_sonido;
    int cant_jug;
    int fichas_max;
    char salon[NOMBRE_LEN];
    char nombreJuego[NOMBRE_LEN];
}Arcade;

Arcade* arcade_new();
Arcade* arcade_newParametros(char* idStr, char* nacionalidadStr, char* tipo_sonidoStr, char* cant_jugStr, char* fichas_maxStr, char* salonStr, char* nombreJuegoStr);
void arcade_delete(Arcade* this);

int arcade_setId(Arcade* this, int id);
int arcade_getId(Arcade* this, int* id);

int arcade_setNacionalidad(Arcade* this, char* nacionalidad);
int arcade_getNacionalidad(Arcade* this, char* nacionalidad);

int arcade_setTipoSonido(Arcade* this, int tipo_sonido);
int arcade_getTipoSonido(Arcade* this, int* tipo_sonido);

int arcade_setCantJug(Arcade* this, int cant_jug);
int arcade_getCantJug(Arcade* this, int* cant_jug);

int arcade_setFichasMax(Arcade* this, int fichas_max);
int arcade_getFichasMax(Arcade* this, int* fichas_max);

int arcade_setSalon(Arcade* this, char* salon);
int arcade_getSalon(Arcade* this, char* salon);

int arcade_setNombreJuego(Arcade* this, char* nombreJuego);
int arcade_getNombreJuego(Arcade* this, char* nombreJuego);

int arcade_findById(LinkedList* listArcades, int id);
int arcade_load(Arcade* pArcade);
int arcade_edit(Arcade* pArcade, int option);
int arcade_print(Arcade* pArcade);
int arcade_compareByNombreJuego(void* pArcadeA, void* pArcadeB);
int arcade_compareById(void* pArcadeA, void* pArcadeB);
int arcade_compareMultijugador(void* pArcade);
void doubleFichasMax(void* pAux);

#endif /* ARCADE_H_ */
