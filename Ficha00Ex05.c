#ifdef _MSC_VER 
#define _CRT_SECURE_NO_WARNINGS 
#endif
#include <stdio.h>
#include <locale.h>	 
void main()
{
	int a, b;
	printf("Qual o valor de a?");
	scanf(" %d,", &a);
	printf("Qual o valor de b?");
	scanf(" %d", &b);
	printf("O valor de a : %d valor de b: %d", a, b);
}