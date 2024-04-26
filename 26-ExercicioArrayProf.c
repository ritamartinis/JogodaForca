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
	int j;

	for (int i = 0; i < 7; i++)
	{
		printf("Temperatura do dia [%d]:", i + 1);
		scanf(" %f", & temp[i]);
	}

	printf("Temperaturas registadas [ ");
	for (int i = 0; i < 7; i++)
		printf(" %f ", temp[i]);
	printf(" ]\n");

	soma = 0;
	j = 0;
	while (j < 7)
	{
		soma = soma + temp[j];
		j = j + 1;
	}
	printf("Temperatura média = %f", soma / 7);
}