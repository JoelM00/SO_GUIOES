#include <unistd.h>
#include <sys/wait.h>

int main() {

	int p[2];

	pipe(p); 

	if (!fork()) {

		close(p[0]); 

		dup2(p[1],1); 

		close(p[1]); 

		execlp("ls","ls","/etc",NULL); 

		_exit(1); 
	}

	close(p[1]); 

	if (!fork()) {

		dup2(p[0],0); 

		close(p[0]); 

		execlp("wc","wc","-l",NULL);

		_exit(1);
	}

	close(p[0]); 

	wait(NULL);

	return 0;
}