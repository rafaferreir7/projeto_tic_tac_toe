#ifndef JOGO_H  // Evita inclusão múltipla do mesmo cabeçalho
#define JOGO_H

// Função para inicializar o tabuleiro com espaços vazios
void inicializarTabuleiro(char tabuleiro[3][3]);

// Função para exibir o tabuleiro no console
void exibirTabuleiro(char tabuleiro[3][3]);

// Função para verificar se há um vencedor
int verificarVitoria(char tabuleiro[3][3]);

// Função para verificar se um movimento é válido
int movimentoValido(char tabuleiro[3][3], int linha, int coluna);

// Função para realizar o movimento do jogador no tabuleiro
void fazerMovimento(char tabuleiro[3][3], int jogador, int linha, int coluna);

#endif // JOGO_H