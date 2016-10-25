#ifndef __ROOK_H__
#define __ROOK_H__
#include "piece.h"
#include <string>
#include <vector>

class Rook: public Piece{
public:	
  bool moved;
  Rook(Cell * (&board)[8][8], Cell * cell, char name, bool moved) : Piece(board,cell,name), moved(moved) {}
  void ping() {
    rmobs();
    int x = getX() - 1;
    int y = getY();
    while (x >= 0) {
	if (chessboard[x][y]->piece != nullptr) {
        Observing.push_back(chessboard[x][y]);
        break;
      }
      Observing.push_back(chessboard[x][y]);
      x--;
    }
    x = getX() + 1;
    while (x <= 7) {
        if (chessboard[x][y]->piece != nullptr) {
        Observing.push_back(chessboard[x][y]);
        break;
      }
      Observing.push_back(chessboard[x][y]);
      x++;
    }
    x = getX();
    y = getY() - 1;
    while (y >= 0) {
        if (chessboard[x][y]->piece != nullptr) {
        Observing.push_back(chessboard[x][y]);
        break;
      }
      Observing.push_back(chessboard[x][y]);
      y--;
    }
    y = getY() + 1;
    while (y <= 7) {
        if (chessboard[x][y]->piece != nullptr) {
        Observing.push_back(chessboard[x][y]);
        break;
      }
      Observing.push_back(chessboard[x][y]);
      y++;
    }

    vector<Cell *>::iterator it;
    it = Observing.begin();
    while (it != Observing.end()) {
      (*it)->Observers.push_back(this);
      it++;
    }
  }
  ~Rook(){
  }
};

#endif
