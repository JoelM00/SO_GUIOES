#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int main() {

	int i, pid, status; 

	for(i=0; i<10; i++) {

		pid = fork();

		if (pid==0) {

			for(int j=0; j<100; j++);

			printf("[%d] -> %d\n",getpid(),i+1);

			_exit(i+1);
		}
	}	

	for (i=0; i<10; i++) {

		pid = wait(&status);

		printf("[%d] ----> %d done\n",pid,WEXITSTATUS(status));

	}

	return 0;

}