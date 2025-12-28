#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define SIZE 10000

int** matrix;


int main(int argc, char* argv[]) {
	clock_t start, end;
	double cpu_time;
	int sum = 0, i, j;
	matrix = (int**) malloc(sizeof(int*) * SIZE);

	assert(matrix != NULL);

	for (i = 0; i < SIZE; i++) {
		matrix[i] = (int*) malloc(sizeof(int) * SIZE);
		assert(matrix[i] != NULL);
	}

	for (i = 0; i < SIZE; i++)
		for (j = 0; j < SIZE; j++)
			matrix[i][j] = i + j;

	start = clock();

	for (i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
			sum += matrix[i][j];

	end = clock();

	cpu_time = ((double) (end - start)) / CLOCKS_PER_SEC;

	printf("CPU time: %.6f secs.\n", cpu_time);

	for (i = 0; i < SIZE; i++)
		free(matrix[i]);

	free(matrix);

	return 0;
}
