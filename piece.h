#ifndef __PIECE_H__
#define __PIECE_H__
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include "cell.h"
using namespace std;

class Piece {
  public:
  Cell* chessboard[8][8];
  Cell* cell;
  const char name;
  vector<Cell*> Observing;
  Piece(Cell * (&board)[8][8], Cell * cell, char name) : cell(cell), name(name) {
    for(int x = 0; x < 8; x++) 
      for (int y=0;y<8;y++)
	this->chessboard[x][y] = board[x][y];
  }
  int getX(){return cell->cellname[0] - 'a';}
  int getY(){return cell->cellname[1] - '0';}
  string getPos() {return cell->cellname;}
  bool white(){return (name <= 'z' && name >= 'a');}
  char getName(){return name;}
// ping is part of the move function to write.
// when a Piece is pinged it will first remove itself from all Observers
// then add itself back to it's new ones
// the next function is validmove, which tries to move to Observed spots. If it can, 
// then it will ping opposing pieces affected by the move. 
// if this doesn't make the king observed, it's a valid move.
  virtual void ping() = 0;
  virtual ~Piece(){};
// void remove observers
  void rmobs() {
    vector<Cell*>::iterator it;
    it = Observing.begin();
    while ( it != Observing.end()) {
      vector<Piece*>::iterator it2;
      it2 = (*it)->Observers.begin();
      while ( it2 != (*it)->Observers.end()) {
	if (*it2 == this) {
	  (*it)->Observers.erase(it2);
	  break;
	} else it2++;
      }
      it++;
    }
    Observing.clear();
  }
  bool Att() {
    bool white = (name > 'a');
    for (vector<Piece*>::iterator Obs = cell->Observers.begin(); Obs != cell->Observers.end(); ++Obs) {
      if (white) {
	if ( (*Obs)->getName() < 'Z') return true;
      } else {
	if ( (*Obs)->getName() > 'a') return true;
      }
    }
    return false;
  }
};
#endif
