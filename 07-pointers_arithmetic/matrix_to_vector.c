#include <assert.h>
#include <stdio.h>
#include <stdlib.h>


int main() {
	int rows = 5;
	int columns = 5;

	int matrix[rows][columns];

	int* vector;
	vector = (int*) malloc(sizeof(int) * (rows * columns));
	assert(vector != NULL);

	int i, j;

	for (i = 0; i < rows; i++) {
		for (j = 0; j < columns; j++) {
			int number = i * rows + j + 1;

			matrix[i][j] = number;
			vector[i * columns + j] = number;
		}
		printf("\n");
	}

	int* matrix_pointer = &matrix[0][0];

	for (i = 0; i < rows; i++) {
		for (j = 0; j < columns; j++)
			printf("%d ", *(matrix_pointer + i * columns + j));
		printf("\n");
	}

	/* The normal way to print a matrix
	for (i = 0; i < rows; i++) {
		for (j = 0; j < columns; j++)
			printf("%d ", matrix[i][j]);
		printf("\n");
	}
	*/

	printf("/* -------------------------------------------------------------------------- */\n");

	for (i = 0; i < rows; i++) {
		for (j = 0; j < columns; j++)
			printf("%d ", vector[i * columns + j]);
		printf("\n");
	}

	return 0;
}
