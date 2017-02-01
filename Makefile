CC=gcc
CFLAGS=-W -Wall
EXEC=sentenceCheker

all: $(EXEC)

automaton.o: automaton.c
	$(CC) -o automaton.o -c automaton.c $(CFLAGS)

sentenceCheker: main.o automaton.o
	$(CC) -o sentenceCheker main.o automaton.o

main.o: main.c automaton.h
	$(CC) -o main.o -c main.c $(CFLAGS)

clean:
	rm -rf *.o *.h.gch

mrproper: clean
	rm -rf $(EXEC)
