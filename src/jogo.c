#include <stdio.h>
#include "jogo.h"

// Inicializa o tabuleiro preenchendo todos os espaços com ' '
void inicializarTabuleiro(char tabuleiro[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            tabuleiro[i][j] = ' '; // Espaço vazio
        }
    }
}

// Exibe o tabuleiro formatado na tela
void exibirTabuleiro(char tabuleiro[3][3]) {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", tabuleiro[i][j]); // Mostra X, O ou espaço vazio
            if (j < 2) printf("|"); // Adiciona separação vertical
        }
        printf("\n");
        if (i < 2) printf("---|---|---\n"); // Adiciona separação horizontal
    }
    printf("\n");
}

// Verifica se um movimento é válido (se a posição está dentro do tabuleiro e vazia)
int movimentoValido(char tabuleiro[3][3], int linha, int coluna) {
    return (linha >= 0 && linha < 3 && coluna >= 0 && coluna < 3 && tabuleiro[linha][coluna] == ' ');
}

// Registra a jogada no tabuleiro (coloca 'X' ou 'O' na posição escolhida)
void fazerMovimento(char tabuleiro[3][3], int jogador, int linha, int coluna) {
    tabuleiro[linha][coluna] = (jogador == 1) ? 'X' : 'O'; // Jogador 1 usa 'X', Jogador 2 usa 'O'
}

// Verifica se há um vencedor verificando linhas, colunas e diagonais
int verificarVitoria(char tabuleiro[3][3]) {
    for (int i = 0; i < 3; i++) {
        // Verifica linhas e colunas
        if (tabuleiro[i][0] != ' ' && tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2]) return 1;
        if (tabuleiro[0][i] != ' ' && tabuleiro[0][i] == tabuleiro[1][i] && tabuleiro[1][i] == tabuleiro[2][i]) return 1;
    }
    // Verifica diagonais
    if (tabuleiro[0][0] != ' ' && tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2]) return 1;
    if (tabuleiro[0][2] != ' ' && tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0]) return 1;
    return 0; // Retorna 0 se ninguém ganhou
}