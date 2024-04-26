#include <stdio.h>
void main()
{
	puts("Texto 01 no ecra...");			//Mostra e MUDA de linha
	puts("Texto 02 no ecra...");

	printf("Texto 03 no ecra...");
	printf("Texto 04 no ecra...");			//Mostra MAS NÃO muda de linha

	printf("\nTexto 05 \nno ecra...\n");	//O printf + \n já muda de linha
	printf("Texto06");

	printf("Como mostro \\ uma barra?\n");	//para uma barra, tenho de colocar duas
	printf("Como mostro \"\"aspas?\n");		//a bara indica caracter especial a seguir

	printf("Texto \t 07\n");				// \t é o tab
}

/* Quer o printf quer o puts servem para mostrar qualquer coisa no ecrã
* Como já vimos, a diferença é que o puts já muda de linha e o printf não
* CONTUDO, O PUTS SÓ SERVE PARA STRINGS (frases)
*/