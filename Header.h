#pragma once
#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <conio.h>

#define gotoXY(x,y) printf("\033[%d;%dH", (y), (x))

using namespace std;