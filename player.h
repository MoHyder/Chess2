#ifndef _PLAYER_H_
#define _PLAYER_H_
#include <string>
#include "board.h"
using namespace std;

class Player {
protected:
	Board *b;
	bool white;;
public:	
	Player(Board * b, bool white): b{b}, white{white}{}
	virtual ~Player(){}
	virtual bool move() = 0;	
};

#endif
