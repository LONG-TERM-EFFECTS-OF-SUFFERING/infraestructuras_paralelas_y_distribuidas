#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int max_size = 512 * 1024 * 1024; //  2^9 * 2^(10) * 2^(10) = 2^(29) bits = 65536 Kibi = 512 Mebi


int main(int argc, char* argv[]) {
	clock_t start, end;
	double cpu_time;
	int i, j, k;

	int *vector = (int*) malloc(max_size * sizeof(int));

	assert(vector != NULL);

	// printf("Loop 1\n");
	// for (k = 0; k < 3; k++) {
	// 	start = clock();

	// 	for (i = 0; i < max_size; i++)
	// 		vector[i] += 3;

	// 	end = clock();

	// 	cpu_time = ((double) (end - start)) / CLOCKS_PER_SEC;

	// 	printf("\tCPU time %.6f secs.\n", cpu_time);
	// }

	// printf("Loop 2\n");
	// for (j = 1; j <= 1024; j <<= 1) { // 11 times
	// 	start = clock();

	// 	for (i = 0; i < max_size; i += j)
	// 		vector[i] += 3;

	// 	end = clock();

	// 	cpu_time = ((double) (end - start)) / CLOCKS_PER_SEC;
	// 	printf("\tCPU time for (j = %d) %.6f secs.\n", j, cpu_time);
	// }

	// Third loop, performing the same operations as loop 2, but only touching 16 Kibi
	// (4096 possible positions multiplied for the size of an int number) of memory
	// printf("Loop 3\n");
	// for (j = 1; j <= 1024; j <<= 1) { // 11 times
	// 	start = clock();

	// 	for (i = 0; i < max_size; i += j)
	// 		vector[i & 0xfff] += 3; // 0xfff = 4095

	// 	end = clock();

	// 	cpu_time = ((double) (end - start)) / CLOCKS_PER_SEC;
	// 	printf("\tCPU time for (j = %d) %.6f secs.\n", j, cpu_time);
	// }

	printf("Loop 4\n");
	for (j = 1; j <= 0xfffffff; j <<= 1) { // 29 times
		start = clock();

		for (i = 0; i < max_size; i++)
			vector[i & j] += 3;

		end = clock();

		cpu_time = ((double) (end - start)) / CLOCKS_PER_SEC;
		printf("\tCPU time for (j = %d) %.6f secs.\n", j, cpu_time);
	}

	free(vector);

	return 0;
}

// gcc -Wall -O3 demo.c -o demo
