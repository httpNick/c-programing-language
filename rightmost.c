//
// Created by Nick Duncan on 2/9/16.
//
#include <stdio.h>
#include <string.h>

int rightmost(char text[], char pattern[]);

char pattern[] = "or";
char text[] = "hello, world";

int main() {
    int res = rightmost(text, pattern);
    return 0;
}

int rightmost(char text[], char pattern[]) {

    int i, j, k;

    for(i = strlen(text) - 1; i >= 0; i--) {
        for(j = i, k = strlen(pattern) - 1; k <= j && text[j] == pattern[k]; j--, k--);

        if (k == -1) {
            return j;
        }
    }

    return -1;
}

