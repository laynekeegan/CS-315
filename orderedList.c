/* Author: Layne Keegan
 * Course: CS 315
 * File: hw1.c
 * Purpose: ordered list - deletion, traversal, insertion
 */
 
#include <stdio.h>
#include <stdlib.h>

typedef struct listItem {
  int value;
  struct listItem *next;
} LIST_ITEM;

int printList(LIST_ITEM *start);

int main() {
  LIST_ITEM *start = NULL;
  LIST_ITEM *temp, *prev, *next, *delPtr;
  int valueDelete = 1;
   while (temp->value != 0) {
    temp = malloc(sizeof(LIST_ITEM));
    printf("Enter an integer: ");
    scanf("%d", &(temp->value));
    temp->next = NULL;
    if (temp->value == 0)
      break;
    /*INSERT IN ORDER*/
    if (start == NULL) {
      start = temp;
    } else {
    next = start;
    prev = NULL;
    while (next != NULL && next->value < temp->value) {
        prev = next;
        next = next->next;
    }
    if (next == NULL) {
      prev->next = temp;
    } else {
        if(prev != NULL) {
          temp->next = prev->next;
          prev->next = temp;
        } else {
          temp->next = start;
          start = temp;
        }
    }
    }
   }
   printList(start);
  /*TRAVERSE LIST AND DELETE ITEM*/
  while (valueDelete != 0) {
    printf("What do you want to delete? ");
    scanf("%d", &valueDelete);
    if (start->value == valueDelete)
      start = start->next;
    if (valueDelete == 0 || start == NULL) {
      printf("Goodbye.\n");
      return 1;
    }
    else {
      delPtr = start;
      while ((delPtr->next != NULL) && (delPtr->next)->value != valueDelete)
        delPtr = delPtr->next;
      if (delPtr->next == NULL)
        printf("Can't find %d in the list.\n", valueDelete);
      else
        delPtr->next = (delPtr->next)->next;
    }
    printList(start);
  }
  return 0;
}

int printList(LIST_ITEM *start) {
  LIST_ITEM *trvPtr;
  trvPtr = start;
  if (trvPtr == NULL) {
    printf("Your list is empty.\n");
    exit(1);
  }
  printf("Ok, here's your list in numeric order: ");
  while (trvPtr != NULL) {
    printf("%d ", trvPtr->value);
    trvPtr = trvPtr->next;
  }
  printf("\n");
  return 0;
}
