#include "matriz.h"
#include "procurador.h"

int main() {

	int **matriz = criaMatriz();

	int i,j,x;

	for (i=0; i<LINHAS; i++) {
		for (j=0; j<COLUNAS; j++) {
			printf("%d ",matriz[i][j]);
		}
		printf("\n");
	} 

	printf("Insira o numero: ");
	scanf("%d",&x);

	procura(matriz,x);

	return 0;
}