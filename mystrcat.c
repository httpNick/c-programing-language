//
// Created by Nick Duncan on 2/12/16.
// Exercise 5-3
//

#include <stdio.h>
#include <string.h>

void mystrcat(char *s, char *t);

int main() {
  char s1[] = "Hello";
  char s2[] = "World";

  mystrcat(s1, s2);
}

void mystrcat(char *s, char *t) {
  while(*s++);
  s--; // move one before terminating '\0'
  while(*s++ = *t++);
}