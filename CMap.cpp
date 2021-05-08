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
void CMap::deletePlayer() {
	delPlayer(_player.getPos(), _player.kind(), _player.getH(), _player.getW());
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
	gotoXY(0, 0);
	for (int i = 0; i <= _height + 1; ++i) {
		cout << "  ";
		for (int j = 0; j <= _width + 1; ++j) {
			cout << _map[i][j];
		}
		cout << endl;
	}
	gotoXY(138, 2); cout << "<Crossing Road Game>";	
	gotoXY(138, 4); cout << "LV. " << _level.getLevel() << endl;
	gotoXY(138, 6); cout << "CONTROL MANUAL" << endl;
	gotoXY(138, 7); cout << "[" << 'W' << "]: UP" << endl;
	gotoXY(138, 8); cout << "[" << 'S' << "]: DOWN" << endl;
	gotoXY(138, 9); cout << "[" << 'A' << "]: LEFT" << endl;
	gotoXY(138, 10); cout << "[" << 'D' << "]: RIGHT" << endl;
	gotoXY(138, 12); cout << "COMMANDS" << endl;
	gotoXY(138, 13); cout << "[ L ]: Save game" << endl;
	gotoXY(138, 14); cout << "[ T ]: Load game" << endl;
	gotoXY(138, 15); cout << "[ P ]: Pause game/Menu" << endl;
	printPlayer();
}
void CMap::init(){
	_player.~CPlayer();
	new(&_player) CPlayer();
	_lines.~CLines();
	new(&_lines) CLines();
	int n = _level.getLine();
	int* road = new int[n];
	for (int i = 0; i < n; ++i) {
		road[i] = 0;
		int speed = rand() % (_level.getMinSpeed() - _level.getMaxSpeed() + 1) + _level.getMaxSpeed();
		bool trafficLight = rand() % 2;
		bool direction = rand() % 2;
		_lines.PushLine(new CLine(speed, direction, trafficLight, i * 4));
	}
	CObject * newObj;
	CPos pos;
	int tryCount = 10000;
	while (tryCount--) { 
		int LineNb = (rand() % (n - 1)) + 1;
		road[LineNb] += (rand() % 20) + 9;
		pos = CPos(LineNb * 4, road[LineNb]);
		newObj = _level.randObj(pos);
		if (!newObj) 
			break;
		if (!_lines.PushObj(newObj, LineNb)) {
			_level.reNbObj(1);
			delete newObj;
		};
	}
	Sleep(200);
	_lines.Transfer(0);
}
void CMap::random() {
	srand(time(NULL));
	CObject* newObj;
	CPos pos;
	int tryCount = 10000;
	int n = _level.getLine();
	while (tryCount--) {
		int LineNb = (rand() % (n - 1)) + 1;
		pos = CPos(LineNb * 4, 4);
		newObj = _level.randObj(pos);
		if (!newObj) break;
		if (!_lines.PushObj(newObj, LineNb)) {
			_level.reNbObj(1);
			delete newObj;
		};
	}
	++t;
	int tmp = _lines.Transfer(t);
	_level.reNbObj(tmp);
	Sleep(10);
}
void CMap::movePlayer(const char& chr) {
	delPlayer(_player.getPos(), _player.kind(), _player.getH(), _player.getW());
	if (chr == 'a' || chr == 'A') _player.moveLeft();
	else if (chr == 'w' || chr == 'W') _player.moveUp();
	else if (chr == 'd' || chr == 'D') _player.moveRight();
	else if (chr == 's' || chr == 'S') _player.moveDown();
	else return;
	printPlayer();
}
bool CMap::isWin() {
	if (_player.getPos().getX() == 2)
		return true;
	return false;
}
void CMap::nextLevel() {
	_level.nextLevel();
}
int CMap::getLevel() {
	return _level.getLevel();
}
void CMap::loadLevel(const int& level) {
	_level.~CLevel();
	new(&_level) CLevel(level);
}
bool CMap::printLevelUp() {
	system("cls");
	printInstruct();
	deletePlayer();
	int color = rand() % 8 + 7;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);

	gotoXY(32, 12); cout << "   _        ___    __   __    ___      _                 _   _      ___   ";
	gotoXY(32, 13); cout << "  | |      | __|   \\ \\ / /   | __|    | |        o O O  | | | |    | _ \\  ";
	gotoXY(32, 14); cout << "  | |__    | _|     \\ V /    | _|     | |__     o       | |_| |    |  _/  ";
	gotoXY(32, 15); cout << "  |____|   |___|    _\\_/_    |___|    |____|   TS__[O]   \\___/    _|_|_    ";
	gotoXY(32, 16); cout << "_|\"\"\"\"\"| _|\"\"\"\"\"| _|\"\"\"\"\"| _|\"\"\"\"\"| _|\"\"\"\"\"|  {======| _|\"\"\"\"\"| _|\"\"\"\"\"| ";
	gotoXY(32, 17); cout << "\"`-0-0-\' \"`-0-0-' \"`-0-0-\' \"`-0-0-\' \"`-0-0-\' ./o--000' \"`-0-0-\' \"`-0-0-\'";
	
	gotoXY(55, 19); cout << "Do you continue ?" << endl;
	const string choice[2] = { "<YES>", "<NON>" };
	int pos = 0, x = 50, y = 22;
	while (1) {
		for (int i = 0; i < 2; i++) {
			if (i == pos) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 63);
				gotoXY(x, y);
				cout << choice[i];
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
			}
			else {
				gotoXY(x + 21, y);
				cout << choice[i];
			}
		}

		switch (_getch()) {
		case 'a': case 'A':
			pos--;
			pos = abs(pos);
			pos %= 2;
			break;
		case 'd': case 'D':
			pos++;
			pos %= 2;
			break;
		case 13:
			return !pos;
		}
	}
}

