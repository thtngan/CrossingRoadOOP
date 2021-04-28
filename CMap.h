#pragma once
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <windows.h>
#include <conio.h>
#include "CPlayer.h"
#include "CObject.h"
#include "CBird.h"
#include "CLines.h"

using namespace std;

class CMap
{
private:
	char _map[200][200];
	const int _width = 130, _height = 37;
	CPlayer _player;
	CLines _lines;
	int t = 0;
public:
	CMap();
	~CMap() = default;
	void printBorders();
	bool Print(CPos pos, char** kind, int h, int w); //height and width of thing to print
	void printPlayer(); //draw player 
	void printObject(CObject *); //draw another object
	void printInstruct();
	void printMap();
	void move();
	bool delPlayer(CPos pos, char** kind, int h, int w); //height and width of thing to del
	void init();
	void random();
};
