#include <stdio.h>
#include <stdlib.h>
typedef struct node NODE;

struct node {
  int data;
  NODE *next;
};

NODE *HEAD = NULL;

int isEmpty() { return HEAD == NULL; }
void push() {
  int num;
  NODE *newNode = (NODE *)malloc(sizeof(NODE));
  printf("Enter the number: ");
  scanf("%d", &num);
  newNode->data = num;
  if (isEmpty()) {
    newNode->next = NULL;
    HEAD = newNode;
    return;
  }
  newNode->next = HEAD;
  HEAD = newNode;
}
void pop() {
  if (isEmpty()) {
    printf("The stack is empty\n");
    return;
  }
  NODE *temp = (NODE *)malloc(sizeof(NODE));
  temp = HEAD;
  HEAD = HEAD->next;
  printf("Popped element is: %d\n", temp->data);
  free(temp);
}
void seek() {
  if (isEmpty()) {
    printf("The stack is empty\n");
    return;
  }
  printf("Top of the Stack element is: %d\n", HEAD->data);
}
void play() {
  int option;
  while (1) {
    printf(
        "Enter 1. Push to the stack, 2. Pop from the Stack, 3. Seek, 4.Exit\n");
    scanf("%d", &option);
    switch (option) {
    case 1:
      push();
      break;
    case 2:
      pop();
      break;
    case 3:
      seek();
      break;
    case 4:
      exit(0);
    }
  }
}
int main() {
  play();
  return 0;
}