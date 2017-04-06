#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    //declaracion de variables
    char seguir='s';
    int flag=0,flag1=0;
    char opcion=0;
    float numero1=0,numero2=0;
    float suma,resta,division,multiplicacion,factor;


    while(seguir=='s')
    {



            printf("1- Ingresar 1er operando (A=%.2f)\n",numero1);
            printf("2- Ingresar 2do operando (B=%.2f)\n",numero2);
            printf("3- Calcular la suma (A+B) \n");
            printf("4- Calcular la resta (A-B)\n");
            printf("5- Calcular la division (A/B)\n");
            printf("6- Calcular la multiplicacion (A*B)\n");
            printf("7- Calcular el factorial (A!)\n");
            printf("8- Calcular todas las operacione\n");
            printf("9- Salir\n");

            //se pide q se ingrese la opcion.
            printf(" \n\nIngrese una opcion: \n\n\n");
            opcion=getch();


            system("cls");



        switch(opcion)
        {
            case '1':
                // se pide el numero 1 y guarda;

                        printf("Ingrese el primer numero: \n");
                        scanf("%f", &numero1);
                        flag=1;

                        system("cls");


                break;


            case '2':
                    //se pide el segundo numero y se guarda .

                        printf("Ingrese el segundo numero: \n");
                        scanf("%f",&numero2);
                        flag1=1;

                        system("cls");

                break;
            case '3':
                    //se llama a la funcion suma del numero 1 y numero 2.
                    if(flag==1&&flag1==1)
                    {
                        suma = sumar(numero1,numero2);
                        printf( "La suma de %.2f+%.2f es: %.2f\n",numero1,numero2,suma);

                        system("pause");
                        system("cls");

                    }
                    else
                    {
                        //se pide pasar por el paso 1 y dos antes de poder sumar .
                        printf("Debe pasar por el paso 1 y 2 para continuar\n \a");

                        system("pause");
                        system("cls");
                    }

                    break;
            case '4':
                      if(flag==1&&flag1==1)
                    {
                        //se llama a la funcion resta.
                        resta=restar(numero1,numero2);
                        printf( "la resta de %.2f-%.2f es: %.2f\n",numero1,numero2,resta);

                        system("pause");
                        system("cls");
                    }
                    else
                    {
                        //se pide pasar por la opcion 1 y 2 antes de restar.
                        printf("Debe pasar por el paso 1 y 2 para continuar\n");

                        system("pause");
                        system("cls");
                    }


                break;
            case '5':

                if(numero2==0&&flag==1&&flag1==1)
                {
                    //se confirma q el divisor no sea 0 ya q no se puede dividir por 0.
                    printf("ERROR. No se puede dividir por 0!!!!! \n\a");

                    system("pause");
                    system("cls");
                }
                else
                {
                     if(flag==1&&flag1==1)
                    {
                        //se llama a la funcion dividir.
                        division=dividir(numero1,numero2);
                        printf( "La division de %.2f/%.2f es: %.2f\n",numero1,numero2,division);

                        system("pause");
                        system("cls");

                    }
                    else
                    {
                        //se pide pasar por el pasos 1 y 2 para poder dividir.
                        printf("Debe pasar por el paso 1 y 2 para continuar\n");

                        system("pause");
                        system("cls");
                    }


                }


                break;
            case '6':
                if(flag==1&&flag1==1)
                    {
                        //se llama a la funcion multiplicacion.
                        multiplicacion=multiplicar(numero1,numero2);
                        printf( "La multiplicacion de %.2f*%.2f es: %.2f\n",numero1,numero2,multiplicacion);

                        system("pause");
                        system("cls");
                    }
                    else
                    {
                        //se pide pasar a por la opcion numero 1 y 2 antes de poder multiplicar.
                        printf("Debe pasar por el paso 1 y 2 para continuar\n");

                        system("pause");
                        system("cls");
                    }


                break;
            case '7':

                if(flag==1)
                    {
                        //se llama a la funcion factorial.
                        factor=factoriar(numero1);
                        printf( "El factorial del numero %.2f es: %.2f\n",numero1,factor);

                        system("pause");
                        system("cls");
                    }
                    else
                    {
                        //se pide pasar por la opcion 1 para poder realizar el factorial.
                        printf("Debe pasar por el paso 1 para continuar\n");

                        system("pause");
                        system("cls");
                    }


                break;
            case '8':
                if(flag==1&&flag1==1)
                    {
                        //se llama a todas las funciones.
                        suma = sumar(numero1,numero2);
                        printf( "La suma de %.2f+%.2f es: %.2f\n\n",numero1,numero2,suma);

                        resta=restar(numero1,numero2);
                        printf( "la resta de %.2f-%.2f es: %.2f\n\n",numero1,numero2,resta);

                        if(numero2==0)//se asegura q no se divida por 0;
                        {
                            printf("La division es: ERROR. no se puede dividir por 0!!! \n");
                        }
                        else
                        {
                            division=dividir(numero1,numero2);
                            printf( "La division de %.2f/%.2f es: %.2f\n\n",numero1,numero2,division);
                        }


                        multiplicacion=multiplicar(numero1,numero2);
                        printf( "La multiplicacion de %.2f*%.2f es: %.2f\n\n",numero1,numero2,multiplicacion);


                        factor=factoriar(numero1);
                        printf( "El factorial del numero  %.2f es: %.2f\n\n\n",numero1,factor);

                        system("pause");
                        system("cls");

                    }
                    else
                    {
                        //se pide pasar por la opcion 1y 2 antes de mostrar las operaciones.
                        printf("Debe pasar por el paso 1 y 2 para continuar\n");

                        system("pause");
                        system("cls");
                    }
                break;

            case '9':
                seguir = 'n';
                break;

            default:
                printf("ERROR. el numero ingresado no esta entre las opciones!!!!\n \a");
                system("pause");
                system("cls");

                break;


        }


    }



    return 0;
}
