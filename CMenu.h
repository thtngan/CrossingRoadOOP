#pragma once
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <windows.h>
#include <conio.h>


using namespace std;

#include "CConsole.h"

class CMenu
{
private:
	int typePlayer;

public:
	CMenu() = default;
	~CMenu() = default;

	void printTitle();
	void menu();
	void settings();
};

