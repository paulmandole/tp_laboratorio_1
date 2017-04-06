#include <stdio.h>
#include <stdlib.h>
// funcion sumar se realizan las operaciones
float sumar(float numero1, float numero2)
{

    float suma;



    suma=numero1+numero2;

    return suma;


}

//funcion restar se realizan las operaciones
float restar(float numero1,float numero2)
{
    float resta;


    resta=numero1-numero2;

    return resta;

}

//funcion dividir se realizan las operaciones
float dividir(float numero1,float numero2)
{
    float division;


    division=numero1/numero2;

    return division;


}
//funcion multiplicar se realizan las operaciones
float multiplicar(float numero1,float numero2)
{
    float multiplicacion;


    multiplicacion=numero1*numero2;

    return multiplicacion;
}
//funcion factorial se realizan las operaciones
float factoriar(float numero1)
{

    float factor=1;
    int cont;



    for(cont=1;cont<=numero1;cont++)
    {
        factor=factor*cont;
    }

    return factor;
}
