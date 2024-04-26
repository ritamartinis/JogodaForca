#ifdef _MSC_VER 
#define _CRT_SECURE_NO_WARNINGS 
#endif
#include <stdio.h>
#include <locale.h>
#include <string.h>

#define P 3					// 20 palavras no jogo   (p.ex. linhas do vetor)
#define L 15				// nr de letras por palavra (imaginando que este é as colunas do vetor)



int sorteio()
{
	return rand() % (P - 1);
}

void batota(char palavraSorteada[L], char palavraJogada[L], int idSorteado)
{
	printf("ID Sorteado      : %d \n", idSorteado);
	printf("Palavra sorteada : %s \n", palavraSorteada);
	printf("O meu jogo       : %s \n", palavraJogada);
}
void main()
{
	setlocale(LC_ALL, "Portuguese");
	
	// array para guardar as as palavras:
	char palavrasTodas[P][L] = { "PROGRAMAÇÃO", "MARAVILHA", "PRIMAVERA"};
	char palavraSorteada[L];			// palavra que foi sorteada
	char palavraJogada[L];
	int idSorteado;
	idSorteado = sorteio();
	strcpy(palavraSorteada, palavrasTodas[idSorteado]);
	batota(palavraSorteada, palavraJogada, idSorteado);




}

