#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"

#include "functions.h"

int employee_menuModify(LinkedList* pArrayListemployee,Employee* pEmployee)
{
	int ret=1;
	int option;
	int horas;
	char nombre[128];
	int sueldo;
	if(pArrayListemployee!=NULL)
	{
		printf("%-5s %-20s %-10s %-10s\n\n","ID","NOMBRE","HORAS TRABAJADAS","SUELDO");
		printEmployee(pEmployee);

		do
		{
			requestNumber(&option,
									 "\n***************************\n"
									 "MODIFICAR\n"
									 "\n***************************\n"
									 "1. Modificar Nombre\n"
									 "2. Modificar HorasTrabajadas\n"
									 "3. Modificar Sueldo\n"
									 "4. Atras\n"
									 "Ingrese opcion: " ,
									 "\n***************************\n"
									 "MODIFICAR\n"
									 "\n***************************\n"
									 "1. Modificar Nombre\n"
									 "2. Modificar HorasTrabajadas\n"
									 "3. Modificar Sueldo\n"
									 "4. Atras\n"
									 "Opcion ingresada invalida.\nReingrese opcion: " , 1, 4);
			switch(option)
			{
				case 1:
					printf("%-5s %-20s %-10s %-10s\n\n","ID","NOMBRE","HORAS","SUELDO");
					printEmployee(pEmployee);
					requestNameOrLastName(nombre, "Ingrese el nombre a modificar: ", "Error.El nombre ungresado no puede contener signos y como maximo 128 caracteres.\nReingrese nombre a modificar: ", 128);
					printf("Empleado luego de la modificacion:\n\n");
					printf("%-5s %-20s %-10s %-10s\n\n","ID","NOMBRE","HORAS","SUELDO");
					printf("%-5d %-20s %-10d %-10d ",pEmployee->id,nombre,pEmployee->horasTrabajadas,pEmployee->sueldo);
					if(!requestCharacterAnswer("\n\nIngrese (s) para modificar el empleado: "))
					{
						employee_setNombre(pEmployee, nombre);
						printf("\nSe Realizo la modificacion correctamente.\n\n");
						systemPause("\nToque cualquier tecla para continuar...\n");
					}
					else
					{
						printf("\nSe cancelo la modificacion del Empleado.\n\n");
						systemPause("\nToque cualquier tecla para continuar...\n");
					}
					break;
				case 2:
					printf("%-5s %-20s %-10s %-10s\n\n","ID","NOMBRE","HORAS","SUELDO");
					printEmployee(pEmployee);
					requestNumber(&horas,"Ingrese las horas trabajadas del Empleado: " ,"Error.Las horas trabajadas ingresadas no puede contener letras o signos, y el rango es (1 a 2000).\nReingrese horas trabajadas del Empleado: ", 1, 2000);
					printf("Empleado luego de la modificacion:\n\n");
					printf("%-5s %-20s %-10s %-10s\n\n","ID","NOMBRE","HORAS","SUELDO");
					printf("%-5d %-20s %-10d %-10d ",pEmployee->id,pEmployee->nombre,horas,pEmployee->sueldo);
					if(!requestCharacterAnswer("\n\nIngrese (s) para modificar el empleado: "))
					{
						employee_setHorasTrabajadas(pEmployee, horas);
						printf("\nSe Realizo la modificacion correctamente.\n\n");
						systemPause("\nToque cualquier tecla para continuar...\n");
					}
					else
					{
						printf("\nSe cancelo la modificacion del Empleado.\n\n");
						systemPause("\nToque cualquier tecla para continuar...\n");
					}
					break;
				case 3:
					printf("%-5s %-20s %-10s %-10s\n\n","ID","NOMBRE","HORAS","SUELDO");
					printEmployee(pEmployee);
					requestNumber(&sueldo, "Ingrese el Sueldo del Empleado: ", "Error.EL sueldo ingresado no puede contener letas o numeros y el rango es (10000 a 1000000).\nReingrese el sueldo del Empleado: ", 10000, 1000000);
					printf("Empleado luego de la modificacion:\n\n");
					printf("%-5s %-20s %-10s %-10s\n\n","ID","NOMBRE","HORAS","SUELDO");
					printf("%-5d %-20s %-10d %-10d ",pEmployee->id,pEmployee->nombre,pEmployee->horasTrabajadas,sueldo);
					if(!requestCharacterAnswer("\n\nIngrese (s) para modificar el empleado: "))
					{
						employee_setSueldo(pEmployee, sueldo);
						printf("\nSe Realizo la modificacion correctamente.\n\n");
						systemPause("\nToque cualquier tecla para continuar...\n");
					}
					else
					{
						printf("\nSe cancelo la modificacion del Empleado.\n\n");
						systemPause("\nToque cualquier tecla para continuar...\n");
					}
					break;
				case 4:
					pEmployee=NULL;
					printf("\nSe volvio atras\n");
					break;
			}

		}while(option!=4);

	}
	return ret;
}

