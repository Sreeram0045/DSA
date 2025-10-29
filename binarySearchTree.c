#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node NODE;

struct node {
  NODE *left;
  int num;
  NODE *right;
};

bool isEmpty(NODE *ROOT) { return ROOT == NULL; }

NODE *createNewNode(int num) {
  NODE *newNode = (NODE *)malloc(sizeof(NODE));
  if (newNode == NULL) {
    printf("Memory allocation failed");
    exit(0);
  }
  newNode->left = newNode->right = NULL;
  newNode->num = num;
  return newNode;
}
NODE *insertRecursively(int num, NODE *pointer) {
  if (pointer == NULL) {
    return createNewNode(num);
  }
  if (num == pointer->num) {
    printf("Duplicate %d skipped.\n", num);
    return pointer;
  }
  if (num < pointer->num) {
    pointer->left = insertRecursively(num, pointer->left);
  } else {
    pointer->right = insertRecursively(num, pointer->right);
  }
  return pointer;
}
void insertNewNode(NODE **ROOT) {
  int num;
  printf("Enter the number: ");
  scanf("%d", &num);
  *ROOT = insertRecursively(num, *ROOT);
}

NODE *deleteNode(int num, NODE **ROOT) {
  if (*ROOT == NULL) {
    printf("Element not found");
    return NULL;
  }
  if ((*ROOT)->num < num) {
    (*ROOT)->right = deleteNode(num, &(*ROOT)->right);
  } else if ((*ROOT)->num > num) {
    (*ROOT)->left = deleteNode(num, &(*ROOT)->left);
  } else {
    // Case 1: No child
    if ((*ROOT)->left == NULL && (*ROOT)->right == NULL) {
      free(*ROOT);
      *ROOT = NULL;
      return NULL;
    }
    // Case 2: Single Child
    if ((*ROOT)->left == NULL) {
      NODE *temp = (*ROOT)->right;
      free(*ROOT);
      *ROOT = temp;
      return temp;
    } else if ((*ROOT)->right == NULL) {
      NODE *temp = (*ROOT)->left;
      free(*ROOT);
      *ROOT = temp;
      return temp;
    } else {
      NODE *succ = (*ROOT)->right;
      NODE *succparent = *ROOT;

      while (succ->left != NULL) {
        succparent = succ;
        succ = succ->left;
      }

      (*ROOT)->num = succ->num;

      if (succparent == *ROOT) {
        succparent->right = deleteNode(succ->num, &succparent->right);
      } else {
        succparent->left = deleteNode(succ->num, &succparent->left);
      }
    }
  }
  return *ROOT;
}
void deleteNodeCaller(NODE **ROOT) {
  int num;
  printf("Enter the number for deletion: ");
  scanf("%d", &num);
  deleteNode(num, ROOT);
}
void inorderTraversal(NODE *pointer) {
  if (pointer != NULL) {
    inorderTraversal(pointer->left);
    printf("%d ", pointer->num);
    inorderTraversal(pointer->right);
  }
}
void preorderTraversal(NODE *pointer) {
  if (pointer != NULL) {
    printf("%d ", pointer->num);
    preorderTraversal(pointer->left);
    preorderTraversal(pointer->right);
  }
}
void postorderTraversal(NODE *pointer) {
  if (pointer != NULL) {
    postorderTraversal(pointer->left);
    postorderTraversal(pointer->right);
    printf("%d ", pointer->num);
  }
}
int main() {
  NODE *ROOT = NULL;
  insertNewNode(&ROOT); // e.g., 50
  insertNewNode(&ROOT); // e.g., 30
  insertNewNode(&ROOT); // e.g., 70
  printf("\nInorder: ");
  inorderTraversal(ROOT);
  // printf("\nPreorder: ");
  // preorderTraversal(ROOT);
  // printf("\nPostorder: ");
  // postorderTraversal(ROOT);
  printf("\n");
  deleteNodeCaller(&ROOT);
  printf("\n");
  printf("\nInorder: ");
  inorderTraversal(ROOT);
  printf("\n");
  return 0;
}