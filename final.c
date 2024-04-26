#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <stdio.h>
#include <locale.h>

#define P 22 											// N� de palavras no jogo
#define C 23 											// N� de caracteres por palavra
#define T 20											// Comprimento do array que guarda as tentativas anteriores (n� de letras /palavras armazenados)

void beepVitoria()
{
	Beep(523, 200);
	Beep(523, 200);
	Beep(523, 200);
	Beep(523, 500);
	Beep(415, 500);
	Beep(466, 500);
	Beep(523, 300);
	Beep(466, 200);
	Beep(523, 950);
}

void beepDerrota()
{
	Beep(246, 250);
	Beep(233, 250);
	Beep(220, 250);
	Beep(207, 999);
}

void escreverDevagar(char text[])					// Fun��o para escrever devagar. Recebe uma frase que � o char text[] - � um array. Criado aqui.
{
	int i = 0;										// Inicia o �ndice para percorrer a string
	while (text[i] != '\0')					    	// Continua at� encontrar o caractere nulo
	{
		putchar(text[i]);                           // Imprime o caractere na posi��o atual. TEM QUE SER putchar e n�o printf! //� o putchar porque n�o tem vars, � s� texto
		Sleep(5);                                  // Atraso de 5 milissegundos
		text = text + 1;                                // Avan�a para o pr�ximo caractere na string
	}
}

void menuInicial()
{
	system("cls||clear");
																						// O caractere de escape \033 permite que os programas controlem a apar�ncia do texto exibido no terminal. 
	printf("\033[7m\t\t\t\t+=================================================+\n");		// [X;Ym: � a sequ�ncia de formata��o, onde X e Y s�o n�meros que representam os estilos de formata��o desejados.
	printf("\t\t\t\t|        \033[45m BEM VINDO AO JOGO DA FORCA EM C \033[40m        |\n");		// X=1 � para aplicar o estilo em negrito e o 0 serve para resetar todas as formata��es, como se verifica 2 linhas abaixo.
	printf("\t\t\t\t+=================================================+\n");
	printf("\t\t\t\t|                                                 |\n");			// Estilos: \033[0m:Reseta todas as formata��es(padr�o) \033[1m:Negrito \033[2m:Faint(baixa intensidade) \033[3m:It�lico(nem sempre suportado) \033[4m:Sublinhado	
	printf("\t\t\t\t|      Escolha uma op��o:       O=============    |\n");
	printf("\t\t\t\t|                               ||           |    |\n");			// FUNDO \033[30m: Preto \033[31m: Vermelho \033[32m: Verde \033[33m: Amarelo \033[34m: Azul \033[35m: Magenta (Roxo) \033[36m: Cyan (Azul claro) \033[37m: Branco
	printf("\t\t\t\t|                               ||           |    |\n");
	printf("\t\t\t\t|      1 - Jogar                ||          ( )   |\n");			// TEXTO: \033[40m:Preto \033[41m:Vermelho \033[42m:Verde \033[43m:Amarelo \033[44m:Azul \033[45m:Magenta(Roxo) \033[46m:Cyan(Azul claro) \033[47m:Branco	
	printf("\t\t\t\t|      2 - Instru��es           ||         \\/|\\   |\n");	
	printf("\t\t\t\t|      3 - Cr�ditos             ||           | \\  |\n");
	printf("\t\t\t\t|      0 - Sair                 ||          / \\   |\n");   
	printf("\t\t\t\t|                               ||         /   \\  |\n");
	printf("\t\t\t\t|                               ||_______________ |\n");
	printf("\t\t\t\t|                                                 |\n");
	printf("\t\t\t\t+=================================================+\n\033[0m");
	printf("\n\t\t\t\t");
}

void loading(char opt)										// Fun��o para mostrar o "LOADING......" no ecr�
{
	printf("\n\t\t\t\tA carregar\033[1;32m op��o %c \033[0m", opt);

	for (int i = 0; i < 16; i++)					    	// Continua at� 16
	{
		printf(".");										// Imprime o caractere na posi��o atual. 
		Sleep(100);											// Atraso de 100 milissegundos
	}
	Sleep(250);
}

