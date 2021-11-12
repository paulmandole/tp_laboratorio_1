#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "functions.h"
#include "controller.h"



/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char* recive un puntero a una cadena de caracterres con el nombre dl archivo
 * \param pArrayListEmployee LinkedList* recive un puntero con el ll
 * \return int ret 0 si sale todo bien y retorna 1 si sale
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int ret=1;
	FILE* pFile= fopen(path,"r");
	if(path!=NULL && pArrayListEmployee!=NULL)
	{
		ret=parser_EmployeeFromText(pFile, pArrayListEmployee);
		fclose(pFile);
		pFile=NULL;
	}

    return ret;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char* recive un puntero a una cadena de caracterres con el nombre dl archivo
 * \param pArrayListEmployee LinkedList* recive un puntero con el ll
 * \return int ret 0 si sale todo bien y retorna 1 si sale
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	FILE* pFile= fopen(path,"rb");
	int ret=1;
	if(path!=NULL && pArrayListEmployee != NULL)
	{
		ret=parser_EmployeeFromBinary(pFile, pArrayListEmployee);
		fclose(pFile);
		pFile=NULL;
	}
    return ret;
}

/**
 * @fn int controller_addEmployee(LinkedList*, int*)
 * @brief agrega un empleado nuevo al ll
 *
 * @param pArrayListEmployee recive un puntero a la lista de empleados cargada en el ll
 * @param lastId recive el ultimo id guardado en el main para que sea auto incremental esto lo agregue par que se guarde el id siempre
 * @return retorna retorana 1 si sale todo mal y 0 si resulta todo bien
 */
int controller_addEmployee(LinkedList* pArrayListEmployee,int* lastId)
{
	int ret=1;
	int ultimoId;
	Employee* pEmpleado = employee_new();
	if(pArrayListEmployee!=NULL)
	{
		ultimoId=*lastId+1;
		pEmpleado->id=ultimoId;
		requestNameOrLastName(pEmpleado->nombre, "Ingrese el Nombre del Empleado: ", "Error.El Nombre ingresado no puede contener numeros o signos.\nReingrese Nombre del Empleado: ", 127);
		requestNumber(&(pEmpleado->horasTrabajadas), "Ingrese las horas trabajadas del Empleado: ", "Error.Las horas trabajadas ingresadas no puede contener letras o signos, y el rango es (1 a 20000).\nReingrese horas trabajadas del Empleado: ", 1, 2000);
		requestNumber(&(pEmpleado->sueldo), "Ingrese el Sueldo del Empleado: ", "Error.EL sueldo ingresado no puede contener letas o numeros y el rango es (10000 a 1000000).\nReingrese el sueldo del Empleado: ", 10000, 1000000);
		printf("%-5s %-20s %-10s %-10s\n\n","ID","NOMBRE","HORAS","SUELDO");
		printEmployee(pEmpleado);

		if(!requestCharacterAnswer("\n\nIngrese (s) para cargar el empleado: "))
		{
			ll_add(pArrayListEmployee,pEmpleado);
			*lastId=ultimoId;
			printf("\nSe Realizo la carga correctamente.\n");
		}
		else
		{
			printf("\nSe cancelo la carga del Empleado.\n");
		}
		ret=0;
	}
    return ret;
}

