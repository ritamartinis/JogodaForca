// Elabore um algoritmo que receba 7 valores reais correspondentes às temperaturas máximas registadas numa determinada semana.
//  Posteriormente deverá informar o utilizador qual a temperatura mais alta e a temperatura mais baixa da semana.

#ifdef _MSC_VER 
#define _CRT_SECURE_NO_WARNINGS 
#endif
#include <stdio.h>
#include <locale.h>	 
void main()
{
	setlocale(LC_ALL, "Portuguese");
	//PEGAMOS NO EXERCICIO ANTERIOR E VAMOS SUBSTITUIR PELO CICLO WHILE!
	//Ao contrário do ciclo FOR, aqui não posso declarar variáveis aquando do ciclo. Têm de ser no início como as outras.


	//declarar variáveis
	float t, soma=0;
	int i;
	float temperatura_max, temperatura_min;

	//receber as temperaturas
	printf("Insira as 7 temperaturas máximas registadas. \n");

	i = 1;
	while (i <= 7)
	{
		printf("Dia %d:", i);
		scanf(" %f", &t);
		soma = soma + t;
		if (i == 1)
		{
			temperatura_min = t;
			temperatura_max = t;
		}
		else
			if (t >= temperatura_max)
				temperatura_max = t;
			else
				if (t <= temperatura_min)
					temperatura_min = t;
		i = i + 1;
	}

	printf("A temperatura mais alta da semana foi %.2f e a mais baixa foi %.2f\n", temperatura_max, temperatura_min);
	printf("A média registada foi %.2f", soma / 7);

	getch();
}
