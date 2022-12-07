// the following are functions and variables created for our main for mode 2

#include "PriorityLinkedList.h"
#include <stdio.h>

// creates priority linked list
List* Pcreate() {
    List* list = malloc(sizeof(List));
    list->head = list->tail = NULL;
    list->count = 0;
    return list;
}

// swaps elements in priority linked list
void Pswap(struct PNode* a, struct PNode* b) {
    struct PNode temp = *a;

    a->word = b->word;
    a->freq = b->freq;

    b->word = temp.word;
    b->freq = temp.freq;
}

// adds element to priority linked list
void Padd(List* list, char* word) {
    if (list->head == NULL) {
        struct PNode* new_node = malloc(sizeof(struct PNode));
        new_node->next = new_node->prev = NULL;
        new_node->freq = 1;
        new_node->word = word;
        list->head = list->tail = new_node;
        list->count = 1;
        return;
    }

    struct PNode* node = list->head;
    while (node != NULL) {
        if (strcmp(node->word, word) == 0) {
            node->freq++;
            while (node->prev != NULL) {
                if (node->freq <= node->prev->freq)
                    break;
                Pswap(node, node->prev);
                node = node->prev;  
            }
            return;
        }  
        node = node->next;  
    }

    if (list->count >= 5) {
        list->tail->word = word;
        list->tail->freq = 1;
        return;
    }

    struct PNode* new_node = malloc(sizeof(struct PNode));
    new_node->prev = list->tail;
    new_node->next = NULL;
    new_node->freq = 1;
    new_node->word = word;
    list->tail->next = new_node;
    list->tail = new_node;
    list->count++;
}

// displays elements in doubly linked list
void Pdisplay(List* list) {
    printf("[");
    struct PNode* node = list->head;
    while (node != NULL) {
        printf(" \"%s\"", node->word);
        node = node->next;   
    }
    printf(" ]");
}