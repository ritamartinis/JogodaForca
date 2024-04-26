#ifdef _MSC_VER 
#define _CRT_SECURE_NO_WARNINGS 
#endif
#include <stdio.h>
#include <locale.h>	
#include <limits.h>
void main()
{
	printf("sizeof(char)  = %d\n", sizeof(char));
	printf("sizeof(int)   = %d\n", sizeof(int));
	printf("INT_MAX       = %d\n", INT_MAX);
	printf("sizeof(float) = %d\n", sizeof(float));
	printf("sizeof(double)= %d\n", sizeof(double));
	getch();
}

//Incluir a biblioteca limits.h
//Para podermos ver o nr de bytes possíveis para as variaveis.
//Sem grande relevo isto mas ok
