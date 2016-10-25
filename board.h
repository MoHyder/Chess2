#ifndef __BOARD_H
#define __BOARD_H
#include "piece.h"
#include "cell.h"
#include <vector>
#include <string>
#include <iostream>
using std::ostream;
class Board {
public:
  std::vector<std::string> WhiteMoves;
  std::vector<std::string> BlackMoves;
  std::vector<std::string> MovesStack;
  Piece *Bking;
  Piece *Wking;
  bool whitecheck;
  bool blackcheck;
  Cell *layout[8][8];
// king should always be first in vector
  std::vector <Piece *> blackPieces;
  std::vector <Piece *> whitePieces;
// functions
  Board();
  bool editBoard(char piece, int posX, int posY);
  bool move(int x1, int y1, int x2, int y2);
  void setup();
  void print();
  void getmoves(bool turn);
  ~Board();
};
#endif
