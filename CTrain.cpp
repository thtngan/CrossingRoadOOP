#include "CTrain.h"

CTrain::CTrain() : CObject(){
	_train = new char* [4];
	for (int i = 0; i < 4; i++)
		_train[i] = new char[45];

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 45; j++)
			_train[i][j] = ' ';

	//Draw row 1
	_train[0][3] = '.';
	_train[0][4] = '.';
	_train[0][5] = '.';
	_train[0][6] = '.';
	_train[0][7] = ' ';
	_train[0][8] = '_';
	_train[0][9] = '_';
	_train[0][10] = '_';
	_train[0][11] = '_';
		//first	
	_train[0][15] = '|';
	for (int i = 16; i < 22; i++)
		_train[0][i] = '~';
	_train[0][19] = '^';
	_train[0][22] = '|';

		//second
	_train[0][25] = '|';
	for (int i = 26; i < 31; i++)
		_train[0][i] = '~';
	_train[0][31] = '|';
		//third
	_train[0][34] = '|';
	for (int i = 35; i < 42; i++)
		_train[0][i] = '~';
	_train[0][42] = '|';

	//Draw row 2
	_train[1][2] = ']';
	_train[1][3] = '[';
	for(int i = 4; i < 8; i++)
		_train[1][i] = '_';
	_train[1][8] = '|';
	_train[1][9] = '[';
	_train[1][10] = ']';
	_train[1][11] = '|';
		//first
	_train[1][15] = '|';
	_train[1][17] = 'N';
	_train[1][18] = 'G';
	_train[1][19] = 'A';
	_train[1][20] = 'N';
	_train[1][22] = '|';

		//second
	_train[1][25] = '|';
	_train[1][27] = 'K';
	_train[1][28] = 'I';
	_train[1][29] = 'M';
	_train[1][31] = '|';
		//third
	_train[1][34] = '|';
	_train[1][36] = 'Q';
	_train[1][37] = 'U';
	_train[1][38] = 'A';
	_train[1][39] = 'N';
	_train[1][40] = 'G';
	_train[1][42] = '|';

	//Draw row 3
	_train[2][1] = '(';
	_train[2][2] = '|';
	for (int i = 3; i < 7; i++)
		_train[2][i] = '_';
	_train[2][4] = '|';
	_train[2][6] = '|';
	_train[2][8] = '|';
	_train[2][7] = '_';
	_train[2][9] = '_';
	_train[2][10] = '_';
	_train[2][11] = '|';
	_train[2][12] = '_';
	_train[2][13] = ',';
	_train[2][14] = '_';
		//first
	_train[2][15] = '|';
	for(int i = 16; i < 22; i++)
		_train[2][i] = '_';
	_train[2][22] = '|';
	for (int i = 23; i < 25; i++)
		_train[2][i] = '_';

		//second
	_train[2][25] = '|';
	for (int i = 26; i < 31; i++)
		_train[2][i] = '_';
	_train[2][31] = '|';
	for (int i = 32; i < 34; i++)
		_train[2][i] = '_';

		//third
	_train[2][34] = '|';
	for (int i = 35; i < 42; i++)
		_train[2][i] = '_';
	_train[2][42] = '|';

	//Draw row 4
	_train[3][0] = '/';
	_train[3][1] = '/';
	_train[3][2] = 'o';
	_train[3][3] = 'o';
	_train[3][4] = '-';
	_train[3][5] = '-';
	_train[3][6] = '-';
	_train[3][7] = 'O';
	_train[3][8] = 'O';
	_train[3][9] = '=';
	_train[3][10] = 'O';
	_train[3][11] = 'O';
	
		//first
	_train[3][16] = '0';
	_train[3][17] = '0';
	_train[3][20] = '0';
	_train[3][21] = '0';

		//second
	_train[3][26] = '0';
	_train[3][27] = '0';
	_train[3][29] = '0';
	_train[3][30] = '0';

		//third
	_train[3][35] = '0';
	_train[3][36] = '0';
	_train[3][40] = '0';
	_train[3][41] = '0';


	//for (int i = 0; i < 4; i++) {
	//	for (int j = 0; j < 45; j++)
	//		cout << _train[i][j];
	//	cout << endl;
	//}
}

