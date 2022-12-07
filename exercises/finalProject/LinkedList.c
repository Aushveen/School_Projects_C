// the following are functions and variables created for our main for mode 1

#include "LinkedList.h"
#include <stdio.h>

// points to first node
struct node *head = NULL;

// points to last node
struct node *last = NULL;

// points to current node
struct node *current = NULL;

// computes length of linked list
 int length() {
   int length = 0;
   struct node *current;
	
   for(current = head; current != NULL; current = current->next){
      length++;
   }
	
   return length;
}
 
// returns true if linked list is empty and false otherwise
bool isEmpty() {
  if (head == NULL) {
    return true;
  }
    
  else {
    return false;
  }
}

// deletes last element in linked list
void deleteLast() {
  struct node *tempLink = last;
  
  if (isEmpty()) {
    
  }

  else if (head->next == NULL) {
      head = NULL;
  } 
   
  else {
      last->prev->next = NULL;
  }

  last = last->prev;
}

// adds element to the beginning of linked list
void insertFirst(char *word) {

   struct node *link = (struct node*) malloc(sizeof(struct node));
   link->word = malloc(sizeof(char) * 15);
  strcpy(link->word, word);

   if (isEmpty()) {
      link->prev = NULL;
      last = link;
   } 
   
   else {
      head->prev = link;
   }

   link->next = head;

   head = link;
}

// adds element to the beginning of linked list and deletes element if it appears later while keeps elements at 5 or below
void add(char *word) {
  struct node *ptr = head;

  while(ptr != NULL) {
      if (strcmp(ptr->word, word) == 0) {
        ptr->next->prev = ptr->prev;
          ptr->prev->next = ptr->next;
          free(ptr);
        break;
      }

    
      ptr = ptr->next;
   }

  insertFirst(word);
  
  if (length() > 5) {
    deleteLast();
  }
}

// displays linked list in its entirety
void display() {

   struct node *ptr = head;

   printf("\n[ ");

   while(ptr != NULL) {
      printf("\"%s\" ",ptr->word);
      ptr = ptr->next;
   }

   printf("]");
}