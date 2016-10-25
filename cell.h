#ifndef __CELL_H
#define __CELL_H
#include <string>
#include <vector>

using namespace std;

class Piece;

class Cell {
  public:
  string cellname;
  Piece *piece;
  vector< Piece *> Observers;
  Cell(string cellname) : cellname(cellname), piece(nullptr) {}
  char getName();
  void ping();
  void addObserver(Piece *x);
  void removeObserver(Piece *x);
};

#endif
