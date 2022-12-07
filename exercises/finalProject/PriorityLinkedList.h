// the following is a header file that declares available functions and structures for our priority linked list

#ifndef PRIORITYLINKEDLIST_H
#define PRIORITYLINKEDLIST_H

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// node and list structures
typedef struct Node Node;

struct PNode {
    char* word;
    int freq;
    struct PNode* next;
    struct PNode* prev;
};

typedef struct {
    struct PNode* head;
    struct PNode* tail;
    size_t count;
} List;

// function declarations
List* Pcreate();
void Pswap(struct PNode* a, struct PNode* b);
void Padd(List* list, char* word);
void Pdisplay(List* list);

#endif