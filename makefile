# Makefiler compila tudo de forma automatizada.
CC = gcc
CFLAGS = -Wall -std=c99
OBJS = main.o jogo.o

# Nome do executável
EXEC = jogo_da_velha

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJS)

main.o: main.c jogo.h
	$(CC) $(CFLAGS) -c main.c

jogo.o: jogo.c jogo.h
	$(CC) $(CFLAGS) -c jogo.c

clean:
	rm -f *.o $(EXEC)