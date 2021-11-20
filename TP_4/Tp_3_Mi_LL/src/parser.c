#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"

/**
 * @fn int parser_EmployeeFromText(FILE*, LinkedList*)
 * @brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * @param pFile recive un puntero a file
 * @param pArrayListEmployee recive un puntero a la lista de empleados cargadas en el ll
 * @return retorna 1 si salio todo mal o el puntero es null o 0 si salio todo bien
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int ret=1;
	char id[10];
	char nombre[21];
	char horasTrabajadas[10];
	char sueldo[20];
	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]",id,nombre,horasTrabajadas,sueldo);
		while(!feof(pFile))
		{
			fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]",id,nombre,horasTrabajadas,sueldo);
			if(feof(pFile))
			{
				break;
			}

			Employee* employee =employee_newParametros(id, nombre, horasTrabajadas,sueldo);
			ll_add(pArrayListEmployee, employee);
		}
		fclose(pFile);
		ret=0;
	}
    return ret;
}

/**
 * @fn int parser_EmployeeFromBinary(FILE*, LinkedList*)
 * @brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * @param pFile recive un puntero a file
 * @param pArrayListEmployee recive un puntero a la lista de empleados cargadas en el ll
 * @return retorna 1 si salio todo mal o el puntero es null o 0 si salio todo bien
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{

	int ret=1;
	Employee* pEmployee=NULL;

	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		while(!feof(pFile))
		{
			pEmployee=employee_new();
			fread(pEmployee, sizeof(Employee), 1, pFile);
			if(feof(pFile))
			{
				break;
			}
			ll_add(pArrayListEmployee, pEmployee);
		}
		pEmployee=NULL;
		fclose(pFile);
		ret=0;
	}

    return ret;
}
