#include "CLevel.h"

CLevel::CLevel() {
	_level = 1;
	_line = 4;
	_nbObj = 0;
	_maxObj = 5;
	_speed = 50;
	init();
}
CLevel::CLevel(const int& level) {
	_level = level;
	_nbObj = 0;
	if ((4 + (_level / 3)) <= 10)
		_line = (4 + (_level / 3));
	else _line = 10;
	_maxObj = 5 + _level*2;
	if ((50 - _level * 5) < 5)
		_speed = 5;
	else _speed = (50 - _level * 5);
	init();
}
void CLevel::init() {
	_maxSpeed = _speed - _level * 2; 
	_minSpeed = _speed - _level * 1;
}
CObject* CLevel::randObj(CPos pos) {
	if (_nbObj == _maxObj) return NULL;
	if (_nbObj < (_maxObj / 2) || (rand() % 3)) {
		++_nbObj;
		CObject* newObj = NULL;
		int r = rand() % 4;
		switch (r) {
		case 0:
			newObj = new CBird(pos);
			break;
		case 1:
			newObj = new CCar(pos);
			break;
		case 2:
			newObj = new CElephant(pos);
			break;
		case 3:
			newObj = new CHelicopter(pos);
			break;
		}
		return newObj;
	}
	return NULL;
}
int CLevel::getLevel() {
	return _level;
}
bool CLevel::newLevel(const int& level) {
	_level = level;
	return true;
}
bool CLevel::nextLevel() {
	_level++;
	if (_level % 3 == 0 && _line < 10)
		_line++;
	_nbObj = 0;
	_maxObj += 2;
	if(_speed > 5)
		_speed -= 5;
	init();
	return true;
}
int CLevel::getLine() {
	return _line;
}
void CLevel::reNbObj(int nb) {
	_nbObj -= nb;
}
int CLevel::getMinSpeed() {
	return _minSpeed;
}
int CLevel::getMaxSpeed() {
	return _maxSpeed;
}