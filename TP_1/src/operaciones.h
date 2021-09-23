/*
 * operaciones.h
 *
 *  Created on: 17 sep. 2021
 *      Author: Paul
 */

#ifndef OPERACIONES_H_
#define OPERACIONES_H_



/**
 * @fn float sumar(float, float)
 * @brief suma dos numeros flotantes
 *
 * @param num1 recive como parametro un numero a sumar
 * @param num2 recive el segundo numero a sumar
 * @return retorna el resultado de la suma entre los dos numeros
 */
float sumar(float num1, float num2);

/**
 * @fn float restar(float, float)
 * @brief realiza una resta entre dos numeros flotantes
 *
 * @param num1 recive el segundo numero a restar
 * @param num2 recive el segundo numero a restar
 * @return retorna el resultado de la resta de numero 1 menos numero 2
 */
float restar(float num1, float num2);

/**
 * @fn float dividir(float, float)
 * @brief realiza una divicion del numero uno dividido el numero dos
 *
 * @param num1 recive el segundo numero a dividir
 * @param num2 recive el segundo numero a dividir
 * @return retorna el resultado de la divicion de numero 1 dividido numero 2
 */
float dividir(float num1, float num2);

/**
 * @fn float multiplicar(float, float)
 * @brief realiza una multiplicacion del numero uno por el numero dos
 *
 * @param num1 recive el segundo numero a multiplicar
 * @param num2 recive el segundo numero a multiplicar
 * @return
 */
float multiplicar(float num1, float num2);

/**
 * @fn long int factoriar(float)
 * @brief realiza un factorial de un numero
 *
 * @param num1 recive el numero a factoriar
 * @return retorna el factorial del numero
 */
long int factoriar(long int num1);


#endif /* OPERACIONES_H_ */
