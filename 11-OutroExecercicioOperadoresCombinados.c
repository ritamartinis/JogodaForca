#ifdef _MSC_VER 
#define _CRT_SECURE_NO_WARNINGS 
#endif
#include <stdio.h>
#include <locale.h>	 
void main()
{
	float a1, a2, b1, b2, c1, c2, d1, d2;
	int e1, e2;
	setlocale(LC_ALL, "Portuguese");

	a1 = a2 = b1 = b2 = c1 = c2 = d1 = d2 = 10;
	e1 = e2 = 10;

	a1 = a1 + 2;
	a2 += 2;
	printf("Resultado 1 : %.2f Resultado 2: %.2f\n", a1, a2);

	b1 = b1 - 2;
	b2 -= 2;
	printf("Resultado 1 : %2.2f Resultado 2: %.2f\n", b1, b2);

	c1 = c1 * 2;
	c2 *= 2;
	printf("Resultado 1 : %.2f Resultado 2: %.2f\n", c1, c2);

	d1 = d1 / 2;
	d2 /= 2;
	printf("Resultado 1 : %.2f Resultado 2: %.2f\n", d1, d2);

	e1 = e1 % 2;
	e2 %= 2;
	printf("Resultado 1 : %d resultado 2: %d\n", e1, e2);

}
