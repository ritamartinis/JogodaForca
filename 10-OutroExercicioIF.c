// Neste novo exercício, vamos repetir o anterior.
// Era o aluno com nota até 9.5 estava reprovado e mais de 9.5 aprovado.
// Contudo, temos uma diferença. No anterior só havia uma instrução no IF e uma instrução no ELSE.
// Agora vamos colocar dois printf em cada um (dois no if e dois no else) para ver a diferença.
// A diferença é que vamos precisar de chavetas.
// Também coloquei .2 no float para controlar as casas decimais para vão aparecer.
// Veremos.

#ifdef _MSC_VER 
#define _CRT_SECURE_NO_WARNINGS 
#endif
#include <stdio.h>
#include <locale.h>	 

// Elabore um programa que diga se um aluno está aprovado ou reprovado.

void main()
{
	setlocale(LC_ALL, "Portuguese");

	float nota;
	printf("Qual a sua nota? ");
	scanf(" %f", &nota);

	if (nota >= 9.5)
	{
		printf("O formando com %.2f ", nota);
		printf("está APROVADO");
	}
	else
	{
		printf("O formando com %.2f ", nota);
		printf("está REPROVADO");
	}
}

//Se o meu IF tem mais do que uma linha para ser executadas, tenho de colocar chavetas. No inicio do bloco e no fim do bloco.
//O mesmo vale para o ELSE.