#ifdef _MSC_VER 
#define _CRT_SECURE_NO_WARNINGS 
#endif
#include <stdio.h>
#include <locale.h>


void main()
{
    setlocale(LC_ALL, "Portuguese");

    printf("====================================================\n");
    printf("                                                    \n");
    printf("            BEM VINDO AO JOGO DA FORCA VERSÃO '/C'  \n");
    printf("                                                    \n");
    printf("====================================================\n");
    srand(time(NULL)); // serve para gerar um numero aleatório novo sempre que se corre o programa

    int jogar_outravez;
    do
    {
        char nivel1[5][4] = { "cao", "cao", "cao", "cao","cao" };  //array com 5 palavras e cada palavra tem 3 letras (3 + \0)
        char nivel2[5][5] = { "gato", "rato", "leme", "rita", "rita" };  //array com 5 palavras e cada palavra tem 4 letras (4 + \0)
        char nivel3[5][6] = { "amigo", "brisa", "dente", "certo", "estar" };  //array com 5 palavras e cada palavra tem 5 letras (5 + \0)

        int n_aleatorio; //variavel para guardar um numero para o index aleatório
        int nivel_jogo;  //nivel do jogo selecionado pelo utilizador

        char letra; //letras que user vai adivinhar
        int nr_tentativas = 5;
        int pontuacao = 0; //pontuacao do user
        int correto = 0;    //variavel para  saber se user acertou na letra ou nao
        int cont_letras_corretas = 0; //contador para saber quantas letras certas o user tem
        char letras_corretas[26] = { 0 }; //array para guardar as letras adivinhadas pelo user para ele nao adivinhar duas vezes a mesma letra

        do
        {
            printf("Escolha o nível que pretende jogar [1 a 3]:");

            if (scanf(" %d", &nivel_jogo) != 1)          // se o input nao for um inteiro, o buffer é apagado
            {
                while (getchar() != '\n');
                printf("Entrada inválida. Por favor, escolha um número entre 1 e 3.\n");
                continue; // faz skip no resto da iteração do loop
            }

            if (nivel_jogo < 1 || nivel_jogo > 3)
            {
                printf("Nível inválido. Escolha entre 1 e 3.\n");
            }

            if (nivel_jogo == 1)
            {
                n_aleatorio = rand() % 5; //gerar um nr aleatorio entre 1 e 5
                printf("Palavra a adivinhar: ");
                for (int i = 0; i < 3; i++)
                {
                    printf("_ ");
                }
                puts(""); // só para fazer paragrafo
                do
                {
                    correto = 0; //reset do contador por cada iteração
                    printf("\nEscolha uma letra: ");
                    scanf(" %c", &letra);

                    // Confirma se a letra insirida já foi sugerida ou nao
                    if (letras_corretas[letra - 'a'])
                    {
                        printf("Essa letra já foi escolhida. Tente novamente.\n");
                        continue; // salta este loop à frente porque a letra ja existe
                    }

                    letras_corretas[letra - 'a'] = 1; // regista a letra como adivinhada

                    for (int i = 0; i < 3; i++)     //ciclo para ler a palavra de 3 letras
                    {
                        if (nivel1[n_aleatorio][i] == letra)
                        {
                            correto = 1; //se o user acertar na letra esta variavel passa a 1
                            printf("%c ", letra);
                            cont_letras_corretas++; // Incrementa o contador de letras corretas
                        }
                        else
                            printf("_ ");
                    }

                    if (correto == 0)
                    {
                        nr_tentativas--;    //numero de tentativas decrementa de a pessoa errar
                        printf("\nNão acertou na letra. Tem mais %d tentativas \n", nr_tentativas);
                    }
                    else
                    {
                        printf("\nBoa, acertaste uma letra\n");
                    }

                } while (nr_tentativas > 0 && cont_letras_corretas < 3);   //este ciclo corre enquanto o use tiver tentativas e a palavra não estiver totalmente correta

                if (cont_letras_corretas == 3)              //mensagem para o user quando acerta a palavra toda
                {
                    printf("\nParabéns! Você adivinhou a palavra mistério!!!!\n");
                }
                else
                    printf("Voçê falhou a adivinhar a palavra nas possíveis tentativas. A palavra mistério é: %s\n\n ", nivel1[n_aleatorio]);
            }
            else if (nivel_jogo == 2)
            {
                n_aleatorio = rand() % 5; //gerar um nr aleatorio entre 1 e 5
                printf("Palavra a adivinhar: ");
                for (int i = 0; i < 3; i++)
                {
                    printf("_ ");
                }
                puts("");

                do
                {
                    correto = 0; //reset do contador por cada iteração
                    printf("\nEscolha uma letra: ");
                    scanf(" %c", &letra);

                    // Confirma se a letra insirida já foi sugerida ou nao
                    if (letras_corretas[letra - 'a'])
                    {
                        printf("Essa letra já foi escolhida. Tente novamente.\n");
                        continue; // salta este loop à frente porque a letra ja existe
                    }

                    letras_corretas[letra - 'a'] = 1; // regista a letra como adivinhada


                    for (int i = 0; i < 4; i++)     //ciclo para ler a palavra de 4 letras
                    {
                        if (nivel2[n_aleatorio][i] == letra)
                        {
                            correto = 1; //se o user acertar na letra esta variavel passa a 1
                            printf("%c ", letra);
                        }
                        else
                            printf("_ ");
                    }

                    if (correto == 0)
                    {
                        nr_tentativas--;    //numero de tentativas decrementa de a pessoa errar
                        printf("\nNão acertou na letra. Tem mais %d tentativas \n", nr_tentativas);
                    }
                    else
                    {
                        printf("\nBoa, acertaste uma letra\n");
                    }

                } while (nr_tentativas > 0 && cont_letras_corretas < 4);   //este ciclo corre enquanto o use tiver tentativas e a palavra não estiver totalmente correta

                if (cont_letras_corretas == 4)              //mensagem para o user quando acerta a palavra toda
                {
                    printf("\nParabéns! Você adivinhou a palavra mistério!!!!\n");
                }

            }
            else if (nivel_jogo == 3)
            {
                n_aleatorio = rand() % 5; //gerar um nr aleatorio entre 1 e 5
                printf("Palavra a adivinhar: ");
                for (int i = 0; i < 5; i++)
                {
                    printf("_ ");
                }
                puts(""); // só para fazer um paragrafo

                do
                {
                    correto = 0; //reset do contador por cada iteração
                    printf("\nEscolha uma letra: ");
                    scanf(" %c", &letra);

                    // Confirma se a letra insirida já foi sugerida ou nao
                    if (letras_corretas[letra - 'a'])
                    {
                        printf("Essa letra já foi escolhida. Tente novamente.\n");
                        continue; // salta este loop à frente porque a letra ja existe
                    }

                    letras_corretas[letra - 'a'] = 1; // regista a letra como adivinhada


                    for (int i = 0; i < 5; i++)     //ciclo para ler a palavra de 3 letras
                    {
                        if (nivel3[n_aleatorio][i] == letra)
                        {
                            correto = 1; //se o user acertar na letra esta variavel passa a 1
                            printf("%c ", letra);
                        }
                        else
                            printf("_ ");
                    }

                    if (correto == 0)
                    {
                        nr_tentativas--;    //numero de tentativas decrementa de a pessoa errar
                        printf("\nNão acertou na letra. Tem mais %d tentativas \n", nr_tentativas);
                    }
                    else
                    {
                        printf("\nBoa, acertaste uma letra\n");
                    }

                } while (nr_tentativas > 0 && cont_letras_corretas < 5);   //este ciclo corre enquanto o user tiver tentativas e a palavra não estiver totalmente correto
                if (cont_letras_corretas == 5)              //mensagem para o user quando acerta a palavra toda
                {
                    printf("\nParabéns! Você adivinhou a palavra mistério!!!!\n");
                }
            }

        } while (nivel_jogo != 1 && nivel_jogo != 2 && nivel_jogo != 3);      //ciclo para o user escolher o nivel certo entre 1 e 3
        do
        {
            printf("\nDeseja jogar novamente? (1 para sim, 0 para não): ");
            if (scanf("%d", &jogar_outravez) != 1)  //confirmar se o user
            {
                while (getchar() != '\n');   // se o input inserido pelo user nao for um inteiro, entra neste ciclo e limpa o buffer

                printf("\nPor favor, digite 1 para jogar novamente ou 0 para sair.\n");
            }
        } while (jogar_outravez != 0 && jogar_outravez != 1);   //loop continua enquanto o input nao for nem 1 nem 0 (garante que o user mete um desses dois numeros)

    } while (jogar_outravez == 1);   //se o user inserir 0, o programa termina


    printf("\nObrigado por ter jogado!!!!\n");
    printf("\nTrabalho realizado por Rita, Rui e Ruben \n\n");
    printf("   O\n");
    printf("  /|\\\n");
    printf("   |   \n");
    printf("  / \\\n");
    printf(" /   \\\n");
    printf("/     \\\n");


}
