#ifdef _MSC_VER 
#define _CRT_SECURE_NO_WARNINGS 
#endif
#include <stdio.h>
#include <locale.h>	 
void main()
{
	setlocale(LC_ALL, "Portuguese");
	int x = 50;

	printf("X = %d\n", x);			//50. Foi o valor que atribui quando declarei a variável

	x = x + 1;
	printf("X = %d\n", x);			//51. Eu peguei no valor de x e atribui o valor de x + 1. Logo, fica 51.

	x++;							// x++ é o mesmo que ter x + 1! O que ele faz é INCREMENTAR uma unidade.
	printf("X = %d\n", x);			//52. 

	printf("X = %d\n", x++);		/*52. Aqui ele mostra na mesma 52. Ele primeiro mostra o x e só depois o incrementa. 
									*Então, só no próximo printf é que ele vai mostrar o valor incrementado.
									* printf: MOSTRA O VALOR DE X (era 52), e depois FAZ O INCREMENTO. MAS N MOSTRA O INCREMENTO
									* SÓ VAI MOSTRAR NO PROXIMO PRINTF */
	printf("X = %d\n", x);			//Aqui está a mostrar o valor já incrementado. É 53.
	
	printf("X = %d\n", ++x);		//Aqui é exactamente o contrário! Incrementa PRIMEIRO e mostra DEPOIS

/* Se eu tenho x++ - Ele MOSTRA primeiro e INCREMENTA depois
*  Se eu tenho ++x - Ele INCREMENTA primeiro e MOSTRA depois (o valor já incrementado)
*/

	printf("X = %d\n", x = x + 1); //55. ++x é igual a x + 1. 

/* Tudo o que está aqui para o incremento é igual para o decremento.
* x++ e x-- e/ou ++x ou --x
* É valido para os dois.
* Ó mesmo não acontece para a multiplicação e para a divisão.
* Veremos depois.
*/
}