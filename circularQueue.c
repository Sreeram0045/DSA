#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;
struct Node {
  int val;
  Node *next;
};

Node *REAR = NULL;
Node *FRONT = NULL;

bool isEmpty() { return REAR == NULL && FRONT == NULL; }

void enqueue() {
  int value;
  Node *newNode = (Node *)malloc(sizeof(Node));
  printf("Enter the number: ");
  scanf("%d", &value);
  newNode->val = value;
  if (isEmpty()) {
    newNode->next = newNode;
    REAR = newNode;
    FRONT = newNode;
  } else {
    newNode->next = FRONT;
    REAR->next = newNode;
    REAR = newNode;
  }
}
void dequeue() {
  if (isEmpty()) {
    printf("Queue is empty\n");
    return;
  }
  Node *temp = FRONT;
  if (FRONT == REAR) {
    FRONT = REAR = NULL;
  } else {
    FRONT = FRONT->next;
    REAR->next = FRONT;
  }
  printf("Value at Front: %d\n", temp->val);
  free(temp);
}
void peek() {
  if (isEmpty()) {
    printf("Queue Empty\n");
    return;
  }
  printf("Element at the Front: %d\n", FRONT->val);
}
int main() {
  int choice;
  while (true) {
    printf("1.Enqueue\n2.Dequeue\n3.Peek\n4.Exit\n");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      enqueue();
      break;
    case 2:
      dequeue();
      break;
    case 3:
      peek();
      break;
    case 4:
      printf("Exiting...");
      exit(0);
    default:
      printf("Invalid option\n");
    }
  }
}