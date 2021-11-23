/*
 ============================================================================
 Project     : Segundo_Parcial_Labo_1
 Author      : Gabriel Servia
 Division    : 1° H
 University  : UTN FRA
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "input_validation.h"
#include "menu.h"
#include "LinkedList.h"
#include "Controller.h"
#include "ListaJuego.h"

/**************************************************************************************
    Menu:
     1. LEER ARCADES DESDE ARCHIVO CSV
     	Se lee de archivo arcades.csv provisto, la lista de arcades del sistema, y se cargan en una LinkedLIst.
     2. INCORPORAR ARCADE
     	Se da de alta un arcade con la nacionalidad, tipo de sonido, cantidad de jugadores, capacidad máxima de
	 	fichas, Nombre del salón al que pertenece y nombre del juego que contiene (hasta 63 caracteres).
	 	Se generará un ID único para gestionar los ARCADE. Actualizar el archivo CSV con el arcade agregado.
     3. MODIFICAR ARCADE
     	Se imprime la lista de arcades con los ID y datos que lo componen.
	 	Se pide que se ingrese un ID y se pueda modificar los campos cantidad de jugadores o juego que contiene.
	 	Al elegir modificar el juego que contiene este arcade, mostrar en un listado los nombres de los juegos ya
	 	cargados en el sistema y se permitirá ingresar un texto con el nombre del nuevo juego. Actualizar el
	 	archivo CSV con el arcade modificado.
     4. ELIMINAR ARCADE
     	Se imprime la lista de arcades con sus ID y datos que lo componen, junto con la información del salón y el
	 	juego que contiene.
	 	Se ingresa un ID y previo a dar de baja se deberá solicitar confirmación, imprimiendo el arcade a dar de baja y
	 	confirmando si está seguro dar de baja esté mismo. Actualizar el archivo CSV con el arcade aeliminado.
     5. IMPRIMIR ARCADES ORDENADOS POR NOMBRE DE JUEGO
     	Se imprime la lista de arcades con ID, y sus datos.

     6. GENERAR ARCHIVO CON JUEGOS
     	Se generará un archivo .txt con los nombres de los juegos (uno por linea) sin repetir.
     7. GENERAR UN ARCHIVO CON ARCADES “Multijugador” (MAS DE 1 JUGADOR)
     	Se generará un archivo “multijugador.csv” con el mismo formato que arcades.csv (incluida la cabecera), que
		contenga solo los arcades que tengan mas de 1 jugador.
     8. ACTUALIZAR CANTIDAD DE FICHAS
     	La empresa compró una actualizacion para que los arcades soporten el doble de fichas, por lo que debe
		actualizarse el valor de fichas en el archivo. Al elegir esta opcion, se duplicará el valor de cantidad de fichas de todos
		los arcades.
    10. GUARDAR INFORMACION Y SALIR
**************************************************************************************/

