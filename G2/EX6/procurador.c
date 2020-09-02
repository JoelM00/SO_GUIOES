#include "procurador.h"

int procura(int **matriz, int x) {

	int pid, i, j, status; 

	for (i=0; i<LINHAS; i++) {

		pid = fork();

		if (pid==0) {

			printf("[%d] -> %d\n",getpid(),i);

			for(j=0; j<COLUNAS; j++) {

				if (matriz[i][j]==x) {

					_exit(1);
				}
			}
			_exit(0);
		}
	}

	for (i=0; i<LINHAS; i++) {

		pid = wait(&status);

		printf("[%d] ------> %d\n",pid,WEXITSTATUS(status));

	}

	return 0; 
}