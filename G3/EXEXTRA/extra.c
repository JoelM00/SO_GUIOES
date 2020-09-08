#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char **argv) {

	if (argc!=4) {
		write(1,"Error\n",7);
		return 0;
	}

	int i, pid, status; 

	for (i=0; i<argc-1; i++) {

		pid = fork();

		if (pid==0) {

			int cont=0;

			while (1) {

				pid = fork();

				if (pid==0) {

					execl(argv[i+1],argv[i+1],NULL);

					_exit(-1);
				}

				waitpid(pid,&status,0);

				if (WEXITSTATUS(status)==0) break;

				cont++;
			}

			printf("%s -> %d\n",argv[i+1],cont);

			exit(0);

		}
	}

	for (i=0; i<argc-1; i++) 
		wait(NULL);

	return 0;
}