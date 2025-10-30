#include <stdlib.h>

struct rectangle {
	double width;
	double height;
	double area;
};

struct rectangle* create_rectangle(double height, double width) {
	struct rectangle* rect = malloc(sizeof(struct rectangle));
	if (rect == NULL) return NULL;

	rect->width = width;
	rect->height = height;

	rect->area = width * height;

	return rect;
}


unsigned int rectangle_area(struct rectangle* r) {
	return r->area;
}

double rectangle_width(struct rectangle* r) {
	return r->width;
}

double rectangle_height(struct rectangle* r) {
	return r->height;
}

void destroy_rectangle(struct rectangle* r) {
	free(r);
}
