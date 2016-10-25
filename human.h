#ifndef _HUMAN_H_
#define _HUMAN_H_
#include <iostream>
#include <string>
#include "player.h"
#include "board.h"
using namespace std;
class Human: public Player {
  public:
  bool move() {
    cout << "Enter a move:" << endl;
    string command;
    while (cin >> command) {
//      cout << command << endl;
      if (command == "resign") {
        if (white) throw string("black wins");
        throw string("white wins");
      }
      if (command.length() == 4) {
	int x1 = command[0] - 'a';
	int y1 = command[1] - '0';
	int x2 = command[2] - 'a';
	int y2 = command[3] - '0';
	if (x1 < 0 || y1 < 0 || x2 < 0 || y2 < 0 || x1 > 7 || y1 > 7 || x2 > 7 || y2 > 7) {
	  cout << "input not valid must be of the form a0c7";
 	} else {
	  vector<string> moves;
	  if (white == true) moves = b->WhiteMoves;
	  else moves = b->BlackMoves;
//	cout << "list of valid moves: " << endl;
	  for (vector<string>::iterator it = moves.begin(); it != moves.end(); it++) {
//	    cout << *it << endl;
	    if (command == *it) {
		b->move(x1, y1, x2, y2); 
		return true;
	    }
	  }
	  cout << "input isn't listed as a possible move, try again" << endl;
	}
      }
    }
    return false;
  }
  Human(Board *b, bool colour): Player(b, colour) {}
  ~Human(){}
};

#endif
