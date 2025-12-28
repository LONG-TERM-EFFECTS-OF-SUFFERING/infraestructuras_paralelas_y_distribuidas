#include <omp.h>
#include <stdio.h>


int main() {
	int number = 999;

	#pragma omp parallel private(number) num_threads(10)
	printf("Thread %d sees %d\n", omp_get_thread_num(), number);

	printf("\n");

	#pragma omp parallel firstprivate(number) num_threads(10)
	printf("Thread %d sees %d\n", omp_get_thread_num(), number);

	return 0;
}
