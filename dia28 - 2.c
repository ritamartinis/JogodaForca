#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>


#define P 21 											// Nº de palavras no jogo
#define C 15 											// Nº de caracteres por palavra
#define T 20											// Comprimento do array que guarda as tentativas anteriores (nº de letras /palavras armazenados)

void escreverDevagar(char text[])					// Função para escrever devagar. Recebe uma matriz de caracteres de entrada de dados
{
	int i = 0;										// Inicia o índice para percorrer a string
	while (text[i] != '\0')					    	// Continua até encontrar o caractere nulo
	{
		putchar(text[i]);                           // Imprime o caractere na posição atual. TEM QUE SER putchar e não printf! 
		Sleep(5);                                  // Atraso de 30 milissegundos
		text = text + 1;                                // Avança para o próximo caractere na string
	}
}

void menuInicial()
{
	system("cls||clear");

	printf("\033[7m");														    // O caractere de escape \033 permite que os programas controlem a aparência do texto exibido no terminal. 
	printf("\t\t\t\t+=================================================+\n");		// [X;Ym: É a sequência de formatação, onde X e Y são números que representam os estilos de formatação desejados.
	printf("\t\t\t\t|         BEM VINDO AO JOGO DA FORCA EM C         |\n");		// X=1 é para aplicar o estilo em negrito e o 0 serve para resetar todas as formatações, como se verifica 2 linhas abaixo.
	printf("\t\t\t\t+=================================================+\n");
	printf("\t\t\t\t|                                                 |\n");		// Estilos: \033[0m:Reseta todas as formatações(padrão) \033[1m:Negrito \033[2m:Faint(baixa intensidade) \033[3m:Itálico(nem sempre suportado) \033[4m:Sublinhado	
	printf("\t\t\t\t|      Escolha uma opção:       O=============    |\n");
	printf("\t\t\t\t|                               ||           |    |\n");		// Texto \033[30m: Preto \033[31m: Vermelho \033[32m: Verde \033[33m: Amarelo \033[34m: Azul \033[35m: Magenta (Roxo) \033[36m: Cyan (Azul claro) \033[37m: Branco
	printf("\t\t\t\t|      1 - BatotaTeste          ||          ( )   |\n");	// Fundo: \033[40m:Preto \033[41m:Vermelho \033[42m:Verde \033[43m:Amarelo \033[44m:Azul \033[45m:Magenta(Roxo) \033[46m:Cyan(Azul claro) \033[47m:Branco	
	printf("\t\t\t\t|      2 - Jogar                ||          /|\\   |\n");	//
	printf("\t\t\t\t|      3 - Instruções           ||           |    |\n");
	printf("\t\t\t\t|      4 - Créditos             ||          / \\   |\n");   //
	printf("\t\t\t\t|      0 - Sair                 ||         /   \\  |\n");
	printf("\t\t\t\t|                               ||______________  |\n");
	printf("\t\t\t\t|                                                 |\n");
	printf("\t\t\t\t+=================================================+\n");
	printf("\033[0m");
	printf("\n\t\t\t\t");
}

void loading(char opt)										// Função para mostrar o "LOADING......" no ecrã
{
	printf("\n\t\t\t\tA carregar opção %c ", opt);
	for (int i = 0; i < 16; i++)					    	// Continua até encontrar o caractere nulo
	{
		printf(".");										// Imprime o caractere na posição atual. 
		Sleep(100);											// Atraso de 200 milissegundos
	}
	Sleep(250);
}

