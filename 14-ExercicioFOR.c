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
	//PEGAMOS NO EXERCICIO ANTERIOR E VAMOS SUBSTITUIR OS IF POR UM CICLO! NESTE CASO, O FOR.
	//Vamos tamb�m fazer a m�dia das temperaturas da semana.


	//declarar vari�veis
	float t;
	float temperatura_max, temperatura_min;
	float soma = 0;

	//receber as temperaturas
	printf("Insira as 7 temperaturas m�ximas registadas. \n");


	//O �NICO sitio onde posso declarar vari�veis sem ser no in�cio, � no FOR.
	// Estou a declarar a variavel i que corre no ciclo e � condi��o de paragem. Auxiliar do ciclo, apenas.
	//o ciclo vai-se repetir do dia 1 ao dia 7 e vai correr enquanto a var i for menor ou igual a 7. 
	
	for (int i = 1; i <= 7; i = i + 1)
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
	}

	printf("A temperatura mais alta da semana foi %.2f e a mais baixa foi %.2f\n", temperatura_max, temperatura_min);
	printf("A m�dia registada foi: %.2f", soma / 7);

	getch();
}

