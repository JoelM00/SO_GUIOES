#include "aux.h"

int fill(int *vetor, int size, int value) {

	int i; 

	for (i=0; i<size; i++) {

		vetor[i] = value; 
	}

	return 0; 
}

int find(int *vetor, int size, int value) {

	int i; 

	for (i=0; i<size; i++) {

		if (vetor[i]==value) return 1;
	}

	return 0; 
}