/* O seu programa deve receber valores reais e guardá-los num vetor.
* Posteriormente, deve percorrer o vetor e calcular e mostrar a media dos valores introduzidos.
*/

#ifdef _MSC_VER 
#define _CRT_SECURE_NO_WARNINGS 
#endif
#include <stdio.h>
#include <locale.h>	 

void main()
{
	setlocale(LC_ALL, "Portuguese");
	float valReais[10];
	float media = 0;

	// Receber 10 valores para o vetor, num ciclo.
	// A cada passo, colocar o valor da media (que é zero) e somar com o valor recebido a cada iteração.

	for (int i = 0; i < 10; i++)
	{
		printf("Insira um valor: ");
		scanf(" %f", &valReais[i]);
		media = media + valReais[i];

	}

	// No fim, fazer o valor da media (que agora tem 10 valores) e dividir por 10

	printf("A média dos valores introduzidos é: %.2f", media / 10);
}
