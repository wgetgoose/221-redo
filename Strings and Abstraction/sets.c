#include <stdlib.h>
#include <stdio.h>

// defining sets as a linked list. allows for easy deletion later
typedef struct node {
  struct node* next;
  int value;
} node;

typedef struct set {
 int size;
 node* first;
} set;

// free all nodes of a set
int node_free(set* s) {
  // improvement: if checks for input
  node* curr = NULL;
  node* prev = s->first;
  for (int i = 0; i < s->size; i++) {
    if (prev->next == NULL) {
      free(prev);
      s->size = 0;
      s->first = NULL;
      return 0;
    }
    curr = prev->next;
    free(prev);
    // reset for next loop iteration
    prev = curr;
  }
  return 1;
}

set* set_create() {
  set* s = malloc(sizeof(set));
  s->first = NULL;
  s->size = 0;
  return s;
}

int set_delete(set* s) {
 if (s == NULL) {
   return 1;
 }
 else {
   node_free(s);
   free(s);
   return 0;
 }
}

int set_insert(set* s, int value) {
  node* curr = s->first;
  node* working = NULL;
  if (curr == NULL) {
    s->first = malloc(sizeof(node));
    working = s->first;
  }
  for (int i = 0; i < s->size; i++) {
    if (curr->value == value) {
      return 1;
    }
    if (curr->next == NULL) {
      curr->next = malloc(sizeof(node));
      working = curr->next;
      break;
    }
    curr = curr->next;
  }
  working->value = value;
  working->next = NULL;
  s->size += 1;
  return 0;
}

int set_remove(set* s, int value) {
  node* prev = NULL;
  node* curr = s->first;
  for (int i = 0; i < s->size; i++) {
    if (curr->value == value) {
      if (prev == NULL) { // if removing first element
	s->first = curr->next; // if curr->next is null, set still exists but is empty after removal
	free(curr);
	s->size -= 1;
	return 0;
      }
      prev->next = curr->next;
      free(curr);
      s->size -= 1;
      return 0;
    }
    prev = curr;
    curr = curr->next;
  }
  return 1;
}

int set_choose(set* s) {
  if (s->first == NULL || s == NULL) {
    return -1;
  }
  else {
    return s->first->value;
  }
}

// 0 false 1 true
int set_empty(set* s) {
  if (s->first == NULL || s == NULL) {
    return 1;
  }
  else {
    return 0;
  }
}


// instructions say return 1 if in set, 0 if not in set
int set_contains(set* s, int value) {
 // very similar to set_remove
 node* curr = s->first;
 for (int i = 0; i < s->size; i++) {
   if (curr->value == value) {
     return 1;
   }
   else {
     curr = curr->next;
   }
 }
 return 0;
}


/*
int main() {
  set* a = set_create();
  printf("%d\n", set_choose(a));
  set_insert(a, 2);
  set_insert(a, 2);
  printf("%d\n", set_choose(a));
  printf("%d\n", set_empty(a));
  printf("%d\n", set_contains(a, 2));
  printf("%d\n", set_contains(a, 3));
  set_remove(a, 2);
  printf("%d\n", set_empty(a));
  set_delete(a);
  return 0;
}
*/
