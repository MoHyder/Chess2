#ifndef __BISHOP_H__
#define __BISHOP_H__
#include "piece.h"
#include <string>
#include <vector>

class Bishop: public Piece{
public:	
  Bishop(Cell * (&board)[8][8], Cell * cell, char name) : Piece(board,cell,name) {}
  void ping() {
    rmobs();
    int x = getX() + 1;
    int y = getY() + 1;
    while (x <= 7 && y <= 7) {
      if (chessboard[x][y]->piece != nullptr) {
	Observing.push_back(chessboard[x][y]);
	break;
      }
      Observing.push_back(chessboard[x][y]);
      x++;
      y++;
    }
    x = getX() + 1;
    y = getY() - 1;
    while (x <= 7 && y >= 0) {
      if (chessboard[x][y]->piece != nullptr) {
        Observing.push_back(chessboard[x][y]);
        break;
      }
      Observing.push_back(chessboard[x][y]);
      x++;
      y--;
    }
    x = getX() - 1;
    y = getY() - 1;
    while (x >=0 && y >= 0) {
      if (chessboard[x][y]->piece != nullptr) {
        Observing.push_back(chessboard[x][y]);
        break;
      }
      Observing.push_back(chessboard[x][y]);
      x--;
      y--;
    }
    x = getX() - 1;
    y = getY() + 1;
    while (x >= 0 && y <= 7) {
      if (chessboard[x][y]->piece != nullptr) {
        Observing.push_back(chessboard[x][y]);
        break;
      }
      Observing.push_back(chessboard[x][y]);
      x--;
      y++;
    }
    vector<Cell *>::iterator it;
    it = Observing.begin();
    while (it != Observing.end()) {
      (*it)->Observers.push_back(this);
      it++;
    }
  }
  ~Bishop(){
  }
};

#endif
