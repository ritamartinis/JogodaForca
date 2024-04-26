// Tendo em conta o exercício anterior, das temperaturas. Apenas vamos criar uma função fora do main.

#ifdef _MSC_VER 
#define _CRT_SECURE_NO_WARNINGS 
#endif
#include <stdio.h>
#include <locale.h>	 

void mostraDia(int d)
{
	switch (d)
	{
	case 1:
		printf("Domingo: ");
		break;
	case 2:
		printf("Segunda-feira: ");
		break;
	case 3:
		printf("Terça-feira: ");
		break;
	case 4:
		printf("Quarta-feira: ");
		break;
	case 5:
		printf("Quinta-feira: ");
		break;
	case 6:
		printf("Sexta-feira: ");
		break;
	case 7:
		printf("Sábado: ");
		break;
	}
}

void main()
{
	setlocale(LC_ALL, "Portuguese");
	float temp[7];
	float soma;
	int j, dia;

	for (int i = 0; i < 7; i++)
	{
		printf("Temperatura de ");
		mostraDia(i + 1);
		scanf(" %f", &temp[i]);
	}

	printf("Temperaturas registadas [ ");
	for (int i = 0; i < 7; i++)
		printf(" %.1f ", temp[i]);
	printf(" ]\n");

	soma = 0;
	j = 0;
	while (j < 7)
	{
		soma = soma + temp[j];
		j = j + 1;
	}

	do 
	{
		printf("Temperatura média = %.1f\n", soma / 7);
		printf("Escolhe um dia: ");
		scanf(" %d", &dia);
		if (dia < 1 || dia > 7)
			puts("A semana tem 7 dias. SABIAS?!");
		else
		{
			printf("Corresponde a ");
			mostraDia(dia);
			printf("\nA temperatura registada foi de : %.1f\n", temp[dia - 1]);
			// o array é de 0 a 6 mas os dias são de 1 a 7. Para isso, tenho de substrair 1 quando mostro ao utilizador
			// para ele saber que a domingo é o 1 (embora ela seja o 0).
			// ie, ela ocupa o espaço 0 mas é o 1º a ser mostrado ao utilizador.
		}
	} while (dia != 0);
	
}