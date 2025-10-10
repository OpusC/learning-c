//
// Created by Cam on 2025-10-02.
//

#include <stdio.h>
#include <string.h>

int main() {
    if (0 == '\0') {
        printf("zero is zero\n");
    }
    if ('\0') {
        printf("ascii zero is special\n");
    } else {
        printf("ascii zero is zero\n");
    }

    char zeroAsInt = 0;
    char zeroAscii = '\0';
    printf("%d\n", memcmp(&zeroAsInt, &zeroAscii, sizeof(short)));
    printf("%d\n", memcmp(&zeroAsInt, &zeroAscii, sizeof(char)));
    if (zeroAsInt == zeroAscii) {
        printf("they are equal\n");
    }
    printf("%.8x %.8x\n", zeroAsInt, zeroAscii);

    return 0;
}