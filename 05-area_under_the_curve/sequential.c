#include <stdio.h>
#include <stdlib.h>

int x_lower_limit = 0;
int x_upper_limit = 1;
int number_rectangles = 10000;


float f(float x) {
	return 4 / (1 + x * x);
}

float work(float x_lower_limit, float x_upper_limit, int number_rectangles) {
	float width = (x_upper_limit - x_lower_limit) / number_rectangles;
	float area = 0;

	for (int i = 0; i < number_rectangles; i++) {
		float x = x_lower_limit + width * i;
		float height = f(x);
		float rectangle_area = width * height;
		area += rectangle_area;
	}

	return area;
}


int main(int argc, char* argv[]) {
	if (argc == 2)
		number_rectangles = atoi(argv[1]);

	printf("Total area: %f", work(x_lower_limit, x_upper_limit, number_rectangles));

	return 0;
}