CTrain::CTrain(CPos pos) : CObject(pos) {
	_train = new char* [4];
	for (int i = 0; i < 4; i++)
		_train[i] = new char[45];

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 45; j++)
			_train[i][j] = ' ';

	//Draw row 1
	_train[0][3] = '.';
	_train[0][4] = '.';
	_train[0][5] = '.';
	_train[0][6] = '.';
	_train[0][7] = ' ';
	_train[0][8] = '_';
	_train[0][9] = '_';
	_train[0][10] = '_';
	_train[0][11] = '_';
	//first	
	_train[0][15] = '|';
	for (int i = 16; i < 22; i++)
		_train[0][i] = '~';
	_train[0][19] = '^';
	_train[0][22] = '|';

	//second
	_train[0][25] = '|';
	for (int i = 26; i < 31; i++)
		_train[0][i] = '~';
	_train[0][31] = '|';
	//third
	_train[0][34] = '|';
	for (int i = 35; i < 42; i++)
		_train[0][i] = '~';
	_train[0][42] = '|';

	//Draw row 2
	_train[1][2] = ']';
	_train[1][3] = '[';
	for (int i = 4; i < 8; i++)
		_train[1][i] = '_';
	_train[1][8] = '|';
	_train[1][9] = '[';
	_train[1][10] = ']';
	_train[1][11] = '|';
	//first
	_train[1][15] = '|';
	_train[1][17] = 'N';
	_train[1][18] = 'G';
	_train[1][19] = 'A';
	_train[1][20] = 'N';
	_train[1][22] = '|';

	//second
	_train[1][25] = '|';
	_train[1][27] = 'K';
	_train[1][28] = 'I';
	_train[1][29] = 'M';
	_train[1][31] = '|';
	//third
	_train[1][34] = '|';
	_train[1][36] = 'Q';
	_train[1][37] = 'U';
	_train[1][38] = 'A';
	_train[1][39] = 'N';
	_train[1][40] = 'G';
	_train[1][42] = '|';

	//Draw row 3
	_train[2][1] = '(';
	_train[2][2] = '|';
	for (int i = 3; i < 7; i++)
		_train[2][i] = '_';
	_train[2][4] = '|';
	_train[2][6] = '|';
	_train[2][8] = '|';
	_train[2][7] = '_';
	_train[2][9] = '_';
	_train[2][10] = '_';
	_train[2][11] = '|';
	_train[2][12] = '_';
	_train[2][13] = ',';
	_train[2][14] = '_';
	//first
	_train[2][15] = '|';
	for (int i = 16; i < 22; i++)
		_train[2][i] = '_';
	_train[2][22] = '|';
	for (int i = 23; i < 25; i++)
		_train[2][i] = '_';

	//second
	_train[2][25] = '|';
	for (int i = 26; i < 31; i++)
		_train[2][i] = '_';
	_train[2][31] = '|';
	for (int i = 32; i < 34; i++)
		_train[2][i] = '_';

	//third
	_train[2][34] = '|';
	for (int i = 35; i < 42; i++)
		_train[2][i] = '_';
	_train[2][42] = '|';

	//Draw row 4
	_train[3][0] = '/';
	_train[3][1] = '/';
	_train[3][2] = 'o';
	_train[3][3] = 'o';
	_train[3][4] = '-';
	_train[3][5] = '-';
	_train[3][6] = '-';
	_train[3][7] = 'O';
	_train[3][8] = 'O';
	_train[3][9] = '=';
	_train[3][10] = 'O';
	_train[3][11] = 'O';

	//first
	_train[3][16] = '0';
	_train[3][17] = '0';
	_train[3][20] = '0';
	_train[3][21] = '0';

	//second
	_train[3][26] = '0';
	_train[3][27] = '0';
	_train[3][29] = '0';
	_train[3][30] = '0';

	//third
	_train[3][35] = '0';
	_train[3][36] = '0';
	_train[3][40] = '0';
	_train[3][41] = '0';
}
CTrain::~CTrain() {
	for (int i = 0; i < 4; i++)
		delete _train[i];

	delete _train;
}

char** CTrain::kind() {
	return _train;
}

int CTrain::getW() {
	return 45;
}
int CTrain::getH() {
	return 4;
}