void instrucoes()									// Função para mostrar as instruções, que vai ser chamada pelo main dentro do switch case 3
{
	escreverDevagar("\nINSTRUÇÕES :\n");
	escreverDevagar("\n\t\t\tBem-vindo ao jogo da forca\n");
	escreverDevagar("\nO objetivo do jogo é adivinhar a palavra oculta.\nPara tal, dispõe de 5 tentativas.\n");
	escreverDevagar("\nPode optar por tentar inserir uma letra ou, se preferir, tentar adivinhar a palavra na íntegra.\nSe falhar, em ambos os casos, perde uma vida!\n");
	escreverDevagar("\nCada vez que errar, uma parte do boneco será desenhado na forca...\n");
	printf("\n\tO======  ");
	printf("\n\t||    |  ");
	printf("\n\t||    0 ");
	printf("\n\t||   /|\\ ");
	printf("\n\t||   / \\ ");
	printf("\n\t||_______ \n");
	escreverDevagar("\nSe acertar uma letra, esta aparecerá no ecrã.\n");
	escreverDevagar("Também as suas tentativas anteriores vão aparecer no ecrã para poder consultar e não cometer erros :)\n");
	escreverDevagar("\n\nAlém disso, as suas tentativas corretas são recompensadas.\n");
	escreverDevagar("\nComo funciona a pontuação? \n");
	escreverDevagar("\n X Por cada letra certa, ganha 5 PONTOS!\n");
	escreverDevagar("\nSe, porventura, a palavra tiver mais do que uma letra igual, receberá 5 pontos por cada vez que esta se repetir. \n");
	escreverDevagar("\nPor outro lado:\n X Se tentar uma palavra e esta estiver certa, recebe 15 PONTOS por cada carater que ainda esteja em falta.\n");
	escreverDevagar("Por exemplo, sendo a palavra BANANA:\n");
	escreverDevagar("Se acertar à primeira tentativa, faltam-lhe 6 letras e recebe:\n 15 x 6 = 90 PONTOS.\n");
	escreverDevagar("Contudo, se tiver tentado anteriormente a letra 'b', recebe: \n 15 x 5 = 75 PONTOS pela palavra\n");
	escreverDevagar("+ 5 pontos pela letra 'b' acertada anteriormente.\n");
	escreverDevagar("\n\nSe acertar todas as letras ou a palavra, vence o jogo!\nSe errar 5 vezes, o boneco fica completo e perde o jogo!\n\n");
}

int sorteio()											// Função para sortear o id da palavra
{
	return rand() % P; 								// Gera um número aleatório entre 0 inclusive e P, exclusive, que é o número de palavras. Neste caso entre 0 e 7.
}

void batota(char palavraSel[C], char palavraMostrada[C], int idPalavra)          // Função batota para ajudar a ver os valores
{
	printf("Palavra Selecionada: %s\n", palavraSel);
	printf("Palavra Mostrada: %s\n", palavraMostrada);
	printf("Id Palavra: %i\n", idPalavra);
}

void esconderPalavra(char palavraSel[C])					// Função para ocultar a palavra selecionada							
{
	for (int i = 0; i < strlen(palavraSel); i++)	// O loop executa enquanto i for menor que o comprimento da palavra.
	{
		if (palavraSel[i] != '-')
			palavraSel[i] = '_';								// Substituição de cada caractere por um sublinhado (_). 	
	}
}

int compararLetra(char entrada[C], char palavraSel[C], char palavraMostrada[C])
{
	int loss = 1;
	for (int i = 0; i < strlen(palavraSel); i++)
	{
		if (palavraSel[i] == entrada[0])					// Se um caractere em palavraSel for igual à letra inserida letraIns
		{
			palavraMostrada[i] = palavraSel[i];			// Atualizamos a posição correspondente na palavra mostrada palavraMostrada com a letra correta.
			loss = 0;									// Damos o output de 0 para a função game, o que indica que ganhaste o jogo
		}
	}
	return loss;										// Se não houver correspondência entre a letra inserida e a letra na palavra selecionada, o output enviado é de 1, o que indica que perdeste o jogo.
}

