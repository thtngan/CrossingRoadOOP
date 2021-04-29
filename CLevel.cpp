#include "CLevel.h"

#define MAXSPEED 120 
#define MINSPEED 30
CLevel::CLevel() {
	_level = 1;
}
CLevel::CLevel(const int& level) {
	_level = level;
}
CObject* CLevel::randObj(CPos pos) {
	CObject* newObj = NULL;
	int r = rand() % 4;
	switch (r) {
		case 0: {
			newObj = new CBird(pos);
			break;
		}
		case 1: {
			newObj = new CCar(pos);
			break;
		}
		case 2: {
			newObj = new CElephant(pos);
			break;
		}
		case 3: {
			newObj = new CHelicopter(pos);
			break;
		}
	}
	return newObj;
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
	return true;
}
int CLevel::getSpeed() {
	int speed;
	speed = MINSPEED + (_level * 5) - 5;
	if (speed > MAXSPEED)
		speed = MAXSPEED;
	return speed;
}