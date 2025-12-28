#include <omp.h>
#include <stdio.h>


int main() {
	int i;
	double share;
	int array[10];

	printf("Address of \"i\" prior to the parallel region is: %lx\n",(unsigned long) &i);
	printf("Address of \"shared\" prior to the parallel region is: %lx\n",(unsigned long) &share);
	printf("Address of \"array\" prior to the parallel region is: %lx\n",(unsigned long) array);

	#pragma omp parallel private(i, Array) shared(share)
	{
		printf("Address of \"i\" as seen by thread %d: %lx\n", omp_get_thread_num(), (unsigned long) &i);
		printf("Address of \"share\" as seen by thread %d: %lx\n", omp_get_thread_num(), (unsigned long) &share);
		printf("Address of \"array\" as seen by thread %d: %lx\n", omp_get_thread_num(), (unsigned long) array);
	}
}
