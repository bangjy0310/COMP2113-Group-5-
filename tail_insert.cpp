#include <cstddef>
#include "tail_insert.h"
// This file is for inserting the guess into linked list storage

struct Node {
  char guess[4];
  Node * next;
};

void tail_insert(Node * &head, Node * &tail, char input[]) {
  Node * newGuess = new Node;
  for (int i = 0; i < 4; i++) {
    newGuess->guess[i] = input[i];
  }
  newGuess->next = NULL;

  // if start of list, create the list with this guess
  if (head == NULL) {
    head = newGuess;
    tail = newGuess;
  }

  // if not start of list, append this guess to last node of new list
  else {
    tail->next = newGuess;
    tail = newGuess;
  }

}
