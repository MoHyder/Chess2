#include "cell.h"
#include <iostream>
#include <string>
#include <vector>
#include "piece.h"
using namespace std;

void Cell::ping() {
  for (unsigned int x = 0; x < Observers.size(); x++) Observers[x]->ping();
};
void Cell::removeObserver(Piece *x) {
  for (unsigned int m = 0; m < Observers.size(); m++) {
    if (Observers[m] == x) {Observers.erase(Observers.begin() + m); return;}
  }
};

void Cell::addObserver(Piece *x) {
  Observers.push_back(x);
};

char Cell::getName() {
  if (piece == nullptr) {
    return (((cellname[0] + cellname[1] - 'a' - '0') % 2) == 1) ? '_' : ' ';
  } return piece->getName();
}

