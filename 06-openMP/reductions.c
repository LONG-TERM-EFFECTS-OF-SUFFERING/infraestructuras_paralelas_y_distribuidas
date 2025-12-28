#include <omp.h>
#include <stdio.h>


int main() {
	int i = 99;
	printf("Value if i prior to parallel region is %d\n", i); // 99

	#pragma omp parallel private(i)
	{
		i = 1000;
	}
	printf("Value if \"i\" after parallel region with private(i) is %d\n", i); // 99

	i = 0;
	// Reductions for addition.
	#pragma omp parallel reduction(+:i) num_threads(10)
	{
		i = 1;
	}
	printf("Value if \"i\" after parallel region with \"reduction(+:i)\" is %d\n", i); // 10

	// Reductions for max.
	#pragma omp parallel reduction(max:i) num_threads(20)
	{
		i = omp_get_thread_num();
	}
	printf("Value if \"i\" after parallel region with \"reduction(max:i)\" is %d\n",i); // 19

	return 0;
}
