#include <unistd.h>
#include <sys/wait.h>

#define COMANDOS 4

int main() {

	int p[COMANDOS-1][2]; 

	char *cm1[5]  = {"grep","-v","^#","/etc/passwd",NULL};
	char *cm2[5]  = {"cut","-f7","-d:",NULL};
	char *cm3[5]  = {"uniq",NULL};
	char *cm4[5]  = {"wc","-l",NULL};

	char **argum[5] = {cm1,cm2,cm3,cm4};
	int i; 

	int ecra = dup(1);

	for (i=0; i<COMANDOS-1; i++) pipe(p[i]);

	for (i=0; i<COMANDOS; i++) {

		if (!fork()) {

			if (i==0) {

				dup2(p[i][1],1);

			} else if (i==COMANDOS-1) {

				dup2(p[i-1][0],0);

			} else {

				dup2(p[i-1][0],0);
				
				dup2(p[i][1],1);
			}

			for (int j=0; j<COMANDOS-1; j++) {
				close(p[j][0]);
				close(p[j][1]);
			}

			execvp(argum[i][0],argum[i]);
		}
	}

	for (int j=0; j<COMANDOS-1; j++) {
		close(p[j][0]);
		close(p[j][1]);
	}

	while (wait(NULL)!=-1);

	return 0;
}