#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define MAX_DIM 10000

int* matrix;


int main(int argc, char* argv[]) {
	clock_t start, end;
	double cpu_time;
	long int sum = 0; int i, j;
	matrix = (int*) malloc(sizeof(int) * MAX_DIM * MAX_DIM);

	assert(matrix != NULL);

	for (i = 0; i < MAX_DIM; i++)
		for (j = 0; j < MAX_DIM; j++)
			matrix[i * MAX_DIM + j] = i + j;

	start = clock();

	// for (i = 0; i < MAX_DIM; i++)
	// 	for (int j = 0; j < MAX_DIM; j++)
	// 		sum += matrix[i * MAX_DIM + j];

	for (i = 0; i < MAX_DIM * MAX_DIM; i++)
		sum += matrix[i];

	end = clock();

	cpu_time = ((double) (end - start)) / CLOCKS_PER_SEC;

	printf("CPU time: %.6f secs.\n", cpu_time);

	free(matrix);

	return 0;
}