#ifdef _MSC_VER 
#define _CRT_SECURE_NO_WARNINGS 
#endif
#include <stdio.h>
#include <locale.h>	 



//Prototipos das funções
int fatorialV1(int);

//Programa principal

void main()
{
	setlocale(LC_ALL, "Portuguese");
	int n;
	printf("Valor: ");
	scanf(" %d", &n);
	printf("Fatorial: %d", fatorialV1(n));
}

int fatorialV1(int n)
{
	int fact = 1;
	for (int i = 2; i <= n; i++)
		fact += i;
	return fact;
}

int fatorialV2(int n)
{
	int fact = 1;
	if 
	 (int n <= 0)
		
	return fact;
}

//terminar o exercício depois, ver a aula

//Não vai sair no teste nem recursividade nem operador trenário.


