#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main() {
	int* pointer;

	printf("Address of \"pointer\" before initialization %p\n", pointer);

	pointer = (int*) malloc(sizeof(int));
	assert(pointer != NULL);

	printf("Address of \"pointer\" after initialization %p\n", pointer);

	int pid = fork();
	assert(pid >= 0);

	if (pid == 0) {
		printf("Address of \"pointer\" after initialization %p\n", pointer);
		*pointer = 10;
	} else {
		printf("Address of \"pointer\" after initialization %p\n", pointer);
		*pointer = 20;
	}

	printf("*pointer = %d\n", *pointer);

	free(pointer);

	return 0;
}
