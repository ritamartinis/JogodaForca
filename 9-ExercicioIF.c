#ifdef _MSC_VER 
#define _CRT_SECURE_NO_WARNINGS 
#endif
#include <stdio.h>
#include <locale.h>	 

// Elabore um programa que diga se um aluno est� aprovado ou reprovado.

void main()
{
	setlocale(LC_ALL, "Portuguese");

	float nota;
	printf("Qual a sua nota? ");
	scanf(" %f", &nota);
	if (nota >= 9.5)
		printf("O formando com %f est� APROVADO", nota);
	else
		printf("O formando com %f est� REPROVADO", nota);
}



/*
* %f Por default, ele coloca imensas casas decimais
* Se eu quiser controlar o nr de casas decimais, basta, DEPOIS do % e ANTES do f colocar o nr de casas que desejo
* ex: %.3f - vao aparecer 3 casas decimais
*/

/* IMPORTANTE!
*  O IF e o ELSE n�o levam ;
* 
* O que leva s�o as instru��es dentro deles (ie, printf e scanf)
* 
* IF - SE (n�o tem o ENTAO)
* ELSE - SENAO 
* (� um comando que corre no caso no if ser falso. Se a condicao n�o acontecer, else...).
* 
*  IF e ELSE c/ instru��o: n�o t�m {}
*  IF e ELSE c/ bloco de instru��es: t�m {}
*/