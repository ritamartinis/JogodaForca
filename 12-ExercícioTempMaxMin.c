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
	//declarar variáveis
	float t1, t2, t3, t4, t5, t6, t7;
	float temperatura_max, temperatura_min;

	//receber as temperaturas
	printf("Insira as 7 temperaturas máximas registadas. \n");

	printf("Dia 1: ");
	scanf(" %f", &t1);
	temperatura_max = t1;
	temperatura_min = t1;
	
	printf("Dia 2: ");
	scanf(" %f", &t2);
	if (t2 > temperatura_max)
		temperatura_max = t2;
	else
		if (t2 <= temperatura_min)
			temperatura_min = t2;

	printf("Dia 3: ");
	scanf(" %f", &t3);
	if (t3 > temperatura_max)
		temperatura_max = t3;
	else
		if (t3 <= temperatura_min)
			temperatura_min = t3;
	printf("Dia 4: ");
	scanf(" %f", &t4);
	if (t4 > temperatura_max)
		temperatura_max = t4;
	else
		if (t4 <= temperatura_min)
			temperatura_min = t4;

	printf("Dia 5: ");
	scanf(" %f", &t5);
	if (t5 > temperatura_max)
		temperatura_max = t5;
	else
		if (t5 <= temperatura_min)
			temperatura_min = t5;
	
	printf("Dia 6: ");
	scanf(" %f", &t6);
	if (t6 > temperatura_max)
		temperatura_max = t6;
	else
		if (t6 <= temperatura_min)
			temperatura_min = t6;

	printf("Dia 7: ");
	scanf(" %f", &t7);
	if (t7 > temperatura_max)
		temperatura_max = t7;
	else
		if (t7 <= temperatura_min)
			temperatura_min = t7;

	printf("A temperatura mais alta da semana foi %.1f e a mais baixa foi %.1f", temperatura_max, temperatura_min);

}