//Elabore uma Calculadora em C. De disponibilizar pelo menos as 4 funções básicas. 

#ifdef _MSC_VER 
#define _CRT_SECURE_NO_WARNINGS 
#endif
#include <stdio.h>
#include <locale.h>	 
void main()
{
	setlocale(LC_ALL, "Portuguese");
	float val1, val2, soma, subtração, multiplicação, divisão;
	char função_básica, c;		// +, -, *, /
	
	do 
	{
		printf("Introduza um número: ");
		scanf(" %f", &val1);
		printf("Introduza outro número: ");
		scanf(" %f", &val2);

		printf("Escolha a função desejada: +, -, * ou /: ");
		scanf(" %c", &função_básica);


		switch (função_básica)
		{
		case '+':
			soma = val1 + val2;
			printf("O valor obtido é: %.2f\n", soma);
			break;
		case '-':
			subtração = val1 - val2;
			printf("O valor obtido é: %.2f\n", subtração);
			break;
		case '*':
			multiplicação = val1 * val2;
			printf("O valor obtido é: %.2f\n", multiplicação);
			break;
		case '/':
			divisão = val1 / val2;
			printf("O valor obtido é: %.2f\n", divisão);
			break;
		default:
			printf("Impossível realizar essa operação.\n ");
		}
		do 
		{
			c = NULL;
			printf("Quer calcular novamente? S - sim ou N - não. \n");
			c = getch();
		} while (c != 'S' && c != 'N');
	} while (c == 'S');

}