void printBoneco(int tentativasR) {
	switch (tentativasR) {
	case 5:
		printf("\t\t\t\t|    O=============                               |\n");
		printf("\t\t\t\t|    ||           |                               |\n");
		printf("\t\t\t\t|    ||                                           |\n");
		printf("\t\t\t\t|    ||                                           |\n");
		printf("\t\t\t\t|    ||                                           |\n");
		printf("\t\t\t\t|    ||                                           |\n");
		printf("\t\t\t\t|    ||                                           |\n");
		printf("\t\t\t\t|    ||______________                             |\n");
		break;

	case 4:
		printf("\t\t\t\t|    O=============                               |\n");
		printf("\t\t\t\t|    ||           |                               |\n");
		printf("\t\t\t\t|    ||          ( )                              |\n");
		printf("\t\t\t\t|    ||                                           |\n");
		printf("\t\t\t\t|    ||                                           |\n");
		printf("\t\t\t\t|    ||                                           |\n");
		printf("\t\t\t\t|    ||                                           |\n");
		printf("\t\t\t\t|    ||______________                             |\n");
		break;

	case 3:
		printf("\t\t\t\t|    O=============                               |\n");
		printf("\t\t\t\t|    ||           |                               |\n");
		printf("\t\t\t\t|    ||          ( )                              |\n");
		printf("\t\t\t\t|    ||           |                               |\n");
		printf("\t\t\t\t|    ||           |                               |\n");
		printf("\t\t\t\t|    ||                                           |\n");
		printf("\t\t\t\t|    ||                                           |\n");
		printf("\t\t\t\t|    ||______________                             |\n");
		break;

	case 2:
		printf("\t\t\t\t|    O=============                               |\n");
		printf("\t\t\t\t|    ||           |                               |\n");
		printf("\t\t\t\t|    ||          ( )                              |\n");
		printf("\t\t\t\t|    ||          /|                               |\n");
		printf("\t\t\t\t|    ||           |                               |\n");
		printf("\t\t\t\t|    ||                                           |\n");
		printf("\t\t\t\t|    ||                                           |\n");
		printf("\t\t\t\t|    ||______________                             |\n");
		break;

	case 1:
		printf("\t\t\t\t|    O=============                               |\n");
		printf("\t\t\t\t|    ||           |                               |\n");
		printf("\t\t\t\t|    ||          ( )                              |\n");
		printf("\t\t\t\t|    ||          /|\\                              |\n");
		printf("\t\t\t\t|    ||           |                               |\n");
		printf("\t\t\t\t|    ||                                           |\n");
		printf("\t\t\t\t|    ||                                           |\n");
		printf("\t\t\t\t|    ||______________                             |\n");
		break;

	case 0:
		printf("\t\t\t\t|    O=============                               |\n");
		printf("\t\t\t\t|    ||           |                               |\n");
		printf("\t\t\t\t|    ||          ( )                              |\n");
		printf("\t\t\t\t|    ||          /|\\                              |\n");
		printf("\t\t\t\t|    ||           |                               |\n");
		printf("\t\t\t\t|    ||          / \\                              |\n");
		printf("\t\t\t\t|    ||         /   \\                             |\n");
		printf("\t\t\t\t|    ||______________                             |\n");
		break;
	default:
		break;
	}
}

int contaLetrasRepetidas(char entrada, char palavraSel[C])		//vai contar as letras que são repetidas
{
	int contador = 0;											// var interna
	for (int i = 0; i < strlen(palavraSel); i++)
	{
		if (palavraSel[i] == entrada)							// se a letra inserida for igual a uma letra já existente no vetor, soma +1. vai ficar 5 * o contador				
			contador += 1;
	}
	return contador;
}

int converterMinusculaCorretor(char entrada[C], int tamanhoEntrada) //converte maiúsculas em minúsculas e retorna o valor 1 se algum carater fora fora de a-z E - (hifene)
{
	//if (tamanhoEntrada == 1)
	//{
	//	entrada[0] = tolower(entrada[0]);
	//	if (entrada[0] < 'a' || entrada[0] > 'z')
	//		return 1;
	//}
	//else
	for (int i = 0; i < tamanhoEntrada; i++)				//tamanhoEntrada-1 porque é para verificar as letras nas posições da matriz de tamanho tamanhoEntrada
	{
		if (entrada[i] != '-')
		{
			entrada[i] = tolower(entrada[i]);
			if (entrada[i] < 'a' || entrada[i] > 'z')
				return 1;
		}
		else if (tamanhoEntrada == 1)
			return 1;
	}
	return 0;
}

int tentativasAnteriores(char entrada[C], int nTentativa, char tentativasInseridas[T][C])
{
	int nRepete = 1;

	for (int i = 0; i < T; i++)
		if (strcmp(tentativasInseridas[i], entrada) == 0)
			nRepete = 0;
	if (nRepete == 1)
		strcpy(tentativasInseridas[nTentativa], entrada);

	return nRepete;
}

