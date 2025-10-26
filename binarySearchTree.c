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
NODE *recursiveSearchingForPosition(int num, NODE **pointer) {
  if (*pointer == NULL || (*pointer)->num == num) {
    return createNewNode(num);
  } else if (num < (*pointer)->num) {
    (*pointer)->left = recursiveSearchingForPosition(num, &(*pointer)->left);
  } else if (num > (*pointer)->num) {
    (*pointer)->right = recursiveSearchingForPosition(num, &(*pointer)->right);
  }
  return *pointer;
}
void insertNewNode(NODE **ROOT) {
  int num;
  printf("Enter the number: ");
  scanf("%d", &num);
  *ROOT = recursiveSearchingForPosition(num, ROOT);
}
NODE *deleteNode(int num, NODE **ROOT) {
  if (num == (*ROOT)->num || ROOT == NULL) {
    if ((*ROOT)->left == NULL && (*ROOT)->right == NULL) {
      printf("Number deleted\n");
      free(*ROOT);
      return NULL;
    } else {
      if ((*ROOT)->left == NULL) {
        (*ROOT)->num = ((*ROOT)->right)->num;
        printf("Number deleted from right node\n");
        free((*ROOT)->right);
        (*ROOT)->right = NULL;
      } else if ((*ROOT)->right == NULL) {
        printf("Number deleted from left node\n");
        (*ROOT)->num = ((*ROOT)->left)->num;
        free((*ROOT)->left);
        (*ROOT)->left = NULL;
      }
    }
  } else if ((*ROOT)->num < num) {
    (*ROOT)->right = deleteNode(num, &(*ROOT)->right);
  } else {
    (*ROOT)->left = deleteNode(num, &(*ROOT)->left);
  }
  return *ROOT;
}
void deleteNodeCaller(NODE **ROOT) {
  int num;
  printf("Enter the number for deletion: ");
  scanf("%d", &num);
  deleteNode(num, &*ROOT);
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