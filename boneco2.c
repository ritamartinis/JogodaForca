#ifdef _MSC_VER 
#define _CRT_SECURE_NO_WARNINGS 
#endif
#include <stdio.h>
#include <locale.h>	 


void printBoneco(int tentativasR) {
	switch (tentativasR) {
	case 1:
		printf(" ____________     \n");
		printf("|            |    \n");
		printf("|            O    \n");
		printf("|                 \n");
		printf("|                 \n");
		printf("|                 \n");
		printf("|                 \n");
		printf("|                 \n");
		break;

	case 2:
		printf(" ____________     \n");
		printf("|            |    \n");
		printf("|            O    \n");
		printf("|            |    \n");
		printf("|            |    \n");
		printf("|				  \n");
		printf("|                 \n");
		printf("|                 \n");
		printf("|                 \n");
		break;

	case 3:
		printf(" ____________     \n");
		printf("|            |    \n");
		printf("|            O    \n");
		printf("|           /|    \n");
		printf("|            |    \n");
		printf("|                 \n");
		printf("|                 \n");
		printf("|                 \n");
		printf("|                 \n");
		break;

	case 4:
		printf(" ____________     \n");
		printf("|            |    \n");
		printf("|            O    \n");
		printf("|           /|\\  \n");
		printf("|            |    \n");
		printf("|                 \n");
		printf("|                 \n");
		printf("|                 \n");
		printf("|                 \n");
		break;

	case 5:
		printf(" ____________    \n");
		printf("|            |   \n");
		printf("|            O   \n");
		printf("|           /|\\ \n");
		printf("|            |   \n");
		printf("|           / \\ \n");
		printf("|          /   \\\n");
		printf("|                \n");
		printf("|                \n");
		printf("|                \n");
		break;

	default:
		break;
	}
}

void main() {
	int tentativasR = 5;

	for (tentativasR = 5; tentativasR > 0; tentativasR--) {
		printBoneco(tentativasR);
	}
}