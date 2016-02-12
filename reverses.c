//
// Created by Nick Duncan on 2/10/16.
// Ex. 4-13 reverse a string recursively.
//

#include <string.h>
#include <stdio.h>

void reverse(char[], int s, int e);
void swap(char[], int, int);

int main() {
    char text[] = "Hello, World!";
    reverse(text, 0, strlen(text) - 1);
    printf("%s", text);
}

void reverse(char s[], int b, int e) {
    int swapper;
    swapper = e - b;
        if (b < swapper) {
            swap(s,b,swapper);
            reverse(s,++b,e);
        }
}

void swap(char s[], int i, int j) {
    char temp;

    temp = s[i];
    s[i] = s[j];
    s[j] = temp;
}
