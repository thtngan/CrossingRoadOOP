#include "CCar.h"

CCar::CCar() {
	_car = new char* [4];
	for (int i = 0; i < 4; i++)
		_car[i] = new char[13];

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 13; j++)
			_car[i][j] = ' ';

	//Draw row 1
	for (int i = 2; i < 8; i++)
		_car[0][i] = '_';

	//Draw row 2
	_car[1][1] = '/';
	_car[1][2] = '|';
	_car[1][3] = '_';
	_car[1][4] = '|';
	_car[1][5] = '|';
	_car[1][6] = '_';
	_car[1][7] = '\\';
	_car[1][8] = '`';
	_car[1][9] = '.';
	_car[1][10] = '_';
	_car[1][11] = '_';

	//Draw row 3
	_car[2][0] = '(';
	_car[2][4] = '_';
	_car[2][9] = '_';
	_car[2][11] = '_';
	_car[2][12] = '\\';

	//Draw row 4
	_car[3][0] = '=';
	_car[3][1] = '`';
	_car[3][2] = '-';
	_car[3][3] = '(';
	_car[3][4] = 'O';
	_car[3][5] = ')';
	_car[3][6] = '-';
	_car[3][7] = '-';
	_car[3][8] = '(';
	_car[3][9] = 'O';
	_car[3][10] = ')';
	_car[3][11] = '-';
	_car[3][12] = '\'';

	//for (int i = 0; i < 4; i++) {
	//	for (int j = 0; j < 13; j++)
	//		cout << _car[i][j];
	//	cout << endl;
	//}
}

CCar::~CCar() {
	for (int i = 0; i < 4; i++)
		delete _car[i];

	delete _car;
}

char** CCar::kind() {
	return _car;
}

int CCar::getW() {
	return 13;
}
int CCar::getH() {
	return 4;
}