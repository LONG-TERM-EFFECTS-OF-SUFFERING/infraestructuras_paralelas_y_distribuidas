#include <stdio.h>

int main() {
	int vector[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };
	int* pointer = &vector[0]; // = vector

	printf("Address of the pointer \"pointer\": %p\n", pointer);
	printf("Vector address: %p\n", vector);
	printf("Vector address: %p\n", &vector[0]);
	printf("Value at this address: %d\n", *pointer);
	printf("Value at this address: %d\n", pointer[0]);
	printf("Value at this address: %d\n", vector[0]);


	printf("Value at position 1: %d\n", pointer[1]); // 1
	pointer = pointer + 1;
	printf("Memory address: %p \t value: %d\n", pointer, *pointer); // 1
	pointer = pointer + 2;
	printf("Memory address: %p \t value: %d\n", pointer, *pointer); // 3
	printf("Memory address: %p \t value: %d\n", pointer, pointer[0]); // 3
	printf("Memory address: %p \t value: %d\n", pointer, pointer[2]); // 5

	return 0;
}