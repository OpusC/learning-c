typedef struct Vector Vector;

/*
* Create a new vector
*/
Vector* v_create();

/*
* Free the vector and its internal memory
*/
void v_free(Vector *vector);

/*
* Set the element at the specified index to a value. Returns the previous
* element. Returns NULL if the index is out of bounds.
*/
void* v_set(Vector *vector, void *element, unsigned int index);

/*
* Return the element at the specified index. Returns NULL if index is out of bounds
*/
void *v_get(Vector *vector, unsigned int index);

/*
* Add an element to the end of the vector
*/
void v_append(Vector *vector, void *element);

/*
* Remove the element from the specified index. Returns the removed element. Returns
* NULL if the index is out of bounds.
*/
void v_remove(Vector *vector, unsigned int index);
