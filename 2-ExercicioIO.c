#include <stdio.h>
void main()
{
	puts("Texto 01 no ecra...");			//Mostra e MUDA de linha
	puts("Texto 02 no ecra...");

	printf("Texto 03 no ecra...");
	printf("Texto 04 no ecra...");			//Mostra MAS N�O muda de linha

	printf("\nTexto 05 \nno ecra...\n");	//O printf + \n j� muda de linha
	printf("Texto06");

	printf("Como mostro \\ uma barra?\n");	//para uma barra, tenho de colocar duas
	printf("Como mostro \"\"aspas?\n");		//a bara indica caracter especial a seguir

	printf("Texto \t 07\n");				// \t � o tab
}

/* Quer o printf quer o puts servem para mostrar qualquer coisa no ecr�
* Como j� vimos, a diferen�a � que o puts j� muda de linha e o printf n�o
* CONTUDO, O PUTS S� SERVE PARA STRINGS (frases)
*/