# What causes a segfault?

## Questions and answers

Q1. Does reading from an index past the bounds of an array cause a segfault?

A1. Sometimes, but not always. This is undefined behavior that could throw a segfault or read garbage values.
See out_of_bounds_read.c as a demo

Q2. Does writing to an index past the bounds of an array cause a segfault?

A2. On my test, I got a "*** stack smashing detected ***: terminated" as an error message
See out_of_bounds_write.c as a demo

That error message is caused from a *stack canary* being overwritten. To disable stack canaries, compile with
the following command:
```bash
gcc -fno-stack-protector out_of_bounds_write.c
```

With this command, I got a segfault when accessing index 9001 on an array of size 10. This is *likely undefined behaviour*
