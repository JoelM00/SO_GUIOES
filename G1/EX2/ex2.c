#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX 1024

int main(int argc,char *argv[]) {

	int fd = open(argv[1],O_RDONLY); 

	char buffer[MAX];
	int n;

	while ((n = read(fd,buffer,MAX)) > 0) {

		write(1,buffer,n);

	}

	return 0; 
}