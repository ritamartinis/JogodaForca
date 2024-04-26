#ifdef _MSC_VER 
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <stdio.h>
#include <locale.h>
#include <math.h>


#define P 6 											// Nº de palavras no jogo
#define C 15 											// Nº de caracteres por palavra


void menuInicial()
{
	system("cls||clear");
	printf("+====================================================+\n");
	printf("|                                                    |\n");
	printf("|            BEM VINDO AO JOGO DA FORCA EM C         |\n");
	printf("|                                                    |\n");
	printf("|    Opções:                                         |\n");
	printf("|    1 - BatotaTeste                                 |\n");
	printf("|    2 - Jogar                                       |\n");
	printf("|    0 - Sair                                        |\n");
	printf("+====================================================+\n");
}


int sorteio()											//sortear o id da palavra
{
	return rand() % (P - 1);
}

void batota(char palavraSel[C], char palavraMostrada[C], int idPalavra)
{
	printf("Palavra Selecionada: %s\n", palavraSel);
	printf("Palavra Mostrada: %s\n", palavraMostrada);
	printf("Id Palavra: %i\n", idPalavra);
}
void esconderPalavra(char palavraSel[C])
{
	for (int i = 0; i < strlen(palavraSel); i++)
		palavraSel[i] = '_';
}
int compararLetra(char letraIns, char palavraSel[C], char palavraMostrada[C])
{
	int loss = 1;
	for (int i = 0; i < strlen(palavraSel); i++)
	{
		if (palavraSel[i] == letraIns)
		{
			palavraMostrada[i] = palavraSel[i];
			loss = 0;
		}

	}
	return loss;
}
void game(char palavrasTodas[P][C], char palavraSel[C], char palavraMostrada[C])
{
	char letraIns;																																											// letra inserida pelo utilizador 																																										
	char palavraIns;																																											// 
	int tentativasR;																																									// tentativas que o utilizador tem
	int idPalavra;																																												// 
	int vitoria;

	system("cls||clear");
	idPalavra = sorteio();
	strcpy(palavraSel, palavrasTodas[idPalavra]);
	strcpy(palavraMostrada, palavrasTodas[idPalavra]);
	esconderPalavra(palavraMostrada);
	tentativasR = 5;
	vitoria = 0;
	do
	{
		system("cls||clear");
		printf("%s\n", palavraMostrada);
		printf("Vidas: %i\n", tentativasR);
		if (strcmp(palavraSel, palavraMostrada) == 0)
		{
			printf("\nGANHOU!!!!\n");
			vitoria = 1;
			getch();
		}
		else {
			printf("Adivinhe:(letra)");
			scanf(" %c", &letraIns);
			if (compararLetra(letraIns, palavraSel, palavraMostrada) == 1)
			{
				tentativasR = tentativasR - 1;
				printf("\nERRADO!\n");
				getch();
			}
			else
			{
				printf("\nCERTO!\n");
				getch();
			}
			if (tentativasR == 0)
			{
				printf("\nPERDEU!\n");
				getch();
			}
		}
	} while (tentativasR > 0 && vitoria == 0);
}

void main()
{
	char palavrasTodas[P][C] = { {"potato"},{"banana"},{"ghost"},{"sadness"},{"haunted"},{"cursed"} };		// array das 20 palavras
	char palavraSel[C];																																										// palavra selecionada
	char palavraMostrada[C];																																							// Display da palavra, depois censurada com "_"
	int opt;

	char letraIns;																																												// letra inserida pelo utilizador 																																										
	char palavraIns;																																											// 
	int tentativasR;																																									// tentativas que o utilizador tem
	int idPalavra;																																												// 
	int vitoria;
	// var auxiliar para terminar o ciclo

// ===========Inicio do programa
	setlocale(LC_ALL, "Portuguese");

	do
	{
		menuInicial();
		//fflush(stdin);
		//opt = getch();
		scanf(" %i", &opt);
		switch (opt)
		{
		case 1:
			system("cls||clear");
			idPalavra = sorteio();
			strcpy(palavraSel, palavrasTodas[idPalavra]);                                          // Copiar o idPalavra para a variável palavraSel                      
			strcpy(palavraMostrada, palavrasTodas[idPalavra]);                                     // Copiar o idPalavra para a variável palavraMostrada   // O valor de Id da palavra é dado pelo resultado da função sorteio
			esconderPalavra(palavraMostrada);
			batota(palavraSel, palavraMostrada, idPalavra);
			printf("\nClique qualquer tecla para voltar ao menu.\n");
			getch();
			system("cls||clear");
			break;
		case 2:
			game(palavrasTodas, palavraSel, palavraMostrada);
		}
	} while (opt != 0);

	printf("\nLista de palavras: %s\nPalavra Selecionada: %s\n Palavra Mostrada: %s\nLetra inserida: %c\n", palavrasTodas[0], palavraSel, palavraMostrada);


	printf("Goodbye!");
	getch();
}


