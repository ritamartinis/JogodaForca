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
	printf("O dobro de X � %i", x * 2);
}

//Sempre que temos um SCANF temos de colocar um &! SEMPRE
// � a variavel e depois o & e o nome que demos � var

//IMPORTANTE: o espa�o antes da variavel (%i) � para fazer o enter
//IMPORTANTE: o scanf vai fazer um enter, automaticamente. Ent�o, no pr�ximo printf n�o preciso de colocar o \n
