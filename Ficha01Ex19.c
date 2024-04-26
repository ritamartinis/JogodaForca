//Série Fibonacci

#ifdef _MSC_VER 
#define _CRT_SECURE_NO_WARNINGS 
#endif
#include <stdio.h>
#include <locale.h>	

void serieFibonacci(int n)
{
	int a, b, soma, i;
	a = 0;
	b = 1;
	soma = 0;
	printf(" %d", b);
	for (i = 0; i < n && soma <= n; i = i + 1)
	{
		soma = a + b;
		a = b;
		b = soma;
		printf(" %d ", soma);
	}
}

int valorPosicaoFinobacci(int n)
{
	if (n == 0 || n == 1)

}
void main()
{
	setlocale(LC_ALL, "Portuguese");

}