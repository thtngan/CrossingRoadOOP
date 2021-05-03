#include "CPlayer.h"
#include "CBird.h"
#include "CElephant.h"
#include "CHelicopter.h"
#include "CTrain.h"
#include "CCar.h"
#include "CMap.h"
#include "CMenu.h"
#include "ConstantVar.h"

using namespace std;

int ConstantVar::_typePlayer = 0;
bool ConstantVar::_isMusic = true;

int main() {
	srand(time(NULL));
	
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, 1400, 800, TRUE);
	FixConsoleWindow();
	

	CMenu game;
	game.menu();
	game.printGB();

	return 0;
}