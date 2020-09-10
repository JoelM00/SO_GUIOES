#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h> 

#define MAX 1024

int main() {

	int fd = open("/etc/passwd",O_RDONLY); 

	int server = open("./fifo",O_WRONLY);

	int n; 

	dup2(fd,0);

	char buffer[MAX];

	while ((n = read(0,buffer,MAX)) > 0) {
		write(server,buffer,n);
	}

	close(fd);
	close(server);
	return 0;

}