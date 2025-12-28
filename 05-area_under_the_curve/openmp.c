#include <omp.h>
#include <stdio.h>
#include <stdlib.h>


int x_lower_limit = 0;
int x_upper_limit = 1;
int number_rectangles = 10000;
int number_threads = 4;


float f(float x) {
	return 4 / (1 + x * x);
}

/**
 * Calculates the area under the curve using the method of rectangles.
 *
 * @param x_lower_limit The lower limit of the interval.
 * @param x_upper_limit The upper limit of the interval.
 * @param number_rectangles The number of rectangles to divide the interval into.
 * @return the area under the curve.
 */
float work(float x_lower_limit, float x_upper_limit, int number_rectangles) {
	float width = (x_upper_limit - x_lower_limit) / number_rectangles;
	float area = 0, x;

	#pragma omp parallel for private (x) reduction(+:area) num_threads(number_threads)
	for (int i = 0; i < number_rectangles; i++) {
		x = x_lower_limit + width * i;
		float height = f(x);
		float rectangle_area = width * height;
		area += rectangle_area;
	}

	return area;
}


int main(int argc, char* argv[]) {
	if (argc == 2)
		number_threads = atoi(argv[1]);
	else if (argc == 3) {
		number_threads = atoi(argv[1]);
		number_rectangles = atoi(argv[2]);
	}

	printf("Total area: %f", work(x_lower_limit, x_upper_limit, number_rectangles));

	return 0;
}

// gcc -fopenmp openmp.c -o openmp  && ./openmp
