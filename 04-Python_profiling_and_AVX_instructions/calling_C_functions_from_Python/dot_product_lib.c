#include <immintrin.h>


double vector_dot_product(const double* vector1, const double* vector2, int size) {
	int fixed_size = (size + 3) & ~3;

	__m256d temp = _mm256_setzero_pd();

	for (int i = 0; i < fixed_size; i += 4) {
		__m256d vector1_chunk = _mm256_loadu_pd(vector1 + i);
		__m256d vector2_chunk = _mm256_loadu_pd(vector2 + i);

		__m256d result = _mm256_mul_pd(vector1_chunk, vector2_chunk);

		// Add the previous products
		temp = _mm256_add_pd(temp, result);
	}

	double result[4];
	_mm256_storeu_pd(result, temp);

	return result[0] + result[1] + result[2] + result[3];
}
