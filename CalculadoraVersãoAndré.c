#ifdef _MSC_VER 
#define _CRT_SECURE_NO_WARNINGS 
#endif
#include <math.h>
#include <stdio.h>
#include <locale.h>

// Funções para operações básicas
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
		printf("Erro: Divisão por zero não permitida\n");
		return 0;
	}
}
// Funções para operações adicionais
float raizQuadrada(float a) {
	if (a >= 0) {
		return sqrt(a);
	}
	else {
		printf("Erro: Não é possível calcular a raiz quadrada de um número negativo\n");
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
	// Obter entrada do usuário
	do {
		printf("Digite um número: ");
		scanf("%f", &num1);

		printf("Digite um operador (+, -, *, /, sqrt, ^): ");
		scanf(" %c", &operador);

		printf("Digite outro número: ");
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
			printf("Operador inválido\n");
			continue;
		}
		printf("Resultado: %.2f\n", resultado);

		printf("Deseja realizar outra operação? (s/n): ");
		scanf(" %c", &continuar);

	} while (continuar == 's' || continuar == 'S');
}