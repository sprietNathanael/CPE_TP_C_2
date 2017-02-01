CC=gcc
CFLAGS=-W -Wall -g
EXEC=sentenceCheker

all: $(EXEC)

automaton.o: automaton.c
	$(CC) -o automaton.o -c automaton.c $(CFLAGS)

file.o: file.c
	$(CC) -o file.o -c file.c $(CFLAGS)

sentenceCheker: main.o automaton.o file.o
	$(CC) -o sentenceCheker main.o automaton.o file.o

main.o: main.c automaton.h file.h
	$(CC) -o main.o -c main.c $(CFLAGS)

clean:
	rm -rf *.o *.h.gch

mrproper: clean
	rm -rf $(EXEC)
