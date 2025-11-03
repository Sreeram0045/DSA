#include <stdio.h>
#include <sys/types.h>
#define MAX 100
int arr[100];
int front = -1, rear = -1;
int isEmpty() {
  if (front == -1 && rear == -1) {
    return 1;
  }
  return 0;
}
int isFull() {
  if (rear == MAX - 1) {
    return 1;
  }
  return 0;
}
void enqueue(int num) {
  if (isEmpty()) {
    arr[++rear] = num;
    ++front;
  } else if (isFull()) {
    printf("Queue is full\n");
  } else {
    arr[++rear] = num;
  }
}
int dequeue() {
  if (isEmpty()) {
    printf("Queue underflow\n");
    return -1;
  }
  int val = arr[front++];
  if (front > rear) {
    front = rear = -1;
  }
  return val;
}
int main() {
  enqueue(10);
  enqueue(20);
  enqueue(30);
  enqueue(40);
  printf("Dequeued number is: %d\n", dequeue());
  printf("Dequeued number is: %d\n", dequeue());
  printf("Dequeued number is: %d\n", dequeue());
  printf("Dequeued number is: %d\n", dequeue());
  printf("Dequeued number is: %d\n", dequeue());
  return 0;
}