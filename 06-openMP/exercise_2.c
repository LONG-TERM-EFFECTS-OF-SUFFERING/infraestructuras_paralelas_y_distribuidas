#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define size 10


void print_array(int array[]) {
	printf("[");
	int i;
	for (i = 0; i < size; i++ && printf(" %d ", array[i - 1]));
	printf("]\n");
}


int main() {
	int numbers[size], i, min = 10000, max;
	float average;

	omp_set_dynamic(0);

	#pragma omp parallel num_threads(size)
	numbers[omp_get_thread_num()] = rand() % 10000;

	print_array(numbers);

	#pragma omp parallel reduction(max:max) num_threads(size)
	max = numbers[omp_get_thread_num()];

	printf("The max is %d\n", max);

	#pragma omp parallel reduction(min:min) num_threads(size)
	min = numbers[omp_get_thread_num()];

	printf("The min is %d\n",min);

	#pragma omp parallel reduction(+:average) num_threads(size)
	average = numbers[omp_get_thread_num()] / size;

	printf("The average is %f\n", average);

	return 0;
}
