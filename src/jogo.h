// Pasta jogo.h arquivo de cabeçalho com as declarações das funções do projeto

#ifndef JOGO_H
#define JOGO_H

// Inicializa o tabuleiro                       
void inicializarTabuleiro(char tabuleiro[3][3]);

// Exibe o tabuleiro
void exibirTabuleiro(char tabuleiro[3][3]);

// Registra uma jogada
int registrarJogada(char tabuleiro[3][3], int linha, int coluna, char jogador);

// Verifica se tem um vencedor
int verificarVencedor(char tabuleiro[3][3], char jogador);  // Agora recebe o jogador

// Verificar empate
int verificarEmpate(char tabuleiro[3][3]);

#endif