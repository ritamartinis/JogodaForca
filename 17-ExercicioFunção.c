#ifdef _MSC_VER 
#define _CRT_SECURE_NO_WARNINGS 
#endif
#include <stdio.h>
#include <locale.h>	 
void boasVindas()
{
	puts("Bem vindo ao programa");
}


//Aqui, neste exemplo cri�mos uma fun��o int!!
//Chama-se int somaValores
//Aten��o que o x, y e a soma s�o diferentes do val1, val2 e soma do main.
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
	soma = somaValores(val1, val2);		//Estou a chamar a fun��o (que � int somaValores) para aqui.
										//� uma fun��o do tipo int e tem de ter obrigatoriamente um return. Neste caso, devolve o resultado da soma.
	printf(" %d + %d = %d", val1, val2, soma);
	printf("M�dia = %f", mediaValores(val1, val2));	//Criei uma fun��o do tipo float que se chama mediaValores
													//Aqui, estou a chamar a fun��o. Fiz o calculo dentro da fun��o float e aqui estou a chamar a fun��o.

}

