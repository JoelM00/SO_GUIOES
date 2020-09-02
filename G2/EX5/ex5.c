#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int main() {

	int i, pid=0, status; 

	printf("Pai: %d\n",getpid());

	for (i=0; i<11; i++) {

		if (pid==0) {

			pid = fork(); 

		} else {

			waitpid(pid,&status,0); 

			printf("[%d] -----> %d\n",pid,WEXITSTATUS(status));

			_exit(i-1); 
		}
	}

	//Ultimo filho!
	_exit(i-1);
}