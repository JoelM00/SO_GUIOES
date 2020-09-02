#include "matriz.h"

int **initMatriz() {

	int i;

	int **mat = malloc(LINHAS*sizeof(int*));

	for (i=0; i<COLUNAS; i++)
		mat[i] = malloc(COLUNAS*sizeof(int));

	return mat;
}

int **criaMatriz() {

	int i,j; 

	int **mat = initMatriz();

	for (i=0; i<LINHAS; i++) {
		for (j=0; j<COLUNAS; j++) {
			mat[i][j] = RANDMIN + (rand() % RANDMAX);
		}
	}

	return mat;
}

/*
void freeMatriz(int **mat) {

	for (int i=0; i<LINHAS; i++) 
		free(mat[i]);
}
*/