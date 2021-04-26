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
bool CMap::delPlayer(CPos pos, char** kind, int h, int w)
{
	int X = pos.getX();
	int Y = pos.getY();
	if (Y + w <= 0) return false;
	if (Y > _width) return false;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			gotoXY(Y + j, X + i);
			cout << " ";
		}
	}
	return true;
}
void CMap::move()
{
	char m;
	while (true)
	{
		if (_kbhit())
		{
			m = _getch();
			switch (m)
			{
			case 75:
				delPlayer(_player.getPos(), _player.kind(), _player.getH(), _player.getW());
				_player.moveLeft();
				printPlayer();
				break;
			case 72:
				delPlayer(_player.getPos(), _player.kind(), _player.getH(), _player.getW());
				_player.moveUp();
				printPlayer();
				break;
			case 80:
				delPlayer(_player.getPos(), _player.kind(), _player.getH(), _player.getW());
				_player.moveDown();
				printPlayer();
				break;
			case 77:
				delPlayer(_player.getPos(), _player.kind(), _player.getH(), _player.getW());
				_player.moveRight();
				printPlayer();
				break;
			case 'p':
				gotoXY(25, 30);
				cout << "Pause,";
				system("pause");
				break;
			}
		}
	}
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
	gotoXY(100, 6); cout << "[" << (char)24 << "]: UP" << endl;
	gotoXY(100, 7); cout << "[" << (char)25 << "]: DOWN" << endl;
	gotoXY(100, 8); cout << "[" << (char)27 << "]: LEFT" << endl;
	gotoXY(100, 9); cout << "[" << (char)26 << "]: RIGHT" << endl;
	gotoXY(100, 11); cout << "COMMANDS" << endl;
	gotoXY(100, 12); cout << "[ L ]: Save game" << endl;
	gotoXY(100, 13); cout << "[ T ]: Load game" << endl;
	gotoXY(100, 14); cout << "[ P ]: Pause game/Menu" << endl;
	printPlayer();
	CObject *a = new CCar();
	printObject(a);
}
//void CMap::init(){
//	_player.~CPlayer();
//	new(&_player) CPlayer();
//	_lines.~CLines();
//	new(&_lines) CLines();
//	int padding[10] = {};
//	for (int i = 0; i < 10; ++i) {
//		int speed = rand() % 5;
//		bool direction = rand() % 2;
//		bool redLight = rand() % 2;
//		_lines.PushLine(new CLine(speed, direction, (i * 3) + 1));
//	}
//	CObject * newObj;
//	CPos pos;
//	int tryCount = 10000;
//	while (tryCount--) { 
//		int rRow = (rand() % 9) + 1;
//		padding[rRow] += (rand() % 20) + 9;
//		pos = CPos((rRow * 3) + 1, padding[rRow]);
//		newObj = new CCar();
//		if (!newObj) 
//			break;
//		if (!_lines.PushObj(newObj, rRow)) {
//			delete newObj;
//		};
//	}
//	Sleep(200);
//	_lines.Transfer(0);
//}

//diff