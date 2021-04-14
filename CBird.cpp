#include "CBird.h"

CBird::CBird() {
	_bird = new char* [4];
	for (int i = 0; i < 4; i++)
		_bird[i] = new char[7];
	
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 7; j++)
			_bird[i][j] = ' ';
	//Draw ear
	_bird[0][1] = '/';
	_bird[0][2] = '\\';
	_bird[0][4] = '/';
	_bird[0][5] = '\\';

	//Draw head
	_bird[1][0] = '(';
	_bird[1][1] = '(';
	_bird[1][2] = 'o';
	_bird[1][3] = 'v';
	_bird[1][4] = 'o';
	_bird[1][5] = ')';
	_bird[1][6] = ')';

	//Draw body
	_bird[2][0] = '(';
	_bird[2][1] = ')';
	_bird[2][2] = ':';
	_bird[2][3] = ':';
	_bird[2][4] = ':';
	_bird[2][5] = '(';
	_bird[2][6] = ')';


	//Draw leg
	_bird[3][2] = 'V';
	_bird[3][3] = 'V';
	_bird[3][4] = 'V';

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 7; j++)
			cout << _bird[i][j];
		cout << endl;
	}
}

CBird::~CBird() {
	for (int i = 0; i < 3; i++)
		delete _bird[i];

	delete _bird;
}
