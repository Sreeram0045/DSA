#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct Node Node;
struct Node {
  Node *prev;
  int val;
  Node *next;
};

Node *REAR = NULL;
Node *FRONT = NULL;
bool isEmpty() { return (FRONT == NULL) && (REAR == NULL); }
void enqueue_at_front() {
  int num;
  Node *newNode = (Node *)malloc(sizeof(Node));
  printf("Enter the number to insert: ");
  scanf("%d", &num);
  newNode->val = num;
  newNode->prev = NULL;
  if (isEmpty()) {
    newNode->next = NULL;
    FRONT = newNode;
    REAR = newNode;
  } else {
    newNode->next = FRONT;
    FRONT->prev = newNode;
    FRONT = newNode;
  }
}
void enqueue_at_rear() {
  int num;
  Node *newNode = (Node *)malloc(sizeof(Node));
  printf("Enter the number to insert: ");
  scanf("%d", &num);
  newNode->val = num;
  newNode->next = NULL;
  if (isEmpty()) {
    newNode->prev = NULL;
    FRONT = newNode;
    REAR = newNode;
  } else {
    newNode->prev = REAR;
    REAR->next = newNode;
    REAR = newNode;
  }
}
void dequeue_at_front() {
  if (isEmpty()) {
    printf("Queue Empty\n");
    return;
  }
  Node *temp = FRONT;
  printf("Dequeued element is: %d\n", temp->val);
  if (FRONT == REAR) {
    FRONT = REAR = NULL;
  } else {
    FRONT = FRONT->next;
    FRONT->prev = NULL;
  }
  free(temp);
}
void dequeue_at_rear() {
  if (isEmpty()) {
    printf("Queue Empty\n");
    return;
  }
  Node *temp = REAR;
  printf("Dequeued element is: %d\n", temp->val);
  if (FRONT == REAR) {
    FRONT = REAR = NULL;
  } else {
    REAR = REAR->prev;
    REAR->next = NULL;
  }
  free(temp);
}
void peek() {
  if (isEmpty()) {
    printf("Queue is empty\n");
    return;
  }
  printf("Element at front: %d\nElement at rear: %d\n", FRONT->val, REAR->val);
}
int main() {
  int choice;
  while (true) {
    printf("1.Enqueue at front\n2.Enqueue at rear\n3.Dequeue at "
           "front\n4.Dequeue at rear\n5.Peek\n6.Exit\n");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      enqueue_at_front();
      break;
    case 2:
      enqueue_at_rear();
      break;
    case 3:
      dequeue_at_front();
      break;
    case 4:
      dequeue_at_rear();
      break;
    case 5:
      peek();
      break;
    case 6:
      printf("Exiting...");
      exit(0);
    default:
      printf("Invalid option\n");
    }
  }
}