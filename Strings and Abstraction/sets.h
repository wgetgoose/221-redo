#ifndef SET_OPERATIONS
#define SET_OPERATIONS

#include <stdlib.h>
#include <stdio.h>


typedef struct node {
  struct node* next;
  int value;
} node;

typedef struct set {
 int size;
 node* first;
} set;

int node_free(set* s);

set* set_create();

int set_delete(set* s);

int set_insert(set* s, int value);

int set_remove(set* s, int value);

int set_empty(set* s);

int set_contains(set* s, int value);

#endif
