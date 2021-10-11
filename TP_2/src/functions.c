/*
 * funciones.c
 *
 *  Created on: 24 sep. 2021
 *      Author: Paul
 */
#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "arrayEmployees.h"
int upperFirstLetter(char* string)
{
	int ret=-1;
	int len;
	int i;
	if(string!=NULL)
	{
		len=strlen(string);
		for(i=0;i<len;i++)
		{
			if(i==0)
			{
				string[i]=toupper(string[i]);
			}
			if(string[i]==' ')
			{
				string[i+1]=toupper(string[i+1]);
			}
		}
		ret=0;
	}
	return ret;
}

int tolowerString(char* string)
{
	int ret=-1;
	int i;
	int len;
	if(string!=NULL)
	{
		len=strlen(string);
		for(i=0;i<len;i++)
		{
			string[i]=tolower(string[i]);
		}

		ret=0;
	}
	return ret;
}
int validateSigns(char* string)
{
	int i;
	int len;
	int ret=-1;
	if(string!=NULL)
	{
		len=strlen(string);
		tolowerString(string);
		for(i=0;i<len;i++)
		{

			if(string[i] < 97 || string[i] > 122)
			{

				ret=0;
				break;
			}
		}
	}
	return ret;
}
int requestNameOrLastName(char* string,char* message,char* messageError,int max)
{
	int ret=-1;
	char chainAux[200];
	if(string!=NULL && max>0)
	{
		printf("%s",message);
		fflush(stdin);
		scanf("%[^\n]",chainAux);

		while(strlen(chainAux)>max || isNumber(chainAux)==-1 || validateSigns(chainAux)==0)
		{
			printf("%s",messageError);
			fflush(stdin);
			scanf("%[^\n]",chainAux);
		}
		tolowerString(chainAux);
		upperFirstLetter(chainAux);
		strcpy(string,chainAux);
		ret=0;
	}
	return ret;
}

int isNumber(char* string)
{
	int ret=-1;
	int i;
	int tam;

	if(string!=NULL)
	{
		tam=strlen(string);

		for(i=0;i<tam;i++)
		{
			if(isdigit(string[i])==0 && string[i]!='.' && string[0]!='+' && string[0]!='-')
			{
				ret=0;
				break;
			}

		}

	}
	return ret;
}
int validateSpace(char* string)
{
	int returned=-1;
	int i;
	int tam;
	tam=strlen(string);
	for(i=0;i<tam;i++)
	{
		if(string[i] == ' ' || string[i] == '\t' || string[i] == '\v')
		{
			returned=0;
			break;
		}

	}
	return returned;
}


int requestNumber(int* num,char* message,char* messageError,int min, int max)
{
	int returned=-1;
	char numAux[51];
	int numIntAux;


	if(num!=NULL && message!=NULL && messageError!=NULL)
	{

		printf("%s",message);
		fflush(stdin);
		scanf("%[^\n]",numAux);
		numIntAux=atoi(numAux);


		while((!isNumber(numAux) && !validateSpace(message)) || (numIntAux>max||numIntAux<min))
		{
			printf("%s",messageError);
			fflush(stdin);
			scanf("%[^\n]",numAux);
			numIntAux=atoi(numAux);
		}

		*num=atoi(numAux);


		returned=0;
	}


	return returned;
}


int requestString(char* chain,char* message,char* messageError,int max)
{
	int returned=-1;
	char chainAux[200];

	if(chain!=NULL && max>0)
	{
		printf("%s",message);
		fflush(stdin);
		scanf("%[^\n]",chainAux);

		while(strlen(chainAux)>max)
		{
			printf("%s",messageError);
			fflush(stdin);
			scanf("%[^\n]",chainAux);
		}
		tolowerString(chainAux);
		strcpy(chain,chainAux);
		returned=0;
	}

	return returned;
}

int requestNumberFloat(float* num, char* message,char* messageError,int min,int max)
{
	int returned=-1;
	char numAux[51];
	float numFloatAux;
	if(num!=NULL && message!=NULL && messageError!=NULL)
	{
		printf("%s",message);
		fflush(stdin);
		scanf("%[^\n]",numAux);
		numFloatAux=atof(numAux);
		while((!isNumber(numAux) && !validateSpace(message)) || (numFloatAux<min ||numFloatAux>max))
		{
			printf("%s",messageError);
			fflush(stdin);
			scanf("%[^\n]",numAux);
			numFloatAux=atof(numAux);
		}
		*num=atof(numAux);
		returned=0;
	}
	return returned;
}
int requestCharacterAnswer(char* message)
{
	int ret=-1;
	char respuesta;
	if(message!=NULL)
	{
		requestCharacter(&respuesta,message);
		if(respuesta=='s'||respuesta=='S')
		{
			ret=0;
		}

	}
	return ret;
}

int requestCharacter(char* character, char* message)
{
	int ret = -1;

	if(character != NULL && message != NULL)
	{
		printf("%s", message);
		fflush(stdin);
		*character = getchar();
		ret = 0;
	}

	return ret;
}
int divideFloat(float* result,float num1,int num2)
{
	int ret=-1;

	if(result!=NULL)
	{
		*result=num1/num2;
		ret=0;
	}
	return ret;
}

int systemPause(char* message)
{
	int ret=-1;
	if(message!=NULL)
	{
		fflush(stdin);
		printf("\n%s",message);
		getchar();
		ret=0;
	}
	return ret;
}
