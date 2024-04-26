#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <windows.h>

#define P 6 											// Nº de palavras no jogo
#define C 15 											// Nº de caracteres por palavra

void menuInicial()
{
	system("cls||clear");

	printf("\033[7m");														    // O caractere de escape \033 permite que os programas controlem a aparência do texto exibido no terminal. 
	printf("\t\t\t\t+================================================+\n");		// [X;Ym: É a sequência de formatação, onde X e Y são números que representam os estilos de formatação desejados.
	printf("\t\t\t\t|         BEM VINDO AO JOGO DA FORCA EM C        |\n");		// X=1 é para aplicar o estilo em negrito e o 0 serve para resetar todas as formatações, como se verifica 2 linhas abaixo.
	printf("\t\t\t\t+================================================+\n");
	printf("\033[0m");															// Texto \033[30m: Preto \033[31m: Vermelho \033[32m: Verde \033[33m: Amarelo \033[34m: Azul \033[35m: Magenta (Roxo) \033[36m: Cyan (Azul claro) \033[37m: Branco
	printf("\033[7m");													        // Fundo: \033[40m:Preto \033[41m:Vermelho \033[42m:Verde \033[43m:Amarelo \033[44m:Azul \033[45m:Magenta(Roxo) \033[46m:Cyan(Azul claro) \033[47m:Branco
	printf("\t\t\t\t|                     Opções:                    |\n");		// Estilos: \033[0m:Reseta todas as formatações(padrão) \033[1m:Negrito \033[2m:Faint(baixa intensidade) \033[3m:Itálico(nem sempre suportado) \033[4m:Sublinhado														//           \033[5m:Piscante(nem sempre suportado) \033[7m:Inverso(texto e fundo trocados) \033[8m:Oculto(nem sempre suportado) 
	printf("\t\t\t\t|                                                |\n");		//
	printf("\t\t\t\t|          1 - BatotaTeste      ||=====          |\n");		//	
	printf("\t\t\t\t|          2 - Jogar            ||    |          |\n");		//
	printf("\t\t\t\t|          3 - Instruções       ||    0          |\n");		//
	printf("\t\t\t\t|          4 - Créditos         ||   /|\\         |\n");    //
	printf("\t\t\t\t|          0 - Sair             ||   / \\         |\n");    //
	printf("\t\t\t\t|                                                |\n");		//
	printf("\t\t\t\t+================================================+\n");
	printf("\033[0m");
	printf("\n");
	printf("\033[1;32m");
	printf("\t\t\t\tEscolha uma opção: ");
	printf("\033[0m");
}

void escreverDevagar(char text[])					// Função para escrever devagar. Recebe uma matriz de caracteres de entrada de dados
{
	int i = 0;										// Inicia o índice para percorrer a string
	while (text[i] != '\0')					    	// Continua até encontrar o caractere nulo
	{
		putchar(text[i]);                           // Imprime o caractere na posição atual. TEM QUE SER putchar e não printf! 
		Sleep(30);                                  // Atraso de 30 milissegundos
		text = text + 1;                                // Avança para o próximo caractere na string
	}
}

void escreverDevagar2(char text[])					// Função para escrever MUITO devagar.
{
	int i = 0;										// Inicia o índice para percorrer a string	
	while (text[i] != '\0')					    	// Continua até encontrar o caractere nulo
	{
		putchar(text[i]);                           // Imprime o caractere na posição atual. TEM QUE SER putchar e não printf!   
		Sleep(200);                                 // Atraso de 200 milissegundos
		text = text + 1;                            // Avança para o próximo caractere na string 
	}
}

void loading()										// Função para mostrar o "LOADING......" no ecrã
{
	printf("\n\t\t\t        LOADING ");
	escreverDevagar2(".............");
	Sleep(2000);
}

