/* Repetidamente enquanto o utilizador assim o desejar:
* Suponha que pretende calcular a nota (de 0 a 20) de uma disciplina com 3 componentes de avaliação.
* Avaliação formativa - peso de 4 valores.
* Trabalho prático - peso de 8 valores.
* Exame - peso de 8 valores.
* Elabore um programa que calcule a nota final.
*/

#ifdef _MSC_VER 
#define _CRT_SECURE_NO_WARNINGS 
#endif
#include <stdio.h>
#include <locale.h>	 
void main()
{
	setlocale(LC_ALL, "Portuguese");
	float a, b, c;
	float nota_final;
	int opcao;

	do
	{ 

		printf("Introduza a nota da avaliação formativa:\n ");
		scanf(" %f", &a);
		printf("Introduza a nota do trabalho prático:\n ");
		scanf(" %f", &b);
		printf("Introduza a nota do exame:\n ");
		scanf(" %f", &c);

		// regra de 3 simples:
		// a - 20% da nota
		// b e c - 40% da nota

		a = a * 0.2;
		b = b * 0.4;
		c = c * 0.4;
		nota_final = a + b + c;

		printf("A sua nota final é: %.1f\n", nota_final);
		if (nota_final >= 9.5)
			puts("Aluno Aprovado. ");
		else
			puts("Estudasses... ");

		printf("\nDeseja calcular novamente as suas notas? Sim - 1 ou Não - 2 ");
		scanf(" %d", &opcao);
	} while (opcao != 2);

}

