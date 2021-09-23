/*
 * funciones.h
 *
 *  Created on: 3 sep. 2021
 *      Author: Paul
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_

#include <stdio.h>
#include <stdlib.h>
/**
 * @fn void mostrarMenu(float, float, int, int)
 * @brief muestra el menu con los datos ingresados del usuario
 *
 * @param num1 el primer operando ingresado
 * @param num2 el segundo operando ingresado
 * @param flag1 si se ingreseo un operando
 * @param flag2 si se ingreso el segundo operando
 */
void mostrarMenu(float num1,float num2,int flag1, int flag2);
/**
 * @fn int pedirNumeroEntero(char*, char*, int, int)
 * @brief pide un numero entero
 *
 * @param mensaje a mostrar para pedir lo que se necesite
 * @param mensajeError mensaje de ERROR mas mensaje de reingreso
 * @param minimo valor minimo a validar
 * @param maximo valor minimo a validar
 * @return retorna un numero entero ingresado valido
 */

int pedirNumeroEntero(char* mensaje,char* mensajeError, int minimo , int maximo);

/**
 * @fn float ingresarNumeroflotante(char*)
 * @brief pide ingresar un numero flotante
 *
 * @param mensaje a mostrar para pedir lo q se nececita
 * @return retorna un numero flotante
 */
float ingresarNumeroflotante(char* mensaje);

/**
 * @fn int esEntero(float)
 * @brief valida q un numero sea entero o decimal
 *
 * @param num1 recive el numero a validar
 * @return devuelve 0 en caso de ser un numero entero o 1 en caso de ser decimal
 */
int esEntero(float num1);


#endif /* FUNCIONES_H_ */
