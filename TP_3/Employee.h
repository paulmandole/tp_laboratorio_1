#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#include "LinkedList.h"
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

/**
 * @fn Employee employee_new*()
 * @brief reserva un espacio para un Employee nuevo con un maloc
 *
 * @return retorna un puntero a Employee
 */
Employee* employee_new();

/**
 * @fn Employee employee_newParametros*(char*, char*, char*, char*)
 * @brief reserva un espacio para un Employee nuevo con un maloc reciviendo los datos para setear la esturctura
 *
 * @param idStr recive un puntero a char con un id
 * @param nombreStr recive un puntero a char con un nombre
 * @param horasTrabajadasStr recive un puntero a char con las horas trabajadas
 * @param Sueldo recive un puntero a char con sueldo
 * @return retorna un puntero a un Employee
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* Sueldo);

/**
 * @fn void employee_delete(Employee*)
 * @brief hace un free de un empleado para borrarlo
 *
 * @param this recive un puntero a un empleado
 */
void employee_delete(Employee* this);

/**
 * @fn int employee_setId(Employee*, int)
 * @brief setea el id en una estructura de empleado
 *
 * @param this recive un puntero a un empleado
 * @param id recive el id a setear
 * @return retorna 1  si se pudo cargar o 0 si no se pudo cargar
 */
int employee_setId(Employee* this,int id);

/**
 * @fn int employee_getId(Employee*, int*)
 * @brief recive un empleado y un  puntero a id y muestra dato cargado en la estructura
 *
 * @param this recive un puntero a un empleado
 * @param id recive un puntero a un id
 * @return ret 0 si salio bien o 1 si salio mal
 */
int employee_getId(Employee* this,int* id);

/**
 * @fn int employee_setNombre(Employee*, char*)
 * @brief setea el nombre en una estructura de empleado
 *
 * @param this recive un puntero a un empleado
 * @param nombre recive el nombre a setear
 * @return retorna 1  si se pudo cargar o 0 si no se pudo cargar
 */
int employee_setNombre(Employee* this,char* nombre);

/**
 * @fn int employee_getNombre(Employee*, char*)
 * @brief recive un empleado y un  puntero a nombre y muestra dato cargado en la estructura
 *
 * @param this recive un puntero a un empleado
 * @param nombre recive un puntero a un nombre
 * @return retorna 0  si se pudo cargar o 1 si no se pudo cargar
 */
int employee_getNombre(Employee* this,char* nombre);

/**
 * @fn int employee_setHorasTrabajadas(Employee*, int)
 * @brief recive un empleado y un  puntero a horas trabajadas y muestra dato cargado en la estructura
 *
 * @param this recive un puntero a un empleado
 * @param horasTrabajadas recive un puntero a horas trabajadas
 * @return retorna 1  si se pudo cargar o 0 si no se pudo cargar
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);

/**
 * @fn int employee_getHorasTrabajadas(Employee*, int*)
 * @brief muestra las horas trabajadas que estan en la estructura q recive por parametro
 *
 * @param this recive un puntero a una structura
 * @param horasTrabajadas recive un puntero a horas trabajadas
 * @return retorna 1 si salio mal o 1 si salio bien
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

/**
 * @fn int employee_setSueldo(Employee*, int)
 * @brief setea el campo de sueldo en la estructura con el int  que recive de parametro
 *
 * @param this recive un puntero a structuctura empleado
 * @param sueldo recive un entero con el sueldo a cargar
 * @return retorna 0 si no se pudo realizar o 1 si se cargo
 */
int employee_setSueldo(Employee* this,int sueldo);

/**
 * @fn int employee_getSueldo(Employee*, int*)
 * @brief muestra el dato guardado en un empleado y devuelve el dato por el puntero a int
 *
 * @param this recive un puntero a una structura
 * @param sueldo recive un puntero a un sueldo
 * @return retorna 1 si sale mal o 0 si sale bien
 */
int employee_getSueldo(Employee* this,int* sueldo);

/**
 * @fn void printEmployee(Employee*)
 * @brief recive un puntero a un empleado y muestra los datos llamando a los geteers
 *
 * @param employee recive un puntero a empleado
 */
void printEmployee(Employee* employee);

/**
 * @fn int employee_getItBackLastId(char*, int*)
 * @brief recive el nombre de un archivo el archivo contiene el ultimo id cargado y un puntero a una variable que guardara el ultimo id
 *
 * @param path recive un puntero a char
 * @param lastId recive un puntero al ultimo id
 * @return retorna 1 si no se pudo cargar el archivo o 0 si se pudo cargar
 */
int employee_getItBackLastId(char* path, int* lastId);

/**
 * @fn int employee_saveLastId(char*, int*)
 * @brief guarda el ultimo id cargado en el archivo  que recive por parametro
 *
 * @param path recive un puntero a char con el nombre del archivo
 * @param lastId recive el ultimo id usado en el programa
 * @return retorna 1 si salio mal o 0 si se realizo la carga
 */
int employee_saveLastId(char* path,int* lastId);

/**
 * @fn int employee_sortForSalary(void*, void*)
 * @brief ordena por salario
 *
 * @param employeeI recive un puntero a empleado guardado en el linkedlist
 * @param employeeJ recive un puntero a empleado guardado en el linkedlist
 * @return devuelve 1 si salio mal o -1 si se un empledo es menor al otro o 0 si son iguales
 */
int employee_sortForSalary(void* employeeI,void* employeeJ);

/**
 * @fn int employee_sortForId(void*, void*)
 * @brief ordena por id
 *
 * @param employeeI recive un puntero a empleado guardado en el linkedlist
 * @param employeeJ recive un puntero a empleado guardado en el linkedlist
 * @return devuelve 1 si salio mal o -1 si se un empledo es menor al otro o 0 si son iguales
 */
int employee_sortForId(void* employeeI, void* employeeJ);

/**
 * @fn int employee_menuSort(LinkedList*)
 * @brief muestra un submenu con las opciones para ordenar y llama a las funciones de ordenamiento
 *
 * @param pArrayListEmployee recive un puntero al ll
 * @return devuelve 1 si salio todo bien o 0 si el puntero recivido es NULL
 */
int employee_menuSort(LinkedList* pArrayListEmployee);

/**
 * @fn int employee_sortForHours(void*, void*)
 * @brief ordena por horas
 *
 * @param employeeI recive un puntero a empleado guardado en el linkedlist
 * @param employeeJ recive un puntero a empleado guardado en el linkedlist
 * @return 1 si salio mal o -1 si se un empledo es menor al otro o 0 si son iguales
 */
int employee_sortForHours(void* employeeI,void* employeeJ);

/**
 * @fn int employee_sortForName(void*, void*)
 * @brief ordena por nombre
 *
 * @param employeeI recive un puntero a empleado guardado en el linkedlist
 * @param employeeJ recive un puntero a empleado guardado en el linkedlist
 * @return 1 si salio mal o -1 si se un empledo es menor al otro o 0 si son iguales
 */
int employee_sortForName(void* employeeI,void* employeeJ);

/**
 * @fn int employee_menuModify(LinkedList*, Employee*)
 * @brief muestra el sub menu modificar y modifica los datos de algun empleado en particular
 *
 * @param pArrayListemployee recive la lista de empleado guardadas en el ll
 * @param pEmployee recive un puntero con el empleado a modificar
 * @return ret 1 si salio bien o 0 si salio mal
 */
int employee_menuModify(LinkedList* pArrayListemployee,Employee* pEmployee);

#endif // employee_H_INCLUDED
