#include <stdio.h>
#include <stdlib.h>


// worked for multiple hours looking for a BSTRemove function that wouldn't segfault
// but didn't get there. create, insert, etc. work

typedef struct node{
  int value;
  struct node* prev;
  struct node* left;
  struct node* right;
} node;

typedef struct bst {
  int size;
  struct node* root;
} bst;

node* buildNode(int value) {
  node* n = malloc(sizeof(node));
  n->left = NULL;
  n->right = NULL;
  n->prev = NULL;
  n->value = value;
  return n;
}

void insertCompare(node* root, node* n) {
  if (root->value == n->value) {
    // not going to insert duplicate values
    return;
  }
  if (root->value > n->value) {
    if (root->left == NULL) {
      root->left = n;
      n->prev = root;
    }
    else if (root->left != NULL) {
      insertCompare(root->left, n);
    }
  }
  else if (root->value < n->value) {
    if (root->right == NULL) {
      root->right = n;
      n->prev = root;
    }
    else if (root->right != NULL) {
      insertCompare(root->right, n);
    }
  }
}

void insert(bst* tree, int value) {
  node* n = buildNode(value);
  if (tree->root == NULL) {
    tree->root = n;
  }
  else {
    insertCompare(tree->root, n);
  }
  tree->size++;
}

// converts a given array to a bst, for testing
bst* creation(int array[], int size) {
  bst* tree = malloc(sizeof(tree));
  tree->root = NULL;
  tree->size = 0;
  for (int i = 0; i < size; i++) {
    insert(tree, array[i]);
  }
  return tree;
}

node* removeCompare(node* root, int value) {
 if (root->value < value) {
   if (root->right == NULL) {
     return NULL;
   }
   else {
     removeCompare(root->right, value);
   }
 }
 if (root->value > value) {
   if (root->left == NULL) {
     return NULL;
   }
   else {
     removeCompare(root->left, value);
   }
 }
 if (root->value == value) {
   return root;
 }
}

int balanceDelete(node* root) {
  // case: no children
  if (root->left == NULL && root->right == NULL) {
    if (root->prev->left = root) {
      root->prev->left = NULL;
    }
    if (root->prev->right = root) {
      root->prev->right = NULL;
    }
    free(root);
    return 0;
  }
  // case: removal node has right child
  if (root->left == NULL) {
    if (root->prev->left == root) {
      root->prev->left = root->right;
    }
    if (root->prev->right == root) {
      root->prev->right = root->right;
    }
    free(root);
    return 0;
  }
  // case: removal node has left child
  if (root->right == NULL) {
    if (root->prev->left == root) {
      root->prev->left = root->left;
    }
    if (root->prev->right == root) {
      root->prev->right == root->left;
    }
    free(root);
    return 0;
  }
  // case: removal node has two children
  node* curr = root->right;
  while (curr->left != NULL) {
    curr = curr->left;
  }
  root->value = curr->value;
  balanceDelete(curr); 
}

int bstRemove(bst* tree, int value) {
  node* n = removeCompare(tree->root, value); 
  if (n == NULL) {
    return 1;
  }
  balanceDelete(removeCompare(tree->root, value));
  tree->size -= 1;
  return 0;
}

// pass the ROOT NODE in for recursive printing
void printBST(node* root) {
    printf("%i\n", root->value);
  if (root->left != NULL) {
    printf("Left of %i: ", root->value);
    printBST(root->left);
  }
  if (root->right != NULL) {
      printf("Right of %i: ", root->value);
      printBST(root->right);
  }
}

int main() {
  int bstArray[] = {20, 27, 15, 6, 4, 22};
  bst* tree = creation(bstArray, 6);
  printBST(tree->root);
  bstRemove(tree, 15);
  printBST(tree->root);
}
