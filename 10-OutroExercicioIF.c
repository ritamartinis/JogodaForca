// Neste novo exerc�cio, vamos repetir o anterior.
// Era o aluno com nota at� 9.5 estava reprovado e mais de 9.5 aprovado.
// Contudo, temos uma diferen�a. No anterior s� havia uma instru��o no IF e uma instru��o no ELSE.
// Agora vamos colocar dois printf em cada um (dois no if e dois no else) para ver a diferen�a.
// A diferen�a � que vamos precisar de chavetas.
// Tamb�m coloquei .2 no float para controlar as casas decimais para v�o aparecer.
// Veremos.

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
	{
		printf("O formando com %.2f ", nota);
		printf("est� APROVADO");
	}
	else
	{
		printf("O formando com %.2f ", nota);
		printf("est� REPROVADO");
	}
}

//Se o meu IF tem mais do que uma linha para ser executadas, tenho de colocar chavetas. No inicio do bloco e no fim do bloco.
//O mesmo vale para o ELSE.