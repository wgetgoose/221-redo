#include <stdio.h>
#include <stdlib.h>

// possible errors
// 1. Incorrect index: copy_substring("hel", 4, 5);

char* copy_substring(char* string, int start, int end) {
  int length = end - start;
  char* sub = malloc(length * sizeof(char));
  int index = 0;
  for (int i = start; i < end; i++) {
   sub[index] = string[i];
   index++;
  }
  return sub;
}

int main() {
  char* substr = copy_substring("hello", 4, 5);
  printf("%s", substr);
}
