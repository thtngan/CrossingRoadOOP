#include "CPlayer.h"
#include "CBird.h"
#include "CElephant.h"
#include "CHelicopter.h"
#include "CTrain.h"
#include "CCar.h"
#include "CMap.h"
#include "CMenu.h"



using namespace std;

int main() {
	srand(time(NULL));
	
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	FixConsoleWindow();
	CMenu game;
	game.menu();

}