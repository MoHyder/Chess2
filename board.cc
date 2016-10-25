#include "board.h"
#include <iostream>
#include <string>
#include <sstream>
#include "piece.h"
#include "king.h"
#include "queen.h"
#include "bishop.h"
#include "knight.h"
#include "pawn.h"
#include "rook.h"
using namespace std;

// Board initialization
Board::Board() : WhiteMoves(), BlackMoves(), MovesStack(), Bking(nullptr), Wking(nullptr), whitecheck(false), blackcheck(false), blackPieces(), whitePieces() {
  for(char x = 'a'; x < 'i'; ++x) {
    for(char y = '0'; y < '8'; ++y) {
      int b = x - 'a';
	int bz = y - '0';
      layout[b][bz] = new Cell(string() + x + y);
    }
  }
}

void Board::setup() {
  string input;
  if (!(cin >> input)) return;
  //  print();
  if (input == string("game")) {
    // default board, return
    for (int x = 0; x < 8; x++) {
      editBoard('P',x,1);
      editBoard('p',x,6);
    }
    editBoard('R',0,0); editBoard('R',7,0); editBoard('r',0,7); editBoard('r',7,7);
    editBoard('N',1,0); editBoard('N',6,0); editBoard('n',1,7); editBoard('n',6,7);
    editBoard('B',2,0); editBoard('B',5,0); editBoard('b',2,7); editBoard('b',5,7);
    editBoard('Q',3,0); editBoard('K',4,0); editBoard('q',3,7); editBoard('k',4,7);
  } else {
    while (cin) {
      cout << "piece: " << input[0] <<  " at: " << input[1] << input[2] - '0' << endl;
      if (input == string("game")) {
//	cout << "TRYING TO START GAME" << endl;
        if ( Bking == nullptr || Wking == nullptr ) {
	  cout << "Must initialize Kings" << endl;
        } else {
	  break;
        }
      } else if (input.length() == 3) {
        editBoard(input[0], input[1] - 'a', input[2] - '0');
      }
	print();
      cin >> input;
    }
  }
  for (int x = 0; x < 8; x++) {
    for (int y = 0; y < 8; y++) {
//	cout << "checking " << x << y << endl;
      if (layout[x][y]->piece != nullptr) {
	layout[x][y]->piece->ping();
	(layout[x][y]->getName() > 'a') ? whitePieces.push_back(layout[x][y]->piece) : blackPieces.push_back(layout[x][y]->piece);
      }
    }
  }
  getmoves(true);
  getmoves(false);
  return;
}

// adds and removes piece from Board
bool Board::editBoard(char piece, int posX, int posY){
  if(posX > 7 || posY > 7 || posX < 0 || posY < 0) return false;
  if((piece == '-' && layout[posX][posY]->piece) || layout[posX][posY]->piece) {
    delete layout[posX][posY]->piece;
    layout[posX][posY]->piece = nullptr;        
  }
  // adding new pieces
  if(piece == 'K'){
    if (Bking != nullptr) {
      cout << "Black King already exists" << endl;
      return false;
    }
    bool moved = true;
    if(posX == 4 && posY == 0) moved = false;
    layout[posX][posY]->piece = new King(layout, layout[posX][posY],'K',moved);
    Bking = layout[posX][posY]->piece;
  } else if(piece == 'Q'){
    layout[posX][posY]->piece = new Queen(layout, layout[posX][posY],'Q');
  } else if(piece == 'B'){
    layout[posX][posY]->piece = new Bishop(layout, layout[posX][posY],'B');
  } else if(piece == 'N'){
    layout[posX][posY]->piece = new Knight(layout, layout[posX][posY],'N');
  } else if (piece == 'R'){
    bool moved = true;
    if((posX == 0 && posY == 0) || (posX == 7 && posY == 0)) moved = false;
    layout[posX][posY]->piece = new Rook(layout, layout[posX][posY],'R',moved);
  } else if(piece == 'P'){
    bool moved = true;
    if(posY == 1 ) moved = false;
    layout[posX][posY]->piece = new Pawn(layout, layout[posX][posY],'P',moved);
  } else if(piece == 'k'){
    if (Wking != nullptr) {
      cout << "White king already exists" << endl;
      return false;
    }
    bool moved = true;
    if(posX == 4 && posY == 7) moved = false;
    layout[posX][posY]->piece = new King(layout, layout[posX][posY],'k',moved);
    Wking = layout[posX][posY]->piece;
  } else if(piece == 'q'){
    layout[posX][posY]->piece = new Queen(layout, layout[posX][posY],'q');
  } else if(piece == 'b'){
    layout[posX][posY]->piece = new Bishop(layout, layout[posX][posY],'b');
  } else if(piece == 'n'){
    layout[posX][posY]->piece = new Knight(layout, layout[posX][posY],'n');
  } else if(piece == 'r'){
    bool moved = true;
    if((posX == 0 && posY == 7) || (posX == 7 && posY == 7)) moved = false;
    layout[posX][posY]->piece = new Rook(layout, layout[posX][posY],'r',moved);
  } else if(piece == 'p'){
    bool moved = false;
    if(posY != 6) moved = true;
    layout[posX][posY]->piece = new Pawn(layout, layout[posX][posY],'p',moved);
  } else return false;
  return true;
}


