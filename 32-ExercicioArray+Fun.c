#ifdef _MSC_VER 
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <stdio.h>
#include <locale.h>
#include <math.h>

#define N 10

void mostraValores(float vet[])
{
    printf("------VALORES DO VETOR------\n");
    for (int i = 0; i < N; i++)
        printf(" %.1f", vet[i]);
    printf("\n--------------------------\n");
}

void carregaValores(float vet[])
{
    for (int i = 0; i < N; i++)
        vet[i] = rand() % 100;
    mostraValores(vet);
}

void mostraMenu() 
{
    printf("1- Gera novos valores\n 2- Ver valores\n 3- Pesquisa valores\n 0- Fim\n");
}

int PesquisaSeq(float vet[], float valor)
{
    for (int i = 0; i < N; i++)
        if (vet[i] == valor)           //Encontrei
            return i;
    return -1;                         //Devolvo indice inválido porque não encontrou
}


void main()
{

    setlocale(LC_ALL, "Portuguese");

    float valores[N], valor;
    int op, id;
    srand((unsigned)time(NULL));
    carregaValores(valores);
    do
    {
        mostraMenu();
        scanf(" %d", &op);
        switch (op)
        {
        case 1:
            carregaValores(valores);
            break;
        case 2:
            mostraValores(valores);
            break;
        case 3:
            printf("Valor a pesquisar: ");
            scanf(" %f", &valor);
            id = PesquisaSeq(valores, valor);
            if (id >= 0)
                printf("O valor %.1f, é o %d valor e está na posição %d\n ", valor, id + 1, id);
            else
                printf("O valor .1%f não existe no vetor\n", valor);
            break;
        default:
            break;
        }

    } while (op != 0);
}