#include <stdio.h>
#define MAX 100

int arr[MAX];
int tos = -1;

void push(int el) {
  tos < MAX - 1 ? arr[++tos] = el : printf("Stack Overflow");
  return;
}
int pop() {
  if (tos < 0) {
    printf("Queue Underflow");
    return -1;
  }
  return arr[tos--];
}

int main() {
  push(10);
  push(20);
  push(30);
  printf("%d\t", pop());
  printf("%d\t", pop());
  printf("%d\n", pop());
  return 0;
}