#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h> 

#define MAX 64

int main() {

	mkfifo("./fifo",0666);

	int log = open("logs",O_CREAT | O_WRONLY,0666);

	int server = open("./fifo",O_RDONLY);

	char buffer;
	int n;

	while (1) {

		while (read(server,&buffer,1) > 0) {
			write(1,&buffer,1);
			write(log,&buffer,1);
		}

	}
	
	close(server); 


	return 0; 

}