/*
 * arrayEmployees.h
 *
 *  Created on: 24 sep. 2021
 *      Author: Paul
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_
#include "functions.h"

#define EMPTY 0
#define FULL 1
#define MAXCHAR 51
#define MINSALARY 25000
#define MAXSALARY 800000
#define SECTORMAX 10
#define SECTORMIN 1
#define MAXID 2000
#define MINID 1000

struct
{
	 int id;
	 char name[51];
	 char lastName[51];
	 float salary;
	 int sector;
	 int isEmpty;

}typedef Employee;

/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int initEmployees(Employee* list , int len);

/**
 * @fn int requestEmployee(Employee*, int, int*, int*)
 * @brief prompts user for array data to load into a helper and send to a function to load
 *
 * @param list Employee* Pointer to array of employees
 * @param len int Array length
 * @param id pinter a id
 * @param amountEmployee pointer amountEmployee
 * @return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int requestEmployee(Employee* list, int len,int* id,int* amountEmployee);

/**
 * @fn int searchEmpty(Employee*, int, int*)
 * @brief looks for an empty space and returns the index if not found returns -1
 *
 * @param list Employee* Pointer to array of employees
 * @param len int Array length
 * @param index pointer a index
 * @return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int searchEmpty(Employee* list,int len, int* index);

/**
 * @fn void printEmployee(Employee)
 * @brief shows an employee
 *
 * @param list receives an employee
 */
void printEmployee(Employee list);

/** \brief print the content of employees array
 *
 * \param list Employee*
 * \param length int
 * \return int
 *
 */
int printEmployees(Employee* list, int length);

/** \brief find an Employee by Id en returns the index position in array.
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL pointer received or employee not found]
 *
 */
int findEmployeeById(Employee* list, int len,int id);

/** \brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param list employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
 *
 **/
int adjustEmployee(Employee* list,int len);

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param list Employee*
 * \param len int
 * \param id int pointer
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
 * la modifique para que el id se reciba como puntero
 */
int removeEmployee(Employee* list, int len,int* id);

/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
 *
 * \param list Employee*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int sortEmployees(Employee* list, int len, int order);

/**
 * @fn int printSubMenuReport(Employee*, int)
 * @brief displays the report submenu and calls functions to display
 *
 * @param list Employee* Pointer to array of employees
 * @param len int
 * @return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int printSubMenuReport(Employee* list, int len);

/**
 * @fn int averagedSalary(Employee*, int)
 * @brief totals employee salaries and shows the number of employees who exceed the average salary
 *
 * @param list Employee* Pointer to array of employees
 * @param len int len of array
 * @return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int averagedSalary(Employee* list,int len);

/** \brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param list employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
 *
 **/
int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector);


#endif /* ARRAYEMPLOYEES_H_ */
