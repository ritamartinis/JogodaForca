// Elabore um algoritmo que receba 7 valores reais correspondentes �s temperaturas m�ximas registadas numa determinada semana.
//  Posteriormente dever� informar o utilizador qual a temperatura mais alta e a temperatura mais baixa da semana.

#ifdef _MSC_VER 
#define _CRT_SECURE_NO_WARNINGS 
#endif
#include <stdio.h>
#include <locale.h>	 
void main()
{
	setlocale(LC_ALL, "Portuguese");
	//PEGAMOS NO EXERCICIO ANTERIOR E VAMOS SUBSTITUIR PELO CICLO WHILE!
	//Ao contr�rio do ciclo FOR, aqui n�o posso declarar vari�veis aquando do ciclo. T�m de ser no in�cio como as outras.


	//declarar vari�veis
	float t, soma=0;
	int i;
	float temperatura_max, temperatura_min;

	//receber as temperaturas
	printf("Insira as 7 temperaturas m�ximas registadas. \n");

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
	printf("A m�dia registada foi %.2f", soma / 7);

	getch();
}
