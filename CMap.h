#pragma once
#include "Header.h"
#include "CPlayer.h"

class CMap
{
private:
	char _map[200][200];
	const int _width = 60, _height = 20;
	CPlayer _player;


public:
	CMap();
	~CMap() = default;
	void printBorders();
	void Print(CPos pos, char** kind, int h, int w); //height and width of thing to print
	void printPlayer(); //draw player 
	//void printObject(); //draw another object


};