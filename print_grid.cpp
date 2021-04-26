#include <iostream>
#include "print_grid.h"
using namespace std;

// This file is for printing the grid

struct Node {
  char guess[4];
  Node * next;
};

void print_grid(Node * head, Node * flagHead, int guessCount) {
  Node * current = head;
  Node * flagCurrent = flagHead;
  cout << endl;
  cout << endl;
  cout << endl;
  cout << "  GUESSES    FLAGS   " << endl;
  cout << "---------------------" << endl;
  for (int i = 0; i < guessCount; i++) {
    cout << "| " << current->guess[0] << " " << current->guess[1] << " " << current->guess[2] << " " << current->guess[3]
    << " | " << flagCurrent->guess[0] << " " << flagCurrent->guess[1] << " " << flagCurrent->guess[2] << " " << flagCurrent->guess[3]
    << " |  Guess " << i + 1 << endl;
    current = current->next;
    flagCurrent = flagCurrent->next;
  }
    cout << "---------------------" << endl;
    cout << "Key: R = Red, B = Blue, G = Green, Y = Yellow, P = Purple, O = Orange" << endl;
    cout << "Flag: R = right position and colour, W = right colour but wrong colour" << endl;


}
