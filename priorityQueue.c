#include <limits.h>
#include <stdio.h>
#define MAX 100
typedef struct queue queue;

struct queue {
  int number;
  int priority;
};

queue array[MAX];
int global_size = -1;

void enqueue(int number, int priority) {
  if (global_size == MAX - 1) {
    printf("Queue Overflow\n");
    return;
  }
  global_size += 1;
  array[global_size].number = number;
  array[global_size].priority = priority;
  printf("Element inserted\n");
}
int peek() {
  if (global_size == -1) {
    return -1;
  }
  int MAX_priority = INT_MIN;
  int index = 0;
  for (int i = 0; i <= global_size; i++) {
    if (array[i].priority > MAX_priority) {
      MAX_priority = array[i].priority;
      index = i;
    }
  }
  // printf("Element having highest priority: %d\n", array[index].number);
  return index;
}
void peekcaller() {
  int index = peek();
  if (index == -1) {
    printf("Queue is empty");
  }
  printf("Element having highest priority: %d\n", array[index].number);
}
void dequeue() {
  if (global_size == -1) {
    printf("Queue Underflow\n");
    return;
  }
  int index = peek();
  printf(
      "Node containing the element having the highest priority is deleted\n");
  for (int i = index; i <= global_size; i++) {
    array[i].number = array[i + 1].number;
    array[i].priority = array[i + 1].priority;
  }
  --global_size;
}
void display() {
  if (global_size == -1) {
    printf("Queue is empty\n");
    return;
  }
  for (int i = 0; i <= global_size; i++) {
    printf("Element: %d\tPriority: %d\n", array[i].number, array[i].priority);
  }
}
int main() {
  display();
  enqueue(9, 10);
  enqueue(10, 5);
  enqueue(11, 30);
  enqueue(12, 10);
  display();
  dequeue();
  display();
  dequeue();
  display();
  dequeue();
  display();
  dequeue();
  enqueue(12, 10);
  display();
  dequeue();
}