#ifdef _MSC_VER 
#define _CRT_SECURE_NO_WARNINGS 
#endif
#include <stdio.h>
#include <locale.h>	 
void boasVindas()
{
	puts("Bem vindo ao programa");
}


//Aqui, neste exemplo criámos uma função int!!
//Chama-se int somaValores
//Atenção que o x, y e a soma são diferentes do val1, val2 e soma do main.
int somaValores(int x, int y)
{
	int soma;
	soma = x + y;
	return soma;
}

float mediaValores(int x, int y)
{
	return (x + y) / 2;
}

void main()
{
	setlocale(LC_ALL, "Portuguese");
	int val1, val2, soma;
	boasVindas();
	printf("Valor 1: ");
	scanf("%d", &val1);
	printf("Valor 2: ");
	scanf("%d", &val2);
	soma = somaValores(val1, val2);		//Estou a chamar a função (que é int somaValores) para aqui.
										//É uma função do tipo int e tem de ter obrigatoriamente um return. Neste caso, devolve o resultado da soma.
	printf(" %d + %d = %d", val1, val2, soma);
	printf("Média = %f", mediaValores(val1, val2));	//Criei uma função do tipo float que se chama mediaValores
													//Aqui, estou a chamar a função. Fiz o calculo dentro da função float e aqui estou a chamar a função.

}

