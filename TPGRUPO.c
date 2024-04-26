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
	printf("+====================================================+\n");
	printf("|                                                    |\n");
	printf("|            BEM VINDO AO JOGO DA FORCA EM C         |\n");
	printf("|                                                    |\n");
	printf("|    Opções:                                         |\n");
	printf("|    1 - BatotaTeste                                 |\n");
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

void main()
{
	char palavrasTodas[P][C] = { {"potato"},{"banana"},{"ghost"},{"sadness"},{"haunted"},{"cursed"} };		// array das 20 palavras
	char palavraSel[C];																																										// palavra selecionada
	char palavraMostrada[C];																																							// Display da palavra, depois censurada com "_"
	char letraIns;																																												// letra inserida pelo utilizador 																																										
	char palavraIns;																																											// 
	int tentativasR = 5;																																									// tentativas que o utilizador tem
	int idPalavra;																																												// 
	int opt;																																															// var auxiliar para terminar o ciclo

	// ===========Inicio do programa
	setlocale(LC_ALL, "Portuguese");

	do
	{
		menuInicial();
		//fflush(stdin);
		//opt = _getch();
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
		}
	} while (opt != 0);
	// [ Mostra o Menu Inicial ] 


	printf("Goodbye!");
	getch();
}


