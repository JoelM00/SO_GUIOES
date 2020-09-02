#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int main() {

	printf("PID: %d -> %d\n",getpid(),getppid());

	return 0;

}