//Elabore uma Calculadora em C. De disponibilizar pelo menos as 4 fun��es b�sicas. 

#ifdef _MSC_VER 
#define _CRT_SECURE_NO_WARNINGS 
#endif
#include <stdio.h>
#include <locale.h>	 
void main()
{
	setlocale(LC_ALL, "Portuguese");
	float val1, val2, soma, subtra��o, multiplica��o, divis�o;
	char fun��o_b�sica, c;		// +, -, *, /
	
	do 
	{
		printf("Introduza um n�mero: ");
		scanf(" %f", &val1);
		printf("Introduza outro n�mero: ");
		scanf(" %f", &val2);

		printf("Escolha a fun��o desejada: +, -, * ou /: ");
		scanf(" %c", &fun��o_b�sica);


		switch (fun��o_b�sica)
		{
		case '+':
			soma = val1 + val2;
			printf("O valor obtido �: %.2f\n", soma);
			break;
		case '-':
			subtra��o = val1 - val2;
			printf("O valor obtido �: %.2f\n", subtra��o);
			break;
		case '*':
			multiplica��o = val1 * val2;
			printf("O valor obtido �: %.2f\n", multiplica��o);
			break;
		case '/':
			divis�o = val1 / val2;
			printf("O valor obtido �: %.2f\n", divis�o);
			break;
		default:
			printf("Imposs�vel realizar essa opera��o.\n ");
		}
		do 
		{
			c = NULL;
			printf("Quer calcular novamente? S - sim ou N - n�o. \n");
			c = getch();
		} while (c != 'S' && c != 'N');
	} while (c == 'S');

}
