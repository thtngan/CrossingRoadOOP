#include "CMap.h"

CMap::CMap() {
	for (int i = 0; i < _width; i++)
		_map[0][i] = _map[_height][i] = '-';

	_map[0][_width] = _map[_height][_width] = ' ';
	for (int i = 1; i < _height; ++i) {
		_map[i][0] = _map[i][_width] = '|';
		_map[i][_width + 1] = ' ';
		for (int j = 1; j < _width; ++j) {
			_map[i][j] = ' ';
		}
	}
}
void CMap::printBorders() {
	system("cls");
	gotoXY(0, 0);
	for (int i = 0; i <= _height; ++i) {
		cout << "  ";
		for (int j = 0; j <= _width; ++j) {
			cout << _map[i][j];
		}
		cout << endl;
	}
}
bool CMap::Print(CPos pos, char** kind, int h, int w) {
	int X = pos.getX();
	int Y = pos.getY();
	if (Y + w <= 0) return false;
	if (Y > _width) return false;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			gotoXY(Y + j, X + i);
			cout << kind[i][j];
		}
	}
	return true;
}
void CMap::printPlayer() {
	//print player
	bool print = Print(
		_player.getPos(),
		_player.kind(),
		_player.getH(),
		_player.getW()
	);
}
void CMap::printObject(CObject *obj) {
	bool print = Print(
		obj->getPos(),
		obj->kind(),
		obj->getH(),
		obj->getW()
	);
	if(!print)
		obj->setOutMap();
}
void CMap::printMap(){
//	clrscr();
	gotoXY(0, 0);
	for (int i = 0; i <= _height + 1; ++i) {
		cout << "  ";
		for (int j = 0; j <= _width + 1; ++j) {
			cout << _map[i][j];
		}
		cout << endl;
	}
	gotoXY(100, 2); cout << "<Crossing Road Game>";	
//	gotoXY(125, 3); cout << "LV. " << level.getLevel() << endl;
	gotoXY(100, 5); cout << "CONTROL MANUAL" << endl;
	gotoXY(100, 6); cout << "[ W ]: UP" << endl;
	gotoXY(100, 7); cout << "[ S ]: DOWN" << endl;
	gotoXY(100, 8); cout << "[ A ]: LEFT" << endl;
	gotoXY(100, 9); cout << "[ D ]: RIGHT" << endl;
	gotoXY(100, 11); cout << "COMMANDS" << endl;
	gotoXY(100, 12); cout << "[ L ]: Save game" << endl;
	gotoXY(100, 13); cout << "[ T ]: Load game" << endl;
	gotoXY(100, 14); cout << "[ P ]: Pause game/Menu" << endl;
	printPlayer();
	CObject *a = new CCar();
	printObject(a);
}
