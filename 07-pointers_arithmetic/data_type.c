#include <assert.h>
#include <stdio.h>
#include <stdlib.h>


int main() {
	int size = 3;
	int* int_pointer;
	double* double_pointer;
	float* float_pointer;
	char* char_pointer;

	int_pointer = (int*) malloc(sizeof(int) * size);
	double_pointer = (double*) malloc(sizeof(double) * size);
	float_pointer = (float*) malloc(sizeof(float) * size);
	char_pointer = (char*) malloc(sizeof(char) * size);

	assert(int_pointer != NULL && double_pointer != NULL && char_pointer != NULL);

	for (int i = 0; i < size; i++) {
		int_pointer[i] = i + 1;
		double_pointer[i] = (i + 1) * 2.0;
		float_pointer[i] = (i + 1) * 3.0;
		char_pointer[i] = i + 'a';
	}

	for (int i = 0; i < 3; i++) {
		printf("&int_pointer[%d] = %p \t int_pointer[%d] = %d\n", i, (void*) &int_pointer[i], i, int_pointer[i]);
		printf("&double_pointer[%d] = %p \t double_pointer[%d] = %lf\n", i, (void*) &double_pointer[i], i, double_pointer[i]);
		printf("&float_pointer[%d] = %p \t float_pointer[%d] = %f\n", i, (void*) &float_pointer[i], i, float_pointer[i]);
		printf("&char_pointer[%d] = %p \t char_pointer[%d] = %c\n", i, (void*) &char_pointer[i], i, char_pointer[i]);
	}

	return 0;
}
