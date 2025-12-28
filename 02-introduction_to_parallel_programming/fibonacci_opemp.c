#include <assert.h>
#include <malloc.h>
#include <omp.h>
#include <stdio.h>


int vector_size = 10000;
int min_fibonacci = 2;
int max_fibonacci = 32;
int *vector;
int threads = 4;


void initialize_vector() {
	vector = (int*) malloc(sizeof(int) * vector_size);

	assert(vector != NULL);

	int i;

	#pragma omp parallel for private(i) num_threads(threads)
	for (i = 0; i < vector_size; i++)
		vector[i] = i % max_fibonacci + min_fibonacci;
}

int fibonacci(int n) {
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else
		return fibonacci(n - 1) + fibonacci(n - 2);
}

void work(void) {
	printf("Processing from 0 to %d\n",vector_size);

	for (int i = 0; i < vector_size; i++)
		vector[i] = fibonacci(vector[i]);
}


int main(int argc, char* argv[]) {
	if (argc == 2)
		threads = atoi(argv[1]);

	initialize_vector();
	work();

	return 0;
}

// gcc -fopenmp fibonacci_opemp.c -o main
