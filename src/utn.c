/*
 * utn.c
 * Author: Gabriel Servia
 */
#include "utn.h"

static int getString(char* pCadena, int len);
static int getText(char* pResultado, int len);
static int getInt(int* pResultado);
static int getFloat(float* pResultado);
static int getNombre(char* pResultado, int len);


/**
 * \brief Solicita un texto al usuario
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param len Es la longitud del array resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param reintentos Cantidad de reintentos
 * \return Retorna 0 si se obtuvo exito y -1 si da Error
 */
int utn_getText(char* pResultado, int len, char* mensaje, char* mensajeError, int reintentos)
{
	char bufferString[4096];
	int retorno = -1;

	while (reintentos>=0)
	{
		reintentos--;
		printf("%s", mensaje);
		if (getText(bufferString, sizeof(bufferString)) == 0 && strnlen(bufferString, sizeof(bufferString)) < len )
		{
			strncpy(pResultado, bufferString, len);
			retorno = 0;
			break;
		}
		printf("%s",mensajeError);
	}
	return retorno;
}


/**
 * \brief Solicita un numero al usuario, luego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param minimo Es el numero minimo a ser aceptado
 * \param maximo Es el numero maximo a ser aceptado
 * \return Retorna 0 si se obtuvo el numero entero y -1 si da error
 */
int utn_getInt(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno = -1;
	int bufferInt;

	do
	{
		printf("%s", mensaje);
		if (getInt(&bufferInt) == 0 && bufferInt >= minimo && bufferInt <= maximo)
		{
			retorno = 0;
			*pResultado = bufferInt;
			break;
		}
		printf("%s",mensajeError);
		reintentos--;
	}while (reintentos >= 0);

	return retorno;
}


/**
 * \brief Solicita un numero flotante al usuario, luego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param minimo Es el numero minimo a ser aceptado
 * \param maximo Es el numero maximo a ser aceptado
 * \return Retorna 0 si se obtuvo el numero flotante y -1 si da Error
 */
int utn_getFloat(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos)
{
	float bufferFloat;
	int retorno = -1;

	while (reintentos >= 0)
	{
		reintentos--;
		printf("%s",mensaje);
		if (getFloat(&bufferFloat) == 0)
		{
			if(bufferFloat >= minimo && bufferFloat <= maximo)
			{
				*pResultado = bufferFloat;
				retorno = 0;
				break;
			}
		}
		printf("%s",mensajeError);
	}
	return retorno;
}


/**
 * \brief Solicita un nombre al usuario, luego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param len Es la longitud del array resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param reintentos Cantidad de reintentos
 * \return Retorna 0 si se obtuvo el nombre y -1 si no
 *
 */
int utn_getName(char* pResultado, int len,char* mensaje, char* mensajeError, int reintentos)
{
	char bufferString[4096];
	int retorno = -1;

	while (reintentos >= 0)
	{
		reintentos--;
		printf("%s", mensaje);

		if (getNombre(bufferString, sizeof(bufferString)) == 0 && strnlen(bufferString, sizeof(bufferString)) < len)
		{
			strncpy(pResultado, bufferString, len);
			retorno = 0;
			break;
		}
		printf("%s", mensajeError);
	}
	return retorno;
}


/**
 * \brief Solicita un string al usuario, lo verifica, y devuelve
 * \param pCadena Puntero al espacio de memoria donde se copiara la cadena obtenida
 * \param len Define la longitud de la cadena
 * \return Retorna 0 si tuvo Exito y obtiene una cadena. O -1 si resulta en Error
 */
static int getString(char* pCadena, int len)
{
	int retorno = -1;
	char bufferString[4096];

	if (pCadena != NULL && len > 0)
	{
		fflush(stdin);

		if (fgets(bufferString, sizeof(bufferString), stdin) != NULL)
		{
			if (bufferString[strnlen(bufferString, sizeof(bufferString)) -1] == '\n')
			{
				bufferString[strnlen(bufferString, sizeof(bufferString)) -1] = '\0';
			}
			if (strnlen(bufferString, sizeof(bufferString)) <= len)
			{
				strncpy(pCadena, bufferString, len);
				retorno =0 ;
			}
		}
	}
	return retorno;
}


/**
 * \brief Obtiene un string valido como texto
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param len Define la longitud de la cadena
 * \return Retorna 0 (Exito) si se obtiene un numero flotante y -1 si da Error
 */
static int getText(char* pResultado, int len)
{
    int retorno = -1;
    char buffer[4096];

    if (pResultado != NULL)
    {
    	if (getString(buffer, sizeof(buffer)) == 0 && esTexto(buffer, sizeof(buffer)) && strnlen(buffer, sizeof(buffer)) < len)
    	{
    		strncpy(pResultado, buffer, len);
			retorno = 0;
		}
    }
    return retorno;
}


/**
 * \brief Solicita un numero entero
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 si tuvo Exito y obtiene una cadena. O -1 si resulta en Error
 */
static int getInt(int* pResultado)
{
    int retorno = -1;
    char bufferString[50];

    if (pResultado != NULL && getString(bufferString, sizeof(bufferString)) == 0 && esNumerica(bufferString, sizeof(bufferString)))
	{
		retorno = 0;
		*pResultado = atoi(bufferString);
	}
    return retorno;
}


/**
 * \brief Verifica si la cadena ingresada es flot
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (Exito) si se obtiene un numero flotante y -1 si da Error
 */
static int getFloat(float* pResultado)
{
    int retorno=-1;
    char buffer[64];

    if (pResultado != NULL)
    {
    	if (getString(buffer,sizeof(buffer)) == 0 && esFloat(buffer))
    	{
			*pResultado = atof(buffer);
			retorno = 0;
		}
    }
    return retorno;
}


/**
 * \brief Obtiene un string valido como nombre
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero flotante y -1 (ERROR) si no
 *
 */
static int getNombre(char* pResultado, int len)
{
    int retorno = -1;
    char buffer[4096];

    if (pResultado != NULL)
    {
    	if ((getString(buffer, sizeof(buffer)) == 0) && (esNombre(buffer, sizeof(buffer)) == 1) && (strnlen(buffer, sizeof(buffer)) < len))
    	{
    		strncpy(pResultado, buffer, len);
			retorno = 0;
		}
    }
    return retorno;
}
