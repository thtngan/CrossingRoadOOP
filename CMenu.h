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
class CMenu
{
private:
	CMap map;
	int typePlayer;
	CLine line;
public:
	CMenu() = default;
	~CMenu() = default;

	void printTitle();
	void menu();
	void settings();
};

