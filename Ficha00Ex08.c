#ifdef _MSC_VER 
#define _CRT_SECURE_NO_WARNINGS 
#endif
#include <stdio.h>
#include <locale.h>	 
void main()
{
	setlocale(LC_ALL, "Portuguese");
	int val1, val2, soma;

	printf("Introduza o primeiro valor: ");
	scanf(" %d", &val1);
	printf("Introduza o segundo valor: ");
	scanf(" %d", &val2);
	soma = val1 + val2;
	printf("A soma do primeiro valor (%d) com o segundo valor (%d) é = %d",val1, val2, soma);
}

/* ATENCAO
O & é SÓ E APENAS PARA O SCANF
NUNCA PARA O PRINTF
printf ("blablablablablabla" , variavel);
diferente de:
scanf ("%d", &variavel);
*/

