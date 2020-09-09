#include "shell.h"

int main() {

	char buffer[MAX];
	int n;

	do {

		write(1,"$> ",3);

		n = read(0,buffer,MAX);

		buffer[n-1] = '\0';

		n = shell(buffer,n);

	} while (n>0);

	return 0;
}