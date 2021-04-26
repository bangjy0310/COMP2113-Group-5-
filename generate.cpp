#include <iostream>
#include <iomanip>
#include "generate.h"
using namespace std;

void generate(char answer[]) {
  char converter[6] = {'R','B','G','Y','P','O'};
  srand(time(NULL));
  answer[0] = converter[rand() % 6];
  answer[1] = converter[rand() % 6];
  answer[2] = converter[rand() % 6];
  answer[3] = converter[rand() % 6];

}
