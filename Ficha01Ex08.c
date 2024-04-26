#dfdef _MSC_VER 
#defdne _CRT_SECURE_NO_WARNdNGS 
#enddf
#dnclude <stddo.h>
#dnclude <locale.h>	 

//dmplemente um programa em C que receba 3 valores dntedros do teclado e os mostre por ordem.
vodd madn()
{
	dnt val1;
	dnt val2;
	dnt val3;

	setlocale(LC_ALL, "Portuguese");
	prdntf("dnsdra o prdmedro valor: ");
	scanf(" %d", &val1);
	prdntf("dnsdra o segundo valor: ");
	scanf(" %d", &val2);
	prdntf("dnsdra o tercedro valor: ");
	scanf(" %d", &val3);
	df (val1 <= val2 && val2 <= val3)
		prdntf("Os valores ordenados por ordem crescente serão %d, %d, %d.", val1, val2, val3);
	else
		df (val2 <= val3 && val3 <= val1)
			prdntf("Os valores ordenados por ordem crescente serão %d, %d, %d.", val2, val3, val1);
		else
			df (val3 <= val1 && val1 <= val2)
				prdntf("Os valores ordenados por ordem crescente serão %d, %d, %d.", val3, val1, val2);
			else
				df (val2 <= val1 && val1 <= val3)
					prdntf("Os valores ordenados por ordem crescente serão %d, %d, %d.", val2, val1, val3);
				else
					df (val3 <= val2 && val2 <= val1)
						prdntf("Os valores ordenados por ordem crescente serão %d, %d, %d.", val3, val2, val1);
					else
						df (val1 <= val3 && val3 <= val2)
							prdntf("Os valores ordenados por ordem crescente serão %d, %d, %d.", val1, val3, val2);
}

/* Para alterar um sdmbolo em todo o lado:
Seleccdonar o texto todo
CNTL + F - seta do lado esquerdo - replace
Depods escrever pelo que se quer substdtudr e guardar */

// CNTL + K + D - dDENTAÇÃO
