#include <stdio.h>
#include "jogo.h"

int main() {
    char tabuleiro[3][3]; // Criação do tabuleiro 3x3
    int jogador = 1, linha, coluna, movimentos = 0;
    
    inicializarTabuleiro(tabuleiro); // Inicia o tabuleiro vazio
    
    while (movimentos < 9) { // O jogo pode ter no máximo 9 rodadas antes de um empate
        exibirTabuleiro(tabuleiro); // Exibe o estado atual do jogo
        printf("Jogador %d, informe linha e coluna (0-2): ", jogador);
        scanf("%d %d", &linha, &coluna); // Lê a jogada do jogador

        if (movimentoValido(tabuleiro, linha, coluna)) { // Verifica se a jogada é válida
            fazerMovimento(tabuleiro, jogador, linha, coluna); // Registra a jogada no tabuleiro
            movimentos++; // Contabiliza um novo movimento

            if (verificarVitoria(tabuleiro)) { // Verifica se houve um vencedor
                exibirTabuleiro(tabuleiro);
                printf("Jogador %d venceu!\n", jogador);
                return 0; // Encerra o jogo
            }

            jogador = (jogador == 1) ? 2 : 1; // Alterna entre jogador 1 e jogador 2
        } else {
            printf("Movimento inválido, tente novamente.\n");
        }
    }

    exibirTabuleiro(tabuleiro);
    printf("Empate!\n"); // Se todos os espaços forem preenchidos e ninguém vencer, há empate
    return 0;
}
