#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node NODE;

struct node {
  NODE *left;
  int num;
  NODE *right;
};

NODE *ROOT = NULL;
bool isEmpty() { return ROOT == NULL; }
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
NODE *recursiveSearchingForPosition(int num, NODE *pointer) {
  if (pointer == NULL || pointer->num == num) {
    return createNewNode(num);
  } else if (num < pointer->num) {
    pointer->left = recursiveSearchingForPosition(num, pointer->left);
  } else if (num > pointer->num) {
    pointer->right = recursiveSearchingForPosition(num, pointer->right);
  }
  return pointer;
}
void insertNewNode() {
  int num;
  printf("Enter the number: ");
  scanf("%d", &num);
  ROOT = recursiveSearchingForPosition(num, ROOT);
}
void printInorder(NODE *pointer) {
  if (pointer != NULL) {
    printInorder(pointer->left);
    printf("%d ", pointer->num);
    printInorder(pointer->right);
  }
}
int main() {
  insertNewNode(); // e.g., 50
  insertNewNode(); // e.g., 30
  insertNewNode(); // e.g., 70
  printf("Inorder: ");
  printInorder(ROOT);
  printf("\n");
  return 0;
}