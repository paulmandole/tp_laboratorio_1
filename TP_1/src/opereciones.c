/*
 * opereciones.c
 *
 *  Created on: 17 sep. 2021
 *      Author: Paul
 */
#include "funciones.h"
#include "operaciones.h"

float sumar(float num1, float num2)
{
	 float suma;

	 suma=num1+num2;

	 return suma;

}

float restar(float num1, float num2)
{
	 float resta;

	 resta=num1-num2;

	 return resta;
}

float dividir(float num1, float num2)
{
	float divicion;

	divicion=num1/num2;

	return divicion;
}

float multiplicar(float num1, float num2)
{
	float multiplicacion;

	multiplicacion=num1*num2;

	return multiplicacion;
}

long int factoriar(long int num1)
{
	int factorial = 1;

	if (num1 != 1 && num1 != 0)
	{
		factorial = num1 * factoriar(num1-1);
	}

	return factorial;
}

