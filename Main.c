#include <stdio.h>
#include <stdlib.h>

// Constante com o tamanho máximo das matrizes
#define TamanhoMaximo 10

// Função para entrada dos elementos na matriz
void InputMatriz(int linhas, int colunas, double (*matriz)[TamanhoMaximo]) {
    /*
     * Função: void InputMatriz(int linhas, int colunas, double (*matriz)[TamanhoMaximo])
     * Descrição: Loop para armazenas os elementos da matriz.
     * Parâmetros:
     *   linhas: O número de linhas da matriz.
     *   colunas: O número de colunas da matriz.
     *   matriz: A matriz onde os elementos serão armazenados.
     * Retorno: Nenhum.
     */

    int i, j;
    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            printf("Elemento[%d][%d] = ", i + 1, j + 1); // Solicita ao usuário o elemento
            while (scanf("%lf", &matriz[i][j]) != 1) { // Verifica se o usuário inseriu um número
                printf("Entrada inválida. Por favor, insira um número!\n");
                printf("Elemento[%d][%d] = ", i + 1, j + 1); // Solicita ao usuário o elemento novamente
                while (getchar() != '\n'); // Limpa o buffer do teclado
            }
        }
    }
}

// Função para exibição de matriz
void ExibirMatriz(int linhas, int colunas, double (*matriz)[TamanhoMaximo]) {
    /*
     * Função: void ExibirMatriz(int linhas, int colunas, double (*matriz)[TamanhoMaximo])
     * Descrição: Exibe os elementos de uma matriz.
     * Parâmetros:
     *   linhas: O número de linhas da matriz.
     *   colunas: O número de colunas da matriz.
     *   matriz: A matriz a ser exibida.
     * Retorno: Nenhum.
     */

    int i, j;
    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            printf("[%.2lf] ", matriz[i][j]); // Imprime a matriz com duas casas decimais
        }
        printf("\n");
    }
}

// Função para calcular a matriz inversa usando o método de eliminação de Gauss-Jordan
void InversaMatriz(int dimensao, double (*matriz)[TamanhoMaximo], double (*matrizInversa)[TamanhoMaximo]) {
    /*
     * Função: void InversaMatriz(int dimensao, double (*matriz)[TamanhoMaximo], double (*matrizInversa)[TamanhoMaximo])
     * Descrição: Calcula a matriz inversa usando o método de eliminação de Gauss-Jordan.
     * Parâmetros:
     *   dimensao: A dimensão da matriz quadrada.
     *   matriz: A matriz original.
     *   matrizInversa: A matriz onde a inversa será armazenada.
     * Retorno: Nenhum.
     */

    // Matriz temporária que armazena a matriz aumentada, sendo a matriz + a matriz identidade
    double matrizTemp[TamanhoMaximo][2 * TamanhoMaximo];

    // Inicializar a matriz aumentada com a matriz original e a matriz identidade
    int i, j;
    for (i = 0; i < dimensao; i++) {
        for (j = 0; j < dimensao; j++) {
            matrizTemp[i][j] = matriz[i][j];
            // Matriz identidade
            matrizTemp[i][j + dimensao] = (i == j) ? 1.0 : 0.0; // "Se i for igual a j, o elemento assume 1.0, senão assume 0.0"
        }
    }

    // Método de eliminação de Gauss-Jordan
    for (i = 0; i < dimensao; i++) {
        // Pivô (matriz[i][i]) assume 1 e zera todos os outros elementos na mesma coluna
        double piv = matrizTemp[i][i];
        for (j = 0; j < 2 * dimensao; j++) {
            matrizTemp[i][j] /= piv;
        }

        // Zera todos os elementos nas outras linhas e colunas
        for (int k = 0; k < dimensao; k++) {
            if (k != i) {
                double fator = matrizTemp[k][i];
                for (j = 0; j < 2 * dimensao; j++) {
                    matrizTemp[k][j] -= fator * matrizTemp[i][j];
                }
            }
        }
    }

    // Copia a matriz inversa para a saída
    for (i = 0; i < dimensao; i++) {
        for (j = 0; j < dimensao; j++) {
            matrizInversa[i][j] = matrizTemp[i][j + dimensao];
        }
    }
}

