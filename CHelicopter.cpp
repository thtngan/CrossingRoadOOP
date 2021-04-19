#include "CHelicopter.h"

CHelicopter::CHelicopter() : CObject(){
	_helicopter = new char* [3];
	for (int i = 0; i < 3; i++)
		_helicopter[i] = new char[14];

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 14; j++)
			_helicopter[i][j] = ' ';

	//Draw row 1
	for (int i = 3; i < 8; i++)
		_helicopter[0][i] = '-';
	_helicopter[0][8] = '|';
	for (int i = 9; i < 14; i++)
		_helicopter[0][i] = '-';
	//Draw row 2
	_helicopter[1][0] = '*';
	_helicopter[1][1] = '>';
	for (int i = 2; i < 7; i++)
		_helicopter[1][i] = '=';
	_helicopter[1][7] = '[';
	_helicopter[1][8] = '_';
	_helicopter[1][9] = ']';
	_helicopter[1][10] = 'L';
	_helicopter[1][11] = ')';

	//Draw row 3
	_helicopter[2][6] = '-';
	_helicopter[2][7] = '\'';
	_helicopter[2][8] = '-';
	_helicopter[2][9] = '`';
	_helicopter[2][10] = '-';


	/*for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 14; j++)
			cout << _helicopter[i][j];
		cout << endl;
	}*/

}

CHelicopter::~CHelicopter() {
	for (int i = 0; i < 3; i++)
		delete _helicopter[i];

	delete _helicopter;
}

char** CHelicopter::kind() {
	return _helicopter;
}

int CHelicopter::getW() {
	return 14;
}
int CHelicopter::getH() {
	return 3;
}
