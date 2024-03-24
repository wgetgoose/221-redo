#include <stdlib.h>
#include <stdio.h>

int* slice(int input[], int start, int end) {
  int size = end - start;
  int* retval = malloc(size * sizeof(int));
  int index = 0;
  for (int j = start; j < end; j++) {
    retval[index] = input[j];
    index += 1;
  }
  return retval;
}

int main() {
  int arr[] = {5, 2, 6, 1, 9, 4, 3};
  int* a = slice(arr, 2, 5);
  for (int i = 0; i < 3; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");
}
