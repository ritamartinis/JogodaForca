
/*Escreva em programa na linguagem C que calcule a �rea de um pol�gono. Inicialmente o operador deve
escolher o tipo de pol�gono que pretende calcular
1 � Quadrado ou Ret�ngulo (lado * lado)
2 � Triangulo (base * altura / 2)
3 � C�rculo (PI * raio^2 ? 3.14 * raio^2)
0 � Fim do programa
No caso de escolher Zero sai do programa, no caso de escolher 1, 2 ou 3 o programa pede-lhe os dados
necess�rios e mostra o resultado do c�lculo respetivo.*/

//Introdu��o de nova mat�ria: CONSTANTES!
//Elas s�o declaradas ANTES do programa (tal como em pseudoc�digo).

#ifdef _MSC_VER 
#define _CRT_SECURE_NO_WARNINGS 
#endif
#include <stdio.h>
#include <locale.h>	

#define PI 3.14f

void main()
{
	setlocale(LC_ALL, "Portuguese");
	int pol;
	float lado1, lado2, area, base, altura, raio;

	printf("Indique o poligono que deseja: \n");
	printf("1-Quadrado ou Ret�ngulo\n");
	printf("2-Triangulo\n");
	printf("3-Circulo\n");
	printf("4-Sair do programa\n");
	scanf("%d", &pol);

	if (pol == 1)
	{
		printf("Ent�o, indique o valor do primeiro lado em cm: \n");
		scanf("%f", &lado1);
		printf("Ent�o, indique o valor do segundo lado em cm: \n");
		scanf("%f", &lado2);
		area = lado1 * lado2;
		printf("A �rea do quadrado ou rectangulo �: %f", area);
	}
	else
		if (pol == 2)
		{
			printf("Ent�o, indique o valor da base em cm: \n");
			scanf("%f", &base);
			printf("Ent�o, indique o valor da altura em cm: \n");
			scanf("%f", &altura);
			area = (base * altura) / 2;
			printf("A �rea do triangulo �: %f", area);
		}
		else
			if (pol == 3)
			{
				printf("Ent�o indique o valor do raio em cm: \n");
				scanf("%f", &raio);
				area = PI * raio * raio;
				printf("A �rea do circulo �: %f", area);
			}
			else
				if (pol == 4)
					printf("\nVolte sempre\n");
				else
					if (pol <= 0)
						printf("Medidas introduzidas s�o inv�lidas. Imposs�vel calcular");
}

/* Problemas a resolver:
* medidas inv�lidas se valores introduzidos pelo utilizador <= 0
* se outra opcao != 1,2,3 ou 4 for seleccionada
*/

/* COMO DECLARAR CONSTANTES:
* ANTES DO MAIN
* #define 
* NOME DA CONSTANTE (em maiusculas) + valor da constante + f (se for float) ou nada se for de outro tipo. 
*/

