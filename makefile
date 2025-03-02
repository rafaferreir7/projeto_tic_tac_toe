# Nome do executável
EXEC = tic_tac_toe

# Diretórios
SRC_DIR = src
OUTPUT_DIR = output

# Compilador
CC = gcc

# Flags de compilação (opcional)
CFLAGS = -Wall -Wextra -std=c11

# Arquivos-fonte
SRCS = $(SRC_DIR)/main.c $(SRC_DIR)/jogo.c

# Arquivo de saída
OUTPUT = $(OUTPUT_DIR)/$(EXEC).exe

# Regra padrão (compila o jogo)
all: $(OUTPUT)

$(OUTPUT): $(SRCS)
	@mkdir -p $(OUTPUT_DIR) # Cria a pasta output se não existir
	$(CC) $(CFLAGS) $(SRCS) -o $(OUTPUT)
	@echo "Compilação concluída! Execute com 'make run'."

# Regra para executar o jogo
run: all
	$(OUTPUT)

# Regra para limpar os arquivos compilados
clean:
	rm -rf $(OUTPUT)
	@echo "Arquivos removidos."
