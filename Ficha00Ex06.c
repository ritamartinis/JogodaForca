#ifdef _MSC_VER 
#define _CRT_SECURE_NO_WARNINGS 
#endif
#include <stdio.h>
#include <locale.h>	 
void main()
{
	setlocale(LC_ALL, "Portuguese");
	int a, b, soma;

	printf("Insira o valor de a: ");
	scanf(" %d", &a);
	printf("Insira o valor de b: ");
	scanf(" %d", &b);
	printf("O valor de a é %d e o valor de b é %d\n", a, b);
	soma = a + b;
	printf("A soma dos dois valores corresponde a %d.", soma);
}