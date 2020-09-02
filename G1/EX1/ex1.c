#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX 1024

int main(int argc, char *argv[]) {

	if (argc!=3) {
		write(1,"Erro",4);
		return 1; 
	}

	int fdIn = open(argv[1],O_RDONLY); 
	int fdOut = open(argv[2],O_CREAT | O_WRONLY,0666); 

	char buffer[MAX]; 
	int n; 

	while ((n = read(fdIn,buffer,MAX)) > 0) {

		write(fdOut,buffer,n); 

	}

	return 0; 
}