void instrucoes()									// Função para mostrar as instruções, que vai ser chamada pelo main dentro do switch case 3
{
	escreverDevagar("\nInstruções :\n");
	escreverDevagar("\nO jogo da forca é um jogo em que o jogador tem que acertar qual é a palavra proposta, tendo como dica o número de letras e o tema ligado à palavra.\n");
	escreverDevagar("\nA cada letra errada, é desenhado uma parte do corpo do enforcado.\n O jogo termina ou com o acerto da palavra ou com o término do preenchimento das partes corpóreas do enforcado.\n");
	escreverDevagar("\nPor exemplo, para a palavra MERCADO, se escreve:\n");
	escreverDevagar("\nM E R C A D O ------ > _ _ _ _ _ _ \n");
	escreverDevagar("\nTentas adivinhar a palavra, dizendo as letras que podem existir nela. Cada letra que ele acerta é escrita no espaço correspondente.\n");
	escreverDevagar("\nM E R C A D O ------ > M _ _ C A _ _\n");
	escreverDevagar("\nCaso a letra não exista nessa palavra, desenha - se uma parte do corpo (iniciando pela cabeça, tronco, braços…)\n");
	printf("\n\t||=====  ");
	printf("\n\t||    |  ");
	printf("\n\t||    0 ");
	printf("\n\t||   /|\\ ");
	printf("\n\t||   / \\ ");
	printf("\n\t||       ");
	escreverDevagar("\nGanhas o jogo se conseguires adivinhar a palavra sem ter o boneco completo.\n Caso o jogador não descubra qual palavra é ele que perdes o jogo...\n");
}

int sorteio()											// Função para sortear o id da palavra
{
	return rand() % P;							        // Gera um número aleatório entre 0 e P, que é o número de palavras. Neste caso entre 0 e 6.
}

void batota(char palavraSel[C], char palavraMostrada[C], int idPalavra)          // Função batota para ajudar a ver os valores
{
	printf("Palavra Selecionada: %s\n", palavraSel);
	printf("Palavra Mostrada: %s\n", palavraMostrada);
	printf("Id Palavra: %i\n", idPalavra);
}

void esconderPalavra(char palavraSel[C])					// Função para ocultar a palavra selecionada							
{
	for (int i = 0; i < strlen(palavraSel); i++)			// O loop executa enquanto i for menor que o comprimento da palavra.
		palavraSel[i] = '_';								// Substituição de cada caractere por um sublinhado (_). 	
}

