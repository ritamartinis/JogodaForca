#ifdef _MSC_VER 
#define _CRT_SECURE_NO_WARNINGS 
#endif
#include <stdio.h>
#include <locale.h>	 
#include <Windows.h>

void escreverDevagar(char text[])					// Fun��o para escrever devagar. Recebe uma matriz de caracteres de entrada de dados
{
	int i = 0;										// Inicia o �ndice para percorrer a string
	while (text[i] != '\0')					    	// Continua at� encontrar o caractere nulo
	{
		putchar(text[i]);                           // Imprime o caractere na posi��o atual. TEM QUE SER putchar e n�o printf! 
		Sleep(5);                                  // Atraso de 30 milissegundos
		text = text + 1;                                // Avan�a para o pr�ximo caractere na string
	}
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
	escreverDevagar("\n\nAl�m disso, as suas tentativas corretas s�o recompensadas mas as erradas custam-lhe pontos.\n");
	escreverDevagar("\nComo funciona a pontua��o? \n");
	escreverDevagar("\n X Por cada letra certa, ganha 5 PONTOS!\n");
	escreverDevagar("\nSe, porventura, a palavra tiver mais do que uma letra igual, receber� 5 pontos por cada vez que esta se repetir. \n");
	escreverDevagar("\n X Se tentar uma letra e esta n�o estiver na palavra, perde 1 PONTO.\n");
	escreverDevagar("\nPor outro lado:\n X Se tentar uma palavra e esta estiver certa, recebe 15 PONTOS por cada carater que ainda esteja em falta.\n");
	escreverDevagar("Por exemplo, sendo a palavra BANANA:\n");
	escreverDevagar("Se acertar � primeira tentativa, faltam-lhe 6 letras e recebe:\n 15 x 6 = 90 PONTOS.\n");
	escreverDevagar("Contudo, se tiver tentado anteriormente a letra 'b', recebe: \n 15 x 5 = 75 PONTOS pela palavra\n");
	escreverDevagar("+ 5 pontos pela letra 'b' acertada anteriormente.\n");
	escreverDevagar("\n X Por �ltimo, se tentar a palavra e esta estiver errada, perde 10 PONTOS!\n");
	escreverDevagar("\n\nSe acertar todas as letras ou a palavra, vence o jogo!\nSe errar 5 vezes, o boneco fica completo e perde o jogo!\n\n");
}


void main()
{
	setlocale(LC_ALL, "Portuguese");
	instrucoes();
}