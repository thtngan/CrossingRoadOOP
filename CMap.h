#pragma once
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <windows.h>
#include <conio.h>
#include "CPlayer.h"
#include "CObject.h"
#include "CCar.h"
#include "CLines.h"

using namespace std;

class CMap
{
private:
	char _map[200][200];
	const int _width = 60, _height = 20;
	CPlayer _player;
	CLines _lines;

public:
	CMap();
	~CMap() = default;
	void printBorders();
	bool Print(CPos pos, char** kind, int h, int w); //height and width of thing to print
	void printPlayer(); //draw player 
	void printObject(CObject *); //draw another object
	void printMap();
	void init();
};
