#include <stdio.h>


int size = 825;
int rows = 1;
int columns = 2;


int main(int argc, char* argv[]) {
	int a[size][size], b[size][size], c[size][size];
	int i, j;
	int option;

	if (argc == 1) {
		printf("Routing by rows");
		option = rows;
	} else {
		printf("routing by columns");
		option = columns;
	}

	printf("(int = %lu bytes)\n", sizeof(int));

	// Initialization of the matrices
	for (i = 0; i < size; i++)
		for (j = 0 ; j < size; j++)
			if (option == rows) {
				a[i][j] = 314;
				b[i][j] = 186;
			} else {
				a[j][i] = 314;
				b[j][i] = 186;
			}

	// Adding the matrices
	for (i = 0; i < size; i++)
		for (j = 0 ; j < size; j++)
			if (option == rows)
				c[i][j] = a[i][j] + b[i][j];
			else
				c[j][i] = a[j][i] + b[j][i];

	return 0;
}

// valgrind --tool=cachegrind <executable>
