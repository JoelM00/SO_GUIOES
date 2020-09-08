#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main() {

	int fdIn = open("/etc/passwd",O_RDONLY);

	int fdOut = open("saida.txt",O_CREAT | O_WRONLY,0666);

	int fdError = open("erros.txt",O_CREAT | O_WRONLY,0666); 

	char buffer[1024]; 
	int n;	

	dup2(fdIn,0);
	dup2(fdError,2);
	dup2(fdOut,1);

	if (!fork()) {
	
		execlp("wc","wc",NULL);
			
		_exit(1);
	}

	return 0;

}