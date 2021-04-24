#ifndef _console_header
#define _console_header

#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <time.h>

#define gotoXY(x,y) printf("\033[%d;%dH", (y), (x))


void FixConsoleWindow();
void ShowConsoleCursor(bool showFlag);
void ClearScreen();

class CConsole
{
};

#endif