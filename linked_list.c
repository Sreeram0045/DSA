#include <stdio.h>
#include <stdlib.h>
// created a typedef or alias for the struct
typedef struct node NODE;

struct node {
  int data;
  NODE *next;
};
// HEAD points to the first element of the linked list
NODE *HEAD = NULL;

// returns 0 if the value of HEAD is NULL otherwise 1
int isEmpty() { return HEAD == NULL; }
// If linkedlist is empty this function is called which in turn points head of
// the linked list to the first element which is newNode
void emptyLinkedList(NODE *newNode) {
  HEAD = newNode;
  newNode->next = NULL;
}
// a new node is created at the start where its next contains the current
// content of HEAD then HEAD is pointed towards the new node
void insertAtStart(NODE *newNode) {
  newNode->next = HEAD;
  HEAD = newNode;
}
// a new node is inserted according to the position specified by the user
void insertBetween(NODE *newNode) {
  int position, i = 1;
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
// a new node is inserted at the end
void insertAtEnd(NODE *newNode) {
  NODE *temp = HEAD;
  while (temp->next != NULL) {
    temp = temp->next;
  }
  temp->next = newNode;
  newNode->next = NULL;
}
// it is a caller function which calls other function based on conditionsdds
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
// Deletes the node at the beginning
void deleteAtBeginning() {
  NODE *temp = HEAD;
  HEAD = temp->next;
  free(temp);
}
// Deletes the node at a specified position
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
// Deletes the node at the end
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
// This is a caller function which calls delete functions based on certain
// conditions
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
// Prints the element each node stores in the linked list
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
// The function which runs the whole circus
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