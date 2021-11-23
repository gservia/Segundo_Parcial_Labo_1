/*
 * utn.h
 * Author: Gabriel Servia
 */

#ifndef UTN_H_
#define UTN_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input_validation.h"

int utn_getText(char* pResultado, int len, char* mensaje, char* mensajeError, int reintentos);
int utn_getInt(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int utn_getFloat(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);
int utn_getName(char* pResultado, int len,char* mensaje, char* mensajeError, int reintentos);

#endif /* UTN_H_ */
