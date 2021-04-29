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
protected:
	int _level;
};

