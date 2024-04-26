#ifdef _MSC_VER 
#define _CRT_SECURE_NO_WARNINGS 
#endif
#include <stdio.h>
#include <locale.h>	 
void main()
{
	setlocale(LC_ALL, "Portuguese");
	int x;
	printf("Insira um valor inteiro:");
	scanf(" %d", &x);
	printf("O valor de x é %d", x);
}
