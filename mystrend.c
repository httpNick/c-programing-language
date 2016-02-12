//
// Created by Nick Duncan on 2/12/16.
// Exercise 5-4
//

#include <stdio.h>

int mystrend(char *a, char *b);

int main() {

  char a[] = "mystrasdndkstrzzxyz";
  char b[] = "strzzxyz";

  printf("%d\n", mystrend(a, b));
}

int mystrend(char *a, char *b) {
  int i = 0;
  while(*a++);
  while(*b++) i++;
  a--;
  b--;
  while(*a-- == *b-- && i--) {
    if (!i) return 1;
  }
  return 0;
}