// check if either kings are in check

void Board::getmoves(bool white) {
  vector<Piece*>::iterator it;
  (white) ? it = whitePieces.begin() : it = blackPieces.begin();
  while (it != whitePieces.end() && it != blackPieces.end()) {
  //  cout << (*it)->getPos() << endl;
    string at = (*it)->getPos();
    // if the piece is under attack, moving it can put the king under attack
   // if ((*it)->Att()) {
      // check moves to see if they put KING under att
    //throw string("wat");
    //} else {
      for (vector<Cell*>::iterator moveto = (*it)->Observing.begin(); moveto != (*it)->Observing.end(); moveto++) {
	char spotname = (*moveto)->getName();
	string attackmove = at + (*moveto)->cellname;
	if (white && (! (spotname > 'a' && spotname < 'z'))) {
	    WhiteMoves.push_back(attackmove);
//	cout << attackmove << endl;
	} else if ((! white) && !(spotname > 'A' && spotname < 'Z')) {
	    BlackMoves.push_back(attackmove);
	}
      }
    //}
    it++;
  }
//  cout << "moves checked" << endl;
}

// The move function returns true if the move was done, (is in list of valid moves)
bool Board::move(int x1, int y1, int x2, int y2){
    // check vector of strings to see if this move is valid
  cout << x1 << y1 << x2 << y2 << endl;
  if (layout[x2][y2]->piece == nullptr) {
    layout[x2][y2]->piece = layout[x1][y1]->piece;
    layout[x1][y1]->piece = nullptr;
    layout[x2][y2]->piece->cell = layout[x2][y2];
    layout[x1][y1]->ping();
    layout[x2][y2]->piece->ping();
    layout[x2][y2]->ping();
  } else {
    layout[x2][y2]->piece->rmobs();
    delete layout[x2][y2]->piece;
    layout[x2][y2]->piece = layout[x1][y1]->piece;
    layout[x1][y1]->piece = nullptr;
    layout[x2][y2]->piece->cell = layout[x2][y2];
    layout[x1][y1]->piece->ping();
    layout[x2][y2]->piece->ping();
  }
  return true;
}

Board::~Board(){
  for(int x = 0; x < 8; ++x){
    for(int y = 0; y < 8; ++y){
      if(layout[x][y]) delete layout[x][y];
    }
  }
  Bking = nullptr;
  Wking = nullptr;
  blackPieces.clear();
  whitePieces.clear();
  WhiteMoves.clear();
  BlackMoves.clear();
  MovesStack.clear();
}
void Board::print() {
  for (int y = 0; y < 8; y++) {
    for (int x = 0; x < 8; x++) {
      cout << this->layout[x][y]->getName();
    }
    cout << std::endl;
  }
  return;
}

