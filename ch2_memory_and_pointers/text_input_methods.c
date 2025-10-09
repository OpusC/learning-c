/*
 * NOTE: YOU MUST USE THE -std=c99 COMPILER FLAG WITH GCC TO COMPILE THIS CLASS
 */
#include <stdio.h>

int main()
{
    /*
     * in the book they show how you can cause a buffer overflow
     * here we're taking in text using scanf and just %s which
     * can allow us to input a value into food that is greater
     * than 5 characters 😬
     */
    char food[5];
    printf("Enter favorite food: ");
    scanf("%s", food);
    printf("Favorite food: %s\n", food);

    /*
     * But what happens if we use %5s to limit the number of characters?
     * Seemingly inputting more than 5 characters doesn't cause a
     * buffer overflow.....
     */
    char secondFood[5];
    printf("Enter your second favorite food: ");
    scanf("%5s", secondFood);
    printf("Second favorite food: %s\n", secondFood);

    /*
     * Instead the book suggests that fgets is a safer approach as a specified
     * size is a forced requirement rather than just providing a type (and
     * allowing for buffer overflow)
     */
    char thirdFood[5];
    printf("Enter your third favorite food: ");
    fgets(thirdFood, sizeof(thirdFood), stdin);
    printf("Third favorite food: %s\n", thirdFood);

    /*
     * Finally, there's something older and even more dangerous - gets
     * this one is so dangerous that you can't even compile this file
     * without specifying C99 as the compiler target
     */
    char fourthFood[5];
    printf("Enter your fourth favorite food: ");
    gets(fourthFood);
    printf("Fourth favorite food: %s\n", fourthFood);

    return 0;


}