#pragma once
#include "CBird.h"
#include "CCar.h"
#include "CElephant.h"
#include "CHelicopter.h"
#include "CTrain.h"
#include "CPos.h"
class CLevel
{
public:
	CLevel();
	CLevel(const int&, const int&);
	~CLevel() = default;
	CObject* randObj(CPos pos);
	int getLevel();
	bool newLevel(const int&);
	bool nextLevel();
	int getLine();
	void init();
	void reNbObj(int nb);
	int getMinSpeed();
	int getMaxSpeed();
protected:
	int _level, _line, _nbObj, _maxObj, _minSpeed, _maxSpeed, _speed;
};

