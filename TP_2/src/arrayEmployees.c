/*
 * arrayEmployees.c
 *
 *  Created on: 24 sep. 2021
 *      Author: Paul
 *
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
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "arrayEmployees.h"
#include "functions.h"

int initEmployees(Employee* list , int lent)
{
	int i;
	int ret=-1;
	if(list!=NULL && lent>0)
	{
		for(i=0;i<lent;i++)
		{
			list[i].isEmpty=EMPTY;
		}
		ret=0;
	}
	return ret;
}
int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector)
{
	int ret=-1;
	int index;
	if(list!=NULL && len>0)
	{

		if(searchEmpty(list, len, &index)==-1)
		{
			printf("error en el tamaño o la lista es NULL.\n");
		}
		else
		{
			if(index!=-1)
			{
				list[index].id=id;
				strcpy(list[index].name,name);
				strcpy(list[index].lastName,lastName);
				list[index].salary=salary;
				list[index].sector=sector;
				list[index].isEmpty=FULL;
				ret=0;
			}
			else
			{
				printf("\nERROR.NO HAY ESPACIO PARA CARGAR MAS EMPLEADOS\n");
			}
		}
	}

	return ret;
}
int requestEmployee(Employee* list, int len,int* id,int* amountEmployee)
{
	int idAct;
	int ret=-1;
	Employee auxEmployee;
	if(list!=NULL && len>0)
	{

		 	idAct=*id;
		 	auxEmployee.id=idAct;
			if(requestNameOrLastName(auxEmployee.name, "Ingrese el Nombre del Empleado: ", "ERROR.El Nombre ingresado no es validoe l maximo de caracteres es 41 y no se permiten signos.\nReingrese el Nombre del empleado: ", MAXCHAR)==-1)
			{
				printf("ERROR.En el puntero o el tamaño enviados a la funcion.\n");
			}
			if(requestNameOrLastName(auxEmployee.lastName, "Ingrese el Apellido del Empleado: ", "ERROR.El Apellido ingresado no es valido el maximo de caracteres es 41 y no se permiten signos.\nReingrese el Apellido del empleado: ", MAXCHAR)==-1)
			{
				printf("ERROR.En el puntero o el tamaño enviados a la funcion.\n");
			}
			if(requestNumberFloat(&auxEmployee.salary, "Ingrese el Salario del Empleado: ", "ERROR.El Numero ingresado debe ser mayor a $25.000 , menor a $800.000 y no puede contener signos o letras\nReingrese el Salario del empleado: ", MINSALARY,MAXSALARY)==-1)
			{
				printf("ERROR.En el puntero o el tamaño enviados a la funcion.\n");
			}
			if(requestNumber(&auxEmployee.sector, "Ingrese el Sector del Empleado: ", "ERROR.El Numero ingresado debe ser mayor a 1 y menor a 10\nReingrese el Salario del empleado: ", SECTORMIN, SECTORMAX)==-1)
			{
				printf("ERROR.En el puntero o el tamaño enviados a la funcion.\n");
			}
			printf("\nEmpleado a cargar:\n\n%-5s %-20s %-20s  %-20s %-20s\n", "ID", "NOMBRE", "APELLIDO", "SALARIO", "SECTOR");
			printEmployee(auxEmployee);

			if(!requestCharacterAnswer("\nIngrese (s) para cargar el empleado: "))
			{
				if(addEmployee(list, len, auxEmployee.id, auxEmployee.name, auxEmployee.lastName, auxEmployee.salary, auxEmployee.sector)==0)
				{
					printf("\nSe Realizo la carga correctamente.\n");
					*id=idAct+1;
					*amountEmployee=*amountEmployee+1;
				}
				else
				{
					printf("ERROR AL CARGAR EMPLEADO.\n");
				}
			}
			else
			{
				printf("\nSe Cancelo la carga del Empleado.\n");
			}



		ret=0;
	}
	return ret;
}
int searchEmpty(Employee* list,int len, int* index)
{
	int i;
	int ret=-1;
	if(list!=NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty==EMPTY)
			{
				*index=i;
				break;
			}
			*index=-1;
		}

		ret=0;
	}
	return ret;
}

void printEmployee(Employee list)
{
	printf("%-5d %-20s %-20s %-20.2f %-25d\n", list.id, list.name, list.lastName ,list.salary, list.sector);
}

int printEmployees(Employee* list, int length)
{
	int ret=-1;
	int i;
	if(list!=NULL && length>0)
	{
		printf("\nLISTA DE EMPLEADOS:\n\n");
		for(i=0;i<length;i++)
		{
			if(list[i].isEmpty==FULL)
			{
				printEmployee(list[i]);
			}
		}
		printf("\n");
		ret=0;
	}
	return ret;
}


int findEmployeeById(Employee* list, int len,int id)
{
	int ret=-1;
	int i;

	if(list!=NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty==FULL)
			{
				if(list[i].id==id)
				{
					ret=i;
				}
			}
		}
	}
	return ret;
}

int adjustEmployee(Employee* list,int len)
{
	int ret=-1;
	int id;
	int option;
	int index;
	Employee auxEmployee;
	if(list!=NULL && len>0)
	{
		printEmployees(list, len);

		if(requestNumber(&id, "Ingrese el ID del empleado a Modificar: ", "ERROR.El Id Ingreado debe estar entre (1000 y 2000).\nReingrese ID del empleado a Modificar: ", MINID, MAXID)==-1)
		{
			printf("ERROR.En el puntero o el tamaño enviados a la funcion.\n");
		}
		index=findEmployeeById(list, len, id);
		if(index!=-1)
		{
			printf("\nEmpleado a modificar:\n\n%-5s %-20s %-20s  %-20s %-5s\n", "ID", "NOMBRE", "APELLIDO", "SALARIO", "SECTOR");
			printEmployee(list[index]);
			do
			{
				auxEmployee=list[index];
				requestNumber(&option,  "\n***********************\n"
										"MODIFICAR\n\n"
										"1.NOMBRE\n"
										"2.APELLIDO\n"
										"3.SALARIO\n"
										"4.SECTOR\n"
										"5.CANCELAR MODIFICACION\n"
										"***********************\n"
										"Ingrese una opcion: ",
										"\n***********************\n"
										"MODIFICAR\n\n"
										"1.NOMBRE\n"
										"2.APELLIDO\n"
										"3.SALARIO\n"
										"4.SECTOR\n"
										"5.ATRAS\n"
										"***********************\n"
										"Opcion invalida, reingrese: ", 1, 5);
				switch(option)
				{
					case 1:
						printf("\nEmpleado a modificar:\n\n%-5s %-20s %-20s  %-20s %-5s\n", "ID", "NOMBRE", "APELLIDO", "SALARIO", "SECTOR");
						printEmployee(list[index]);
						requestNameOrLastName(auxEmployee.name, "Ingrese el Nombre del Empleado: ", "ERROR.El Nombre ingresado no es validoe l maximo de caracteres es 41 y no se permiten signos.\nReingrese el Nombre del empleado: ", MAXCHAR);
						printf("\nEmpleado Luego de la Modificacion:\n\n%-5s %-20s %-20s  %-20s %-5s\n", "ID", "name", "lastName", "salary", "sector");
						printEmployee(auxEmployee);
						if(!requestCharacterAnswer("\nIngrese (s) para modificar el Empleado: "))
						{
							list[index]=auxEmployee;
							printf("\nSe Realizo la Modificacion correctamente.\n");
						}
						else
						{
							printf("\nSe Cancelo la Modicicacion del Nombre.\n");
						}
						break;
					case 2:
						printf("\nEmpleado a modificar:\n\n%-5s %-20s %-20s  %-20s %-5s\n", "ID", "NOMBRE", "APELLIDO", "SALARIO", "SECTOR");
						printEmployee(list[index]);
						requestNameOrLastName(auxEmployee.lastName, "Ingrese el Apellido del Empleado: ", "ERROR.El Apellido ingresado no es valido el maximo de caracteres es 41 y no se permiten signos.\nReingrese el Apellido del empleado: ", MAXCHAR);
						printf("\nEmpleado Luego de la Modificacion:\n\n%-5s %-20s %-20s  %-20s %-5s\n", "ID", "name", "lastName", "salary", "sector");
						printEmployee(auxEmployee);
						if(!requestCharacterAnswer("\nIngrese (s) para modificar el Empleado: "))
						{
							list[index]=auxEmployee;
							printf("Se Realizo la Modificacion correctamente.\n");
						}
						else
						{
							printf("Se Cancelo la Modicicacion del Nombre.\n");
						}
						break;
					case 3:
						printf("\nEmpleado a modificar:\n\n%-5s %-20s %-20s  %-20s %-5s\n", "ID", "NOMBRE", "APELLIDO", "SALARIO", "SECTOR");
						printEmployee(list[index]);
						requestNumberFloat(&auxEmployee.salary, "Ingrese el Salario del Empleado: ", "ERROR.El Numero ingresado debe ser mayor a $25.000 , menor a $800000 y no puede contener signos o letras\nReingrese el Salario del empleado: ", MINSALARY,MAXSALARY);
						printf("\nEmpleado Luego de la Modificacion:\n\n%-5s %-20s %-20s  %-20s %-5s\n",  "ID", "NOMBRE", "APELLIDO", "SALARIO", "SECTOR");
						printEmployee(auxEmployee);
						if(!requestCharacterAnswer("\nIngrese (s) para modificar el Empleado: "))
						{
							list[index]=auxEmployee;
							printf("\nSe Realizo la Modificacion correctamente.\n");
						}
						else
						{
							printf("\nSe Cancelo la Modificacion del Nombre.\n");
						}
						break;
					case 4:
						printf("\nEmpleado a Modificar:\n\n%-5s %-20s %-20s  %-20s %-5s\n",  "ID", "NOMBRE", "APELLIDO", "SALARIO", "SECTOR");
						printEmployee(list[index]);
						requestNumber(&auxEmployee.sector, "Ingrese el Sector del Empleado: ", "ERROR.El Numero ingresado debe ser mayor a 1 y menor a 10\nReingrese el Salario del empleado: ", SECTORMIN, SECTORMAX);
						printf("\nEmpleado Luego de la Modificacion:\n\n%-5s %-20s %-20s  %-20s %-5s\n", "ID", "name", "lastName", "salary", "sector");
						printEmployee(auxEmployee);
						if(!requestCharacterAnswer("\nIngrese (s) para modificar el Empleado: "))
						{
							list[index]=auxEmployee;
							printf("\nSe Realizo la Modificacion correctamente.\n");
						}
						else
						{
							printf("\nSe Cancelo la Modicicacion del Nombre.\n");
						}
						break;
					case 5:
						printf("\nSe cancelo la modificacion.\n");
						break;
				}

			}while(option!=5);
		}
		else
		{
			printf("\nERROR.No se encontro el id del empleado ingresado.\n");
		}
		ret=0;
	}
	return ret;
}
int removeEmployee(Employee* list, int len,int* id)
{
	int ret=-1;
	int idEmployee;
	int index;
	if(list!=NULL && len>0)
	{
		printEmployees(list, len);
		requestNumber(&idEmployee, "Ingrese el ID del empleado a Dar de baja: ", "ERROR.El Id Ingreado debe estar entre (1000 y 2000).\nReingrese ID del empleado a Dar de baja: ", MINID, MAXID);
		index=findEmployeeById(list, len, idEmployee);
		if(index!=-1)
		{
			printf("\nEmpleado a Dar de baja:\n\n%-5s %-20s %-20s  %-20s %-5s\n",  "ID", "NOMBRE", "APELLIDO", "SALARIO", "SECTOR"	);
			printEmployee(list[index]);
			if(!requestCharacterAnswer("\nIngrese (s) para Dar de baja el Empleado: "))
			{
				list[index].isEmpty=EMPTY;
				printf("\nSe Realizo la baja correctamente.\n");
				*id=*id-1;
			}
			else
			{
				printf("\nSe Cancelo la baja del empleado.\n");
			}
		}
		else
		{
			printf("\nERROR.No se encontro el id del empleado ingresado.\n");
		}
		ret=0;
	}
	return ret;
}
int sortEmployees(Employee* list, int len, int order)
{
	int ascOrDes;
	int ret=-1;
	int flagSwap=0;
	int newLimit;
	int i;

	Employee auxEmployee;
	if(list!=NULL && len>0)
	{

		if(order==1)
		{
			ascOrDes=-1;
		}
		else
		{
			ascOrDes=1;
		}
		newLimit=len;
		do
		{
			flagSwap=0;
			for(i=0;i<newLimit;i++)
			{
				if(list[i].isEmpty==FULL && list[i+1].isEmpty==FULL)
				{
					if(strcmp(list[i].lastName,list[i+1].lastName)==0)
					{
						if(list[i].sector>list[i+1].sector)
						{
							auxEmployee=list[i];
							list[i]=list[i+1];
							list[i+1]=auxEmployee;
							flagSwap=1;
						}
					}
					else
					{
						if(strcmp(list[i].lastName,list[i+1].lastName)==ascOrDes)
						{
							auxEmployee=list[i];
							list[i]=list[i+1];
							list[i+1]=auxEmployee;
							flagSwap=1;
						}
					}
				}

			}

			newLimit--;
		}while(flagSwap);

		ret=0;
	}
	return ret;
}
int printSubMenuReport(Employee* list, int len)
{
	int ret=-1;
	int option;
	if(list!=NULL && len>0)
	{
		sortEmployees(list, len, 1);
		do
		{
			requestNumber(&option,  "\n***********************\n"
									"INFORMAR\n\n"
									"1.LISTADO EMPLEADOS\n"
									"2.SALARIOS\n"
									"3.ATRAS\n"
									"***********************\n"
									"Ingrese una opcion: ",

									"\n***********************\n"
									"INFORMAR\n\n"
									"1.LISTADO EMPLEADOS\n"
									"2.SALARIOS\n"
									"3.ATRAS\n"
									"***********************\n"
									"Opcion invalida, reingrese: ", 1, 3);
			switch(option)
			{
				case 1:
					if(printEmployees(list, len))
					{
						printf("ERROR.En el puntero o el tamaño enviados a la funcion.\n");
					}
					systemPause("\nToque cualquier tecla para continuar...");
					break;
				case 2:
					if(averagedSalary(list, len))
					{
						printf("ERROR.En el puntero o el tamaño enviados a la funcion.\n");
					}
					systemPause("\nToque cualquier tecla para continuar...");
					break;
				case 3:
					printf("\nSe volvio al menu anterior.\n");
					break;
			}


		}while(option!=3);
		ret=0;
	}
	return ret;
}

int averagedSalary(Employee* list,int len)
{
	int ret=-1;
	float accumSalary=0;
	int i;
	int countSalary=0;
	int countSalaryUpAveraged=0;
	float result;
	if(list!=NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty==FULL)
			{
				accumSalary=accumSalary+list[i].salary;
				countSalary++;
			}
		}

		divideFloat(&result, accumSalary, countSalary);

		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty==FULL)
			{
				if(list[i].salary>result)
				{
					countSalaryUpAveraged++;
				}
			}
		}
		if(countSalary!=0)
		{

			printf("\nTotal de Salarios: %.2f\n\nPromedio de salarios: %.2f\n\nCantidad de Empleados que superan el Salario Promedio: %d\n\n",accumSalary,result,countSalaryUpAveraged);
		}
		ret=0;
	}
	return ret;
}



