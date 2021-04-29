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
	CLevel(const int&);
	~CLevel() = default;
	CObject* randObj(CPos pos);
	int getLevel();
	bool newLevel(const int&);
	bool nextLevel();
	int getSpeed();
protected:
	int _level;
};

