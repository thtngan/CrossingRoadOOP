#pragma once
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <windows.h>
#include <conio.h>


using namespace std;

#include "CConsole.h"
#include "CMap.h"
#include "CObject.h"
#include "CConsole.h"
#include "CLine.h"
#include "CTrain.h"
#include "ConstantVar.h"

class CMenu
{
private:
	CMap map;
	CLine line;

	//int typePlayer; //0: (O.O), 1: (^O^), 2: (>_<)
	bool isMusic; //true: ON, false: OFF

public:
	CMenu() = default;
	~CMenu() = default;

	void printTitle();
	void menu();

	//New game
	void loading();


	//Load game

	//Rank

	//Settings
	void settings();

	void FAQs();

	void printFAQs();

	//Exit
	void printGB();

};

