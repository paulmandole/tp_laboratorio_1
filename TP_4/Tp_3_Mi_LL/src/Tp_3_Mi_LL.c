#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "functions.h"
/*
****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
	Ejecución 1 - Usuario elegir opción 1: NO puede volver a elegir opción 1 ni 2. Puede elejir opción 8 y también puede elegir opción 9
	Ejecución 2 - Usuario elegir opción 2: NO puede volver a elegir opción 1 ni 2. Puede elegir opción 8 y también puede elegir opción 9
*****************************************************
*/


int main()
{
	setbuf(stdout,NULL);



    int option = 0;
    int lastId;
    int flagLoadTxt=0;
    int flagLoadBn=0;

    employee_getItBackLastId("src\\lastId.csv", &lastId);
    LinkedList* listaEmpleados = ll_newLinkedList();

    do{

    	requestNumber(&option,  "**************************************\n"
								"MENU\n"
								"**************************************\n"
								"1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n"
								"2. Cargar los datos de los empleados desde el archivo data.csv (modo binario)\n"
								"3. Alta de empleado\n"
								"4. Modificar datos de empleado\n"
								"5. Baja de empleado\n"
								"6. Listar empleados\n"
								"7. Ordenar empleados\n"
								"8. Guardar los datos de los empleados en el archivo data.csv (modo texto)\n"
								"9. Guardar los datos de los empleados en el archivo data.csv (modo binario)\n"
								"10. Salir\n"
								"**************************************\n"
								"Ingrese una opcion: ",

								"**************************************\n"
								"MENU\n"
								"**************************************\n"
								"1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n"
								"2. Cargar los datos de los empleados desde el archivo data.csv (modo binario)\n"
								"3. Alta de empleado\n"
								"4. Modificar datos de empleado\n"
								"5. Baja de empleado\n"
								"6. Listar empleados\n"
								"7. Ordenar empleados\n"
								"8. Guardar los datos de los empleados en el archivo data.csv (modo texto)\n"
								"9. Guardar los datos de los empleados en el archivo data.csv (modo binario)\n"
								"10. Salir\n"
								"**************************************\n"
								"Opcion invalida, reingrese: ", 1, 10);

        switch(option)
        {
            case 1:
            	if(!flagLoadBn)
            	{
            		if(!flagLoadTxt)
            		{
            			if(!controller_loadFromText("src\\data.csv",listaEmpleados))
            			{
            				printf("\nEl archivo se cargo con exito.\n");
            				flagLoadTxt=1;
            			}
            			else
            			{
            				printf("\nERROR al cargar el archivo\n");
            				flagLoadTxt=0;
            			}
            		}
            		else
            		{
            			printf("\nERROR.Ya se cargo el archivo.\n");
            		}
            	}
            	else
            	{
            		printf("\nERROR.Ya se cargo los datos en binario,para cargar los datos del archivo de texto debe reiniciar el programa.\n");
            	}
                systemPause("\nToque cualquier tecla para continuar...\n");
                break;
            case 2:
            	if(!flagLoadTxt)
            	{
            		if(!flagLoadBn)
            		{
            			if(!controller_loadFromBinary("src\\dataBinary.csv", listaEmpleados))
            			{
            				printf("\nEl archivo se cargo con exito.\n");
            				flagLoadBn=1;
            			}
            			else
            			{
            				printf("\nERROR al cargar el archivo\n");
            				flagLoadBn=0;
            			}
            		}
            		else
            		{
            			printf("\nERROR.Ya se cargo el archivo.\n");
            		}
            	}
            	else
            	{
            		printf("\nERROR.Ya se cargo los datos del archivo en modo txt ,para cargar los datos del archivo de binario debe reiniciar el programa.\n");
            	}
            	systemPause("\nToque cualquier tecla para continuar...");
                break;
            case 3:
            	if(flagLoadTxt || flagLoadBn)
            	{
            		controller_addEmployee(listaEmpleados,&lastId);
            		/**Agregue un id para poder hacerlo auto incremental y
            		en el main tener el ultimo id se guardara cuando termina el programa si se guardan los datos**/
            	}
            	else
            	{
            		printf("\nERROR.Debe cargar una lista desde el archivo antes de dar de alta un Empleado.\n");
            	}
            	systemPause("\nToque cualquier tecla para continuar...");
                break;
            case 4:
            	if(flagLoadTxt || flagLoadBn)
            	{
            		controller_editEmployee(listaEmpleados);
            	}
            	else
            	{
            		printf("\nERROR.Debe cargar una lista desde un archivo antes de modificar un Empleado.\n");
            	}
            	systemPause("\nToque cualquier tecla para continuar...");
                break;
            case 5:
            	if(flagLoadTxt || flagLoadBn)
            	{
            		controller_removeEmployee(listaEmpleados);
            	}
            	else
            	{
            		printf("\nERROR.Debe cargar una lista desde un archivo antes de dar de baja un Empleado.\n");
            	}
            	systemPause("\nToque cualquier tecla para continuar...");
                break;
            case 6:
            	if(flagLoadBn || flagLoadTxt)
            	{
            		controller_ListEmployee(listaEmpleados);
            	}
            	else
            	{
            		printf("\nERROR.Debe cargar una lista desde un archivo antes de listar los Empleados.\n");
            	}
            	systemPause("\nToque cualquier tecla para continuar...");
                break;
            case 7:
            	if(flagLoadBn || flagLoadTxt)
				{
            		controller_sortEmployee(listaEmpleados);
				}
				else
				{
					printf("\nERROR.Debe cargar una lista desde un archivo antes de ordenar los Empleados.\n");
				}
				systemPause("\nToque cualquier tecla para continuar...");
                break;
            case 8:
            	if(flagLoadBn || flagLoadTxt)
            	{
            		controller_saveAsText("src\\data.csv", listaEmpleados);
            		employee_saveLastId("src\\lastId.csv", &lastId);
					printf("Se guardo el archivo con Exito.\n");
            	}
            	else
            	{
            		printf("\nERROR.Debe cargar una lista desde un archivo antes de guardar los datos.\n");
            	}
            	systemPause("\nToque cualquier tecla para continuar...");
                break;
            case 9:
            	if(flagLoadBn || flagLoadTxt)
            	{
            		controller_saveAsBinary("src\\dataBinary.csv", listaEmpleados);
					employee_saveLastId("src\\lastId.csv", &lastId);
					printf("Se guardo el archivo con Exito.\n");
            	}
            	else
            	{
            		printf("\nERROR.Debe cargar una lista desde un archivo antes de guardar los datos.\n");
            	}
				systemPause("\nToque cualquier tecla para continuar...");
                break;
            case 10:
            	ll_deleteLinkedList(listaEmpleados);
                printf("\n\nGracias por usar el programeitor 9000!!!");
                break;

        }
    }while(option != 10);

    return 0;
}

