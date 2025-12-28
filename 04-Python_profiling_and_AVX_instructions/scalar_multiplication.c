#include <stdio.h>
#include <assert.h>


#define VECTOR_SIZE 4
// #define DEBUG


void print_vector(double* vector, int size) {
	for (int i = 0; i < size; ++i)
		printf("%lf ", vector[i]);

	printf("\n");
}

void vector_scalar_multiplication(double* vector, double scalar, int size) {
	for (int i = 0; i < size; i++)
		vector[i] = vector[i] * scalar;
}


int main(int argc, char* argv[]) {
	int vector_size;
	double *vector;
	double scalar = 2.0;

	if (argc == 1)
		vector_size = VECTOR_SIZE;
	else
		vector_size = atoi(argv[1]);

	vector = (double*) malloc(sizeof(double) * vector_size);
	assert(vector != NULL);


	for (int i = 0; i < vector_size; ++i)
		vector[i] = i + 1;

	#ifdef DEBUG
		printf("Original vector:\n");
		print_vector(vector, vector_size);
	#endif

	vector_scalar_multiplication(vector, scalar, vector_size);

	#ifdef DEBUG
		printf("Result:\n");
		print_vector(vector, vector_size);
	#endif

	free(vector);

	return 0;
}
