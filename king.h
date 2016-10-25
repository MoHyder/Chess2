#ifndef __KING_H__
#define __KING_H__
#include "piece.h"
#include <string>
#include <vector>
#include <iostream>

class King: public Piece{
public:	
  bool moved;
  King(Cell * (&board)[8][8], Cell * cell, char name, bool moved = false) : Piece(board,cell,name), moved(moved) {}
  void ping() {
    rmobs();
    int x = getX();
    int y = getY();
    if ((x + 1) <= 7) {
	if ((y - 1) >= 0) Observing.push_back(chessboard[x+1][y- 1]);
	if ((y + 1) <= 7) Observing.push_back(chessboard[x+1][y+ 1]);
	Observing.push_back(chessboard[x+1][y]);
    }
    if ((x - 1) >= 0) {
	if ((y - 1) >= 0) Observing.push_back(chessboard[x-1][y-1]);
	if ((y + 1) <= 7) Observing.push_back(chessboard[x-1][y+1]);
	Observing.push_back(chessboard[x-1][y]);
    }
    if ((y - 1) >= 0) Observing.push_back(chessboard[x][y-1]);
    if ((y + 1) <=7) Observing.push_back(chessboard[x][y+1]);
    vector<Cell *>::iterator it;
    it = Observing.begin();
//cout << name << " is on" << cell->cellname << x << y << endl;
    while (it != Observing.end()) {
//    cout << name << " is attacking " <<(*it)->cellname << endl;
      (*it)->Observers.push_back(this);
      it++;
    }
  }
  ~King(){
  }
};

#endif
