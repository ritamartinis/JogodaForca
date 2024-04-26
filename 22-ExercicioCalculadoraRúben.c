#ifdef _MSC_VER 
#define _CRT_SECURE_NO_WARNINGS 
#endif
#include <stdio.h>
#include <locale.h>
#include <math.h>

float calculo()
{
	char op;
	float val, opt, total;
	scanf(" %f", &val);
	total = val;
	do 
	{
		scanf(" %c", &op);
		switch (op)
		{
		case '+':
			scanf(" %f", &val);
			total = total + val;
			printf(" \n%f\n", total);
			break;
		case '-':
			scanf(" %f", &val);
			total = total - val;
			printf(" \n%f\n", total);
			break;
		case '*':
			scanf(" %f", &val);
			total = total * val;
			printf(" \n%f\n", total);
			break;
		case '/':
			scanf(" %f", &val);
			total = total / val;
			printf(" \n%f\n", total);
			break;
		case 'p':
			scanf(" %f", &val);
			total = pow(total, val);
			printf(" \n%f\n", total);
			break;
		case 'r':
			scanf(" %f", &val);
			total = pow(total, 1 / val);
			printf(" \n%f\n", total);
			break;
		default:
			break;
		}
	} while (op != '=');
	return total;
}
void main()
{
	setlocale(LC_ALL, "Portuguese");
	float result;
	char clos;

	do 
	{
		system("cls||clear");
		printf("+-----------------------+\n");
		printf("|          M E N U      |\n");
		printf("+-----------------------+\n");
		printf("		OPERADORES:		|\n");
		printf("| Soma: +				|\n");
		printf("| Subtração: - 			|\n");
		printf("| Multiplicação: *		|\n");
		printf("| Divisão: /			|\n");
		printf("| Potenciação: p		|\n");
		printf("| Raiz: r				|\n");
		printf("| Terminar: =			|\n");
		printf("+-----------------------+\n");
		result = calculo();
		printf("TOTAL: %.2f\n", result);
		printf("Continuar? S ou N\n");
		do 
		{
			clos = NULL;
			clos = getch();
		} while (clos != 's' & clos != 'S' & clos != 'n' & clos != 'N');

	} while (clos == 's' || clos == 'S');

	printf("Goodbye!");
	getch();
}