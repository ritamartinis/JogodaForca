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
	int a, b; //vari�veis da fun��o main. N�o t�m nada a ver com o a e b da funcao mostraSoma. As do main s� s�o usadas no main e vice versa.
	setlocale(LC_ALL, "Portuguese");
	mostraSoma(14, 21); //Envio de valores num�ricos para a void

	printf("Insira um valor: ");
	scanf(" %d", &a);
	printf("Insira um valor: ");
	scanf(" %d", &b);
	mostraSoma(a, b);	//Envio de valores de vari�veis para o void
	mostraSoma(a, 88);	//Envio de uma vari�vel e um valor. 

}
