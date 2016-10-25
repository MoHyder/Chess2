#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "board.h"
#include "piece.h"
#include "player.h"
#include "human.h"
//#include "comp.h"

using namespace std;

int main() {
  string input;
  Player *white;
  Player *black;
  Board *b = new Board();
  bool whiteturn = true;
  int whitescore = 0;
  int blackscore = 0;
  cout << "Enter P1 Options: human OR comp" << endl;
  while (cin >> input) {
  if (input == "human") {
    white = new Human(b, true);
    break;
  } else if (input == "comp") {
//	white = new Comp(&board, true);
    break;
  } else cout << "Enter human or comp for player 1" << endl;
  }
  cout << "Enter P2 Options: humand OR comp" << endl;
  while (cin >> input) {
    if (input == "human") {
        black = new Human(b, false);
	break;
    } else if (input == "comp") {
//        black = new Comp(&board, false);
      break;
    } else cout << "Enter human or comp for player 2" << endl;
  }
  //while (true) {
    cout << "PLEASE ENTER setup OR game OR stop" << endl;
    cout << "setup: To setup custom board" << endl;  	
    cout << "game: To start game" << endl;
    b->setup();
    try {
      while (true) {
	b->print();
	b->getmoves(whiteturn);
	if (whiteturn) {
	  if (white->move() == false) throw string("black");
	  whiteturn = false;
        } else {
	  if (black->move() == false) throw string("white");
	  whiteturn = true;
        }
      }
    } 
    catch (const string &winner) {
	cout << winner << endl;
//	break;
    }
  //}
  cout << "Final Score" << endl;
  cout << "White: " << whitescore << endl;
  cout << "Black: " << blackscore << endl;
  if(white) delete white;
  if(black) delete black;
  delete b;	
  return 0;
}