/**
 * @fn int controller_editEmployee(LinkedList*)
 * @brief modificas los datos de un empleado
 *
 * @param pArrayListEmployee recive la lista de empleados cargada en el ll
 * @return retornar 1 si salio todo bien o 0 si salio todo mal o el puntero es null
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int ret=1;
	Employee* pEmployee=NULL;
	int idEmployee;
	int len;
	int indexEncontrado=-1;

	if(pArrayListEmployee!=NULL)
	{
		len=ll_len(pArrayListEmployee);
		controller_ListEmployee(pArrayListEmployee);
		systemPause("\nToque cualquier tecla para continuar...\n");
		requestNumber(&idEmployee, "Ingrese el ID del Empleado a modificar: ", "ERROR.El ID ingresado no puede contener signos y el rango es entre (1 y 20000).\nReingrese el ID del Empleado a modificar: ", 1, 20000);
		for(int i=0;i<len;i++)
		{
			pEmployee=(Employee*)ll_get(pArrayListEmployee, i);
			if(pEmployee->id==idEmployee)
			{
				indexEncontrado=i;
				break;
			}
		}
		if(indexEncontrado!=-1)
		{
			employee_menuModify(pArrayListEmployee, pEmployee);
		}
		else
		{
			printf("\nERROR.EL Id ingresado no encontrado.\n");
		}
		ret=0;
	}
    return ret;
}

/**
 * @fn int controller_removeEmployee(LinkedList*)
 * @brief remueve un empleado
 *
 * @param pArrayListEmployee pArrayListEmployee recive la lista de empleados cargada en el ll
 * @return retornar 1 si salio todo bien o 0 si salio todo mal o el puntero es null
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int ret=1;
	int idEmpleado;
	int len;
	int indexEncontrado=-1;
	Employee* pEmployee=NULL;

	if(pArrayListEmployee!=NULL)
	{
		controller_ListEmployee(pArrayListEmployee);
		systemPause("\nToque cualquier tecla para continuar...");

		requestNumber(&idEmpleado, "Ingrese el ID del empleado a dar de baja:  ", "Error.El ID no puede contener signos y debe estar en el rango entre(1 y 20000).\nReingrese ID del empleado a dar de baja: ", 1, 20000);
		len=ll_len(pArrayListEmployee);
		for(int i=0;i<len;i++)
		{
			pEmployee=(Employee*)ll_get(pArrayListEmployee, i);
			if(pEmployee->id==idEmpleado)
			{
				indexEncontrado=i;
				break;
			}
		}
		if(indexEncontrado!=-1)
		{
			printf("%-5s %-20s %-10s %-10s\n\n","ID","NOMBRE","HORAS TRABAJADAS","SUELDO");
			printEmployee(pEmployee);
			if(!requestCharacterAnswer("\n\nIngrese (s) para dar de baja el empleado: "))
			{
				ll_remove(pArrayListEmployee, indexEncontrado);
				pEmployee=NULL;
				printf("\nSe Realizo Baja correctamente.\n");
			}
			else
			{
				printf("\nSe cancelo la Baja del Empleado.\n");
			}
		}
		else
		{
			printf("\nERROR. ID no encontrado.");
		}
		ret=0;
	}
    return ret;
}

/**
 * @fn int controller_ListEmployee(LinkedList*)
 * @brief lista todos los empleados cargados
 *
 * @param pArrayListEmployee recive la lista de empleados cargada en el ll
 * @return retornar 1 si salio todo bien o 0 si salio todo mal o el puntero es null
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int ret=1;
	Employee* pEmployee=NULL;
	int len;
	if(pArrayListEmployee != NULL)
	{
		len=ll_len(pArrayListEmployee);
		printf("\n%-5s %-20s %-10s %-10s\n\n","ID","NOMBRE","HORAS","SUELDO");
		for(int i=0;i<len;i++)
		{
			pEmployee=ll_get(pArrayListEmployee, i);
			printEmployee(pEmployee);
		}
		ret=0;
	}
    return ret;
}

/**
 * @fn int controller_sortEmployee(LinkedList*)
 * @brief ordena los empleados llama a un submenu ordenar
 *
 * @param pArrayListEmployee recive un puntero a la lista de empleados cargada en el ll
 * @return retorna 1 si el puntero es null o 0 si no lo es
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int ret=1;

	if(pArrayListEmployee!=NULL)
	{
		employee_menuSort(pArrayListEmployee);
		ret=0;
	}
    return ret;
}

/**
 * @fn int controller_saveAsText(char*, LinkedList*)
 * @brief guarda en el archivo de texto
 *
 * @param path recive un puntero a una cadena con el nombre del archivo
 * @param pArrayListEmployee recive un puntero a la lista de empleados cargada en el ll
 * @return retorna 1 si el puntero es null o 0 si sale todo bien
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int ret=1;
	int len;
	Employee* auxEmployee=NULL;

	FILE* pFile= fopen(path,"w");

	if(path!=NULL && pArrayListEmployee!=NULL)
	{
		len=ll_len(pArrayListEmployee);
		if(pFile!=NULL)
		{
			fprintf(pFile, "%s", "id,nombre,horas trabajadas,sueldo\n");
			for(int i=0;i<len;i++)
			{
				auxEmployee=(Employee*)ll_get(pArrayListEmployee, i);
				fprintf(pFile, "%d,%s,%d,%d\n", auxEmployee->id,auxEmployee->nombre,auxEmployee->horasTrabajadas,auxEmployee->sueldo);
			}

			fclose(pFile);
			pFile=NULL;
			auxEmployee=NULL;
		}
		else
		{
			printf("Error.Archivo no creado");
		}

		ret=0;
	}

    return ret;
}

/**
 * @fn int controller_saveAsBinary(char*, LinkedList*)
 * @brief guarda el archivo en modo binario
 *
 * @param path recive un puntero a una cadena con el nombre del archivo
 * @param pArrayListEmployee recive un puntero a la lista de empleados cargada en el ll
 * @return retorna 1 si el puntero es null o 0 si sale todo bien
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int ret=1;
	int len;
	Employee* pEmployee=NULL;

	if(path!=NULL && pArrayListEmployee!=NULL)
	{
		FILE* pFile=fopen(path,"wb");
		if(pFile!=NULL)
		{
			len=ll_len(pArrayListEmployee);
			for(int i=0;i<len;i++)
			{
				pEmployee=(Employee*)ll_get(pArrayListEmployee, i);
				fwrite(pEmployee, sizeof(Employee), 1, pFile);
			}
		}
		fclose(pFile);
		pFile=NULL;

		ret=0;
	}
    return ret;
}

