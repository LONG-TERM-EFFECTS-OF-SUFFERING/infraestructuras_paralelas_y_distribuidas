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

double vector_dot_product(const double* vector1, const double* vector2, int size) {
	int fixed_size = (size + 3) & ~3;

	__m256d temp = _mm256_setzero_pd();

	for (int i = 0; i < fixed_size; i += 4) {
		__m256d vector1_chunck = _mm256_loadu_pd(vector1 + i);
		__m256d vector2_chunck = _mm256_loadu_pd(vector2 + i);

		__m256d result = _mm256_mul_pd(vector1_chunck, vector2_chunck);

		// Add the previous products
		temp = _mm256_add_pd(temp, result);
	}

	double result[4];
	_mm256_storeu_pd(result, temp);

	return result[0] + result[1] + result[2] + result[3];
}


int main(int argc, char* argv[]) {
	int vector_size;
	double *vector1;
	double *vector2;
	double scalar = 2.0;

	if (argc == 1)
		vector_size = VECTOR_SIZE;
	else
		vector_size = atoi(argv[1]);

	vector1 = (double*) malloc(sizeof(double) * vector_size);
	assert(vector1 != NULL);

	vector2 = (double*) malloc(sizeof(double) * vector_size);
	assert(vector2 != NULL);

	for (int i = 0; i < vector_size; ++i) {
		vector1[i] = 1;
		vector2[i] = i + 1;
	}

	#ifdef DEBUG
		printf("Vector 1:\n");
		print_vector(vector1, vector_size);

		printf("Vector 2:\n");
		print_vector(vector2, vector_size);
	#endif

	printf("Dot product: %lf\n", vector_dot_product(vector1, vector2, vector_size));

	free(vector1);
	free(vector2);

	return 0;
}

// gcc -march=native dot_product_AVX.c -o main
