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
			case 'a':
				delPlayer(_player.getPos(), _player.kind(), _player.getH(), _player.getW());
				_player.moveLeft();
				printPlayer();
				break;
			case 'w':
				delPlayer(_player.getPos(), _player.kind(), _player.getH(), _player.getW());
				_player.moveUp();
				printPlayer();
				break;
			case 's':
				delPlayer(_player.getPos(), _player.kind(), _player.getH(), _player.getW());
				_player.moveDown();
				printPlayer();
				break;
			case 'd':
				delPlayer(_player.getPos(), _player.kind(), _player.getH(), _player.getW());
				_player.moveRight();
				printPlayer();
				break;
			case 'p':
				gotoXY(25, 30);
				cout << "PAUSED - Press p to continue";
				bool t = 1;
				while (t)
				{
					char a;
					a = _getch();
					switch (a)
					{
					case 'p':
						t = false;
						gotoXY(25, 30);
						cout << "                             ";
						break;
					}
				}
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
void CMap::printInstruct(){
//	clrscr();
	gotoXY(0, 0);
	for (int i = 0; i <= _height + 1; ++i) {
		cout << "  ";
		for (int j = 0; j <= _width + 1; ++j) {
			cout << _map[i][j];
		}
		cout << endl;
	}
	gotoXY(98, 2); cout << "<Crossing Road Game>";	
//	gotoXY(125, 3); cout << "LV. " << level.getLevel() << endl;
	gotoXY(98, 5); cout << "CONTROL MANUAL" << endl;
	gotoXY(98, 6); cout << "[" << 'W' << "]: UP" << endl;
	gotoXY(98, 7); cout << "[" << 'S' << "]: DOWN" << endl;
	gotoXY(98, 8); cout << "[" << 'A' << "]: LEFT" << endl;
	gotoXY(98, 9); cout << "[" << 'D' << "]: RIGHT" << endl;
	gotoXY(98, 11); cout << "COMMANDS" << endl;
	gotoXY(98, 12); cout << "[ L ]: Save game" << endl;
	gotoXY(98, 13); cout << "[ T ]: Load game" << endl;
	gotoXY(98, 14); cout << "[ P ]: Pause game/Menu" << endl;
	printPlayer();
}
void CMap::init(){
	_player.~CPlayer();
	new(&_player) CPlayer();
	_lines.~CLines();
	new(&_lines) CLines();
	int road[5] = { 0 };
	for (int i = 0; i < 5; ++i) {
		int speed = rand() % 100;
		bool direction = rand() % 2;
		_lines.PushLine(new CLine(speed, direction, (i * 4) + 1));
	}
	CObject * newObj;
	CPos pos;
	int tryCount = 10000;
	while (tryCount--) { 
		int LineNb = (rand() % 4) + 1;
		road[LineNb] += (rand() % 20) + 9;
		pos = CPos((LineNb * 4) + 1, road[LineNb]);
		newObj = new CBird(pos);
		if (!newObj) 
			break;
		if (!_lines.PushObj(newObj, LineNb)) {
			delete newObj;
		};
	}
	Sleep(200);
	_lines.Transfer(0);
}
void CMap::printMap() {
}
void CMap::random() {
	srand(time(NULL));
	CObject* newObj;
	CPos pos;
	int tryCount = 10000;
	while (tryCount--) {
		int LineNb = (rand() % 4) + 1;
		pos = CPos((LineNb * 4) + 1, 4);
		newObj = new CBird(pos);
		if (!newObj) break;
		if (!_lines.PushObj(newObj, LineNb)) {
			delete newObj;
		};
	}
	++t;
	int tmp = _lines.Transfer(t);
	printMap();
}

