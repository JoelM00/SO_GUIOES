# Compiler
CC=gcc

# Flags for compiler
CC_FLAGS = -Wall -ansi

# Compilation and linking

prog: ex6.o matriz.o procurador.o
	$(CC) $(CFLAGS) ex6.o matriz.o procurador.o -o prog

ex6.o: ex6.c 
	$(CC) $(CFLAGS) -c ex6.c

procurador.o: procurador.c procurador.h
	$(CC) $(CFLAGS) -c procurador.c

matriz.o: matriz.c matriz.h
	$(CC) $(CFLAGS) -c matriz.c

clean: 
	rm *.o