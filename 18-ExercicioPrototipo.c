#ifdef _MSC_VER 
#define _CRT_SECURE_NO_WARNINGS 
#endif
#include <stdio.h>
#include <locale.h>	
void boasVindas();			//Se eu quiser colocar as funções depois do main, eu posso. CONTUDO, para ele saber, tenho de colocar o protótipo da função antes do main.
int somaValores(int n);		//PROTOTIPOS DAS FUNCOES


//Programa principal

void main()
{
	setlocale(LC_ALL, "Portuguese");
	int n;
	boasVindas();
	printf("Valor: ");
	scanf(" %d", &n);
	if (n < 0)
		n = -n;
	prinf("Soma = %d\n", somaValores(n));
}

//Implementação

void boasVindas()
{
	puts("Bem vindo ao programa");

}

int somaValores(int n)
{
	int acumulado = 0;
	for (int i = 0; i <= n; i++)
		acumulado += i;
	return acumulado;
}
