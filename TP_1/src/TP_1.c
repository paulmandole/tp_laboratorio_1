/*
 ============================================================================
 Name        : TP_1.c
 Author      : Paul Mandole
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "operaciones.h"
int main(void) {
	setbuf(stdout, NULL);
	int opcion;
	float num1;
	float num2;
	float resta;
	float suma;
	float divicion;
	float multiplicacion;
	long int factorial;
	long int factorial2;
	int entero;
	int entero2;
	int flag1=0;
	int flag2=0;
	int flag3=0;
	int flag4=0;
	int flag5=0;
	int flag6=0;
	long int numAFactoriar;

	do
	{
		mostrarMenu(num1,num2,flag1,flag2);
		opcion=pedirNumeroEntero("Ingrese una opcion: ","ERROR. la opcion ingresada no es valida.\nReingrese una opcion: ",1,5);

		switch(opcion)
		{
			case 1:
				printf("***********************************************************************\n");
				num1=ingresarNumeroflotante("Ingrese el primer operando: ");
				entero=esEntero(num1);
				flag1=1;
				printf("***********************************************************************\n");
				system("pause");
				break;
			case 2:
				printf("***********************************************************************\n");
				num2=ingresarNumeroflotante("ingrese el segundo operando: ");
				entero2=esEntero(num2);
				flag2=1;
				printf("***********************************************************************\n");
				system("pause");
				break;
			case 3:
				printf("***********************************************************************\n");
				if(flag6==0)
				{
					if(flag1==0 && flag2==0)
					{
						 printf("ERROR.Debe pasar por la opcion 1 y 2 antes.\n");
					}
					else
					{
						if(flag1==1 && flag2==1)
						{
							suma=sumar(num1,num2);
							resta=restar(num1,num2);
							if(num2!=0)
							{
								divicion=dividir(num1,num2);
							}
							multiplicacion=multiplicar(num1,num2);
							flag3=1;
						}
						if(entero==0 && num1>=0 && flag1==1 && num1 <32)
						{
							numAFactoriar=num1;
							factorial=factoriar(numAFactoriar);
							flag4=1;
						}
						if(entero2==0 && num2>=0 && flag2==1 && num2 <32)
						{
							numAFactoriar=num2;
							factorial2=factoriar(numAFactoriar);
							flag5=1;
						}

						if(flag3==1 || flag4==1 || flag5==1)
						{
							printf("Se realizaron los calculos con los numero ingresados.\n");
						}
						else
						{
							printf("no se an podido realizar los calculos con los numeros ingresados.\n");
						}
					}
					flag6=1;
				}


				printf("***********************************************************************\n");
				system("pause");
				break;
			case 4:
				printf("***********************************************************************\n");

				if(flag6==1)
				{
					if(flag3==1 || flag4==1 || flag5==1)
					{
						if(entero==0 && entero2==0)
						{
							if(flag3==1)
							{
								printf("El resultado de %.0f + %.0f es: %.0f\nEl resultado de %.0f - %.0f es: %.0f\nEl resultado de %.0f * %.0f es: %.0f", num1,num2,suma,num1,num2,resta,num1,num2,multiplicacion);
								if(num2!=0)
								{
										printf("\nEl resultado de %.0f / %.0f es: %.2f\n",num1,num2,divicion);
								}
								else
								{
									printf("\nError no es posible dividir por 0.\n");
								}
							}
							if(num1>=0 && flag4==1)
							{
								printf("\nEl resultado de !%.0f es: %ld\n", num1, factorial);
							}
							else
							{
								printf("No es posible hacer el factorial de un numero Negativo.El numero ingresado fue: %.0f\n",num1);
							}
							if(num2>=0 && flag5==1)
							{
								printf("\nEl resultado de !%.0f es: %ld\n", num2, factorial2);
							}
							else
							{
								printf("\nNo es posible hacer el factorial de un numero Negativo.El numero ingresado fue: %.0f\n",num2);
							}
						}
						else
						{
							if(flag3==1)
							{
								printf("El resultado de %.2f + %.2f es: %.2f\nEl resultado de %.2f - %.2f es: %.2f\nEl resultado de %.2f * %.2f es: %.2f", num1,num2,suma,num1,num2,resta,num1,num2,multiplicacion);
								if(num2!=0)
								{
										printf("\nEl resultado de %.2f / %.2f es: %.2f\n",num1,num2,divicion);
								}
								else
								{
									printf("\nError no es posible dividir por 0.\n");
								}
							}
							if(flag4==1)
							{
								if(entero==0)
								{
									printf("\nEl resultado de !%.0f es: %ld\n",num1 , factorial);
								}
								else
								{
									printf("\nNo es posible hacer el factor de un numero con decimal.El numero ingresado fue: %.2f",num1);
								}
							}
							if(flag5==1)
							{
								if(entero2==0)
								{
									printf("\nEl resultado de !%.0f es: %ld\n",num2 , factorial2);
								}
								else
								{
									printf("\nNo es posible hacer el factor el numero ingresado fue: %.2f\n",num2);
								}
							}
						}
					}
					else
					{
						if((num1<0 && flag1==1)||(num2<0 && flag2==1))
						{
							printf("el numero ingresado no se pudo factoriar ya que era un numero negativo.\n");
						}
						else
						{
							printf("Error.Debe pasar por la opcion 3 antes de mostrar resultados.\n");
						}
					}
				}
				else
				{
					printf("Debe pasar por la opcion 3 antes de mostrar resultados.\n");
				}
				flag6=0;
				printf("***********************************************************************\n");
				system("pause");
				break;
			case 5:
				printf("***********************************************************************\n");
				printf("Gracias por utilizar el calculeitor 9000 que tenga un exelente dia.!!!!\n");
				printf("***********************************************************************");
				break;
			default:
				printf("hay un error en el programa.!!!");
				break;
		}

	}while(opcion!=5);


	return EXIT_SUCCESS;
}
