#include <pthread.h>
#include <stdio.h>


void* square(void* arg) {
	int* number = (int*) arg;
	printf("number^2 = %d\n", *number * *number);
}

void* cube(void* arg) {
	int* number = (int*) arg;
	printf("number^3 = %d\n", *number * *number * *number);
}


int main() {
	pthread_t pt_id_1, pt_id_2;
	int number = 10;

	pthread_create(&pt_id_1, NULL, square, &number);
	pthread_create(&pt_id_1, NULL, cube, &number);

	pthread_join(pt_id_1, NULL);
	pthread_join(pt_id_2, NULL);

	return 0;
}

// gcc -pthread pthread_1.c -o main
