#include <stdio.h>
#include "rectangle.h"

int main() {


	struct rectangle* r = create_rectangle(3, 3);

	double width = rectangle_width(r);

	printf("width %f\n", width);

	double height = rectangle_height(r);

	printf("height %f\n", height);

	double area = rectangle_area(r);

	printf("area %f\n", area);

	destroy_rectangle(r);
}
