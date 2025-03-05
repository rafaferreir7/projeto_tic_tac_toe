// Pasta jogo.c contém as funções para manipular o tabuleiro e verificar vitórias
#include <stdio.h>
#include "jogo.h"

// Função para inicializar o tabuleiro com espaços vazios
void inicializarTabuleiro(char tabuleiro[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            tabuleiro[i][j] = ' ';  // Espaço vazio
        }
    }
}

// Função para exibir o tabuleiro atual
void exibirTabuleiro(char tabuleiro[3][3]) {
    printf("\nTabuleiro atual:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", tabuleiro[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");
        if (i < 2) printf("-----------\n");
    }
    printf("\n");
}

// Função para registrar a jogada do jogador (X ou O)
int registrarJogada(char tabuleiro[3][3], int linha, int coluna, char jogador) {
    // Verifica se a posição é válida e está vazia
    if (linha >= 0 && linha < 3 && coluna >= 0 && coluna < 3 && tabuleiro[linha][coluna] == ' ') {
        tabuleiro[linha][coluna] = jogador;
        return 1;  // Jogada válida
    }
    return 0;  // Jogada inválida
}

// Função para verificar se alguém ganhou
int verificarVencedor(char tabuleiro[3][3], char jogador) {
    // Verifica linhas colunas e diagonais
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2] && tabuleiro[i][0] != ' ')
            return 1;  // Linha vencedora
        if (tabuleiro[0][i] == tabuleiro[1][i] && tabuleiro[1][i] == tabuleiro[2][i] && tabuleiro[0][i] != ' ')
            return 1;  // Coluna vencedora
    }

    // Verifica diagonais
    if (tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2] && tabuleiro[0][0] != ' ')
        return 1;  // Diagonal principal
    if (tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0] && tabuleiro[0][2] != ' ')
        return 1;  // Diagonal secundária

    return 0;  // Não tem vencedor
}

// Função para verificar se houve empate
int verificarEmpate(char tabuleiro[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (tabuleiro[i][j] == ' ') {
                return 0;  // Se ainda tiver espaço vazio o jogo não terminou
            }
        }
    }
    return 1;  // Empate
}