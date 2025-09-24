#include <stdio.h>
#include <stdlib.h>

#define RESIZE_FACTOR 1.5
#define SHRINK_FACTOR 0.5
#define INITIAL_CAPACITY 4
#define SHRINK_RATIO 0.25

struct Vector {
	void** v_array;
	unsigned int size;
	unsigned int capacity;
};

typedef struct Vector Vector;

static int resize_up(Vector *vector) {
	unsigned int new_capacity = vector->capacity * RESIZE_FACTOR;

	void **new_array = malloc(sizeof(void *) * new_capacity);
	if (!new_array) {
		return -1;
	}

	for (unsigned int i = 0; i < vector->size; i++) {
		new_array[i] = vector->v_array[i];
	}

	free(vector->v_array);
	vector->v_array = new_array;
	vector->capacity = new_capacity;

	return 1;
}

static int resize_down(Vector *vector) {
	unsigned int new_capacity = vector->capacity * SHRINK_FACTOR;

	if (new_capacity < vector->size) {
	}

	if (new_capacity < INITIAL_CAPACITY) {
		return 0;
	}

	void ** new_array = malloc(sizeof(void *) * new_capacity);
	if (!new_array) {
		return -1;
	}

	for (unsigned int i = 0; i < vector->size; i++) {
		new_array[i] = vector->v_array[i];
	}

	free(vector->v_array);
	vector->v_array = new_array;
	vector->capacity = new_capacity;

	return 1;
}


void* v_set(Vector *vector, void *element, unsigned int index) {
	if (!vector || index > vector->size - 1) return NULL;

	void *return_element = return_element = vector->v_array[index];
	vector->v_array[index] = element;
	return return_element;
}

void* v_get(Vector *vector, unsigned int index) {
	if (!vector || index > vector->size - 1) return NULL;

	return vector->v_array[index];
}

void* v_remove(Vector *vector, unsigned int index) {
	if (!vector || index > vector->size) return NULL;

	void* return_element = vector->v_array[index];

	
	for (unsigned int i = index; i+1 < vector->size; i++) {
		vector->v_array[i] = vector->v_array[i + 1];
	}

	vector->size -= 1;

	if (vector->size < vector->capacity * SHRINK_RATIO) {
		resize_down(vector);
	}

	return return_element;
}

Vector* v_create() {
	void **v_array = malloc(sizeof(void *) * INITIAL_CAPACITY);
	if (!v_array) return NULL;

	Vector *vector = malloc(sizeof(Vector));
	vector->size = 0;
	vector->capacity = INITIAL_CAPACITY;
	vector->v_array = v_array;

	return vector;
}

void v_free(Vector *vector) {
	if (!vector) return;

	for (unsigned int i = 0; i < vector->size; i++) {
		free(vector->v_array[i]);
	}

	free(vector->v_array);
	free(vector);
}



/*
* Add an element to the end of the vector
*/
void v_append(Vector *vector, void *element) {
	if (vector->size + 1 > vector->capacity) {
		resize_up(vector);
	}

	vector->v_array[vector->size] = element;
	vector->size += 1;
}

int main() {

	Vector *v = v_create();

	if (!v) { fprintf(stderr, "v_create failed\n"); return 1; }
	if (v->size != 0) { fprintf(stderr, "Initial size should be 0\n"); return 1; }
	if (v->capacity != INITIAL_CAPACITY) { fprintf(stderr, "Initial capacity incorrect\n"); return 1; }

	// Append 10 integers
	for (int i = 0; i < 10; i++) {
		int *val = malloc(sizeof(int));
		*val = i * 10;
		v_append(v, val);

		if (v->size != i + 1) { fprintf(stderr, "Size incorrect after append at index %d\n", i); return 1; }
		if (v->capacity < v->size) { fprintf(stderr, "Capacity too small after append at index %d\n", i); return 1; }
	}

	// Test v_get
	for (unsigned int i = 0; i < v->size; i++) {
		int *val = (int*)v_get(v, i);
		if (!val) { fprintf(stderr, "v_get returned NULL at index %u\n", i); return 1; }
		if (*val != (int)(i * 10)) { fprintf(stderr, "v_get returned wrong value at index %u\n", i); return 1; }
	}

	// Test v_set
	int *new_val = malloc(sizeof(int));
	*new_val = 999;
	void *old_val = v_set(v, new_val, 5);
	if (*(int*)old_val != 50) { fprintf(stderr, "v_set returned wrong old value\n"); return 1; }
	if (*(int*)v_get(v, 5) != 999) { fprintf(stderr, "v_set did not update value correctly\n"); return 1; }

	// Test v_remove
	int *removed = (int*)v_remove(v, 3);
	if (*removed != 30) { fprintf(stderr, "v_remove returned wrong element\n"); return 1; }
	free(removed);
	if (v->size != 9) { fprintf(stderr, "Size incorrect after removal\n"); return 1; }

	// Check remaining elements after removal
	int expected[] = {0, 10, 20, 40, 999, 60, 70, 80, 90};
	for (unsigned int i = 0; i < v->size; i++) {
		int *val = (int*)v_get(v, i);
		printf("list element value %d\n", *val);
		if (*val != expected[i]) {
			fprintf(stderr, "v_remove did not shift elements correctly at index %u\n", i);
			printf("expected %d but got %d\n", expected[i], *val);


			return 1;
		}
	}

	// Remove all elements to test shrinking
	while (v->size > 0) {
		int *r = (int*)v_remove(v, 0);
		free(r);
	}
	if (v->size != 0) { fprintf(stderr, "Size should be 0 after removing all elements\n"); return 1; }
	if (v->capacity < INITIAL_CAPACITY) { fprintf(stderr, "Capacity should not shrink below initial\n"); return 1; }

	// Free vector
	v_free(v);

	printf("All tests passed!\n");
	return 0;
}