bool CMap::collision()
{
	bool a = false;
	vector <CObject*> List = _lines.listObj();
	for (int i = 0; i < (int)List.size(); ++i)
	{
		if (_player.crash(List[i]->getPos(), List[i]->getW(), List[i]->getH()))
		{
			a = true;
			system("cls");
			gotoXY(50, 10); cout << "     _.-^^---....,,--    ";
			gotoXY(50, 11); cout << " _--                 --_";
			gotoXY(50, 12); cout << "<                        >)";
			gotoXY(50, 13); cout << "|                         |";
			gotoXY(50, 14); cout << "|._                   _./";
			gotoXY(50, 15); cout << "  ```--. . , ; .--''' ";
			gotoXY(50, 16); cout << "   	  | |   |   ";
			gotoXY(50, 17); cout << "      .-=||  | |=-.   ";
			gotoXY(50, 18); cout << "      `-=#$%&%$#=-'   ";
			gotoXY(50, 19); cout << "   	  | ;  :|     ";
			gotoXY(50, 20); cout << "_____.,-#%&$@%#&#~,._____";
			gotoXY(40, 23); cout << "    _____                   _                _ ";
			gotoXY(40, 24); cout << "   / ____|                 | |              | | ";
			gotoXY(40, 25); cout << "  | |      _ __  __ _  ___ | |__    ___   __| | ";
			gotoXY(40, 26); cout << "  | |     | '__|/ _` |/ __|| '_ \\ / _ | / _`  |";
			gotoXY(40, 27); cout << "  | |____ | |  | (_| ||__ || | | || __/| (_ | |";
			gotoXY(40, 28); cout << "   \\_____||_|   \\__,_||___/|_| |_|\\___| \\__,|_|";
			gotoXY(48, 38); cout << "   Press-Any-Key-To-Proceed";
			bool t = true;
			while (t)
			{
				if (_kbhit())
				{
					break;
				}
			}
			system("cls");
			writeToRank();
		}
	}
	if (a)
	{
		return a;
	}
	return false;
}
bool cmp(pair<string, int>& a, pair<string, int>& b)
{
	return a.second > b.second;
}
void CMap::writeToRank()
{
	string ten;
	string tmp;
	int level;
	vector<pair<string, int>> board;
	fstream ifs;
	ifs.open("C:/Users/Envy/Downloads/NCR/rank.txt", std::fstream::in);
	if (!ifs.is_open())
	{
		cout << "cannot open file";
		return;
	}
	while (!ifs.eof())
	{
		getline(ifs, ten, ':');
		getline(ifs, tmp, '\n');
		level = stoi(tmp);
		pair <string, int> a(ten, level);
		board.push_back(a);
	}
	ifs.close();
	cin.clear();
	gotoXY(20, 20); cout << "Enter your name: ";
	getline(cin, ten);
	pair <string, int> a(ten, _level.getLevel());
	board.push_back(a);
	sort(board.begin(), board.end(), cmp);
	ifs.open("C:/Users/Envy/Downloads/NCR/rank.txt", std::fstream::out);
	if (!ifs.is_open())
	{
		cout << "cannot open file";
		return;
	}
	for (int i = 0; i < 5; i++)
	{
		ifs << board[i].first << ":" << board[i].second << "\n";
	}
	ifs.close();
	board.clear();
	Sleep(500);
	return;
}