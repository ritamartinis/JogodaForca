/* Fatorial de um n�mero n(n pertence a N), � representado por n!e dado por :
N! = n(n-1)(n-2)(n-3) ...3,2,1.
Exemplo:
	0! = 1
	3! = 3 x 2 x 1 = 6
Note que:
	4! = 4 x 3!
	7! = 7 x 6 x 5!
Fa�a um programa que calcule o fatorial de um n�mero previamente introduzido.
*/

//O fatorial de um n�mero � uma cadeia de multiplica��es dos valores menores desse n�mero.
//O fatorial � representado pelo !

#ifdef _MSC_VER 
#define _CRT_SECURE_NO_WARNINGS 
#endif
#include <stdio.h>
#include <locale.h>	 
void main()
{
	int num, i, fatorial=1;

	setlocale(LC_ALL, "Portuguese");
	
	printf("Introduza um n�mero: ");
	scanf(" %d", &num);
	if (num < 0)
		printf("N�mero inv�lido. ");
	else
		if (num == 0)
			printf("O fatorial de 0 � 1.");
		else
		{
			i = 1;
			while (i < num)
			{
				fatorial = fatorial * i;
				i = i + 1;
			}
			printf("O fatorial de %d �: %d", num, fatorial);
		}
}
