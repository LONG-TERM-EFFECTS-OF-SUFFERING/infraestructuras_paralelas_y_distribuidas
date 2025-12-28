#include <assert.h>
#include <malloc.h>
#include <pthread.h>
#include <stdio.h>


int vector_size = 10000;
int min_fibonacci = 2;
int max_fibonacci = 32;
int* vector;
int number_threads = 2;


void initialize_vector() {
	vector = (int*) malloc(sizeof(int) * vector_size);

	assert(vector != NULL);

	for (int i = 0; i < vector_size; i++)
		vector[i] = i % max_fibonacci + min_fibonacci;
}

int fibonacci(int n) {
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else
		return fibonacci(n - 1) + fibonacci(n - 2);
}

void* work(void* arg) {
	int id = (int) arg;
	int step = vector_size / number_threads;

	printf("Thread %d proccesing form %d to %d\n", id, id * step, (id + 1) * step);

	for (int i = id * step; i < (id + 1) * step; i++)
		vector[i] = fibonacci(vector[i]);

	return NULL;
}


int main(int argc, char* argv[]) {
	pthread_t* pt_id;
	int* id;

	if (argc == 2)
		number_threads = atoi(argv[1]);

	pt_id = (pthread_t*) malloc(sizeof(pthread_t) * number_threads);
	assert(pt_id != NULL);

	id = (int*) malloc(sizeof(int) * number_threads);
	assert(id != NULL);

	initialize_vector();

	for (int i = 0; i < number_threads; i++) {
		id[i] = i;
		pthread_create(&pt_id[i], NULL, work, &id[i]);
	}

	for (int i = 0; i < number_threads; i++)
		pthread_join(pt_id[i], NULL);

	return 0;
}
