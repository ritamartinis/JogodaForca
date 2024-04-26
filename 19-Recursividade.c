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

//Implementa��o

//Estas duas fun��es, no fundo, simulam um ciclo. 
// At� ser 0, elas s�o saltar de uma fun��o para a outra.
// O main chama a fun��o 1, a 1 chama a 2 e a 2 volta a chamar a um at� o valor ser 0.
// Tenho de ter obrigatoriamente condi��o de paragem.
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

//Se forem duas fun��es, Recursividade Indireta.
//Se for s� uma fun��o que se chama a si pr�pria - Recursividade direta. A func01() chama-se a ela pr�pria.

//N�o vai ser pedido para avalia��o nenhum exerc�cio de recursividade.