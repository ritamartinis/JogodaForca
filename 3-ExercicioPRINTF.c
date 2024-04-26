#include <stdio.h>
void main()
{
	//No início da função, declaro as variáveis

	float y;				// declarei variável y
	int x = 10;				// declarei uma variável (x) e atribuí-lhe um valor (=). Em C = é <- (toma o valor de)
	char z;					// declarei variável z

	y = 20;					// Atribui o valor 
	z = 'Z';				// Atribui o valor e meti entre plicas. O caracter é entre plicas
	puts("Mostrar valores de variáveis;");
	printf("Valor de y : %f\n", y);		//MOSTRA("Valor de y: ", y) //%f para float
	printf("Valor de x : %d\n", x);		// %d ou %i para inteiros
	printf("Valor de x : %i\n", x);
	printf("Valor de z : %c\n", z);		// %c para carater

	printf("Valor de x : %i\n", 123);
	printf("Valor de x : %i\n", 100 + 23);
	printf("Valor de x : %i\n", 100 + x + 13); //tudo isto dá 123
}

	// Identar código: CTRL + K + D

/* Em C, a atribuição de valor faz - se com um =
* Então, na linha 7 temos uma variável do tipo inteiro e depois
* eu disse que x toma o valor de 10.
* Então, se o sinal de = é para "toma o valor de" como é que represento
* o sinal de igual? É com dois iguais.
* um sinal de igual é toma o valor de 
* dois sinais de igual é equivalência
* ex: x = 10
*	  x == y
* o x é igual ao y.
*/ 