void instrucoes()									// Fun��o para mostrar as instru��es, que vai ser chamada pelo main dentro do switch case 3
{
	escreverDevagar("\nINSTRU��ES :\n");
	escreverDevagar("\n\t\t\tBem-vindo ao jogo da forca\n");
	escreverDevagar("\nO objetivo do jogo � adivinhar a palavra oculta.\nPara tal, disp�e de 5 tentativas.\n");
	escreverDevagar("\nPode optar por tentar inserir uma letra ou, se preferir, tentar adivinhar a palavra na �ntegra.\nSe falhar, em ambos os casos, perde uma vida!\n");
	escreverDevagar("\nCada vez que errar, uma parte do boneco ser� desenhado na forca...\n");
	printf("\n\tO======  ");
	printf("\n\t||    |  ");
	printf("\n\t||    0 ");
	printf("\n\t||   /|\\ ");
	printf("\n\t||   / \\ ");
	printf("\n\t||_______ \n");
	escreverDevagar("\nSe acertar uma letra, esta aparecer� no ecr�.\n");
	escreverDevagar("Tamb�m as suas tentativas anteriores v�o aparecer no ecr� para poder consultar e n�o cometer erros :)\n");
	escreverDevagar("\n\nAl�m disso, as suas tentativas corretas s�o recompensadas.\n");
	escreverDevagar("\nComo funciona a pontua��o? \n");
	escreverDevagar("\n X Por cada letra certa, ganha 5 PONTOS!\n");
	escreverDevagar("\nSe, porventura, a palavra tiver mais do que uma letra igual, receber� 5 pontos por cada vez que esta se repetir. \n");
	escreverDevagar("\nPor outro lado:\n X Se tentar uma palavra e esta estiver certa, recebe 15 PONTOS por cada carater que ainda esteja em falta.\n");
	escreverDevagar("Por exemplo, sendo a palavra BANANA:\n");
	escreverDevagar("Se acertar � primeira tentativa, faltam-lhe 6 letras e recebe:\n 15 x 6 = 90 PONTOS.\n");
	escreverDevagar("Contudo, se tiver tentado anteriormente a letra 'b', recebe: \n 15 x 5 = 75 PONTOS pela palavra\n");
	escreverDevagar("+ 5 pontos pela letra 'b' acertada anteriormente.\n");
	escreverDevagar("\n\nSe acertar todas as letras ou a palavra, vence o jogo!\nSe errar 5 vezes, o boneco fica completo e perde o jogo!\n\n");
}

int sorteio()											// Fun��o para sortear o id da palavra
{
	return rand() % P; 									// Gera um n�mero aleat�rio entre 0 inclusive e P, exclusive, que � o n�mero de palavras. Neste caso entre 0 e 22.
}

void batota(char palavraSel[C], char palavraMostrada[C], int idPalavra)          // Fun��o batota para ajudar a ver os valores
{
	printf("Palavra Selecionada: %s\n", palavraSel);
	printf("Palavra Mostrada: %s\n", palavraMostrada);
	printf("Id Palavra: %i\n", idPalavra);
	printf("\nClique qualquer tecla para voltar ao menu.\n");
	getch();
	system("cls||clear");
}

void esconderPalavra(char palavraSel[C])					// Fun��o para ocultar a palavra selecionada							
{
	for (int i = 0; i < strlen(palavraSel); i++)			// O loop executa enquanto i for menor que o comprimento da palavra.
	{
		if (palavraSel[i] != '-')
			palavraSel[i] = '_';							// Substitui��o de cada caractere por um sublinhado (_). 	
	}														// a n�o ser que seja um hifen
}

