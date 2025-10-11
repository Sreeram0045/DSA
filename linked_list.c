#include <stdio.h>
#include <stdlib.h>
typedef struct node NODE;

struct node {
  int data;
  NODE *next;
};

NODE *HEAD = NULL;
int isEmpty() { return HEAD == NULL; }
void emptyLinkedList(NODE *newNode) {
  HEAD = newNode;
  newNode->next = NULL;
}
void insertAtStart(NODE *newNode) {
  newNode->next = HEAD;
  HEAD = newNode;
}
void insertBetween(NODE *newNode) {
  int position, i = 1, flag = 0;
  NODE *curr = HEAD;
  printf("Enter the position: ");
  scanf("%d", &position);
  while (i < position && curr != NULL) {
    curr = curr->next;
    i++;
  }
  if (curr == NULL) {
    printf("The position you specified is not in the linked list\n");
    return;
  }
  newNode->next = curr->next;
  curr->next = newNode;
}
void insertAtEnd(NODE *newNode) {
  NODE *temp = HEAD;
  while (temp->next != NULL) {
    temp = temp->next;
  }
  temp->next = newNode;
  newNode->next = NULL;
}
void createNewNode() {
  int option, num;
  NODE *newNode = (NODE *)malloc(sizeof(NODE));
  printf("Enter the number to linked list: ");
  scanf("%d", &num);
  newNode->data = num;
  if (isEmpty()) {
    printf("Linked List is not initialized so inserting the new node at the "
           "beginning\n");
    emptyLinkedList(newNode);
    return;
  }
  printf(
      "Enter 1 for node at the start, 2 for in-between and 3 for at the end: ");
  scanf("%d", &option);
  if (option == 1) {
    insertAtStart(newNode);
  } else if (option == 2) {
    insertBetween(newNode);
  } else {
    insertAtEnd(newNode);
  }
}
void deleteAtBeginning() {
  NODE *temp = HEAD;
  HEAD = temp->next;
  free(temp);
}
void deleteAtPosition() {
  int position, i = 1, flag = 0;
  NODE *curr = HEAD;
  NODE *prev = NULL;
  printf("Enter the position: ");
  scanf("%d", &position);
  while (i < position && curr != NULL) {
    prev = curr;
    curr = curr->next;
    i++;
  }
  if (curr == NULL) {
    printf("Invalid position\n");
    return;
  }
  if (prev == NULL) {
    HEAD = curr->next;
  } else {
    prev->next = curr->next;
  }
  free(curr);
}
void deleteAtEnd() {
  if (HEAD->next == NULL) {
    free(HEAD);
    HEAD = NULL;
    return;
  }
  NODE *curr = HEAD;
  NODE *prev = NULL;
  while (curr->next != NULL) {
    prev = curr;
    curr = curr->next;
  }
  prev->next = NULL;
  free(curr);
}
void deleteNode() {
  int option;
  if (isEmpty()) {
    printf("Can't delete from the linked list because it is empty\n");
    return;
  }
  printf("Enter 1 to delete node at the beginning, 2 to delete in-between and "
         "3 for at the end: ");
  scanf("%d", &option);
  if (option == 1) {
    deleteAtBeginning();
  } else if (option == 2) {
    deleteAtPosition();
  } else if (option == 3) {
    deleteAtEnd();
  }
}
void traversal() {
  NODE *temp = HEAD;
  if (isEmpty()) {
    printf("There are no elements in the linked list\n");
    return;
  }
  printf("Elements of the linked list are: ");
  while (temp != NULL) {
    printf("%d\t", temp->data);
    temp = temp->next;
  }
  printf("\n");
}
void play() {
  int option;
  while (1) {
    printf("Enter 1. Insertion, 2.Deletion, 3.Traversal, 4.Exit\n");
    scanf("%d", &option);
    switch (option) {
    case 1:
      createNewNode();
      break;
    case 2:
      deleteNode();
      break;
    case 3:
      traversal();
      break;
    case 4:
      exit(0);
    }
  }
}
int main() { play(); }