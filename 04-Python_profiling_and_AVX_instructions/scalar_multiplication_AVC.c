#include <assert.h>
#include <immintrin.h>
#include <stdio.h>


#define VECTOR_SIZE 4
// #define DEBUG


void print_vector(double* vector, int size) {
	for (int i = 0; i < size; ++i)
		printf("%lf ", vector[i]);

	printf("\n");
}

void vector_scalar_multiplication(double* vector, double scalar, int size) {
	// Ensure the length is a multiple of 4 for proper alignment
	int fixed_size = (size + 3) & ~3; // size + (4 - size % 4)

	// Loop through the vector in 4-element chunks because AVX instructions
	// operate on 256 bits of data at once, which corresponds to a 4
	// double-precision floating-point numbers
	for (int i = 0; i < fixed_size; i += 4) {
		// Load the vector chunk into AVX register
		__m256d vector1 = _mm256_loadu_pd(vector + i);

		// Broadcast the scalar value to all elements of another AVX register
		__m256d vector2 = _mm256_broadcast_sd(&scalar);

		// Perform element-wise multiplication
		__m256d result = _mm256_mul_pd(vector1, vector2);

		// Store the result back to memory
		_mm256_storeu_pd(vector + i, result);
	}
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

// gcc -march=native scalar_multiplication_AVC.c -o main
