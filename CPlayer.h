#ifndef CPlayer_h
#define CPlayer_h

#include "CPos.h"
#include "ConstantVar.h"

#include <iostream>
#include <Windows.h>
#include <string>
#include <conio.h>
#include <windows.h>
#pragma comment(lib, "winmm.lib")



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
	int getX();
	int getY();
	void xuatPos();
	void moveUp();
	void moveDown();
	void moveRight();
	void moveLeft();
	bool crash(CPos pos, int w, int h);
	void soundPlayer();
};

#endif