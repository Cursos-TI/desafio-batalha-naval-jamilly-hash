#include <stdio.h>

// Constantes para tamanho do tabuleiro e valores 
#define TAM 10
#define VALOR_AGUA 0
#define VALOR_NAVIO 3
#define TAM_NAVIO 3

int main() {
    // Declara e inicializa o tabuleiro 10x10 com água (valor 0)
    int tabuleiro[TAM][TAM] = {0};

    // Verificar se uma posição está livre (sem navio)
    #define POSICAO_LIVRE(i, j) (tabuleiro[i][j] == VALOR_AGUA)

    int pode_posicionar = 1; // Variável auxiliar para verificar se é possível posicionar um navio


    // 1. Posiciona navio horizontal (E2, F2, G2)
    int linhaH = 1;        // Linha 2 (indice 1)
    int colunaH = 4;       // Coluna E (indice 4)
    pode_posicionar = 1;
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (!POSICAO_LIVRE(linhaH, colunaH + i)) pode_posicionar = 0;
    }
    if (pode_posicionar && colunaH + TAM_NAVIO <= TAM) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            tabuleiro[linhaH][colunaH + i] = VALOR_NAVIO;
        }
    }

    
    // 2. Posiciona navio vertical (B5, B6, B7)
    int linhaV = 4;        // Linha 5 (indice 4)
    int colunaV = 1;       // Coluna B (indice 1)
    pode_posicionar = 1;
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (!POSICAO_LIVRE(linhaV + i, colunaV)) pode_posicionar = 0;
    }
    if (pode_posicionar && linhaV + TAM_NAVIO <= TAM) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            tabuleiro[linhaV + i][colunaV] = VALOR_NAVIO;
        }
    }

    
    // 3. Posiciona navio diagonal principal (0,0), (1,1), (2,2)
    pode_posicionar = 1;
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (!POSICAO_LIVRE(i, i)) pode_posicionar = 0;
    }
    if (pode_posicionar) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            tabuleiro[i][i] = VALOR_NAVIO;
        }
    }

    
    // 4. Posiciona navio diagonal secundária (0,9), (1,8), (2,7)
    pode_posicionar = 1;
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (!POSICAO_LIVRE(i, 9 - i)) pode_posicionar = 0;
    }
    if (pode_posicionar) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            tabuleiro[i][9 - i] = VALOR_NAVIO;
        }
    }

    
    // Exibição do tabuleiro 
    printf("TABULEIRO BATALHA NAVAL\n");

    // Impressão das letras das colunas (A a J)
    printf("    "); // Espaço inicial para alinhar com as linhas
    for (char letra = 'A'; letra < 'A' + TAM; letra++) {
        printf(" %c", letra);
    }
    printf("\n");

    // Impressão de cada linha numerada (1 a 10)
    for (int i = 0; i < TAM; i++) {
        printf("%2d  ", i + 1); // Número da linha
        for (int j = 0; j < TAM; j++) {
            printf(" %d", tabuleiro[i][j]); // Valor da célula: 0 (agua) ou 3 (navio)
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
