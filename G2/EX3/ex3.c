#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int main() {

	int i, pid, status; 

	for (i=0; i<10; i++) {

		pid = fork(); 

		if (pid==0) {

			printf("Filho: %d de %d\n",getpid(),getppid());

			_exit(i+1); 
		}

		wait(&status); 

		printf("[%d] -> %d\n",pid,WEXITSTATUS(status));
	}

	return 0;

}