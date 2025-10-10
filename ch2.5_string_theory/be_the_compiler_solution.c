//
// Created by Cam on 2025-10-02.
//
#include <stdio.h>
#include <string.h>

char tracks[][80] = {
    "I left my  heart in Harvard Med School",
    "Newark, Newark - a wonderful town",
    "Dancing with a Dork",
    "From here to maternity",
    "The girl from Iwo Jima",
};

void find_track(char search_for[]) {
    int i;
    for (i = 0; i < 5; i++) {
        if (strstr(tracks[i], search_for)) {
            printf("Track %i: '%s'\n", i, tracks[i]);
        }
    }
}

void find_and_print(char search_for[]) {
    printf("Searching for %s\n", search_for);
    find_track(search_for);
}

int main() {
    char search_for[80];
    printf("Search for: ");

    // there are seemingly two bugs here
    // 1. scanf will stop at the first space, so there's a logic error for search terms with a space
    // e.g. "Dancing On The Town"
    scanf("%79s", search_for);
    // 2. strlen requires a null-terminating character, so this will remove the last character in the search term
    int length_of_search_term = strlen(search_for);
    printf("%d\n", length_of_search_term);

    char search_for_incorrect[80];
    strcpy(search_for_incorrect, search_for);
    search_for_incorrect[length_of_search_term - 1] = '\0'; // this (from the book) is wrong

    find_and_print(search_for_incorrect); // will search for the search term less than
    find_and_print(search_for);

    return 0;
}

