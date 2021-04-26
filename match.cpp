#include <iostream>
#include "match.h"
using namespace std;
// this file is used to:
// 1. match guess with the correct answer
// 2. change win flag if needed
// 3. output correct flags

void match(char guess[], char answer[], char flag[], bool &win){
  int redflag = 0;
  int whiteflag = 0;
  char tempGuess[4] = {'A', 'A', 'A', 'A'};
  char tempAns[4] = {'A', 'A', 'A', 'A'};

  for (int i = 0; i < 4; i++) {
    tempGuess[i] = guess[i];
    tempAns[i] = answer[i];
  }

  //checking for red flag
  for(int i=0; i<4; i++){
    if(tempGuess[i]==tempAns[i]){
      tempGuess[i] = 'X';
      tempAns[i] = 'Z';
      redflag++;
    }
  }

  //checking for white flag
  for(int i=0; i<4; i++){
    for(int j=0; j<4; j++){
      if(tempGuess[i]==tempAns[j]){
        tempGuess[i] = 'K';
        tempAns[j] = 'W';
        whiteflag++;
      }
    }
  }

  if(redflag == 4) {
    win = true;
  }


  if (redflag != 0){
    for(int i = 0; i < redflag; i++){
      flag[i] = 'R';
    }
  }

  if (whiteflag != 0){
    for(int i = 0; i < whiteflag; i++){
      flag[i+redflag] = 'W';
    }
  }

}
