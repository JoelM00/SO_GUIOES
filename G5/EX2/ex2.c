#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/wait.h>

#define MAX 1024

int main() {

	int p[2]; 
	char buffer[MAX];  
	int n;

	pipe(p); 

	if (!fork()) {

		close(p[1]);

		int ecra = dup(1);
		int fdOut = open("saida.txt",O_CREAT | O_WRONLY,0666);

		while ((n = read(p[0],buffer,MAX)) > 0) {

			write(fdOut,buffer,n);
		}

		write(ecra,"PAROU\n",7);

		close(p[0]); 

		_exit(0);
	}

	close(p[0]); 

	int fd = open("/etc/passwd",O_RDONLY);

	dup2(fd,0);

	while ((n = read(0,buffer,MAX)) > 0) {
		write(p[1],buffer,n); 
	}

	sleep(5);

	write(1,"EOF -> ENVIADO\n",16);

	close(p[1]);

	wait(NULL);

	return 0;

}