void game(char palavrasTodas[P][C], char palavraSel[C], char palavraMostrada[C])
{
	char entrada[C];		// quando tenta uma palavra	 																																										
	int tentativasR;	    // tentativas que o utilizador tem
	int idPalavra;		    // indice aleatório das palavras, é o que vai sortear uma palavra
	int vitoria;			// var auxiliar de condição de paragem do ciclo
	int nTentativa = 0;     // Número da tentativa de 0 a T-1
	char tentativasInseridas[T][C]; //array que guarda as tentativas de letras ou palavras já inseridas
	int tamanhoEntrada;     // Tamanho da palavra/ letra inserida.
	int pontos = 0;			// pontos
	int letraJaUtilizada;	//não deixar acumular pontos por uma letra já usada


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
		printf("\033[7m");
		printf("\t\t\t\t+=================================================+\n");
		printf("\t\t\t\t|                  Jogo da Forca                  |\n");
		printf("\t\t\t\t+=================================================+\n");
		printf("\t\t\t\t|                                                 |\n");
		printBoneco(tentativasR);
		printf("\t\t\t\t|                                                 |\n");
		printf("\t\t\t\t|      Vidas restantes: %i                        |\n", tentativasR);
		printf("\t\t\t\t|                                                 |\n");
		printf("\t\t\t\t+=================================================+\n");

		printf("\t\t\t\t|      Palavra:%s        Vidas restantes: %i  |\n", palavraMostrada, tentativasR);
		printf("\t\t\t\t|      Tentativas anteriores: ");
		for (int i = 0; i < nTentativa; i++)
			printf("%s, ", tentativasInseridas[i]);
		printf("   |\n");
		printf("\t\t\t\t|      Pontuação: %i                               |\n", pontos);
		printf("\t\t\t\t|                                                 |\n");
		printf("\t\t\t\t+=================================================+\n");
		printf("\033[0m");

		if (strcmp(palavraSel, palavraMostrada) == 0)
		{
			printf("\n\t\t\t\t+=================================================+\n");
			printf("\t\t\t\t|                    Parabéns!                    |\n");
			printf("\t\t\t\t|                 ");
			printf("\033[1;32m"); printf("   Ganhaste!"); printf("\033[0m"); printf("                    | \n");
			printf("\033[0m");
			printf("\t\t\t\t+=================================================+\n");
			vitoria = 1;
			getch();
		}
		else
		{
			if (tentativasR > 0)
			{
				printf("\n");
				printf("\t\t\t\tInsira um caractere de A a Z ou a palavra completa \n\n");
				printf("\033[1;32m");
				printf("\t\t\t\tTentativa:");
				printf("\033[0m");

				scanf(" %14[^\n]s", entrada);			//máximo de 14 caráteres + \0 (colocado automaticamente pelo scanf)
			}
			else									// se for zero, ficou sem vidas
			{
				printf("\n");
				printf("\n\t\t\t\t+=================================================+\n");
				printf("\t\t\t\t|                Ficaste sem vidas...             |\n");
				printf("\t\t\t\t|                 ");
				printf("\033[1;31m"); printf("   PERDESTE!"); printf("\033[0m"); printf("                    | \n");
				printf("\033[0m");
				printf("\t\t\t\t+=================================================+\n");
				Sleep(4000);
				break;
			}

			tamanhoEntrada = strlen(entrada);

			if (converterMinusculaCorretor(entrada, tamanhoEntrada) == 1)	// se o user introduzir um carater menor que a e maior que z
			{
				printf("\033[1;31m");
				printf("\n");
				printf("\t\t\t\tOs carateres permitidos são exclusivamente de A a Z.\n");
				printf("\t\t\t\tNão são permitidos espaços.\n");
				printf("\t\t\t\tQuando aplicável, deverá colocar o hífen.");
				printf("\033[0m");
				getch();
			}
			else
			{
				letraJaUtilizada = tentativasAnteriores(entrada, nTentativa, tentativasInseridas);
				nTentativa += letraJaUtilizada;						//armazena as tentativas anteriores, caso já não tenham sido inseridas

				if (tamanhoEntrada == 1)                    // se for um carater, ou seja, uma letra
				{
					if (compararLetra(entrada, palavraSel, palavraMostrada) == 1)
					{
						tentativasR = tentativasR - 1;
						printf("\033[1;31m");
						printf("\n");
						printf("\t\t\t\tLetra errada!\n");
						printf("\033[0m");
						/*if (pontos > 0)
						{
							pontos -= 1;
						}
						printf("\t\t\t\tPerdeu "); printf("\033[1;31m"); printf("1"); printf("\033[0m"); printf(" ponto\n");						// instruções para mostrar a vermelho*/
						Sleep(2000);
					}
					else
					{
						if (letraJaUtilizada == 1)		// se a letra não foi usada, acontece isto:
						{
							printf("\033[1;32m");
							printf("\n");
							printf("\t\t\t\tLetra certa!\n");
							printf("\t\t\t\tGanhou mais %i pontos\n", contaLetrasRepetidas(entrada[0], palavraSel) * 5);
							printf("\033[0m");
							pontos += 5 * contaLetrasRepetidas(entrada[0], palavraSel);  // pontos: 5 por cada carater certo!
						}
						else {																			//se a letra já foi usada, então acontece isto:
							printf("\033[1;31m");
							printf("\n");
							printf("\t\t\t\tLetra certa mas já utilizada!\n");
							printf("\033[0m");
						}
						Sleep(2000);

					}
				}
				else
				{
					if (strcmp(entrada, palavraSel) == 0)  // palavra		//o entrada vai ser comparado com o array palavraSel
					{
						strcpy(palavraMostrada, palavraSel);		// para atualizar os _ e mostrar a palavra completa

						if (pontos == 0)							// se o user não tiver pontos da ronda dos carateres, começa as contas aqui.							
							pontos = strlen(palavraSel) * 15;		// pontos toma o valor de nr de _  * 15;
						else
							pontos += (strlen(palavraSel) - pontos / 5) * 15;		//pontos trazidos da ronda dos carateres.
						// assim, nr de _ * 15, MENOS pontos da ronda dos carateres a dividir por 5 (que são pontos por cada letra)
					}												// nao podemos subtrair pontos porque, aqui, os pontos trazidos da ronda anterior são divididos por cada carater certo
					else
					{
						printf("\033[1;31m");
						printf("\n");
						printf("\t\t\t\tPalavra errada!\n");
						printf("\033[0m");
						/*printf("\t\t\t\tPerdeste "); printf("\033[1;31m"); printf("10"); printf("\033[0m"); printf(" pontos\n");
						if (pontos != 0)
							pontos -= 10;*/
						tentativasR = tentativasR - 1;
						Sleep(2000);
					}
				}
			}
		}
	} while (vitoria == 0);
}

