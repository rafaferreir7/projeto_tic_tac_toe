# Makefiler compila tudo do jogo de forma automatizada. 
CC = gcc
CFLAGS = -Wall -std=c99
OBJS = src/main.o src/jogo.o

# Nome do executável
EXEC = src/output/jogo_da_velha

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJS)

src/main.o: src/main.c src/jogo.h
	$(CC) $(CFLAGS) -c src/main.c -o src/main.o

src/jogo.o: src/jogo.c src/jogo.h
	$(CC) $(CFLAGS) -c src/jogo.c -o src/jogo.o

clean:
	rm -f src/*.o $(EXEC)