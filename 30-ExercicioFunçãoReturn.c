#ifdef _MSC_VER 
#define _CRT_SECURE_NO_WARNINGS 
#endif
#include <stdio.h>
#include <locale.h>	 


//Ao contrário do exercício anterior, que era void, esta é int. E já devolve valores.
//Recebe dois inteiros e devolve um inteiro que é a soma
int somaValores(int a, int b)	//recebe dois inteiros e devolve um inteiro (a soma)
{
	int soma;
	soma = a + b;
	return soma; //Devolve o valor da variável soma 
}


void main()
{
	int a, b, soma; //variáveis da função main. Não têm nada a ver com o a e b da funcao mostraSoma. As do main só são usadas no main e vice versa.
	setlocale(LC_ALL, "Portuguese");
	soma = somaValores(14, 21);
	printf("%d + %d = %d\n", 14, 21, soma);


	printf("Insira um valor: ");
	scanf(" %d", &a);
	printf("Insira um valor: ");
	scanf(" %d", &b);
	soma = somaValores(14, 21);	//Envio de valores de variáveis para o void
	printf(" %d + %d = %d\n", a, b, soma);

	printf(" %d + %d = %d\n", a, 88, somaValores(a, 88));
}