/*
 * funciones.h
 *
 *  Created on: 24 sep. 2021
 *      Author: Paul
 */

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_
#include "arrayEmployees.h"

/**
 * @fn int systemPause(char*)
 * @brief Asks the user to press a key to continue// pide a el usuario que ingrese una tecla para continuar
 *
 * @param message pointer a message/puntero a mensaje
 * @return int Return (-1) if Error [NULL pointer] - (0) if Ok / int Devuelve (-1) si hay error [puntero NULL] - (0) si está bien
 */
int systemPause(char* message);
/**
 * @fn int isNumber(char*)
 * @brief check if the string consists of letters or numbers / comprueba si la cadena está formada por letras o números
 *
 * @param string receives a string pointer/ recibe un puntero de cadena de caracteres
 * @return returns -1 if the string is numbers 0 if it has letters / devuelve -1 si la cadena son números 0 si tiene letras
 */
int isNumber(char* string);

/**
 * @fn int validateSpace(char*)
 * @brief validate if there is space, tab or \v / valida si hay espacio, tabulador o \v
 *
 * @param string string receives a string pointer/ recibe un puntero de cadena de caracteres
 * @return returns 0 if there is a space, tab, or \ v in the string / devuelve 0 si hay un espacio, tabulación o \ v en la cadena
 */
int validateSpace(char* string);

/**
 * @fn int requestNumber(int*, char*, char*, int, int)
 * @brief
 *
 * @param num  receives a pointer num / recive un puntero a num
 * @param message receives a string pointer with a message/ recibe un puntero de cadena de caracteres con un mensaje
 * @param messageError receives a string pointer with a message of error/ recibe un puntero de cadena de caracteres con un mensaje de error
 * @param int min receives a num minimun / recive un numero minimo
 * @param int max receives a num maximun / recive un numero maximo
 * @return int Return (-1) if Error [NULL pointer] - (0) if Ok / int Devuelve (-1) si hay error [puntero NULL] - (0) si está bien
 */
int requestNumber(int* num,char* message,char* messageError,int min, int max);

/**
 * @fn int requestString(char*, char*, char*, int)
 * @brief ask the user for a string /pide una cadena  al usuario
 *
 * @param string receives a string pointer / recive un puntero a una cadena
 * @param message receives a string pointer with a message/ recibe un puntero de cadena de caracteres con un mensaje
 * @param messageError mreceives a string pointer with a message of error/ recibe un puntero de cadena de caracteres con un mensaje de error
 * @param int max receives a num maximun the string len / recive un numero maximo del tamaño de la cadena
 * @return int Return (-1) if Error [NULL pointer] - (0) if Ok / int Devuelve (-1) si hay error [puntero NULL] - (0) si está bien
 */
int requestString(char* string,char* message,char* messageError,int max);

/**
 * @fn int requestNumberFloat(float*, char*, char*, int, int)
 * @brief asks the user for the floating number /pide a el usuario el número flotante
 *
 * @param num  receives pointer of float num / recive un puntero de un numero flotante
 * @param message receives a string pointer with a message/ recibe un puntero de cadena de caracteres con un mensaje
 * @param messageError receives a string pointer with a message of error/ recibe un puntero de cadena de caracteres con un mensaje de error
 * @param min int min receives a num minimun / recive un entero numero minimo
 * @param max int max receives a num maximun / recive un entero numero maximo
 * @return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok / int Devuelve (-1) si hay error [longitud no válida o puntero NULL] - (0) si está bien
 */
int requestNumberFloat(float* num, char* message,char* messageError,int min,int max);

/**
 * @fn int requestCharacterAnswer(char*)
 * @brief asks the user if they agree with something / pregunta al usuario si está de acuerdo con algo
 *
 * @param menssage receives a string pointer with a message/ recibe un puntero de cadena de caracteres con un mensaje
 * @return int Return (-1) if Error [NULL pointer] - (0) if Ok / int Devuelve (-1) si hay error [longitud no válida o puntero NULL] - (0) si está bien
 */
int requestCharacterAnswer(char* message);

/**
 * @fn int requestCharacter(char*, char*)
 * @brief prompts the user to enter a character / solicita al usuario que ingrese un carácter
 *
 * @param character receives pointer of character / recive un puntero a un caracter
 * @param message receives a string pointer with a message/ recibe un puntero de cadena de caracteres con un mensaje
 * @return int Return (-1) if Error [NULL pointer] - (0) if Ok / int Devuelve (-1) si hay error [longitud no válida o puntero NULL] - (0) si está bien
 */
int requestCharacter(char* character, char* message);

/**
 * @fn int divideFloat(float*, float, int)
 * @brief divide num1 / num 2 / divide el numero 1  / numero 2
 *
 * @param result returns a pointer to float with the result of the division / devuelve un puntero para flotar con el resultado de la división
 * @param num1 receives a number float / recive un numero flotante
 * @param num2 receives a numbre int / recive un numero entero
 * @return int Return (-1) if Error [NULL pointer] - (0) if Ok / int Devuelve (-1) si hay error [puntero NULL] - (0) si está bien
 */
int divideFloat(float* result,float num1,int num2);

/**
 * @fn int requestNameOrLastName(char*, char*, char*, int)
 * @brief asks the user for a string of characters inside it is validated that there are no signs / pide al usuario una cadena de caracteres en su interior se valida que no hay signos
 *
 * @param chain receives a pointer string / recive un puntero a una cadena de caracteres
 * @param message receives a string pointer with a message/ recibe un puntero de cadena de caracteres con un mensaje
 * @param messageError receives a string pointer with a message of Error/ recibe un puntero de cadena de caracteres con un mensaje de error
 * @param max receives a int maximun large of chain / recive un entero con el largo maximo de la cadena
 * @return int Return (-1) if Error [NULL pointer] - (0) if Ok / int Devuelve (-1) si hay error [puntero NULL] - (0) si está bien
 */
int requestNameOrLastName(char* chain,char* message,char* messageError,int max);

/**
 * @fn int validateSigns(char*)
 * @brief validates if signs were entered in the string / valida si se ingresaron signos en la cadena
 *
 * @param string receives a pointer string / recive un puntero a una cadena de caracteres
 * @return int Return (-1) if Error [NULL pointer] - (0) if Ok / int Devuelve (-1) si hay error [puntero NULL] - (0) si está bien
 */
int validateSigns(char* string);

/**
 * @fn int tolowerString(char*)
 * @brief lowercase a character string/pasa a minúsculas una cadena de caracteres
 *
 * @param string receives a pointer string / recive un puntero a una cadena de caracteres
 * @return int Return (-1) if Error [NULL pointer] - (0) if Ok / int Devuelve (-1) si hay error [puntero NULL] - (0) si está bien
 */
int tolowerString(char* string);

/**
 * @fn int upperFirstLetter(char*)
 * @brief capitalize the first letter of a string and the first letter after a space/ poner en mayúscula la primera letra de una cadena y la primera letra después de un espacio
 *
 * @param string receives a pointer string / recive un puntero a una cadena de caracteres
 * @return int Return (-1) if Error [NULL pointer] - (0) if Ok / int Devuelve (-1) si hay error [puntero NULL] - (0) si está bien
 */
int upperFirstLetter(char* string);


#endif /* FUNCTIONS_H_ */
