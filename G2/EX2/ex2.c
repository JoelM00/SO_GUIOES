#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int main() {

	int pid = fork(); 

	if (pid==0) {

		for (int i=0; i<1000000000;i++);

		printf("Filho: %d de %d\n",getpid(),getppid());

		_exit(0); 
	}

	printf("Pai: %d de %d\n",getpid(),pid);

	//wait(NULL);

	return 0; 
}