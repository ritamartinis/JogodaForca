
/*Escreva em programa na linguagem C que calcule a área de um polígono. Inicialmente o operador deve
escolher o tipo de polígono que pretende calcular
1 – Quadrado ou Retângulo (lado * lado)
2 – Triangulo (base * altura / 2)
3 – Círculo (PI * raio^2 ? 3.14 * raio^2)
0 – Fim do programa
No caso de escolher Zero sai do programa, no caso de escolher 1, 2 ou 3 o programa pede-lhe os dados
necessários e mostra o resultado do cálculo respetivo.*/

//Introdução de nova matéria: CONSTANTES!
//Elas são declaradas ANTES do programa (tal como em pseudocódigo).

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
	printf("1-Quadrado ou Retângulo\n");
	printf("2-Triangulo\n");
	printf("3-Circulo\n");
	printf("4-Sair do programa\n");
	scanf("%d", &pol);

	if (pol == 1)
	{
		printf("Então, indique o valor do primeiro lado em cm: \n");
		scanf("%f", &lado1);
		printf("Então, indique o valor do segundo lado em cm: \n");
		scanf("%f", &lado2);
		area = lado1 * lado2;
		printf("A área do quadrado ou rectangulo é: %f", area);
	}
	else
		if (pol == 2)
		{
			printf("Então, indique o valor da base em cm: \n");
			scanf("%f", &base);
			printf("Então, indique o valor da altura em cm: \n");
			scanf("%f", &altura);
			area = (base * altura) / 2;
			printf("A área do triangulo é: %f", area);
		}
		else
			if (pol == 3)
			{
				printf("Então indique o valor do raio em cm: \n");
				scanf("%f", &raio);
				area = PI * raio * raio;
				printf("A área do circulo é: %f", area);
			}
			else
				if (pol == 4)
					printf("\nVolte sempre\n");
				else
					if (pol <= 0)
						printf("Medidas introduzidas são inválidas. Impossível calcular");
}

/* Problemas a resolver:
* medidas inválidas se valores introduzidos pelo utilizador <= 0
* se outra opcao != 1,2,3 ou 4 for seleccionada
*/

/* COMO DECLARAR CONSTANTES:
* ANTES DO MAIN
* #define 
* NOME DA CONSTANTE (em maiusculas) + valor da constante + f (se for float) ou nada se for de outro tipo. 
*/

