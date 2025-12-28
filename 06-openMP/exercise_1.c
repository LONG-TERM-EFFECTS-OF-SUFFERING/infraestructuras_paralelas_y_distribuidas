#include <omp.h>
#include <stdio.h>


int main() {
	#pragma omp parallel num_threads(10)
	{
		int thread_number = omp_get_thread_num();

		printf("Hello from thread %d ", omp_get_thread_num());

		if (thread_number % 2)
			printf("I am odd");
		else
			printf("I am even");
	}

	return 0;
}
