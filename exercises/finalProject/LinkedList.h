// the following is a header file that declares available functions and structures for our linked list

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// node structure
struct node {
   char *word;
   struct node *next;
   struct node *prev;
};

// function declarations
int length();
bool isEmpty();
void deleteLast();
void insertFirst(char *word);
void add(char *word);
void display();

#endif