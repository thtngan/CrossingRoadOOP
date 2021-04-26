#include "CPlayer.h"
#include<iostream>

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

	//type 1
	//Draw head
	_player[0][0] = ' ';
	_player[0][1] = '(';
	_player[0][2] = 'O';
	_player[0][3] = '.';
	_player[0][4] = 'O';
	_player[0][5] = ')';
	_player[0][6] = ' ';

	
}

CPlayer::CPlayer() {
	_pos.setPos(25, 20); //position default
	Draw(1);		
}

CPlayer::~CPlayer() {
	for (int i = 0; i < 3; i++)
		delete _player[i];

	delete _player;
}

char** CPlayer::kind() {
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
	_pos.setPos((_pos.getX() - 5), _pos.getY());
	//cout << "moved up: " << _pos.getX() << " " << _pos.getY() << endl;
}
void CPlayer::moveDown()
{
	_pos.setPos((_pos.getX() + 5), _pos.getY());
	//cout << "moved down: " << _pos.getX() << " " << _pos.getY() << endl;
}
void CPlayer::moveRight()
{
	_pos.setPos(_pos.getX(), (_pos.getY() + 8));
	//cout << "moved right: " << _pos.getX() << " " << _pos.getY() << endl;
}
void CPlayer::moveLeft()
{
	_pos.setPos(_pos.getX(), (_pos.getY() - 8));
}