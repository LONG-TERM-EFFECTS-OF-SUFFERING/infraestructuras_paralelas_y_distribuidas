#include <assert.h>
#include <stdio.h>
#include <stdlib.h>


int main() {
	int* pointer;

	printf("Address of \"pointer\" before initialization %p\n", pointer);
	pointer = (int*) malloc(sizeof(int));
	assert(pointer != NULL);
	printf("Address of \"pointer\" after initialization %p\n", pointer);

	free(pointer);

	return 0;
}
