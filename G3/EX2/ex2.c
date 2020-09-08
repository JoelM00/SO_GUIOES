#include <unistd.h>

int main() {

	if (!fork()) {
		execl("/usr/bin/ls","ls","-l",NULL);
	}

	return 0;
}