#include "CPlayer.h"
#include<iostream>
using namespace std;

void CPlayer::Draw(const int type) {
	_player = new char* [3];
	for (int i = 0; i < 3; i++) {
		_player[i] = new char[7];
	}

	//Draw body
	_player[1][0] = '/';
	_player[1][1] = '(';
	_player[1][2] = ' ';
	_player[1][3] = '_';
	_player[1][4] = ' ';
	_player[1][5] = ')';
	_player[1][6] = '\\';

	//Draw leg
	for (int i = 0; i < 7; i++) {
		if (i == 2)
			_player[2][i] = '^';
		else if (i == 4)
			_player[2][i] = '^';
		else _player[2][i] = ' ';
	}

	//Draw head

	//type 1
	if (type == 0) {
		_player[0][0] = ' ';
		_player[0][1] = '(';
		_player[0][2] = 'O';
		_player[0][3] = '.';
		_player[0][4] = 'O';
		_player[0][5] = ')';
		_player[0][6] = ' ';
	}
	else if (type == 1) {
		_player[0][0] = ' ';
		_player[0][1] = '(';
		_player[0][2] = '^';
		_player[0][3] = 'O';
		_player[0][4] = '^';
		_player[0][5] = ')';
		_player[0][6] = ' ';
	}
	else {
		_player[0][0] = ' ';
		_player[0][1] = '(';
		_player[0][2] = '>';
		_player[0][3] = '_';
		_player[0][4] = '<';
		_player[0][5] = ')';
		_player[0][6] = ' ';
	}


	
}

CPlayer::CPlayer() {
	_pos.setPos(40, 60); //position default
	_type = ConstantVar::_typePlayer;
	Draw(_type);		
}

CPlayer::~CPlayer() {
	for (int i = 0; i < 3; i++)
		delete _player[i];

	delete _player;
}

char** CPlayer::kind() {
	Draw(ConstantVar::_typePlayer);
	return _player;
}
CPos CPlayer::getPos() {
	return _pos;
}
int CPlayer::getW() {
	return 7;
}
int CPlayer::getH() {
	return 3;
}
void CPlayer::xuatPos()
{
	std::cout << _pos.getX() << " " << _pos.getY() << std::endl;
}
void CPlayer::moveUp()
{
	soundPlayer();
	_pos.setPos((_pos.getX() - 2), _pos.getY());
	if (_pos.getX() < 2)
	{
		_pos.setPos(2, _pos.getY());
	}
	//cout << "moved up: " << _pos.getX() << " " << _pos.getY() << endl;
}
void CPlayer::moveDown()
{
	soundPlayer();
	_pos.setPos((_pos.getX() + 2), _pos.getY());
	if (_pos.getX() > 40)
	{
		_pos.setPos(40, _pos.getY());
	}
	//cout << "moved down: " << _pos.getX() << " " << _pos.getY() << endl;
}
void CPlayer::moveRight()
{
	soundPlayer();
	_pos.setPos(_pos.getX(), (_pos.getY() + 3));
	if (_pos.getY() > 126)
	{
		_pos.setPos(_pos.getX(), 126);
	}
	//cout << "moved right: " << _pos.getX() << " " << _pos.getY() << endl;
}
void CPlayer::moveLeft()
{
	soundPlayer();
	_pos.setPos(_pos.getX(), (_pos.getY() - 3));
	if (_pos.getY() < 4)
	{
		_pos.setPos(_pos.getX(), 4);
	}
}

void CPlayer::soundPlayer() {
	if (ConstantVar::_isMusic) {
		PlaySoundW(L"PlayerMove.wav", NULL, SND_FILENAME | SND_ASYNC);
	}
}
