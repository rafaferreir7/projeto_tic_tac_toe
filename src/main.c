// Pasta main.c controla o fluxo principal do jogo.
#include <stdio.h>
#include "jogo.h"

int main() {
    char tabuleiro[3][3];    //Matriz do jogo
    int linha, coluna; 
    int vencedor = 0;
    int empate = 0;
    char jogadorAtual = 'X';

    inicializarTabuleiro(tabuleiro);

    // Loop principal do jogo (continua até ter um vencedor ou empate)
    while (!vencedor && !empate) {
        exibirTabuleiro(tabuleiro);

        // Solicita a jogada do jogador atual 
        printf("Jogador %c, insira a linha e coluna (0, 1 ou 2): ", jogadorAtual);
        scanf("%d %d", &linha, &coluna);

        // Valida e registra a jogada
        if (registrarJogada(tabuleiro, linha, coluna, jogadorAtual)) {
            // Verifica se houve vencedor ou empate depois da jogada
            vencedor = verificarVencedor(tabuleiro, jogadorAtual); 
            if (!vencedor) {
                empate = verificarEmpate(tabuleiro);
            }
            // Troca para o próximo jogador
            jogadorAtual = (jogadorAtual == 'X') ? 'O' : 'X';
        } else {
            printf("Jogada inválida, tente novamente!\n");
        }
    }

    exibirTabuleiro(tabuleiro);

    // Exibe o resultado
    if (vencedor) {
        printf("Jogador %c venceu!\n", (jogadorAtual == 'X') ? 'O' : 'X');
    } else {
        printf("Empate!\n");
    }

    return 0;
}