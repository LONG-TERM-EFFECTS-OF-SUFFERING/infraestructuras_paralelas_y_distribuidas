#include <assert.h>
#include <math.h>
#include <pthread.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define MIN(a, b) (((a) < (b)) ? (a) : (b))

int x_lower_limit = 0;
int x_upper_limit = 1;
int number_rectangles = 1000;
float width_rectangles;
int rectangles_per_thread;
int number_threads = 4;
float* partial_areas;


float f(float x) {
	return 4 / (1 + x * x);
}

/**
 * Calculates the partial area under the curve for a given thread.
 *
 * @param arg The thread number passed as an argument.
 * @return NULL.
 */
void* work(void* arg) {
	intptr_t thread_number = (intptr_t) arg;
	float partial_area = 0;

	/*
	int start_index = rectangles_per_thread * thread_number;
	int end_index = MIN(rectangles_per_thread * (thread_number + 1), number_rectangles);
	int step = 1;
	*/
	int start_index = thread_number;
	int end_index = number_rectangles;
	int step = number_threads;

	for (int i = start_index; i < end_index; i += step) {
		float x = x_lower_limit + width_rectangles * i;
		float height = f(x);
		float rectangle_area = width_rectangles * height;
		partial_area += rectangle_area;
	}

	partial_areas[thread_number] = partial_area;

	return NULL;
}


int main(int argc, char* argv[]) {
	pthread_t* threads;

	if (argc == 2)
		number_threads = atoi(argv[1]);
	else if (argc == 3) {
		number_threads = atoi(argv[1]);
		number_rectangles = atoi(argv[2]);
	}

	threads = (pthread_t*) malloc(sizeof(pthread_t) * number_threads);
	assert(threads != NULL);

	partial_areas = (float*) malloc(sizeof(float) * number_threads);
	assert(partial_areas != NULL);

	intptr_t thread_identifiers[number_threads];

	width_rectangles = (x_upper_limit - x_lower_limit) / (float) number_rectangles;

	rectangles_per_thread = ceil(number_rectangles / number_threads); // Step

	for (int i = 0; i < number_threads; i++) {
		thread_identifiers[i] = i;
		pthread_create(&threads[i], NULL, work, (void*) thread_identifiers[i]);
	}

	for (int i = 0; i < number_threads; i++)
		pthread_join(threads[i], NULL);

	float area = 0;
	for (int i = 0; i < number_threads; i++)
		area += partial_areas[i];

	printf("Total area: %f", area);

	free(threads);
	free(partial_areas);

	return 0;
}

// gcc -pthread pthread.c -o pthread  && ./pthread
