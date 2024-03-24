#include "sets.h"

set* intersection(set* s1, set* s2) {
  // logic: check set 1 against set 2
  set* retval = set_create(); 
  node* curr = s1->first;
  for (int i = 0; i < s1->size; i++) {
    if (set_contains(s2, curr->value) == 1) {
      set_insert(retval, curr->value);
    }
    curr = curr->next;
  }
  return retval;
}

/*
int main() {
  set* a = set_create();
  set* b = set_create();
  set_insert(a, 2);
  set_insert(a, 4);
  set_insert(b, 1);
  set_insert(b, 3);
  set* c = intersection(a, b);
  printf("%d\n", c->first->value); // will segfault if no intersection
}
*/
