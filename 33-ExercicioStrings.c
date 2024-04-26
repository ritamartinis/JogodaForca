#ifdef _MSC_VER 
#define _CRT_SECURE_NO_WARNINGS 
#endif
#include <stdio.h>
#include <locale.h>	 

#define N 55				//constante

void mostraVetor(char texto[N])
{
	for (int i = 0; i < N; i++)
		printf("%c", texto[i]);
	puts("");
}

void altera01(char texto[N])
{
	for (int i = 0; i < N; i++)
		if (texto[i] == ' ')
			texto[i] = '_';
}

void altera02(char texto[N])
{

	for (int i = 0; i < N; i++)
		if (texto[i] == '_')
			texto[i] = ' ';
}

void altera03(char texto[N])
{
	for (int i = 0; i < N; i++)
		if (texto[i] >= 'a' && texto[i] <= 'z')
			texto[i] = texto[i] - 32; //vai colocar todas as letras maisculas! É o codigo para a capitalizado

}


void main()
{
	setlocale(LC_ALL, "Portuguese");
	char texto[N] = {"É dia de programar em C.Podia ser bem pior...\0"};		//string/cadeia de carateres. É um vetor do tipo string

	puts("----------Exemplo 1");
	mostraVetor(texto);
	scanf(" %54[^\n]s", texto);
	printf(" %s\n", texto);
	mostraVetor();
	mostraVetor("Este texto... E este texto...");		
	printf("Este texto...\0 E este texto...");			
	altera01(texto);
	mostraVetor(texto);
	printf("\nTexto: %s\n", texto);
	altera02(texto);
	altera03(texto);
	printf("\nTexto: %s\n", texto);
}