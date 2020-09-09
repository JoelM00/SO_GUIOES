# Compiler
CC=gcc

# Flags for compiler
CC_FLAGS = -Wall -ansi

# Compilation and linking

prog: ex7.o shell.o 
	$(CC) $(CFLAGS) ex7.o shell.o -o prog

ex7.o: ex7.c 
	$(CC) $(CFLAGS) -c ex7.c
	
shell.o: shell.c shell.h
	$(CC) $(CFLAGS) -c shell.c

clean: 
	rm *.o