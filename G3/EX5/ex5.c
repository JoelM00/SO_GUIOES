#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>

int main(int argc, char **argv) {

	int i;

	for (i=1; i<argc; i++) {

		if (!fork()) {

			execlp(argv[i],argv[i],NULL);

			_exit(0);

		}
	}

	while (wait(NULL)!=-1);

	return 0;
}