# Calling Cat
When using the cat program, you can put the command line arguments before or after the file

```shell
cat -E sample.txt

```shell
cat sample.txt -E
```

*-E will show print a $ at the end of each line where there is a new line character*

Both of these are valid ussages of cat

In my program wcat.c (Completed by me as an exercise from the book Operating Systems: Three Easy Pieces and added to for
the purpose of demonstrating command line arguments), this is not possible. To fix this:

1. Rewrite the command line arguments processing portion of the program to use getopt()
2. Use the GNU extension of getopt() to allow passing the conditional arguments after the non-optional arguments

*It turns out that the default behavior of GNU getopt() is to allow options to come before
or after non-optional arguments. I thought I would have to set some special options but
it turns out it just works*
