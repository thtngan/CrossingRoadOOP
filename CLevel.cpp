#include "CLevel.h"

#define MAXSPEED 120 
#define MINSPEED 50
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