int compararLetra(char entrada[C], char palavraSel[C], char palavraMostrada[C])  //Fun��o que compara e verifica se o vetor entrada[c] corresponde a alguma das letras presentes na palavraSel
{
	int errou = 1;																// var aux toma o valor de 1 por defeito e 	
	for (int i = 0; i < strlen(palavraSel); i++)
	{
		if (palavraSel[i] == entrada[0])					// Se um caractere em palavraSel corresponder ao entrada[0]
		{
			palavraMostrada[i] = palavraSel[i];				// Atualizamos a posi��o correspondente na palavra mostrada palavraMostrada com a letra correta.
			errou = 0;										// Damos o output de 0 para a fun��o game, o que indica que acertou a letra.
		}
	}
	return errou;		// Se n�o houver correspond�ncia entre a entrada e palavraSel, o output enviado � de 1, o que indica que errou a letra.
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
		printf("\t\t\t\t|    ||           |                               |\n");
		printf("\t\t\t\t|    ||           |                               |\n");
		printf("\t\t\t\t|    ||                                           |\n");
		printf("\t\t\t\t|    ||                                           |\n");
		printf("\t\t\t\t|    ||______________                             |\n");
		break;

	case 3:
		printf("\t\t\t\t|    O=============                               |\n");
		printf("\t\t\t\t|    ||           |                               |\n");
		printf("\t\t\t\t|    ||          ( )                              |\n");
		printf("\t\t\t\t|    ||          /|                               |\n");
		printf("\t\t\t\t|    ||           |                               |\n");
		printf("\t\t\t\t|    ||                                           |\n");
		printf("\t\t\t\t|    ||                                           |\n");
		printf("\t\t\t\t|    ||______________                             |\n");
		break;

	case 2:
		printf("\t\t\t\t|    O=============                               |\n");
		printf("\t\t\t\t|    ||           |                               |\n");
		printf("\t\t\t\t|    ||          ( )                              |\n");
		printf("\t\t\t\t|    ||          /|\\                              |\n");
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
		printf("\t\t\t\t|    ||            \\                              |\n");
		printf("\t\t\t\t|    ||             \\                             |\n");
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

int contaLetrasRepetidas(char entrada, char palavraSel[C])		//vai contar as letras que s�o repetidas
{
	int contador = 0;											// var interna
	for (int i = 0; i < strlen(palavraSel); i++)
	{
		if (palavraSel[i] == entrada)							// se a letra inserida for igual a uma letra j� existente no vetor, soma +1. vai ficar 5 * o contador				
			contador += 1;
	}
	return contador;
}

int converterMinusculaVerificador(char entrada[C], int tamanhoEntrada) //converte mai�sculas em min�sculas e retorna o valor 1 se algum carater for fora de a-z ou - (hifen)
{
	for (int i = 0; i < tamanhoEntrada; i++)							//� para verificar as letras nas posi��es da matriz de tamanho tamanhoEntrada
	{
		if (entrada[i] != '-')								// se for != de apenas um carater "hifen"
		{
			entrada[i] = tolower(entrada[i]);
			if (entrada[i] < 'a' || entrada[i] > 'z')
				return 1;
		}
		else if (tamanhoEntrada == 1)				// else, ou seja, se for apenas um h�fen:
			return 1;					// serve para impedir que a tentativa do utilizador seja apenas um h�fen. D� erro. Mostra linha 335
	}
	return 0;
}

int tentativasAnteriores(char entrada[C], int nTentativa, char tentativasInseridas[T][C])	//Armazena as palavras/letras inseridas anteriormente SE n�o forem repetidas
{
	int naoRepete = 1;					// var aux  
										// 1== NUNCA foi usada, 0== J� foi usado 
	for (int i = 0; i < T; i++)
		if (strcmp(tentativasInseridas[i], entrada) == 0)		// Se (tentativasInseridas, entrada) forem iguais
			naoRepete = 0;										// J� foi usado, n�o acrescenta no ecr� �s tentativas anteriores
	if (naoRepete == 1)											
		strcpy(tentativasInseridas[nTentativa], entrada);		// NUNCA foi usado, acrescenta no ecr� �s tentativas anteriores

	return naoRepete;
}

void ecraJogo(int tentativasR, char palavraMostrada[], int nTentativa, char tentativasInseridas[T][C], int pontos)
{
	system("cls||clear");
	printf("\033[7m\t\t\t\t+=================================================+\n");
	printf("\t\t\t\t|                \033[45m JOGO DA FORCA\033[40m                   |\n");
	printf("\t\t\t\t+=================================================+\n");
	printf("\t\t\t\t|                                                 |\n");
	printBoneco(tentativasR);
	printf("\t\t\t\t|                                                 |\n");
	printf("\t\t\t\t|      Vidas restantes: %i                         |\n", tentativasR);
	printf("\t\t\t\t|                                                 |\n");
	printf("\t\t\t\t+=================================================+\n\n\033[0m");
	printf("\033[1;33m\t\t\t\t       Palavra:\033[0m % s\n\n", palavraMostrada);
	printf("\033[1;35m\t\t\t\t       Tentativas anteriores:\033[0m");
	for (int i = 0; i < nTentativa; i++)
		printf("%s, ", tentativasInseridas[i]);
	printf("\033[1;32m\n\n\t\t\t\t       Pontua��o:\033[0m %i\n\n", pontos);
	printf("\t\t\t\t---------------------------------------------------\n");
}

void jogo(char palavrasTodas[P][C], char palavraSel[C], char palavraMostrada[C])
{
	char entrada[C];				// quando tenta uma palavra	 																																										
	int tentativasR;				// tentativas que o utilizador tem
	int idPalavra;					// indice aleat�rio das palavras, � o que vai sortear uma palavra
	int vitoria;					// var auxiliar de condi��o de paragem do ciclo
	int nTentativa = 0;			    // N�mero da tentativa de 0 a T-1
	char tentativasInseridas[T][C]; // array que guarda as tentativas de letras ou palavras j� inseridas
	int tamanhoEntrada;				// Tamanho da palavra/ letra inserida.
	int pontos = 0;					// pontos
	int letraJaUtilizada;			// n�o deixar acumular pontos por uma letra j� usada

	system("cls||clear");
	idPalavra = sorteio();			 // Obt�m um �ndice aleat�rio (retornado pela fun��o sorteio) para selecionar uma palavra do conjunto	
	strcpy(palavraSel, palavrasTodas[idPalavra]);	// Copia a palavra selecionada para palavraSel
	strcpy(palavraMostrada, palavrasTodas[idPalavra]);	// Copia a palavra selecionada para palavraMostrada
	esconderPalavra(palavraMostrada); // Esconde a palavra selecionada para que o jogador a descubra, usando a fun��o esconderPalavra  
	tentativasR = 5;				// Define o n�mero de tentativas dispon�veis para o jogador					
	vitoria = 0;					// Inicializa a vari�vel de vit�ria como falso (0) - 1 para vit�ria, 0 para derrota

	do                               // Ciclo principal do jogo 
	{
		ecraJogo(tentativasR, palavraMostrada, nTentativa, tentativasInseridas, pontos);	// Mostra o ecraJogo

		if (strcmp(palavraSel, palavraMostrada) == 0)	// Compara a palavraSel com a palavraMostrada, se for igual =0, � dada a VIT�RIA 
		{
			printf("\n\t\t\t\t+=================================================+\n");
			printf("\t\t\t\t|                    Parab�ns!                    |\n");
			printf("\t\t\t\t|                 ");
			printf("\033[1;32m   Ganhaste!\033[0m                    | \n\033[0m");
			printf("\t\t\t\t+=================================================+\n");
			vitoria = 1;						// Indica que o jogador venceu o jogo
			beepVitoria();
			Sleep(3000);
		}
		else
		{
			if (tentativasR > 0)				// Verifica se o jogador ainda tem tentativas restantes
			{
				printf("\n\t\t\t\tInsira um caractere de A a Z ou a palavra completa \n\n");	// Solicita uma entrada v�lida ao utilizador
				printf("\033[1;33m\t\t\t\t       Tentativa:\033[0m");
				scanf(" %22[^\n]s", entrada);		// L� a entrada do usu�rio, permitindo at� 22 caracteres +  \0 (colocado automaticamente pelo scanf)
				Beep(200, 200);
				fflush(stdin);						// Limpa o buffer do teclado

			}
			else								// Se o jogador ficou sem vidas
			{
				printf("\n\n\t\t\t\t+=================================================+\n");
				printf("\t\t\t\t|                Ficaste sem vidas...             |\n");
				printf("\t\t\t\t|                 ");
				printf("\033[1;31m   PERDESTE!\033[0m                    | \n\033[0m");
				printf("\t\t\t\t+=================================================+\n");
				beepDerrota();
				Sleep(3000);
				break;
			}

			tamanhoEntrada = strlen(entrada);					// A var�avel tamanhoEntrada toma o valor do n�mero de caracteres na string entrada at� encontrar o caractere nulo \0
			if (converterMinusculaVerificador(entrada, tamanhoEntrada) == 1)	// se o user introduzir um caractere menor que a e maior que z
			{
				printf("\033[1;31m\n\t\t\t\tOs carateres permitidos s�o exclusivamente de A a Z.\n");
				printf("\t\t\t\tN�o s�o permitidos espa�os.\n");
				printf("\t\t\t\tQuando aplic�vel, dever� colocar o h�fen.\033[0m");
				getch();
				Beep(200, 200);
			}
			else                                               // se o user introduzir um caractere/string CORRETO
			{
				letraJaUtilizada = tentativasAnteriores(entrada, nTentativa, tentativasInseridas);	//A LetraJaUtilizada toma o valor do tentativasAnteriores()
				nTentativa += letraJaUtilizada;						//armazena as tentativas anteriores, caso n�o tenham sido inseridas anteriormente

				if (tamanhoEntrada == 1)                    // se for um caractere, ou seja, uma LETRA
				{
					if (compararLetra(entrada, palavraSel, palavraMostrada) == 1)	// Se a letra for ERRADA
					{
						tentativasR = tentativasR - 1;                   //Decrementa o n�mero de tentativas restantes quando a letra inserida � errada
						printf("\033[1;31m\n\t\t\t\tLetra errada!\033[0m\n");
					}
					else                                //  Se for uma LETRA CERTA
					{
						if (letraJaUtilizada == 1)		// se a letra N�O foi usada, acontece isto:
						{
							printf("\033[1;32m\n\t\t\t\tLetra certa!\033[0m\n");
							printf("\t\t\t\tGanhou mais\033[1;32m %i\033[0m pontos\n", contaLetrasRepetidas(entrada[0], palavraSel) * 5);
							pontos += 5 * contaLetrasRepetidas(entrada[0], palavraSel);  // pontos: 5 por cada caractere certo!
						}
						else 							//se a letra J� foi usada, ent�o acontece isto:
							printf("\n\t\t\t\t\033[1;31m Letra certa mas j� utilizada! \033[0m\n");
					}
					Sleep(2000);
				}
				else                   // Se for uma PALAVRA
				{
					if (strcmp(entrada, palavraSel) == 0)  	// Se for palavra CERTA
					{
						strcpy(palavraMostrada, palavraSel);		// para atualizar os _ e mostrar a palavra completa, n�o censurada.

						if (pontos == 0)							// se o user n�o tiver pontos da ronda dos carateres, come�a as contas aqui.							
							pontos = strlen(palavraSel) * 15;		// pontos toma o valor de nr de _  * 15;
						else
							pontos += (strlen(palavraSel) - pontos / 5) * 15;		//pontos trazidos da ronda dos carateres, assim, nr de _ * 15, MENOS pontos da ronda dos carateres a dividir por 5 (que s�o pontos por cada letra)
					}					
					else									// Se for palavra ERRADA
					{
						printf("\033[1;31m\n\t\t\t\tPalavra errada!\033[0m\n");
						tentativasR = tentativasR - 1;
						Sleep(2000);
					}
				}
			}
		}
	} while (vitoria == 0);			// Condi��o de PARAGEM do Ciclo
}

void main()
{
	// =========== VARS:
	char palavrasTodas[P][C] = { {"guarda-chuva"},{"bem-vindo"},{"fim-de-semana"},{"arco-iris"},{"guarda-sol"},{"porta-moedas"},{"cor-de-rosa"},
		{"amarelo"}, {"azul"} ,	{"vermelho"}, {"computador"}, {"algoritmo"}, {"internet"}, {"protocolo"}, {"fado"}, {"bacalhau"}, {"saudade"},
		{"sardinha"}, {"vinho"}, {"guitarra"}, {"aurora"}, {"cereja"} };													// array das 22 palavras
	char palavraSel[C];																										// palavra selecionada
	char palavraMostrada[C];																								// Display da palavra, depois censurada com "_"
	char opt;																												// var do switch case
	int idPalavra;																											// indice aleat�rio das palavras, � o que vai sortear uma palavra


	// =========== Inicio do programa:
	setlocale(LC_ALL, "Portuguese");
	srand(time(NULL));							// Necess�rio para complementar a fun��o rand, contida no sorteio()


	do
	{
		menuInicial();
		opt = getch();							// Fica � espera de uma op��o do utilizador
		Beep(200, 200);

		if (opt == '0' || opt == '1' || opt == '2' || opt == '3' || opt == '$')		// S� aceita ESTAS
		{
			switch (opt)
			{
			case '$':					// Fun��o batota() escondida 
				system("cls||clear");
				idPalavra = sorteio();											// O valor de Id da palavra � dado pelo valor devolvido pela fun��o sorteio
				strcpy(palavraSel, palavrasTodas[idPalavra]);                   // Copiar o idPalavra para a vari�vel palavraSel                      
				strcpy(palavraMostrada, palavrasTodas[idPalavra]);              // Copiar o idPalavra para a vari�vel palavraMostrada   
				esconderPalavra(palavraMostrada);								// Esconde a palavraMostrada 
				batota(palavraSel, palavraMostrada, idPalavra);
				break;
			case '1':					// Op��o para jogar							
				loading(opt);
				jogo(palavrasTodas, palavraSel, palavraMostrada);
				break;
			case '2':					// Op��o para Instru��es
				loading(opt);
				system("cls||clear");
				instrucoes();
				getch();
				Beep(200, 200);
				break;
			case '3':					// Op��o para Cr�ditos	
				loading(opt);
				escreverDevagar("\n\n\t\t\t\tThis program was made by : \033[35m kithar, \033[32m ryuka, \033[31m ritans \033[0m \n");
				escreverDevagar("\n\t\t\t\tPressione qualquer tecla para continuar");
				getch();
				Beep(200, 200);
				break;
			}
		}
		else                        //Se o utilizador inserir algo != de 1, 2, 3, 0 ou $ 
		{
			printf("\n\t\t\t\tOp��o\033[1;31m inv�lida \n\033[0m");
			Sleep(1000);
		}
	} while (opt != '0');			// Sai do ciclo se o utilizador inserir 0
	escreverDevagar("\n\t\t\t\t   Obrigado por jogar! ");
	getch();
}
