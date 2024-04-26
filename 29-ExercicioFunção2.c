#ifdef _MSC_VER 
#define _CRT_SECURE_NO_WARNINGS 
#endif
#include <stdio.h>
#include <locale.h>	 

void mostraSoma(int a, int b)
{
	int soma;
	soma = a + b;
	printf(" %d + %d = %d\n", a, b, a + b);
	printf(" %d + %d = %d\n", a, b, soma);
}


void main()
{
	int a, b; //variáveis da função main. Não têm nada a ver com o a e b da funcao mostraSoma. As do main só são usadas no main e vice versa.
	setlocale(LC_ALL, "Portuguese");
	mostraSoma(14, 21); //Envio de valores numéricos para a void

	printf("Insira um valor: ");
	scanf(" %d", &a);
	printf("Insira um valor: ");
	scanf(" %d", &b);
	mostraSoma(a, b);	//Envio de valores de variáveis para o void
	mostraSoma(a, 88);	//Envio de uma variável e um valor. 

}
