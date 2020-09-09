#include "shell.h"

int shell(char *str,int n) {
	
	int status, i = 0, j, ncomandos = 0;
	char *cmd, *args[MAX][MAX];

	char *token = strtok(str, " ");

	if (!token) return 0;

	cmd = token;

	if(!strcmp("exit", cmd)) return 0;

	while(token) {

		if (!strcmp("|", token)) {
			args[ncomandos][i] = NULL;
			i = 0;
			ncomandos++;
		} else {

			args[ncomandos][i++] = token;

		}

		token = strtok(NULL, " ");
	}

	args[ncomandos++][i] = NULL;

	int fds[ncomandos-1][2];
	
	// Iniciar os pipes necessários.
	for(i = 0; i < ncomandos - 1; i++)
		pipe(fds[i]);
	
	// Criar um processo filho para cada comando a executar.
	for(i = 0; i < ncomandos; i++) {
		
		if (fork() == 0) {
			
			// Configurar os inputs/outputs de cada processo
			if (i == 0) {
				// Primeiro processo.
				dup2(fds[i][1], 1);
			
			} else if (i == ncomandos - 1) {
				//  Último processo.
				dup2(fds[i-1][0], 0);
			
			} else {
				// Processos intermédios.
				dup2(fds[i-1][0], 0);  
				dup2(fds[i][1], 1);
				
			}
			// Fechar em cada processo os pipes.
			for(j = 0; j < ncomandos - 1; j++) {
				close(fds[j][0]);
				close(fds[j][1]);
			}
			
			// Executar o comando.
			execvp(args[i][0], args[i]);	
		}
	}
	// Processo pai.
	// Fechar os pipes.
	for(j = 0; j < ncomandos - 1; j++) {
		close(fds[j][0]);
		close(fds[j][1]);
	}
	// Esperar por todos os filhos.
	while(wait(NULL) != -1);

	return n;
}