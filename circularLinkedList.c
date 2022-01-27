/* Author: Layne Keegan
 * Course: CS 315
 * File: hw2.c
 * Purpose: circular linked list as a queue; insertion and deletion
 */
 
 #include <stdio.h>
 #include <stdlib.h>
 
typedef struct listItem {
  char value;
  struct listItem *next;
} LIST_ITEM;

void *insert(LIST_ITEM **q, char data);
void *delete(LIST_ITEM **q, int *count);

int main() {
  LIST_ITEM *q = NULL; 
  int count = 0;
  char option, data;
  while (option != 'q') {
    printf("Enter 'i' to insert, 'r' to remove, or 'q' to quit: ");
    scanf("%c", &option);
    getchar();
    if (option == 'i') {
      printf("What would you like to add? ");
      scanf("%c", &data);
      getchar();
      insert(&q, data);
      count += 1;
    } else if (option == 'r') {
      delete(&q, &count);
    } else if (option == 'q') {
      return 1;
    }
  }
  return 0;
}
 
void *insert(LIST_ITEM **q, char data) {
  LIST_ITEM *temp = (LIST_ITEM*)malloc(sizeof(LIST_ITEM));
  temp->value = data;
  if (*q == NULL) {
    temp->next = temp;
    (*q) = temp;
  } 
  else {
    temp->next = (*q)->next;
    (*q)->next = temp;
    (*q) = temp;
  }
}

void *delete(LIST_ITEM **q, int *count) {
  LIST_ITEM *tempdel = (LIST_ITEM*)malloc(sizeof(LIST_ITEM));
  if (*count > 0) {
    tempdel = (*q)->next;
    (*q)->next = tempdel->next;
    printf("You removed character '%c' from the list.\n", tempdel->value);
    free(tempdel);
    (*count)--;
  }
  else {
    printf("The queue is empty, nothing to remove.\n");
  }
}
