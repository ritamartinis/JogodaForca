#ifdef _MSC_VER 
#define _CRT_SECURE_NO_WARNINGS 
#endif
#include <stdio.h>
#include <locale.h>	 
void main()
{
	setlocale(LC_ALL, "Portuguese");
	int x = 50;

	printf("X = %d\n", x);			//50. Foi o valor que atribui quando declarei a vari�vel

	x = x + 1;
	printf("X = %d\n", x);			//51. Eu peguei no valor de x e atribui o valor de x + 1. Logo, fica 51.

	x++;							// x++ � o mesmo que ter x + 1! O que ele faz � INCREMENTAR uma unidade.
	printf("X = %d\n", x);			//52. 

	printf("X = %d\n", x++);		/*52. Aqui ele mostra na mesma 52. Ele primeiro mostra o x e s� depois o incrementa. 
									*Ent�o, s� no pr�ximo printf � que ele vai mostrar o valor incrementado.
									* printf: MOSTRA O VALOR DE X (era 52), e depois FAZ O INCREMENTO. MAS N MOSTRA O INCREMENTO
									* S� VAI MOSTRAR NO PROXIMO PRINTF */
	printf("X = %d\n", x);			//Aqui est� a mostrar o valor j� incrementado. � 53.
	
	printf("X = %d\n", ++x);		//Aqui � exactamente o contr�rio! Incrementa PRIMEIRO e mostra DEPOIS

/* Se eu tenho x++ - Ele MOSTRA primeiro e INCREMENTA depois
*  Se eu tenho ++x - Ele INCREMENTA primeiro e MOSTRA depois (o valor j� incrementado)
*/

	printf("X = %d\n", x = x + 1); //55. ++x � igual a x + 1. 

/* Tudo o que est� aqui para o incremento � igual para o decremento.
* x++ e x-- e/ou ++x ou --x
* � valido para os dois.
* � mesmo n�o acontece para a multiplica��o e para a divis�o.
* Veremos depois.
*/
}