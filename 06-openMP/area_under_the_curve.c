#include <assert.h>
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>


int x_lower_limit = 0;
int x_upper_limit = 1;
int number_rectangles = 10000;
int number_threads = 4;
float* partial_areas;


float f(float x) {
	return 4 / (1 + x * x);
}

/**
 * Calculates the area under the curve using the method of rectangles.
 *
 * @param x_lower_limit The lower limit of the interval.
 * @param x_upper_limit The upper limit of the interval.
 * @param number_rectangles The number of rectangles to divide the interval into.
 */
void work(float x_lower_limit, float x_upper_limit, int number_rectangles) {
	float width = (x_upper_limit - x_lower_limit) / number_rectangles;
	float x;

	#pragma omp parallel for private(x) num_threads(number_threads)
	for (int i = 0; i < number_rectangles; i++) {
		x = x_lower_limit + width * i;
		float height = f(x);
		float rectangle_area = width * height;
		partial_areas[omp_get_thread_num()] += rectangle_area;
	}
}


int main(int argc, char* argv[]) {
	if (argc == 2)
		number_threads = atoi(argv[1]);
	else if (argc == 3) {
		number_threads = atoi(argv[1]);
		number_rectangles = atoi(argv[2]);
	}

	partial_areas = (float*) malloc(sizeof(float) * number_threads);
	assert(partial_areas != NULL);

	#pragma omp parallel num_threads(number_threads)
	partial_areas[omp_get_thread_num()] = 0;

	work(x_lower_limit, x_upper_limit, number_rectangles);

	float area = 0;
	for (int i = 0; i < number_threads; i++)
		area += partial_areas[i];

	printf("Total area: %f\n", area);

	free(partial_areas);

	return 0;
}

// gcc -fopenmp area_under_the_curve.c -o openmp  && ./openmp
