/*
 ============================================================================
 Name        : TP_2.c
 Author      : Paul Mandole
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================

 El sistema deberá tener el siguiente menú de opciones:
	1. ALTAS: Se debe permitir ingresar un empleado calculando automáticamente el número
	de Id. El resto de los campos se le pedirá al usuario.
	2. MODIFICAR: Se ingresará el Número de Id, permitiendo modificar: o Nombre o Apellido
	o Salario o Sector
	3. BAJA: Se ingresará el Número de Id y se eliminará el empleado del sistema.
	4. INFORMAR:
	1. Listado de los empleados ordenados alfabéticamente por Apellido y Sector.
	2. Total y promedio de los salarios, y cuántos empleados superan el salario promedio.
	NOTA: Se deberá realizar el menú de opciones y las validaciones a través de funciones.
	Tener en cuenta que no se podrá ingresar a los casos 2, 3 y 4; sin antes haber realizado la
	carga de algún empleado.
 ============================================================================

 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "arrayEmployees.h"
#include "functions.h"
#define LEN 2
#define MAXOPTION 5
#define MINOPTION 1


int main(void) {

	setbuf(stdout,NULL);

	Employee list[LEN];
	int option;
	int lastId=1000;
	int amountEmployee=0;
	initEmployees(list, LEN);
	do
	{

		requestNumber(&option,  "***********************\n"
								"BIENVENIDO\n\n"
								"1.ALTA DE EMPLEADO\n"
								"2.MODIFICAR EMPLEADO\n"
								"3.BAJA DE EMPLEADO\n"
								"4.INFORMAR\n"
								"5.SALIR DEL PROGRAMA\n"
								"***********************\n"
								"Ingrese una opcion: ",

								"\n***********************\n"
								"BIENVENIDO\n\n"
								"1.ALTA DE EMPLEADO\n"
								"2.MODIFICAR EMPLEADO\n"
								"3.BAJA DE EMPLEADO\n"
								"4.INFORMAR\n"
								"5.SALIR DEL PROGRAMA\n"
								"***********************\n"
								"Opcion invalida, reingrese: ", MINOPTION, MAXOPTION);

		printf("\n");
		switch(option)
		{
			case 1:
				if(requestEmployee(list, LEN, &lastId,&amountEmployee)==-1)
				{
					printf("error en el tamaño o la lista es NULL.\n");
				}
				printf("\n");
				systemPause("\nToque cualquier tecla para continuar...");
				break;
			case 2:
				if(amountEmployee>0)
				{
					if(adjustEmployee(list, LEN)==-1)
					{
						printf("error en el tamaño o la lista es NULL.\n");
					}
				}
				else
				{
					printf("Se debe cargar un empleado antes de poder modificar.\n");
				}
				systemPause("Toque cualquier tecla para continuar...");
				break;
			case 3:
				if(amountEmployee>0)
				{
					if(removeEmployee(list, LEN,&amountEmployee)==-1)
					{
						printf("error en el tamaño o la lista es NULL.\n");
					}
				}
				else
				{
					printf("Se debe cargar un empleado antes de poder dar de baja.\n");
				}
				systemPause("\nToque cualquier tecla para continuar...");
				break;
			case 4:
				if(amountEmployee>0)
				{
					if(printSubMenuReport(list, LEN)==-1)
					{
						printf("error en el tamaño o la lista es NULL.\n");
					}
				}
				else
				{
					printf("Se debe cargar un empleado antes de poder informar.\n");
				}
				systemPause("\nToque cualquier tecla para continuar...");
				break;
			case 5:
				printf("Gracias por utilizar el Programeitor 9000\n\n");
				break;
		}

	}while(option!=5);


	return EXIT_SUCCESS;
}
