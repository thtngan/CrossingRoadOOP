#ifndef CPlayer_h
#define CPlayer_h

#include "CPos.h"
#include "ConstantVar.h"

class CPlayer
{
private:
	CPos _pos;
	char** _player;
	int _type; //type of player

public:
	CPlayer(); //player at position default
	void Draw(const int);
	~CPlayer();

	void setType(const int& t) {
		this->_type = t;
	}

	//return sth
	char** kind();
	CPos getPos();
	int getW();
	int getH();
	void xuatPos();
	void moveUp();
	void moveDown();
	void moveRight();
	void moveLeft();
};

#endif