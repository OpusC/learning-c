#pragma once

struct rectangle;

struct rectangle* create_rectangle(double height, double width); // this abstraction gets better with the typedef keyword,
// but let's keep it simple for now

double rectangle_area(struct rectangle* rectangle);

double rectangle_width(struct rectangle* rectangle);

double rectangle_height(struct rectangle* rectangle);

void destroy_rectangle(struct rectangle*);
