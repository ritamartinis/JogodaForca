/* O seu programa deve pedir ao utilizador 2 valores reais
Com auxilio de 4 funções que deovlvem o resultado, 
mostre esse mesmo resultado das 4 operações artimeticas simples com esses valores.
Ex:
Valor 1: 12
Valor 2: 4
12 + 4 = 16 
12 - 4 = 8
12 * 4 = 48
12 / 4 = 3
*/

#ifdef _MSC_VER 
#define _CRT_SECURE_NO_WARNINGS 
#endif
#include <stdio.h>
#include <locale.h>	 

float somaValores(float x, float y)
{
	float soma;
	soma = x + y;
	return soma;
}

float subtraiValores(float x, float y)
{
	float subtrair;
	subtrair = x - y;
	return subtrair;
}

float multiplicaValores(float x, float y)
{
	float multiplicacao;
	multiplicacao = x * y;
	return multiplicacao;
}

float divideValores(float x, float y)
{
	float divisao;
	
	if (y == 0)
	{
		printf("Impossível dividir por zero.\n");
		return 0;
	}
	else
	{
		divisao = x / y;
		return divisao;
	}
			
}

void main()
{
	float a, b;
	char c;
	setlocale(LC_ALL, "Portuguese");
	
	do 
	{
		printf("Insira o primeiro valor: ");
		scanf(" %f", &a);
		printf("Insira o segundo valor: ");
		scanf(" %f", &b);
		printf("\nA soma dos valores é: %.1f + %.1f = %.1f\n", a, b, somaValores(a, b));
		printf("A subtração dos valores é: %.1f - %.1f = %.1f\n", a, b, subtraiValores(a, b));
		printf("A multiplicação dos valores é: %.1f * %.1f = %.1f\n", a, b, multiplicaValores(a, b));
		if (b != 0)
			printf("A divisão dos valores é: %.1f / %.1f = %.1f\n", a, b, divideValores(a, b));
		else
			printf("Impossível dividir por zero.\n");

		do
		{
			c = NULL;
			printf("\nQuer introduzir novos valores?\n S - sim ou N - não. \n");
			c = getch();
		} while (c != 'S' && c != 'N');

	} while (c == 'S');


}