#ifdef _MSC_VER 
#define _CRT_SECURE_NO_WARNINGS 
#endif
#include <stdio.h>
#include <locale.h>	 
void main()
{
	setlocale(LC_ALL, "Portuguese");
	float real, dobro;

	printf("Insira um valor real:");
	scanf("%f", &real);
	dobro = real * 2;
	printf("O dobro do valor inserido é %f", dobro);
}
/* De outra forma:
* float real;
* printf("Insira um valor real:");
*scanf("%f", &real);
*printf("O dobro de %f é %f", real, 2 * real); *\

