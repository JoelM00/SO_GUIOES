#include "shell.h"

int shell(char *str,int n) {

	char *token = strtok(str," ");
	char *argm[10];
	int cont = 0;

	while (token!=NULL) {

		argm[cont++] = token;

		token = strtok(NULL," ");
	}

	argm[cont] = NULL;

	if (!fork()) {
		execvp(argm[0],argm);
	}

	wait(NULL);

	return 0;
}