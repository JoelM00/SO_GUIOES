#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main() {

	int p[2];

	pipe(p); 

	if (!fork()) {

		close(p[1]); 

		char buffer[64]; 

		read(p[0],buffer,64);

		close(p[0]);

		write(1,buffer,strlen(buffer));

		_exit(0); 
	}

	close(p[0]); 

	char *str = "OLA MA FREND!";

	sleep(5);

	write(p[1],str,strlen(str)); 

	close(p[1]); 

	wait(NULL);

	return 0;
}