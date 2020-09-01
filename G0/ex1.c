#include "aux.h"

int main() {

	int numero, tamanho, x; 

	printf("Insira o numero: ");
	scanf("%d",&numero); 

	printf("Insira o tamanho: ");
	scanf("%d",&tamanho); 

	int *array = malloc(tamanho * sizeof(int));

	fill(array,tamanho,numero);

	printf("Insira o numero a procurar: ");
	scanf("%d",&x); 

	if (find(array,tamanho,x)) printf("Encontrado!\n");
	else printf("Nao Encontrado!\n");

	return 0; 

}
