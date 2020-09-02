 
#ifndef MATRIZ_H
#define MATRIZ_H

#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "procurador.h"

#define LINHAS 50
#define COLUNAS 10000


#define RANDMIN 0
#define RANDMAX 1000

int **initMatriz();

int **criaMatriz();

#endif