#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <stdio.h>
#include <locale.h>
void main()
{
	//Elabore um programa que receba um valor e mostre o dobro desse valor

	setlocale(LC_ALL, "Portuguese");
	int x;
	printf("Insira um valor:");
	scanf(" %i", &x);
	printf("O dobro de X é %i", x * 2);
}

//Sempre que temos um SCANF temos de colocar um &! SEMPRE
// é a variavel e depois o & e o nome que demos à var

//IMPORTANTE: o espaço antes da variavel (%i) é para fazer o enter
//IMPORTANTE: o scanf vai fazer um enter, automaticamente. Então, no próximo printf não preciso de colocar o \n
