#ifdef _MSC_VER 
#define _CRT_SECURE_NO_WARNINGS 
#endif
#include <stdio.h>
void main()
{
	char texto[25];
	// =============================== Receber valores
	printf("Insira uma palavra : ");
	scanf(" %24s", texto);  // Não colocar & é um array funciona sempre por endereço
	// =============================== Mostra valores
	printf("O texto recebido : %s\n", texto);
	puts(texto);

	printf("Insira duas palavras texto : ");
	scanf(" %24[^\n]s", texto);				// Ele vai ler até encontrar um enter. Dá para colocar mais que uma palavra.
	puts(texto);

	scanf(" ");
	printf("Insira  texto : ");
	gets(texto);
	puts(texto);
}

// relembrando, o puts só serve para strings. E é o equivalente do printf.
//o gets tb só serve para strings e é o equivalente do SCANF.

