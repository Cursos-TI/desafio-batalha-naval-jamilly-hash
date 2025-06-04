#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Definições para o tamanho do tabuleiro e das matrizes de habilidade
#define TAM 10
#define TAM_HAB 5
#define MEIO_HAB (TAM_HAB / 2)

// Códigos para representar diferentes elementos no tabuleiro
#define AGUA 0
#define NAVIO 3
#define CRUZ 1
#define CONE 2
#define OCTAEDRO 4

// Função que sobrepõe uma matriz de habilidade ao tabuleiro
// "valor" indica o tipo de habilidade (CRUZ, CONE, OCTAEDRO)
void aplicarHabilidade(int tab[TAM][TAM], int habilidade[TAM_HAB][TAM_HAB], int origem_l, int origem_c, int valor) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            int tab_i = origem_l - MEIO_HAB + i;
            int tab_j = origem_c - MEIO_HAB + j;
            // Verifica se a posição está dentro dos limites do tabuleiro
            if (tab_i >= 0 && tab_i < TAM && tab_j >= 0 && tab_j < TAM) {
                // Apenas sobrepõe se a posição for água (não sobrescreve navios)
                if (habilidade[i][j] == 1 && tab[tab_i][tab_j] == AGUA) {
                    tab[tab_i][tab_j] = valor;
                }
            }
        }
    }
}

// Gera a matriz de habilidade em formato de cruz
// A cruz afeta a linha e a coluna centrais da matriz
void gerarMatrizCruz(int m[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            m[i][j] = (i == MEIO_HAB || j == MEIO_HAB) ? 1 : 0;
        }
    }
}

// Gera a matriz de habilidade em formato de cone (apontando para baixo)
// Começa com 1 célula no topo e expande até a base (formato piramidal)
void gerarMatrizCone(int m[TAM_HAB][TAM_HAB]) {
    // Inicializa tudo com 0
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            m[i][j] = 0;
        }
    }
    // Preenche o cone expandindo horizontalmente conforme desce
    for (int i = 0; i < MEIO_HAB + 1; i++) {
        for (int j = MEIO_HAB - i; j <= MEIO_HAB + i; j++) {
            m[i + MEIO_HAB][j] = 1;
        }
    }
}

// Gera a matriz de habilidade em formato de octaedro (losango)
// A condição abs(i - centro) + abs(j - centro) <= raio define esse formato
void gerarMatrizOctaedro(int m[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            m[i][j] = (abs(i - MEIO_HAB) + abs(j - MEIO_HAB) <= MEIO_HAB) ? 1 : 0;
        }
    }
}

int main() {
    int tabuleiro[TAM][TAM] = {0}; // Inicializa o tabuleiro com água

    // Posiciona manualmente três navios na diagonal principal
    tabuleiro[0][0] = NAVIO;
    tabuleiro[1][1] = NAVIO;
    tabuleiro[2][2] = NAVIO;
    tabuleiro[0][9] = NAVIO;
    tabuleiro[1][8] = NAVIO;
    tabuleiro[2][7] = NAVIO;

    // Matrizes das habilidades
    int cruz[TAM_HAB][TAM_HAB], cone[TAM_HAB][TAM_HAB], octaedro[TAM_HAB][TAM_HAB];
    gerarMatrizCruz(cruz);           // Preenche matriz da cruz com 1s e 0s
    gerarMatrizCone(cone);           // Preenche matriz do cone com 1s e 0s
    gerarMatrizOctaedro(octaedro);   // Preenche matriz do octaedro com 1s e 0s

    // Aplica as habilidades no tabuleiro em pontos fixos
    aplicarHabilidade(tabuleiro, cruz, 2, 4, CRUZ);         // Aplica cruz com centro em E3
    aplicarHabilidade(tabuleiro, cone, 7, 2, CONE);         // Aplica cone com base em C8
    aplicarHabilidade(tabuleiro, octaedro, 6, 7, OCTAEDRO); // Aplica octaedro centrado em H7

    // Exibe cabeçalho do tabuleiro com letras das colunas
    printf("      ");
    for (char letra = 'A'; letra < 'A' + TAM; letra++) {
        printf("%c ", letra);
    }
    printf("\n");

    // Exibe linhas numeradas e conteúdo das células
    for (int i = 0; i < TAM; i++) {
        printf("%-5d", i + 1);
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
