#include <stdio.h>
void main()
{
	//No in�cio da fun��o, declaro as vari�veis

	float y;				// declarei vari�vel y
	int x = 10;				// declarei uma vari�vel (x) e atribu�-lhe um valor (=). Em C = � <- (toma o valor de)
	char z;					// declarei vari�vel z

	y = 20;					// Atribui o valor 
	z = 'Z';				// Atribui o valor e meti entre plicas. O caracter � entre plicas
	puts("Mostrar valores de vari�veis;");
	printf("Valor de y : %f\n", y);		//MOSTRA("Valor de y: ", y) //%f para float
	printf("Valor de x : %d\n", x);		// %d ou %i para inteiros
	printf("Valor de x : %i\n", x);
	printf("Valor de z : %c\n", z);		// %c para carater

	printf("Valor de x : %i\n", 123);
	printf("Valor de x : %i\n", 100 + 23);
	printf("Valor de x : %i\n", 100 + x + 13); //tudo isto d� 123
}

	// Identar c�digo: CTRL + K + D

/* Em C, a atribui��o de valor faz - se com um =
* Ent�o, na linha 7 temos uma vari�vel do tipo inteiro e depois
* eu disse que x toma o valor de 10.
* Ent�o, se o sinal de = � para "toma o valor de" como � que represento
* o sinal de igual? � com dois iguais.
* um sinal de igual � toma o valor de 
* dois sinais de igual � equival�ncia
* ex: x = 10
*	  x == y
* o x � igual ao y.
*/ 
