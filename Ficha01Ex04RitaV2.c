#ifdef _MSC_VER 
#define _CRT_SECURE_NO_WARNINGS 
#endif
#include <stdio.h>
#include <locale.h>

float getNota()
{
	float n = 0;
	do 
	{
		scanf("%f", &n);
		if (n < 0 || n > 20)
			printf("Nota inválida. Insira novamente: ");
	} while (n < 0 || n > 20);
	return n;
}

float getNotaFinal(float a, float b, float c)
{
	int nota_final;
	// regra de 3 simples:
	// a - 20% da nota
	// b e c - 40% da nota

	a = a * 0.2;
	b = b * 0.4;
	c = c * 0.4;
	nota_final = a + b + c;
	return nota_final;
}

void main()
{
	setlocale(LC_ALL, "Portuguese");
	float a, b, c;
	float nota_final;
	int opcao;

	do
	{

		printf("Introduza a nota da avaliação formativa:\n ");
		a = getNota();
		printf("Introduza a nota do trabalho prático:\n ");
		b = getNota();
		printf("Introduza a nota do exame:\n ");
		c = getNota();

		nota_final = getNotaFinal(a,b,c);

		printf("A sua nota final é: %.1f\n", nota_final);
		if (nota_final >= 9.5)
			puts("Aluno Aprovado. ");
		else
			puts("Estudasses... ");

		printf("\nDeseja calcular novamente as suas notas? Sim - 1 ou Não - 2 ");
		scanf(" %d", &opcao);
	} while (opcao != 2);

}