// Função para soma entre matrizes
void SomaMatriz(int linhas, int colunas, double (*matrizA)[TamanhoMaximo], double (*matrizB)[TamanhoMaximo], double (*matrizCalculo)[TamanhoMaximo]) {
    /*
     * Função: void SomaMatriz(int linhas, int colunas, double (*matrizA)[TamanhoMaximo], double (*matrizB)[TamanhoMaximo], double (*matrizCalculo)[TamanhoMaximo])
     * Descrição: Realiza a soma entre duas matrizes.
     * Parâmetros:
     *   linhas: O número de linhas das matrizes.
     *   colunas: O número de colunas das matrizes.
     *   matrizA: A primeira matriz.
     *   matrizB: A segunda matriz.
     *   matrizCalculo: A matriz onde a soma será armazenada.
     * Retorno: Nenhum.
     */

    int i, j;
    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            matrizCalculo[i][j] = matrizA[i][j] + matrizB[i][j]; // Reliza a soma dos elementes entre as matrizes
        }
    }
}

// Função para subtração entre matrizes
void SubtracaoMatriz(int linhas, int colunas, double (*matrizA)[TamanhoMaximo], double (*matrizB)[TamanhoMaximo], double (*matrizCalculo)[TamanhoMaximo]) {
    /*
     * Função: void SubtracaoMatriz(int linhas, int colunas, double (*matrizA)[TamanhoMaximo], double (*matrizB)[TamanhoMaximo], double (*matrizCalculo)[TamanhoMaximo])
     * Descrição: Realiza a subtração entre duas matrizes.
     * Parâmetros:
     *   linhas: O número de linhas das matrizes.
     *   colunas: O número de colunas das matrizes.
     *   matrizA: A primeira matriz.
     *   matrizB: A segunda matriz.
     *   matrizCalculo: A matriz onde a subtração será armazenada.
     * Retorno: Nenhum.
     */

    int i, j;
    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            matrizCalculo[i][j] = matrizA[i][j] - matrizB[i][j]; // Reliza a subtração dos elementes entre as matrizes
        }
    }
}

// Função para multiplicação entre matrizes
void MultiplicacaoMatriz(int linhasA, int colunasA, int colunasB, double (*matrizA)[TamanhoMaximo], double (*matrizB)[TamanhoMaximo], double (*matrizCalculo)[TamanhoMaximo]) {
    /*
     * Função: void MultiplicacaoMatriz(int linhasA, int colunasA, int colunasB, double (*matrizA)[TamanhoMaximo], double (*matrizB)[TamanhoMaximo], double (*matrizCalculo)[TamanhoMaximo])
     * Descrição: Realiza a multiplicação entre duas matrizes.
     * Parâmetros:
     *   linhasA: O número de linhas da primeira matriz.
     *   colunasA: O número de colunas da primeira matriz e de linhas da segunda matriz.
     *   colunasB: O número de colunas da segunda matriz.
     *   matrizA: A primeira matriz.
     *   matrizB: A segunda matriz.
     *   matrizCalculo: A matriz onde o resultado da multiplicação será armazenado.
     * Retorno: Nenhum.
     */

    int i, j, k;
    for (i = 0; i < linhasA; i++) {
        for (j = 0; j < colunasB; j++) {
            matrizCalculo[i][j] = 0;
            for (k = 0; k < colunasA; k++) {
                matrizCalculo[i][j] += matrizA[i][k] * matrizB[k][j]; // Reliza a multiplicação dos elementes entre as matrizes
            }
        }
    }
}

// Função para transposição de matriz
void TransposicaoMatriz(int linhas, int colunas, double (*matriz)[TamanhoMaximo], double (*matrizTransposta)[TamanhoMaximo]) {
    /*
     * Função: void TransposicaoMatriz(int linhas, int colunas, double (*matriz)[TamanhoMaximo], double (*matrizTransposta)[TamanhoMaximo])
     * Descrição: Calcula a transposta de uma matriz.
     * Parâmetros:
     *   linhas: O número de linhas da matriz original.
     *   colunas: O número de colunas da matriz original.
     *   matriz: A matriz original.
     *   matrizTransposta: A matriz onde a transposta será armazenada.
     * Retorno: Nenhum.
     */

    int i, j;
    for (i = 0; i < colunas; i++) {
        for (j = 0; j < linhas; j++) {
            matrizTransposta[i][j] = matriz[j][i];
        }
    }
}