Employee* employee_new()
{
	Employee* employeeRet = NULL;
	employeeRet = (Employee*) malloc (sizeof(Employee));
	return employeeRet;
}
//parcer
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* Sueldo)
{
	int auxId;
	int auxHoras;
	int auxSueldo;
	Employee* employee = NULL;
	employee = employee_new();
	if(employee != NULL)// agregar != para los datos q llegan
	{
		//verificar validaciones

		auxId=atoi(idStr);
		auxHoras=atoi(horasTrabajadasStr);
		auxSueldo=atoi(Sueldo);
		employee_setHorasTrabajadas(employee, auxHoras);
		employee_setId(employee, auxId);
		employee_setNombre(employee, nombreStr);
		employee_setSueldo(employee, auxSueldo);
	}
	return employee;
}

int employee_setId(Employee* this,int id)
{
	int takeCare= 0;

	if(this != NULL)
	{
		this->id=id;
		takeCare = 1;
	}
	return takeCare;
}

int employee_setNombre(Employee* this,char* nombre)
{
	int takeCare=0;

	if(this != NULL && nombre != NULL)
	{
		strcpy(this->nombre,nombre);
		takeCare=1;
	}

	return takeCare;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int takeCare=0;

	if(this!=NULL)
	{
		this->horasTrabajadas=horasTrabajadas;
		takeCare=1;
	}
	return takeCare;
}

int employee_setSueldo(Employee* this,int sueldo)
{
	int takeCare=0;
	if(this!=NULL)
	{
		this->sueldo=sueldo;
		takeCare=1;
	}
	return takeCare;
}

int employee_getNombre(Employee* this,char* nombre)
{
	int ret=1;
	if(this != NULL)
	{
		strcpy(nombre,this->nombre);
		ret=0;
	}
	return ret;
}
int employee_getId(Employee* this,int* id)
{
	int ret=1;
	if(this != NULL && id != NULL)
	{
		*id=this->id;
		ret=0;
	}
	return ret;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int ret=1;
	if(this != NULL && horasTrabajadas)
	{
		*horasTrabajadas=this->horasTrabajadas;
		ret=0;
	}
	return ret;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
	int ret=1;
	if(this!=NULL && sueldo!=NULL)
	{
		*sueldo=this->sueldo;
		ret=0;
	}
	return ret;
}
void employee_delete(Employee* this)
{
	if(this != NULL)
	{
		free(this);
		this = NULL;
	}
}

void printEmployee(Employee* employee)
{
	int id;
	char nombre[128];
	int sueldo;
	int horasTrabajadas;
	if(employee!=NULL)
	{
		employee_getId(employee, &id);
		employee_getNombre(employee, nombre);
		employee_getSueldo(employee, &sueldo);
		employee_getHorasTrabajadas(employee, &horasTrabajadas);

		printf("%-5d %-20s %-10d %-10d\n",id,nombre,horasTrabajadas,sueldo);
	}

}
int employee_getItBackLastId(char* path, int* lastId)
{
	int ret=1;
	char ultimoId[20];
	FILE* pFile= fopen(path,"r");
	if(path!=NULL && lastId!=NULL)
	{

		if(pFile!=NULL)
		{
			while(!feof(pFile))
			{
				fscanf(pFile, "%[^\n]",ultimoId);
				if(!feof(pFile))
				{
					break;
				}
			}
			*lastId=atoi(ultimoId);
			fclose(pFile);
			pFile=NULL;
		}
		ret=0;
	}
	return ret;
}
int employee_saveLastId(char* path,int* lastId)
{
	int ret=1;
	FILE* pFile=fopen(path,"w");
	if(path!=NULL && lastId!=NULL)
	{
		if(pFile!=NULL)
		{
			fprintf(pFile,"%d\n",*lastId);
			fclose(pFile);
			pFile=NULL;
		}
		ret=0;
	}
	return ret;
}
int employee_sortForSalary(void* employeeI,void* employeeJ)
{
	int state=1;
	Employee* pAux1;
	Employee* pAux2;

	if(employeeI!=NULL && employeeJ!=NULL)
	{
		pAux1=(Employee*)employeeI;
		pAux2=(Employee*)employeeJ;
		if(pAux1->sueldo<pAux2->sueldo)
		{
			state=-1;
		}
		else if(pAux1->sueldo==pAux2->sueldo)
		{
			state=0;
		}

		pAux1=NULL;
		pAux2=NULL;
	}
	return state;
}

