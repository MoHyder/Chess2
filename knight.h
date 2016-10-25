#ifndef __KNIGHT_H__
#define __KNIGHT_H__
#include "piece.h"
#include <string>
#include <vector>

class Knight: public Piece{
public:	
  Knight(Cell * (&board)[8][8], Cell * cell, char name) : Piece(board,cell,name) {}
  void ping() {
    rmobs();
    int x = getX();
    int y = getY();
    if ((x - 1) >= 0) {
	if ((y - 2) >= 0) Observing.push_back(chessboard[y-2][x-1]);
	if ((y + 2) <= 7) Observing.push_back(chessboard[y+2][x-1]);
    }
    if ((x - 2) >= 0) {
	if ((y - 1) >= 0) Observing.push_back(chessboard[y-1][x-2]);
	if ((y + 1) <= 7) Observing.push_back(chessboard[y+1][x-2]);
    }
    if ((x + 1) <= 7) {
        if ((y - 2) >= 0) Observing.push_back(chessboard[y-2][x+1]);
        if ((y + 2) <= 7) Observing.push_back(chessboard[y+2][x+1]);
    }
    if ((x + 2) <= 7) {
        if ((y - 1) >= 0) Observing.push_back(chessboard[y-1][x+2]);
        if ((y + 1) <= 7) Observing.push_back(chessboard[y+1][x+2]);
    }
    vector<Cell *>::iterator it;
    it = Observing.begin();
    while (it != Observing.end()) {
      (*it)->Observers.push_back(this);
      it++;
    }
  }
  ~Knight(){
  }
};

#endif
