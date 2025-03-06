// Pasta jogo.h arquivo de cabeçalho com as declarações das funções do projeto

#ifndef JOGO_H
#define JOGO_H

// Prepara o tabuleiro para o início do jogo, deixando tudo vazio                    
void inicializarTabuleiro(char tabuleiro[3][3]);

// Mostra o tabuleiro na tela
void exibirTabuleiro(char tabuleiro[3][3]);

// Marca a jogada do jogador no tabuleiro, se a posição estiver livre
int registrarJogada(char tabuleiro[3][3], int linha, int coluna, char jogador);

// Vê se o jogador ganhou o jogo
int verificarVencedor(char tabuleiro[3][3], char jogador);

// Vê se deu empate (tabuleiro cheio sem vencedor)
int verificarEmpate(char tabuleiro[3][3]);

#endif