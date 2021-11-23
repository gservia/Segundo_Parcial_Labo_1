/*
 * input_validation.h
 * Author: Gabriel Servia
 */

#ifndef INPUT_VALIDATION_H_
#define INPUT_VALIDATION_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int esTexto(char* cadena,int len);
int esNumerica(char* cadena, int limite);
int esFloat(char* cadena);
int esNombre(char* cadena,int len);

#endif /* INPUT_VALIDATION_H_ */