int employee_sortForId(void* employeeI, void* employeeJ)
{
	int ret=1;
	Employee* pAux1;
	Employee* pAux2;
	if(employeeI!=NULL && employeeJ!=NULL)
	{
		pAux1=(Employee*)employeeI;
		pAux2=(Employee*)employeeJ;
		if(pAux1->id<pAux2->id)
		{
			ret=-1;
		}
		else if(pAux1->id==pAux2->id)
		{
			ret=0;
		}
		pAux1=NULL;
		pAux2=NULL;
	}
	return ret;
}
int employee_sortForHours(void* employeeI,void* employeeJ)
{
	int ret=1;
	Employee* pAux1;
	Employee* pAux2;
	if(employeeI!=NULL && employeeJ!=NULL)
	{
		pAux1=(Employee*)employeeI;
		pAux2=(Employee*)employeeJ;
		if(pAux1->horasTrabajadas<pAux2->horasTrabajadas)
		{
			ret=-1;
		}
		else if(pAux1->horasTrabajadas==pAux2->horasTrabajadas)
		{
			ret=0;
		}
		pAux1=NULL;
		pAux2=NULL;
	}
	return ret;
}
int employee_sortForName(void* employeeI,void* employeeJ)
{
	int ret=1;
	Employee* pAux1;
	Employee* pAux2;
	if(employeeI!=NULL && employeeJ!=NULL)
	{
		pAux1=(Employee*)employeeI;
		pAux2=(Employee*)employeeJ;
		if(strcmp(pAux1->nombre,pAux2->nombre)==-1)
		{
			ret=-1;
		}
		else if(strcmp(pAux1->nombre,pAux2->nombre)==0)
		{
			ret=0;
		}
		pAux1=NULL;
		pAux2=NULL;
	}
		return ret;
}
int employee_menuSort(LinkedList* pArrayListEmployee)
{
	int option;
	int ret=1;
	do
	{
		requestNumber(&option, "**************************************\n"
								"SUBMENU ORDENAR\n"
								"**************************************\n"
								"1. Ordenar por nombre ascendente\n"
								"2. Ordenar por nombre descendente\n"
								"3. Ordenar por sueldo ascendente\n"
								"4. Ordenar por sueldo descendente\n"
								"5. Ordenar por horas trabajadas ascendente\n"
								"6. Ordenar por horas trabajadas descendente\n"
								"7. Ordenar por id ascendente\n"
								"8. Ordenar por id descendente\n"
								"9. Atras\n"
								"**************************************\n"
								"Ingrese una opcion: ",
								"**************************************\n"
								"SUBMENU ORDENAR\n"
								"1. Ordenar por nombre ascendente\n"
								"2. Ordenar por nombre descendente\n"
								"3. Ordenar por sueldo ascendente\n"
								"4. Ordenar por sueldo descendente\n"
								"5. Ordenar por horas trabajadas ascendente\n"
								"6. Ordenar por horas trabajadas descendente\n"
								"7. Ordenar por id ascendente\n"
								"8. Ordenar por id descendente\n"
								"9. Atras\n"
								"**************************************\n"
								"Opcion invalida, reingrese: ", 1, 9);
		switch(option)
		{
			case 1:
				printf("\nordenando por nombre ascendente..............\n\n");
				ll_sort(pArrayListEmployee,employee_sortForName,1);
				printf("se realizo el ordenamiento\n\n");
				break;
			case 2:
				printf("\nordenando por nombre desendente..............\n\n");
				ll_sort(pArrayListEmployee,employee_sortForName,0);
				printf("se realizo el ordenamiento\n\n");
				break;
			case 3:
				printf("\nordenando por sueldo ascendente..............\n\n");
				ll_sort(pArrayListEmployee,employee_sortForSalary,1);
				printf("se realizo el ordenamiento\n\n");
				break;
			case 4:
				printf("\nordenando por sueldo desendente..............\n\n");
				ll_sort(pArrayListEmployee,employee_sortForSalary,0);
				printf("se realizo el ordenamiento\n\n");
				break;
			case 5:
				printf("\nordenando por horas ascendente..............\n\n");
				ll_sort(pArrayListEmployee,employee_sortForHours,1);
				printf("se realizo el ordenamiento\n\n");
				break;
			case 6:
				printf("\nordenando por horas desendente..............\n\n");
				ll_sort(pArrayListEmployee,employee_sortForHours,0);
				printf("se realizo el ordenamiento\n\n");
				break;
			case 7:
				printf("\nordenando por id ascendente..............\n\n");
				ll_sort(pArrayListEmployee,employee_sortForId,1);
				break;
			case 8:
				printf("\nordenando por id descendente..............\n\n");
				ll_sort(pArrayListEmployee,employee_sortForId,0);
				break;
			case 9:
				printf("\nVolviendo al menu anterior.\n");
				break;
		}

	}while(option!=9);
		return ret;
}

