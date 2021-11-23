/*
 * input_validation.c
 * Author: Gabriel Servia
 */
#include "input_validation.h"


/**
 * \brief Verifica si la cadena ingresada es un texto valida
 * \param cadena Cadena de caracteres a ser analizada
 * \param len Define la longitud de la cadena
 * \return Retorna 1 (verdadero) si la cadena es valida y 0 (falso) si no lo es
 */
int esTexto(char* cadena, int len)
{
	int i = 0;
	int retorno = 1;

	if (cadena != NULL && len > 0)
	{
		for (i = 0; cadena[i] != '\0' && i < len; i++)
		{
			if (cadena[i] != '.' && cadena[i] != ' ' && (cadena[i] < 'A' || cadena[i] > 'Z' ) && (cadena[i] < 'a' || cadena[i] > 'z' ) && (cadena[i] < '0' || cadena[i] > '9' ) )
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}


/**
 * \brief Verifica si la cadena ingresada es numerica
 * \param pCadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (Verdadero) si la cadena es numerica, 0 (Falso) si no lo es y -1 en caso de Error
 */
int esNumerica(char* pCadena, int limite)
{
	int retorno = -1; // Error
	int i;

	if (pCadena != NULL && limite > 0)
	{
		retorno = 1; // Verdadero

		for(i = 0; i < limite && pCadena[i] != '\0'; i++)
		{
			if (i == 0 && (pCadena[i] == '+' || pCadena[i] == '-'))
			{
				continue;
			}
			if (pCadena[i] < '0'|| pCadena[i] > '9')
			{
				retorno = 0; // Falso
				break;
			}
		}
	}
	return retorno;
}


/**
 * \brief Verifica si la cadena ingresada es flotante
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (Verdadero) si la cadena es flotante y 0 (Falso) si no lo es
 */
int esFloat(char* cadena)
{
	int i = 0;
	int retorno = 1;
	int contadorPuntos = 0;

	if (cadena != NULL && strlen(cadena) > 0)
	{
		for (i = 0; cadena[i] != '\0'; i++)
		{
			if (i == 0 && (cadena[i] == '-' || cadena[i] == '+'))
			{
				continue;
			}
			if (cadena[i] < '0' || cadena[i] > '9')
			{
				if (cadena[i] == '.' && contadorPuntos == 0)
				{
					contadorPuntos++;
				}
				else
				{
					retorno = 0;
					break;
				}
			}
		}
	}
	return retorno;
}


/**
 * \brief Verifica si la cadena ingresada es un nombre valido
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (verdadero) si la cadena es valida y 0 (falso) si no lo es
 *
 */
int esNombre(char* cadena, int len)
{
	int i = 0;
	int retorno = 1;

	if (cadena != NULL && len > 0)
	{
		for (i = 0; cadena[i] != '\0' && i < len; i++)
		{
			if ((cadena[i] < 'A' || cadena[i] > 'Z' ) && (cadena[i] < 'a' || cadena[i] > 'z' ) && (cadena[i] != ' ') && (cadena[i] != '-'))
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}
