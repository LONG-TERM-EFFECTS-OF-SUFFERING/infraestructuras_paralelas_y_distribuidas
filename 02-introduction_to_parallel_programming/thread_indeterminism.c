#include <pthread.h>
#include <stdio.h>


int threads_number = 4;


void* work(void *arg) {
	int thread = (int) arg;

	for (int i = 0; i < 2; i++)
		printf("%d: %d\n", thread, i);

	return NULL;
}


int main(int argc, char* argv[]) {
	pthread_t threads[threads_number];
	int enumeration[threads_number];
	int i;
	int actual_threat = 1;

	for (i = 0; i < threads_number; i++, actual_threat++) {
		enumeration[i] = actual_threat;
		pthread_create(&threads[i], NULL, work, &enumeration[i]); // Giving each thread a copy of actual_threat
	}

	for (i = 0; i < threads_number; i++)
		pthread_join(threads[i], NULL);

	return 0;
}