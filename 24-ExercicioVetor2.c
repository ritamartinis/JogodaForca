#ifdef _MSC_VER 
#define _CRT_SECURE_NO_WARNINGS 
#endif
#include <stdio.h>
void main()
{
	char texto[25];
	// =============================== Receber valores
	printf("Insira uma palavra : ");
	scanf(" %24s", texto);  // N�o colocar & � um array funciona sempre por endere�o
	// =============================== Mostra valores
	printf("O texto recebido : %s\n", texto);
	puts(texto);

	printf("Insira duas palavras texto : ");
	scanf(" %24[^\n]s", texto);				// Ele vai ler at� encontrar um enter. D� para colocar mais que uma palavra.
	puts(texto);

	scanf(" ");
	printf("Insira  texto : ");
	gets(texto);
	puts(texto);
}

// relembrando, o puts s� serve para strings. E � o equivalente do printf.
//o gets tb s� serve para strings e � o equivalente do SCANF.

