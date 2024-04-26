/*O seu programa deve receber valores reais e guarda-los num vetror.
Posteriormente deve percorrer o vetor e calcular e mostrar a média dos valores introduzidos.
 */

#ifdef _MSC_VER 
#define _CRT_SECURE_NO_WARNINGS 
#endif
#include <stdio.h>
#include <locale.h>	 

void main()
{
	setlocale(LC_ALL, "Portuguese");
	float temp[7];
	float soma;
	int j, dia;

	for (int i = 0; i < 7; i++)
	{
		printf("Temperatura de ");
		dia = i + 1;
		switch (dia)
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
	printf("Temperatura média = %.1f", soma / 7);
}