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

	int server = open("./fifo",O_RDONLY);
	int n; 

	char buffer;

	while (read(server,&buffer,1) > 0) 
		write(1,&buffer,1);

	close(server); 
	return 0; 
}