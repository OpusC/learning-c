# Why did name get printed?

stackbug.c is the program with the bug. compile and run it and see that name is mysteriously
printed correctly even though getName() does not even have a return value

stackbug.s is the assembly instructions for the compiled code on my machine. you can
get the instructions for the compiler on your machine with the following command

```bash
gcc -S main.c
```

note that not returning a value from a function that is supposed to have a return value is
*undefined behaviour*, so it might not be reproducable on all machines

