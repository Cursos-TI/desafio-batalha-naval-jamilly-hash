#include <stdio.h>

#define TAM 10
#define VALOR_AGUA 0
#define VALOR_NAVIO 3

int main() {
    int tabuleiro[TAM][TAM] = {0};

    // 1. Navio horizontal em E2, F2, G2
    int linhaH = 1;    // Linha 2 (índice 1)
    int colunaH = 4;   // Coluna E (índice 4)
    for (int i = 0; i < 3; i++) {
        tabuleiro[linhaH][colunaH + i] = VALOR_NAVIO;
    }

    // 2. Navio vertical em B5, B6, B7
    int linhaV = 4;    // Linha 5 (índice 4)
    int colunaV = 1;   // Coluna B (índice 1)
    for (int i = 0; i < 3; i++) {
        tabuleiro[linhaV + i][colunaV] = VALOR_NAVIO;
    }

    // Exibindo o título
    printf("TABULEIRO BATALHA NAVAL\n");

    // Exibindo as letras das colunas A-J
    printf("    "); // Espaço para alinhar com os números das linhas
    for (char letra = 'A'; letra < 'A' + TAM; letra++) {
        printf(" %c", letra);
    }
    printf("\n");

    // Exibindo o tabuleiro com linha numerada
    for (int i = 0; i < TAM; i++) {
        printf("%2d  ", i + 1); // Alinhamento adequado (ex: "10  ")
        for (int j = 0; j < TAM; j++) {
            printf(" %d", tabuleiro[i][j]);
        }
        printf("\n");
    }
    
    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}
