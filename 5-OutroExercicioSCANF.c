#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <stdio.h>
#include <locale.h>
void main()
{

	//Variáveis
	int x;
	float y;
	
	//Inicio do programa
	setlocale(LC_ALL, "Portuguese");
	printf("Insira um inteiro:");
	scanf(" %d", &x); //ou %i
	printf("Insira um real:");
	scanf(" %f", &y);
	printf(" %d + %f = %f\n", x, y, x + y);
	printf("O valor de x é %d\nO Valor de y é %f\n O Total é = %f\n", x, y, x + y);
}

