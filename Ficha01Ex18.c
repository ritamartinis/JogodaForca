#ifdef _MSC_VER 
#define _CRT_SECURE_NO_WARNINGS 
#endif
#include <stdio.h>
#include <locale.h>	
#include <math.h>

void calculos(float valor);


void main()
{
	setlocale(LC_ALL, "Portuguese");

	float valor;

	do
	{
		printf("Introduza o valor que pretende saber o troco ou 0 para sair: \n");
		scanf(" %f", &valor);

		if (valor > 0)
			calculos(valor);
		else
			if (valor < 0)
				valor = -valor;
			else
				if (valor == 0)
				{
					printf("Até à próxima...\n");
					return;
				}
	} while (valor != 0);
}
		
void calculos(float valor)
{
	int eur2, eur1, cent50, cent20, cent10, cent5, cent2, cent1;
	
	eur2 = valor / 2;
	valor = valor - eur2 * 2;

	eur1 = valor / 1;
	valor = valor - eur1 * 1;

	cent50 = valor / 0.5;
	valor = valor - cent50 * 0.5;

	cent20 = valor / 0.2;
	valor = valor - cent20 * 0.2;

	cent10 = valor / 0.1;
	valor = valor - cent10 * 0.1;

	cent5 = valor / 0.05;
	valor = valor - cent5 * 0.05;

	cent2 = valor / 0.02;
	valor = valor - cent2 * 0.02;

	cent1 = valor / 0.01;
	valor = valor - cent1 * 0.01;

	printf("O valor pode ser trocado em:\n");

	if (eur2 > 0)
		printf(" %d moedas de 2 euros\n", eur2);

	if (eur1 > 0)
		printf(" %d moedas de 1 euro\n", eur1);

	if (cent50 > 0)
		printf(" %d moedas de 50 centimos\n", cent50);

	if (cent20 > 0)
		printf(" %d moedas de 20 centimos\n", cent20);

	if (cent10 > 0)
		printf(" %d moedas de 10 centimos\n", cent10);

	if (cent5 > 0)
		printf(" %d moedas de 5 centimos\n", cent5);

	if (cent2 > 0)
		printf(" %d moedas de 2 centimos\n", cent2);

	if (cent1 > 0)
		printf(" %d moedas de 1 centimo\n", cent1);
}