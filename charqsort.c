#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void charqsort(char *, int, int);
int partition(char *, int, int);
void swap(char *, int, int);

int main() {
  size_t n_bytes = 100;
  char *my_input;
  my_input = malloc(n_bytes + 1);
  while(getline(&my_input, &n_bytes, stdin) && strlen(my_input) > 1) {

    charqsort(
      my_input,
      0,
      strlen(my_input) - 1
    );
    printf("%s\n", my_input);
  }
  return 0;
}

void charqsort(char *data, int l, int h) {
  if (l < h) {
    int part = partition(data, l, h);
    charqsort(data, l, part);
    charqsort(data, part + 1, h);
  }
}

int partition(char *data, int l, int h) {
  char pivot = data[l];
  int i, leftwall;
  leftwall = l;

  for(i = l + 1; i < h; i++) {
    if (data[i] < pivot) {
      leftwall++;
      swap(data, i, leftwall);
    }
  }

  swap(data, l, leftwall);
  return leftwall;
}

void swap(char *v, int i, int j) {
  char temp;

  temp = *(v+i);
  v[i] = *(v+j);
  v[j] = temp;
}
