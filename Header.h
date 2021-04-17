#ifndef _header
#define _header

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <windows.h>
#include <conio.h>



#define gotoXY(x,y) printf("\033[%d;%dH", (y), (x))

using namespace std;

#define BLACK 0
#define BLUE 1
#define GREEN 2
#define CYAN 3
#define RED 4
#define MAGENTA 5
#define BROWN 6
#define LIGHTGREY 7
#define DARKGREY 8
#define LIGHTBLUE 9
#define LIGHTGREEN 10
#define LIGHTCYAN 11
#define LIGHTRED 12
#define LIGHTMAGENTA 13
#define YELLOW 14
#define WHITE 15
#define BLINK 16

#endif