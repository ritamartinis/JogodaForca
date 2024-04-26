#ifdef _MSC_VER 
#define _CRT_SECURE_NO_WARNINGS 
#endif
#include <stdio.h>
void main()
{
	int vet[5];

	// =============================== Receber valores
	for (int i = 0; i < 5; i++)
	{
		printf("insere valor : ");
		// 		scanf("%d", &x);
		// 		vet[i] = x;
		scanf("%d", &vet[i]);
	}

	// =============================== Mostra valores
	for (int i = 0; i < 5; i++)
		printf("Valor no indice %d = %d\n", i, vet[i]);
}
