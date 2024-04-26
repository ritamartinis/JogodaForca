#ifdef _MSC_VER 
#define _CRT_SECURE_NO_WARNINGS 
#endif
#include <stdio.h>
#include <locale.h>

#define PI 3.14f 

void main()
{
	setlocale(LC_ALL, "Portuguese");
	int opcao;
	float medida1, medida2, area;
	
	printf("+-----------------------+\n");
	printf("|          M E N U      |\n");
	printf("+-----------------------+\n");
	printf("| 1 - quadrado          |\n");
	printf("| 2 - triangulo         |\n");
	printf("| 3 - circulo           |\n");
	printf("| 4 - fim de programa   |\n");
	printf("+-----------------------+\n");

	printf("Escolha a opção que deseja:");
	scanf("%d", &opcao);

	if (opcao == 1)
	{
		printf("Medida do lado:");
		scanf("%f", &medida1);
		if (medida1 <= 0)
			puts("Medida inválida. ");
		else
		{
			area = medida1 * medida1;
			printf("Area = %f", area);
		}
	}
	else
		if (opcao == 2)
		{
			printf("Medida da base:");
			scanf("%f", &medida1);
			printf("Medida da altura:");
			scanf("%f", &medida2);
			if (medida1 <= 0 || medida2 <= 0)
				puts("Medida inválida. ");
			else
			{
				area = (medida1 * medida2) / 2;
				printf("Area = %f", area);
			}
		}
		else
			if (opcao == 3)
			{
				printf("Medida do raio:");
				scanf("%f", &medida1);
				if (medida1 <= 0)
					puts("Medida inválida. ");
				else
				{
					area = PI * medida1 * medida1;
					//para fazer a potenciação, ou faço assim ou uso a função pow.
					//pow(medida1, 2) <- para isso necessito da biblioteca math.h
					printf("Area = %f", area);
				}
			}
			else
				if (opcao == 4)
					printf("Volte sempre.");
				else
					puts("Opção inválida. ");

}
/* C já tem algumas constantes definidas para matemática, como é o caso do PI. 
* Assim, em vez eu a declarar, posso ir buscar a biblioteca, adiciona-la ao codigo e assim o programa já a reconhece sem declarar.
* Para isso:
* #define _USE_MATH_DEFINES	// Para usar as constantes definidas em C
* #include <math.h>
* Caso contrário, a declaração é:
* NOME + VALOR + f (se for) ou nada.
*/