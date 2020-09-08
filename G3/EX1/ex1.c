#include <unistd.h>

int main() {

	execl("/usr/bin/ls","ls","-l",NULL);

	return 0;
}