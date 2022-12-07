// this is the main of the program
#include "LinkedList.h"
#include "PriorityLinkedList.h"
#include <stdio.h>

int main(void) {
  printf("HI! WELCOME TO THE MEMORY GAME :)\n");
  printf("\n");

  int mode;
  printf("Enter the mode (1 or 2) = ");
  scanf("%d", &mode);
  printf("\n");
  char word[15];

  if (mode == 1) {
    int number;
    printf("Enter number of words to be stored in the word stream = ");
    scanf("%d%*c", &number);
    printf("\n");
    
    for (int i = 0; i < number; i++) {
      printf("Enter word %d = ", i+1);
      fgets(word,15,stdin);
      word[strcspn(word, "\n")] = 0;
      add(word);
    }

      display();
  }

  else if (mode == 2) {
    List* list = Pcreate();
    int number;
    printf("Enter number of words to be stored in the word stream = ");
    scanf("%d%*c", &number);
    printf("\n");
    
    for (int i = 0; i < number; i++) {
      printf("Enter word %d = ", i+1);
      fgets(word,15,stdin);
      word[strcspn(word, "\n")] = 0;
      Padd(list, word);
      Pdisplay(list);
      }
    Pdisplay(list);
  }

  else {
    printf("\n");
    printf("Invalid mode. Program terminated.");
    exit(1);
  }

}