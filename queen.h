#ifndef __QUEEN_H__
#define __QUEEN_H__
#include "piece.h"
#include <string>
#include <vector>

class Queen: public Piece{
public:	
  Queen(Cell * (&board)[8][8], Cell * cell, char name) : Piece(board,cell,name) {}
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
    x = getX() - 1;
    y = getY();
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
  ~Queen(){
  }
};

#endif
