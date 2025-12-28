#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

#include "log/log.h"


void* work(void* arg) {
	pthread_t thread_id = pthread_self();
	log_info("Thread %lu: starting", thread_id);
	sleep(2);
	log_info("Thread %lu: finishing", thread_id);
}


int main() {
	pthread_t pt_id_1;

	pthread_create(&pt_id_1, NULL, work, NULL);

	pthread_join(pt_id_1, NULL);

	return 0;
}

// gcc -pthread pthread_2.c log/log_c -o main
