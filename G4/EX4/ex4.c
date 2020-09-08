#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, char **argv) {

	int fdIn, fdOut, temIn=0, temOut=0;


	if (argc >= 6) {

		fdIn = open(argv[2],O_RDONLY);
		fdOut = open(argv[4],O_CREAT | O_WRONLY, 0666); 

		dup2(fdIn,0); dup2(fdOut,1);

		temOut = 1; 
		temIn = 1;

	} else if (argc >= 4 && !strcmp("-i",argv[1])) {

		fdIn = open(argv[2],O_RDONLY);

		dup2(fdIn,0); 

		temIn = 1;

	} else if (argc >= 4 && !strcmp("-o",argv[1])) {

		fdOut = open(argv[2],O_CREAT | O_WRONLY, 0666); 

		dup2(fdOut,1);

		temOut = 1;

	} else {
		write(1,"Erro\n",6);
		return 0;
	}

	if (!fork()) {

		if (temIn && temOut) {
			
			execvp(argv[5],argv+5);
		
		} else {

			execvp(argv[3],argv+3);
		}

	}

	wait(NULL);

	return 0;
}