#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>


#define MAX 64

int main(int argc, char **argv) {

	if (!fork()) 
		execv("./prog",argv);

	wait(NULL);
	return 0;

}