// Função para calcular o determinante de uma matriz quadrada
double DeterminanteMatriz(int ordem, double (*matriz)[TamanhoMaximo]) {
    /*
     * Função: double DeterminanteMatriz(int ordem, double (*matriz)[TamanhoMaximo])
     * Descrição: Calcula o determinante de uma matriz quadrada.
     * Parâmetros:
     *   ordem: A ordem da matriz quadrada.
     *   matriz: A matriz quadrada.
     * Retorno: O determinante da matriz.
     */

    // Se a ordem da matriz for 1, retorna o único elemento da matriz como o determinante
    if (ordem == 1) {
        return matriz[0][0];
    } else {
        double det = 0;
        double sinal = 1;
        int i, j, k;
        double submatriz[TamanhoMaximo][TamanhoMaximo];

        // Loop sobre a primeira linha para calcular o determinante
        for (i = 0; i < ordem; i++) {
            int sub_linha = 0, sub_coluna = 0;
            // Criando a submatriz excluindo a linha e coluna do elemento atual
            for (j = 1; j < ordem; j++) {
                for (k = 0; k < ordem; k++) {
                    if (k == i) continue; // Ignora a coluna do elemento atual
                    submatriz[sub_linha][sub_coluna] = matriz[j][k];
                    sub_coluna++;
                }
                sub_linha++;
                sub_coluna = 0;
            }
            // Calcula recursivamente o determinante da submatriz e soma ao determinante
            det += sinal * matriz[0][i] * DeterminanteMatriz(ordem - 1, submatriz);
            // Alterna o sinal para o próximo termo da expansão
            sinal = -sinal;
        }
        return det;
    }
}

// Função para executar uma operação escalar em uma matriz
void OperacaoEscalar(int linhas, int colunas, double (*matrizA)[TamanhoMaximo], double escalar, char operacao, double (*matrizResultado)[TamanhoMaximo]) {
    /*
     * Função: void OperacaoEscalar(int linhas, int colunas, double (*matrizA)[TamanhoMaximo], double escalar, char operacao, double (*matrizResultado)[TamanhoMaximo])
     * Descrição: Realiza uma operação escalar em uma matriz (multiplicação ou divisão por um escalar).
     * Parâmetros:
     *   linhas: O número de linhas da matriz.
     *   colunas: O número de colunas da matriz.
     *   matrizA: A matriz.
     *   escalar: O escalar para a operação.
     *   operacao: A operação a ser realizada ('1' para multiplicação, '2' para divisão).
     *   matrizResultado: A matriz onde o resultado da operação será armazenado.
     * Retorno: Nenhum.
     */

    int i, j;
    // Loop para iterar sobre todas as células da matriz
    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            // Verifica a operação a ser realizada
            switch (operacao) {
                // Multiplicação por um escalar
                case 1:
                    matrizResultado[i][j] = matrizA[i][j] * escalar; // Multiplica o elemente pelo escalar
                    break;
                // Divisão por um escalar e verificação para divisões por zero
                case 2:
                    if (escalar != 0)
                        matrizResultado[i][j] = matrizA[i][j] / escalar; // Divide o elemente pelo escalar
                    else
                        printf("Não é possível realizar a divisão por zero.\n");
                    break;
                // Operação inválida
                default:
                    printf("Operação inválida.\n");
                    break;
            }
        }
    }
}


