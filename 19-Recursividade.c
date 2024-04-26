#ifdef _MSC_VER 
#define _CRT_SECURE_NO_WARNINGS 
#endif
#include <stdio.h>
#include <locale.h>	
void func01(int n);
void func02(int n);

//Programa principal

void main()
{
	setlocale(LC_ALL, "Portuguese");
	int n;
	
	n = 1;
	printf("Valor: ");
	scanf(" %d", &n);
	if (n < 0)
		n = -n;
	prinf("= %d\n", func01(n));
}

//Implementação

//Estas duas funções, no fundo, simulam um ciclo. 
// Até ser 0, elas são saltar de uma função para a outra.
// O main chama a função 1, a 1 chama a 2 e a 2 volta a chamar a um até o valor ser 0.
// Tenho de ter obrigatoriamente condição de paragem.
// A isto chama-se Recursividade Indireta! 

void func01( int n)
{
	printf(" %d", n--);
	if (n <= 0)
		return;
	else
		func02(n);				//Ex: 10
}

void func02(int n)
{
	printf(" %d", n--);
		if (n <= 0)
			return;
		else
			func01(n);
}

//Se forem duas funções, Recursividade Indireta.
//Se for só uma função que se chama a si própria - Recursividade direta. A func01() chama-se a ela própria.

//Não vai ser pedido para avaliação nenhum exercício de recursividade.