// game_main.cpp
// THis is the main file of the game - Mastermind can be played by executing this file
#include <iostream>
#include <string>
#include <fstream>
// for Makefile purposes
#include "generate.h"
#include "print_grid.h"
#include "tail_insert.h"
#include "match.h"
using namespace std;

struct Node {
  char guess[4];
  Node * next;
};

int main() {
  Node * head = NULL, * tail = NULL;
  Node * flagHead = NULL, * flagTail = NULL;
  char answer[4] = {'A', 'B', 'C', 'D'};
  char flag[4] = {'-', '-', '-', '-'};
  int guessCount;

  // instructions on home screen
  cout << "Welcome to Mastermind!" << endl;
  cout << "Please type \"PLAY\" to start the game," << endl;
  cout << "or type \"INSTRUCTIONS\" to learn the rules of the game!" << endl;
  cout << "Enjoy!" << endl;
  cout << endl;

  // taking user input at home screen
  string intention;
  cin >> intention;
  if (intention == "PLAY") {
    // ask whether to load existing game or start new game
    cout << endl;
    cout << "Do you want to start a new game?" << endl;
    cout << "YES for new game, NO to open an existing game" << endl;
    cin >> intention;

    // if answer is NO, construct linked list from savefile guesses
    if (intention == "NO") {
       char filename[100] = "saveFile.txt";
       ifstream fin;
       fin.open(filename);

       if (fin.fail()) {
         cout << "You don't have a savefile. Please restart the game with a new game." << endl;
         exit(1);
       }
       fin >> guessCount; // (1) guess no.
       for (int i = 0; i < 4; i++) {
         fin >> answer[i];  // (2) answer array
       }

       Node * genGuess = new Node; // building new lists
       Node * genFlag = new Node;
       fin >> genGuess->guess[0] >> genGuess->guess[1] >> genGuess->guess[2] >> genGuess->guess[3]; // building head of new lists from savefile
       fin >> genFlag->guess[0] >> genFlag->guess[1] >> genFlag->guess[2] >> genFlag->guess[3];
       genGuess->next = NULL;
       genFlag->next = NULL;
       head = genGuess;
       tail = genGuess;
       flagHead = genFlag;
       flagTail = genFlag;

       int count = 1;
       while (count != guessCount) {
         for (int j = 1; j < guessCount; j++) {
           Node * genGuess = new Node;
           Node * genFlag = new Node;
           fin >> genGuess->guess[0] >> genGuess->guess[1] >> genGuess->guess[2] >> genGuess->guess[3]; // adding onto list
           fin >> genFlag->guess[0] >> genFlag->guess[1] >> genFlag->guess[2] >> genFlag->guess[3];
           genGuess->next = NULL;
           genFlag->next = NULL;
           tail->next = genGuess;
           tail = genGuess;
           flagTail->next = genFlag;
           flagTail = genFlag;
           count++;
         }
       }
       fin.close();
    }
    else if (intention == "YES"){
      guessCount = 0;
      generate(answer); // generates a random game state
    }
    cout << endl;
    cout << "Enter your guesses in this format: " << endl;
    cout << "1 2 3 4" << endl;
    cout << "where each number is the code for a colour." << endl;
    cout << "You can type \"S\" during guess input to save your game," << endl;
    cout << "but please do not save when you have not made a guess." << endl;
    cout << "Saving will end your game." << endl;
    cout << endl;
    cout << "Key:" << endl;
    cout << "\"R\" for Red, \"B\" for Blue, \"G\" for Green" << endl;
    cout << "\"Y\" for Yellow, \"P\" for Purple, \"O\" for Orange" << endl;
    cout << endl;
    cout << "P.S. Don't forget, position matters!" << endl;


    // IN GAME
    char input[4];
    bool win = false;
    while (guessCount < 12 && win == false) {

      // step 1: printing grid
      print_grid(head, flagHead, guessCount);

      // step 2: taking user guess
      cout << "Guesses: " << guessCount << " / 12" << endl;
      cout << "Insert Your Guess: " << endl;
      for (int i = 0; i < 4; i++) { // save function
        cin >> input[i];
        if (input[i] == 'S') {
          // saves both linked lists' data in full written form
          Node * saveGuess = head;
          Node * saveFlag = flagHead;

          ofstream fout;
          fout.open("saveFile.txt");

          if (fout.fail()) {
            cout << "Error in saving file. Try again." << endl;
          }

          fout << guessCount << endl; // (1) guess no.

          for (int j = 0; j < 4; j++) { // (2) answer
            fout << answer[j] << " ";
          }
          fout << endl;

          for (int i = 0; i < guessCount; i++) { // (3) all guesses and corresponding flags
            fout << saveGuess->guess[0] << " " << saveGuess->guess[1] << " " << saveGuess->guess[2] << " " << saveGuess->guess[3] << " " << endl;
            fout << saveFlag->guess[0] << " " << saveFlag->guess[1] << " " << saveFlag->guess[2] << " " << saveFlag->guess[3] << " " << endl;
            saveGuess = saveGuess->next;
            saveFlag = saveFlag->next;
          }
          fout.close();
          exit(1);
        }
      }

    // step 3: adding it to linked list for storage (saving purposes)
      tail_insert(head, tail, input);

    // step 4: matching function
      match(input, answer, flag, win);
      tail_insert(flagHead, flagTail, flag);
      for (int i = 0; i < 4; i++) {
        flag[i] = '-';
      }
      guessCount++;

      //step 5: checking if win condition is met
      if (win == true) {
        cout << "Congratulations! You have found the solution: " << endl;
        cout << "[ ";
        for (int j = 0; j < 4; j++) {
          cout << answer[j] << " ";
        }
        cout << "]" << endl;
        cout << "Guesses taken: " << guessCount << endl;
        exit(1);
    }

    }
    if (win == false) {
      cout << "Game Over. The correct Solution was: " << endl;
      cout << "[ ";
      for (int j = 0; j < 4; j++) {
        cout << answer[j] << " ";
      }
      cout << "]" << endl;
      cout << "Guesses taken: " << guessCount << endl;
      exit(1);
    }

  }

  else if (intention == "INSTRUCTIONS") {
    cout << "Game Instruction" << endl;
  cout << "Step 1: The game will randomly generate four coloured pins." << endl;
  cout << "Step 2: The codebreaker would have to guess all the pins' respective order and colour to win the game." << endl;
  cout << "Step 3: There will be a total of 12 guess attempts." << endl;
  cout << "Step 3: Each guess with both the correct order and the colour of the pins would return a red flag." << endl;
  cout << "Step 4: Each guess with the wrong order, but the correct colour of the pins would return a white flag." << endl;
  cout << "Step 5: Each guess with both incorrect order and colour of the pins would return a dash." << endl;
  cout << "Step 6: Failure to guess the correct pins within 12 attempts would result in a loss." << endl;
  }
  return 0;
}
