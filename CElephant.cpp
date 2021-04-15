#include "CElephant.h"

CElephant::CElephant() {
	_elephant = new char* [4];
	for (int i = 0; i < 4; i++)
		_elephant[i] = new char[10];

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 10; j++)
			_elephant[i][j] = ' ';


	//Draw ear
	_elephant[0][6] = '_';
	_elephant[0][7] = '_';

	//Draw head
	_elephant[1][1] = '.';
	_elephant[1][2] = '-';
	_elephant[1][3] = '-';
	_elephant[1][4] = '(';
	_elephant[1][5] = ')';
	_elephant[1][6] = 'O';
	_elephant[1][7] = '\'';
	_elephant[1][8] = '.';
	_elephant[1][9] = '\'';

	//Draw body
	_elephant[2][0] = '\'';
	_elephant[2][1] = '|';
	_elephant[2][2] = ',';
	_elephant[2][4] = '.';
	_elephant[2][6] = ',';
	_elephant[2][7] = '\'';

	//Draw leg
	_elephant[3][1] = '!';
	_elephant[3][2] = '_';
	_elephant[3][3] = '-';
	_elephant[3][4] = '(';
	_elephant[3][5] = '_';
	_elephant[3][6] = '\\';

	/*for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 10; j++)
			cout << _elephant[i][j];
		cout << endl;
	}*/
}

CElephant::~CElephant() {
	for (int i = 0; i < 4; i++)
		delete _elephant[i];

	delete _elephant;
}

char** CElephant::kind() {
	return _elephant;
}

int CElephant::getW() {
	return 10;
}
int CElephant::getH() {
	return 4;
}
