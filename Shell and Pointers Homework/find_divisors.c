#include <stdio.h>
#include <stdlib.h>

typedef struct divstore {
  // i'th element of divisor can divide i'th element of dividend
  int* divisor;
  int* dividend;
  int size;
} divstore;

divstore* find_divisors(int* input, int size) {
  // initialize divstore
  divstore* retval = malloc(sizeof(divstore));
  // not going to malloc(0), so start of with a size of 1 and realloc later
  // call this a "size offset"
  retval->size = 1;
  retval->divisor = (int*)malloc(retval->size * sizeof(int));
  retval->dividend = (int*)malloc(retval->size * sizeof(int));
  for (int i = 0; i < size; i++) {
    int divisor = input[i];
    for (int j = 0; j < size; j++) {
     if (input[i] == input[j]) {
       continue; // curr will always divide itself, so don't congest 
		 // the divstore with duplicates in divisor and dividend
		 // note input is assumed to not contain duplicates
     }
     int dividend = input[j];
     if (dividend % divisor == 0) {
       retval->divisor = realloc(retval->divisor, retval->size);
       retval->dividend = realloc(retval->dividend, retval->size);
       int index = retval->size - 1;
       retval->size += 1;
       retval->divisor[index] = divisor;
       retval->dividend[index] = dividend;
     }
     else {
       continue;
     }
    }
  }
  // undo "size offset"
  retval->size -= 1;
  return retval;
}

// everything printed on top will be divided by the bottom!
int main() {
  int a[] = {3, 6, 4, 12};
  divstore* r = find_divisors((int*)&a, 4);
  for (int i = 0; i < r->size; i++) {
    printf("%d ", r->dividend[i]);
  }
  printf("\n");
  for (int i = 0; i < r->size; i++) {
    printf("%d ", r->divisor[i]);
  }
  printf("\n");
}
