# Strings

## Passing a string into a function

```c
void foo(char msg[]) {
    ...
}
```
- A char array (string) passed into a function will actually be a pointer passed into the
function
- **C does NOT support passing arrays in by value**
    Why?
    - Functions don't need to know the size of the array at compile time, they just get
    a pointer
    - Copying arrays by value is expensive

- Even though array variables can work similarly to pointers, they ARE different
- sizeof() called on an array will give the size of the entire array
    - This differs from what happens when sizeof is called on a pointer (it returns the size
    of a pointer)
- If you use the & operator on an array, it is will return the address of the first element of the array
    - If you use & on a pointer, it returns the address of the pointer variable itself
    - Additionally, the compiler wont allocate space to store the array variable so you cannot make them
    point somewhere else

    - Pointers, unlike arrays, do not store the size (length) of an array
    - This is called pointer decay, as information is lost

- 