int main(void) {
    int linhasA, colunasA, colunasB, operacao, formula, continuar = 1;
    double matrizA[TamanhoMaximo][TamanhoMaximo], matrizB[TamanhoMaximo][TamanhoMaximo], matrizCalculo[TamanhoMaximo][TamanhoMaximo], matrizTransposta[TamanhoMaximo][TamanhoMaximo], matrizInversa[TamanhoMaximo][TamanhoMaximo];
    double escalar, determinante;

    // Loop para manter o programa em execução até que o usuário escolha parar
    while (continuar) {
        system("clear");
        printf("~ CALCULADORA DE MATRIZES ~\n===========================\n\n");
        printf("1 - Adição de matrizes\n2 - Subtração de matrizes\n3 - Multiplicação de matrizes\n4 - Transposição de matriz\n5 - Determinante de matriz\n6 - Matriz Inversa\n7 - Operações Escalares\n0 - Encerrar programa\n\n");
        printf("Insira o número equivalente à operação desejada: ");
        scanf("%d", &formula);

        // Switch case para escolher a operação a ser realizada
        switch (formula) {
            case 0:
                continuar = 0; // Variável continuar como 0 encerra o loop
                break;

            case 1:
                // Código para adição de matrizes
                system("clear");
                printf("~ ADIÇÃO DE MATRIZES ~\n===========================\n\n");

                //Solicita as dimensões das matrizes
                printf("\nInforme a quantidade de linhas da matriz: ");
                scanf("%d", &linhasA);
                printf("Informe a quantidade de colunas da matriz: ");
                scanf("%d", &colunasA);
              
                // Solicita os elementos da matriz
                printf("\n\nInsira os elementos da matriz A:\n");
                InputMatriz(linhasA, colunasA, matrizA);
                printf("\nInsira os elementos da matriz B:\n");
                InputMatriz(linhasA, colunasA, matrizB);

                // Exibe as matrizes
                printf("\n\nMatriz A:\n");
                ExibirMatriz(linhasA, colunasA, matrizA);
                printf("\nMatriz B:\n");
                ExibirMatriz(linhasA, colunasA, matrizB);

                // Realiza a adição entre as matrizes
                SomaMatriz(linhasA, colunasA, matrizA, matrizB, matrizCalculo);

                // Exibe o resultado
                printf("\n\nResultado da soma:\n");
                ExibirMatriz(linhasA, colunasA, matrizCalculo);

                // Sai da opção escolhida
                printf("\n\nClique em 'Enter' para continuar. ");
                getchar();
                getchar();
                break;

            case 2:
                // Código para subtração de matrizes
                system("clear");
                printf("~ SUBTRAÇÃO DE MATRIZES ~\n===========================\n\n");
              
                //Solicita as dimensões das matrizes
                printf("\nInforme a quantidade de linhas da matriz: ");
                scanf("%d", &linhasA);
                printf("Informe a quantidade de colunas da matriz: ");
                scanf("%d", &colunasA);
              
                // Solicita os elementos da matriz
                printf("\n\nInsira os elementos da matriz A:\n");
                InputMatriz(linhasA, colunasA, matrizA);
                printf("\nInsira os elementos da matriz B:\n");
                InputMatriz(linhasA, colunasA, matrizB);

                // Exibe as matrizes
                printf("\n\nMatriz A:\n");
                ExibirMatriz(linhasA, colunasA, matrizA);
                printf("\nMatriz B:\n");
                ExibirMatriz(linhasA, colunasA, matrizB);
              
                // Realiza a subtração entre as matrizes
                SubtracaoMatriz(linhasA, colunasA, matrizA, matrizB, matrizCalculo);
              
                // Exibe o resultado
                printf("\n\nResultado da subtração:\n");
                ExibirMatriz(linhasA, colunasA, matrizCalculo);

                // Sai da opção escolhida
                printf("\n\nClique em 'Enter' para continuar. ");
                getchar();
                getchar();
                break;

            case 3:
                // Código para multiplicação de matrizes
                system("clear");
                printf("~ MULTIPLICAÇÃO DE MATRIZES ~\n===========================\n\n");
              
                //Solicita as dimensões das matrizes
                printf("\nInforme a quantidade de linhas da matriz A: ");
                scanf("%d", &linhasA);
                printf("Informe a quantidade de colunas da matriz A: ");
                scanf("%d", &colunasA);
                printf("Informe a quantidade de colunas da matriz B: ");
                scanf("%d", &colunasB);

                // Solicita os elementos da matriz
                printf("\n\nInsira os elementos da matriz A:\n");
                InputMatriz(linhasA, colunasA, matrizA);
                printf("\nInsira os elementos da matriz B:\n");
                InputMatriz(colunasA, colunasB, matrizB);

                // Exibe as matrizes
                printf("\n\nMatriz A:\n");
                ExibirMatriz(linhasA, colunasA, matrizA);
                printf("\nMatriz B:\n");
                ExibirMatriz(colunasA, colunasB, matrizB);

                // Realiza a multiplicação entre as matrizes
                MultiplicacaoMatriz(linhasA, colunasA, colunasB, matrizA, matrizB, matrizCalculo);

                // Exibe o resultado
                printf("\n\nResultado da multiplicação:\n");
                ExibirMatriz(linhasA, colunasB, matrizCalculo);

                // Sai da opção escolhida
                printf("\n\nClique em 'Enter' para continuar. ");
                getchar();
                getchar();
                break;

            case 4:
                system("clear");
                printf("~ TRANSPOSIÇÃO DE MATRIZ ~\n===========================\n\n");

                //Solicita as dimensões da matriz
                printf("\nInforme a quantidade de linhas da matriz: ");
                scanf("%d", &linhasA);
                printf("Informe a quantidade de colunas da matriz: ");
                scanf("%d", &colunasA);

                // Verifica se o número de linhas e colunas ultrapassam o tamanho maximo da matriz ou se são menores do que 1
                if (linhasA < 1 || colunasA < 1 || linhasA > TamanhoMaximo || colunasA > TamanhoMaximo) {
                    printf("\n*** Tamanho da matriz inválido! ***\n");
                    // Sai da opção escolhida
                    printf("\n\nClique em 'Enter' para continuar. ");
                    getchar();
                    getchar();
                    break;
                }

                // Solicita os elementos da matriz
                printf("\n\nInsira os elementos da matriz:\n");
                InputMatriz(linhasA, colunasA, matrizA);
                printf("\n\nMatriz:\n");
                ExibirMatriz(linhasA, colunasA, matrizA);

                // Realiza a transposição da matriz
                TransposicaoMatriz(linhasA, colunasA, matrizA, matrizTransposta);

                // Exibe o resultado
                printf("\n\nMatriz Transposta:\n");
                ExibirMatriz(colunasA, linhasA, matrizTransposta);

                // Sai da opção escolhida
                printf("\n\nClique em 'Enter' para continuar. ");
                getchar();
                getchar();
                break;

            case 5:
                system("clear");
                printf("~ DETERMINANTE DE MATRIZ ~\n===========================\n\n");

                //Solicita as dimensões da matriz
                printf("\nInforme a ordem da matriz quadrada: ");
                scanf("%d", &linhasA);
              
                // Verifica se o número de linhas e colunas ultrapassam o tamanho maximo da matriz
                if (linhasA <= 0 || linhasA > TamanhoMaximo) {
                    printf("\n*** Tamanho da matriz inválido! ***\n");
                    // Sai da opção escolhida
                    printf("\n\nClique em 'Enter' para continuar. ");
                    getchar();
                    getchar();
                    break;
                }

                // Solicita os elementos da matriz
                printf("\n\nInsira os elementos da matriz:\n");
                InputMatriz(linhasA, linhasA, matrizA);

                // Exibe a matriz
                printf("\n\nMatriz:\n");
                ExibirMatriz(linhasA, linhasA, matrizA);

                // Calcula o determinante da matriz e define a variavel "determinante" com o valor
                determinante = DeterminanteMatriz(linhasA, matrizA);
                
                // Exibe o resultado
                printf("\n\nDeterminante da matriz: %.2lf\n", determinante);

                // Sai da opção escolhida
                printf("\n\nClique em 'Enter' para continuar. ");
                getchar();
                getchar();
                break;

            case 6:
                system("clear");
                printf("~ MATRIZ INVERSA ~\n===========================\n\n");

                //Solicita as dimensões da matriz
                printf("\nInforme a ordem da matriz quadrada: ");
                scanf("%d", &linhasA);

                if (linhasA <= 0 || linhasA > TamanhoMaximo) {
                    printf("\n*** Tamanho da matriz inválido! ***\n");
                    break;
                }

                // Solicita os elementos da matriz
                printf("\n\nInsira os elementos da matriz:\n");
                InputMatriz(linhasA, linhasA, matrizA);

                printf("\n\nMatriz:\n");
                ExibirMatriz(linhasA, linhasA, matrizA);

                InversaMatriz(linhasA, matrizA, matrizInversa);

                determinante = DeterminanteMatriz(linhasA, matrizA);
                if(determinante == 0){
                  printf("\n\nO determinante da matriz é zero, portante não é invertível!");
                }else{
                  printf("\n\nMatriz Inversa:\n");
                  ExibirMatriz(linhasA, linhasA, matrizInversa);
                }
              
                printf("\n\nClique em 'Enter' para continuar. ");
                getchar();
                getchar();
                break;

            case 7:
                system("clear");
                printf("~ OPERAÇÕES ESCALARES ~\n===========================\n\n");

                // Solicita a operação a ser realizada nas operações escalares
                printf("1 - Multiplicação\n2 - Divisão\n\n");
                printf("Insira o número equivalente à operação desejada: ");
                scanf("%d", &operacao);

                //Solicita as dimensões da matriz
                printf("\nInforme a quantidade de linhas da matriz: ");
                scanf("%d", &linhasA);
                printf("Informe a quantidade de colunas da matriz: ");
                scanf("%d", &colunasA);

                // Solicita o escalar a ser usádo no calculo
                printf("\nInforme o escalar: ");
                scanf("%lf", &escalar);

                // Solicita os elementos da matriz
                printf("\n\nInsira os elementos da matriz:\n");
                InputMatriz(linhasA, colunasA, matrizA);

                printf("\n\nMatriz:\n");
                ExibirMatriz(linhasA, colunasA, matrizA);

                printf("\n\nResultado da operação escalar:\n");
                OperacaoEscalar(linhasA, colunasA, matrizA, escalar, operacao, matrizCalculo);
                ExibirMatriz(linhasA, colunasA, matrizCalculo);
                printf("\n\nClique em 'Enter' para continuar. ");
                getchar();
                getchar();
                break;

            default:
                printf("\n\n*** Opção inválida, por favor escolha uma opção válida ou digite 0 para encerrar o programa. ***\n");
                break;
        }
    }

    printf("\nPrograma encerrado.\n");

    return 0;
}
