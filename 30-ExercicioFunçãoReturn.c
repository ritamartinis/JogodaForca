#ifdef _MSC_VER 
#define _CRT_SECURE_NO_WARNINGS 
#endif
#include <stdio.h>
#include <locale.h>	 


//Ao contr�rio do exerc�cio anterior, que era void, esta � int. E j� devolve valores.
//Recebe dois inteiros e devolve um inteiro que � a soma
int somaValores(int a, int b)	//recebe dois inteiros e devolve um inteiro (a soma)
{
	int soma;
	soma = a + b;
	return soma; //Devolve o valor da vari�vel soma 
}


void main()
{
	int a, b, soma; //vari�veis da fun��o main. N�o t�m nada a ver com o a e b da funcao mostraSoma. As do main s� s�o usadas no main e vice versa.
	setlocale(LC_ALL, "Portuguese");
	soma = somaValores(14, 21);
	printf("%d + %d = %d\n", 14, 21, soma);


	printf("Insira um valor: ");
	scanf(" %d", &a);
	printf("Insira um valor: ");
	scanf(" %d", &b);
	soma = somaValores(14, 21);	//Envio de valores de vari�veis para o void
	printf(" %d + %d = %d\n", a, b, soma);

	printf(" %d + %d = %d\n", a, 88, somaValores(a, 88));
}