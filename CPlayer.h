#ifndef CPlayer_h
#define CPlayer_h
#include "Header.h"
#include "CPos.h"

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

	//return sth
	char** kind();
	CPos getPos();
	int getW();
	int getH();
};

#endif