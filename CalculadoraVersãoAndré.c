#ifdef _MSC_VER 
#define _CRT_SECURE_NO_WARNINGS 
#endif
#include <math.h>
#include <stdio.h>
#include <locale.h>

// Fun��es para opera��es b�sicas
float adicao(float a, float b) {
	return a + b;
}

float subtracao(float a, float b) {
	return a - b;
}

float multiplicacao(float a, float b) {
	return a * b;
}

float divisao(float a, float b) {
	if (b != 0) {
		return a / b;
	}
	else {
		printf("Erro: Divis�o por zero n�o permitida\n");
		return 0;
	}
}
// Fun��es para opera��es adicionais
float raizQuadrada(float a) {
	if (a >= 0) {
		return sqrt(a);
	}
	else {
		printf("Erro: N�o � poss�vel calcular a raiz quadrada de um n�mero negativo\n");
		return 0;
	}
}

float potencia(float base, float expoente) {
	return pow(base, expoente);
}

void main() {
	float num1, num2, resultado;
	char operador;
	char continuar;
	setlocale(LC_ALL, "Portuguese");
	// Obter entrada do usu�rio
	do {
		printf("Digite um n�mero: ");
		scanf("%f", &num1);

		printf("Digite um operador (+, -, *, /, sqrt, ^): ");
		scanf(" %c", &operador);

		printf("Digite outro n�mero: ");
		scanf("%f", &num2);

		// Calcular resultado com base no operador inserido
		switch (operador) {
		case '+':
			resultado = adicao(num1, num2);
			break;
		case '-':
			resultado = subtracao(num1, num2);
			break;
		case '*':
			resultado = multiplicacao(num1, num2);
			break;
		case '/':
			resultado = divisao(num1, num2);
			break;
		case 's':
			resultado = raizQuadrada(num1);
			break;
		case '^':
			resultado = potencia(num1, num2);
			break;
		default:
			printf("Operador inv�lido\n");
			continue;
		}
		printf("Resultado: %.2f\n", resultado);

		printf("Deseja realizar outra opera��o? (s/n): ");
		scanf(" %c", &continuar);

	} while (continuar == 's' || continuar == 'S');
}