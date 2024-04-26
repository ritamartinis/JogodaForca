/*Programa igual ao anterior mas com mais poligonos, a saber :
 1 - quadrado
 2 - retangulo
 3 - triangulo
 4 - circulo
 5 - pentagono regular (perimetro * apotema) /2
 6 - hexagono regular  (perimetro * apotema) /2
 0 - fim do programa*/

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS 
#endif
#include <stdio.h>
#include <locale.h>	 

#define PI 3.14f

void mostraMenu()
{
	printf("+-----------------------+\n");
	printf("|          M E N U      |\n");
	printf("+-----------------------+\n");
	printf("| 1 - quadrado          |\n");
	printf("| 2 - retangulo         |\n");
	printf("| 3 - triangulo         |\n");
	printf("| 4 - circulo           |\n");
	printf("| 5 - pentagono regular |\n");
	printf("| 6 - hexagono regular  |\n");
	printf("| 0 - fim do programa   |\n");
	printf("+-----------------------+\n");
	printf(" Escolha uma opção: ");
}

void main()
{
	setlocale(LC_ALL, "Portuguese");

	int opcao;
	float medida1, medida2, area;
	mostraMenu();
	scanf("%d", &opcao);

	// EM VEZ DE IF, VAMOS FAZER COM SWITCH CASE!
	/* swtich(variavel)
	* {
			case 0:
				bloco de instruçõs
				break;
			case 1:
				bloco de instruções
				break;
			etc
			default:
				bloco de instruções;
				break;
	   }*/

	switch (opcao)
	{
	case 1: //lado*lado
		printf("Introduza a medida do lado: ");
		scanf(" %f", &medida1);
		area = medida1 * medida1;
		printf("A area do quadrado é: %.1f", area);
		break;
	case 2: //lado*lado
		printf("Introduza a medida do primeiro lado: ");
		scanf(" %f", &medida1);
		printf("Introduza a medida do segundo lado: ");
		scanf(" %f", &medida2);
		area = medida1 * medida2;
		printf("A area do retangulo é: %.1f", area);
		break;
	case 3: //(base*altura) /2
		printf("Introduza a medida da base: ");
		scanf(" %f", &medida1);
		printf("Introduza a medida da altura: ");
		scanf(" %f", &medida2);
		area = (medida1 * medida2) / 2;
		printf("A area do triangulo é: %.1f", area);
		break;
	case 4: // PI * raio * raio 
		printf("Introduza a medida do raio: ");
		scanf(" %f", &medida1);
		area = PI * medida1 * medida1;
		printf("A area do circulo é: %.1f", area);
		break;
	case 5: // (perimetro * apotema) /2 
		printf("Introduza a medida do perimetro: ");
		scanf(" %f", &medida1);
		printf("Introduza a medida da apotema: ");
		scanf(" %f", &medida2);
		scanf(" %f", &medida2);
		area = (medida1 * medida2) / 2;
		printf("A area do pentagono regular é: %.1f", area);
		break;
	case 6: // (perimetro * apotema) /2 
		printf("Introduza a medida do perimetro: ");
		scanf(" %f", &medida1);
		printf("Introduza a medida da apotema: ");
		scanf(" %f", &medida2);
		area = (medida1 * medida2) / 2;
		printf("A area do hexagono regular é: %.1f", area);
		break;
	case 0:
		printf("Fim do programa. ");
		break;
	default:			//sifnifica: outros casos
		printf("Opção não prevista. ");
		break;
	}
	getch();			//significa que fica à espera de um enter do utilizador antes de encerrar a janela do programa

}

