#include <unistd.h>
#include <sys/wait.h>

#define MAX 64

int main() {

	int p[2], n;

	char buffer[MAX];

	pipe(p);

	if (!fork()) {

		close(p[1]);

		dup2(p[0],0);

		execlp("wc","wc",NULL); 

		_exit(0);

	}

	close(p[0]); 

	while ((n = read(0,buffer,MAX)) > 0) {
		write(p[1],buffer,n);
	}

	sleep(5); 

	close(p[1]);

	wait(NULL);

	return 0;
}