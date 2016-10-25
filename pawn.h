#ifndef __PAWN_H__
#define __PAWN_H__
#include "piece.h"
#include <string>
#include <vector>

class Pawn: public Piece{
public:	
  bool moved;
  Pawn(Cell * (&board)[8][8], Cell * cell, char name, bool moved = false) : Piece(board,cell,name), moved(moved) {}
  void ping() {
    rmobs();
    int x = getX();
    int y = getY();
    bool white = (name > 'a');
    white ? y-- : y++;
    if ((x - 1) >= 0) Observing.push_back(chessboard[x-1][y]);
    if ((x + 1) <= 7) Observing.push_back(chessboard[x+1][y]);
    Observing.push_back(chessboard[x][y]);
    vector<Cell *>::iterator it;
    it = Observing.begin();
    while (it != Observing.end()) {
      (*it)->Observers.push_back(this);
      it++;
    }
  }
  ~Pawn(){
  }
};

#endif