int main(void) {

	setbuf(stdout, NULL);

	LinkedList* listArcades = ll_newLinkedList();
	LinkedList* listJuegos = ll_newLinkedList();

	int flagContinue;
	int menuOptionSelected;
	int flagLoadFileTxt;
	int flagExit;

	flagContinue = 0;
	flagLoadFileTxt = -1;
	flagExit = -1;

	do {
		menuOptionSelected = menu();
		switch (menuOptionSelected)
		{
			case 1:
				if (flagLoadFileTxt == -1)
				{
	            	if (controller_loadFromText("arcades.csv", listArcades) == 0)
	            	{
	            		printf("\n=== Carga de archivo satisfatoria ===\n");
	            		flagLoadFileTxt = 0;
	            	}
	            	else
	            	{
	            		printf("\n=== Error al cargar archivo ===\n");
	            	}
				}
				else
				{
					printf("\n=== El archivo ya fue cargado en sistema ===\n");
				}
				break;

			case 2:
				if (flagLoadFileTxt == 0)
				{
	            	if (controller_addArcade(listArcades) == 0)
	                {
	                	printf("\n=== Alta de arcade satisfatoria ===\n");

	                }
	                else
	                {
	                	printf("\n=== Error al dar de alta ===\n");
	                }
				}
				else
				{
					printf("\n=== Realizar lectura de archivo en sistema. Seleccione la opcion 1  ===\n");
				}
				break;

			case 3:
				if (flagLoadFileTxt == 0)
				{
					if (controller_editArcade(listArcades, listJuegos) == 0)
		            {
		                printf("\n=== Modificacion de arcade satisfatoria ===\n");
		            }
		            else
		            {
		                printf("\n=== Error al modificar arcade ===\n");
		            }
				}
				else
				{
					printf("\n=== Realizar lectura de archivo en sistema. Seleccione la opcion 1 ===\n");
				}
				break;

			case 4:
				if (flagLoadFileTxt == 0)
				{
                	if (controller_removeArcade(listArcades) == 0)
                	{
                		printf("\n=== Baja de arcade satisfatoria ===\n");
                	}
                	else
                	{
                		printf("\n=== Error al dar de baja al arcade ===\n");
                	}
				}
				else
				{
					printf("\n=== Realizar lectura de archivo en sistema. Seleccione la opcion 1 ===\n");
				}
				break;

			case 5:
            	if (flagLoadFileTxt == 0)
            	{
            		if (controller_sortArcade(listArcades) == 0)
            		{
                    	if (controller_ListArcade(listArcades) == 0)
                    	{
                    		printf("\n=== Listado de arcades satisfactorio ===\n");
                    	}
                    	else
                    	{
                    		printf("\n=== Algo salio mal. No es posible listar los arcades ===\n");
                    	}
            		}
                	else
                	{
                		printf("\n=== Algo salio mal. No es posible ordenar los arcades ===\n");
                	}
            	}
            	else
            	{
            		printf("\n=== Realizar lectura de archivo en sistema. Seleccione la opcion 1 ===\n");
            	}
				break;

			case 6:
				if (flagLoadFileTxt == 0)
				{
					if (listaJuego_createGamesFile(listArcades, listJuegos) == 0)
					{
						if (listaJuego_saveGamesFile("juegos.txt", listJuegos) == 0)
						{
							printf("\n=== Archivo con lista de juegos guardado con exito ===\n");;
						}
	                	else
	                	{
	                		printf("\n=== Algo salio mal. No es posible guardar la lista de juegos ===\n");
	                	}
					}
                	else
                	{
                		printf("\n=== Algo salio mal. No es posible crear la lista de juegos ===\n");
                	}
				}
				else
				{
					printf("\n=== Realizar lectura de archivo en sistema. Seleccione la opcion 1 ===\n");
				}
				break;

			case 7:
				if (flagLoadFileTxt == 0)
				{
					LinkedList* listaMultijugador = ll_newLinkedList();
					listaMultijugador = ll_filter(listArcades, arcade_compareMultijugador);
					controller_saveAsText("multijugador.csv", listaMultijugador);
					ll_deleteLinkedList(listaMultijugador);
					printf("\n=== Archivo con juegos multijugador creado con exito ===\n");
				}
				else
				{
					printf("\n=== Realizar lectura de archivo en sistema. Seleccione la opcion 1 ===\n");
				}
				break;

			case 8:
				if (flagLoadFileTxt == 0)
				{
					if (ll_map(listArcades, doubleFichasMax) == 0)
					{
						printf("\n=== Se duplicaron la cantidad de fichas de todos los arcades con exito ===\n");
					}
				}
				else
				{
					printf("\n=== Realizar lectura de archivo en sistema. Seleccione la opcion 1 ===\n");
				}
				break;

			case 9:
				if (flagLoadFileTxt == 0)
				{
            		printf("\n¿Estas seguro que deseas guardar los cambios y salir?\n 1. Si\n 2. No\n");
            		if (utn_getInt(&flagExit, "Ingrese una opcion: ", "Error: comando no valido\n", 1, 2, 0) == 0)
            		{
            			switch (flagExit)
            			{
            				case 1:
            					printf("\nSaliendo...\n");
            	            	if (controller_saveAsText("arcades.csv", listArcades) == 0)
            	            	{
            	            		printf("\n=== ARCHIVO ACTUALIZADO | PROGRAMA FINALIZADO ===\n");
            	            		flagContinue = 1;
            	            		ll_deleteLinkedList(listArcades);
            	            	}
            	            	else
            	            	{
            	            		printf("\n=== Error al guardar archivo ===\n");
            	            	}

            					break;
            				case 2:
            					printf("\nRegreso al menu principal...\n");
            					flagContinue = 0;
            					break;
            			}
            		}
				}
				else
				{
					printf("\n=== Realizar lectura de archivo en sistema. Seleccione la opcion 1 ===\n");
				}
				break;

			default:
				printf("Elija una opcion entre 1 y 9. Vuelva intentar.\n");
				break;
		}
	} while (flagContinue == 0);

	return EXIT_SUCCESS;
}