int compararLetra(char letraIns, char palavraSel[C], char palavraMostrada[C])
{
	int loss = 1;
	for (int i = 0; i < strlen(palavraSel); i++)
	{
		if (palavraSel[i] == letraIns)					// Se um caractere em palavraSel for igual à letra inserida letraIns
		{
			palavraMostrada[i] = palavraSel[i];			// Atualizamos a posição correspondente na palavra mostrada palavraMostrada com a letra correta.
			loss = 0;									// Damos o output de 0 para a função game, o que indica que ganhaste o jogo
		}

	}
	return loss;										// Se não houver correspondência entre a letra inserida e a letra na palavra selecionada, o output enviado é de 1, o que indica que perdeste o jogo.
}
void game(char palavrasTodas[P][C], char palavraSel[C], char palavraMostrada[C])
{
	char entrada[C];
	char letraIns;			// letra inserida pelo utilizador 																																										
	char palavraIns;		// palavra inserida pelo utilizador
	int tentativasR;	    // tentativas que o utilizador tem
	int idPalavra;		    // 
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
		printf("\033[1;32m");
		printf("\t\t\t\t+======================================+\n");
		printf("\t\t\t\t|            Jogo da Forca             |\n");
		printf("\t\t\t\t+======================================+\n");
		printf("\033[0m");
		printf("\t\t\t\t|                                      |\n");
		printf("\t\t\t\t|     %s                           |\n", palavraMostrada);
		printf("\t\t\t\t|                                      |\n");
		printf("\t\t\t\t|     Vidas restantes: %i               |\n", tentativasR);
		printf("\t\t\t\t|                                      |\n");
		printf("\t\t\t\t+======================================+\n");

		if (strcmp(palavraSel, palavraMostrada) == 0)
		{
			printf("\nGANHOU!!!!\n");
			vitoria = 1;
			getch();
		}
		else
		{
			printf("\n");
			printf("\t\t\t\tInsira um caractere de A a Z ou a palavra completa \n\n");
			printf("\t\t\t\tTentativa:");


			scanf(" %s", &entrada);

			entrada[0] = tolower(entrada[0]);

			if (entrada[0] < 'a' || entrada[0] > 'z')
			{
				printf("\033[1;31m");
				printf("\n");
				printf("\t\t\t\t           Essa letra não é aceite");
				printf("\033[0m");
				Sleep(2000);
			}
			else
			{
				if (strlen(entrada) == 1)                   // letra
				{
					letraIns = entrada[0];
					if (compararLetra(letraIns, palavraSel, palavraMostrada) == 1)
					{
						tentativasR = tentativasR - 1;
						printf("\033[1;31m");
						printf("\t\t\t\t          Letra errada!\n");
						printf("\033[0m");

						Sleep(2000);
					}
					else
					{
						printf("\033[1;32m");
						printf("\t\t\t\t          Letra certa!\n");
						printf("\033[0m");
						Sleep(2000);
					}
				}
				else {
					letraIns = entrada[0];
					if (compararLetra(letraIns, palavraSel, palavraMostrada) == 0)  // palavra
					{
						printf("\n");
						printf("\033[1;32m");
						printf("\t\t\t\t+=================================+\n");
						printf("\t\t\t\t|           GANHOU!!!!            |\n");
						printf("\t\t\t\t+=================================+\n");
						printf("\033[0m");
						vitoria = 1;
						Sleep(4000);
					}
					else
					{
						printf("\033[1;31m");
						printf("\n");
						printf("\t\t\t\t           Palavra errada!\n");
						printf("\033[0m");
						tentativasR = tentativasR - 1;
						Sleep(2000);
					}
				}


				if (tentativasR == 0)
				{
					printf("\033[1;31m");
					printf("\t\t\t\t          Ficaste sem vidas e PERDESTE!\n");
					printf("\033[0m");
					Sleep(4000);
				}
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
	char letraIns;																																										// letra inserida pelo utilizador 																																										
	char palavraIns;																																									// 
	int tentativasR;																																									// tentativas que o utilizador tem
	int idPalavra;																																										// 
	int vitoria;
	// var auxiliar para terminar o ciclo

// ===========Inicio do programa
	setlocale(LC_ALL, "Portuguese");

	do
	{
		menuInicial();
		//fflush(stdin);
		scanf(" %i", &opt);

		while (getchar() != '\n'); // SEM ISTO NAO FUNCIONA, A PERCERBER PORQUE, PROBLEMA DE BUFFER , FLUSH FUNCIONA MAL

		if (opt >= 0 && opt <= 4)
		{
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
				//system("cls||clear");
				loading();
				game(palavrasTodas, palavraSel, palavraMostrada);
				break;
			case 3:
				system("cls||clear");
				loading();
				system("cls||clear");
				instrucoes();
				getch();
			case 4:
				escreverDevagar("\t\t\t\tThis program was made by : kithar, ryuka, ritam\n");
				escreverDevagar("\t\t\t\tPressione qualquer tecla para continuar");
				getch();
			}

		}
		else
		{
			printf("\n");
			printf("\033[1;31m");
			printf("\t\t\t\t           Opção inválida\n");
			printf("\033[0m");
			printf("\n");
			//	printf("Clique qualquer tecla para voltar ao menu.\n");
			Sleep(1000);
		}
	} while (opt != 0);


	system("cls||clear");
	printf("Goodbye!");
	getch();
}
