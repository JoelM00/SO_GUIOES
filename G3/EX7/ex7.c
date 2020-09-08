#include "shell.h"

int main() {

	char buffer[MAX];
	int n;

	write(1,"bash$ ",6);

	while ((n = read(0,buffer,MAX)) > 0) {

		buffer[n-1] = '\0';

		if (!strcmp("exit",buffer)) return 0;  

		if (!shell(buffer,n-1)) 
			write(1,"bash$ ",6);

	}

	return 0;
}