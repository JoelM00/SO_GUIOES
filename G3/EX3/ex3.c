#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]) {

	int i; 

	for (i=0; i<argc; i++) {
		write(1,argv[i],strlen(argv[i]));
	}

	return 0; 

}