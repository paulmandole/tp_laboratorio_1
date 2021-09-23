/*
 * funciones.c
 *
 *  Created on: 3 sep. 2021
 *      Author: Paul
 */
#include "funciones.h"
#include "operaciones.h"

void mostrarMenu(float num1,float num2,int flag1, int flag2)
{
	if(flag1==0 && flag2==0)
			{
				printf("Bienvenido a la calculeitor 9000\n");
				printf("**************************************\n");
				printf("1.Ingresar 1er operando: X\n2.Ingresar 2do operando: Y\n3.Calcular todas las operaciones\n4.Informar resultados\n5.Salir\n");
				printf("**************************************\n");
			}
			else if(flag1==1 && flag2==1)
			{
				printf("Bienvenido a la calculeitor 9000\n");
				printf("**************************************\n");
				printf("1.Ingresar 1er operando: %.2f\n2.Ingresar 2do operando: %.2f\n3.Calcular todas las operaciones\n4.Informar resultados\n5.Salir\n",num1,num2);
				printf("**************************************\n");
			}
			else if(flag1==1)
			{
				printf("Bienvenido a la calculeitor 9000\n");
				printf("**************************************\n");
				printf("1.Ingresar 1er operando: %.2f\n2.Ingresar 2do operando: Y\n3.Calcular todas las operaciones\n4.Informar resultados\n5.Salir\n",num1);
				printf("**************************************\n");
			}
			else if(flag2==1)
			{
				printf("Bienvenido a la calculeitor 9000\n");
				printf("**************************************\n");
				printf("1.Ingresar 1er operando: X\n2.Ingresar 2do operando: %.2f\n3.Calcular todas las operaciones\n4.Informar resultados\n5.Salir\n",num2);
				printf("**************************************\n");
			}
}

 int pedirNumeroEntero(char* mensaje, char* mensajeError, int minimo , int maximo)
 {
 	int numeroIngresado;

 	 printf("%s", mensaje);
 	 fflush(stdin);
 	 scanf("%d",&numeroIngresado);

 	while(numeroIngresado<minimo || numeroIngresado>maximo)
 	{
	 	 printf("%s", mensajeError);
	 	 fflush(stdin);
	 	 scanf("%d",&numeroIngresado);
 	}

 	 return numeroIngresado;
 }

 float ingresarNumeroflotante(char* mensaje)
 {
	 float num;

	 printf("%s",mensaje);
	 fflush(stdin);
	 scanf("%f",&num);


	 return num;
}



int esEntero(float num1)
{
	int entero;
	float flotante;
	int respuesta;

	flotante=num1;
	entero=flotante;

	if((entero-flotante)==0)
	{
		respuesta=0;
	}
	else
	{
		respuesta=1;
	}

	return respuesta;
}