void main()
{
	setlocale(LC_ALL, "Portuguese");

	//VARS:
	char palavrasTodas[P][C] = { {"guarda-chuva"},{"bem-vindo"},{"fim-de-semana"},{"arco-iris"},{"guarda-sol"},{"porta-moedas"},{"cor-de-rosa"},
		{"amarelo"}, {"azul"} ,	{"vermelho"}, {"computador"}, {"algoritmo"}, {"internet"}, {"protocolo"}, {"fado"}, {"bacalhau"}, {"saudade"},
		{"sardinha"}, {"vinho"}, {"guitarra"}, {"aurora"} };																// array das 20 palavras
	char palavraSel[C];																										// palavra selecionada
	char palavraMostrada[C];																								// Display da palavra, depois censurada com "_"
	char opt;																												// var do switch case
	int idPalavra;																											// indice aleatório das palavras, é o que vai sortear uma palavra

	// ===========Inicio do programa
	srand(time(NULL));
	do
	{
		//Beep(10000, 8000);
		menuInicial();


		opt = getche();
		setbuf(stdin, NULL);



		if (opt == '0' || opt == '1' || opt == '2' || opt == '3' || opt == '4')
		{
			switch (opt)
			{
			case '1':
				system("cls||clear");
				idPalavra = sorteio();
				strcpy(palavraSel, palavrasTodas[idPalavra]);                                       // Copiar o idPalavra para a variável palavraSel                      
				strcpy(palavraMostrada, palavrasTodas[idPalavra]);                                  // Copiar o idPalavra para a variável palavraMostrada   // O valor de Id da palavra é dado pelo resultado da função sorteio
				esconderPalavra(palavraMostrada);
				batota(palavraSel, palavraMostrada, idPalavra);
				printf("\nClique qualquer tecla para voltar ao menu.\n");
				getch();
				system("cls||clear");
				break;
			case '2':
				loading(opt);
				game(palavrasTodas, palavraSel, palavraMostrada);
				break;
			case '3':
				loading(opt);
				system("cls||clear");
				instrucoes();
				getch();
				break;
			case '4':
				loading(opt);
				escreverDevagar("\n\t\t\t\tThis program was made by : kithar, ryuka, ritans\n");
				escreverDevagar("\n\t\t\t\tPressione qualquer tecla para continuar");
				getch();
				break;
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
	} while (opt != '0');
	printf("\n");
	escreverDevagar("\t\t\t\t   Obrigado por jogar! ");
	getch();
}
