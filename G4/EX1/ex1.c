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

	while ((n = read(fdIn,buffer,1024)) > 0) {
		write(fdOut,buffer,n);
		write(fdError,buffer,n);
	}

	return 0;

}