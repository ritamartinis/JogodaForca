#ifdef _MSC_VER 
#define _CRT_SECURE_NO_WARNINGS 
#endif
#include <stdio.h>
#include <locale.h>	
void main()
{
	int x;
	setlocale(LC_ALL, "Portuguese");
	/* Operadores Combinados
		+=		Exemplo: x += 2;    equivalente a	x = x + 2;
		-=		Exemplo: x -= 5;    equivalente a	x = x - 5;
		*=		Exemplo: x *= 3;    equivalente a	x = x * 3;
		/=		Exemplo: x /= 2;    equivalente a	x = x / 2;
		%=		Exemplo: x %= 2;	equivalente a	x = x % 2;
	*/
	x = 50;
	x += 2;
	printf("X = %d\n", x);		// 52

	x = 50;
	x -= 5;
	printf("X = %d\n", x);		// 45

	x = 50;
	x *= 3;
	printf("X = %d\n", x);		// 150

	x = 50;
	x /= 2;
	printf("X = %d\n", x);		// 25

	x = 50;
	x %= 2;
	printf("X = %d\n", x);		// 0

/* Fazer potenciação em C, que antes era** em pseudocódigo, agora é pow.
*  Não é um operador. É UMA FUNÇÃO!. pow(base,expoente).
*/

}
